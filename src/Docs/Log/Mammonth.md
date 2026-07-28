# 猛犸象 — 天轶2.0 Pro 系统架构与开发指南

> author: 景宇航 email: jyh1621839418@163.com
> 最后更新: 2026-07-24

---

## 一、机器总览

### 1.1 硬件配置

天轶2.0 Pro（TG2.0-Pro），双足轮式人形机器人，35 自由度，软件版本 v2.0.9。

| 项目 | 值 |
|------|-----|
| CPU | Intel i7-1355U, 4核8线程 |
| 内存 | 15 GB |
| 磁盘 | 228 GB NVMe |
| 电池 | 48V 15Ah 三元锂 |

### 1.2 关节参数

| 部位 | 自由度 | 电机 ID |
|------|:--:|------|
| 头 | Roll / Pitch / Yaw | 1-3 |
| 左臂 | 肩俯仰→肩翻滚→肩偏航→肘俯仰→肘偏航→腕俯仰→腕翻滚 | 11-17 |
| 右臂 | 同上 | 21-27 |
| 腰 | Yaw / Pitch | 31-32 |
| 腿 | Hip Pitch / Knee Pitch | 51-52 |
| 灵巧手 ×2 | 6 指/手 | Inspire Hand 3 (CAN) |

**坐标系：** X(Roll)=前, Y(Pitch)=左, Z(Yaw)=上

**关键限位：** 肩俯仰 ±170° / 肩翻滚(左) -15°~+150° / 肘俯仰 -150°~+15° / 腕俯仰 -45°~+60° / 腕翻滚(左) -95°~+75° / 头偏航 ±90° / 头俯仰 ±25°

### 1.3 双主机架构

| 主机 | IP | 用户名 | 职责 |
|------|------|------|------|
| x86 | 192.168.41.1 | ubuntu | body_control + XARM 控制框架 |
| Orin AGX | 192.168.41.2 | nvidia | Gemini 330 相机、语音、模型推理 |

两台主机通过 DDS 共享 ROS2 系统。关节通讯 400Hz (EtherCAT)，灵巧手 100Hz (CAN)。

### 1.4 网络拓扑

| IP | 角色 |
|----|------|
| 192.168.41.1 | 机器人 x86 |
| 192.168.41.2 | 机器人 Orin |
| 192.168.41.5 | 笔记本（调试） |
| 192.168.41.100 | 工控机（遥操数采用） |

笔记本直连机器人调试以太网口：手动设 IP `192.168.41.5`，掩码 `255.255.255.0`，ping `.1` 和 `.2` 验证。

### 1.5 DDS 白名单配置

三端 DDS Profile 的 `<interfaceWhiteList>` 都必须包含所有设备 IP：

- 机器人 x86: `/home/ubuntu/data/param/dds_profile.xml` + `/home/ubuntu/ros2ws/install/body_control/share/body_control/cfg/fastdds_profile.xml`
- Orin: `/home/nvidia/data/param/dds_profile.xml`
- 笔记本: `data/param/dds_profile.xml`

`ROS_DOMAIN_ID=0`（所有设备一致），默认禁止 WiFi DDS，必须用有线。

验证：`ros2 topic list` 能看见机器人 `/joint_states` 即成功。

---

## 二、机器人控制

### 2.1 开机自检

1. 按下总开关 → 短按开机键 → 急停按钮顺时针弹出
2. 等待开机音效结束，整机状态灯变为蓝绿缓慢呼吸
3. F 拨杆中间挡位下，按遥控器 **A 键** 启动自检
4. 自检过程：蓝绿急促呼吸 + 音效
5. 自检成功：蓝绿常亮，进入 Ready 状态
6. 自检失败：红灯闪烁，20 秒后自动重试

未自检的机器人无法使用 ROS2 控制。

### 2.2 跳过自检（手动启动 body_control）

遥控器自检失败、没插遥控器、或需要灵活配置时：

```bash
ssh ubuntu@192.168.41.1   # 密码: 123
sudo su
sudo systemctl stop proc_manager.service
```

