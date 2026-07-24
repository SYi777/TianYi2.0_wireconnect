# xrocs 使用指南

> 天轶2.0 Pro 机器人控制 Python SDK (v3.1.6.1)
> 开发者: EAI
> 最后更新: 2026-07-20

---

## 1. 概述

**xrocs** 是天轶2.0 Pro 人形机器人的 Python 控制 SDK，提供从底层关节控制到高层 MoveIt2 规划的统一抽象。封装了 ROS2/DDS 通信、运动学、数据采集、相机、灵巧手等所有子系统的接口。

### 核心能力

| 能力 | 说明 |
|------|------|
| 关节状态读取 | 头/臂/腰/腿/手/力传感器 实时状态 |
| 关节空间控制 | 位置/速度/力位混合控制 |
| 笛卡尔空间控制 | 末端位姿规划 (body_control Service + MoveIt2) |
| 正运动学 | Pinocchio 正解 (head/arm TCP) |
| 相机 | Orbbec Gemini 330 / RealSense RGB-D |
| 灵巧手 | Inspire Hand 3 / Brainco / Robotiq |
| 数据采集 | HDF5 录制 (关节60Hz + 相机30Hz + 力100Hz) |
| 模型推理 | 闭环控制 (Diffusion Policy / ACT) |
| 底盘 | Slamtec 底盘控制 |

### 安装

```bash
# whl 文件路径
pip install ~/WireConnect_ws/unkonwn/xrocs/eai/syseai/xrocs-3.1.6.1-cp310-cp310-linux_x86_64.whl

# 配套灵巧手消息兼容层
pip install ~/WireConnect_ws/inspire_sdk/src/interfaces/RH5DG2/
```

### CLI 入口

```bash
# 数据采集模式 (运行在机器人 x86 上)
cd ~/eai/syseai
source /opt/ros/humble/setup.bash
export ROS_DOMAIN_ID=0
uv run xhumanoid-xrocs --mode data_collect
```

---

## 2. 模块结构

```
xrocs
├── core/                   # 核心
│   ├── config_loader       # ConfigLoader — 读取 TOML 配置文件
│   └── station_loader      # StationLoader — 工厂: 从配置构建 Station
├── entity/                 # 硬件实体
│   ├── robot/              # 机器人驱动
│   │   ├── TienYi2/        #   TienYi2Ros2Robot (旧版天轶2)
│   │   ├── TienYi2Pro/     #   TienYi2ProRos2Robot (Pro版)
│   │   ├── TienKung2/      #   天工2
│   │   ├── TienKung3/      #   天工3
│   │   ├── Franka/         #   Franka Panda
│   │   └── UR/             #   Universal Robots
│   ├── hand/               # 灵巧手驱动
│   │   ├── InspireHand/    #   InspireHand3Ros2 (因时)
│   │   ├── Brainco/        #   Brainco 手
│   │   ├── RobotiqUSB/     #   Robotiq 夹爪
│   │   └── hand_loader     #   工厂: instantiate_hands()
│   ├── camera/             # 相机驱动
│   │   ├── OrbbecCameraRos2
│   │   └── RealSenseCamera
│   └── station/            # Station 组合层
│       ├── TienYi2/
│       ├── TienYi2Pro/     #   TienYi2ProRos2Station
│       ├── TienKung2/
│       └── ...
├── apps/                   # 应用层
│   └── data_collection/    # 数据采集 (HDF5)
├── mc/                     # Motion Controller
│   ├── direct_ctrler       # 直接 Topic/Action 控制
│   └── moveit_ctrler       # MoveIt2 规划
├── common/                 # 公共数据类型
│   └── data_type           # Joints, Pose, PoseArray, Coordinate, Rotation
└── utils/                  # 工具
    ├── path_manager        # 管理配置/数据路径
    ├── ros2_node_manager   # 共享 ROS2 节点管理
    ├── camera_utils        # CameraUtils.decode_color_image()
    └── logger              # 日志
```

---

## 3. Station 模式 — 核心抽象

Station 将机器人、手、相机、力传感器组合为一个统一对象：

