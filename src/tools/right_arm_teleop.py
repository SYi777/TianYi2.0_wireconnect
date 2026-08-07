#!/usr/bin/env python3
"""right_arm_teleop — 同构臂 ZMQ → 天轶右手遥操 + 录制/回放

Usage:
    python3 right_arm_teleop.py                    # 遥操+录制 (空格保存)
    python3 right_arm_teleop.py --replay <file>    # 回放录好的轨迹
"""

import json, math, os, sys, time, threading, signal, select, tty, termios

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq, rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition

ZMQ_IP, ZMQ_PORT = "192.168.41.100", 5003

MOTOR_RIGHT = [21, 22, 23, 24, 25, 26, 27]
SPD_R = 2.0
CUR_R = [8.0, 6.0, 4.0, 4.0, 4.0, 3.0, 3.0]

REF_R  = [0.04, -0.032, 0.077, -0.258, 0.08, 0.247, -0.084]
THRESH = [math.radians(25)] * 7
APPROACH_STEP = 0.002
OUTPUT = os.path.expanduser("~/WireConnect_ws/src/trajectory_bridge/config/right_traj.json")


def check_safety(a):
    return all(abs(a[i] - REF_R[i]) < THRESH[i] for i in range(7))


class RightTeleopNode(Node):
    def __init__(self):
        super().__init__("right_arm_teleop")
        self._pub = self.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)
    def send(self, angles):
        msg = CmdSetMotorPosition()
        msg.header = Header(stamp=self.get_clock().now().to_msg())
        msg.cmds = [SetMotorPosition(name=m, pos=a, spd=SPD_R, cur=CUR_R[i])
                    for i, (m, a) in enumerate(zip(MOTOR_RIGHT, angles))]
        self._pub.publish(msg)


def replay_traj(node, filename, reverse=False):
    with open(filename) as f: traj = json.load(f)
    if reverse: traj = list(reversed(traj))
    first_frame = traj[0]

    # 安全检查: 当前关节 vs 轨迹第一帧差距
    try:
        import subprocess as sp
        r = sp.run("source /opt/ros/humble/setup.bash && ros2 topic echo /joint_state_broadcaster/joint_states --once 2>/dev/null",
                   shell=True, capture_output=True, text=True, timeout=3)
        cur = [float(x) for x in r.stdout.split('\n') if x.strip() and x.strip()[0] in '-0123456789'][:7]
        if len(cur) == 7:
            max_diff = max(abs(cur[i] - first_frame[i]) for i in range(7))
            print(f"  当前 vs 首帧 最大偏差: {math.degrees(max_diff):.1f}°")
            if max_diff > 0.5:  # ~30°
                print(f"⚠ 偏差过大，拒绝回放！请先遥操靠近目标位置")
                return
            if max_diff > 0.05:  # ~3°
                print(f"  插值逼近中...")
                for step in range(50):  # ~2.5s
                    t = (step + 1) / 50.0
                    interp = [cur[i] + (first_frame[i] - cur[i]) * t for i in range(7)]
                    node.send(interp); time.sleep(0.05)
    except Exception:
        pass

    print(f"{'◀ 倒放' if reverse else '▶ 回放'} {len(traj)} 帧")
    for i, angles in enumerate(traj):
        node.send(angles); time.sleep(0.012)
        if i % 200 == 0: print(f"  {i}/{len(traj)}")


def main():
    rclpy.init(); node = RightTeleopNode()
    threading.Thread(target=lambda: [rclpy.spin_once(node, timeout_sec=0.01) or time.sleep(0.001) for _ in iter(int,1)], daemon=True).start()
    time.sleep(0.3)

    if "--replay" in sys.argv:
        rev = "--reverse" in sys.argv
        replay_traj(node, sys.argv[sys.argv.index("--replay") + 1], reverse=rev)
        node.destroy_node(); rclpy.try_shutdown(); return

    # keyboard: space to start/stop recording
    fd = sys.stdin.fileno(); old = termios.tcgetattr(fd); tty.setcbreak(fd)

    ctx = zmq.Context(); sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1); sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{ZMQ_IP}:{ZMQ_PORT}"); sock.setsockopt(zmq.RCVTIMEO, 200)

    state = "waiting"; start_angles = list(REF_R)
    last_sent = None; recorded = []; recording = False
    hand_angles = list(REF_R)

    print("🎮 右手遥操 + 录制")
    print("   [空格] 开始录制    [空格] 停止并保存    q 退出")

    try:
        while rclpy.ok():
            # drain ZMQ
            try:
                while True:
                    d = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
                    a = d.get("arm",{}).get("position",{}).get("right")
                    if a and len(a) == 7: hand_angles = [float(x) for x in a]
            except zmq.Again: pass

            # keyboard
            if select.select([sys.stdin], [], [], 0)[0]:
                key = sys.stdin.read(1)
                if key == ' ':
                    if recording:
                        with open(OUTPUT, "w") as f: json.dump(recorded, f, indent=2)
                        print(f"\n💾 保存 {len(recorded)} 帧 → {OUTPUT}")
                        recording = False; recorded = []
                    else:
                        recording = True; recorded = []
                        print(f"\n🔴 录制中...")
                elif key in ('q', '\x1b'):
                    break

            if state == "waiting":
                if not check_safety(hand_angles): time.sleep(0.1); continue
                print("→ 步进逼近..."); state = "approaching"

            if state == "approaching":
                done = True
                for i in range(7):
                    d = hand_angles[i] - start_angles[i]
                    if abs(d) < 0.001: continue
                    done = False
                    start_angles[i] += max(-APPROACH_STEP, min(APPROACH_STEP, d))
                if done: print("→ 跟随"); state = "following"
                else: node.send(start_angles); time.sleep(0.03); continue

            if state == "following":
                if last_sent != hand_angles:
                    node.send(hand_angles)
                    if recording: recorded.append(list(hand_angles))
                    last_sent = list(hand_angles)
                continue

            time.sleep(0.01)

    finally: termios.tcsetattr(fd, termios.TCSADRAIN, old)
    sock.close(); ctx.destroy(); node.destroy_node(); rclpy.try_shutdown()
    print("✅ 已退出")


if __name__ == "__main__": main()
