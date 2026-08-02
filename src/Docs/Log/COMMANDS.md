# WireConnect 命令速查

> 最后更新: 2026-07-31

---

## 环境

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash
```

## 构建

```bash
cd ~/WireConnect_ws
colcon build --symlink-install
colcon build --symlink-install --packages-select wire_connect_vision wire_connect_planner wire_connect_debug
```

---

# 完整操作流程

## 阶段1 — 笔记本：基础设施一键启动（TF + 转发 + 桥接）

```bash
source ~/WireConnect_ws/install/setup.bash
ros2 launch wire_connect_debug infrastructure.launch.py
```

等价于同时启动：
- `static_transform_publisher` — 相机 TF 链补全
- `joint_relay` — joint_states 转发（含手指关节）
- `trajectory_bridge` — MoveIt → /jointspace_commands_L/R

---

## 阶段2 — 机器人 (SSH ubuntu@192.168.41.1)

```bash
source /opt/ros/humble/setup.bash
source ~/XARM/install/setup.bash

# 2.1 启动 body_control + XARM
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 2.2 杀掉机器人 RSP（避免TF与笔记本冲突）
pkill -f robot_state_publisher

# 2.3 手臂模式 + 使能
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"

# 2.4 激活左/右臂关节控制器
ros2 control switch_controllers --activate jointspace_arm_L_controller
ros2 control switch_controllers --activate jointspace_arm_R_controller

# 2.5 确认控制器 active
ros2 control list_controllers | grep jointspace_arm
```

---

## 阶段3 — Orin (SSH nvidia@192.168.41.2)：视觉感知

```bash
source /opt/ros/humble/setup.bash
source ~/jyh_ws/install/setup.bash
export PYTHONPATH=$HOME/jyh_ws/src/wire_connect_vision/vendor:$PYTHONPATH

# 3.1 线缆+端口识别（YOLO双模型 + 深度 + TF → /vision/plugs, /vision/left_target）
ros2 launch wire_connect_vision detect_both.launch.py

# 3.2 桌子识别（深度边缘 → /vision/table）
ros2 run wire_connect_vision table_detector
```

---

## 阶段4 — 笔记本：MoveIt + 场景 + 规划

```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/install/setup.bash

	# 4.0 启动本地 RSP（发布 TF 树，move_group 依赖）
	ros2 launch tianyi2_moveit_config rsp.launch.py

# 4.1 启动 move_group（提供 /compute_ik, /plan_kinematic_path, /compute_cartesian_path）
ros2 launch tianyi2_moveit_config move_group.launch.py

# 4.2 场景管理（订阅 /vision/table → CollisionObject → /planning_scene）
ros2 run wire_connect_planner planning_scene_manager

# 4.3 规划跟随（状态机：检测→IK→OMPL避障→执行→跟踪）
ros2 launch wire_connect_planner planner.launch.py arm:=left

# 4.4 测试模式（不需视觉，当前TCP+10cm）
ros2 launch wire_connect_planner planner.launch.py arm:=left test_mode:=true
```

---

## 调试工具

```bash
# 键盘遥控 TCP 6-DOF（OMPL规划，给planner发目标）
ros2 run wire_connect_debug keyboard_teleop

# 笛卡尔直线插值调试（直线插值+碰撞检测，独立于planner）
ros2 run wire_connect_debug cartesian_debug

# 相机原始画面
ros2 run wire_connect_debug camera_view

# XARM 话题监控（对比baseline, 高亮新话题, 关节状态, 控制器）
ros2 run xarm_debug xarmdebug

# XARM 控制器管理（交互式TUI: 切换控制器, 发关节/笛卡尔指令）
ros2 run xarm_debug xarmcontroldebug

# 头部键盘遥控（方向键 pitch/yaw, a/d roll）
ros2 run bodyctrl_debug headkb
```

### Cartesian Debug 按键

```
平移: w/s X前后  a/d Y左右  q/e Z上下
旋转: i/k 绕X    j/l 绕Y    u/o 绕Z
步长: r/R  平移±1cm  f/F  旋转±1°
[空格] 笛卡尔规划  [Enter] 执行  [c] 重置  [Esc] 退出
```

---

## 话题调试

```bash
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

