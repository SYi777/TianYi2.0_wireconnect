#!/usr/bin/env python3
"""
isomorphic_hand_bridge — 同构臂按键 → 左手预设 (机器人端)

部署在机器人 x86 (192.168.41.1):
  ssh ubuntu@192.168.41.1
  将此脚本复制到机器人上运行

链路:
  工控机 fast_sync → ZMQ 5003 → 机器人(bridge) → ROS2 body_control → 左手

按键:
  Right_A → 张手 | Right_B → 捏住

前置:
  1. 机器人开机自检完成，body_control 运行中
  2. 工控机 fast_sync 运行中
  3. 机器人与工控机互通 (ping 192.168.41.100)
"""

import os
import time
import json
import threading
import signal

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq
import rclpy
from rclpy.node import Node
from rclpy.logging import LoggingSeverity
from sensor_msgs.msg import JointState


# ── 配置 ───────────────────────────────────────────────────
TONGSUO_IP   = "192.168.41.100"
TONGSUO_PORT = 5003

# button.right[] 索引: 0=A, 1=B, 2=C, 3=摇杆按钮, 4=滚轮按钮
BTN_OPEN  = 0   # Right_A → 张手
BTN_CLOSE = 1   # Right_B → 捏住

# 手部预设: JointState 6 DOF [小指,无名指,中指,食指,拇指弯曲,拇指旋转]
JOINT_NAMES = ["1", "2", "3", "4", "5", "6"]
PRESETS = {
    "open":  [0.10, 0.05, 1.00, 0.65, 0.85, 0.10],
    "close": [0.10, 0.05, 0.45, 0.45, 0.60, 0.10],
}


class HandPresetNode(Node):
    def __init__(self):
        super().__init__("hand_button_bridge")
        self.get_logger().set_level(LoggingSeverity.FATAL)
        self.pub = self.create_publisher(
            JointState, "/inspire_hand/ctrl/left_hand", 10
        )
        self.angles = [0.0] * 6
        self._busy = False
        self._lock = threading.Lock()

    def send(self, angles=None):
        if angles is not None:
            self.angles = list(angles)
        msg = JointState()
        msg.name = JOINT_NAMES
        msg.position = list(self.angles)
        self.pub.publish(msg)

    def execute_preset(self, name: str):
        tgt = PRESETS[name]
        with self._lock:
            if self._busy:
                return
            self._busy = True

        self.angles[0] = tgt[0]
        self.angles[1] = tgt[1]
        self.angles[5] = tgt[5]
        self.send()

        def step_to(idx, target, step, delay):
            cur = self.angles[idx]
            while abs(cur - target) > 0.005:
                cur = min(target, cur + step) if cur < target \
                    else max(target, cur - step)
                self.angles[idx] = cur
                self.send()
                time.sleep(delay)

        threading.Thread(target=step_to, args=(3, tgt[3], 0.06, 0.06),
                         daemon=True).start()
        threading.Thread(target=step_to, args=(4, tgt[4], 0.05, 0.06),
                         daemon=True).start()

        def middle():
            time.sleep(2.0)
            step_to(2, tgt[2], 0.02, 0.10)
            with self._lock:
                self._busy = False

        threading.Thread(target=middle, daemon=True).start()
        print(f"\n🎮 按键 → {'🖐️ 张手' if name == 'open' else '✊ 捏住'}")


def main():
    rclpy.init()
    hand = HandPresetNode()
    threading.Thread(target=rclpy.spin, args=(hand,), daemon=True).start()

    ctx = zmq.Context()
    sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1)
    sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{TONGSUO_IP}:{TONGSUO_PORT}")
    sock.setsockopt(zmq.RCVTIMEO, 200)

    running = True

    def stop(sig, frame):
        nonlocal running
        print("\n🛑 停止...")
        running = False

    signal.signal(signal.SIGINT, stop)
    signal.signal(signal.SIGTERM, stop)

    print("=" * 55)
    print("🎮 同构臂手柄 → 左手预设 (机器人端)")
    print(f"📡 ZMQ: tcp://{TONGSUO_IP}:{TONGSUO_PORT}")
    print(f"   Right_A → 🖐️  张手")
    print(f"   Right_B → ✊ 捏住")
    print(f"📍 运行位置: 机器人 x86 (本机)")
    print("=" * 55)

    btn_consumed = {BTN_OPEN: False, BTN_CLOSE: False}

    print("⏳ 等待按键...")
    while running:
        try:
            messages = sock.recv_multipart(zmq.NOBLOCK)
            for msg in messages:
                try:
                    data = json.loads(msg.decode("utf-8"))
                except (json.JSONDecodeError, UnicodeDecodeError):
                    continue

                button = data.get("button", {})
                right = button.get("right", [])
                if len(right) < 5:
                    continue

                # Right_A
                if right[BTN_OPEN] and not btn_consumed[BTN_OPEN]:
                    btn_consumed[BTN_OPEN] = True
                    hand.execute_preset("open")
                elif not right[BTN_OPEN]:
                    btn_consumed[BTN_OPEN] = False

                # Right_B
                if right[BTN_CLOSE] and not btn_consumed[BTN_CLOSE]:
                    btn_consumed[BTN_CLOSE] = True
                    hand.execute_preset("close")
                elif not right[BTN_CLOSE]:
                    btn_consumed[BTN_CLOSE] = False

        except zmq.Again:
            time.sleep(0.01)
        except zmq.ZMQError:
            pass

    sock.close()
    ctx.destroy()
    hand.destroy_node()
    rclpy.shutdown()
    print("✅ 已退出")


if __name__ == "__main__":
    main()
