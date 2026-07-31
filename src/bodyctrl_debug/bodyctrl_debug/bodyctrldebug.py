#!/usr/bin/env python3
"""
bodyctrldebug — body_control 传感器监控 + 电机级角度控制 (无需 XARM)。

Usage:
    source ~/WireConnect_ws/ROS/ros2ws/install/setup.bash
    ros2 run bodyctrl_debug bodyctrldebug
"""

import sys
import select
import time
from typing import Dict, Optional, Tuple

import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from sensor_msgs.msg import JointState

try:
    from bodyctrl_msgs.msg import (
        MotorStatusMsg, MotorStatus,
        CmdSetMotorPosition, SetMotorPosition,
        Imu, PowerBatteryStatus,
    )
    HAS_BODYCTRL = True
except ImportError:
    HAS_BODYCTRL = False

# ---- 常量 ----

MOTOR_TO_JOINT: Dict[int, str] = {
    1:  "head_roll",       2:  "head_pitch",       3:  "head_yaw",
    11: "shoulder_pitch_l", 12: "shoulder_roll_l",  13: "shoulder_yaw_l",
    14: "elbow_pitch_l",    15: "elbow_yaw_l",      16: "wrist_pitch_l",
    17: "wrist_roll_l",
    21: "shoulder_pitch_r", 22: "shoulder_roll_r",  23: "shoulder_yaw_r",
    24: "elbow_pitch_r",    25: "elbow_yaw_r",      26: "wrist_pitch_r",
    27: "wrist_roll_r",
    31: "waist_yaw",        32: "waist_pitch",
    51: "first_leg_pitch",  52: "second_leg_pitch",
}

MOTOR_TO_CTRL: Dict[int, str] = {}
for _mid in range(1, 4):    MOTOR_TO_CTRL[_mid] = "/head/cmd_pos"
for _mid in range(11, 18):  MOTOR_TO_CTRL[_mid] = "/arm/cmd_pos"
for _mid in range(21, 28):  MOTOR_TO_CTRL[_mid] = "/arm/cmd_pos"
for _mid in (31, 32):       MOTOR_TO_CTRL[_mid] = "/waist/cmd_pos"
for _mid in (51, 52):       MOTOR_TO_CTRL[_mid] = "/leg/cmd_pos"

MOTOR_GROUPS = [
    ("Head",  [1, 2, 3]),
    ("L Arm", [11, 12, 13, 14, 15, 16, 17]),
    ("R Arm", [21, 22, 23, 24, 25, 26, 27]),
    ("Waist", [31, 32]),
    ("Legs",  [51, 52]),
]

JOINT_LIMITS: Dict[int, Tuple[float, float]] = {
    1:  (-0.45, 0.45),      2:  (-0.43, 0.43),       3:  (-1.57, 1.57),
    11: (-2.96, 2.96),      12: (-0.262, 2.616),     13: (-2.96, 2.96),
    14: (-2.61, 0.261),     15: (-2.96, 2.96),       16: (-0.785, 1.05),
    17: (-1.65, 1.3),
    21: (-2.96, 2.96),      22: (-2.616, 0.262),     23: (-2.96, 2.96),
    24: (-2.61, 0.261),     25: (-2.96, 2.96),       26: (-0.785, 1.05),
    27: (-1.3, 1.65),
    31: (-2.96, 3.14),      32: (-0.785, 2.094),
    51: (-0.419, 0.908),    52: (-1.745, 0.506),
}

JOINT_SHORT: Dict[str, str] = {
    "head_roll": "roll", "head_pitch": "pitch", "head_yaw": "yaw",
    "shoulder_pitch_l": "sh_p", "shoulder_roll_l": "sh_r", "shoulder_yaw_l": "sh_y",
    "elbow_pitch_l": "el_p", "elbow_yaw_l": "el_y",
    "wrist_pitch_l": "wr_p", "wrist_roll_l": "wr_r",
    "shoulder_pitch_r": "sh_p", "shoulder_roll_r": "sh_r", "shoulder_yaw_r": "sh_y",
    "elbow_pitch_r": "el_p", "elbow_yaw_r": "el_y",
    "wrist_pitch_r": "wr_p", "wrist_roll_r": "wr_r",
    "waist_yaw": "yaw", "waist_pitch": "pitch",
    "first_leg_pitch": "leg1", "second_leg_pitch": "leg2",
}

