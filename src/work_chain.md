# 线缆连接 — 自研规划链路

> 目标: 检测插头位姿 → 自研 move_group 避碰规划 → 手掌到线缆正上方5cm
> 最后更新: 2026-07-28 17:30

---

## 进度总览

| # | 任务 | 状态 | 备注 |
|---|------|:--:|------|
| 1 | workspace 整合 (src/ 统一构建) | ✅ | 9 packages, colcon build 通过 |
| 2 | `wire_connect_msgs` 自定义消息 | ✅ | 5 个 msg, 编译安装正常 |
| 3 | `wire_connect_vision` 视觉包 | ✅ | YOLO双模型 + 深度反投影 + TF变换 + 左/右分配 |
| 4 | 视觉节点真机测试 | ⚠️ | 识别效果不错，相机话题频繁掉线 |
| 5 | RViz 可视化验证 | ❌ | 相机掉线无法验证 MarkerArray |
| 6 | RViz 拖拽验证手掌朝向 | ⬜ | 待做 |
| 7 | `wire_connect_planner` 规划包 | ⬜ | cable_tracker |
| 8 | 真机规划执行 | ⬜ | |

### 2026-07-28 测试记录

- **相机话题掉线**: `/ob_camera_head/color/image_raw/compressed` 和 depth 话题不持续稳定，时有时无
- **识别效果**: 从少数有效帧来看，YOLO 双模型推理正常，插头 OBB + 端口框均能检出
- **可视化未验证**: 因相机掉线，RViz `/vision/detected_objects` MarkerArray 未能持续观察

---

## 架构全景

```
Orin (相机)                      笔记本 (192.168.41.5)                         机器人 (192.168.41.1)
                          ┌──────────────────────────────────┐
                          │ wire_connect_vision (已就绪 ✅)    │
  color/compressed ────→  │  detect_both_node                 │
  depth/image_raw ─────→  │   → /vision/plugs (PlugDetectArray)│
                          │   → /vision/ports (PortDetectArray)│
                          │   → /vision/left_target (ArmTarget)│
                          │   → /vision/right_target (ArmTarget)│
                          │   → /vision/detected_objects (MarkerArray)│
                          │                                   │
                          │ wire_connect_planner (待建 ⬜)       │
                          │   PlanningScene + TableBox + OMPL   │
                          │   → FollowJointTrajectory           │
                          │        ↓                            │
                          │   trajectory_bridge                 │
                          │        ↓                            │
                          │   /jointspace_commands_L ──DDS──→ XARM Ruckig → 电机
                          └──────────────────────────────────┘

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

### 思路: 对绿色桌面区域采深度 → 局部平面 → 5cm 厚 box

桌子不总完整可见（相机视野有限/手臂遮挡），直接 RANSAC 全局平面不可靠。
改用颜色+深度联合：

```
1. 彩色图提取绿色区域 (工作台面为绿色)
   → mask: HSV 绿色范围 或 YOLO 检测桌面
2. 绿色 mask 内采样深度点 → back_project → waist_yaw_link
3. 对采样点拟合水平面 → z + XY 范围
4. 生成 5cm 厚 box 障碍物
```

**优势：**
- 只看桌子不看线缆/杂物
- 桌子局部可见就能工作
- 不依赖线缆位置推断

### 桌面 box 参数

```
box center Z  = table_z - 0.025  (top = table_z, 5cm厚)
box center XY = 绿色区域采样点 XY 范围的均值
box size      = (x_range, y_range, 0.05)
```

### 深度采样 + 绿色过滤

```python
# 1. 绿色 mask
hsv = cv2.cvtColor(color_img, cv2.COLOR_BGR2HSV)
green_mask = cv2.inRange(hsv, (35, 40, 40), (85, 255, 255))

# 2. 绿色区域内采样深度
ys, xs = np.where(green_mask & depth_mm > 0)
if len(xs) > 100:
    pts_3d = [back_project(x, y, depth_mm[y,x]) for x,y in zip(xs, ys)]
    # TF → waist_yaw_link
    # 取 z 中值 → table_z
    # 取 x,y 分位数 [10%,90%] → x_range, y_range
```

---

## 4. 代码文件清单

| # | 文件 | 位置 | 功能 | 状态 |
|---|------|------|------|:--:|
| 1 | `wire_connect_msgs/` | `src/wire_connect_msgs/` | 自定义消息 (5 msg) | ✅ |
| 2 | `wire_connect_vision/` | `src/wire_connect_vision/` | 视觉检测包 (YOLO+深度+TF+分配) | ✅ |
| 3 | `cable_tracker.py` | 待建 | 规划+跟踪核心 | ⬜ |
| 4 | `work_chain.md` | `src/` | 本文档 | ✅ |

### 已废弃

| 文件 | 原因 |
|------|------|
| `detect/scripts/detect_both.py` | 逻辑已迁移到 `wire_connect_vision/detect_both_node.py` |
| `detect/scripts/detect_3d.py` | 被 detect_both_node 覆盖 |
| `detect/scripts/detect_live.py` | 被 detect_both_node 覆盖 |

---

## 5. 环境启动命令速查

```bash
# ===== 所有终端 =====
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# ===== 本机 =====
# 终端1: 视觉检测
ros2 launch wire_connect_vision detect_both.launch.py

# 带可视化窗口:
ros2 launch wire_connect_vision detect_both.launch.py show_display:=true

# 终端2: RViz (订阅 /vision/detected_objects)
rviz2
# Fixed Frame: waist_yaw_link
# Add → MarkerArray → Topic: /vision/detected_objects

# ===== 以下待规划包完成后启用 =====
# 终端3: move_group (本地规划)
ros2 launch tianyi2_moveit_config move_group.launch.py

# 终端4: trajectory_bridge (MoveIt→XARM)
ros2 run trajectory_bridge trajectory_bridge --ros-args -p debug:=false

# ===== 机器人侧 (SSH ubuntu@192.168.41.1) =====
# 终端1: XARM 启动
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 终端2: 初始化手臂
source /home/ubuntu/XARM/install/setup.bash
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
ros2 control switch_controllers --activate jointspace_arm_L_controller
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
