# 天轶2.0 Pro 控制链路完全手册

> 基于 XARM使用手册（对外）、ROS2 SDK二次开发文档（v2.0.5）、真机调试验证
> 最后更新: 2026-07-20

---

## 1. 架构总览

```
┌──────────────────────────────────────────────────────────────────┐
│  笔记本 (192.168.41.5)          机器人 x86 (192.168.41.1)          │
│                                                                    │
│  ros2 topic pub ──── DDS ────→  body_control                      │
│  ros2 service call ─ DDS ────→    /arm/cmd_pos    → CAN → 电机    │
│                                    /head/cmd_pos                   │
│                                    /waist/cmd_pos                  │
│                                    /leg/cmd_pos                    │
│                                                                    │
│                              ←───  /joint_states (DDS)             │
│                              ←───  /tf, /tf_static                 │
│                              ←───  /arm_6dof_left/right (100Hz)   │
│                              ←───  /ob_camera_head/color/* (30Hz)  │
│                                                                    │
│  ros2 control ──── DDS ────→  XARM (ros2_control)                 │
│    switch_controllers         controller_manager                   │
│    topic pub                  EAIHardware (TianyiHardware)          │
│    service call               /jointspace_commands_*               │
│                               /endposetarget_*                     │
│                               /joint_space_control                 │
│                               /dual_arm_waypoints                  │
└──────────────────────────────────────────────────────────────────┘
```

**两套控制系统**，共享同一组电机硬件。XARM 是高层的 ros2_control 框架，body_control 是底层硬件驱动。XARM 最终也通过 `/arm/cmd_pos` 驱动电机。

---

## 2. 启动顺序

### 2.1 跳过遥控器自检的完整启动

> 来源：SDK 文档 §(非必需步骤) + 真机验证

```bash
# === 机器人侧 (SSH ubuntu@192.168.41.1, 密码 123) ===

# Step 1: 停掉开机自启管理器
sudo systemctl stop proc_manager

# Step 2: 关掉手部检查（没插灵巧手时必做，否则 body_control 不 Ready）
/home/ubuntu/ros2ws/install/body_control/share/body_control/param/inspire_hands.yaml
inspire_hands:
  left:
    enable: false
  right:
    enable: false


# Step 3: 启动 body_control（终端1，保持运行）
sudo su
cd /home/ubuntu/ros2ws
source install/setup.bash
ros2 launch body_control body.launch.py

# Step 4: 启动 XARM（终端2，保持运行）
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real
```

> 来源：XARM 手册 §4.1.3.3 — `source ~/XARM/install/setup.bash` + `ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real`
>
> 来源：SDK 文档 §(非必需步骤) — `sudo systemctl stop proc_manager` + `ros2 launch body_control body.launch.py`

### 2.2 notebook 环境

```bash
# 每个新终端都要：
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/ROS/nk2_ws/install/setup.bash       # bodyctrl_msgs (匹配机器人)
source ~/WireConnect_ws/XARM/install/setup.bash            # eai_manipulator_msgs eai_manipulator_msgs
```

### 2.3 验证启动成功

```bash
# 机器人 alive
ros2 topic list | grep joint_states

# XARM 在线
ros2 control list_controllers | head -3
# 应看到: joint_state_broadcaster  active

# 硬件是真实模式
ros2 control list_hardware_components | grep plugin
# 应看到: plugin name: tianyi_hardware/TianyiHardware
```

---

## 3. XARM = ros2_control 控制器集合

> 来源：XARM 手册 §2 整体介绍 — 框架按照 ros2_control 划分，上层 Controller 负责运动生成，下层 Hardware 负责控制

### 3.1 控制器列表

