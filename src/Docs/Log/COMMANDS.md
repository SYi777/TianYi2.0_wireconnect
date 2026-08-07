# WireConnect 命令速查

> 最后更新: 2026-08-05

---

## 通用环境

```bash
# 笔记本
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 构建 (增量, 只重编译有变化的文件)
cd ~/WireConnect_ws
colcon build --symlink-install
```

---

# 一、笔记本 (x86 规划 + 控制)

## 1.1 基础设施一键启动

```bash
source ~/WireConnect_ws/install/setup.bash
ros2 launch wire_connect_debug infrastructure.launch.py
```

等价于：`static_transform_publisher` (相机TF) + `joint_relay` (合并关节状态+手指) + `trajectory_bridge` (MoveIt→机器人桥接)

## 1.2 MoveIt 规划链

```bash
source ~/WireConnect_ws/install/setup.bash

# RSP (发布 TF 树)
ros2 launch tianyi2_moveit_config rsp.launch.py

# move_group (IK / OMPL / Cartesian 服务)
ros2 launch tianyi2_moveit_config move_group.launch.py

# RViz 可视化 (可选)
LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 \
  ros2 launch tianyi2_moveit_config moveit_rviz.launch.py
```

RViz: Fixed Frame → `waist_yaw_link`, Add → RobotModel, MotionPlanning → left_arm

## 1.3 场景 + 规划

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 场景管理 (桌子 CollisionObject)
ros2 run wire_connect_planner planning_scene_manager

# 规划跟随 (视觉→IK→OMPL→执行)
ros2 launch wire_connect_planner planner.launch.py arm:=left

# 测试模式 (不需视觉, TCP+10cm)
ros2 launch wire_connect_planner planner.launch.py arm:=left test_mode:=true
```

## 1.4 轨迹录制与回放

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 录制 (RViz 每次 Plan&Execute 自动追加)
ros2 run trajectory_bridge record_trajectory --ros-args -p output:=my_path.json

# 回放
ros2 run trajectory_bridge replay_trajectory my_path.json
```

## 1.5 比赛

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 力控轴向标定 (需 2 次以上, u 夹角 < 10° 确认方向稳定)
python3 ~/WireConnect_ws/src/tools/calibrate_force_axis.py
# → force_axis_cal.json 保存在同目录

# 初始化录制 (录左右臂轨迹)
python3 ~/WireConnect_ws/compition/competition.py --mode init

# 比赛运行 (回放+遥操+恒力插入+返回循环)
python3 ~/WireConnect_ws/compition/competition.py --mode compete
```

### 1.5a 比赛依赖链 (最少启动)

```
┌─ 机器人 (SSH ubuntu@192.168.41.1) ───────────────────┐
│ sudo su                                               │
│ source /opt/ros/humble/setup.bash                     │
│ source /home/ubuntu/ros2ws/install/setup.bash          │
│ sudo systemctl stop proc_manager.service              │
│ ros2 launch body_control body.launch.py               │
│                                                       │
│ source /home/ubuntu/XARM/install/setup.bash            │
│ ros2 launch tianyi2_bringup tianyi2.launch.py hw:=real│
│ pkill -f robot_state_publisher                        │
│ ros2 control switch_controllers \                     │
│   --deactivate jointspace_arm_L_controller \          │
│                jointspace_arm_R_controller             │
│                                                       │
│ 数据: /joint_states  /arm_6dof_left  /arm/cmd_pos     │
└───────────────────────────────────────────────────────┘

┌─ 笔记本 (3个终端) ────────────────────────────────────┐
│ source /opt/ros/humble/setup.bash                     │
│ source ~/WireConnect_ws/install/setup.bash             │
│                                                       │
│ # 终端1: 基础设施                                     │
│ ros2 launch wire_connect_debug infrastructure.launch.py│
│                                                       │
│ # 终端2: MoveIt                                       │
│ ros2 launch tianyi2_moveit_config rsp.launch.py       │
│ ros2 launch tianyi2_moveit_config move_group.launch.py│
│                                                       │
│ # 终端3: 比赛                                         │
│ python3 ~/WireConnect_ws/compition/competition.py \   │
│   --mode compete                                       │
│                                                       │
│ 需先 calibrate_force_axis.py → force_axis_cal.json    │
└───────────────────────────────────────────────────────┘
```

**一键版 (SSH 机器人 + 笔记本两个终端)：**

```bash
# 终端A: 笔记本基础设施 + MoveIt
source ~/WireConnect_ws/install/setup.bash
ros2 launch wire_connect_debug infrastructure.launch.py &
sleep 2
ros2 launch tianyi2_moveit_config rsp.launch.py &
sleep 2
ros2 launch tianyi2_moveit_config move_group.launch.py &
wait

