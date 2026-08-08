#!/usr/bin/env python3
"""右手控制 — ZMQ手柄 或 键盘

Usage:
    python3 zmq_hand_control.py              # ZMQ模式 (默认)
    python3 zmq_hand_control.py --keyboard   # 键盘模式 (空格=切换张手/闭合, q=退出)

部署: ssh ubuntu@172.16.17.214 后 python3 zmq_hand_control.py [--keyboard]
"""

import os
import sys
import json
import time
import select
import threading

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import rclpy
from rclpy.node import Node
from rclpy.logging import LoggingSeverity
from sensor_msgs.msg import JointState

# ── 配置 ───────────────────────────────────────────────────
ZMQ_IP   = "192.168.41.100"
ZMQ_PORT = 5003
BTN_A = 0  # Left first button

JOINT_NAMES = ["1", "2", "3", "4", "5", "6"]
# PRESET_OPEN  = [1.00, 1.00, 1.00, 0.85, 0.75, 0.16]   # 张手
# PRESET_CLOSE = [1.00, 1.00, 1.00, 0.55, 0.55, 0.16]   # 闭合

PRESET_OPEN  = [1.00, 1.00, 1.00, 0.80, 0.50, 0.15]   # 张手
PRESET_CLOSE = [1.00, 1.00, 1.00, 0.50, 0.50, 0.15]   # 闭合


class HandControlNode(Node):
    def __init__(self):
        super().__init__("zmq_hand_control")
        self.get_logger().set_level(LoggingSeverity.WARN)
        self.pub = self.create_publisher(JointState, "/inspire_hand/ctrl/right_hand", 10)
        # 设置力度为最大 (1.0 = 1000g)
        from bodyctrl_msgs.srv import SetForce
        self._force_cli = self.create_client(SetForce, "/inspire_hand/set_force/right_hand")

    def set_force_max(self):
        if not self._force_cli.wait_for_service(timeout_sec=1.0):
            print("⚠ set_force 服务不可用，跳过力度设置")
            return
        from bodyctrl_msgs.srv import SetForce
        req = SetForce.Request()
        req.force0_ratio = 1.0
        req.force1_ratio = 1.0
        req.force2_ratio = 1.0
        req.force3_ratio = 1.0
        req.force4_ratio = 1.0
        req.force5_ratio = 1.0
        self._force_cli.call_async(req)
        print("💪 力度已设为最大 (1000g)")

    def send(self, angles: list):
        msg = JointState()
        msg.name = JOINT_NAMES
        msg.position = list(angles)
        self.pub.publish(msg)


def run_zmq(hand: HandControlNode):
    import zmq
    ctx = zmq.Context()
    sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1)
    sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{ZMQ_IP}:{ZMQ_PORT}")
    sock.setsockopt(zmq.RCVTIMEO, 200)

    was_pressed = False
    hand.send(PRESET_CLOSE)

    try:
        while rclpy.ok():
            pressed = was_pressed
            try:
                while True:
                    msg = sock.recv(zmq.NOBLOCK)
                    try:
                        data = json.loads(msg.decode("utf-8"))
                        left = data.get("button", {}).get("left", [])
                        if len(left) > BTN_A:
                            pressed = bool(left[BTN_A])
                    except (json.JSONDecodeError, UnicodeDecodeError):
                        pass
            except zmq.Again:
                pass

            if pressed != was_pressed:
                print("🖐️ 张手" if pressed else "✊ 闭合")
            was_pressed = pressed
            hand.send(PRESET_OPEN if pressed else PRESET_CLOSE)
            time.sleep(0.02)
    except KeyboardInterrupt:
        pass
    finally:
        sock.close(); ctx.destroy()


def run_keyboard(hand: HandControlNode):
    import tty, termios
    fd = sys.stdin.fileno(); old = termios.tcgetattr(fd); tty.setcbreak(fd)
    is_open = False
    hand.send(PRESET_CLOSE)
    print("⌨️ 键盘模式: 空格=切换张手/闭合  q=退出")
    try:
        while rclpy.ok():
            rclpy.spin_once(hand, timeout_sec=0.02)
            if select.select([sys.stdin], [], [], 0)[0]:
                key = sys.stdin.read(1)
                if key == ' ':
                    is_open = not is_open
                    print("🖐️ 张手" if is_open else "✊ 闭合")
                elif key in ('q', '\x1b', '\x03'):
                    break
            hand.send(PRESET_OPEN if is_open else PRESET_CLOSE)
            time.sleep(0.02)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)


def main():
    rclpy.init()
    hand = HandControlNode()
    hand.set_force_max()

    try:
        if "--keyboard" in sys.argv:
            run_keyboard(hand)
        else:
            print("🎮 ZMQ 手柄 → 左手 (Ctrl+C 退出)")
            run_zmq(hand)
    except KeyboardInterrupt:
        pass

    hand.destroy_node(); rclpy.try_shutdown()
    print("✅ 已退出")


if __name__ == "__main__":
    main()