---

## Orin 同步 + 构建

```bash
# 笔记本 → Orin 同步代码 (排除 build/install/log)
rsync -avz --exclude 'build/' --exclude 'install/' --exclude 'log/' \
  ~/WireConnect_ws/src/ nvidia@192.168.41.2:~/jyh_ws/src/

# Orin 重建 (不删 vendor, 不删网线检测模型)
ssh nvidia@192.168.41.2 "
source /opt/ros/humble/setup.bash
cd ~/jyh_ws && rm -rf build/ install/
colcon build --symlink-install --packages-select wire_connect_msgs wire_connect_vision wire_connect_debug
source install/setup.bash
"
```

## Orin 离线依赖

```bash
# 笔记本下载 ARM64 轮子
pip3 download ultralytics --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
pip3 download "numpy<2" --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
scp /tmp/u_arm/*.whl nvidia@192.168.41.2:/tmp/u_arm/

# Orin 安装到包 vendor 目录
ssh nvidia@192.168.41.2 "
mkdir -p ~/jyh_ws/src/wire_connect_vision/vendor
rm -rf ~/jyh_ws/src/wire_connect_vision/vendor/numpy*
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/numpy-1.26.4*.whl
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/ultralytics*.whl
"
```

---

---

## 数据采集 (模仿学习)

### AGX — 同步 + 构建

```bash
# 笔记本 → AGX (全量同步src)
rsync -avz --exclude 'build/' --exclude 'install/' --exclude 'log/' \
  ~/WireConnect_ws/src/ nvidia@192.168.41.2:~/jyh_ws/src/

# AGX 构建
ssh nvidia@192.168.41.2 "
source /opt/ros/humble/setup.bash
cd ~/jyh_ws && rm -rf build/ install/
colcon build --symlink-install --packages-select wire_connect_msgs wire_connect_vision wire_connect_debug wire_connect_planner trajectory_bridge bodyctrl_msgs data_collect
source install/setup.bash
"
```

### AGX — 启动腕部相机

```bash
ssh nvidia@192.168.41.2
source /opt/ros/humble/setup.bash && source ~/realsense_ros2_ws/install/setup.bash
ros2 launch data_collect wrist_cameras.launch.py
```

### 笔记本 — 可视化 (SSH X转发)

```bash
ssh -X nvidia@192.168.41.2
# 腕部右
ros2 run rqt_image_view rqt_image_view /camera_wrist/camera_wrist/color/image_rect_raw --ros-args -p _image_transport:=compressed &

# 腕部左
ros2 run rqt_image_view rqt_image_view /camera_wrist_left/camera_wrist_left/color/image_rect_raw --ros-args -p _image_transport:=compressed &

# 头部 (机器人端，只有raw)
ros2 run rqt_image_view rqt_image_view /ob_camera_head/color/image_raw &
```

### AGX — 录制

```bash
source ~/jyh_ws/install/setup.bash
ros2 run data_collect record_episode --ros-args -p obs_window:=5 -p output_dir:=$HOME/jyh_ws/bags
```

操作: `s` 开始 → 拖臂做动作 → `s` 停止 → `y` 保留 / `n` 丢弃

### 笔记本 — 校验 + 转换

```bash
# 拖回数据
scp -r nvidia@192.168.41.2:~/jyh_ws/bags/ep_0002 ~/WireConnect_ws/bags/

# 校验
source ~/WireConnect_ws/install/setup.bash
ros2 run data_collect check_dataset ~/WireConnect_ws/bags/ep_0002 --obs-window 5

# 转 LeRobot 格式
ros2 run data_collect bag_to_lerobot ~/WireConnect_ws/bags/ep_0002 --output ~/lerobot_data --obs-window 5

# 导出视频查看
python3 -c "
from data_collect.bag_to_lerobot import read_bag, decode_image
streams = read_bag('~/WireConnect_ws/bags/ep_0002')
# ... export frames as mp4
"
```

---

## 网络

```bash
nmcli radio wifi off / on
nmtui
```

## SSH 免密

```bash
ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
ssh-copy-id ubuntu@192.168.41.1    # 密码 123
ssh-copy-id nvidia@192.168.41.2
```
