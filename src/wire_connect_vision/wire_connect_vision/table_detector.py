#!/usr/bin/env python3
"""Table edge detector — find floor→table depth jump, compute base→table distance.

Camera looks forward+down from head. Bottom rows = ground (far).
Move up = table surface (closer). Depth discontinuity = table front edge.

Publishes:
  /vision/table          (TableInfo) — table z + XY bounds in waist_yaw_link
  /vision/table_marker   (Marker)
"""

import numpy as np
from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy

from sensor_msgs.msg import Image
from geometry_msgs.msg import Point, Pose, Vector3
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker

from wire_connect_msgs.msg import TableInfo
from .depth_projection import back_project, project_to_frame


class TableDetector(Node):
    def __init__(self):
        super().__init__("table_detector")

        self.declare_parameter("fx", 689.21)
        self.declare_parameter("fy", 689.26)
        self.declare_parameter("cx", 644.15)
        self.declare_parameter("cy", 360.16)
        self.declare_parameter("target_frame", "waist_yaw_link")
        self.declare_parameter("optical_frame", "ob_camera_head_color_optical_frame")
        self.declare_parameter("interval_sec", 2.0)
        self.declare_parameter("jump_thresh", 0.10)     # 10cm depth jump = edge
        self.declare_parameter("table_thickness", 0.05)
        self.declare_parameter("show_debug", False)

        self._fx = self.get_parameter("fx").value
        self._fy = self.get_parameter("fy").value
        self._cx = self.get_parameter("cx").value
        self._cy = self.get_parameter("cy").value
        self._target = self.get_parameter("target_frame").value
        self._optical = self.get_parameter("optical_frame").value
        self._thresh = self.get_parameter("jump_thresh").value
        self._table_h = self.get_parameter("table_thickness").value
        self._show_dbg = self.get_parameter("show_debug").value

        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(Image, "/ob_camera_head/depth/image_raw",
                                 self._cb_depth, qos)
        self._depth_arr = None

        import tf2_ros
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        self._pub = self.create_publisher(TableInfo, "/vision/table", 10)
        from visualization_msgs.msg import Marker
        self._marker_pub = self.create_publisher(Marker, "/vision/table_marker", 10)

        self._z_hist = deque(maxlen=3)
        self._x_hist = deque(maxlen=3)
        self._y_hist = deque(maxlen=3)

        self.create_timer(self.get_parameter("interval_sec").value, self._tick)
        self.get_logger().info("table edge detector ready")

    def _cb_depth(self, m):
        self._depth_arr = np.frombuffer(m.data, np.uint16).reshape(
            m.height, m.width).copy()

    def _tick(self):
        if self._depth_arr is None:
            return
        h, w = self._depth_arr.shape

        # Scan columns, find first depth jump going upward from bottom
        edge_pts = []
        for col in range(w // 4, 3 * w // 4, 8):  # middle 50% columns
            prev_d = 0
            for row in range(h - 40, h // 4, -1):  # bottom → up
                d = float(self._depth_arr[row, col])
                if d == 0:
                    continue
                if prev_d > 0:
                    jump = prev_d - d  # closer = smaller depth
                    if abs(jump) > self._thresh * 1000:  # mm
                        v = row if jump > 0 else row - 1
                        X, Y, Z = back_project(col, v, int(self._depth_arr[v, col]),
                                               self._fx, self._fy, self._cx, self._cy)
                        edge_pts.append((X, Y, Z))
                        break
                prev_d = d

        if len(edge_pts) < 20:
            # fallback: sample bottom-middle depth as floor
            pts = []
            for col in range(w // 4, 3 * w // 4, 16):
                for row in range(h - 80, h - 20, 8):
                    d = int(self._depth_arr[row, col])
                    if d > 0:
                        X, Y, Z = back_project(col, row, d, self._fx, self._fy, self._cx, self._cy)
                        pts.append((X, Y, Z))
                if len(pts) > 50:
                    break
            self.get_logger().warn(f"no edge found, using {len(pts)} floor pts")
            edge_pts = pts

        # TF → target frame
        pts_t = []
        for X, Y, Z in edge_pts:
            try:
                pt = project_to_frame(X, Y, Z, self._optical, self._target, self._tf_buf, 0.5)
                pts_t.append((pt.x, pt.y, pt.z))
            except Exception:
                continue

        if len(pts_t) < 10:
            self.get_logger().warn(f"too few TF points: {len(pts_t)}")
            return

        arr = np.array(pts_t)

        # Table surface = the closer points (higher Z = nearer plane)
        z_cluster = arr[:, 2]
        z_med = float(np.median(z_cluster))
        # Keep points near dominant Z (table surface)
        ok = np.abs(z_cluster - z_med) < 0.05
        table_pts = arr[ok]
        if len(table_pts) < 10:
            return

        # table surface Z from detected edge points
        edge_z = float(np.median(table_pts[:, 2]))
        # edge is the front of table (closest to robot)
        edge_x = float(np.median(table_pts[:, 0]))
        edge_y_center = float(np.median(table_pts[:, 1]))

        # Rules: table = 80cm depth(X) × 120cm width(Y), robot at long side centre
        TABLE_DEPTH = 0.8  # X (forward, away from robot along short side)
        TABLE_WIDTH = 1.2  # Y (left-right, along long side)

        x_min = edge_x
        x_max = edge_x + TABLE_DEPTH
        y_min = edge_y_center - TABLE_WIDTH / 2
        y_max = edge_y_center + TABLE_WIDTH / 2

        self._z_hist.append(edge_z)
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
            f"edge x={edge_x:.3f}  table: {TABLE_DEPTH:.1f}d×{TABLE_WIDTH:.1f}w m  "
            f"z={msg.z:.3f}  xy=[{msg.x_min:.2f}~{msg.x_max:.2f}][{msg.y_min:.2f}~{msg.y_max:.2f}]",
            throttle_duration_sec=2.0)

        # marker: full table box
        m = Marker()
        m.header = msg.header; m.ns = "table"; m.id = 0
        m.type = Marker.CUBE; m.action = Marker.ADD
        m.pose.position = Point(x=(x_min + x_max) / 2,
                                y=float(edge_y_center),
                                z=msg.z - self._table_h / 2)
        m.scale = Vector3(x=TABLE_DEPTH, y=TABLE_WIDTH, z=self._table_h)
        m.color = ColorRGBA(r=0.0, g=0.5, b=1.0, a=0.35)
        m.lifetime.sec = 5
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
