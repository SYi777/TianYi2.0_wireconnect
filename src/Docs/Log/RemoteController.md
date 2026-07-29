# 遥操数据采集系统架构

> 目标机器人: 天轶2.0 Pro | 主端: 天梭 TS1P 同构臂 + Manus Pro 手套 | 更新时间: 2026-07-19
>
> 作者: 景宇航 | 更新: 朱良超 (2026-07-19, 操作流程+数据流细化)
>
> **腕部相机尚未接入**, 当前仅使用头部 Orbbec Gemini 330 相机。

---

## 1. 机器角色与网络

所有机器通过 **192.168.41.x 有线以太网** 互联，DDS 白名单: .1 .2 .5 .6 .100。

```
192.168.41.100             192.168.41.5              192.168.41.1          192.168.41.2
┌──────────────┐          ┌──────────────┐          ┌──────────────┐      ┌──────────────┐
│   工控机      │          │   笔记本      │          │ 天轶2.0 Pro  │      │   Orin AGX   │
│   (eai)      │          │  (你的电脑)   │          │   (x86)      │      │   (感知)     │
│              │          │              │          │              │      │              │
│ 无 ROS2      │          │ 有 ROS2      │          │ ROS2 Humble  │      │ ROS2 Humble  │
│              │          │ eai_env      │          │ freq_change  │      │ 相机驱动     │
│              │          │ sharpa_      │          │ xrocs        │      │              │
│              │          │ retarget     │          │              │      │              │
└──────┬───────┘          └──────┬───────┘          └──────┬───────┘      └──────┬───────┘
       │                         │                         │                      │
  CAN 读同构臂              USB 读手套              EtherCAT/CAN 驱电机       USB3 相机
  ZMQ 发布数据              ZMQ 发布手套流           xrocs收ZMQ并发ROS2      ROS2/DDS
```

| IP | 机器 | 运行的进程 |
|----|------|-----------|
| 192.168.41.100 | 工控机 | fast_sync (读同构臂CAN → ZMQ发布手臂角度), tele_manage |
| 192.168.41.5 | 笔记本 | SharpaManusClient (读手套), retargeting_manus (重定向), xtele --zmqpub manus (ZMQ发布手套关节角). 同构臂和手套数据分开传输 |
| 192.168.41.1 | 机器人 | xrocs --mode data_collect (接收ZMQ→整理→发freq_change), freq_change, body_control |
| 192.168.41.2 | Orin | orbbec_camera |

---

## 2. 完整数据流

