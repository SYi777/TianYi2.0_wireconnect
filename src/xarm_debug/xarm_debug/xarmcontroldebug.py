#!/usr/bin/env python3
"""
xarmcontroldebug — XARM 控制器交互管理。
列出/切换控制器，发送关节空间指令，监控告警，硬件使能。

Usage:
    source ~/WireConnect_ws/ROS/nk2_ws/install/setup.bash
    ros2 run xarm_debug xarmcontroldebug

命令:
  l                    列出所有控制器
  a <name>             激活控制器
  d <name>             停用控制器
  jL <7f>              左臂关节 (rad)
  jR <7f>              右臂关节
  jD <14f>             双臂关节 (左7+右7)
  jB <4f>              身体关节
  jH <3f>              头部关节
  cL <x> <y> <z> <qx> <qy> <qz> <qw>  左臂笛卡尔 (m + 四元数)
  cR <x> <y> <z> <qx> <qy> <qz> <qw>  右臂笛卡尔
  eb <x> <z> <pitch> <yaw>             腰腿笛卡尔
  frame <name>         设置笛卡尔参考系 (默认 waist_yaw_link)
  arm enable|disable   手臂硬件使能
  all enable|disable   全身硬件使能
  mode <0-3>           手臂模式 (0柔顺 1速度 2重力 3位置)
  auto on|off          自动控制器切换
  q                    退出
"""

import sys, time, select, subprocess
from typing import List, Optional

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, Header
from geometry_msgs.msg import Pose, Point, Quaternion, TransformStamped

try:
    from eai_manipulator_msgs.msg import ArmTargetPose, WarnAndErrorInfo
    HAS_EAI = True
except ImportError:
    HAS_EAI = False

try:
    import tf2_ros
    HAS_TF = True
except ImportError:
    HAS_TF = False

C_RESET = "\033[0m"; C_BOLD = "\033[1m"; C_DIM = "\033[2m"
C_RED = "\033[31m"; C_GREEN = "\033[32m"; C_YELLOW = "\033[33m"
C_CYAN = "\033[36m"; C_MAGENTA = "\033[35m"; C_GRAY = "\033[90m"

# controller type → color
CTRL_COLORS = {
    "active": C_GREEN,
    "inactive": C_DIM,
    "unconfigured": C_YELLOW,
    "finalized": C_RED,
}

ARM_L = ["shoulder_pitch_l","shoulder_roll_l","shoulder_yaw_l",
         "elbow_pitch_l","elbow_yaw_l","wrist_pitch_l","wrist_roll_l"]
ARM_R = ["shoulder_pitch_r","shoulder_roll_r","shoulder_yaw_r",
         "elbow_pitch_r","elbow_yaw_r","wrist_pitch_r","wrist_roll_r"]
BODY = ["first_leg_pitch","second_leg_pitch","waist_pitch","waist_yaw"]
HEAD = ["head_yaw","head_pitch","head_roll"]

LIMITS = {
    "shoulder_pitch_l":(-2.96,2.96), "shoulder_roll_l":(-0.262,2.616),
    "shoulder_yaw_l":(-2.96,2.96), "elbow_pitch_l":(-2.61,0.261),
    "elbow_yaw_l":(-2.96,2.96), "wrist_pitch_l":(-0.785,1.05),
    "wrist_roll_l":(-1.65,1.3),
    "shoulder_pitch_r":(-2.96,2.96), "shoulder_roll_r":(-2.616,0.262),
    "shoulder_yaw_r":(-2.96,2.96), "elbow_pitch_r":(-2.61,0.261),
    "elbow_yaw_r":(-2.96,2.96), "wrist_pitch_r":(-0.785,1.05),
    "wrist_roll_r":(-1.3,1.65),
    "first_leg_pitch":(-0.419,0.908), "second_leg_pitch":(-1.745,0.506),
    "waist_pitch":(-0.785,2.094), "waist_yaw":(-2.96,3.14),
    "head_yaw":(-1.57,1.57), "head_pitch":(-0.43,0.43), "head_roll":(-0.45,0.45),
}


