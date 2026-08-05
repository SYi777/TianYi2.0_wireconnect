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

bodyctrl + XARM(关节) + joint_relay + bridge + RSP + move_group
