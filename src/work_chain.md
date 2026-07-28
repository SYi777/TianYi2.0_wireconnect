# 线缆连接 — 自研规划链路

> 目标: 检测插头位姿 → 自研 move_group 避碰规划 → 手掌到线缆正上方5cm
> 最后更新: 2026-07-28

---

## 架构全景

```
相机 (Orin)                     笔记本 (192.168.41.5)                      机器人 (192.168.41.1)
                          ┌─────────────────────────────────┐
  YOLO detect (端口) ─┐   │  detect_both.py (扩展)           │
  YOLO OBB (插头+方向) ─┤  │   → /detected_plug (PoseStamped) │
  深度图 ──────────────┘  │                                  │
                          │  table_from_depth.py (新建)       │
                          │   深度采样 → 桌面z → PlanningScene │
                          │                                  │
                          │  cable_tracker.py (新建) ⭐核心    │
                          │   PlanningScene:                  │
                          │   ├─ 桌面障碍物 box                │
                          │   ├─ 目标位姿 (插头上方5cm)         │
                          │   └─ OMPL 避碰规划                 │
                          │   execute:                        │
                          │   move_group.plan() → trajectory  │
                          │        ↓                          │
                          │   trajectory_bridge               │
                          │        ↓                          │
                          │   /jointspace_commands_L ──DDS──→ XARM Ruckig → 电机
                          └─────────────────────────────────┘

不经过 XARM QP笛卡尔 → 不受 0.2m dis_err_bound 限制
```

---

## 1. RViz MotionPlanning 验证朝向

先在 RViz 里拖拽末端到理想姿态，读出四元数，确认朝向效果。

### 启动命令

```bash
# === 本机 终端1: 启动完整 demo (RSP + move_group + RViz) ===
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/ROS/moveit_with_hand_ws/install/setup.bash
ros2 launch tianyi2_moveit_config demo.launch.py

# 如果要连接真机 joint_states (可选，看实时姿态):
# 先 ssh 机器人 pkill -f robot_state_publisher (避免 TF 冲突)
```

### RViz 操作步骤

1. 左侧面板 **MotionPlanning** → Planning Group 选 `left_arm`
2. 勾选 **Allow Approx IK Solutions**
3. 在 3D 视图中拖拽 `left_tcp_link` 末端球（橙色/绿色交互标记）
4. 拖动到目标姿态：**手掌面朝下，指尖朝桌面**
5. 展开 **Planning** 标签 → 点击 **Update** 查看当前末端位姿
6. 在 **Select Goal State** 中读取 `position (x,y,z)` 和 `orientation (x,y,z,w)`
7. 点 **Plan** 验证 IK 可解
8. 把四元数填回下方 "朝向参考值"

### 朝向参考值 (待 RViz 拖拽确认)

```
waist_yaw_link 坐标系:
  X → 前方
  Y → 左侧
  Z → 上方

预计姿态 (插头在正前方桌面):
  手掌面朝下 + 指尖朝桌面 + 拇指在上方
  position:  x≈0.6, y≈0.0, z≈0.05  (插头上方)
  orientation:  x=0.5, y=-0.5, z=0.5, w=0.5   ← 估算，待 RViz 验证
```

---

## 2. left_tcp_link → 手掌朝向推导

### 运动学链

```
wrist_roll_l_link (腕部最后一个主动关节)
  → left_tcp_joint      fixed  xyz="0 0 -0.085"  rpy="0 0 0"
    → left_tcp_link       ← move_group 规划的目标 frame
      → left_flange_joint fixed  xyz="0 0 0"      rpy="0 0 0"
        → left_flange_link (圆柱 Ø40mm × 31mm)
          → left_hand_to_tcp  fixed  xyz="0 0 0.031"  rpy="3.14 0 -1.5708"
            → L_base_link   ← 手部基座

L_base_link 方向 (在 left_tcp_link 坐标系下):
  手 X ← TCP -Y
  手 Y ← TCP -X
  手 Z ← TCP -Z

手指关节轴: (0,0,±1) → 手指绕 L_base_link Z 轴旋转弯曲
```

### 目标朝向定义

| 条件 | 描述 |
|------|------|
| 手掌面朝下 | palm 法向量指向世界 +Z（朝天花板） |
| 指尖卷曲朝下 | 手指指端指向桌面方向（世界 -Z） |
| 拇指-食指连线 ⊥ 线缆 | 手部Y轴（拇指-小指方向）⊥ 线缆长轴 |

### OBB 方向 → 目标 Quaternion

```
输入: OBB 长边方向角 θ (在 waist_yaw_link XY 平面的投影)
  拇指侧方向 = θ + π/2  (垂直于线缆)

目标朝向 = 手掌朝下旋转 × 拇指侧方向旋转

手掌朝下: 绕 X 轴旋转 -π/2 (TCP Z 指向世界 -Z)
         q_palm = [sin(-π/4), 0, 0, cos(π/4)]
                ≈ [-0.707, 0, 0, 0.707]

拇指定向: 绕 Z 轴旋转 (θ + π/2)
         q_thumb = [0, 0, sin((θ+π/2)/2), cos((θ+π/2)/2)]

最终: q_target = q_thumb × q_palm  (四元数乘法)
```