```
Station (TienYi2ProRos2Station)
├── Robot (TienYi2ProRos2Robot)
│   ├── state              状态读取 (head/arm/waist/leg)
│   ├── head_ctrler        头部控制 (roll, pitch, yaw)
│   ├── arm_ctrler         手臂控制 (14DOF)
│   ├── waist_ctrler       腰部控制 (2DOF)
│   ├── leg_ctrler         腿部控制
│   ├── mc                 Motion Controller
│   │   ├── direct_ctrler  直接控制
│   │   └── moveit_ctrler  MoveIt2 规划
│   ├── pin_kine           Pinocchio 正运动学
│   └── ros2controller     ROS2 controller 切换/执行
├── Hand (InspireHand3Ros2)  灵巧手
│   ├── get_position() / get_velocity() / get_effort()
│   ├── open() / sync_target_joint()
├── Camera (OrbbecCameraRos2) 相机
│   └── read() → (rgb_encoded, depth_encoded)
└── ForceSensor              六维力传感器
```

---

## 4. 基础用法

### 4.1 初始化 Station

```python
from xrocs.entity.station.TienYi2Pro.tienyi2_pro_ros2_station import TienYi2ProRos2Station

# 机器人配置
robot_dict = {
    "enable": True,
    "controller": {
        "sub_robot_state": True,               # 订阅 /robot_state
        "enable_pin_kine": True,               # 启用 Pinocchio 正运动学
        "enable_head_controller": True,        # 头部控制
        "enable_arm_controller": True,         # 手臂控制
        "enable_waist_controller": True,       # 腰部控制
        "enable_leg_controller": True,         # 腿部控制
        "enable_direct_motion_controller": True,   # 直接 Topic 控制
        "enable_moveit_motion_controller": True,   # MoveIt2 规划
        "arm": {
            "motor": {
                "spd": [1.0] * 14,    # 14个手臂电机速度 (rpm)
                "cur": [10.0] * 14    # 14个手臂电机电流 (A)
            }
        }
    }
}

# 相机配置
camera_dict = {
    "head": {
        "enable": True,
        "type": "OrbbecCameraRos2",
        "camera_name": "ob_camera_head",
        "use_compress_rgb": True,
        "use_compress_depth": False,
        "is_use_time_synchronizer": True,
    }
}

# 手部配置
hand_dict = {
    "left": {
        "enable": True,
        "type": "InspireHand3Ros2",
        "hand_name": "left",
        "sub_hand_joints": True
    },
    "right": {
        "enable": True,
        "type": "InspireHand3Ros2",
        "hand_name": "right",
        "sub_hand_joints": True
    }
}

# 力传感器配置
force_sensor_dict = {
    "enable": False,
    "type": "Srisensor"
}

# 构建 Station
station = TienYi2ProRos2Station(
    robot_dict=robot_dict,
    camera_dict=camera_dict,
    hand_dict=hand_dict,
    force_sensor_dict=force_sensor_dict,
    control_rate_hz=100.0
)

# 获取 robot handle
robot = station.get_robot_handle().get("robot")
```

### 4.2 关闭 Station

```python
def shutdown_station(station):
    if station is None:
        return
    try:
        station.shutdown()
    except Exception as e:
        print(f"Station shutdown error: {e}")
```

---

## 5. 状态读取

### 5.1 头部状态

```python
state = robot.state

# 等待第一帧数据到达
import time
deadline = time.monotonic() + 3.0
while time.monotonic() < deadline and state._get_state_snapshot() is None:
    time.sleep(0.05)

# 读取
state.get_head_pos_list()          # [roll, pitch, yaw] 弧度
state.get_head_pos_dict()          # {1: roll, 2: pitch, 3: yaw}
state.get_head_speed_list()        # 速度
state.get_head_current_list()      # 电流
state.get_head_temperature_list()  # 温度
state.get_head_mos_temperature_list()  # MOS 管温度
state.get_head_error_dict()        # 错误码
```

### 5.2 手臂状态

```python
# 双臂 (14关节: 左7 + 右7)
state.get_arm_pos_list()           # 14个关节角
state.get_left_arm_pos_list()      # 7个左臂关节角
state.get_right_arm_pos_list()     # 7个右臂关节角
state.get_arm_current_list()       # 电流
state.get_arm_error_dict()         # 错误码
```

### 5.3 腰部状态

```python
state.get_waist_pos_list()         # 2个关节角 (电机31, 32)
state.get_waist_speed_list()
state.get_waist_current_list()
state.get_waist_temperature_list()
state.get_waist_error_dict()
```

### 5.4 腿部状态

```python
state.get_leg_pos_list()           # 腿部关节
state.get_left_leg_pos_list()      # 左腿
state.get_right_leg_pos_list()     # 右腿
state.get_leg_error_dict()
```

---