**手部使能开关：** 编辑 `/home/ubuntu/data/param/u2c_sn.yaml`，改 `enable_hands` 字段：

```yaml
# enable_hands: false   # 没插灵巧手时关掉，否则 body_control 不 Ready
# enable_hands: true    # 插了灵巧手时打开
```

然后启动：

```bash
cd /home/ubuntu/ros2ws
source install/setup.bash
ros2 launch body_control body.launch.py
```

> 另一处手部配置 `/home/ubuntu/ros2ws/install/body_control/share/body_control/param/inspire_hands.yaml`（`enable: true/false`），旧版机器也在那里改。

### 2.3 控制体系 —— 双系统并存

机器人上有两套并行的控制体系，共享同一组电机硬件。同一时间只能一个控制器占用硬件。

**底层 — body_control：**
- `/arm/cmd_pos` `/head/cmd_pos` `/waist/cmd_pos` `/leg/cmd_pos`
- 直接关节控制，无 IK，无避碰

**上层 — XARM 框架 (`/home/ubuntu/XARM`)：**
- `/jointspace_commands_L/R` → 关节空间 + Ruckig 平滑
- `/endposetarget_L/R` → 笛卡尔末端 + IK + QP 避碰
- `/joint_space_control` (Service) → MoveIt 关节多路点规划
- `/dual_arm_waypoints` (Service) → MoveIt 笛卡尔多路点规划

XARM 通过 ros2_control 管理。EAIHardware 在 250Hz 下持续写 `/arm/cmd_pos` 保持当前位置，外部 `--once` 指令会被覆盖。需切 `empty_controller` 释放控制权。

### 2.4 body_control 底层控制

| 部位 | Topic | 消息类型 | 电机 ID |
|------|-------|---------|--------|
| 头 | `/head/cmd_pos` | CmdSetMotorPosition | 1-3 |
| 手臂 | `/arm/cmd_pos` | CmdSetMotorPosition | 11-17(左) 21-27(右) |
| 腰 | `/waist/cmd_pos` | CmdSetMotorPosition | 31-32 |
| 腿 | `/leg/cmd_pos` | CmdSetMotorPosition | 51-52 |

CmdSetMotorPosition 字段: `name(uint16)` `pos(rad)` `spd(RPM)` `cur(A)`

```bash
# 左腕(17)转 0.1 rad
ros2 topic pub --once /arm/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header:{stamp:{sec:0,nanosec:0},frame_id:''}, \
    cmds:[{name:17,pos:0.1,spd:2.0,cur:5.0}]}"
```

**额定电流参考：**

| 部位 | 电机 ID | 额定电流 |
|------|--------|:--:|
| 头 | 1-3 | 5A |
| 肩俯仰 | 11/21 | 35A |
| 肩翻滚 | 12/22 | 23A |
| 肩偏航/肘 | 13-15 | 8A |
| 腕 | 16-17 | 5A |
| 腰/腿 | 31-32/51-52 | ~30A |

错误码: `33072`=设备掉线, `33073`=关节超限, `1`=过温, `2`=过流, `5`=堵转, `8`=编码器错误

### 2.5 XARM 上层框架

**启动（机器人侧，干净终端，不要 source ros2ws，否则 bodyctrl_msgs 符号冲突导致崩溃）：**
```bash
source /home/ubuntu/XARM/install/setup.bash
ros2 launch tianyi2_bringup tianyi2.launch.py hardware:=real
```

**笔记本环境：**
```bash
source /opt/ros/humble/setup.bash
source ~/WireConnect_ws/ROS/robot_pkgs/nk2_ws/install/setup.bash   # bodyctrl_msgs
source ~/WireConnect_ws/ROS/robot_pkgs/XARM/install/setup.bash    # eai_manipulator_msgs
```

#### 硬件使能与模式（使用手臂前必做）
```bash
# 设位置模式（mode=3 高刚度位置环，推荐）
ros2 service call /EAIHardware/set_arm_mode eai_manipulator_msgs/srv/Mode "{mode: 3}"
# 硬件上电
ros2 service call /EAIHardware/set_arm_enable std_srvs/srv/SetBool "data: true"
```

