# WireConnect — 线缆连接 全自主方案

> 天轶2.0 Pro · 世界人形机器人运动会 · 灵巧手专项赛  
> ROS2 Humble + MoveIt2 + YOLO + OMPL


## 目录结构

| 目录 | 内容 |
|------|------|
| `src/` | 全部 ROS2 包（统一工作空间） |
| `tools/` | 工具脚本（ZMQ 遥操/调试/手柄桥接） |
| `data_collector/` | Web 相机预览（UDP JPEG 流） |
| `bags/` | 录制数据 |
| `Docs/Log/` | 工程日志 + 命令速查 |
| `Docs/Robot/` | 机器人使用手册、RealSense 部署文档 |

## ROS2 包

| 包 | 用途 |
|----|------|
| `wire_connect_msgs` | 自定义消息：ArmTarget / PlugDetect / PortDetect / TableInfo |
| `wire_connect_vision` | YOLO 双模型检测 + 深度反投影 + 桌子检测 |
| `wire_connect_planner` | cable_tracker 规划跟随 + planning_scene_manager 场景管理 |
| `wire_connect_debug` | 调试工具：键盘遥控/笛卡尔调试/gripper TF/相机/joint relay |
| `trajectory_bridge` | MoveIt 轨迹 → XARM /jointspace_commands |
| `tianyi2_moveit_config` | MoveIt2 配置：URDF/SRDF/OMPL planner |
| `data_collect` | 模仿学习数采：rosbag 录制 + 校验 + LeRobot 转换 |
| `xarm_debug` | XARM 话题监控 + 控制器交互管理 |
| `bodyctrl_debug` | Body 传感器监控 + 头部键盘遥控 |
| `bodyctrl_msgs` | body_control 自定义消息 |

## 架构

```
Orin AGX (感知)              笔记本 x86 (规划+控制)         机器人 x86 (执行)
┌──────────────────┐    DDS   ┌──────────────────────┐    ┌─────────────────┐
│ detect_both_node │─────────→│ planning_scene_manager│    │ tianyi2_bringup │
│ table_detector   │          │ cable_tracker        │    │ inspire_hand    │
│ wrist_cameras    │          │ move_group (OMPL+IK)  │───→│ /jointspace_*   │
└──────────────────┘          │ trajectory_bridge     │    └─────────────────┘
                              └──────────────────────┘
                                      ↑
                              同构臂→ZMQ→zmq_hand_control (机器人端)
```

## 启动流程

详见 [COMMANDS.md](src/Docs/Log/COMMANDS.md)

```bash
# 阶段1: 笔记本基础设施 (TF + relay + bridge)
ros2 launch wire_connect_debug infrastructure.launch.py

# 阶段2: 机器人 (SSH) — body_control + XARM + 使能
# 阶段3: Orin (SSH) — 视觉 + 腕部相机
# 阶段4: 笔记本 — move_group + RSP + tracker
```

## 规划策略

**两段式**：OMPL 绕障到线缆上方 → Cartesian 直线下插。

**gripper 偏移**：`GRIPPER_OFFSET = [0.02, -0.10, -0.13]` (TCP 坐标系)  
**朝向**：TCP Y↑(世界+Z)，TCP X∥线缆，XZ∥桌面，yaw 容差 ±10°

## 遥操左手

同构臂 → ZMQ :5003 → 机器人 `/inspire_hand/ctrl/left_hand`  
脚本：`tools/zmq_hand_control.py`（机器人端），Left[0] 按键张手/闭合

```bash
# 同步到机器人
scp ~/WireConnect_ws/tools/zmq_hand_control.py ubuntu@172.16.17.214:~/
```

## 录制数据

原始ROS2 bag (sqlite3)，三路raw图像 + 6维力 + TCP位姿 + 手指状态。  
校验：`ros2 run data_collect check_dataset <bag_dir> --obs-window 5`  
转换：`ros2 run data_collect bag_to_lerobot <bag_dir>`

## 比赛解题思路

状态机节点（wire_state_node），订阅 joint_states + hand_states：

```
init → 手臂放到桌子正上方 (waypoint + 障碍物)
  ↓
1 初始准备 (识别线缆+插口，记录位置)
  ↓
2 抓取线缆 (腕部相机确认手捏住)
  ↓
3 规划前往插口 (腕部相机确认)
  ↓
4 返回初始位姿 → 回到 1
```

很可惜，最后实在没时间完成纯自主方案。自主进度在完成数采脚本后停滞。下一步：在重力补偿模式下为抓取和插入两个短动作进行数采，然后模仿学习部署。
