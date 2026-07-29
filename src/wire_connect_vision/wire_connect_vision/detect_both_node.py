#!/usr/bin/env python3
"""Dual-model detection node: port (detect) + plug (OBB) → 3D + left/right arm targets.

Subscribes:
  /ob_camera_head/color/image_raw/compressed  (CompressedImage)
  /ob_camera_head/depth/image_raw             (Image, 16UC1 mm)

Publishes:
  /vision/plugs           (PlugDetectArray)    all plugs with direction
  /vision/ports           (PortDetectArray)    all USB-A ports
  /vision/left_target     (ArmTarget)          best plug for left arm
  /vision/right_target    (ArmTarget)          best plug for right arm
  /vision/detected_objects (MarkerArray)       RViz spheres + arrows
"""

import math
import sys
import numpy as np
from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy

from sensor_msgs.msg import CompressedImage, Image
from geometry_msgs.msg import Pose, Point, Quaternion
from visualization_msgs.msg import MarkerArray

from wire_connect_msgs.msg import (
    PlugDetect, PlugDetectArray,
    PortDetect, PortDetectArray,
    ArmTarget,
)

from .depth_projection import back_project, project_to_frame
from .viz_utils import make_sphere, make_arrow, publish_markers

# ── marker colour constants ──────────────────────────────────────────
GREEN = (0.0, 1.0, 0.0)
RED = (1.0, 0.0, 0.0)
MAGENTA = (1.0, 0.0, 1.0)  # direction arrows