mode: 0=柔顺, 1=速度环(不推荐), 2=重力补偿, **3=位置环(推荐)**

#### 关节空间控制器

| 控制器 | Topic | 数据 | 避碰 |
|--------|-------|------|:--:|
| jointspace_arm_L_controller | /jointspace_commands_L | Float64[7] | ❌ |
| jointspace_arm_R_controller | /jointspace_commands_R | Float64[7] | ❌ |
| jointspace_ruckig_qp_controller | /jointspace_commands_Dual | Float64[14] | ✅ |

```bash
ros2 control switch_controllers --activate jointspace_arm_L_controller
ros2 topic pub --once /jointspace_commands_L std_msgs/msg/Float64MultiArray \
  "data: [0.0, 1.18, 0.0, -1.3, 0.0, -0.13, 0.18]"
```

#### 笛卡尔空间控制器（推荐比赛用）

ArmTargetPose 字段: `target`(Pose), `from_frame`(建议 `waist_yaw_link`), `to_frame`(`left_tcp_link`/`right_tcp_link`), `offset_x/y/z`(m)

```bash
ros2 control switch_controllers --activate endpose_single_arm_qp_L_controller

ros2 topic pub --once /endposetarget_L eai_manipulator_msgs/msg/ArmTargetPose \
  '{header:{frame_id:"waist_yaw_link"}, target:{position:{x:0.35,y:0.20,z:-0.10}, \
    orientation:{w:1.0}}, from_frame:"waist_yaw_link", to_frame:"left_tcp_link", \
    offset_x:0,offset_y:0,offset_z:0}'
```

> 注意：目标位姿须在 `dis_err_bound`(默认 0.2m) 和 `ori_err_bound`(默认 1.0rad) 范围内。

#### MoveIt Service（笔记本通过 DDS 调机器人上的 Service）

```bash
# 关节空间多路点
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

# 笛卡尔空间多路点
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

group: `left_arm` / `right_arm` / `dual_arm` | mode: `plan` / `execute` / `plan_and_execute`

#### 控制器切换

```bash
ros2 control list_controllers
ros2 control switch_controllers --deactivate old_ctrl --activate new_ctrl
ros2 control auto_switch_mode --enable   # 自动切换
```

**empty_controller：** 声明接口但不往 `/arm/cmd_pos` 写任何数据。激活后释放控制权，外部直发指令不会被 EAIHardware 覆盖。

#### EAIHardware 覆写规则（真机验证）

| 状态 | /arm/cmd_pos 行为 |
|------|------|
| empty_controller active | 不受干扰，自由发指令 |
| 其他 controller active + 无指令 | 250Hz hold 当前位置（死锁） |
| 其他 controller active + 有指令 | 正常执行 |

### 2.6 控制链路决策

```
需要避碰     → XARM endpose_qp 或 ruckig_qp
需要笛卡尔   → XARM endpose_qp 或 /dual_arm_waypoints
需要多路点   → XARM /dual_arm_waypoints
单关节控制   → body_control /arm/cmd_pos（先切 empty_controller）
头部控制     → /head/cmd_pos（不受 XARM 影响，始终可用）
比赛任务     → 感知算 pose → XARM endpose_qp → 力监控 → 手松
```

### 2.7 灵巧手控制

Inspire Hand 3，CAN 总线。手指 ID: 1=小指 2=无名指 3=中指 4=食指 5=拇指弯曲 6=拇指旋转

**所有值均为百分比（0~1），不是弧度。**

| 接口 | Topic / Service |
|------|------|
| 状态 | `/inspire_hand/state/{left,right}_hand` (JointState position=[0~1]*6) |
| 控制 | `/inspire_hand/ctrl/{left,right}_hand` (JointState position=[0~1]*6) |
| 角度 | `/inspire_hand/set_angle_flexible/{left,right}_hand` (Service) |
| 力矩 | `/inspire_hand/set_force/{left,right}_hand` (Service, 0→0g, 1→1000g) |
| 速度 | `/inspire_hand/set_speed/{left,right}_hand` (Service) |
| 清错 | `/inspire_hand/set_clear_error/{left,right}_hand` (Service) |

```bash
# 左手全开
ros2 topic pub --once /inspire_hand/ctrl/left_hand sensor_msgs/msg/JointState \
  '{name: ["1","2","3","4","5","6"], position: [0.5, 0.5, 0.5, 0.5, 0.5, 0.5]}'
