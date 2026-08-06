# 比赛流程架构

## 按键操作

| 控件 | 模式 | 功能 |
|------|------|------|
| 空格 | init | 右手:结束录制 / 左手:开始+结束录制 |
| button.left[0] | compete | 夹爪开合(切换) |
| button.left[1] | compete | 自锁↔插入模式切换 |
| button.left[2] | compete遥操 | 右臂正放(到位) / 再按倒放(回悬垂) |
| joystick.left XY | 插入 | TCP精细XY（约6mm/s） |
| button.right[0/1] | 插入手动模式 | TCP上/下（约6mm/s） |
| button.right[2] | 插入 | 启动/退出1.2N恒力Z环 |
| scroll.left/right | 插入 | 暂不使用，避免姿态变化破坏力基线 |

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
  ├─ 插入: 锁定当前TCP姿态 → 采集0.5s力基线
  │         默认手动: joystick控制精细XY, 右键0/1控制Z
  │         右键2启动恒力环: XY仍由人工控制, Z由六维力闭环控制
  │         再按右键2退出恒力环，恢复手动Z
  │         XY+Z合成为单次连续笛卡尔路径
  │         恒力环: 总力4N/横向力3N触发2mm回退
  │         手动Z: 轴向4N仅警告, 8N硬停；横向力仍为3N硬停
  │         回退完成自动恢复手动Z；故障锁存时按右键2也可确认并恢复手动
  │         Z软限位30mm只保持，不自动返回
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
         └─→ /arm_6dof_left (100Hz六维力)
                                                              ↓
笔记本: RSP(URDF→TF) ← move_group(/compute_ik, /compute_cartesian_path)
                                                              ↓
比赛:   ZMQ(同构臂) → competition.py → bodyctrl /arm/cmd_pos → 电机
                              └─→ /inspire_hand/ctrl/right_hand → 灵巧手
```

恒力插入还需 `src/tools/force_axis_cal.json`，每次进入插入模式都会重新采集当前姿态下的 `F₀`。