## 6. 关节空间控制

### 6.1 头部控制

```python
head = robot.head_ctrler

# 方式1: 列表 (roll, pitch, yaw) 弧度
head.set_cmd_position([0.2, 0.0, 0.0], timeout=3.0, pub_interval=0.1)

# 方式2: 字典 (按电机名)
head.set_cmd_pos([
    {"name": 1, "pos": 0.0, "spd": 0.5, "cur": 4.0},   # roll
    {"name": 2, "pos": 0.2, "spd": 0.5, "cur": 3.0},   # pitch
    {"name": 3, "pos": 0.0, "spd": 0.75, "cur": 4.0}   # yaw
])

# 读取当前位置
cur_joints = head.get_current_joint()  # (roll, pitch, yaw)
```

### 6.2 手臂控制

```python
arm = robot.arm_ctrler  # 或 robot.dual_arm_ctrler

# 位置控制 (14关节: 左7 + 右7)
arm.set_cmd_position(cmd, timeout=3.0, pub_interval=0.1)

# 同步目标关节 (带频率切换)
arm.sync_target_joint(arm_joints_cmd, flex_freq=True)

# 力位混合控制
arm.sync_ctrl_target_joint(arm_joints_cmd)

# 速度控制
arm.set_cmd_vel([{"name": 14, "spd": -0.1, "cur": 15.0}])

# 回到当前位姿
cur = arm.get_current_joint()
arm.reach_target_joint(cur)
```

### 6.3 腰部控制

```python
waist = robot.waist_ctrler

# 位置控制
waist.set_cmd_pos([0.0, 0.0])             # [motor31, motor32] 弧度
waist.set_yaw_cmd_pos(0.0)                # 仅偏航
```

### 6.4 腿部控制

```python
leg = robot.leg_ctrler

# 获取/设置位置
leg.get_pos()
leg.set_cmd_pos(target=[0.0, 0.0])        # [motor51, motor52]
```

---

## 7. 正运动学

```python
kin = robot.pin_kine
import numpy as np

head_q = np.array([0.0, 0.0, 0.0])       # 头部关节 [3,]
left_q = np.array([0.0]*7)                # 左臂关节 [7,]
right_q = np.array([0.0]*7)               # 右臂关节 [7,]

# 查看模型信息
kin.get_joint_names()                     # 所有关节名
kin.get_all_frame_names()                 # 所有 frame 名

# TCP 在 base 坐标系下的位姿 (xyz(m) + xyzw)
kin.get_left_tcp_pose(left_q).get_xyz_m_xyzw_ndarray()
kin.get_right_tcp_pose(right_q).get_xyz_m_xyzw_ndarray()
kin.get_head_pose(head_q).get_xyz_m_xyzw_ndarray()

# TCP 在头部坐标系下的位姿 (head→hand)
kin.get_head_to_left_tcp_pose(head_q, left_q).get_xyz_m_xyzw_ndarray()
kin.get_head_to_right_tcp_pose(head_q, right_q).get_xyz_m_xyzw_ndarray()
```

---

## 8. MoveIt2 规划控制

### 8.1 使能/失能手臂

```python
mc = robot.mc

# 使能手臂 (必须先使能才能运动)
mc.enable_arm(timeout_sec=3.0)

# 设置控制模式
mc.set_arm_mode(3, timeout_sec=3.0)       # mode 3: 高刚度位置模式

# 失能
mc.disable_arm(timeout_sec=3.0)

# 错误信息
mc.get_warn_error_info(source="EAIHardware", history=5)
mc.clear_warn_error_info()
```

### 8.2 关节空间规划

```python
from xrocs.common.data_type import Joints

moveit = robot.mc.moveit_ctrler

# 单臂 — 阻塞等待完成
moveit.reach_joints_and_wait(
    motion_mode="left_arm",
    left_target_joints=Joints([0.1, 0.1, 0.0, -0.4, 0.0, 0.0, 0.2], num_of_dofs=7),
    vel_scale=0.1,
    acc_scale=0.1,
    timeout=30.0
)

# 双臂 — 非阻塞发送
accepted = moveit.reach_joints(
    motion_mode="dual_arm",
    left_target_joints=Joints([0.1, 0.2, 0.0, -0.3, 0.0, 0.0, 0.0], num_of_dofs=7),
    right_target_joints=Joints([0.1, -0.2, 0.0, -0.3, 0.0, 0.0, 0.0], num_of_dofs=7),
    vel_scale=0.1,
    acc_scale=0.1
)
if accepted:
    moveit.wait_joints_finish(timeout=30.0)

# 多路点轨迹
left_trajectory = [
    Joints([0.1, 0.2, 0.0, -0.3, 0.2, 0.0, 0.0], num_of_dofs=7),
    Joints([0.1, 0.2, 0.0, -0.4, 0.3, 0.0, 0.0], num_of_dofs=7),
    Joints([0.1, 0.2, 0.0, -0.4, 0.3, 0.0, 0.2], num_of_dofs=7),
]
moveit.reach_joints_and_wait(
    motion_mode="dual_arm",
    left_target_joints=left_trajectory,
    right_target_joints=right_trajectory,
    vel_scale=0.1, acc_scale=0.1, timeout=60.0
)
```

