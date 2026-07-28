#!/usr/bin/env python3
"""
三路相机实时可视化: RealSense左 | Orbbec头(中) | RealSense右
按 q 退出, s 截图保存到 /tmp/。
Usage: source /opt/ros/humble/setup.bash && python3 tri_camera_view.py
"""
import cv2, numpy as np, time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from rclpy.qos import QoSProfile, ReliabilityPolicy

TOPICS = {
    "left":  "/camera1/camera1/color/image_rect_raw",
    "head":  "/ob_camera_head/color/image_raw",
    "right": "/camera2/camera2/color/image_rect_raw",
}


class TriCameraView(Node):
    def __init__(self):
        super().__init__("tri_camera_view")
        qos = QoSProfile(depth=5, reliability=ReliabilityPolicy.BEST_EFFORT)
        self._bridge = CvBridge()
        self._buf = {k: None for k in TOPICS}
        for name, topic in TOPICS.items():
            self.create_subscription(Image, topic,
                                     lambda m, n=name: self._cb(n, m), qos)
        self.get_logger().info("三路相机订阅已建立. q=退出 s=截图")

    def _cb(self, name, msg):
        try:
            self._buf[name] = self._bridge.imgmsg_to_cv2(msg, "bgr8")
        except Exception:
            pass

    def frame(self, name):
        img = self._buf.get(name)
        return img if img is not None else np.zeros((480, 640, 3), dtype=np.uint8)

    def render(self):
        l, h, r = self.frame("left"), self.frame("head"), self.frame("right")
        H = max(l.shape[0], h.shape[0], r.shape[0])
        W = max(l.shape[1], h.shape[1], r.shape[1])
        l, h, r = [cv2.resize(x, (W, H)) if x.shape != (H, W) else x for x in (l, h, r)]
        return cv2.hconcat([l, h, r])


def main():
    rclpy.init()
    node = TriCameraView()
    win = "D405左 | Orbbec头 | D405右 (q退出 s截图 f全屏)"
    cv2.namedWindow(win, cv2.WINDOW_NORMAL)
    cv2.resizeWindow(win, 1920, 540)
    full = False
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.02)
            img = node.render()
            cv2.imshow(win, img)
            key = cv2.waitKey(1) & 0xFF
            if key == ord("q"):
                break
            elif key == ord("s"):
                p = f"/tmp/tri_cam_{time.strftime('%Y%m%d_%H%M%S')}.jpg"
                cv2.imwrite(p, img)
                node.get_logger().info(f"截图已保存: {p}")
            elif key == ord("f"):
                full = not full
                if full:
                    cv2.setWindowProperty(win, cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
                else:
                    cv2.setWindowProperty(win, cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_NORMAL)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
