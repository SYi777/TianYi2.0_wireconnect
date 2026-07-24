# 灵巧手纳入 MoveIt 规划链 — 草稿纸

> 目标: 将 inspire 6-DOF 灵巧手集成到 MoveIt 规划管线，预设固定手势用于线缆夹取
> 硬件: 天轶2.0 Pro 双臂, 左右 inspire hand (6-DOF + 5 mimic), 31mm 法兰
> 基于: moveit_ws (双臂7-DOF规划已验证) → moveit_with_hand_ws
> 最后更新: 2026-07-22

---

## 1. 已知条件

### URDF 结构

```
left_tcp_link (腕部末端)
  └─ left_flange_joint (fixed) → left_flange_link (圆柱, Ø40mm × 31mm)
       └─ left_hand_to_tcp (fixed, rpy=3.14 0 -1.57) → L_base_link
            ├─ left_thumb_1 → thumb_2 → thumb_3(mimic) → thumb_4(mimic)
            ├─ left_index_1 → index_2(mimic ×1.1169)
            ├─ left_middle_1 → middle_2(mimic ×1.1169)
            ├─ left_ring_1 → ring_2(mimic ×1.1169)
            └─ left_little_1 → little_2(mimic ×1.1169)
```

- 右手为镜像结构
- 法兰长度参数: `flange_length` (xacro arg, 默认 0.031)
- 每手 11 个 link, 6 个独立旋转关节 + 5 个 mimic 关节

### 手部独立关节

| 关节 | 限位 (rad) | 轴 | 对应 SDK ID |
|------|-----------|-----|:--:|
| *_thumb_1 | [0, 1.246] | Z | 5 (拇指弯曲) |
| *_thumb_2 | [0, 0.48] | Z | 6 (拇指旋转) |
| *_index_1 | [0, 1.333] | Z | 4 (食指) |
| *_middle_1 | [0, 1.333] | Z | 3 (中指) |
| *_ring_1 | [0, 1.333] | Z | 2 (无名指) |
| *_little_1 | [0, 1.333] | Z | 1 (小指) |

### MoveIt 规划组

| 组名 | DOF | 类型 | 用途 |
|------|:--:|------|------|
| left_arm | 7 | chain (waist_yaw→left_tcp_link) | 左臂到达+姿态 |
| right_arm | 7 | chain (waist_yaw→right_tcp_link) | 右臂到达+姿态 |
| dual_arm | 14 | 子组联合 | 双臂同步规划 |
| **left_hand** | **6** | **joint list** | **左手手势** |
| **right_hand** | **6** | **joint list** | **右手手势** |
| head | 3 | joint list | 头部姿态 |

---

## 2. 进度总览

| 步骤 | 内容 | 状态 |
|------|------|:--:|
| 1 | URDF: 法兰 link (cylinder 31mm) | ✅ |
| 2 | 工作区: moveit_with_hand_ws 创建 | ✅ |
| 3 | SRDF: left_hand/right_hand 规划组 | ✅ |
| 4 | SRDF: 4 个 group_state (open/cable/usb/fist) | ✅ |
| 5 | SRDF: 法兰碰撞对 | ✅ |
| 6 | kinematics.yaml: 手部 KDL | ✅ |
| 7 | joint_limits.yaml: 手指限位 | ✅ |
| 8 | moveit_controllers.yaml: 手部控制器 | ✅ |
| 9 | initial_positions.yaml: 手指归零 | ✅ |
| 10 | ompl_planning.yaml: 手部规划配置 | ✅ |
| 11 | hand_gestures.yaml + Python 加载脚本 | ✅ |
| 12 | demo_with_hands.launch.py 启动文件 | ✅ |
| 13 | colcon build 编译验证 | ⬜ |
| 14 | RViz 可视化验证 | ⬜ |
| 15 | 手势真机标定 | ⬜ |

---

## 3. 技术要点

### 3.1 法兰实现

- 在 `install_left_hand` / `install_right_hand` 宏内部插入 `*_flange_link`
- 圆柱体: radius=0.02m, length=${flange_length}
- 关节链: `*_tcp_link` → `*_flange_joint`(fixed, xyz=0) → `*_flange_link` → `*_hand_to_tcp`(fixed, xyz="0 0 ${flange_length}") → `*_base_link`
- 命令行传参: `xacro ... flange_length:=0.031`

### 3.2 Mimic 关节处理