| 控制器 | 插件类型 | 接口 | 功能 | 来源 |
|--------|---------|------|------|:--:|
| `jointspace_arm_L_controller` | JointspaceRuckigActionController | `/jointspace_commands_L` Float64[7] | 左手关节空间 + Ruckig平滑 + 限位检查 | §3.1 |
| `jointspace_arm_R_controller` | JointspaceRuckigActionController | `/jointspace_commands_R` Float64[7] | 右手关节空间 | §3.2 |
| `jointspace_ruckig_qp_controller` | JointspaceRuckigQpController | `/jointspace_commands_Dual` Float64[14] | 双臂关节 + 自碰撞 + 双臂互碰检测 | §3.9 |
| `jointspace_head_controller` | JointspaceRuckigActionController | `/jointspace_commands_head` Float64[3] | 头部关节空间 | §3.6 |
| `jointspace_body_controller` | JointspaceRuckigActionController | `/jointspace_commands_body` Float64[4] | 腰腿关节空间 | §3.4 |
| `jointspace_waist_yaw_controller` | JointspaceRuckigActionController | `/jointspace_commands_waist_yaw` Float64[1] | 腰偏航单关节 | §3.8 |
| `endpose_single_arm_qp_L_controller` | SingleArmQpController | `/endposetarget_L` ArmTargetPose | **左手笛卡尔 + IK + QP避碰** | §3.12 |
| `endpose_single_arm_qp_R_controller` | SingleArmQpController | `/endposetarget_R` ArmTargetPose | 右手笛卡尔 + IK + QP避碰 | §3.13 |
| `endpose_dual_arm_qp_controller` | EndposeDualArmQpController | `/endposetarget_Dual` DualArmTargetPose | 双臂同步笛卡尔 | §3.15 |
| `endpose_wholebody_controller` | EndposeWholebodyController | `/endposetarget_Dual_wholebody` | 双臂 + 腰腿联动 | §3.3 |
| `endpose_head_controller` | HeadIkController | `/endposetarget_Head` Float64[3] | 头部 ZYX 欧拉角 | §3.11 |
| `endpose_body_controller` | EndposeBodyController | `/endposetarget_Body` Float64[4] | 腰腿笛卡尔 [x,z,pitch,yaw] | §3.10 |
| `moveit_left_arm_controller` | — | — | 用于 MoveIt 功能 | §3.16 |
| `moveit_right_arm_controller` | — | — | 用于 MoveIt 功能 | §3.16 |
| `empty_L/R_controller` | EmptyController | — | 占位，不写数据，释放 /arm/cmd_pos | — |

### 3.2 控制器生命周期

> 来源：XARM 手册 §3.1 注意事项 — action接口和topic接口只能同时使用其中之一

控制器有四个状态：`unconfigured → inactive → active`。只有 active 状态才工作。

同一组关节同一时间只能有一个控制器 active。切换用：

```bash
ros2 control switch_controllers --deactivate old_ctrl --activate new_ctrl
```

### 3.3 empty_controller 的作用

`empty_controller` 声明了 joint command interface 但**不往 /arm/cmd_pos 写任何数据**。激活后 EAIHardware 不会覆盖外部指令，可以直接用 body_control 直发 `/arm/cmd_pos`。

```bash
# 释放 /arm/cmd_pos 控制权
ros2 control switch_controllers \
  --deactivate jointspace_arm_L_controller \
  --activate empty_L_controller
```

### 3.4 EAIHardware 覆写规则

> 真机调试发现

```
empty_controller active     → /arm/cmd_pos 不受干扰，自由发指令      ✅
jointspace_* active + 无指令 → EAIHardware 250Hz hold 当前位置       🔴 死锁原地
jointspace_* active + 有指令 → 正常执行                               ✅
endpose_* active + 无指令     → 同 jointspace                        🔴
endpose_* active + 有指令     → IK+避碰后正常执行                      ✅
```

---

## 4. 硬件使能与模式设置

> 来源：XARM 手册 §3 控制器说明 + 真机验证

### 4.1 必须的初始化步骤

使用任何手臂控制器之前：

```bash
# 1. 设位置模式 (XARM 手册注明 mode=3 是推荐的高刚度位置环)
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"

# 2. 硬件上电
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
```

> **重要**: 必须先设 mode 再 enable，且 mode=3 是位置模式。默认 mode=1 是速度环，不响应位置指令。(真机调试发现)

### 4.2 arm_mode 取值

> 来源：XARM 手册 §3 注意事项 — mode 0-3 可选，推荐 mode 3

| mode | 说明 |
|:--:|------|
| 0 | 柔顺模式（力位混合）|
| 1 | 高刚度速度环（不推荐，控制频率波动问题）|
| 2 | 重力补偿模式（kp/kd=0）|
| 3 | **高刚度位置环（推荐）** |

### 4.3 全部硬件使能 Service

| Service | 类型 | 用途 | 来源 |
|---------|------|------|:--:|
| `/EAIHardware/set_arm_enable` | `std_srvs/SetBool` | 手臂上电 | §XARM |
| `/EAIHardware/set_leg_enable` | `std_srvs/SetBool` | 腿部上电 | §XARM |
| `/EAIHardware/set_waist_enable` | `std_srvs/SetBool` | 腰部上电 | §XARM |
| `/EAIHardware/set_head_enable` | `std_srvs/SetBool` | 头部上电 | §XARM |
| `/EAIHardware/set_all_enable` | `std_srvs/SetBool` | 全部上电 | §XARM |
| `/EAIHardware/set_arm_mode` | `eai_manipulator_msgs/srv/Mode` | 手臂模式 {mode: 0~3} | §XARM |