C_RESET = "\033[0m"; C_BOLD = "\033[1m"; C_DIM = "\033[2m"
C_RED = "\033[31m"; C_GREEN = "\033[32m"; C_YELLOW = "\033[33m"
C_CYAN = "\033[36m"; C_GRAY = "\033[90m"
GROUP_COLORS = [C_CYAN, C_GREEN, C_GREEN, C_YELLOW, C_YELLOW]


class BodyCtrlDebug(Node):
    def __init__(self):
        super().__init__("bodyctrldebug")
        self.declare_parameter("spd_head", 6.0)
        self.declare_parameter("spd_arm", 9.0)
        self.declare_parameter("spd_waist", 4.0)
        self.declare_parameter("spd_leg", 4.0)
        # rated current from SDK §1.1 (waist/legs estimated from peak torque)
        self._cur = {
            1: 5, 2: 5, 3: 5,                       # head
            11: 35, 12: 23, 13: 8, 14: 8, 15: 8, 16: 5, 17: 5,   # L arm
            21: 35, 22: 23, 23: 8, 24: 8, 25: 8, 26: 5, 27: 5,   # R arm
            31: 20, 32: 30,                           # waist
            51: 30, 52: 30,                           # legs
        }
        self._spd = {}
        for _mid in MOTOR_TO_JOINT:
            if _mid <= 3:
                self._spd[_mid] = self.get_parameter("spd_head").value
            elif _mid <= 27:
                self._spd[_mid] = self.get_parameter("spd_arm").value
            elif _mid <= 32:
                self._spd[_mid] = self.get_parameter("spd_waist").value
            else:
                self._spd[_mid] = self.get_parameter("spd_leg").value

        self._motor_data: Dict[int, MotorStatus] = {}
        self._last_msg_time = 0.0
        self._imu = None
        self._battery = None

        for t in ["/head/status", "/arm/status", "/waist/status", "/leg/status"]:
            self.create_subscription(MotorStatusMsg, t, self._cb_motor, 10)
        self.create_subscription(Imu, "/imu/status", self._cb_imu, 10)
        self.create_subscription(PowerBatteryStatus, "/power/battery/status", self._cb_battery, 10)

        self._pub_head  = self.create_publisher(CmdSetMotorPosition, "/head/cmd_pos", 10)
        self._pub_arm   = self.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)
        self._pub_waist = self.create_publisher(CmdSetMotorPosition, "/waist/cmd_pos", 10)
        self._pub_leg   = self.create_publisher(CmdSetMotorPosition, "/leg/cmd_pos", 10)

        self._running = True

    def _cb_motor(self, msg):
        for m in msg.status: self._motor_data[m.name] = m
        self._last_msg_time = self.get_clock().now().nanoseconds * 1e-9
    def _cb_imu(self, msg): self._imu = msg
    def _cb_battery(self, msg): self._battery = msg

    def send(self, motor_id: int, angle_rad: float) -> str:
        limits = JOINT_LIMITS.get(motor_id)
        if limits and (angle_rad < limits[0] or angle_rad > limits[1]):
            return f"{C_RED}OUT OF RANGE: {angle_rad:+.3f} not in [{limits[0]:+.3f}, {limits[1]:+.3f}]{C_RESET}"
        topic = MOTOR_TO_CTRL.get(motor_id)
        pub = {"/head/cmd_pos": self._pub_head, "/arm/cmd_pos": self._pub_arm,
               "/waist/cmd_pos": self._pub_waist, "/leg/cmd_pos": self._pub_leg}.get(topic)
        if not pub:
            return f"{C_RED}no publisher{C_RESET}"
        msg = CmdSetMotorPosition()
        msg.header.stamp.sec = 0
        msg.header.stamp.nanosec = 0
        s = self._spd.get(motor_id, 2.0)
        c = self._cur.get(motor_id, 1.0)
        msg.cmds = [SetMotorPosition(name=motor_id, pos=float(angle_rad), spd=float(s), cur=float(c))]
        self.get_logger().info(f"PUB: header.frame_id='{msg.header.frame_id}' cmds[0]={msg.cmds[0]}")
        pub.publish(msg)
        return f"{C_GREEN}SENT motor {motor_id} ({MOTOR_TO_JOINT.get(motor_id)}) -> {angle_rad:+.4f} rad -> {topic}{C_RESET}"

    def render(self, last_cmd: str = "", selected: Optional[int] = None) -> str:
        t = self.get_clock().now().nanoseconds * 1e-9
        age = t - self._last_msg_time if self._last_msg_time else 999
        lines = ["\033[2J\033[H"]
        lines.append(f"{C_BOLD}bodyctrldebug{C_RESET}  {C_DIM}{time.strftime('%H:%M:%S')}{C_RESET}  "
                     f"{C_DIM}age:{age:.1f}s  q=quit  h=help{C_RESET}")

        for gi, (gname, motor_ids) in enumerate(MOTOR_GROUPS):
            parts = [f"{C_BOLD}{GROUP_COLORS[gi]}{gname:6s}{C_RESET}"]
            for mid in motor_ids:
                m = self._motor_data.get(mid)
                short = JOINT_SHORT.get(MOTOR_TO_JOINT.get(mid, ""), "?")
                limits = JOINT_LIMITS.get(mid)
                lim_hint = f"[{limits[0]:+.2f},{limits[1]:+.2f}]" if limits else ""
                if m:
                    pos = m.pos
                    over = limits and (pos < limits[0] or pos > limits[1])
                    parts.append(f"{C_RED if over else ''}{short}:{pos:+.3f}{C_RESET if over else ''}"
                                 f"{C_DIM}{lim_hint}{C_RESET}")
                else:
                    parts.append(f"{C_GRAY}{short}:---{C_RESET}")
            lines.append("  ".join(parts))

        if self._battery:
            b = self._battery
            lines.append(f"{C_DIM}Batt {b.master_battery_voltage:.1f}V {b.master_battery_current:.1f}A {int(b.master_battery_power)}%{C_RESET}")

        if selected is not None:
            m = self._motor_data.get(selected)
            jname = MOTOR_TO_JOINT.get(selected, "?")
            limits = JOINT_LIMITS.get(selected)
            lim_str = f"[{limits[0]:+.3f}, {limits[1]:+.3f}]" if limits else "?"
            if m:
                lines.append(f"\n{C_YELLOW}motor {selected} {jname} limits:{lim_str}  "
                             f"pos={m.pos:+.4f} spd={m.speed:+.2f} cur={m.current:+.2f}A "
                             f"temp={m.temperature:.0f}°C{C_RESET}")
            else:
                lines.append(f"\n{C_YELLOW}motor {selected} {jname} limits:{lim_str}  no data{C_RESET}")

        if last_cmd:
            lines.append(f"\n{C_DIM}{last_cmd}{C_RESET}")
        lines.append(f"\n{C_BOLD}> {C_RESET}")
        return "\n".join(lines)