### 8.3 笛卡尔空间规划

```python
from xrocs.common.data_type import PoseArray, Coordinate, Rotation, BaseData

# 位姿格式: [x, y, z, qx, qy, qz, qw] (位置(m) + 四元数(XYZW))

# 单臂单路点
left_waypoints = PoseArray(
    pose_array_data=[[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0]],
    coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
    length_unit_type=BaseData.LengthUnitType.METER,
    rotation_form_type=Rotation.FormType.XYZW,
)

moveit.reach_cartesian_and_wait(
    group="left_arm",
    mode="plan_and_execute",
    left_motion_id=1,
    left_waypoints=left_waypoints,
    vel_scale=0.1,
    acc_scale=0.1,
    timeout=30.0
)

# 双臂多路点
dual_left_waypoints = PoseArray(
    pose_array_data=[
        [0.1, 0.40, -0.15, 0.0, 0.0, 0.0, 1.0],
        [0.1, 0.30, -0.20, 0.0, 0.0, 0.0, 1.0],
    ],
    coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
    rotation_form_type=Rotation.FormType.XYZW,
)

moveit.reach_cartesian_and_wait(
    group="dual_arm",
    mode="plan_and_execute",
    left_motion_id=0,
    left_waypoints=dual_left_waypoints,
    right_motion_id=0,
    right_waypoints=dual_right_waypoints,
    vel_scale=0.1,
    acc_scale=0.1,
    timeout=60.0
)
```

### 8.4 TF 查询

```python
moveit = robot.mc.moveit_ctrler

# 获取末端位姿
moveit.get_left_tcp_pose()
moveit.get_right_tcp_pose()
moveit.get_head_pose()
moveit.get_head_camera_pose()

# 任意 frame 间变换
moveit.get_transformation_between_frames("waist_yaw_link", "left_tcp_link")
```

### 8.5 碰撞物体管理

```python
from xrocs.common.data_type import Pose, Coordinate, Rotation

box_pose = Pose(
    coordinate=Coordinate(
        data=[1.0, 1.0, 1.0],
        length_unit_type=BaseData.LengthUnitType.METER,
    ),
    rotation=Rotation(
        data=[0.0, 0.0, 0.0, 1.0],
        rotation_form_type=Rotation.FormType.XYZW,
    )
)

# 添加单个障碍物
moveit.add_obstacle(
    sharp_type='BOX',
    object_name='obstacle1',
    dimensions=[0.5, 0.5, 0.5],
    pose=box_pose
)

# 批量添加
moveit.add_obstacles([
    {"sharp_type": "BOX", "object_name": "obs1", "dimensions": [1,1,1], "pose": box_pose},
    {"sharp_type": "SPHERE", "object_name": "obs2", "dimensions": [1], "pose": box_pose}
])

# 删除
moveit.remove_obstacle('obstacle1')
moveit.remove_all_obstacles()
```

---

## 9. 直接控制器 (Direct Controller)

绕过 MoveIt2，直接操作 ROS2 Topic/Action/Service。

### 9.1 控制器切换

```python
mc = robot.mc
direct = mc.direct_ctrler

# 激活控制器
mc.activate_controllers(
    ["jointspace_arm_L_controller"],
    via_http=True,
    timeout_sec=3.0
)

# 停用
mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)
```

### 9.2 Topic 方式 (直接发布)

