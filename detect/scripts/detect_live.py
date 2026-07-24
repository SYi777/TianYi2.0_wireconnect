#!/usr/bin/env python3
"""
实时检测 USB-A 母口. 订阅相机彩色图, YOLO推理, 画框显示.

Usage:
    source /opt/ros/humble/setup.bash
    python3 detect_live.py [--model runs/usb_a_port/weights/best.pt]
"""

import sys
import os
import argparse
import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from rclpy.qos import QoSProfile, ReliabilityPolicy
from ultralytics import YOLO


class Detector(Node):
    def __init__(self, model_path):
        super().__init__("detect_live")
        self._model = YOLO(model_path)
        self._frame = None
        self._results = None
        # subscribe to compressed topic (JPEG, 100-200KB/frame vs 2.8MB raw)
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage, "/ob_camera_head/color/image_raw/compressed", self._cb, qos)
        self.get_logger().info(f"model: {model_path}")

    def _cb(self, msg):
        # decode JPEG bytes → BGR
        buf = np.frombuffer(msg.data, dtype=np.uint8)
        self._frame = cv2.imdecode(buf, cv2.IMREAD_COLOR)

    def detect(self):
        if self._frame is None:
            return None
        self._results = self._model(self._frame, verbose=False)
        return self._results

    def annotate(self):
        if self._frame is None:
            return np.zeros((480, 640, 3), dtype=np.uint8)
        if self._results and self._results[0].boxes is not None:
            # draw YOLO boxes
            disp = self._results[0].plot()
            n = len(self._results[0].boxes)
            cv2.putText(disp, f"USB-A ports: {n}", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
        else:
            disp = self._frame.copy()
        return disp


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--model", default="")
    args = parser.parse_args()

    # auto-find best.pt
    model_path = args.model
    if not model_path:
        candidates = [
            os.path.join(os.path.dirname(__file__), "..", "runs", "usb_a_port", "weights", "best.pt"),
            os.path.join(os.path.dirname(__file__), "..", "runs", "usb_a_port", "weights", "last.pt"),
        ]
        for c in candidates:
            if os.path.exists(os.path.normpath(c)):
                model_path = os.path.normpath(c)
                break
    if not model_path or not os.path.exists(model_path):
        print(f"model not found: {model_path}")
        print("  usage: python3 detect_live.py --model <path>")
        sys.exit(1)

    rclpy.init()
    node = Detector(model_path)
    cv2.namedWindow("detect", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("detect", 960, 540)

    frame_count = 0
    infer_every = 1  # GPU: every frame

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
            frame_count += 1

            if frame_count % infer_every == 0:
                node.detect()

            disp = node.annotate()
            # show fps
            cv2.putText(disp, f"infer every {infer_every}frames", (10, 60),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 200, 0), 1)
            cv2.imshow("detect", disp)

            key = cv2.waitKey(1) & 0xFF
            if key == ord("q"):
                break
            elif key == ord("s"):
                cv2.imwrite("screenshot.jpg", disp)
                node.get_logger().info("saved screenshot.jpg")
            elif key == ord("+"):
                infer_every = max(1, infer_every - 1)
                node.get_logger().info(f"infer every {infer_every} frames")
            elif key == ord("-"):
                infer_every = min(30, infer_every + 1)
                node.get_logger().info(f"infer every {infer_every} frames")
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