```
┌──────────────────────────────────────────────────────────────────────────┐
│                         工控机 192.168.41.100                            │
│                                                                          │
│  天梭同构臂 TS1P                                                         │
│  ┌─────────────┐                                                        │
│  │ 左臂 7DOF   │──┐                                                     │
│  │ 右臂 7DOF   │  │   CAN                   ┌──────────────────────┐    │
│  │ 腰 1DOF     │  │────────────────────────→│                      │    │
│  └─────────────┘  │                         │  fast_sync           │    │
│                   │                         │  ├─ PostTeleAgent    │    │
│                   │                         │  │  ├─ 读同构臂角度  │    │
│                   │                         │  │  ├─ 读手柄输入    │    │
│                   │                         │  │  └─ 生成控制指令  │    │
│                   │                         │  │                   │    │
│                   │                         │  ├─ CmdPubServer     │    │
│                   │                         │  ├─ JoyPubServer     │    │
│                   │                         │  └─ LocalDataPubServer│   │
│                   │                         └──────────┬───────────┘    │
│                   │                                    │                │
│                   │                           ZMQ PUB  │                │
│                   │                           手臂关节角│                │
│                   │                           手柄状态  │                │
└───────────────────┼────────────────────────────────────┼────────────────┘
                    │                                    │
                    │                   ZMQ → 机器人 xrocs
                    │                                    │
┌───────────────────┼────────────────────────────────────┼────────────────┐
│                   │          笔记本 192.168.41.5        │                │
│                   │                                    │                │
│  Manus Pro 手套   │                                                     │
│  ┌──────────┐    │                                                     │
│  │USB 接收器│    │                                                     │
│  └────┬─────┘    │                                                     │
│       │ USB      │                                                     │
│  ┌────▼──────────────┐                                                │
│  │ SharpaManusClient │  C++ SDK, 手套动捕原始数据                      │
│  │ (sudo)            │  每手25个关键点 (xyz + 四元数)                   │
│  └────────┬─────────┘                                                │
│           │ ZMQ PUB (protobuf)                                        │
│  ┌────────▼──────────────────────────────────────┐                    │
│  │ retargeting_manus_demo_multiprocess.py -wave  │ sharpa_retarget    │
│  │                                               │                    │
│  │  人手关键点 → 优化求解 → HA4 灵巧手关节角      │                    │
│  │  ZMQ SUB (动捕) → ZMQ PUB (手部关节)          │                    │
│  └────────┬──────────────────────────────────────┘                    │
│           │ 手部关节角 (左手22DOF + 右手22DOF)                         │
│           │                                                            │
│  ┌────────▼──────────────────────────────────────────────────────┐    │
│  │              xhumanoid-xtele --zmqpub manus (eai_env)         │    │
│  │                                                                │    │
│  │  输入:                                                         │    │
│  │  └─ ZMQ SUB ← 本地 (手部关节角: 左手22+右手22)                │    │
│  │                                                                │    │
│  │  转发:                                                         │    │
│  │  Manus→HA4 手部关节角 → tcp://0.0.0.0:7015                    │    │
│  │                                                                │    │
│  │  输出:                                                         │    │
│  │  ZMQ PUB → 机器人 xrocs                                        │    │
│  └────────────────────────────────────────────────────────────────┘    │
│                                                                        │
│  同构臂和手套数据分开传输, 汇总在机器人端完成                            │
└────────────────────────────────────────────────────────────────────────┘
                                         │
                                  ZMQ (7015)
                                  192.168.41.x 有线
                                         │
┌────────────────────────────────────────┼────────────────────────────────┐
│                       机器人 192.168.41.1                               │
│                                        │                                │
│  ┌─────────────────────────────────────▼──────────────────────────┐    │
│  │  xhumanoid-xrocs --mode data_collect (数据采集/控制发布)        │    │
│  │                                                                 │    │
│  │  ZMQ 读取主端数据                                               │    │
│  │  ├─ 来自工控机: 同构臂/手柄                                     │    │
│  │  └─ 来自笔记本: Manus→HA4 手部关节角                            │    │
│  │                                                                 │    │
│  │  ROS2 发布:                                                     │    │
│  │  ├─ /joint_states_flex_freq → freq_change                       │    │
│  │  └─ arm/head/leg/hand 控制话题                                  │    │
│  │                                                                 │    │
│  │  录制 ──→ HDF5 (~/Data/sim_data/)                              │    │
│  │  └─ 关节状态60Hz + 相机30Hz + 六维力100Hz                       │    │
│  └─────────────────────────────────────┬──────────────────────────┘    │
│                                        │ /joint_states_flex_freq        │
│  ┌─────────────────────────────────────▼──────────────────────────┐    │
│  │  freq_change (ros2 launch freq_change freq_change.launch.py)   │    │
│  │                                                                 │    │
│  │  力位混合控制 → 转换 bodyctrl 手臂控制格式                      │    │
│  └─────────────────────────────────────┬──────────────────────────┘    │
│                                        │                                │
│  ┌─────────────────────────────────────▼──────────────────────────┐    │
│  │  body_control (bodyctrl)                                       │    │
│  │                                                                 │    │
│  │  ┌─ SOEM (EtherCAT) → 左臂7DOF / 右臂7DOF 电机                  │    │
│  │  ├─ CAN            → Inspire Hand 3 灵巧手                     │    │
│  │  └─ CAN            → 头/腰/腿 电机                             │    │
│  └────────────────────────────────────────────────────────────────┘    │
│                                                                        │
└────────────────────────────────────────────────────────────────────────┘
```

---

## 3. 控制链路

```
同构臂 + Manus手套 (主端)                         天轶机器人 (从端)
─────────────────────────                        ─────────────────

[工控机] fast_sync ───────────── ZMQ ────────────────┐
                                                     │
[笔记本] SharpaManusClient                           │
   │                                                 │
  ZMQ                                                │
   ↓                                                 │
[笔记本] retargeting_manus                           │
   │                                                 │
  ZMQ                                                │
   ↓                                                 ↓
[笔记本] xtele --zmqpub manus ─ ZMQ ─────→ [机器人] xrocs data_collect
                                                     │
                                                     ├─ ROS2: /joint_states_flex_freq
                                                     ↓
                                               [freq_change]
                                                     │ bodyctrl_msgs
                                                     ↓
                                               [bodyctrl]
                                                     │ EtherCAT / CAN
                                                     ↓
                                                [机器人硬件]

[录制] xrocs data_collect ←── 关节60Hz + 相机30Hz + 力100Hz → HDF5
```

