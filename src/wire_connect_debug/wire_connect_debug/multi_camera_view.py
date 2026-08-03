#!/usr/bin/env python3
"""三路相机可视化 — 头部 + 左右腕部 RGB. 15Hz 显示, JPEG 压缩后传输."""
import cv2
import numpy as np
import time
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Image


TOPICS = {
    "head":  "/ob_camera_head/color/image_raw",
    "wrist_r": "/camera_wrist/camera_wrist/color/image_rect_raw",
    "wrist_l": "/camera_wrist_left/camera_wrist_left/color/image_rect_raw",
}


class MultiCameraView(Node):
    def __init__(self):
        super().__init__("multi_camera_view")
        qos = QoSProfile(depth=2, reliability=ReliabilityPolicy.BEST_EFFORT)
        self._frames = {}
        for name, topic in TOPICS.items():
            self._frames[name] = None
            self.create_subscription(Image, topic, lambda m, n=name: self._cb(m, n), qos)

        # canvas: head(1280x720) above, wrists(640x480) below → total 1280x1200
        self._cw, self._ch = 1280, 1200
        cv2.namedWindow("cameras", cv2.WINDOW_NORMAL)
        cv2.resizeWindow("cameras", self._cw // 2, self._ch // 2)
        self._last_show = 0.0
        self.get_logger().info("ready — q=quit")

    def _cb(self, msg: Image, name: str):
        # decode raw → JPEG (压缩, 减小 X11 带宽)
        data = bytes(msg.data)
        frame = np.frombuffer(data, np.uint8).reshape(msg.height, msg.width, 3)
        if msg.encoding == "rgb8":
            frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
        # store as JPEG to keep in callback cheap; decode in show()
        _, jpeg = cv2.imencode(".jpg", frame, [cv2.IMWRITE_JPEG_QUALITY, 60])
        self._frames[name] = jpeg

    def show(self):
        now = time.time()
        if now - self._last_show < 0.066:  # ~15Hz
            return
        self._last_show = now

        def _get(name, w, h):
            jpeg = self._frames.get(name)
            if jpeg is not None:
                img = cv2.imdecode(jpeg, cv2.IMREAD_COLOR)
                return cv2.resize(img, (w, h))
            return np.zeros((h, w, 3), np.uint8)

        head = _get("head", 1280, 720)
        wrist_l = _get("wrist_l", 640, 480)
        wrist_r = _get("wrist_r", 640, 480)

        bottom = np.hstack([wrist_l, wrist_r])
        canvas = np.vstack([head, bottom])

        cv2.putText(canvas, "HEAD", (5, 24), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,0), 2)
        cv2.putText(canvas, "L", (10, 750), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,0), 2)
        cv2.putText(canvas, "R", (650, 750), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,0), 2)
        cv2.imshow("cameras", canvas)


def main():
    rclpy.init()
    node = MultiCameraView()
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.005)
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
