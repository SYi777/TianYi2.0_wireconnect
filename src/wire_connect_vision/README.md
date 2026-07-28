# wire_connect_vision — 视觉检测包

> YOLO 双模型实时推理：端口 (detect) + 插头 (OBB) → 深度反投影 → TF 变换 → 手臂目标分配

---

## 包结构

```
wire_connect_vision/
├── wire_connect_vision/
│   ├── __init__.py
│   ├── detect_both_node.py     # ⭐ 主节点：检测+分配决策
│   ├── depth_projection.py     # 深度反投影 + TF 坐标变换
│   └── viz_utils.py            # RViz MarkerArray 构造函数
├── models/
│   ├── port_detect.pt          # YOLOv8n detect 端口模型权重
│   └── plug_obb.pt             # YOLOv8n-obb 插头模型权重
├── launch/
│   └── detect_both.launch.py   # 启动文件
├── config/
│   └── camera.yaml             # 相机内参 (fx,fy,cx,cy)
├── package.xml
├── setup.py
├── setup.cfg
└── README.md
```

## 话题通信

```
输入:
  /ob_camera_head/color/image_raw/compressed  (CompressedImage, BEST_EFFORT)
  /ob_camera_head/depth/image_raw             (Image, 16UC1 mm)
  /tf                                          (TFMessage, 动态TF)
  /tf_static                                   (TFMessage, 静态TF)

输出:
  /vision/plugs            (PlugDetectArray)   所有插头 + 方向角
  /vision/ports            (PortDetectArray)   所有 USB-A 母口
  /vision/left_target      (ArmTarget)         ← 左手规划目标
  /vision/right_target     (ArmTarget)         ← 右手规划目标
  /vision/detected_objects  (MarkerArray)       RViz 可视化
```

## 分配决策

```
每帧检测到的有效插头 (depth_valid=true) 按 waist_yaw_link Y 坐标排序:

  2+ 个插头:  left_target  ← Y 最大 (最靠左)
              right_target ← Y 最小 (最靠右)

  1 个插头:   优先分配给 default_arm (默认 "left")

  0 个插头:   不发布 left_target / right_target
```

**决策放在视觉包的理由：**
- "左/右"是空间选择，不依赖任务状态机
- 下游规划节点 (`wire_connect_planner`) 直接订阅 `left_target` / `right_target`，无需自己做空间推理
- 状态机只需根据任务阶段决定用哪个手的 target

## 自定义消息

依赖 [`wire_connect_msgs`](../wire_connect_msgs/):

| 消息 | 关键字段 |
|------|----------|
| `PlugDetect` | `pose`(位置+方向), `cable_yaw`, `depth_valid` |
| `PlugDetectArray` | `plugs[]` |
| `PortDetect` | `center`(3D点), `depth_valid` |
| `PortDetectArray` | `ports[]` |
| **`ArmTarget`** | `arm`("left"/"right"), `pose`, `cable_yaw`, `cable_z`, `plug_id` |

### `ArmTarget.pose.orientation` 的含义

```
pose.orientation = quat_from_euler(0, 0, cable_yaw)

只编码线缆方向 (绕Z旋转)，不包含手掌朝向。
手掌朝向由规划节点根据 cable_yaw 自行计算:
  拇指定向 = cable_yaw ± π/2  (左手 +π/2, 右手 -π/2)
  手掌朝下 = 绕X旋转 -π/2
```

### `ArmTarget.cable_z` 的用途

下游规划节点用 `cable_z` 计算桌面障碍物 box 的位置：
- 障碍物 top = `cable_z - 0.02` (低于检测面2cm)
- 障碍物 bottom = `top - 0.05` (5cm厚)
- 目标位姿 z = `cable_z + 0.05` (插头上方5cm)

## 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `model_port` | (launch指定) | YOLO detect 模型路径 |
| `model_plug` | (launch指定) | YOLO OBB 模型路径 |
| `fx/fy/cx/cy` | 689.21/689.26/644.15/360.16 | 相机内参 |
| `target_frame` | `waist_yaw_link` | 输出 TF 坐标系 |
| `optical_frame` | `ob_camera_head_color_optical_frame` | 相机光学帧 |
| `min_confidence` | `0.5` | YOLO 最低置信度 |
| `default_arm` | `left` | 仅1个插头时分配给哪只手 |
| `show_display` | `true` | OpenCV 实时显示窗口 |
| `publish_rate` | `30.0` | 最大推理频率 (Hz) |

## OBB 方向提取算法

```
1. YOLO OBB 输出 4 个角点 pts[0..3]
2. mid1 = (pts[0]+pts[1])/2  → 第一条长边中点
   mid2 = (pts[2]+pts[3])/2  → 第二条长边中点
3. mid1, mid2 分别深度反投影 → 光学帧3D坐标
4. TF 变换到 target_frame → (x1,y1,z1), (x2,y2,z2)
5. cable_yaw = atan2(y1-y2, x1-x2)  ← XY平面投影方向
6. pose.orientation = quat_from_yaw(cable_yaw)
```

## 深度空洞处理

- `depth[vc,uc] == 0` → `depth_valid = false`
- `PlugDetectArray` 中包含所有检测 (含无效的)，供监控用
- `ArmTarget` **只用** `depth_valid = true` 的插头
- 如果所有插头都无效 → 不发布 arm target

## 启动

```bash
# 环境
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 确保模型文件在 models/ 目录
ls ~/WireConnect_ws/src/wire_connect_vision/models/

# 启动
ros2 launch wire_connect_vision detect_both.launch.py

# 或手动运行
ros2 run wire_connect_vision detect_both \
  --ros-args -p model_port:=/path/to/port_detect.pt \
  -p model_plug:=/path/to/plug_obb.pt
```

## 与下游规划节点的约定

1. 规划节点订阅 `/vision/left_target` 和 `/vision/right_target`
2. 从 `ArmTarget` 中取出：
   - `pose.position` → 插头 3D 位置
   - `cable_yaw` → 线缆方向角，用于计算手掌朝向
   - `cable_z` → 用于计算桌面障碍物位置
3. 规划目标：
   - 位置 = `(pose.x, pose.y, cable_z + 0.05)`
   - 朝向 = 手掌朝下 × 拇指⊥线缆 (由 `cable_yaw` 导出)
4. 手势：`cable_grasp` 预设 (手指卷曲 ~40%)

## 节点启动后的状态转换

```
init → warmup (30帧) → running (持续检测+发布)
                           │
                           ├─ 无有效检测: 不发 arm target, 发空 arrays
                           ├─ 1个有效插头: 只发 default_arm 的 target
                           └─ 2+个有效插头: 左/右各发一个 target
```