```

> **手部话题无数据/无法控制？** 说明 body_control 的手部驱动没跑。检查 `/home/ubuntu/data/param/u2c_sn.yaml` 里 `enable_hands: true`，然后重启 body_control。参考 §2.2。

### 2.8 传感器总览

| 传感器 | Topic | 类型 | 频率 |
|--------|-------|------|:--:|
| 全身关节 | `/joint_states` | JointState | — |
| 头部状态 | `/head/status` | MotorStatusMsg | — |
| 手臂状态 | `/arm/status` | MotorStatusMsg | — |
| 腰部状态 | `/waist/status` | MotorStatusMsg | — |
| 腿部状态 | `/leg/status` | MotorStatusMsg | — |
| 左/右六维力 | `/arm_6dof_{left,right}` | WrenchStamped | 100Hz |
| 彩色 | `/ob_camera_head/color/image_raw` | BGR8 1280×720 | 30Hz |
| 彩色压缩 | `/ob_camera_head/color/image_raw/compressed` | JPEG ~150KB | 30Hz |
| 深度 | `/ob_camera_head/depth/image_raw` | 16UC1 mm | 30Hz |
| 内参 | `/ob_camera_head/color/camera_info` | CameraInfo | — |
| 电池 | `/power/battery/status` | PowerBatteryStatus | 1Hz |
| 急停 | `/power/board/key_status` | PowerBoardKeyStatus | 1Hz |
| 告警 | `/manipulator/warn_and_error_info` | WarnAndErrorInfo | — |

关键告警码: `300100` warn=目标超跟踪限, `600100` error=优化不可行, `600101/2`=关节超限, `600120/30`=frame 错误

---

## 三、遥操与数采

### 3.1 架构

三机协同：工控机读同构臂 CAN → ZMQ / 笔记本读手套 USB → ZMQ → 机器人录制 HDF5。

```
[工控机 192.168.41.100] 无 ROS2
  同构臂 TS1P ─CAN→ fast_sync ─ZMQ PUB→ :5001(控制) :5002(手柄) :5003(原始数据)

[笔记本 192.168.41.5] 有 ROS2, eai_env
  手套USB → SharpaManusClient ─ZMQ:2044→ retargeting_manus ─ZMQ:6668→ xtele
  xtele ZMQ SUB ← 工控机手臂数据
  xtele ROS2/DDS → 机器人

[机器人 192.168.41.1]
  DDS → freq_change(力位混合) → bodyctrl → EtherCAT/CAN → 电机
  data_collect → HDF5 (关节60Hz + 相机30Hz + 六维力100Hz)
```

同构臂和手套数据分开传输，在机器人端通过 ZMQ 同时收两路数据后汇总。

### 3.2 完整启动流程

**前置：** 笔记本有线 IP 设为 `192.168.41.5/24`，三机能互 ping。

| 步骤 | 机器 | 操作 |
|:--:|------|------|
| 0 | 笔记本 | `ping 192.168.41.1` + `ping 192.168.41.100` |
| 1 | 机器人 | 停 proc_manager → 手动启 body_control（或用遥控 A 自检） |
| 2 | 笔记本 | `sudo ./SharpaManusClient.out`（手套动捕 → ZMQ :2044） |
| 3 | 笔记本 | `conda activate sharpa_retarget && python3 retargeting_manus_demo_multiprocess.py -wave` |
| 4 | 笔记本 | `conda activate eai_env && xhumanoid-xtele --zmqpub manus` |
| 5 | 机器人 | `ros2 launch freq_change freq_change.launch.py`（力位混合控制） |
| 6 | Orin | 启动 orbbec_camera (640×480@30Hz) |
| 7 | 机器人 | 启动数采录制（HDF5） |

**工控机验证：** `curl http://192.168.41.100:8000`（关节 REST API）