---

## 5. 控制方式

### 5.1 方式一：body_control 直发（无 XARM 依赖）

> 来源：SDK 文档 §5.3~§5.6

| 部位 | Topic | 消息类型 | 电机 ID | 单位 |
|------|-------|---------|--------|:--:|
| 头 | `/head/cmd_pos` | `CmdSetMotorPosition` | 1=Roll 2=Pitch 3=Yaw | rad |
| 左臂 | `/arm/cmd_pos` | `CmdSetMotorPosition` | 11~17 | rad |
| 右臂 | `/arm/cmd_pos` | `CmdSetMotorPosition` | 21~27 | rad |
| 腰 | `/waist/cmd_pos` | `CmdSetMotorPosition` | 31=Yaw 32=Pitch | rad |
| 腿 | `/leg/cmd_pos` | `CmdSetMotorPosition` | 51~52 | rad |

> 来源：SDK 文档 §4.1 全身关节id定义 + §5.3~§5.6 控制接口

```bash
# 示例：左腕(17)转 0.1 rad
ros2 topic pub /arm/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header: {stamp: {sec:0, nanosec:0}, frame_id:''}, \
    cmds: [{name:17, pos:0.1, spd:2.0, cur:1.0}]}" --once
```

> 来源：SDK 文档 §5.5.2 — `spd` 单位 rpm, `cur` 单位 A

**使用前提**: `/arm/cmd_pos` 不被 XARM 覆盖 → 先切 empty_controller（见 §3.3）

### 5.2 方式二：XARM 关节空间

> 来源：XARM 手册 §3.1、§3.2、§3.9

```
Topic 命令 → Ruckig 平滑 → 限位检查 → EAIHardware → /arm/cmd_pos
```

| 控制器 | Topic | 数据 | 避碰 | 来源 |
|--------|-------|------|:--:|:--:|
| `jointspace_arm_L_controller` | `/jointspace_commands_L` | Float64[7] | ❌ | §3.1 |
| `jointspace_arm_R_controller` | `/jointspace_commands_R` | Float64[7] | ❌ | §3.2 |
| `jointspace_ruckig_qp_controller` | `/jointspace_commands_Dual` | Float64[14] | **✅** | §3.9 |

> 来源：XARM 手册 §3.1 示例 — `ros2 topic pub /jointspace_commands_L std_msgs/msg/Float64MultiArray 'data: [0.0, 1.18, 0.0, -1.3, 0.0, -0.13, 0.18]'`

```bash
# 1. 初始化
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
ros2 control switch_controllers --activate jointspace_arm_L_controller

# 2. 发指令（XARM 手册原文示例）
ros2 topic pub /jointspace_commands_L std_msgs/msg/Float64MultiArray \
  "data: [0.0, 1.18, 0.0, -1.3, 0.0, -0.13, 0.18]" --once
```

### 5.3 方式三：XARM 笛卡尔空间（推荐比赛用）

> 来源：XARM 手册 §3.12、§3.13

```
ArmTargetPose → IK 求解 → QP 碰撞规避 → EAIHardware → /arm/cmd_pos
```

**坐标系**：
> 来源：XARM 手册 §3.12 — `from_frame` 建议 `base_footprint` 或 `waist_yaw_link`；`to_frame` 建议 `left_tcp_link` / `right_tcp_link`
>
> 来源：XARM 手册 §4.2.4.1 — frame 参数：天轶系列用 `waist_yaw_link`

```
base_footprint → base_link → waist_yaw_link (z≈0.82m)
                              ├── shoulder_pitch_l → ... → left_tcp_link
                              └── shoulder_pitch_r → ... → right_tcp_link
```

| 控制器 | Topic | 消息类型 | 功能 | 来源 |
|--------|-------|---------|------|:--:|
| `endpose_single_arm_qp_L` | `/endposetarget_L` | `ArmTargetPose` | 左手笛卡尔 + IK + QP避碰 | §3.12 |
| `endpose_single_arm_qp_R` | `/endposetarget_R` | `ArmTargetPose` | 右手笛卡尔 | §3.13 |
| `endpose_dual_arm_qp` | `/endposetarget_Dual` | `DualArmTargetPose` | 双臂同步 | §3.15 |
| `endpose_wholebody` | `/endposetarget_Dual_wholebody` | `DualArmTargetPose` | 双臂 + 腰腿联动 | §3.3 |
| `endpose_head` | `/endposetarget_Head` | Float64[3] | 头部 ZYX 欧拉角 | §3.11 |