同构臂和手套数据分开传输, xrocs 通过 ZMQ 同时接收两路数据后汇总处理。

---

## 4. 操作流程

### 4.1 前置

- **笔记本有线 IP 设为 `192.168.41.5`，掩码 `255.255.255.0`**
- 三台机器 192.168.41.x 互通，笔记本能 ping 通 .1 (机器人) 和 .100 (工控机)
- 机器人开机后一分钟内 ping 不通，重启机器人再试
- 工控机已配置开机自启动 (systemd `xtele-monitor.service`), 无需手动操作
- 如需手动启动/重启同构臂数据发布:
  ```bash
  sudo systemctl restart xtele-monitor    # 重启 fast_sync
  systemctl status xtele-monitor          # 查看状态
  journalctl -u xtele-monitor -f          # 实时日志
  ```
- 验证工控机 ZMQ 已就绪: `curl http://192.168.41.100:8000` (关节 REST API)

### 4.2 启动步骤

> 2026-07-19 朱良超进行了更新

- 步骤 0 ─ 网络检查，在笔记本上本地运行:

```
  ping 192.168.41.1      # 机器人 (一分钟内不通则重启机器人)
  ping 192.168.41.100    # 工控机
```

- 步骤 1 ─ 机器人: 手动启动 body_control（绕过自检，优化掉遥控器）

```bash
ssh ubuntu@192.168.41.1   # 密码: 123
sudo systemctl stop proc_manager.service
# 遥操时灵巧手插着，enable_hands 保持 true（默认），无需改配置
cd /home/ubuntu/ros2ws
source install/setup.bash
ros2 launch body_control body.launch.py
```

- 步骤 2 ─ 笔记本: 启动 Manus 手套

> → 手套动捕原始数据 → ZMQ PUB

```
cd ~/dev/manuspro/SharpaManusLinuxClient
sudo ./SharpaManusClient.out
```

- 步骤 3 ─ 笔记本: 启动手部重定向

> → ZMQ SUB (动捕) → 优化求解 → ZMQ PUB (HA4手部关节角)

```
cd ~/dev/manuspro/retargeting_alg
conda activate sharpa_retarget
python3 retargeting_manus_demo_multiprocess.py -wave
```

- 步骤 4 ─ 笔记本: 启动 `xtele` 发布手套数据

> → ZMQ SUB ← 本地 (手) → tcp://0.0.0.0:7015

```
conda activate eai_env
xhumanoid-xtele --zmqpub manus
```

- 步骤 5 ─ 机器人: 启动力位混合控制

> 1. 启动 `freq_change_node` 节点
> 2. 其输入（订阅）是 `/joint_states_flex_freq` 话题( `sensor_msgs/JointState` 类型，同构臂14维关节目标（位置+速度），**来自 `xrocs` ，关键输入**)和 `arm/status` 话题( `bodyctrl_msgs/MotorStatusMsg` 类型)
> 3. 输出是`/arm/cmd_ctrl` 、`/arm/cmd_pos` 、`/arm/cmd_vel` ，**仅能控制手臂**

```
ssh ubuntu@192.168.41.1   # 密码: 123
sudo su                   # 密码: 123
export ROS_DOMAIN_ID=0
source nk2_ws/install/setup.bash
ros2 launch freq_change freq_change.launch.py
```

- 步骤 6 ─ Orin: 启动相机

```
ssh nvidia@192.168.41.2   # 密码: nvidia
source /opt/ros/humble/setup.bash
export ROS_DOMAIN_ID=0
source /home/nvidia/orbbec_camera_ros2/install/setup.bash
ros2 launch orbbec_camera gemini_330_series.launch.py \
  color_width:=640 color_height:=480 \
  depth_width:=640 depth_height:=480 \
  color_fps:=30 depth_fps:=30
```

