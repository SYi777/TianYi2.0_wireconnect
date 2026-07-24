#!/usr/bin/env python3
"""
YOLO检测 + 深度反投影 → 母口3D坐标 (waist_yaw_link).
自动2s刷新, q退出, RViz显示红球.

Usage: source /opt/ros/humble/setup.bash && python3 detect_3d.py
"""
import os, sys, cv2, select, numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image
from rclpy.qos import QoSProfile, ReliabilityPolicy
from ultralytics import YOLO
import tf2_ros, tf2_geometry_msgs as tfg
from geometry_msgs.msg import PointStamped, Point
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import ColorRGBA

FX, FY = 689.21, 689.26
CX, CY = 644.15, 360.16

class Detect3D(Node):
    def __init__(self, model_path):
        super().__init__("detect_3d")
        self._model = YOLO(model_path)
        self._color_data = None
        self._depth_arr = None
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage, "/ob_camera_head/color/image_raw/compressed", self._cb_c, qos)
        self.create_subscription(Image, "/ob_camera_head/depth/image_raw", self._cb_d, 10)
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)
        self._marker_pub = self.create_publisher(MarkerArray, "/detected_ports", 10)

    def _cb_c(self, msg): self._color_data = msg.data
    def _cb_d(self, msg): self._depth_arr = np.frombuffer(msg.data, dtype=np.uint16).reshape(msg.height, msg.width).copy()

    def run_once(self):
        if self._color_data is None or self._depth_arr is None:
            print("等待数据..."); return
        img = cv2.imdecode(np.frombuffer(self._color_data, np.uint8), cv2.IMREAD_COLOR)
        results = self._model(img, verbose=False)
        markers = []

        if results[0].boxes is None or len(results[0].boxes) == 0:
            print("未检测到母口")
        else:
            boxes = results[0].boxes.xyxy.cpu().numpy()
            print(f"检测到 {len(boxes)} 个母口:")
            for i, box in enumerate(boxes):
                uc, vc = int((box[0]+box[2])/2), int((box[1]+box[3])/2)
                d = self._depth_arr[vc, uc]
                if d == 0: print(f"  [{i}] ({uc},{vc}) 深度=无数据"); continue
                Z = d/1000.0; X = (uc-CX)*Z/FX; Y = (vc-CY)*Z/FY
                ps = PointStamped(); ps.header.frame_id = "ob_camera_head_color_optical_frame"
                ps.point = Point(x=X, y=Y, z=Z)
                try:
                    tf = self._tf_buf.lookup_transform("waist_yaw_link", "ob_camera_head_color_optical_frame",
                        rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=1.0))
                    p = tfg.do_transform_point(ps, tf)
                    print(f"  [{i}] ({uc},{vc}) d={d}mm → 腰:[{p.point.x:+.4f},{p.point.y:+.4f},{p.point.z:+.4f}]")
                    m = Marker()
                    m.header.frame_id = "waist_yaw_link"
                    m.header.stamp = rclpy.time.Time().to_msg()
                    m.ns = "usb_ports"; m.id = i; m.type = Marker.SPHERE
                    m.pose.position.x = p.point.x; m.pose.position.y = p.point.y; m.pose.position.z = p.point.z
                    m.scale.x = 0.01; m.scale.y = 0.01; m.scale.z = 0.01
                    m.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=1.0)
                    m.lifetime.sec = 3  # auto-clear after 3s if not refreshed
                    markers.append(m)
                except Exception as e:
                    print(f"  [{i}] ({uc},{vc}) d={d}mm → 光学:[{X:+.4f},{Y:+.4f},{Z:+.4f}] (TF:{e})")

        # clear old + publish new
        del_all = Marker(); del_all.action = Marker.DELETEALL
        markers.insert(0, del_all)
        self._marker_pub.publish(MarkerArray(markers=markers))

def main():
    p = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "runs/usb_a_port/weights/best.pt"))
    if not os.path.exists(p): print(f"no model: {p}"); sys.exit(1)
    rclpy.init(); node = Detect3D(p)
    try:
        for _ in range(50): rclpy.spin_once(node, timeout_sec=0.05)
        print("自动检测中 (2s刷新, q退出)...")
        while rclpy.ok():
            for _ in range(40): rclpy.spin_once(node, timeout_sec=0.05)
            node.run_once()
            if select.select([sys.stdin], [], [], 0)[0]:
                if sys.stdin.readline().strip().lower() in ("q","quit"): break
    finally:
        node.destroy_node()
        try: rclpy.shutdown()
        except: pass

if __name__ == "__main__": main()
