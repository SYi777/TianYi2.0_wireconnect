# 视觉识别 — 命令速查

> 最后更新: 2026-07-24

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

空格拍图, q 退出。图像存到 `detect/images/`。需要相机在发 `/ob_camera_head/color/image_raw/compressed`。

---

## 2. 实时检测

```bash
python3 ~/WireConnect_ws/detect/scripts/detect_live.py
```

YOLO 实时推理 + 画框显示。

---

## 3. 标注 (labelme)

```bash
pip install labelme
labelme ~/WireConnect_ws/detect/images
```

框完标注后, JSON 转 YOLO 格式:

```bash
cd ~/WireConnect_ws/detect/images
for f in *.json; do
    python3 -c "
import json, os
f = '$f'
data = json.load(open(f))
h, w = data['imageHeight'], data['imageWidth']
lines = []
for s in data['shapes']:
    pts = s['points']
    x1,y1 = pts[0]; x2,y2 = pts[1]
    cx = ((x1+x2)/2)/w; cy = ((y1+y2)/2)/h
    bw = abs(x2-x1)/w; bh = abs(y2-y1)/h
    lines.append(f'0 {cx:.6f} {cy:.6f} {bw:.6f} {bh:.6f}')
open(f.replace('.json','.txt'),'w').write('\n'.join(lines))
"
done
echo "转换: $(ls *.txt 2>/dev/null | wc -l) 个"
```

---

## 4. 训练

```bash
cd ~/WireConnect_ws/detect

# 划分数据集 (80/20)
mkdir -p dataset/train/images dataset/train/labels dataset/val/images dataset/val/labels
python3 -c "
import os, random, shutil
imgs = sorted([f for f in os.listdir('images') if f.endswith('.jpg')])
random.seed(42); random.shuffle(imgs)
split = int(len(imgs)*0.8)
for i,f in enumerate(imgs):
    sub = 'train' if i < split else 'val'
    shutil.copy(f'images/{f}', f'dataset/{sub}/images/{f}')
    txt = f.replace('.jpg','.txt')
    if os.path.exists(f'images/{txt}'):
        shutil.copy(f'images/{txt}', f'dataset/{sub}/labels/{txt}')
print(f'train:{split} val:{len(imgs)-split}')
"

# 训练配置
cat > dataset/data.yaml << 'EOF'
path: /home/syi777/WireConnect_ws/detect/dataset
train: train/images
val: val/images
names:
  0: usb_a_port
nc: 1
EOF

# 开始训练 (GPU)
yolo detect train \
  data=/home/syi777/WireConnect_ws/detect/dataset/data.yaml \
  model=yolov8n.pt \
  epochs=100 \
  imgsz=640 \
  project=/home/syi777/WireConnect_ws/detect/runs \
  name=usb_a_port
```

---

## 5. 查看相机原始数据

```bash
# Orin 启动相机
ssh nvidia@192.168.41.2 sudo systemctl start orbbec_head.service

# 本机查看话题
ros2 topic list | grep ob_camera

# 深度图
ros2 topic echo /ob_camera_head/depth/image_raw --once 2>&1 | head -5
```

---

## 6. 深度反投影 + 3D坐标

### 6.1 单点测试

```bash
python3 ~/WireConnect_ws/detect/scripts/depth_to_3d.py <uc> <vc>
```

### 6.2 检测 + 3D坐标

```bash
python3 ~/WireConnect_ws/detect/scripts/detect_3d.py
```

检测所有母口, 输出 waist_yaw_link 坐标系下的 3D 坐标。按回车刷新, q退出。

---

## 7. TF 查询 & 补全

### 7.1 验证 TF 链

```bash
# 相机光学帧在机器人坐标系的位姿
ros2 run tf2_ros tf2_echo base ob_camera_head_color_optical_frame

# 手部TF链是否完整
ros2 run tf2_ros tf2_echo base right_index_1

# 查看完整TF树
ros2 run tf2_tools view_frames
```

### 7.2 补 TF 桥 (仅当缺时)

```bash
# camera_link → ob_camera_head_link (通常不需要, XARM启动已有)
ros2 run tf2_ros static_transform_publisher \
  0 0 0 0 0 0 1 camera_link ob_camera_head_link &

# 腕部法兰延长 (31mm)
ros2 run tf2_ros static_transform_publisher \
  0 0 0.031 0 0 0 1 left_tcp_link left_tcp_flange_link &
```

### 7.3 本机 RViz 看机器人

```bash
source /opt/ros/humble/setup.bash
rviz2
# Add → RobotModel → Description Topic: /xarm_robot_description
```

---

## 8. 当前模型

```
detect/runs/usb_a_port/weights/best.pt
```

mAP50=0.87, P=0.89, R=0.82, YOLOv8n 3.2M参数