### 3.3 换手操作（改三处文件）

| # | 机器 | 文件 | 修改内容 |
|---|------|------|------|
| 1 | 笔记本+机器人 | `~/.config/xhumanoid/xtele/default.toml` | `output_degree` 改数据维度 |
| 2 | 机器人 | `~/Documents/configuration.toml` | `hand_type` 改手型号 |
| 3 | 机器人 | `~/inspire_hand/start_rh5dg2_both.sh` | 单独启动因时手 |

```bash
# 机器人端启动 13 自由度因时手
ssh ubuntu@192.168.41.1
cd ~/inspire_hand
./start_rh5dg2_both.sh
```

### 3.4 数采录制

| 数据 | 频率 | 来源 |
|------|:--:|------|
| 全身关节角度 | 60Hz | bodyctrl |
| 同构臂主端关节角 | 60Hz | fast_sync → ZMQ |
| 六维力 | 100Hz | SRI (CAN) |
| RGB / Depth | 30Hz | Gemini 330 (Orin) |
| 手部关节角 | — | retargeting → xtele |

存储: HDF5 → `~/Data/sim_data/`

### 3.5 ZMQ 端口

**工控机 (192.168.41.100)：** 5001(控制指令) / 5002(手柄) / 5003(原始数据) / 8000 HTTP(关节 API)

**笔记本 (192.168.41.5)：** 2044 PUB/SUB(手套动捕 protobuf) / 6668 PUB(HA4 手部关节角)

---

## 四、遥操优化方案

当前问题：多设备经交换机 ZMQ/WebSocket 中转，链路长，设备多。

**优化方向：** 手套接收器 + dev 直接装在机器人上，ZMQ 自回环。同构臂仍走工控机 CAN → ZMQ → 机器人。

```
[机器人] 手套接收器(USB) → ZMQ 自回环 → DDS → freq_change → bodyctrl
[工控机] 同构臂(CAN) → ZMQ → 机器人
```

---

## 五、自主操作（线缆连接专项赛）

### 5.1 赛题

工作台 120×80×75cm，白色插排 4~5 个 USB-A 母口朝上。线缆 USB-A 公头 ↔ Type-C，整齐排列，短而硬。任务：抓 USB-A → 插入母口 → 循环。只插不拔，5 分钟，全自主权重 1.0。

### 5.2 视觉识别链路

相机: Orbbec Gemini 330, 1280×720@30Hz, 头部安装
内参: fx≈689, fy≈689, cx≈644, cy≈360
模型: YOLOv8n (3.2M 参数), 单类 `usb_a_port`, mAP50=0.87, P=0.89, GPU 3060 ~5ms/帧

```
彩色压缩图(JPEG ~150KB) → YOLO 检测 → bbox + OBB 角度
                                         ↓
深度图(16UC1 mm) → 取 bbox 中心像素深度值 Z
                                         ↓
  3D 点 = [(u-cx)*Z/fx,  (v-cy)*Z/fy,  Z]   (相机坐标系)
                                         ↓
  TF: optical_frame → waist_yaw_link
                                         ↓
        腰坐标系 3D 坐标 → XARM 笛卡尔控制
```

> 用 `/image_raw/compressed` 替代原图（DDS 传输快 20 倍）。不用 cv_bridge（numpy 版本冲突），直接用 `np.frombuffer` + `cv2.imdecode`。

```bash
# 实时推理
python3 ~/WireConnect_ws/detect/scripts/detect_live.py
# 检测 + 深度反投影 + TF 变换 + RViz MarkerArray
python3 ~/WireConnect_ws/detect/scripts/detect_3d.py
# 采集图像
python3 ~/WireConnect_ws/detect/scripts/capture.py
```

