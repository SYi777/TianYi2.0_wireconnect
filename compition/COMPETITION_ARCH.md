# 比赛流程架构

## 按键操作

| 控件 | 模式 | 功能 |
|------|------|------|
| 空格 | init | 右手:结束录制 / 左手:开始+结束录制 |
| button.left[0] | compete | 夹爪开合(切换) |
| button.left[1] | compete | 自锁↔插入模式切换 |
| button.left[2] | compete遥操 | 右臂正放(到位) / 再按倒放(回悬垂) |
| joystick.left XY | 插入 | TCP前后左右 |
| button.right[0] | 插入 | TCP上 |
| button.right[1] | 插入 | TCP下 |
| scroll.left | 插入 | 绕TCP局部X旋转 |
| scroll.right | 插入 | 绕基座Z旋转 |

## init 模式

```
右手跟随 → [空格]录完 → 自锁5s → 倒放悬垂
左手跟随 → [空格]开始 → [空格]录完 → 自锁5s → 倒放悬垂
保存 config/right_traj.json + left_traj.json
```

## compete 模式

```
启动 → 右臂等待手动 [btn2] 触发

循环:
  ├─ 右臂: [btn2] 正放到目标 → 到位自锁
  │
  ├─ 遥操: 左臂5s安全等 → 步进逼近 → 跟随同构臂
  │         [btn0] 夹爪  [btn2] 右臂倒放回悬垂
  │         [btn1] → 锁定位姿+朝向, 进入插入
  │
  ├─ 插入: TCP位姿+朝向锁定不变
  │         joystick+按钮+双scroll 微调
  │         连续笛卡尔路径 (compute_cartesian_path)
  │         [btn0] 夹爪  [btn1] → 完成, 进入返回
  │
  └─ 返回: smoothstep回录制终点 → 倒放悬垂 → 循环
```

## 依赖

## 完整启动流程 (从机器人开机)

### 机器人 (SSH ubuntu@192.168.41.1)

```bash
# 0. 跳过自检
sudo systemctl stop proc_manager.service

# 1. body_control (电机驱动 + 灵巧手)
source /opt/ros/humble/setup.bash
source /home/ubuntu/ros2ws/install/setup.bash
ros2 launch body_control body.launch.py

# 2. XARM (仅关节状态, 不用于控制)
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 3. 杀机器人RSP (避免TF冲突)
pkill -f robot_state_publisher
```

### 笔记本

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 1. 基础设施 (joint_relay + bridge + TF)
ros2 launch wire_connect_debug infrastructure.launch.py

# 2. RSP (发布TF树)
ros2 launch tianyi2_moveit_config rsp.launch.py

# 3. move_group (IK + Cartesian)
ros2 launch tianyi2_moveit_config move_group.launch.py
```

### 比赛脚本

```bash
# 初始化录制
python3 ~/WireConnect_ws/compition/competition.py --mode init

# 比赛运行
python3 ~/WireConnect_ws/compition/competition.py --mode compete
```

### 一键启动 (三个终端)

```bash
# 终端1: 笔记本基础设施
source ~/WireConnect_ws/install/setup.bash
ros2 launch wire_connect_debug infrastructure.launch.py
ros2 launch tianyi2_moveit_config rsp.launch.py
ros2 launch tianyi2_moveit_config move_group.launch.py

# 终端2: 机器人 (SSH)
ssh ubuntu@192.168.41.1 "
source /opt/ros/humble/setup.bash
source /home/ubuntu/ros2ws/install/setup.bash
ros2 launch body_control body.launch.py &
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real &
sleep 5
pkill -f robot_state_publisher
"

# 终端3: 比赛
python3 ~/WireConnect_ws/compition/competition.py --mode compete
```

### 依赖链

```
机器人: body_control → XARM(关节) → joint_relay(笔记本) → /joint_states
                                                              ↓
笔记本: RSP(URDF→TF) ← move_group(/compute_ik, /compute_cartesian_path)
                                                              ↓
比赛:   ZMQ(同构臂) → competition.py → bodyctrl /arm/cmd_pos → 电机
                              └─→ /inspire_hand/ctrl/right_hand → 灵巧手
```