def main():
    rclpy.init()
    if not HAS_BODYCTRL:
        print("bodyctrl_msgs not found. source ~/WireConnect_ws/ROS/ros2ws/install/setup.bash")
        sys.exit(1)

    node = BodyCtrlDebug()
    last_cmd = ""
    selected = None

    sys.stdout.write(node.render(last_cmd))
    sys.stdout.flush()

    try:
        while node._running and rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
            if select.select([sys.stdin], [], [], 0)[0]:
                line = sys.stdin.readline()
                if not line:
                    break
                line = line.strip()
                if line in ("q", "quit", "exit"):
                    break
                if line in ("l", "list"):
                    last_cmd = "\n".join(f"  {mid:2d}  {MOTOR_TO_JOINT.get(mid, '?')}"
                                         for mid in sorted(MOTOR_TO_JOINT))
                elif line in ("h", "help", "?"):
                    last_cmd = "<id> <rad> send  |  Enter refresh  |  l list  |  q quit"
                elif line == "":
                    last_cmd = ""
                    selected = None
                else:
                    parts = line.split()
                    try:
                        mid = int(parts[0])
                        if mid not in MOTOR_TO_JOINT:
                            last_cmd = f"{C_RED}unknown motor {mid} — try 'l'{C_RESET}"
                        elif len(parts) >= 2:
                            angle = float(parts[1])
                            last_cmd = node.send(mid, angle)
                            selected = None
                        else:
                            selected = mid
                            last_cmd = ""
                    except ValueError:
                        last_cmd = f"{C_RED}? {line} — try 'h'{C_RESET}"
                sys.stdout.write(node.render(last_cmd, selected))
                sys.stdout.flush()
    except (KeyboardInterrupt, EOFError):
        pass

    node.destroy_node()
    try:
        rclpy.shutdown()
    except Exception:
        pass
    print(f"\n{C_DIM}stopped.{C_RESET}")


if __name__ == "__main__":
    main()