```python
# 左臂关节空间
direct.pub_jointspace_commands_l([0.1, 0.1, 0.0, -0.4, 0.0, 0.0, 0.3])

# 右臂关节空间
direct.pub_jointspace_commands_r([0.1, -0.1, 0.0, -0.4, 0.0, 0.0, -0.3])

# 左臂末端位姿
direct.pub_endposetarget_l(
    from_frame="waist_yaw_link",
    to_frame="left_tcp_link",
    target=[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0],  # xyz + xyzw
    offset=[0.0, 0.0, 0.0],
)

# 右臂末端位姿
direct.pub_endposetarget_r(
    from_frame="waist_yaw_link",
    to_frame="right_tcp_link",
    target=[0.1, -0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
    offset=[0.0, 0.0, 0.0],
)
```

### 9.3 Action 方式 (带反馈)

```python
def feedback_cb(feedback_msg):
    print(f"[feedback] {feedback_msg}")

# 关节空间 Action
direct.act_jointspace_arm_L_controller(
    target=[0.1, 0.2, 0.0, -0.2, 0.0, 0.0, 0.0],
    feedback_callback=feedback_cb,
    timeout_sec=30.0
)

# 末端位姿 Action
direct.act_endpose_single_arm_qp_L_controller(
    from_frame="waist_yaw_link",
    to_frame="left_tcp_link",
    target=[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
    offset=[0.0, 0.0, 0.0],
    feedback_callback=feedback_cb,
    timeout_sec=30.0
)
```

### 9.4 IK 可达性检查

```python
direct.srv_check_endpose_single_arm_qp_L_reachability(
    from_frame="waist_yaw_link",
    to_frame="left_tcp_link",
    target=[0.1, 0.35, -0.3, 0.0, 0.0, 0.0, 1.0],
    offset=[0.0, 0.0, 0.0]
)
```

---

## 10. 灵巧手控制

### 10.1 初始化

```python
from xrocs.entity.hand.hand_loader import hand_loader

hand_cfgs = {
    "left": {
        "enable": True,
        "type": "InspireHand3Ros2",
        "hand_name": "left",
        "sub_hand_joints": True
    },
    "right": {
        "enable": True,
        "type": "InspireHand3Ros2",
        "hand_name": "right",
        "sub_hand_joints": True
    }
}

hands = hand_loader.instantiate_hands(hand_cfgs=hand_cfgs)
left_hand = hands["left"]
left_hand.connect()
```

### 10.2 读取与控制

```python
hand = hands["left"]

# 读取
hand.get_position()            # 关节位置
hand.get_velocity()            # 速度
hand.get_effort()              # 力/力矩
hand.get_current_joint().get_radian_ndarray()  # 当前关节 (弧度 numpy)
hand.num_dofs()                # 自由度数

# 控制
hand.open()                    # 张开
hand.sync_target_joint([1.0] * hand.num_dofs())  # 设置目标关节
```

---

## 11. 相机

```python
from xrocs.utils.camera_utils import CameraUtils
import cv2

# 通过 Station 获取相机
cameras = station.get_camera_handle()
camera = cameras["head"]

# 读取一帧
rgb_encoded, depth_encoded = camera.read(timeout=2.0, check_interval=0.1)

# 解码
rgb_decoded = CameraUtils.decode_color_image(encoded_color_image=rgb_encoded)

# OpenCV 显示
rgb_bgr = cv2.cvtColor(rgb_decoded, cv2.COLOR_RGB2BGR)
cv2.imwrite("output.jpg", rgb_bgr)

# 批量读取
images, depths = station.get_camera_state()
for name, img in images.items():
    print(f"[{name}] {img.shape}")
```

---

## 12. Station 统一接口

适用于强化学习/模仿学习等需要统一 obs/action 接口的场景。

### 12.1 读取观测 (get_obs)

```python
obs = station.get_robot_state()  # 或 robot_station.get_obs()

# obs 字典结构:
# {
#     "head_joints": np.ndarray,       # (3,)  弧度
#     "head_pose": np.ndarray,         # (7,)  xyz(m)+xyzw
#     "arm_joints": {
#         "left": np.ndarray,          # (7,)  弧度
#         "right": np.ndarray          # (7,)  弧度
#     },
#     "arm_pose": {
#         "left": np.ndarray,          # (7,)  xyz(m)+xyzw
#         "right": np.ndarray          # (7,)  xyz(m)+xyzw
#     },
#     "waist_joints": np.ndarray,      # (2,)  弧度
#     "leg_joints": Any,
#     "hand_joints": {
#         "left": np.ndarray,
#         "right": np.ndarray
#     },
#     "hand_touch": {
#         "left": Any,
#         "right": Any
#     },
#     "end_effector_force": {
#         "left": Any,
#         "right": Any
#     },
#     "chassis_state": {
#         "chassis_twist": np.ndarray  # (3,)  [linear_x, linear_y, angular_z]
#     }
# }
```