> ⚠️ 以上为推测，请在 RViz 中拖拽确认后以实际值为准

---

## 3. 桌面障碍物策略

### 核心思路: 障碍物低于线缆

```
waist_yaw_link Z ↑
  ┌─────────────────────────────┐
  │  🎯 目标 z = cable_z + 0.05 │  ← 规划目标 (插头上方5cm)
  │  ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ │
  │  🔌 线缆 z = cable_z        │  ← 检测值 (线缆平放桌面)
  │  ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ │
  │  📦 障碍物 top = cable_z-0.02│  ← 故意低于检测面2cm
  │  ████████████████████████████│  ← 桌面 box (5cm厚)
  │  📦 障碍物 bottom = z-0.05  │
  └─────────────────────────────┘
```

**关键设计:**
- 障碍物 top face 故意低于线缆检测值 2cm → 线缆总是在障碍物上方
- 深度图噪声 ±1cm 不会导致线缆被包
- 2cm 余量对机械臂刚度安全可行
- 桌面 z 直接从插头检测 z 取（线缆平放桌面=桌面高度）

### 获取桌面 z

```python
from collections import deque
import numpy as np

class TableEstimator:
    def __init__(self, window=10):
        self._z_buffer = deque(maxlen=window)

    def update(self, cable_z: float):
        """每帧检测到插头后更新"""
        self._z_buffer.append(cable_z)

    @property
    def table_z(self) -> float:
        return float(np.median(self._z_buffer))

    @property
    def obstacle_top(self) -> float:
        """障碍物顶面 = 桌面 - 2cm"""
        return self.table_z - 0.02
```

---

## 4. 代码文件清单

| # | 文件 | 位置 | 功能 | 状态 |
|---|------|------|------|:--:|
| 1 | `detect_both.py` | `detect/scripts/` | **扩展**: 加 PoseStamped topic | ⬜ |
| 2 | `cable_tracker.py` | `detect/scripts/` | **新建**: 规划+跟踪核心 | ⬜ |
| 3 | `work_chain.md` | 根目录 | 本文档 | ✅ |

### `detect_both.py` 扩展点 (改10行)

当前只发 `MarkerArray`(SPHERE)，需要加发 `PoseStamped`:

```python
# 新增 import
from geometry_msgs.msg import PoseStamped

# 在 __init__ 中加 publisher
self._pose_pub = self.create_publisher(PoseStamped, "/detected_plug", 10)

# 在 _make_marker 后面，对每个插头 OBB 发布 PoseStamped:
# - position: 3D 坐标 (已有)
# - orientation: OBB 长边方向角 → 四元数 (新增)
```

### `cable_tracker.py` 伪代码

```python
class CableTracker(Node):
    def __init__(self):
        # Sub: /detected_plug, /joint_states
        # Init: move_group("left_arm"), planning_scene
        # 加桌面 box 到 PlanningScene
        # 设手部手势: cable_grasp

    def update_table(self, plug_z):
        """中值滤波更新桌面高度"""
        self._z_buffer.append(plug_z)
        table_z = median(self._z_buffer)
        # 移动 table box: top = table_z - 0.02

    def compute_target(self, plug_pose):
        """插头位姿 → 目标位姿"""
        target = Pose()
        target.position.x = plug_pose.position.x
        target.position.y = plug_pose.position.y
        target.position.z = plug_pose.position.z + 0.05  # 上方5cm
        # orientation = 手掌朝下 × 拇指⊥线缆 (见 §2)
        return target

    def run(self):
        # 等待第一帧检测
        # while rclpy.ok():
        #   plug = latest /detected_plug
        #   update_table(plug.z)
        #   target = compute_target(plug)
        #   move_group.set_pose_target(target)
        #   plan = move_group.plan()
        #   if plan: move_group.execute(plan)
        #   到位后等待下一帧, 判断偏移 >阈值 → 重规划
```

---

## 5. 环境启动命令速查

```bash
# ===== 机器人侧 (SSH ubuntu@192.168.41.1) =====
# 终端1: XARM 启动
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 终端2: 初始化手臂
source /home/ubuntu/XARM/install/setup.bash
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
ros2 control switch_controllers --activate jointspace_arm_L_controller

# ===== 本机 =====
# 每个终端:
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/ROS/moveit_with_hand_ws/install/setup.bash

# 终端1: move_group
ros2 launch tianyi2_moveit_config move_group.launch.py

# 终端2: trajectory_bridge (MoveIt→XARM)
ros2 run trajectory_bridge trajectory_bridge --ros-args -p debug:=false

# 终端3: 视觉检测
python3 ~/WireConnect_ws/detect/scripts/detect_both.py

# 终端4: 规划跟踪 (今天要写)
python3 ~/WireConnect_ws/detect/scripts/cable_tracker.py
```

---

## 6. 今天目标

```
☐ RViz 拖拽验证手掌朝向，读出 quaternion (§1)
☐ 扩展 detect_both.py: 发布 PoseStamped + OBB 方向角
☐ 新建 cable_tracker.py: PlanningScene + 桌面box + OMPL规划
☐ 离线验证: DDS收 joint_states + 本机 move_group plan → 看轨迹是否合理
☐ 真机执行: debug=true 单步确认 → debug=false 自动跑
```
