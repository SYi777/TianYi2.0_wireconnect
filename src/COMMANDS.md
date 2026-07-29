# WireConnect 命令速查

> 最后更新: 2026-07-29

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
colcon build --symlink-install --packages-select wire_connect_vision
```

---

## 笔记本 — 视觉

```bash
# 检测节点 (YOLO双模型 + 深度 + 分配)
ros2 launch wire_connect_vision detect_both.launch.py
# 带窗口
ros2 launch wire_connect_vision detect_both.launch.py show_display:=true

# 桌面检测 (绿色区域深度采样, 5s一次)
ros2 run wire_connect_vision table_detector

# 相机原始画面 (debug)
ros2 run wire_connect_debug camera_view
```

## 笔记本 — 规划

```bash
# move_group 规划引擎
ros2 launch tianyi2_moveit_config move_group.launch.py

# 轨迹桥接 MoveIt→XARM
ros2 run trajectory_bridge trajectory_bridge --ros-args -p debug:=false

# 场景管理 (持续更新桌面障碍物)
ros2 run wire_connect_planner planning_scene_manager

# 规划节点 (状态机: 检测→规划→执行→跟踪)
ros2 launch wire_connect_planner planner.launch.py arm:=left
ros2 launch wire_connect_planner planner.launch.py arm:=right
```

### 规划状态机流程

```
IDLE → PLANNING(重试≤3) → EXECUTING → TRACKING
  ↑                                    ↓ 偏移>3cm非遮挡→PLANNING
  └── 失败回IDLE                       ↓ 遮挡(z跳变>5cm)→忽略
                                       ↓ target丢失>3s→保持
```

## 笔记本 — 可视化

```bash
# 离线 (纯URDF拖动)
ros2 launch tianyi2_moveit_config demo.launch.py

# 机器人实时模型
ros2 launch tianyi2_moveit_config rsp.launch.py
rviz2
# RViz: Fixed Frame → waist_yaw_link
# Add → RobotModel
# Add → Marker → /vision/table_marker
# Add → MarkerArray → /vision/detected_objects
```

## 笔记本 — 补 TF

```bash
# 相机 TF 链
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 camera_link ob_camera_head_link
# 验证
ros2 run tf2_ros tf2_echo waist_yaw_link ob_camera_head_color_optical_frame
# TF 树全景
ros2 run tf2_tools view_frames
```

## 笔记本 — 调试

```bash
# 话题频率
ros2 topic hz /ob_camera_head/color/image_raw/compressed
ros2 topic hz /ob_camera_head/depth/image_raw

# 话题数据
ros2 topic echo /vision/plugs --once
ros2 topic echo /vision/detected_objects --once
ros2 topic info /vision/detected_objects

# 话题列表
ros2 topic list | grep vision
```

---

## Orin — 部署 & 运行

```bash
# 同步代码 (笔记本→Orin)
rsync -avz --exclude 'build/' --exclude 'install/' --exclude 'log/' \
  ~/WireConnect_ws/src/ nvidia@192.168.41.2:~/jyh_ws/src/

# Orin 构建
source /opt/ros/humble/setup.bash
cd ~/jyh_ws
colcon build --symlink-install --packages-select wire_connect_msgs wire_connect_vision wire_connect_debug
source install/setup.bash

# Orin 运行 (必须加 PYTHONPATH 加载 vendor 依赖)
PYTHONPATH=$HOME/jyh_ws/src/wire_connect_vision/vendor:$PYTHONPATH \
  ros2 launch wire_connect_vision detect_both.launch.py

PYTHONPATH=$HOME/jyh_ws/src/wire_connect_vision/vendor:$PYTHONPATH \
  ros2 run wire_connect_vision table_detector
```

## Orin — 依赖 (离线)

```bash
# 笔记本下载 ARM64 轮子
pip3 download ultralytics --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
pip3 download "numpy<2" --platform manylinux2014_aarch64 --python-version 3.10 --only-binary=:all: -d /tmp/u_arm
scp /tmp/u_arm/*.whl nvidia@192.168.41.2:/tmp/u_arm/

# Orin 安装到包目录
mkdir -p ~/jyh_ws/src/wire_connect_vision/vendor
rm -rf ~/jyh_ws/src/wire_connect_vision/vendor/numpy*
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/numpy-1.26.4*.whl
pip3 install --target ~/jyh_ws/src/wire_connect_vision/vendor /tmp/u_arm/ultralytics*.whl
```

---

## 机器人 (SSH ubuntu@192.168.41.1)

```bash
# XARM 启动
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real

# 手臂初始化
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
ros2 control switch_controllers --activate jointspace_arm_L_controller

# 杀掉机器人 RSP (避免TF冲突)
pkill -f robot_state_publisher
```

## 网络

```bash
nmcli radio wifi off
nmcli radio wifi on
nmtui
gnome-control-center wifi
nm-connection-editor
```

## SSH 免密

```bash
ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
ssh-copy-id ubuntu@192.168.41.1    # 密码 123
ssh-copy-id nvidia@192.168.41.2
```

## 笔记本 — Orin 同步

```bash
# 同步代码 (排除 build/install/log，不覆盖 vendor)
rsync -avz --exclude 'build/' --exclude 'install/' --exclude 'log/' \
  ~/WireConnect_ws/src/ nvidia@192.168.41.2:~/jyh_ws/src/

# Orin 重建 (注意不要删 vendor)
cd ~/jyh_ws && rm -rf build/ install/
colcon build --symlink-install --packages-select wire_connect_msgs wire_connect_vision wire_connect_debug wire_connect_planner trajectory_bridge
source install/setup.bash
```