### 12.2 执行动作 (execute_action)

```python
action = {}

# 头部
action["head"] = {"position": [
    {"name": 1, "pos": 0.0, "spd": 0.5, "cur": 4.0},
    {"name": 2, "pos": 0.0, "spd": 0.5, "cur": 3.0},
]}

# 手臂
action["arm"] = {"position": {
    "left": [0.0]*7,
    "right": [0.0]*7
}}

# 腰部
action["waist"] = {"position": [
    {"name": 31, "pos": 0.0, "spd": 1.0, "cur": 10.0},
    {"name": 32, "pos": 0.0, "spd": 1.0, "cur": 10.0},
]}

# 手部
action["hand"] = {"position": {
    "left": np.array([0.0]),
    "right": np.array([0.0])
}}

# 底盘
action["chassis"] = np.array([0.5, 0.0, 0.0])  # m/s, m/s, rad/s

station.execute_action(action)
```

### 12.3 模型推理闭环

```python
# 关节空间推理
obs = robot_station.get_obs()
while True:
    action_pred = model.infer(obs)                   # 模型推理
    robot_targets = robot_station.decompose_action(action_pred)
    obs = robot_station.step(robot_targets)          # 关节控制

# 末端空间推理
obs = robot_station.get_obs()
while True:
    action_pred = model.infer(obs)
    robot_targets = robot_station.decompose_action(action_pred)
    obs = robot_station.step_ee(robot_targets)       # 末端控制
```

---

## 13. 数据采集

```python
from xrocs.apps.data_collection.data_collector import data_collector_loader
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

config_path = str(path_manager.config_toml_path)
cfg_loader = ConfigLoader(config_path)
cfg_dict = cfg_loader.get_config()

collector = data_collector_loader(
    config_path=config_path,
    save_type=cfg_dict["data_collect"]["save_type"]  # "hdf5"
)
collector.prepare()
collector.start_collect(
    data_dir=cfg_dict["data_collect"]["save_path"],
    task_name=cfg_dict["data_collect"]["task_name"],
    task_description=cfg_dict["data_collect"]["task_description"]
)
```

---

## 14. 数据类型参考

### 14.1 Joints

```python
from xrocs.common.data_type import Joints, BaseData

# 构造函数
j = Joints(
    data=[0.1, 0.2, 0.0, -0.4, 0.0, 0.0, 0.2],
    num_of_dofs=7,
    angle_unit_type=BaseData.AngleUnitType.RADIAN  # 默认
)
```

### 14.2 Pose / PoseArray

```python
from xrocs.common.data_type import Pose, PoseArray, Coordinate, Rotation, BaseData

# 单个 Pose
pose = Pose(
    coordinate=Coordinate(
        data=[1.0, 1.0, 1.0],                      # x, y, z
        length_unit_type=BaseData.LengthUnitType.METER,
    ),
    rotation=Rotation(
        data=[0.0, 0.0, 0.0, 1.0],                 # 四元数
        rotation_form_type=Rotation.FormType.XYZW,
    )
)

# PoseArray
waypoints = PoseArray(
    pose_array_data=[
        [0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0],    # xyz + xyzw
        [0.1, 0.30, -0.2, 0.0, 0.0, 0.0, 1.0],
    ],
    coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
    length_unit_type=BaseData.LengthUnitType.METER,
    rotation_form_type=Rotation.FormType.XYZW,
)
```

### 14.3 坐标系枚举

```python
Coordinate.CoordinateSystem.WAIST_YAW_LINK    # 腰部偏航坐标系
Coordinate.CoordinateSystem.BASE              # 基座坐标系
# ... 等
```

### 14.4 旋转格式枚举

```python
Rotation.FormType.XYZW     # 四元数 (qx, qy, qz, qw)
Rotation.FormType.WXYZ     # 四元数 (qw, qx, qy, qz)
# ... 等
```

---

## 15. 配置管理

### 15.1 TOML 配置文件

```python
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

# 从默认路径加载
config_path = str(path_manager.config_toml_path)
cfg_loader = ConfigLoader(config_path)
config = cfg_loader.get_config()

# 按 section 读取
robot_config = config["robot"]
hand_config = config["hand"]
camera_config = config["camera"]
data_config = config["data_collect"]
```