`ArmTargetPose` 字段（来源：XARM 手册 §3.12）：
```
target:      Pose (position + orientation, 单位 m + 四元数)
from_frame:  string (参考系, "waist_yaw_link" 或 "base_footprint")
to_frame:    string (目标系, "left_tcp_link" 或 "right_tcp_link")
offset_x/y/z: float32 (末端坐标系下偏移, 单位 m)
```

```bash
# 1. 初始化（同关节空间）
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
ros2 control switch_controllers --activate endpose_single_arm_qp_L_controller

# 2. Topic 方式（持续发指令）
ros2 topic pub /endposetarget_L eai_manipulator_msgs/msg/ArmTargetPose \
  '{header: {frame_id: "waist_yaw_link"}, target: {position: {x:0.35, y:0.20, z:-0.10}, orientation: {w:1.0}}, from_frame: "waist_yaw_link", to_frame: "left_tcp_link", offset_x:0, offset_y:0, offset_z:0}' --once

# 3. Action 方式（阻塞等待到位）— 来源：XARM 手册 §3.12
ros2 action send_goal /endpose_single_arm_qp_L_controller/endPosSingleTarget \
  eai_manipulator_msgs/action/EndPosSingleTarget '{
    "target": {"header":{"frame_id":"waist_yaw_link"}, "target":{"position":{"x":0.35,"y":0.20,"z":-0.10},"orientation":{"w":1.0}}, "from_frame":"waist_yaw_link", "to_frame":"left_tcp_link", "offset_x":0,"offset_y":0,"offset_z":0}}'
```

**注意**：目标位姿须在当前位置的 `dis_err_bound`（默认 0.2m）和 `ori_err_bound`（默认 1.0 rad）范围内，否则控制器拒绝执行并报警（来源：XARM 手册 §3.12 注意事项 + error 300100）。

### 5.4 方式四：XARM MoveIt Service

> 来源：XARM 手册 §4.1、§4.2

**不需要 notebook 跑 move_group**。Service 在机器人上，笔记本通过 DDS 调 Service。

| Service | 用途 | 来源 |
|---------|------|:--:|
| `/joint_space_control` | 关节空间多路点轨迹 (JSON) | §4.1 |
| `/dual_arm_waypoints` | 笛卡尔空间多路点轨迹 (JSON) | §4.2 |

#### 关节空间 — 来源：XARM 手册 §4.1.3.1

```bash
# 先切 moveit 控制器 — 来源：XARM 手册 §4.2.4.3
ros2 control switch_controllers --activate moveit_left_arm_controller

# 调 Service — 来源：XARM 手册 §4.1.3.3
ros2 service call /joint_space_control cm_msgs/srv/CommonStreamRos2 "msg_id: ''
json_data: '{
  \"group\": \"left_arm\",
  \"vel_scale\": 0.5,
  \"acc_scale\": 0.5,
  \"waypoints\": [{
    \"shoulder_pitch_l_joint\": -0.3, \"shoulder_roll_l_joint\": 0.3,
    \"shoulder_yaw_l_joint\": 0.2, \"elbow_pitch_l_joint\": -1.0,
    \"elbow_yaw_l_joint\": -0.2, \"wrist_pitch_l_joint\": -0.2,
    \"wrist_roll_l_joint\": -0.1
  }]
}'
data: []"
```

> group 可选: `left_arm`, `right_arm`, `dual_arm`
> 来源：XARM 手册 §4.1.3.1

#### 笛卡尔空间 — 来源：XARM 手册 §4.2.4.1

```bash
ros2 service call /dual_arm_waypoints cm_msgs/srv/CommonStreamRos2 "msg_id: ''
json_data: '{
  \"group\": \"left_arm\",
  \"frame\": \"waist_yaw_link\",
  \"mode\": \"plan_and_execute\",
  \"vel_scale\": 0.1,
  \"acc_scale\": 0.1,
  \"left_waypoints\": [[0.30, 0.25, -0.15, 0,0,0,1], [0.30, 0.25, -0.18, 0,0,0,1]]
}'
data: []"
```

> `group`: `left_arm`, `right_arm`, `dual_arm`
> `frame`: 天轶用 `waist_yaw_link`
> `mode`: `plan`, `execute`, `plan_and_execute`
> `waypoints`: `[x, y, z, qx, qy, qz, qw]`
> 来源：XARM 手册 §4.2.4.1

---

## 6. 灵巧手

> 来源：SDK 文档 §5.7

**所有值均为百分比（0~1），不是弧度。**

