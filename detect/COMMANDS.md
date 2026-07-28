# 视觉识别 — 命令速查

> 最后更新: 2026-07-27

---

## 环境

```bash
source /opt/ros/humble/setup.bash
```

---

## 1. 采集图像

```bash
python3 ~/WireConnect_ws/detect/scripts/capture.py
```

空格拍图, q 退出。图像存到 `detect/images/`。

---

## 2. 标注

```bash
# 母口: 矩形框 (R键)
# 插头: 旋转框 (O键), 长边顺线缆方向
labelme ~/WireConnect_ws/detect/images
```

---

## 3. 标注转训练格式

```bash
python3 ~/WireConnect_ws/detect/scripts/convert_labels.py
```

产出: `dataset_port/`(端口 detect) + `dataset_plug_obb/`(插头 OBB), 自动 80/20 划分。

---

## 4. 训练

```bash
# 端口 (YOLO detect)
yolo detect train \
  data=/home/syi777/WireConnect_ws/detect/dataset_port/data.yaml \
  model=yolov8n.pt epochs=100 imgsz=640 batch=16 \
  project=runs_port name=train

# 插头 (YOLO OBB)
yolo obb train \
  data=/home/syi777/WireConnect_ws/detect/dataset_plug_obb/data.yaml \
  model=yolov8n-obb.pt epochs=100 imgsz=640 batch=16 \
  project=runs_plug_obb name=train
```

---

## 5. 实时检测

### 5.1 单模型 (端口 only)
```bash
python3 ~/WireConnect_ws/detect/scripts/detect_live.py
```

### 5.2 单模型 + 3D坐标 (端口 only)
```bash
python3 ~/WireConnect_ws/detect/scripts/detect_3d.py
```

### 5.3 双模型 (端口+插头OBB) + 3D + RViz红/绿球
```bash
python3 ~/WireConnect_ws/detect/scripts/detect_both.py
```

### 5.4 单点深度反投影
```bash
python3 ~/WireConnect_ws/detect/scripts/depth_to_3d.py <uc> <vc>
```

---

## 6. 本机 RViz 可视化机器人+检测结果

```bash
# 机器人: 杀 RSP
ssh ubuntu@192.168.41.1 pkill -f robot_state_publisher

# 本机终端1: RSP (带手URDF, 发TF)
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/ROS/moveit_with_hand_ws/install/setup.bash
ros2 run robot_state_publisher robot_state_publisher \
  --ros-args \
  -p robot_description:="$(xacro ~/WireConnect_ws/ROS/moveit_with_hand_ws/src/tianyi2_moveit_config/urdf/tianyi2.0_complete_with_hands.xacro)"

# 本机终端2: RViz
source /opt/ros/humble/setup.bash
rviz2
# Add → RobotModel
# Add → MarkerArray → Topic /detected_objects, Fixed Frame waist_yaw_link

# 本机终端3: 检测
python3 ~/WireConnect_ws/detect/scripts/detect_both.py
```

---

## 7. TF 查询

```bash
# 相机光学帧位姿
ros2 run tf2_ros tf2_echo base ob_camera_head_color_optical_frame

# 手部TF完整度
ros2 run tf2_ros tf2_echo base left_flange_link

# TF树全景图
ros2 run tf2_tools view_frames
```

---

## 8. 当前模型

| 模型 | 路径 | 类型 | mAP50 |
|------|------|------|:--:|
| 端口 | `detect/runs/detect/runs_port/train/weights/best.pt` | YOLOv8n detect | 0.87 |
| 插头 | `detect/runs/obb/runs_plug_obb/train/weights/best.pt` | YOLOv8n-obb | - |

---

## 9. 相机相关

### 9.1 启动相机 (Orin 上)

```bash
# Orbbec 头部 (SSH Orin)
ssh nvidia@192.168.41.2
source ~/orbbec_camera_ros2/install/setup.bash
ros2 launch orbbec_camera gemini_330_series.launch.py \
  color_width:=640 color_height:=480 depth_width:=640 depth_height:=480

# RealSense 左 (SSH Orin, 串号 260522275730)
source ~/realsense_ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py \
  serial_no:="'260522275730'" camera_name:=camera1 camera_namespace:=camera1

# RealSense 右 (SSH Orin, 串号 260522273200)
ros2 launch realsense2_camera rs_launch.py \
  serial_no:="'260522273200'" camera_name:=camera2 camera_namespace:=camera2
```

### 9.2 本机查看

```bash
# 话题列表
ros2 topic list | grep -E "camera|ob_camera"

# 频率检查
ros2 topic hz /ob_camera_head/color/image_raw
```

### 9.3 三路相机可视化（左 | 头 | 右）

```bash
source /opt/ros/humble/setup.bash
python3 ~/WireConnect_ws/detect/scripts/tri_camera_view.py
```
q 退出, s 截图。

## 10. 相机串号

| 相机 | 串号 | 话题前缀 |
|------|------|------|
| Orbbec 头 | - | `/ob_camera_head/` |
| RealSense 左 | 260522275730 | `/camera1/camera1/` |
| RealSense 右 | 260522273200 | `/camera2/camera2/`