### 15.2 StationLoader (从配置批量构建)

```python
from xrocs.core.station_loader import StationLoader

cfg_loader = ConfigLoader(config_path)
cfg_dict = cfg_loader.get_config()

station_loader = StationLoader(cfg_dict)
robot_station = station_loader.get_station_handle()
robot_station.connect()
```

---

## 16. ROS2 节点管理

```python
from xrocs.utils.ros2_node_manager import ros2_node_manager

# 获取共享节点
node = ros2_node_manager.acquire()

# 直接用节点创建机器人 (不走 Station)
from xrocs.entity.robot.TienYi2.tienyi2_ros2 import TienYi2Ros2Robot
robot = TienYi2Ros2Robot(node=node, robot_config=robot_config)
```

---

## 17. 日志

```python
from xrocs.utils.logger.logger_loader import logger

logger.info("信息")
logger.success("成功")    # 绿色
logger.warning("警告")    # 黄色
logger.error("错误")      # 红色
```

---

## 18. ROS2 Controller 切换 (底层)

```python
ros2controller = robot.ros2controller

# 切换控制器
ros2controller._controller_switcher.switch_controllers(
    activate=["jointspace_arm_L_controller", "jointspace_arm_R_controller"]
)
ros2controller._controller_switcher.switch_controllers(
    deactivate=["jointspace_arm_L_controller"]
)

# 执行关节空间控制器
ros2controller.exec_jointspace_arm_L_controller(
    target=[0.2, 0.2, 0.0, -0.2, 0.0, 0.0, 0.0]
)

# 可用的控制器:
#   jointspace_arm_L_controller / jointspace_arm_R_controller       — 关节空间
#   jointspace_arm_L_collisionfree_controller / ..._R_...           — 避碰关节空间
#   jointspace_ruckig_qp_controller                                 — Ruckig QP 全身
#   endpose_single_arm_qp_L_controller / ..._R_...                  — 单臂末端 QP
#   jointspace_head_controller                                      — 头部关节
#   moveit_left_arm_controller / moveit_right_arm_controller        — MoveIt2
```

---

## 19. 不依赖 xrocs 的替代方案

如果暂时无法安装 xrocs（或不需要高层抽象），可以直接用 rclpy + bodyctrl_msgs：

```python
import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
from std_msgs.msg import Header

class RobotController(Node):
    def __init__(self):
        super().__init__('my_controller')
        self._arm_pub = self.create_publisher(
            CmdSetMotorPosition, '/arm/cmd_pos', 10
        )

    def move_arm(self, positions: list):
        msg = CmdSetMotorPosition()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.cmds = [
            SetMotorPosition(name=i+11, pos=p, spd=1.0, cur=10.0)
            for i, p in enumerate(positions[:7])
        ]
        self._arm_pub.publish(msg)

# 底层 Topic 列表:
#   /arm/cmd_pos       — 手臂位置控制 (电机11-17左, 21-27右)
#   /arm/cmd_ctrl      — 手臂力位混合控制
#   /arm/status        — 手臂状态
#   /head/cmd_pos      — 头部控制 (电机1-3)
#   /waist/cmd_pos     — 腰部控制 (电机31-33)
#   /leg/cmd_pos       — 腿部控制 (电机51-66)
#   /inspire_hand/ctrl/left_hand   — 左手控制
#   /inspire_hand/ctrl/right_hand  — 右手控制
#   /arm_6dof_left     — 左腕六维力 (100Hz)
#   /arm_6dof_right    — 右腕六维力 (100Hz)
```

---

## 20. body_control 自带规划 Service

body_control 内置了 3 个无需 MoveIt2 即可使用的规划 Service：

| Service | 输入 | 功能 |
|---------|------|------|
| `PlanEefLine` | `arm_name` + `eef_pose`(Pose) + 速度/加速度比例 | **绝对笛卡尔空间移动** |
| `PlanEefRelLine` | `arm_name` + `dx,dy,dz`(米) + 速度/加速度比例 | **相对移动**（如"往下移3cm"） |
| `PlanJointTraj` | `arm_name` + 目标关节角 + 速度/加速度/jerk | **关节空间移动** |

这些 Service 不依赖 MoveIt2，直接在 body_control 进程中运行。对于简单的抓放任务（如线缆连接比赛），这是最直接高效的控制方式。

---

## 21. 完整示例: 从初始化到笛卡尔移动

