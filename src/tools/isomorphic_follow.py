#!/usr/bin/env python3
"""isomorphic_follow — 按键控制同构臂跟随机械臂。

用法:
    python3 isomorphic_follow.py

按键:
    f  = 左臂: 读取当前关节角 → 发给同构臂
    g  = 右臂: 读取当前关节角 → 发给同构臂
    s  = 双腕: 同时发左右臂
    q  = 退出

依赖: bodyctrl + XARM(关节) + joint_relay → /joint_states
"""

import json, math, os, sys, time, select, tty, termios, threading

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

# ── 配置 ──
ZMQ_HOST = "192.168.41.100"
ZMQ_SUB_PORT = 5003   # 同构臂 → 笔记本 (传感器数据)
ZMQ_PUB_PORT = 6003   # 笔记本 → 同构臂 (电机指令)

ARM_J_L = [
    "shoulder_pitch_l_joint", "shoulder_roll_l_joint",
    "shoulder_yaw_l_joint",  "elbow_pitch_l_joint",
    "elbow_yaw_l_joint",     "wrist_pitch_l_joint",
    "wrist_roll_l_joint",
]
ARM_J_R = [
    "shoulder_pitch_r_joint", "shoulder_roll_r_joint",
    "shoulder_yaw_r_joint",  "elbow_pitch_r_joint",
    "elbow_yaw_r_joint",     "wrist_pitch_r_joint",
    "wrist_roll_r_joint",
]


class JointReader(Node):
    def __init__(self):
        super().__init__("isomorphic_follow")
        self._left = None
        self._right = None
        self.create_subscription(JointState, "/joint_states", self._cb, 10)

    def _cb(self, msg):
        v = dict(zip(msg.name, msg.position))
        if all(n in v for n in ARM_J_L):
            self._left = [float(v[n]) for n in ARM_J_L]
        if all(n in v for n in ARM_J_R):
            self._right = [float(v[n]) for n in ARM_J_R]

    def get(self):
        return self._left, self._right


def main():
    rclpy.init()
    reader = JointReader()

    # 启动 ROS spin
    spin = threading.Thread(target=rclpy.spin, args=(reader,), daemon=True)
    spin.start()
    time.sleep(0.3)

    # ZMQ SUB — 监听同构臂数据
    ctx = zmq.Context()
    sub = ctx.socket(zmq.SUB)
    sub.setsockopt(zmq.CONFLATE, 1)
    sub.setsockopt(zmq.SUBSCRIBE, b"")
    sub.connect(f"tcp://{ZMQ_HOST}:{ZMQ_SUB_PORT}")
    sub.setsockopt(zmq.RCVTIMEO, 100)

    # ZMQ PUB — 给同构臂发指令 (TeleServe 等价)
    pub = ctx.socket(zmq.PUB)
    pub.connect(f"tcp://{ZMQ_HOST}:{ZMQ_PUB_PORT}")
    time.sleep(0.1)

    # 键盘
    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    tty.setcbreak(fd)

    print("━" * 50)
    print("🎮 同构臂遥操调试")
    print(f"   SUB ← {ZMQ_HOST}:{ZMQ_SUB_PORT} (同构臂传感器)")
    print(f"   PUB → {ZMQ_HOST}:{ZMQ_PUB_PORT} (同构臂电机指令)")
    print()
    print("  f = 左臂跟随  g = 右臂跟随  s = 双腕跟随")
    print("  1 = 张手      2 = 闭合")
    print("  q = 退出")
    print()
    print("  同构臂最新数据:")

    try:
        while rclpy.ok():
            # 显示同构臂数据
            try:
                while True:
                    raw = sub.recv(zmq.NOBLOCK)
                    try:
                        data = json.loads(raw.decode("utf-8"))
                        arm = data.get("arm", {}).get("position", {})
                        left = arm.get("left", [])
                        right = arm.get("right", [])
                        btn = data.get("button", {})
                        joy = data.get("joystick", {})
                        if left and right:
                            print(
                                f"\r  左={len(left)}轴  右={len(right)}轴  "
                                f"btn={btn.get('left',[])}  joy={joy.get('left',[0,0])}  ",
                                end="", flush=True)
                    except (json.JSONDecodeError, UnicodeDecodeError):
                        pass
            except zmq.Again:
                pass

            # 键盘
            if select.select([sys.stdin], [], [], 0)[0]:
                key = sys.stdin.read(1)
                if key == 'q':
                    break

                robot_l, robot_r = reader.get()
                cmd = {}

                if key == 'f':
                    if robot_l:
                        cmd = {"arm": {"cmd": {"left": robot_l}}}
                        print(f"\n  ← 左臂 → 同构臂  {[f'{a:.3f}' for a in robot_l]}")
                    else:
                        print("\n  ⚠ 无左臂关节数据")

                elif key == 'g':
                    if robot_r:
                        cmd = {"arm": {"cmd": {"right": robot_r}}}
                        print(f"\n  → 右臂 → 同构臂  {[f'{a:.3f}' for a in robot_r]}")
                    else:
                        print("\n  ⚠ 无右臂关节数据")

                elif key == 's':
                    if robot_l and robot_r:
                        cmd = {"arm": {"cmd": {"left": robot_l, "right": robot_r}}}
                        print(f"\n  ⇄ 双腕 → 同构臂")
                    else:
                        print("\n  ⚠ 关节数据不全")

                elif key == '1':
                    cmd = {"hand": {"open": True}}
                    print("\n  🖐 张手")

                elif key == '2':
                    cmd = {"hand": {"open": False}}
                    print("\n  ✊ 闭合")

                if cmd:
                    pub.send(json.dumps(cmd).encode("utf-8"))

            time.sleep(0.02)

    except KeyboardInterrupt:
        pass
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
        pub.close()
        sub.close()
        ctx.destroy()
        reader.destroy_node()
        rclpy.try_shutdown()
        print("\n✅ 已退出")


if __name__ == "__main__":
    main()