class XarmControlDebug(Node):
    def __init__(self):
        super().__init__("xarmcontroldebug")
        # joint space publishers
        self._pub_L = self.create_publisher(Float64MultiArray, "/jointspace_commands_L", 10)
        self._pub_R = self.create_publisher(Float64MultiArray, "/jointspace_commands_R", 10)
        self._pub_D = self.create_publisher(Float64MultiArray, "/jointspace_commands_Dual", 10)
        self._pub_B = self.create_publisher(Float64MultiArray, "/jointspace_commands_body", 10)
        self._pub_H = self.create_publisher(Float64MultiArray, "/jointspace_commands_head", 10)
        # cartesian publishers (eai_manipulator_msgs)
        self._pub_cL = None
        self._pub_cR = None
        self._pub_eb = None
        if HAS_EAI:
            self._pub_cL = self.create_publisher(ArmTargetPose, "/endposetarget_L", 10)
            self._pub_cR = self.create_publisher(ArmTargetPose, "/endposetarget_R", 10)
        self._pub_eb = self.create_publisher(Float64MultiArray, "/endposetarget_Body", 10)
        self.declare_parameter("frame", "waist_yaw_link")
        self._frame = self.get_parameter("frame").value
        self._last_cmd = ""

        # TF listener for current pose
        self._tf_buf = None
        self._tf_listener = None
        if HAS_TF:
            self._tf_buf = tf2_ros.Buffer()
            self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)
        self._pose_L: Optional[TransformStamped] = None
        self._pose_R: Optional[TransformStamped] = None

        # warn/error subscription
        self._warn_err: List[str] = []
        if HAS_EAI:
            self.create_subscription(WarnAndErrorInfo, "/manipulator/warn_and_error_info", self._cb_warn, 10)

    def _run(self, cmd: list) -> str:
        try:
            return subprocess.check_output(cmd, timeout=5, text=True, stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            return e.output or str(e)
        except Exception as e:
            return str(e)

    def _cb_warn(self, msg):
        entry = f"{msg.source}: {msg.info}"
        if msg.level == "error":
            self._warn_err.append(f"{C_RED}ERR {entry}{C_RESET}")
        else:
            self._warn_err.append(f"{C_YELLOW}WARN {entry}{C_RESET}")
        self._warn_err = self._warn_err[-10:]

    def _update_pose(self):
        if self._tf_buf:
            for side, dst in [("L","left_tcp_link"),("R","right_tcp_link")]:
                try:
                    t = self._tf_buf.lookup_transform(self._frame, dst, rclpy.time.Time())
                    if side == "L": self._pose_L = t
                    else: self._pose_R = t
                except Exception:
                    pass

    def _check(self, joints: List[str], angles: List[float]) -> str:
        for j, a in zip(joints, angles):
            lim = LIMITS.get(j)
            if lim and (a < lim[0] or a > lim[1]):
                return f"{C_RED}SAFETY: {j} {a:+.3f} ∉ [{lim[0]:+.3f}, {lim[1]:+.3f}]{C_RESET}"
        return ""

    def render(self) -> str:
        self._update_pose()
        ctrl = self._run(["ros2","control","list_controllers"])
        lines = ["\033[2J\033[H"]
        lines.append(f"{C_BOLD}xarmcontroldebug{C_RESET}  {C_DIM}{time.strftime('%H:%M:%S')}{C_RESET}  "
                     f"frame={self._frame}  q=quit  h=help")

        # current pose
        if self._pose_L:
            t = self._pose_L.transform.translation
            r = self._pose_L.transform.rotation
            lines.append(f"{C_CYAN}L pose{C_RESET} xyz=[{t.x:+.3f},{t.y:+.3f},{t.z:+.3f}]  "
                         f"q=[{r.x:+.3f},{r.y:+.3f},{r.z:+.3f},{r.w:+.3f}]")
        if self._pose_R:
            t = self._pose_R.transform.translation
            lines.append(f"{C_CYAN}R pose{C_RESET} xyz=[{t.x:+.3f},{t.y:+.3f},{t.z:+.3f}]")

        # recent warnings/errors
        if self._warn_err:
            lines.append(f"\n{C_BOLD}Recent:{C_RESET}")
            for w in self._warn_err[-5:]:
                lines.append(f"  {w}")

        if ctrl:
            lines.append(f"\n{C_BOLD}Controllers:{C_RESET}")
            for l in ctrl.strip().split("\n")[1:]:
                if not l.strip(): continue
                # parse: "name[type] state" → color by state
                for state, color in CTRL_COLORS.items():
                    if state in l:
                        # split into name[type] and state
                        name_part = l[:l.rfind("  ")].strip()
                        state_part = l[l.rfind("  "):].strip()
                        lines.append(f"  {color}{C_BOLD}{name_part}{C_RESET}  {color}{state_part}{C_RESET}")
                        break
                else:
                    lines.append(f"  {C_GRAY}{l}{C_RESET}")
        if self._last_cmd:
            lines.append(f"\n{C_DIM}{self._last_cmd}{C_RESET}")
        lines.append(f"\n{C_BOLD}xcmd>{C_RESET} ")
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
                    parts = line.split()
                    cmd = parts[0].lower() if parts else ""

                    try:
                        if line in ("q","quit","exit"): break
                        elif line == "l":
                            self._last_cmd = self._run(["ros2","control","list_controllers"])
                        elif cmd == "a" and len(parts)>=2:
                            self._last_cmd = self._run(["ros2","control","switch_controllers","--activate",parts[1]])
                        elif cmd == "d" and len(parts)>=2:
                            self._last_cmd = self._run(["ros2","control","switch_controllers","--deactivate",parts[1]])
                        elif cmd == "jl" and len(parts)==8:
                            angles = [float(x) for x in parts[1:]]
                            err = self._check(ARM_L, angles)
                            if err: self._last_cmd = err
                            else:
                                msg = Float64MultiArray(data=[float(a) for a in angles])
                                self._pub_L.publish(msg)
                                self._last_cmd = f"{C_GREEN}L Arm → {angles}{C_RESET}"
                        elif cmd == "jr" and len(parts)==8:
                            angles = [float(x) for x in parts[1:]]
                            err = self._check(ARM_R, angles)
                            if err: self._last_cmd = err
                            else:
                                msg = Float64MultiArray(data=[float(a) for a in angles])
                                self._pub_R.publish(msg)
                                self._last_cmd = f"{C_GREEN}R Arm → {angles}{C_RESET}"
                        elif cmd == "jd" and len(parts)==15:
                            angles = [float(x) for x in parts[1:]]
                            err = self._check(ARM_L+ARM_R, angles)
                            if err: self._last_cmd = err
                            else:
                                msg = Float64MultiArray(data=[float(a) for a in angles])
                                self._pub_D.publish(msg)
                                self._last_cmd = f"{C_GREEN}Dual → {angles}{C_RESET}"
                        elif cmd == "jb" and len(parts)==5:
                            angles = [float(x) for x in parts[1:]]
                            err = self._check(BODY, angles)
                            if err: self._last_cmd = err
                            else:
                                msg = Float64MultiArray(data=[float(a) for a in angles])
                                self._pub_B.publish(msg)
                                self._last_cmd = f"{C_GREEN}Body → {angles}{C_RESET}"
                        elif cmd == "jh" and len(parts)==4:
                            angles = [float(x) for x in parts[1:]]
                            err = self._check(HEAD, angles)
                            if err: self._last_cmd = err
                            else:
                                msg = Float64MultiArray(data=[float(a) for a in angles])
                                self._pub_H.publish(msg)
                                self._last_cmd = f"{C_GREEN}Head → {angles}{C_RESET}"
                        elif cmd == "arm" and len(parts)>=2:
                            val = "true" if parts[1]=="enable" else "false"
                            self._last_cmd = self._run(["ros2","service","call",
                                "/EAIHardware/set_arm_enable","std_srvs/srv/SetBool",f"{{data: {val}}}"])
                        elif cmd == "all" and len(parts)>=2:
                            val = "true" if parts[1]=="enable" else "false"
                            self._last_cmd = self._run(["ros2","service","call",
                                "/EAIHardware/set_all_enable","std_srvs/srv/SetBool",f"{{data: {val}}}"])
                        elif cmd == "mode" and len(parts)>=2:
                            m = int(parts[1])
                            if m in (0,1,2,3):
                                self._last_cmd = self._run(["ros2","service","call",
                                    "/EAIHardware/set_arm_mode","eai_manipulator_msgs/srv/Mode",f"{{mode: {m}}}"])
                            else:
                                self._last_cmd = f"{C_RED}mode 0-3 (0柔顺 1速度 2重力 3位置){C_RESET}"
                        elif cmd == "auto" and len(parts)>=2:
                            act = "enable" if parts[1] in ("on","enable","true") else "disable"
                            self._last_cmd = self._run(["ros2","control","auto_switch_mode",f"--{act}"])
                        elif cmd == "cl" and len(parts)==8:
                            if not HAS_EAI:
                                self._last_cmd = f"{C_RED}eai_manipulator_msgs not found — source XARM install{C_RESET}"
                            else:
                                x,y,z,qx,qy,qz,qw = [float(v) for v in parts[1:]]
                                msg = ArmTargetPose()
                                msg.header = Header(frame_id=self._frame)
                                msg.target = Pose(position=Point(x=x,y=y,z=z),
                                                  orientation=Quaternion(x=qx,y=qy,z=qz,w=qw))
                                msg.from_frame = self._frame
                                msg.to_frame = "left_tcp_link"
                                self._pub_cL.publish(msg)
                                self._last_cmd = f"{C_GREEN}L cart → [{x:.3f},{y:.3f},{z:.3f}] @ {self._frame}{C_RESET}"
                        elif cmd == "cr" and len(parts)==8:
                            if not HAS_EAI:
                                self._last_cmd = f"{C_RED}eai_manipulator_msgs not found — source XARM install{C_RESET}"
                            else:
                                x,y,z,qx,qy,qz,qw = [float(v) for v in parts[1:]]
                                msg = ArmTargetPose()
                                msg.header = Header(frame_id=self._frame)
                                msg.target = Pose(position=Point(x=x,y=y,z=z),
                                                  orientation=Quaternion(x=qx,y=qy,z=qz,w=qw))
                                msg.from_frame = self._frame
                                msg.to_frame = "right_tcp_link"
                                self._pub_cR.publish(msg)
                                self._last_cmd = f"{C_GREEN}R cart → [{x:.3f},{y:.3f},{z:.3f}] @ {self._frame}{C_RESET}"
                        elif cmd == "eb" and len(parts)==5:
                            x,z,pitch,yaw = [float(v) for v in parts[1:]]
                            msg = Float64MultiArray(data=[x,z,pitch,yaw])
                            self._pub_eb.publish(msg)
                            self._last_cmd = f"{C_GREEN}Body cart → [x={x:.3f},z={z:.3f},pitch={pitch:.3f},yaw={yaw:.3f}]{C_RESET}"
                        elif cmd == "frame" and len(parts)>=2:
                            self._frame = parts[1]
                            self._last_cmd = f"{C_GREEN}frame = {self._frame}{C_RESET}"
                        elif line in ("h","help","?"):
                            self._last_cmd = "jL/jR/jD/jB/jH | cL/cR xyz qxyzw | eb x z pitch yaw | frame <name> | a/d | arm/all enable|disable | mode 0-3 | auto on|off | q quit"
                        elif line == "":
                            self._last_cmd = ""
                        else:
                            self._last_cmd = f"{C_RED}? {line} — try 'h'{C_RESET}"
                    except Exception as e:
                        self._last_cmd = f"{C_RED}error: {e}{C_RESET}"

                    sys.stdout.write(self.render())
                    sys.stdout.flush()
        except (KeyboardInterrupt, EOFError):
            pass


def main():
    rclpy.init()
    node = XarmControlDebug()
    try:
        node.run()
    finally:
        node.destroy_node()
        try: rclpy.shutdown()
        except Exception: pass
        print(f"\n{C_DIM}xarmcontroldebug stopped.{C_RESET}")


if __name__ == "__main__":
    main()