```python
"""完整示例: 初始化Station → 读取状态 → 笛卡尔空间移动"""
from __future__ import annotations
import time
import numpy as np

from xrocs.entity.station.TienYi2Pro.tienyi2_pro_ros2_station import TienYi2ProRos2Station
from xrocs.common.data_type import Joints, PoseArray, Coordinate, Rotation, BaseData
from xrocs.utils.logger.logger_loader import logger


def main():
    station = None
    try:
        # 1. 构建 Station
        robot_dict = {
            "enable": True,
            "controller": {
                "sub_robot_state": True,
                "enable_pin_kine": True,
                "enable_arm_controller": True,
                "enable_direct_motion_controller": True,
                "enable_moveit_motion_controller": True,
                "arm": {
                    "motor": {
                        "spd": [1.0] * 14,
                        "cur": [10.0] * 14
                    }
                }
            }
        }
        
        station = TienYi2ProRos2Station(
            robot_dict=robot_dict,
            camera_dict={},
            hand_dict={},
            force_sensor_dict={},
            control_rate_hz=100.0,
        )
        robot = station.get_robot_handle().get("robot")
        logger.success("Station ready.")

        # 2. 等待状态
        deadline = time.monotonic() + 3.0
        while time.monotonic() < deadline and robot.state._get_state_snapshot() is None:
            time.sleep(0.05)
        
        if robot.state._get_state_snapshot() is None:
            logger.error("No robot state received.")
            return

        # 3. 读取当前关节
        left_q = np.asarray(robot.state.get_left_arm_pos_list())
        logger.info(f"Current left arm joints: {left_q}")

        # 4. 正运动学 — 获取当前 TCP 位姿
        tcp_pose = robot.pin_kine.get_left_tcp_pose(left_q).get_xyz_m_xyzw_ndarray()
        logger.info(f"Current left TCP pose: {tcp_pose}")

        # 5. 使能手臂
        robot.mc.enable_arm(timeout_sec=3.0)

        # 6. 笛卡尔空间移动 (MoveIt2)
        moveit = robot.mc.moveit_ctrler
        waypoints = PoseArray(
            pose_array_data=[[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0]],
            coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
            length_unit_type=BaseData.LengthUnitType.METER,
            rotation_form_type=Rotation.FormType.XYZW,
        )
        moveit.reach_cartesian_and_wait(
            group="left_arm",
            mode="plan_and_execute",
            left_motion_id=1,
            left_waypoints=waypoints,
            vel_scale=0.1,
            acc_scale=0.1,
            timeout=30.0
        )

        # 7. 失能手臂
        robot.mc.disable_arm(timeout_sec=3.0)
        logger.success("Done.")

    except KeyboardInterrupt:
        logger.warning("Interrupted.")
    finally:
        if station is not None:
            station.shutdown()


if __name__ == "__main__":
    main()
```

---

## 22. 注意事项

1. **运动命令会驱动机器人** — 运行前确保急停可用，建议先用 `XROCS_TEST_NONINTERACTIVE=1` 禁用交互确认
2. **必须先使能手臂** — 调用 `mc.enable_arm()` 后才能发送运动命令
3. **所有角度用弧度** — `Joints` 默认 `AngleUnitType.RADIAN`
4. **所有位置用米** — `Pose` 默认 `LengthUnitType.METER`
5. **机器人必须完成自检** — 蓝绿常亮后才可通过 ROS2 控制
6. **DDS 需要同一网段** — 笔记本必须和机器人配置在同一子网 (有线 `192.168.41.x`, 无线 `10.11.x.x`)
7. **xrocs 话题命名** — 手部话题用 `/left_hand/*` 和 `/right_hand/*`（原生 SDK 用 `/hand_left/*` / `/hand_right/*`）

---

## 23. 相关文档

| 文档 | 路径 | 说明 |
|------|------|------|
| 项目日志 | `Docs/Log/PROJECT_LOG.md` | 完整开发进程记录 |
| 系统架构 | `Docs/Log/Mammonth.md` | 天轶2.0架构概述 |
| 启动指南 | `Docs/Log/START.md` | 开机/联网/相机/控制 |
| MoveIt2 安装 | `ROS/moveit_ws/笛卡尔规划安装及使用.md` | 笛卡尔规划 API |
| Inspire SDK | `inspire_sdk/docs/` | 灵巧手驱动文档 |
| 灵巧手 ROS2 API | `inspire_sdk/docs/EG5CD1_ROS2_API.md` | 灵巧手 ROS2 接口 |