# 终端B: 机器人 + 比赛
ssh ubuntu@192.168.41.1 "
  sudo su
  source /opt/ros/humble/setup.bash
  source /home/ubuntu/ros2ws/install/setup.bash
  sudo systemctl stop proc_manager.service
  ros2 launch body_control body.launch.py &
  sleep 3
  source /home/ubuntu/XARM/install/setup.bash
  ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real &
  sleep 5
  pkill -f robot_state_publisher
  ros2 control switch_controllers \
    --deactivate jointspace_arm_L_controller jointspace_arm_R_controller
  wait
"
# 等机器人就绪后:
python3 ~/WireConnect_ws/compition/competition.py --mode compete
```

## 1.6 同构臂调试

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 遥操调试: 按键让同构臂跟随机械臂
python3 ~/WireConnect_ws/src/tools/isomorphic_follow.py
# 空格=开始/停止同步 q=退出
```

## 1.7 遥操 (同构臂 ZMQ → bodyctrl)

```bash
source ~/WireConnect_ws/install/setup.bash

# 左手遥操
python3 ~/WireConnect_ws/src/tools/left_arm_teleop.py

# 右手遥操 + 录制 (空格=录/停/存)
python3 ~/WireConnect_ws/src/tools/right_arm_teleop.py

# 右手回放 / 倒放
python3 ~/WireConnect_ws/src/tools/right_arm_teleop.py --replay \
  ~/WireConnect_ws/src/trajectory_bridge/config/right_traj.json
python3 ~/WireConnect_ws/src/tools/right_arm_teleop.py --replay \
  ~/WireConnect_ws/src/trajectory_bridge/config/right_traj.json --reverse
```

## 1.8 灵巧手控制

```bash
source ~/WireConnect_ws/install/setup.bash

# 键盘模式 (空格切换张手/闭合, q/ESC/Ctrl+C 退出)
python3 ~/WireConnect_ws/src/tools/zmq_hand_control.py --keyboard

# ZMQ手柄模式
python3 ~/WireConnect_ws/src/tools/zmq_hand_control.py
```

## 1.9 调试工具

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 6-DOF 键盘遥控 TCP
ros2 run wire_connect_debug keyboard_teleop

# 笛卡尔直线插值调试 (直线插值+碰撞检测)
ros2 run wire_connect_debug cartesian_debug

# 相机原始画面
ros2 run wire_connect_debug camera_view

# XARM 话题监控 (对比baseline, 高亮新话题)
ros2 run xarm_debug xarmdebug

# XARM 控制器交互管理 (TUI: 切换控制器/关节/笛卡尔指令)
ros2 run xarm_debug xarmcontroldebug

# 身体传感器监控
ros2 run bodyctrl_debug bodyctrldebug
```

### Cartesian Debug 按键

```
平移: w/s X前后  a/d Y左右  q/e Z上下
旋转: i/k 绕X    j/l 绕Y    u/o 绕Z
步长: r/R 平移±1cm  f/F 旋转±1°
[空格] 笛卡尔规划  [Enter] 执行  [c] 重置  [Esc] 退出
```

### xarmcontroldebug 按键

| 命令 | 说明 |
|------|------|
| `l` | 列出所有控制器 |
| `a <name>` / `d <name>` | 激活 / 停用 |
| `jL <7f>` / `jR <7f>` | 关节空间指令 (rad) |
| `cL/cR <xyz qxyzw>` | 笛卡尔空间指令 |
| `mode <0-3>` | 0柔顺 1速度 2重力补偿 3位置环 |
| `arm enable` | 手臂硬件使能 |

## 1.10 话题调试

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 频率
ros2 topic hz /ob_camera_head/color/image_raw/compressed
ros2 topic hz /ob_camera_head/depth/image_raw

# 数据
ros2 topic echo /vision/plugs --once
ros2 topic echo /vision/table --once
ros2 topic echo /vision/left_target --once

# TF 验证
ros2 run tf2_ros tf2_echo waist_yaw_link ob_camera_head_color_optical_frame
ros2 run tf2_tools view_frames
```