class DetectBothNode(Node):
    def __init__(self):
        super().__init__("detect_both_node")

        # ── parameters ───────────────────────────────────────────────
        self.declare_parameter("model_port", "")
        self.declare_parameter("model_plug", "")
        self.declare_parameter("fx", 689.21)
        self.declare_parameter("fy", 689.26)
        self.declare_parameter("cx", 644.15)
        self.declare_parameter("cy", 360.16)
        self.declare_parameter("target_frame", "waist_yaw_link")
        self.declare_parameter("optical_frame", "ob_camera_head_color_optical_frame")
        self.declare_parameter("min_confidence", 0.5)
        self.declare_parameter("default_arm", "left")
        self.declare_parameter("show_display", True)
        self.declare_parameter("publish_rate", 30.0)

        # cache params
        self._fx = self.get_parameter("fx").value
        self._fy = self.get_parameter("fy").value
        self._cx = self.get_parameter("cx").value
        self._cy = self.get_parameter("cy").value
        self._target_frame = self.get_parameter("target_frame").value
        self._optical_frame = self.get_parameter("optical_frame").value
        self._min_conf = self.get_parameter("min_confidence").value
        self._default_arm = self.get_parameter("default_arm").value
        self._show_disp = self.get_parameter("show_display").value

        # ── YOLO models ──────────────────────────────────────────────
        from ultralytics import YOLO
        mp = self.get_parameter("model_port").value
        ml = self.get_parameter("model_plug").value
        if not mp or not ml:
            self.get_logger().fatal("model_port and model_plug params are required")
            sys.exit(1)
        self._port_model = YOLO(mp)
        self._plug_model = YOLO(ml)
        self.get_logger().info(f"port model: {mp}")
        self.get_logger().info(f"plug model: {ml}")

        # ── subscribers ──────────────────────────────────────────────
        self._color_data = None
        self._depth_arr = None

        qos_img = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage,
            "/ob_camera_head/color/image_raw/compressed", self._cb_color, qos_img)
        self.create_subscription(Image,
            "/ob_camera_head/depth/image_raw", self._cb_depth, qos_img)

        # ── TF ───────────────────────────────────────────────────────
        import tf2_ros
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # ── publishers ───────────────────────────────────────────────
        self._pub_plugs = self.create_publisher(PlugDetectArray, "/vision/plugs", 10)
        self._pub_ports = self.create_publisher(PortDetectArray, "/vision/ports", 10)
        self._pub_left = self.create_publisher(ArmTarget, "/vision/left_target", 10)
        self._pub_right = self.create_publisher(ArmTarget, "/vision/right_target", 10)
        self._pub_markers = self.create_publisher(MarkerArray, "/vision/detected_objects", 10)

        # ── state ────────────────────────────────────────────────────
        self._plug_id_seq = 0
        self._port_id_seq = 0
        self._frame_n = 0

        self.get_logger().info("detect_both_node ready")

    # ── callbacks ────────────────────────────────────────────────────
    def _cb_color(self, msg: CompressedImage):
        if self._color_data is None:
            self.get_logger().info("first color frame received")
        self._color_data = msg.data

    def _cb_depth(self, msg: Image):
        if self._depth_arr is None:
            self.get_logger().info(f"first depth frame {msg.width}x{msg.height}")
        self._depth_arr = np.frombuffer(msg.data, np.uint16).reshape(
            msg.height, msg.width).copy()

    # ── per-frame processing ─────────────────────────────────────────
    def process(self):
        if self._color_data is None or self._depth_arr is None:
            return

        # decode image
        img = cv2_decode(self._color_data)
        if img is None:
            return
        self._frame_n += 1

        # YOLO inference
        r_port = self._port_model(img, verbose=False)
        r_plug = self._plug_model(img, verbose=False)

        markers = []
        plugs = []
        ports = []

        # ── process ports (detect boxes) ──────────────────────────
        if r_port[0].boxes is not None:
            for i, box in enumerate(r_port[0].boxes):
                conf = float(box.conf[0].cpu().numpy())
                if conf < self._min_conf:
                    continue
                x1, y1, x2, y2 = map(int, box.xyxy[0].cpu().numpy())
                uc, vc = (x1 + x2) // 2, (y1 + y2) // 2
                d_mm = self._safe_depth(uc, vc)

                if d_mm > 0:
                    X, Y, Z = back_project(uc, vc, d_mm, self._fx, self._fy, self._cx, self._cy)
                    try:
                        pt = project_to_frame(X, Y, Z, self._optical_frame, self._target_frame, self._tf_buf)
                        pd = PortDetect()
                        pd.id = self._port_id_seq
                        pd.center = Point(x=pt.x, y=pt.y, z=pt.z)
                        pd.confidence = conf
                        pd.depth_valid = True
                        ports.append(pd)
                        self._port_id_seq += 1
                        markers.append(make_sphere(pt.x, pt.y, pt.z,
                            self._target_frame, pd.id, "ports", GREEN, 0.008))
                    except Exception:
                        pass

        # ── process plugs (OBB rotated boxes) ─────────────────────
        if hasattr(r_plug[0], 'obb') and r_plug[0].obb is not None:
            for i, obb in enumerate(r_plug[0].obb):
                conf = float(obb.conf[0].cpu().numpy())
                if conf < self._min_conf:
                    continue
                pts = obb.xyxyxyxy[0].cpu().numpy().astype(np.int32).reshape(-1, 2)

                # obb centre pixel
                center = np.mean(pts, axis=0).astype(int)
                uc, vc = center[0], center[1]
                d_mm = self._safe_depth(uc, vc)

                # OBB direction: midpoints of the two long edges
                mid1 = (pts[0].astype(float) + pts[1]) / 2.0
                mid2 = (pts[2].astype(float) + pts[3]) / 2.0

                plug = PlugDetect()
                plug.id = self._plug_id_seq
                plug.confidence = conf
                plug.depth_valid = d_mm > 0

                if d_mm > 0:
                    # back-project centre
                    Xc, Yc, Zc = back_project(uc, vc, d_mm, self._fx, self._fy, self._cx, self._cy)

                    # back-project midpoints to get 3D direction
                    d1 = self._safe_depth(int(mid1[0]), int(mid1[1]))
                    d2 = self._safe_depth(int(mid2[0]), int(mid2[1]))
                    yaw = 0.0
                    if d1 > 0 and d2 > 0:
                        X1, Y1, Z1 = back_project(int(mid1[0]), int(mid1[1]), d1, self._fx, self._fy, self._cx, self._cy)
                        X2, Y2, Z2 = back_project(int(mid2[0]), int(mid2[1]), d2, self._fx, self._fy, self._cx, self._cy)
                        try:
                            pt1 = project_to_frame(X1, Y1, Z1, self._optical_frame, self._target_frame, self._tf_buf)
                            pt2 = project_to_frame(X2, Y2, Z2, self._optical_frame, self._target_frame, self._tf_buf)
                            dx = pt1.x - pt2.x
                            dy = pt1.y - pt2.y
                            yaw = math.atan2(dy, dx)
                        except Exception:
                            yaw = 0.0

                    try:
                        pt = project_to_frame(Xc, Yc, Zc, self._optical_frame, self._target_frame, self._tf_buf)
                        plug.pose.position = Point(x=pt.x, y=pt.y, z=pt.z)
                        plug.pose.orientation = quat_from_yaw(yaw)
                        plug.cable_yaw = yaw

                        plugs.append(plug)
                        self._plug_id_seq += 1

                        # markers
                        markers.append(make_sphere(pt.x, pt.y, pt.z,
                            self._target_frame, plug.id, "plugs", RED, 0.008))
                        # direction arrow (5cm long in XY plane)
                        arrow_len = 0.05
                        markers.append(make_arrow(
                            (pt.x, pt.y, pt.z),
                            (arrow_len * math.cos(yaw), arrow_len * math.sin(yaw), 0.0),
                            self._target_frame, plug.id + 1000, "plug_dir", MAGENTA))
                    except Exception:
                        pass

        # ── publish detection arrays ──────────────────────────────
        plug_array = PlugDetectArray()
        plug_array.header.stamp = self.get_clock().now().to_msg()
        plug_array.header.frame_id = self._target_frame
        plug_array.plugs = plugs
        self._pub_plugs.publish(plug_array)

        port_array = PortDetectArray()
        port_array.header.stamp = self.get_clock().now().to_msg()
        port_array.header.frame_id = self._target_frame
        port_array.ports = ports
        self._pub_ports.publish(port_array)

        # ── arm target assignment ─────────────────────────────────
        valid_plugs = [p for p in plugs if p.depth_valid]
        # sort by Y coordinate: left arm (y large, most positive) first
        valid_plugs.sort(key=lambda p: p.pose.position.y, reverse=True)

        left_target = None
        right_target = None

        if len(valid_plugs) >= 2:
            # leftmost → left arm, rightmost → right arm
            left_target = self._make_arm_target(valid_plugs[0], "left")
            right_target = self._make_arm_target(valid_plugs[-1], "right")
        elif len(valid_plugs) == 1:
            if self._default_arm == "left":
                left_target = self._make_arm_target(valid_plugs[0], "left")
            else:
                right_target = self._make_arm_target(valid_plugs[0], "right")

        if left_target is not None:
            self._pub_left.publish(left_target)
        if right_target is not None:
            self._pub_right.publish(right_target)

        # ── publish markers ───────────────────────────────────────
        publish_markers(self._pub_markers, markers)

        # ── optional display ──────────────────────────────────────
        if self._show_disp:
            self._draw_overlay(img, r_port, r_plug, len(valid_plugs))

    # ── helpers ──────────────────────────────────────────────────────
    def _safe_depth(self, uc: int, vc: int) -> int:
        """Read depth at pixel, return 0 if out of bounds."""
        h, w = self._depth_arr.shape
        if 0 <= uc < w and 0 <= vc < h:
            return int(self._depth_arr[vc, uc])
        return 0

    def _make_arm_target(self, plug: PlugDetect, arm: str) -> ArmTarget:
        t = ArmTarget()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = self._target_frame
        t.arm = arm
        t.pose = plug.pose
        t.cable_yaw = plug.cable_yaw
        t.cable_z = plug.pose.position.z
        t.plug_id = plug.id
        return t

    def _draw_overlay(self, img, r_port, r_plug, n_valid: int) -> None:
        """OpenCV overlay window (optional) — only called when _show_disp=True."""
        import cv2

        # draw port boxes
        if r_port[0].boxes is not None:
            for box in r_port[0].boxes:
                x1, y1, x2, y2 = map(int, box.xyxy[0].cpu().numpy())
                cv2.rectangle(img, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # draw plug OBB
        if hasattr(r_plug[0], 'obb') and r_plug[0].obb is not None:
            for obb in r_plug[0].obb:
                pts = obb.xyxyxyxy[0].cpu().numpy().astype(np.int32).reshape(-1, 2)
                cv2.polylines(img, [pts], True, (255, 0, 0), 2)
                mid1 = ((pts[0] + pts[1]) / 2).astype(int)
                mid2 = ((pts[2] + pts[3]) / 2).astype(int)
                cv2.arrowedLine(img, mid2, mid1, (255, 0, 255), 2, tipLength=0.3)

        cv2.putText(img, f"plugs:{n_valid}  frame:{self._frame_n}",
                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        cv2.imshow("detect_both", img)
        # waitKey is called from main() loop for responsiveness


# ── pure functions (no ROS deps) ─────────────────────────────────────

def cv2_decode(data: bytes):
    """Decode JPEG bytes to BGR numpy array."""
    import cv2
    return cv2.imdecode(np.frombuffer(data, np.uint8), cv2.IMREAD_COLOR)


def quat_from_yaw(yaw: float) -> Quaternion:
    """Quaternion encoding a pure Z-axis rotation."""
    return Quaternion(
        x=0.0, y=0.0,
        z=float(math.sin(yaw / 2.0)),
        w=float(math.cos(yaw / 2.0)),
    )


# ── main ─────────────────────────────────────────────────────────────

def main():
    import cv2

    rclpy.init()
    node = DetectBothNode()
    show = node._show_disp

    if show:
        cv2.namedWindow("detect_both", cv2.WINDOW_NORMAL)
        cv2.resizeWindow("detect_both", 960, 540)

    # warmup
    for _ in range(10):
        rclpy.spin_once(node, timeout_sec=0.01)

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.001)
            node.process()
            if show:
                cv2.waitKey(1)
    except KeyboardInterrupt:
        pass
    finally:
        if show:
            cv2.destroyWindow("detect_both")
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