- 步骤 7 ─ 机器人: 启动数据采集

> 1. 启动 `xrocs_shared_ros2_node_d3e122` 数采节点
> 2. 输入（订阅）
>
> | 话题                                 | 消息类型                       | 说明                 |
> | ------------------------------------ | ------------------------------ | -------------------- |
> | `/arm/status`                        | `bodyctrl_msgs/MotorStatusMsg` | 手臂状态反馈         |
> | `/head/status`                       | `bodyctrl_msgs/MotorStatusMsg` | 头部状态反馈         |
> | `/inspire_hand/state/left_hand`      | `sensor_msgs/JointState`       | 左手灵巧手状态       |
> | `/inspire_hand/state/right_hand`     | `sensor_msgs/JointState`       | 右手灵巧手状态       |
> | `/camera/color/image_raw/compressed` | `sensor_msgs/CompressedImage`  | 彩色相机图像（压缩） |
> | `/camera/depth/image_raw`            | `sensor_msgs/Image`            | 深度图像             |
>
> 3. 输出（发布）
>
> | 话题                            | 消息类型                            | 说明                                  |
> | ------------------------------- | ----------------------------------- | ------------------------------------- |
> | `/joint_states_flex_freq`       | `sensor_msgs/JointState`            | **给 freq_change 的输入**             |
> | `/arm/cmd_ctrl`                 | `bodyctrl_msgs/CmdMotorCtrl`        | 双臂力位混合控制（与freq_change竞争） |
> | `/arm/cmd_pos`                  | `bodyctrl_msgs/CmdSetMotorPosition` | 双臂位置控制                          |
> | `/arm/cmd_vel`                  | `bodyctrl_msgs/CmdSetMotorSpeed`    | 双臂速度控制                          |
> | `/head/cmd_pos`                 | `bodyctrl_msgs/CmdSetMotorPosition` | 头部位置控制                          |
> | `/leg/cmd_pos`                  | `bodyctrl_msgs/CmdSetMotorPosition` | 腿部位置控制                          |
> | `/inspire_hand/ctrl/left_hand`  | `sensor_msgs/JointState`            | 左手灵巧手控制                        |
> | `/inspire_hand/ctrl/right_hand` | `sensor_msgs/JointState`            | 右手灵巧手控制                        |
>
> 4. 注意到这个节点有对机器人各个部位的控制，包括手臂，可能存在抢占问题；
> 5. 同时，可以看到其订阅的话题均是机器人的硬件状态而没有输入（manus手套和同构臂），合理推测该节点是通过zmq直接读取的数据然后进行的处理

```
ssh -X ubuntu@192.168.41.1   # 密码: 123
cd ~/eai/syseai
source /opt/ros/humble/setup.bash
export ROS_DOMAIN_ID=0
uv run xhumanoid-xrocs --mode data_collect
→ 录制关节+相机+力传感器 → HDF5
```

- 步骤 7 ─ 机器人: 修改数采配置 (按需)

```
ssh ubuntu@192.168.41.1   # 密码: 123
nano ~/Documents/configuration.toml
```

### 4.3 机器人数采配置

```
路径: ~/Documents/configuration.toml

[basic]
tele_agent_type = "ServoTeleCore"     # 遥操模式
control_rate_hz = 100                 # 控制频率 100Hz
enable_hybrid_controller = true       # 混合控制

[data_collect]
save_type = "hdf5"
save_path = "~/Data/sim_data"
robot_state_save_rate_hz = 60         # 关节状态 60Hz
camera_state_save_rate_hz = 30        # 相机 30Hz
```

### 4.4 笔记本 xtele 配置 (换手修改维度)

```
路径: ~/.config/xhumanoid/xtele/default.toml

[equipments.manus_glove]
is_mock = false
is_zmq = false
manus_ip = "10.11.67.191"   # 手套 IP (仅 is_zmq=true 时生效)
manus_port = 7015            # 手套端口
output_degree = 6            # 输出维度 (换手时修改此值)

# 打开配置: gedit ~/.config/xhumanoid/xtele/default.toml
```

### 4.5 机器人 ment 手控制频率配置

