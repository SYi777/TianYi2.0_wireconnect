#!/usr/bin/env python3
"""按空格拍图, q 退出. 存到 ../images/"""
import cv2, os, numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from rclpy.qos import QoSProfile, ReliabilityPolicy

class Capture(Node):
    def __init__(self, save_dir):
        super().__init__("capture")
        self._frame = None
        self._save_dir = save_dir
        os.makedirs(save_dir, exist_ok=True)
        self._count = len([f for f in os.listdir(save_dir) if f.endswith(".jpg")])
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage, "/ob_camera_head/color/image_raw/compressed", self._cb, qos)
        self.get_logger().info(f"存图: {save_dir} 已有{self._count}张")

    def _cb(self, msg):
        self._frame = cv2.imdecode(np.frombuffer(msg.data, np.uint8), cv2.IMREAD_COLOR)

    def save(self):
        if self._frame is None: return
        self._count += 1
        path = os.path.join(self._save_dir, f"{self._count:05d}.jpg")
        cv2.imwrite(path, self._frame)
        self.get_logger().info(f"✓ {path}")

def main():
    save_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "images"))
    rclpy.init()
    node = Capture(save_dir)
    cv2.namedWindow("capture", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("capture", 960, 540)
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
            if node._frame is not None:
                disp = node._frame.copy()
                cv2.putText(disp, f"count:{node._count} SPACE=save Q=quit", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0,255,0), 2)
                cv2.imshow("capture", disp)
            key = cv2.waitKey(1) & 0xFF
            if key == ord("q"): break
            elif key == ord(" "): node.save()
    except KeyboardInterrupt: pass
    finally:
        cv2.destroyAllWindows(); node.destroy_node(); rclpy.shutdown()
        print(f"共{node._count}张 → {save_dir}")

if __name__ == "__main__": main()