- MoveIt 不直接处理 mimic 关节，依赖 URDF 解析器自动传播 mimic 值
- 手部规划组只包含 6 个独立关节（_1 / thumb_2）
- mimic 关节（_2, _3, _4）的 joint limits 不需要在 joint_limits.yaml 中定义
- KDL IK 求解器会忽略非独立的 mimic 关节

### 3.3 手势预设

4 个预设，存储在 SRDF group_state 和 YAML 中：

| 手势 | thumb_1 | thumb_2 | index_1 | middle_1 | ring_1 | little_1 | 用途 |
|------|:---:|:---:|:---:|:---:|:---:|:---:|------|
| open | 0 | 0 | 0 | 0 | 0 | 0 | 全张开/复位 |
| cable_grasp | 0.50 | 0.19 | 0.53 | 0.53 | 0.53 | 0.53 | 抓线缆 (~40%) |
| usb_grasp | 0.75 | 0.29 | 0.80 | 0.80 | 0.80 | 0.80 | 抓USB-A头 (~60%) |
| fist | 1.246 | 0.48 | 1.333 | 1.333 | 1.333 | 1.333 | 握拳 (100%) |

> ⚠️ 数值为估算值，需在真手上验证安全范围

### 3.4 SDK 手指 ID 映射

```python
# gesture 数组顺序: [thumb_1, thumb_2, index_1, middle_1, ring_1, little_1]
# SDK 顺序:        [1=little, 2=ring, 3=middle, 4=index, 5=thumb_bend, 6=thumb_rotate]
# 转换见 hand_gestures.py: load_gesture_array()
```

### 3.5 碰撞矩阵

- 原有 807 对 disable_collisions 不变
- 新增 11 对法兰碰撞:
  - `_flange_link` ↔ `_tcp_link` (Adjacent)
  - `_flange_link` ↔ `_base_link` (Adjacent)
  - `_flange_link` ↔ `wrist_roll` (Never)
  - `_flange_link` ↔ `wrist_pitch` (Never)
  - `_flange_link` ↔ `elbow_pitch` (Never)
  - `left_flange_link` ↔ `right_flange_link` (Never)

---

## 4. 文件清单

| 文件 | 说明 |
|------|------|
| `urdf_ws/.../tianyi2.0_complete_with_hands.xacro` | 修改: 加入法兰 link + joint |
| `moveit_with_hand_ws/.../tianyi2.0_complete.srdf` | 修改: 加 hand group + state + collision |
| `moveit_with_hand_ws/.../kinematics.yaml` | 修改: 加 left_hand/right_hand KDL |
| `moveit_with_hand_ws/.../joint_limits.yaml` | 修改: 加 12 个手指关节 |
| `moveit_with_hand_ws/.../moveit_controllers.yaml` | 修改: 加 2 个手部控制器 |
| `moveit_with_hand_ws/.../initial_positions.yaml` | 修改: 加 12 个手指初始值 |
| `moveit_with_hand_ws/.../ompl_planning.yaml` | 修改: 加 left_hand/right_hand 规划 |
| `moveit_with_hand_ws/.../hand_gestures.yaml` | **新建**: 手势预设值 |
| `moveit_with_hand_ws/.../scripts/hand_gestures.py` | **新建**: Python 加载工具 |
| `moveit_with_hand_ws/.../launch/demo_with_hands.launch.py` | **新建**: RViz 启动文件 |

---

## 5. 下一步

### 5.1 编译 & 可视化验证
```bash
cd ~/WireConnect_ws/ROS/moveit_with_hand_ws
colcon build --symlink-install
source install/setup.bash
ros2 launch tianyi2_moveit_config demo_with_hands.launch.py
```
- [ ] 法兰圆柱在 RViz 中正确显示
- [ ] 手指关节可通过 MotionPlanning 面板拖动
- [ ] group_state (open/cable_grasp 等) 可正确切换
- [ ] 手臂规划时手部不参与（独立规划组）
- [ ] 无碰撞报警

### 5.2 真机手势标定
- [ ] 通过 inspire SDK 发送手势关节值，验证安全范围
- [ ] 根据实际抓取效果微调 YAML 数值
- [ ] 标定力控参数配合手势

### 5.3 视觉引导抓取集成
- [ ] 相机检测 USB 母口 6D 位姿 → XARM 笛卡尔控制手臂到位
- [ ] 到达目标后发送 cable_grasp/usb_grasp 手势
- [ ] 力传感器监控抓取力度
- [ ] 完整闭环: 感知 → 规划 → 手势 → 力反馈
