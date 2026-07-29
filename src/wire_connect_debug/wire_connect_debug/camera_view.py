#!/usr/bin/env python3
"""Orbbec camera RGB-D viewer — no YOLO, pure display."""

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import CompressedImage, Image


class CameraView(Node):
    def __init__(self):
        super().__init__("camera_view")
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)

        self.create_subscription(CompressedImage,
            "/ob_camera_head/color/image_raw/compressed", self._cb_c, qos)
        self.create_subscription(Image,
            "/ob_camera_head/depth/image_raw", self._cb_d, qos)

        self._color = None
        self._depth = None

        cv2.namedWindow("color", cv2.WINDOW_NORMAL)
        cv2.resizeWindow("color", 960, 540)
        cv2.namedWindow("depth", cv2.WINDOW_NORMAL)
        cv2.resizeWindow("depth", 960, 540)

        self.get_logger().info("camera_view ready — q quit")

    def _cb_c(self, m):
        self._color = m.data

    def _cb_d(self, m):
        self._depth = np.frombuffer(m.data, np.uint16).reshape(m.height, m.width).copy()

    def show(self):
        if self._color is not None:
            img = cv2.imdecode(np.frombuffer(self._color, np.uint8), cv2.IMREAD_COLOR)
            if img is not None:
                cv2.imshow("color", img)
        if self._depth is not None:
            d = self._depth.astype(np.float32)
            d = np.clip(d / 2000.0 * 255, 0, 255).astype(np.uint8)
            cv2.imshow("depth", d)


def main():
    rclpy.init()
    node = CameraView()
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.001)
            node.show()
            if cv2.waitKey(1) in (27, ord("q")):
                break
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        try: rclpy.shutdown()
        except: pass


if __name__ == "__main__":
    main()