| 接口 | 名称 | 说明 | 来源 |
|------|------|------|:--:|
| 状态 | `/inspire_hand/state/left_hand` | JointState, position=[0~1]*6 | §5.7.2 |
| Topic 控制 | `/inspire_hand/ctrl/left_hand` | JointState, position=[0~1]*6 | §5.7.3 |
| Service 角度 | `/inspire_hand/set_angle_flexible/left_hand` | 角度百分比 | §5.7.4 |
| Service 力矩 | `/inspire_hand/set_force/left_hand` | 力矩百分比 (0→0g, 1→1000g) | §5.7.5 |
| Service 速度 | `/inspire_hand/set_speed/left_hand` | 速度百分比 | §5.7.6 |
| Service 清错 | `/inspire_hand/set_clear_error/left_hand` | 清除错误 | §5.7.7 |

手指 ID：小指=1, 无名指=2, 中指=3, 食指=4, 拇指弯曲=5, 拇指旋转=6
> 来源：SDK 文档 §5.7.1

---

## 7. 传感器

> 来源：SDK 文档 §5.8~§5.10

| 传感器 | Topic | 类型 | 频率 | 来源 |
|--------|-------|------|:--:|:--:|
| 关节状态 | `/joint_states` | JointState | — | — |
| 左腕六维力 | `/arm_6dof_left` | WrenchStamped | 100Hz | §5.8.1 |
| 右腕六维力 | `/arm_6dof_right` | WrenchStamped | 100Hz | §5.8.1 |
| 彩色相机 | `/ob_camera_head/color/image_raw` | BGR8 1280x720 | 30Hz | §5.10 |
| 深度 | `/ob_camera_head/depth/image_raw` | 16UC1 | 30Hz | §5.10 |
| 相机内参 | `/ob_camera_head/color/camera_info` | CameraInfo | — | §5.10 |
| 电池 | `/power/battery/status` | PowerBatteryStatus | 1Hz | §5.11 |
| 急停 | `/power/board/key_status` | PowerBoardKeyStatus | 1Hz | §5.11 |

---

## 8. 电机 ID 速查

> 来源：SDK 文档 §4.1 全身关节id定义 + body_control YAML

```
头:  1=Roll  2=Pitch  3=Yaw
左臂: 11=肩俯仰 12=肩翻滚 13=肩偏航 14=肘俯仰 15=肘偏航 16=腕俯仰 17=腕翻滚
右臂: 21=肩俯仰 22=肩翻滚 23=肩偏航 24=肘俯仰 25=肘偏航 26=腕俯仰 27=腕翻滚
腰:  31=Yaw  32=Pitch
腿:  51=Hip  52=Knee
```

> 来源：SDK 文档 §5.3~§5.6 — SetMotorPosition: `name(uint16) pos(float32 rad) spd(float32 rpm) cur(float32 A)`

---

## 9. 链路选择决策

```
需要避碰？     ──是──→ XARM endpose_qp (笛卡尔) 或 ruckig_qp (关节)
需要笛卡尔？   ──是──→ XARM endpose_qp 或 /dual_arm_waypoints
需要多路点？   ──是──→ XARM /dual_arm_waypoints Service
只需单关节？   ──是──→ body_control /arm/cmd_pos (先切 empty)
只需头控制？   ──是──→ body_control /head/cmd_pos (不受XARM影响, 始终可用)
比赛任务？     ──是──→ 感知算 pose → XARM endpose_qp 到位 → 力监控 → 手松
```

---

## 10. 完整控制流程速查

### 头部（始终可用, 最快）

```bash
ros2 topic pub /head/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header:{stamp:{sec:0,nanosec:0},frame_id:''}, cmds:[{name:3,pos:0.3,spd:2.0,cur:1.0}]}" --once
```

### 手臂（XARM 笛卡尔, 推荐）

```bash
# 初始化(一次)
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode:3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data:true"
ros2 control switch_controllers --activate endpose_single_arm_qp_L_controller

# 发目标位姿
ros2 topic pub /endposetarget_L eai_manipulator_msgs/msg/ArmTargetPose \
  '{header:{frame_id:"waist_yaw_link"}, target:{position:{x:0.35,y:0.20,z:-0.10}, orientation:{w:1.0}}, from_frame:"waist_yaw_link", to_frame:"left_tcp_link", offset_x:0,offset_y:0,offset_z:0}' --once
```

### 手臂（body_control 直发, 最简单）

```bash
# 先释放控制权
ros2 control switch_controllers --activate empty_L_controller

# 发关节指令
ros2 topic pub /arm/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header:{stamp:{sec:0,nanosec:0},frame_id:''}, cmds:[{name:17,pos:0.1,spd:2.0,cur:1.0}]}" --once
```
