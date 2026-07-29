#!/usr/bin/env python3
"""Green-table detector — colour + depth, runs every 5s.

Extracts green pixels from colour image, samples depth within that region,
back-projects to waist_yaw_link, fits a horizontal plane → TableInfo + Marker.

Publishes:
  /vision/table          (TableInfo)
  /vision/table_marker   (Marker)
"""

import numpy as np
from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy

from sensor_msgs.msg import CompressedImage, Image
from geometry_msgs.msg import Point, Pose, Vector3
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker

from wire_connect_msgs.msg import TableInfo
from .depth_projection import back_project, project_to_frame

# HSV green range (tune if lighting changes)
GREEN_LOW  = (35, 40, 40)
GREEN_HIGH = (85, 255, 255)


class TableDetector(Node):
    def __init__(self):
        super().__init__("table_detector")

        self.declare_parameter("fx", 689.21)
        self.declare_parameter("fy", 689.26)
        self.declare_parameter("cx", 644.15)
        self.declare_parameter("cy", 360.16)
        self.declare_parameter("target_frame", "waist_yaw_link")
        self.declare_parameter("optical_frame", "ob_camera_head_color_optical_frame")
        self.declare_parameter("interval_sec", 5.0)
        self.declare_parameter("show_debug", False)

        self._fx = self.get_parameter("fx").value
        self._show_dbg = self.get_parameter("show_debug").value
        self._fy = self.get_parameter("fy").value
        self._cx = self.get_parameter("cx").value
        self._cy = self.get_parameter("cy").value
        self._target = self.get_parameter("target_frame").value
        self._optical = self.get_parameter("optical_frame").value

        # subscribers
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage,
            "/ob_camera_head/color/image_raw/compressed", self._cb_color, qos)
        self.create_subscription(Image,
            "/ob_camera_head/depth/image_raw", self._cb_depth, qos)

        self._color_data = None
        self._depth_arr = None

        # TF
        import tf2_ros
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # publishers
        self._pub = self.create_publisher(TableInfo, "/vision/table", 10)
        self._marker_pub = self.create_publisher(Marker, "/vision/table_marker", 10)

        # smoothing
        self._z_hist = deque(maxlen=3)
        self._x_hist = deque(maxlen=3)
        self._y_hist = deque(maxlen=3)

        self.create_timer(self.get_parameter("interval_sec").value, self._tick)
        self.get_logger().info("green-table detector ready")

    def _cb_color(self, m):
        self._color_data = m.data

    def _cb_depth(self, m):
        self._depth_arr = np.frombuffer(m.data, np.uint16).reshape(
            m.height, m.width).copy()

    def _tick(self):
        if self._color_data is None or self._depth_arr is None:
            return

        import cv2
        img = cv2.imdecode(np.frombuffer(self._color_data, np.uint8), cv2.IMREAD_COLOR)
        if img is None:
            return

        # 1. green mask
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, GREEN_LOW, GREEN_HIGH)

        if self._show_dbg:
            overlay = img.copy()
            overlay[mask > 0] = overlay[mask > 0] // 2 + [0, 127, 0]
            cv2.imshow("table_mask", overlay)
            cv2.waitKey(1)

        # 2. sample depth in green region (stride 4)
        ys, xs = np.where((mask > 0) & (self._depth_arr > 0))
        if len(xs) < 200:
            self.get_logger().warn(f"too few green+deep points: {len(xs)}")
            return

        # subsample
        idx = np.random.choice(len(xs), min(800, len(xs)), replace=False)
        pts_3d = []
        for i in idx:
            u, v = xs[i], ys[i]
            d = int(self._depth_arr[v, u])
            X, Y, Z = back_project(u, v, d, self._fx, self._fy, self._cx, self._cy)
            pts_3d.append((X, Y, Z))

        # 3. TF → target frame
        pts_target = []
        for X, Y, Z in pts_3d:
            try:
                pt = project_to_frame(X, Y, Z, self._optical, self._target, self._tf_buf, 0.5)
                pts_target.append((pt.x, pt.y, pt.z))
            except Exception:
                continue

        if len(pts_target) < 100:
            self.get_logger().warn(f"too few TF'd points: {len(pts_target)}")
            return

        pts = np.array(pts_target)

        # 4. horizontal plane: median Z, XY 10%-90% range
        z_med = float(np.median(pts[:, 2]))
        # filter outliers > 3cm from median
        ok = np.abs(pts[:, 2] - z_med) < 0.03
        pts_f = pts[ok]
        if len(pts_f) < 50:
            return

        x_min, x_max = float(np.percentile(pts_f[:, 0], 5)), float(np.percentile(pts_f[:, 0], 95))
        y_min, y_max = float(np.percentile(pts_f[:, 1], 5)), float(np.percentile(pts_f[:, 1], 95))

        # 5. smooth
        self._z_hist.append(z_med)
        self._x_hist.append((x_min, x_max))
        self._y_hist.append((y_min, y_max))

        msg = TableInfo()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._target
        msg.z = float(np.mean(list(self._z_hist)))
        msg.x_min = float(np.mean([v[0] for v in self._x_hist]))
        msg.x_max = float(np.mean([v[1] for v in self._x_hist]))
        msg.y_min = float(np.mean([v[0] for v in self._y_hist]))
        msg.y_max = float(np.mean([v[1] for v in self._y_hist]))
        msg.valid = True
        self._pub.publish(msg)

        self.get_logger().info(
            f"table z={msg.z:.3f} x=[{msg.x_min:.2f},{msg.x_max:.2f}] "
            f"y=[{msg.y_min:.2f},{msg.y_max:.2f}] n={len(pts_f)}",
            throttle_duration_sec=4.0)

        # 6. marker
        w = msg.x_max - msg.x_min
        d = msg.y_max - msg.y_min
        h = 0.05
        m = Marker()
        m.header = msg.header
        m.ns = "table"; m.id = 0; m.type = Marker.CUBE; m.action = Marker.ADD
        m.pose.position = Point(
            x=(msg.x_min + msg.x_max) / 2,
            y=(msg.y_min + msg.y_max) / 2,
            z=msg.z - h / 2)
        m.scale = Vector3(x=w, y=d, z=h)
        m.color = ColorRGBA(r=0.0, g=0.5, b=1.0, a=0.35)
        m.lifetime.sec = 10
        self._marker_pub.publish(m)


def main():
    import cv2
    rclpy.init()
    node = TableDetector()
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        try: rclpy.shutdown()
        except: pass


if __name__ == "__main__":
    main()
