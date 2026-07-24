#!/usr/bin/env python3
"""
取 bbox 中心像素 + 深度值 → 反投影 → TF 变换到 waist_yaw_link.

Usage:
    source /opt/ros/humble/setup.bash
    python3 depth_to_3d.py <uc> <vc>
"""

import sys, numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import PointStamped, Point
import tf2_ros
import tf2_geometry_msgs

# 相机内参 (color)
FX, FY = 689.21, 689.26
CX, CY = 644.15, 360.16


class Depth3D(Node):
    def __init__(self, uc, vc):
        super().__init__("depth_to_3d")
        self._uc, self._vc = uc, vc
        self._depth = None
        self._got = False
        self.create_subscription(Image, "/ob_camera_head/depth/image_raw", self._cb, 10)
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

    def _cb(self, msg):
        if self._got: return
        arr = np.frombuffer(msg.data, dtype=np.uint16).reshape(msg.height, msg.width)
        self._depth = arr[self._vc, self._uc]  # mm
        self._got = True

    def compute(self):
        while not self._got and rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.1)

        Z_m = self._depth / 1000.0
        X = (self._uc - CX) * Z_m / FX
        Y = (self._vc - CY) * Z_m / FY

        # optical frame → waist_yaw_link
        ps = PointStamped()
        ps.header.frame_id = "ob_camera_head_color_optical_frame"
        ps.point = Point(x=X, y=Y, z=Z_m)

        try:
            tf = self._tf_buf.lookup_transform("waist_yaw_link",
                "ob_camera_head_color_optical_frame", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=2.0))
            ps_tf = tf2_geometry_msgs.do_transform_point(ps, tf)

            print(f"像素 ({self._uc},{self._vc}) 深度={self._depth}mm")
            print(f"光学坐标系: [{X:+.4f}, {Y:+.4f}, {Z_m:+.4f}] m")
            print(f"waist_yaw_link: [{ps_tf.point.x:+.4f}, {ps_tf.point.y:+.4f}, {ps_tf.point.z:+.4f}] m")
        except Exception as e:
            print(f"像素 ({self._uc},{self._vc}) 深度={self._depth}mm")
            print(f"光学坐标系: [{X:+.4f}, {Y:+.4f}, {Z_m:+.4f}] m")
            print(f"TF变换失败: {e}")


def main():
    if len(sys.argv) != 3:
        print("用法: python3 depth_to_3d.py <u> <v>")
        sys.exit(1)
    uc, vc = int(sys.argv[1]), int(sys.argv[2])
    rclpy.init()
    node = Depth3D(uc, vc)
    node.compute()
    node.destroy_node(); rclpy.shutdown()


if __name__ == "__main__": main()