```
路径: inspire_sdk/src/driver/config/ros2_controller_config_rh5dg2.yaml

device_nodes:
  - device: hand_left
    update_rate: 50              # ← 左手控制/发布频率 (Hz)
  - device: hand_right
    update_rate: 50              # ← 右手控制/发布频率 (Hz)

# xrocs 兼容配置 (topic 名不同):
# inspire_sdk/src/driver/config/ros2_controller_config_rh5dg2_xrocs.yaml
#   update_rate: 30 (xrocs 模式下较低频率)
```

---

## 5. 关键软件

### xtele SDK (遥操)

```
版本: pip 0.0.8 / whl 2.4.8
位置: 笔记本 eai_env + 工控机 pip

模块:
  core/              标定、配置管理、状态获取、遥控模式
  equipment/         硬件驱动 (达妙电机/CAN/舵机/手柄/手套/动捕/踏板/IMU)
  scripts/fast_sync/ 同构臂快速同步 (工控机主循环)
  station/           工位配置 (tienkung, mock, Franka, UR)
  examples/          示例 (力反馈、重力补偿、轨迹录制)
```

### fast_sync (工控机主循环)

```
源码: xtele/scripts/fast_sync/fast_sync.py (Cython编译)
配置: fast_sync_config.toml
      robot_type = 'tienkung'
      hand_type = 'inspire3'

核心类:
  FastSync           主控: initialize → run(主循环) → close
  PostTeleAgent      数据融合: 手臂+手+头+腰+腿 → 统一控制指令
  CmdPubServer       ZMQ PUB: 控制指令
  JoyPubServer       ZMQ PUB: 手柄状态
  LocalDataPubServer ZMQ PUB: 同构臂原始数据
  RobotStatusClient  ZMQ SUB: 机器人状态 (错误/电流安全)
  SyncStatusClient   ZMQ PUB: 同步状态码
  WebStatusServer    HTTP: WebUI 在线状态

PostTeleAgent._refresh_ctrl_cmde():
  _refresh_arm       手臂 (同构臂 CAN)
  _refresh_hand      手   (因时灵巧手)
  _refresh_head      头
  _refresh_waist     腰
  _refresh_leg       腿 + 摇杆→速度映射
  _refresh_current_and_power  电流+功率

PostTeleAgent.register_button():  20个手柄回调
  按钮: Left_X/Y/Z, Right_A/B/C
  事件: short(短按), joystick_hold(摇杆长推), combo(组合键)
```

### xrocs SDK (控制)

```
版本: 3.1.6.1
位置: 机器人 /home/ubuntu/eai/syseai/

API: ARobot / ACamera / AHand / AStation
CLI: xhumanoid-xrocs --mode data_collect
```

### body_control (全身控制器)

```
位置: /opt/PARTITIONS/entry/ros2ws/install/body_control/
类型: ROS2 Component (C++)

硬件驱动:
  libsoem.so              EtherCAT 主站 (关节电机)
  libcontrolcan.so         CAN 总线
  libdev_inspire_hand.so   因时灵巧手 3
  libdev_sri_6dof.so       SRI 六维力传感器
  libdev_motor_zeroerr.so  ZeroErr 电机

消息: bodyctrl_msgs (53个, 含 CmdMotorCtrl/SetAngle/GetStatus/PlanEefLine/...)
```

---

## 6. 协议栈

```
操纵层    操作员 → 同构臂(物理) + Manus手套(物理) + 手柄
────────
采集层    CAN (同构臂编码器) + USB (手套动捕)
────────
传输层    ZMQ (工控机/笔记本 → 机器人 xrocs) + ROS2 DDS (机器人内部/Orin相机)
────────
转发层    xtele (笔记本): Manus→HA4 手部关节角 → ZMQ PUB tcp://0.0.0.0:7015
────────
融合/数采层 xrocs (机器人): 读取主端ZMQ数据 + 机器人状态/相机 → 发布控制话题并录制
────────
桥接层    freq_change (机器人): /joint_states_flex_freq → bodyctrl 手臂控制格式
────────
执行层    bodyctrl (机器人): 指令 → EtherCAT/CAN → 电机
────────
录制层    xrocs data_collect (机器人): 关节+相机+力 → HDF5
```

---

## 7. 数采录制内容