## 1.11 数据校验与转换

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

# 拖回数据
scp -r nvidia@192.168.41.2:~/jyh_ws/bags/ep_0002 ~/WireConnect_ws/bags/

# 校验
ros2 run data_collect check_dataset ~/WireConnect_ws/bags/ep_0002 --obs-window 5

# 转 LeRobot 格式
ros2 run data_collect bag_to_lerobot ~/WireConnect_ws/bags/ep_0002 --output ~/lerobot_data --obs-window 5
```

---

# 二、机器人 (SSH ubuntu@192.168.41.1)

## 2.1 跳过自检 + 启动 body_control

```bash
sudo systemctl stop proc_manager.service

source /opt/ros/humble/setup.bash
source /home/ubuntu/ros2ws/install/setup.bash
ros2 launch body_control body.launch.py
```

## 2.2 启动 XARM (仅关节状态, 不用于 bodyctrl 控制)

```bash
source /opt/ros/humble/setup.bash
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 杀机器人 RSP (避免 TF 与笔记本冲突)
pkill -f robot_state_publisher
```

## 2.3 手臂使能与控制器 (XARM 模式才需要, bodyctrl 遥操跳过)

```bash
source /opt/ros/humble/setup.bash
source /home/ubuntu/XARM/install/setup.bash

ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "{data: true}"
ros2 control switch_controllers --activate jointspace_arm_L_controller
ros2 control switch_controllers --activate jointspace_arm_R_controller
```

## 2.4 比赛前必查：禁用 XARM 控制器

> **根因**：XARM EAIHardware 以 250Hz 向 `/arm/cmd_pos` 发布保持指令，覆盖 competition.py / left_arm_teleop.py 的 ~20Hz 指令。症状：固定位置附近振动、摇杆推不动。

```bash
source /opt/ros/humble/setup.bash
source /home/ubuntu/XARM/install/setup.bash

# 查看控制器
ros2 control list_controllers

# 停用 XARM 关节控制器 (释放 /arm/cmd_pos)
ros2 control switch_controllers \
  --deactivate jointspace_arm_L_controller jointspace_arm_R_controller

# 确认发布者 (应只剩 bodyctrl)
ros2 topic info /arm/cmd_pos --verbose

# 确认无残留进程
pgrep -af "teleop|competition|cable_tracker"
```

## 2.5 灵巧手控制 (机器人端)

```bash
source /opt/ros/humble/setup.bash
source /home/ubuntu/ros2ws/install/setup.bash

# 同步脚本到机器人
scp ~/WireConnect_ws/src/tools/zmq_hand_control.py ubuntu@192.168.41.1:~/

# 运行
ssh ubuntu@192.168.41.1 "source /opt/ros/humble/setup.bash && python3 ~/zmq_hand_control.py"

# 直接控制 (JointState, position=0~1)
ros2 topic pub --once /inspire_hand/ctrl/left_hand sensor_msgs/msg/JointState \
  '{name: ["1","2","3","4","5","6"], position: [0.5, 0.5, 0.5, 0.5, 0.5, 0.5]}'

# 读取状态
ros2 topic echo /inspire_hand/state/left_hand --once
```

手指ID: 1=小指 2=无名指 3=中指 4=食指 5=拇指弯曲 6=拇指旋转

## 2.6 身体关节直控 (bodyctrl)

| 话题 | 电机ID | 关节 |
|------|--------|------|
| `/head/cmd_pos` | 1-3 | roll/pitch/yaw |
| `/waist/cmd_pos` | 31-32 | yaw/pitch |
| `/leg/cmd_pos` | 51-52 | first/second_leg_pitch |

身高 = waist_pitch (电机32), 范围 -0.785~2.094 rad, 正=后仰升高

```bash
source /opt/ros/humble/setup.bash
source /home/ubuntu/ros2ws/install/setup.bash

