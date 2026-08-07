#!/usr/bin/env python3
"""isomorphic_follow — 按键控制同构臂跟随机械臂。

协议 (PUB → 192.168.41.100:6003):
    开始同步: {"type": "sync_xtele", "position": [左7, 右7, 腰1]}
    停止同步: {"type": "get_xtele"}

用法:
    python3 isomorphic_follow.py

按键:
    空格 = 开始/停止同步
    q   = 退出

依赖: bodyctrl + XARM(关节) + joint_relay → /joint_states
"""

import json, os, sys, time, select, tty, termios, threading

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

# ── 配置 ──
ZMQ_HOST = "192.168.41.100"
ZMQ_SUB_PORT = 5003   # 同构臂 → 笔记本 (传感器)
ZMQ_PUB_PORT = 6003   # 笔记本 → 同构臂 (电机指令)
SYNC_HZ = 100

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
        self._lock = threading.Lock()
        self.create_subscription(JointState, "/joint_states", self._cb, 10)

    def _cb(self, msg):
        v = dict(zip(msg.name, msg.position))
        with self._lock:
            if all(n in v for n in ARM_J_L):
                self._left = [float(v[n]) for n in ARM_J_L]
            if all(n in v for n in ARM_J_R):
                self._right = [float(v[n]) for n in ARM_J_R]

    def get(self):
        with self._lock:
            return (
                list(self._left) if self._left else None,
                list(self._right) if self._right else None,
            )


def sync_loop(pub, reader, get_syncing, stop_event):
    """后台线程: 持续读取 /joint_states 并以 ~100Hz PUB sync_xtele"""
    period = 1.0 / SYNC_HZ
    while not stop_event.is_set():
        t0 = time.perf_counter()

        if not get_syncing():
            time.sleep(0.1)
            continue

        left, right = reader.get()
        if left is None or right is None:
            time.sleep(0.1)
            continue

        pos = list(left) + list(right) + [0.0]
        pub.send(json.dumps({"type": "sync_xtele", "position": pos}).encode("utf-8"))

        elapsed = time.perf_counter() - t0
        if elapsed < period:
            time.sleep(period - elapsed)


def main():
    rclpy.init()
    reader = JointReader()

    spin = threading.Thread(target=rclpy.spin, args=(reader,), daemon=True)
    spin.start()
    time.sleep(0.3)

    # ZMQ
    ctx = zmq.Context()

    sub = ctx.socket(zmq.SUB)
    sub.setsockopt(zmq.CONFLATE, 1)
    sub.setsockopt(zmq.SUBSCRIBE, b"")
    sub.connect(f"tcp://{ZMQ_HOST}:{ZMQ_SUB_PORT}")
    sub.setsockopt(zmq.RCVTIMEO, 100)

    pub = ctx.socket(zmq.PUB)
    pub.connect(f"tcp://{ZMQ_HOST}:{ZMQ_PUB_PORT}")
    time.sleep(0.1)

    # 同步状态
    _syncing = False
    _lock = threading.Lock()

    def get_syncing():
        with _lock: return _syncing

    def set_syncing(v):
        nonlocal _syncing
        with _lock: _syncing = v

    # 启动同步线程
    stop_sync = threading.Event()
    sync_thread = threading.Thread(
        target=sync_loop, args=(pub, reader, get_syncing, stop_sync), daemon=True)
    sync_thread.start()

    # 键盘
    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    tty.setcbreak(fd)

    print("━" * 50)
    print("🎮 同构臂跟随")
    print(f"   SUB ← {ZMQ_HOST}:{ZMQ_SUB_PORT}")
    print(f"   PUB → {ZMQ_HOST}:{ZMQ_PUB_PORT}  ({SYNC_HZ}Hz)")
    print()
    print("  空格 = 开始/停止同步  q = 退出")
    print()

    try:
        while rclpy.ok():
            # 显示同构臂数据
            try:
                while True:
                    raw = sub.recv(zmq.NOBLOCK)
                    data = json.loads(raw.decode("utf-8"))
                    arm = data.get("arm", {}).get("position", {})
                    left = arm.get("left", [])
                    right = arm.get("right", [])
                    if left or right:
                        state = "🟢同步中" if _syncing else "🔴已停止"
                        print(
                            f"\r  {state}  同构臂: 左={len(left)}轴 右={len(right)}轴  ",
                            end="", flush=True)
            except (zmq.Again, json.JSONDecodeError, UnicodeDecodeError):
                pass

            if select.select([sys.stdin], [], [], 0)[0]:
                key = sys.stdin.read(1)
                if key == 'q':
                    break
                elif key == ' ':
                    if _syncing:
                        set_syncing(False)
                        pub.send(json.dumps({"type": "get_xtele"}).encode("utf-8"))
                        print("\n  ⏸ 停止同步")
                    else:
                        set_syncing(True)
                        print("\n  ▶ 开始同步")

            time.sleep(0.02)

    except KeyboardInterrupt:
        pass
    finally:
        set_syncing(False)
        pub.send(json.dumps({"type": "get_xtele"}).encode("utf-8"))
        time.sleep(0.05)
        stop_sync.set()
        sync_thread.join(timeout=0.5)
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
        pub.close(); sub.close(); ctx.destroy()
        reader.destroy_node(); rclpy.try_shutdown()
        print("\n✅ 已退出")


if __name__ == "__main__":
    main()