### 5.3 控制执行链路

```
YOLO + 深度图 → USB 口在 waist_yaw_link 系下的 3D 坐标
  → /endposetarget_L → 手臂到位（笛卡尔 + QP 避碰）
  → 相对移动 dz=-0.03 垂直下插
  → /arm_6dof_left 六维力监控插入阻力
  → /inspire_hand/ctrl/left_hand 松手
  → 回到初始位姿，循环
```

---

## 附录 A：速查表

### A.1 电机 ID

```
头:   1=Roll    2=Pitch         3=Yaw
左臂: 11=肩俯仰  12=肩翻滚        13=肩偏航  14=肘俯仰
      15=肘偏航  16=腕俯仰        17=腕翻滚
右臂: 21-27 (同左臂)
腰:   31=Yaw    32=Pitch
腿:   51=Hip    52=Knee
手:   /inspire_hand/ctrl/{left,right}_hand  JointState position=[0~1]*6
```

### A.2 控制 Topic 速查

| 接口 | Topic | 消息类型 |
|------|-------|---------|
| 头/臂/腰/腿 | `/head\|arm\|waist\|leg/cmd_pos` | CmdSetMotorPosition |
| 手 | `/inspire_hand/ctrl/{left,right}_hand` | JointState (百分比) |
| XARM 左/右关节 | `/jointspace_commands_L/R` | Float64MultiArray[7] |
| XARM 双臂关节 | `/jointspace_commands_Dual` | Float64MultiArray[14] |
| XARM 左/右笛卡尔 | `/endposetarget_L/R` | ArmTargetPose |
| XARM 告警 | `/manipulator/warn_and_error_info` | WarnAndErrorInfo |

### A.3 Service 速查

| Service | 用途 |
|---------|------|
| `/EAIHardware/set_arm_mode` | mode: 0-3 |
| `/EAIHardware/set_arm_enable` | 手臂使能 |
| `/EAIHardware/set_all_enable` | 全身使能 |
| `/joint_space_control` | MoveIt 关节多路点 |
| `/dual_arm_waypoints` | MoveIt 笛卡尔多路点 |
| `/inspire_hand/set_angle_flexible/{left,right}_hand` | 手角度百分比 |
| `/inspire_hand/set_force/{left,right}_hand` | 手力矩百分比 |
| `/inspire_hand/set_clear_error/{left,right}_hand` | 手清错 |

### A.4 常用命令

```bash
# SSH
ssh ubuntu@192.168.41.1      # x86 密码 123
ssh nvidia@192.168.41.2      # Orin 密码 nvidia
ssh eai@192.168.41.100       # 工控机 密码 eai231102!

# 机器人进程
sudo systemctl stop proc_manager.service
sudo systemctl status proc_manager.service

# 相机（Orin）
sudo systemctl start orbbec_head.service

# DDS 验证
ros2 topic list | grep joint_states

# 工控机验证
curl http://192.168.41.100:8000

# 控制器管理
ros2 control list_controllers
ros2 control switch_controllers --activate <name>
ros2 control auto_switch_mode --enable

# RViz 看机器人（本机）
rviz2
# Add → RobotModel → Description Topic: /xarm_robot_description
```

### A.5 机器人关键路径

| 内容 | 路径 |
|------|------|
| ROS2 workspace | `/home/ubuntu/ros2ws` |
| XARM 框架 | `/home/ubuntu/XARM` |
| bodyctrl_msgs (新版) | `/home/ubuntu/nk2_ws` |
| 机器人配置 | `/home/ubuntu/Documents/configuration.toml` |
| DDS 配置 | `/home/ubuntu/data/param/dds_profile.xml` |
| 灵巧手 SDK | `/home/ubuntu/inspire_hand` |
| Bag 存储 | `/home/ubuntu/bags` |
| U2C 序列号 | `31F10005E45/E44/E40/C57` （头腰腿/右臂/左臂/手&力） |
