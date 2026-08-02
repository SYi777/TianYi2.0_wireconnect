#!/usr/bin/env python3
"""ZMQ 手柄 → 左手控制 (机器人端)

按键: Right_A 按下张开手，松开闭合手
部署: ssh ubuntu@172.16.17.214 后 python3 zmq_hand_control.py
"""

import os
import json
import time
import threading
import signal

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq
import rclpy
from rclpy.node import Node
from rclpy.logging import LoggingSeverity
from sensor_msgs.msg import JointState

# ── 配置 ───────────────────────────────────────────────────
ZMQ_IP   = "192.168.41.100"
ZMQ_PORT = 5003
BTN_A = 0  # Left first button

JOINT_NAMES = ["1", "2", "3", "4", "5", "6"]
PRESET_OPEN  = [0.10, 0.05, 0.75, 0.55, 0.65, 0.22]   # 张手 (thumb roll 22%)
PRESET_CLOSE = [0.10, 0.05, 0.50, 0.50, 0.55, 0.22]   # 闭合 (thumb roll 22%)


class HandControlNode(Node):
    def __init__(self):
        super().__init__("zmq_hand_control")
        self.get_logger().set_level(LoggingSeverity.WARN)
        self.pub = self.create_publisher(JointState, "/inspire_hand/ctrl/left_hand", 10)
        self._angles = [0.0] * 6
        self._lock = threading.Lock()

    def send(self, angles=None):
        if angles is not None:
            self._angles = list(angles)
        msg = JointState()
        msg.name = JOINT_NAMES
        msg.position = list(self._angles)
        self.pub.publish(msg)

    def set_all(self, values: list):
        """Set all 6 joints at once."""
        self._angles = list(values)
        self.send()

    def step_to(self, idx: int, target: float, step: float, delay: float):
        """Smoothly step one joint to target."""
        cur = self._angles[idx]
        while abs(cur - target) > 0.005:
            cur = min(target, cur + step) if cur < target else max(target, cur - step)
            self._angles[idx] = cur
            self.send()
            time.sleep(delay)


def main():
    rclpy.init()
    hand = HandControlNode()
    threading.Thread(target=rclpy.spin, args=(hand,), daemon=True).start()

    ctx = zmq.Context()
    sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1)
    sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{ZMQ_IP}:{ZMQ_PORT}")
    sock.setsockopt(zmq.RCVTIMEO, 200)

    running = True
    def stop(sig, frame):
        nonlocal running; running = False
    signal.signal(signal.SIGINT, stop)
    signal.signal(signal.SIGTERM, stop)

    print("🎮 ZMQ 手柄 → 左手")
    print(f"   Left[0] 按下 → 🖐️ 张手")
    print(f"   Left[0] 松手 → ✊ 闭合")
    print("等待按键...")

    was_pressed = False
    hand.set_all(PRESET_CLOSE)

    try:
        while running and rclpy.ok():
            pressed = was_pressed  # default keep current
            try:
                # drain all ZMQ messages, keep latest button state
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

            if pressed and not was_pressed:
                print("🖐️ 张手")
            elif not pressed and was_pressed:
                print("✊ 闭合")
            was_pressed = pressed

            hand.set_all(PRESET_OPEN if pressed else PRESET_CLOSE)
            time.sleep(0.02)   # 50Hz send rate
    finally:
        sock.close()
        ctx.destroy()
        hand.destroy_node()
        rclpy.shutdown()
        print("✅ 已退出")


if __name__ == "__main__":
    main()
