#!/usr/bin/env python3
"""
xarmdebug — XARM 话题变化监控。
对比 body_control 基准话题，高亮 XARM 新增话题，显示 /joint_states 和控制器状态。

前提: 机器人启动 XARM (hardware:=real), 本机DDS互通

Usage:
    source ~/WireConnect_ws/ROS/nk2_ws/install/setup.bash
    ros2 run xarm_debug xarmdebug
"""

import sys, time, select, subprocess
from typing import Dict, Set

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

C_RESET = "\033[0m"; C_BOLD = "\033[1m"; C_DIM = "\033[2m"
C_RED = "\033[31m"; C_GREEN = "\033[32m"; C_YELLOW = "\033[33m"
C_CYAN = "\033[36m"; C_GRAY = "\033[90m"

XARM_PREFIXES = [
    "/jointspace_", "/endposetarget_", "/endpose_",
    "/controller_manager", "/manipulator/",
    "/moveit_", "/EAIHardware",
    "/joint_trajectory_controller",
    "/joint_state_broadcaster", "/joint_states",
]

JS_GROUPS = [
    ("Head",  ["head_roll","head_pitch","head_yaw"]),
    ("L Arm", ["shoulder_pitch_l","shoulder_roll_l","shoulder_yaw_l",
               "elbow_pitch_l","elbow_yaw_l","wrist_pitch_l","wrist_roll_l"]),
    ("R Arm", ["shoulder_pitch_r","shoulder_roll_r","shoulder_yaw_r",
               "elbow_pitch_r","elbow_yaw_r","wrist_pitch_r","wrist_roll_r"]),
    ("Waist", ["waist_yaw","waist_pitch"]),
    ("Legs",  ["first_leg_pitch","second_leg_pitch"]),
]


class XarmDebug(Node):
    def __init__(self):
        super().__init__("xarmdebug")
        self._js: Dict[str, float] = {}
        self._js_time = 0.0
        self._last_cmd = ""

        self.create_subscription(JointState, "/joint_states", self._cb_js, 10)
        self._baseline = self._get_topics()
        self.get_logger().info(f"baseline: {len(self._baseline)} topics")

    def _get_topics(self) -> Set[str]:
        try:
            return set(subprocess.check_output(
                ["ros2","topic","list"], timeout=5, text=True).strip().split("\n"))
        except Exception:
            return set()

    def _get_controllers(self) -> str:
        try:
            return subprocess.check_output(
                ["ros2","control","list-controllers"], timeout=5, text=True)
        except Exception:
            return ""

    def _cb_js(self, msg):
        for n, p in zip(msg.name, msg.position):
            self._js[n] = float(p)
        self._js_time = self.get_clock().now().nanoseconds * 1e-9

    def render(self) -> str:
        t = self.get_clock().now().nanoseconds * 1e-9
        current = self._get_topics()
        new_topics = current - self._baseline
        js_age = t - self._js_time if self._js_time else 999

        lines = ["\033[2J\033[H"]
        lines.append(f"{C_BOLD}xarmdebug{C_RESET}  {C_DIM}{time.strftime('%H:%M:%S')}{C_RESET}  "
                     f"topics:{len(current)} (+{len(new_topics)})  q=quit  r=reset  Enter=refresh")

        if new_topics:
            xarm = [tp for tp in sorted(new_topics)
                    if any(tp.startswith(p) for p in XARM_PREFIXES)]
            other = [tp for tp in sorted(new_topics) if tp not in xarm]
            if xarm:
                lines.append(f"\n{C_BOLD}{C_GREEN}XARM new:{C_RESET}")
                for tp in xarm:
                    lines.append(f"  {C_GREEN}{tp}{C_RESET}")
            if other:
                lines.append(f"\n{C_BOLD}{C_YELLOW}Other new:{C_RESET}")
                for tp in other:
                    lines.append(f"  {C_YELLOW}{tp}{C_RESET}")
        else:
            lines.append(f"\n{C_GRAY}no new topics — XARM may not be running{C_RESET}")

        if self._js:
            lines.append(f"\n{C_BOLD}/joint_states{C_RESET}  {C_DIM}age:{js_age:.1f}s{C_RESET}")
            for gname, jnames in JS_GROUPS:
                vals = []
                for j in jnames:
                    if j in self._js:
                        v = self._js[j]
                        vals.append(f"{j.rsplit('_',1)[-1]}:{C_DIM}{v:+.3f}{C_RESET}")
                if vals:
                    lines.append(f"  {C_CYAN}{gname:6s}{C_RESET}  " + "  ".join(vals))
        else:
            lines.append(f"\n{C_YELLOW}waiting for /joint_states ...{C_RESET}")

        ctrl = self._get_controllers()
        if ctrl:
            lines.append(f"\n{C_BOLD}Controllers:{C_RESET}")
            for line in ctrl.strip().split("\n")[1:]:
                if line.strip():
                    lines.append(f"  {C_GREEN if 'active' in line else C_DIM}{line}{C_RESET}")

        if self._last_cmd:
            lines.append(f"\n{C_DIM}{self._last_cmd}{C_RESET}")
        lines.append(f"\n{C_BOLD}> {C_RESET}")
        return "\n".join(lines)

    def run(self):
        sys.stdout.write(self.render())
        sys.stdout.flush()
        try:
            while rclpy.ok():
                rclpy.spin_once(self, timeout_sec=0.05)
                if select.select([sys.stdin], [], [], 0)[0]:
                    line = sys.stdin.readline()
                    if not line: break
                    line = line.strip()
                    if line in ("q","quit","exit"): break
                    if line in ("r","reset"):
                        self._baseline = self._get_topics()
                        self._last_cmd = f"{C_GREEN}baseline reset: {len(self._baseline)} topics{C_RESET}"
                    elif line in ("h","help","?"):
                        self._last_cmd = "r=reset baseline  q=quit  Enter=refresh"
                    elif line == "":
                        self._last_cmd = ""
                    else:
                        self._last_cmd = f"{C_RED}? {line} — try 'h'{C_RESET}"
                    sys.stdout.write(self.render())
                    sys.stdout.flush()
        except (KeyboardInterrupt, EOFError):
            pass


def main():
    rclpy.init()
    node = XarmDebug()
    try:
        node.run()
    finally:
        node.destroy_node()
        try: rclpy.shutdown()
        except Exception: pass
        print(f"\n{C_DIM}xarmdebug stopped.{C_RESET}")


if __name__ == "__main__":
    main()
