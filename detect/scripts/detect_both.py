#!/usr/bin/env python3
"""
双模型实时推理: 端口(绿色矩形)+插头(蓝色OBB+方向箭头)+3D坐标+RViz红/蓝球.
3060全帧推理, q退出, s截图.

Usage: source /opt/ros/humble/setup.bash && python3 detect_both.py
"""
import os, sys, cv2, numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image
from rclpy.qos import QoSProfile, ReliabilityPolicy
from ultralytics import YOLO
import tf2_ros, tf2_geometry_msgs as tfg
from geometry_msgs.msg import PointStamped, Point
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import ColorRGBA

MODEL_PORT = os.path.normpath(os.path.join(os.path.dirname(__file__),"..","runs/detect/runs_port/train/weights/best.pt"))
MODEL_PLUG = os.path.normpath(os.path.join(os.path.dirname(__file__),"..","runs/obb/runs_plug_obb/train/weights/best.pt"))
FX,FY=689.21,689.26; CX,CY=644.15,360.16

class DetectBoth(Node):
    def __init__(self):
        super().__init__("detect_both")
        self._port = YOLO(MODEL_PORT)
        self._plug = YOLO(MODEL_PLUG)
        self._color = None; self._depth = None
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.create_subscription(CompressedImage, "/ob_camera_head/color/image_raw/compressed", self._cb_c, qos)
        self.create_subscription(Image, "/ob_camera_head/depth/image_raw", self._cb_d, 10)
        self._tf = tf2_ros.Buffer()
        tf2_ros.TransformListener(self._tf, self)
        self._pub = self.create_publisher(MarkerArray, "/detected_objects", 10)
        self.get_logger().info("detect_both ready")

    def _cb_c(self, m): self._color = m.data
    def _cb_d(self, m): self._depth = np.frombuffer(m.data, np.uint16).reshape(m.height,m.width).copy()

    def process(self):
        if self._color is None or self._depth is None: return None
        img = cv2.imdecode(np.frombuffer(self._color, np.uint8), cv2.IMREAD_COLOR)
        rp = self._port(img, verbose=False)
        rl = self._plug(img, verbose=False)
        markers = []

        # 端口: 绿色矩形
        if rp[0].boxes is not None:
            for box in rp[0].boxes:
                x1,y1,x2,y2 = map(int, box.xyxy[0].cpu().numpy())
                cv2.rectangle(img, (x1,y1), (x2,y2), (0,255,0), 2)
                cv2.putText(img, "port", (x1,y1-5), cv2.FONT_HERSHEY_SIMPLEX, 0.4, (0,255,0),1)
                uc,vc = (x1+x2)//2, (y1+y2)//2
                d = self._depth[vc, uc]
                if d>0: m=self._make_marker(uc,vc,d,"port",len(markers),(0.0,1.0,0.0)); m and markers.append(m)

        # 插头: 蓝色OBB + 方向
        if hasattr(rl[0],'obb') and rl[0].obb is not None:
            for obb in rl[0].obb:
                pts = obb.xyxyxyxy[0].cpu().numpy().astype(np.int32).reshape(-1,2)
                cv2.polylines(img, [pts], True, (255,0,0), 2)
                mid1 = ((pts[0]+pts[1])/2).astype(int)
                mid2 = ((pts[2]+pts[3])/2).astype(int)
                center = np.mean(pts, axis=0).astype(int)
                cv2.arrowedLine(img, mid2, mid1, (255,0,255), 2, tipLength=0.3)
                cv2.putText(img, "plug", (pts[0][0], pts[0][1]-5), cv2.FONT_HERSHEY_SIMPLEX, 0.4, (255,0,0),1)
                uc,vc = center[0], center[1]
                d = self._depth[vc, uc]
                if d>0: m=self._make_marker(uc,vc,d,"plug",len(markers),(1.0,0.0,0.0)); m and markers.append(m)

        n_port = len(rp[0].boxes) if rp[0].boxes else 0
        n_plug = len(rl[0].obb) if hasattr(rl[0],'obb') and rl[0].obb else 0
        cv2.putText(img, f"ports:{n_port} plugs:{n_plug}", (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,255,0),2)

        # publish markers
        markers = [m for m in markers if m is not None]
        if markers:
            del_all = Marker(); del_all.action = Marker.DELETEALL
            self._pub.publish(MarkerArray(markers=[del_all]+markers))
        return img

    def _make_marker(self, uc, vc, d_mm, label, idx, color):
        Z = d_mm/1000.0; X = (uc-CX)*Z/FX; Y = (vc-CY)*Z/FY
        ps = PointStamped(); ps.header.frame_id = "ob_camera_head_color_optical_frame"
        ps.point = Point(x=X, y=Y, z=Z)
        try:
            t = self._tf.lookup_transform("waist_yaw_link", "ob_camera_head_color_optical_frame",
                rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=1.0))
            p = tfg.do_transform_point(ps, t)
            self.get_logger().info(f"{label}[{idx}] ({uc},{vc}) d={d_mm}mm → 腰:[{p.point.x:+.4f},{p.point.y:+.4f},{p.point.z:+.4f}]")
        except: return None
        m = Marker()
        m.header.frame_id = "waist_yaw_link"; m.header.stamp = rclpy.time.Time().to_msg()
        m.ns = label; m.id = idx; m.type = Marker.SPHERE
        m.pose.position.x = p.point.x; m.pose.position.y = p.point.y; m.pose.position.z = p.point.z
        m.scale.x = 0.008; m.scale.y = 0.008; m.scale.z = 0.008
        m.color = ColorRGBA(r=color[0], g=color[1], b=color[2], a=1.0)
        m.lifetime.sec = 0
        return m

def main():
    rclpy.init(); node = DetectBoth()
    cv2.namedWindow("detect_both", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("detect_both", 960, 540)
    try:
        frame_n = 0
        for _ in range(30): rclpy.spin_once(node, timeout_sec=0.05)
        while rclpy.ok():
            # spin many times to drain DDS buffer
            for _ in range(5): rclpy.spin_once(node, timeout_sec=0.005)
            frame_n += 1
            img = node.process()
            if img is not None:
                cv2.imshow("detect_both", img)
            k = cv2.waitKey(1) & 0xFF
            if k == ord("q"): break
            elif k == ord("s"):
                if img is not None: cv2.imwrite("screenshot_both.jpg", img); print("saved")
    finally:
        cv2.destroyAllWindows(); node.destroy_node()
        try: rclpy.shutdown()
        except: pass

if __name__ == "__main__": main()