# 示例: 设置腰部
ros2 topic pub --once /waist/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header:{stamp:{sec:0,nanosec:0},frame_id:''}, cmds:[{name:32,pos:0.5,spd:4.0,cur:20.0}]}"
```

---

# 三、AGX / Orin (SSH nvidia@192.168.41.2)

## 3.1 全部相机 (头部 Orbbec + 双腕 D405)

```bash
ssh nvidia@192.168.41.2 "
source /opt/ros/humble/setup.bash && export ROS_DOMAIN_ID=0
source /home/nvidia/orbbec_camera_ros2/install/setup.bash
source /home/nvidia/realsense_ros2_ws/install/setup.bash
source ~/jyh_ws/install/setup.bash
ros2 launch wire_connect_debug start_all_cameras.launch.py
"
```

## 3.2 视觉检测

```bash
source /opt/ros/humble/setup.bash
source ~/jyh_ws/install/setup.bash

# 线缆+端口识别 (YOLO双模型 + 深度 + TF)
export PYTHONPATH=$HOME/jyh_ws/src/wire_connect_vision/vendor:$PYTHONPATH
ros2 launch wire_connect_vision detect_both.launch.py

# 桌子识别 (深度边缘 → /vision/table)
ros2 run wire_connect_vision table_detector
```

## 3.3 可视化 (SSH X转发, 15Hz JPEG压缩)

```bash
ssh -X nvidia@192.168.41.2 "
source /opt/ros/humble/setup.bash
source ~/jyh_ws/install/setup.bash
ros2 run wire_connect_debug multi_camera_view
"
```

## 3.4 同步 + 构建

```bash
# 笔记本 → AGX (全量同步)
rsync -avz --exclude 'build/' --exclude 'install/' --exclude 'log/' \
  ~/WireConnect_ws/src/ nvidia@192.168.41.2:~/jyh_ws/src/
rsync -avz ~/WireConnect_ws/src/tools/ nvidia@192.168.41.2:~/jyh_ws/tools/

# AGX 增量构建
ssh nvidia@192.168.41.2 "
source /opt/ros/humble/setup.bash && cd ~/jyh_ws
colcon build --symlink-install --packages-select wire_connect_msgs wire_connect_vision wire_connect_debug wire_connect_planner trajectory_bridge bodyctrl_msgs data_collect
"
```

## 3.5 Orin 离线依赖

```bash
# 笔记本下载 ARM64 轮子
pip3 download ultralytics --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
pip3 download "numpy<2" --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
scp /tmp/u_arm/*.whl nvidia@192.168.41.2:/tmp/u_arm/

# Orin 安装
ssh nvidia@192.168.41.2 "
mkdir -p ~/jyh_ws/src/wire_connect_vision/vendor
rm -rf ~/jyh_ws/src/wire_connect_vision/vendor/numpy*
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/numpy-1.26.4*.whl
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/ultralytics*.whl
"
```

## 3.6 录制

```bash
source ~/jyh_ws/install/setup.bash
ros2 run data_collect record_episode --ros-args -p obs_window:=5 -p output_dir:=$HOME/jyh_ws/bags
```

操作: `s` 开始 → 拖臂做动作 → `s` 停止 → `y` 保留 / `n` 丢弃

---

# 四、参考

## 4.1 电机 ID 与额定电流

| 部位 | ID | 关节 | 额定电流 |
|------|----|------|---------|
| 头 | 1-3 | roll/pitch/yaw | 5A |
| 左臂 | 11-17 | 肩俯仰~腕翻滚 | 5-35A |
| 右臂 | 21-27 | 同左臂 | 5-35A |
| 腰 | 31-32 | yaw/pitch | ~20-30A |
| 腿 | 51-52 | hip/knee | ~30A |

## 4.2 网络

```bash
nmcli radio wifi off / on
nmtui
```

## 4.3 SSH 免密

```bash
ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
ssh-copy-id ubuntu@192.168.41.1    # 密码 123
ssh-copy-id nvidia@192.168.41.2
```