| 数据 | 频率 | 来源 |
|------|------|------|
| 全身关节角度 | 60Hz | bodyctrl |
| 同构臂主端关节角 | 60Hz | fast_sync → ZMQ → xrocs |
| 六维力传感器 | 100Hz | SRI (bodyctrl CAN) |
| RGB 图像 | 30Hz | Orbbec Gemini 330 (Orin, 头部) |
| Depth 图像 | 30Hz | Orbbec Gemini 330 (Orin, 头部) |
| 腕部相机 | — | **尚未接入** |
| 手套手指关节角 | — | retargeting_manus → xtele ZMQ发布 → xrocs |

存储: HDF5 → ~/Data/sim_data/

---

## 8. 机器人硬件速查

```
CPU:  Intel i7-1355U, 15GB RAM, 228GB NVMe
ROS2: Humble, rmw_fastrtps_cpp, Domain ID 0

关节:
  左臂 7DOF   shoulder_pitch → shoulder_roll → shoulder_yaw
              → elbow_pitch → elbow_yaw → wrist_pitch → wrist_roll
  右臂 7DOF   同上
  灵巧手 ×2   Inspire Hand 3 (CAN)
  腰 2DOF     pitch, yaw
  头 3DOF     yaw, pitch, roll
  腿 2DOF     pitch ×2

传感器:
  六维力 ×2   SRI (CAN, 100Hz)
  关节编码器   EtherCAT (400Hz)
  相机         Orbbec Gemini 330 (1280×720@30Hz, 在Orin上)

U2C (USB-to-CAN):
  31F10005E45 → 头/腰/腿
  31F10005E44 → 右臂
  31F10005E40 → 左臂
  31F10005C57 → 手/六维力
```

---

---

## 附录: ZMQ 端口详情

### 工控机 192.168.41.100

#### 开机自启动 (systemd)

| 服务 | 启动脚本 | 作用 | 状态 |
|------|----------|------|:--:|
| `xtele-monitor` | `~/dev/sysEAI/start_xtele.sh` → `fast_sync.py` | 读同构臂CAN → ZMQ发布 | auto-restart |
| `tele_manage` | `/opt/tele_manage/run_tele_manage.sh` | C++ 守护, 远程管理 | running |
| `tele-cockpit-admin` | `~/dev/sysEAI/x-humanoid/.../tele-cockpit-admin.sh` | Web 管理后台 | running |

**xtele-monitor.service 详情:**
```ini
# /etc/systemd/system/xtele-monitor.service
[Service]
Type=simple
User=eai
ExecStart=/bin/bash /home/eai/dev/sysEAI/start_xtele.sh
Restart=always
RestartSec=3
```
启动流程: `配置 can0/can1 → 查找 FTDI 串口 → python3 fast_sync.py → FastSync().run()`

#### ZMQ 端口 (fast_sync)

| 端口 | 方向 | 类 | 内容 |
|------|------|-----|------|
| 5001 | PUB | CmdPubServer | 融合后控制指令 |
| 5002 | PUB | JoyPubServer | 手柄按钮/摇杆/扳机 |
| 5003 | PUB | LocalDataPubServer | 同构臂原始数据 |
| 6000 | PUB | SyncStatusClient | 同步状态码 |
| 6001 | SUB | RobotStatusClient | 机器人状态 |

#### ZMQ/HTTP 端口 (tele_manage, C++ 守护)

| 端口 | 方向 | 内容 |
|------|------|------|
| 5000 | ← 收 | 外部控制命令 |
| 5001 | SUB | 订阅 fast_sync 同构臂状态 |
| 5002 | SUB | 订阅 fast_sync 手柄状态 |
| 6000 | ← 收 | 外部控制命令 |
| 6001 | PUB | 机器人状态 (供外部订阅) |
| **7000** | HTTP | QuickRun (`http://192.168.41.100:7000`) |
| **8000** | HTTP | 关节状态 API (`http://192.168.41.100:8000`) |

---

### 笔记本 192.168.41.5

| 端口 | 方向 | 进程 | 内容 |
|------|------|------|------|
| 2044 | PUB | SharpaManusClient | 手套动捕 protobuf |
| 2044 | SUB | retargeting_manus | 订阅手套动捕 |
| 6668 | PUB | retargeting_manus | HA4 手部关节角 |

笔记本 ZMQ 链路: SharpaManusClient → PUB :2044 → retargeting_manus SUB :2044 → PUB :6668 → xtele SUB :6668 → ZMQ PUB → 机器人 xrocs :7015
