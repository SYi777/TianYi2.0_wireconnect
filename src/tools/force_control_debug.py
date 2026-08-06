#!/usr/bin/env python3
"""左臂纯 Z 轴力控调试器（独立于 competition.py）。

默认只监控，不发送电机命令：
    python3 force_control_debug.py

允许实际运动：
    python3 force_control_debug.py --execute

控制：
    Space  启用/暂停力控
    q      停止并沿已执行关节路径退回起点
    Ctrl+C 同 q；再次 Ctrl+C 立即中止退回
"""

import argparse
import csv
import json
import math
import os
import select
import signal
import sys
import termios
import threading
import time
import tty
from collections import deque

import rclpy
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
from geometry_msgs.msg import Point, Pose, Quaternion, WrenchStamped
from moveit_msgs.msg import RobotState
from moveit_msgs.srv import GetCartesianPath
from rclpy.node import Node
from sensor_msgs.msg import JointState


SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
DEFAULT_CALIBRATION = os.path.join(SCRIPT_DIR, "force_axis_cal.json")
DEFAULT_LOG_DIR = os.path.expanduser("~/WireConnect_ws/log")

MOTOR_LEFT = [11, 12, 13, 14, 15, 16, 17]
ARM_J_L = [
    "shoulder_pitch_l_joint", "shoulder_roll_l_joint",
    "shoulder_yaw_l_joint", "elbow_pitch_l_joint",
    "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint",
]
JOINT_LIMITS_L = [
    (-2.96, 2.96), (-0.262, 2.616), (-2.96, 2.96), (-2.61, 0.261),
    (-2.96, 2.96), (-0.785, 1.05), (-1.65, 1.3),
]
CUR_L = [20.0, 15.0, 6.0, 6.0, 6.0, 4.0, 4.0]
SPD_FORCE = 3.0

CONTROL_HZ = 20.0
FILTER_SAMPLES = 5
CART_MAX_STEP = 0.001
CART_MIN_FRACTION = 0.99
CART_JUMP_THRESHOLD = 1.5
MAX_JOINT_STEP = math.radians(10.0)
FORCE_STALE_SEC = 0.1


def clamp(value, lo, hi):
    return max(lo, min(hi, value))


def clamp_joints(joints):
    return [
        clamp(float(joints[i]), JOINT_LIMITS_L[i][0], JOINT_LIMITS_L[i][1])
        for i in range(7)
    ]


def joints_diff(a, b):
    return max(abs(a[i] - b[i]) for i in range(7))


def normalize(vector):
    norm = math.sqrt(sum(value * value for value in vector))
    if norm < 1e-9:
        raise ValueError("标定轴向量长度为0")
    return [value / norm for value in vector]


def nearest_equivalent(joints, seed):
    result = []
    for i, value in enumerate(joints):
        lo, hi = JOINT_LIMITS_L[i]
        options = [
            value + turns * 2.0 * math.pi
            for turns in (-1, 0, 1)
            if lo <= value + turns * 2.0 * math.pi <= hi
        ]
        if not options:
            return None
        result.append(min(options, key=lambda candidate: abs(candidate - seed[i])))
    return result


def validate_joint_path(path, seed):
    validated = []
    previous = list(seed)
    for joints in path:
        joints = nearest_equivalent(joints, previous)
        if joints is None or joints_diff(joints, previous) > MAX_JOINT_STEP:
            return None
        joints = clamp_joints(joints)
        validated.append(joints)
        previous = joints
    return validated


class ForceControlNode(Node):
    def __init__(self):
        super().__init__("force_control_debug")
        self._lock = threading.Lock()
        self._forces = deque(maxlen=200)
        self._force_at = 0.0
        self._left_joints = None
        self._joints_at = 0.0

        self.create_subscription(
            WrenchStamped, "/arm_6dof_left", self._force_cb, 100)
        self.create_subscription(
            JointState, "/joint_states", self._joint_cb, 20)
        self._pub = self.create_publisher(
            CmdSetMotorPosition, "/arm/cmd_pos", 10)
        self._cartesian = self.create_client(
            GetCartesianPath, "/compute_cartesian_path")

        import tf2_ros
        self._tf_buffer = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(
            self._tf_buffer, self)

    def _force_cb(self, msg):
        force = msg.wrench.force
        with self._lock:
            self._forces.append((
                float(force.x), float(force.y), float(force.z)))
            self._force_at = time.monotonic()

    def _joint_cb(self, msg):
        values = dict(zip(msg.name, msg.position))
        if all(name in values for name in ARM_J_L):
            with self._lock:
                self._left_joints = [
                    float(values[name]) for name in ARM_J_L]
                self._joints_at = time.monotonic()

    def force_fresh(self):
        with self._lock:
            return (
                bool(self._forces) and
                time.monotonic() - self._force_at <= FORCE_STALE_SEC)

    def filtered_force(self, count=FILTER_SAMPLES):
        with self._lock:
            if not self._forces:
                return None
            samples = list(self._forces)[-count:]
        return [
            sum(sample[i] for sample in samples) / len(samples)
            for i in range(3)
        ]

    def get_left_joints(self, max_age=1.0):
        with self._lock:
            if (
                self._left_joints is None or
                time.monotonic() - self._joints_at > max_age
            ):
                return None
            return list(self._left_joints)

    def get_tcp(self):
        try:
            transform = self._tf_buffer.lookup_transform(
                "waist_yaw_link", "left_tcp_link", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.3))
            translation = transform.transform.translation
            rotation = transform.transform.rotation
            return [
                translation.x, translation.y, translation.z,
                rotation.x, rotation.y, rotation.z, rotation.w,
            ]
        except Exception:
            return None

    def sample_baseline(self, duration=0.5):
        with self._lock:
            self._forces.clear()
        deadline = time.monotonic() + duration
        while time.monotonic() < deadline:
            time.sleep(0.01)
        with self._lock:
            samples = list(self._forces)
        if len(samples) < 20:
            return None, None
        mean = [
            sum(sample[i] for sample in samples) / len(samples)
            for i in range(3)
        ]
        std = [
            math.sqrt(
                sum((sample[i] - mean[i]) ** 2 for sample in samples)
                / len(samples))
            for i in range(3)
        ]
        return mean, std

    def send_left(self, joints):
        joints = clamp_joints(joints)
        msg = CmdSetMotorPosition()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.cmds = [
            SetMotorPosition(
                name=motor, pos=joints[i], spd=SPD_FORCE, cur=CUR_L[i])
            for i, motor in enumerate(MOTOR_LEFT)
        ]
        self._pub.publish(msg)

    def cartesian_path(self, position, orientation, seed):
        if not self._cartesian.wait_for_service(timeout_sec=0.2):
            return None, 0.0
        request = GetCartesianPath.Request()
        request.header.frame_id = "waist_yaw_link"
        request.header.stamp = self.get_clock().now().to_msg()
        request.start_state = RobotState(is_diff=True)
        request.start_state.joint_state.name = list(ARM_J_L)
        request.start_state.joint_state.position = list(seed)
        request.group_name = "left_arm"
        request.link_name = "left_tcp_link"
        request.waypoints = [Pose(
            position=Point(
                x=position[0], y=position[1], z=position[2]),
            orientation=Quaternion(
                x=orientation[0], y=orientation[1],
                z=orientation[2], w=orientation[3]),
        )]
        request.max_step = CART_MAX_STEP
        request.jump_threshold = CART_JUMP_THRESHOLD
        request.avoid_collisions = True

        future = self._cartesian.call_async(request)
        deadline = time.monotonic() + 1.0
        while rclpy.ok() and not future.done() and time.monotonic() < deadline:
            time.sleep(0.002)
        if not future.done():
            return None, 0.0
        result = future.result()
        if result is None or result.error_code.val != 1:
            return None, float(result.fraction) if result else 0.0

        trajectory = result.solution.joint_trajectory
        names = list(trajectory.joint_names)
        if (
            not trajectory.points or
            not all(name in names for name in ARM_J_L)
        ):
            return None, float(result.fraction)
        indexes = [names.index(name) for name in ARM_J_L]
        path = [
            [float(point.positions[index]) for index in indexes]
            for point in trajectory.points
        ]
        return validate_joint_path(path, seed), float(result.fraction)


class ForceController:
    def __init__(self, node, axis, baseline, args):
        self.node = node
        self.axis = normalize(axis)
        self.baseline = list(baseline)
        self.args = args

        tcp = node.get_tcp()
        joints = node.get_left_joints(max_age=2.0)
        if tcp is None:
            raise RuntimeError(
                "无法获取 waist_yaw_link → left_tcp_link TF")
        if joints is None:
            raise RuntimeError("无法获取左臂 /joint_states")

        self.start_position = list(tcp[:3])
        self.target_position = list(tcp[:3])
        self.orientation = normalize(tcp[3:7])
        self.start_joints = clamp_joints(joints)
        self.last_joints = list(self.start_joints)
        self.history = [list(self.start_joints)]

        self.enabled = False
        self.state = "PAUSED"
        self.contact_frames = 0
        self.last_fraction = 1.0
        self.fault_reason = None
        self.retracted = False

    def measurement(self):
        force = self.node.filtered_force()
        if force is None:
            return None
        delta = [force[i] - self.baseline[i] for i in range(3)]
        axial = sum(delta[i] * self.axis[i] for i in range(3))
        total = math.sqrt(sum(value * value for value in delta))
        lateral = math.sqrt(max(0.0, total * total - axial * axial))
        return force, delta, axial, total, lateral

    def set_enabled(self, enabled):
        if self.fault_reason:
            return
        self.enabled = enabled
        if enabled:
            self.state = "APPROACH"
            self.contact_frames = 0
        else:
            self.state = "PAUSED"

    def _fault(self, reason):
        self.enabled = False
        self.state = "FAULT"
        self.fault_reason = reason

    def _move_z(self, dz):
        next_z = clamp(
            self.target_position[2] + dz,
            self.start_position[2] - self.args.max_descent,
            self.start_position[2])
        if abs(next_z - self.target_position[2]) < 1e-7:
            return True

        candidate = [
            self.start_position[0], self.start_position[1], next_z]
        path, fraction = self.node.cartesian_path(
            candidate, self.orientation, self.last_joints)
        self.last_fraction = fraction
        if path is None or fraction < CART_MIN_FRACTION:
            self._fault(f"Cartesian路径失败 fraction={fraction:.3f}")
            return False

        for joints in path:
            self.node.send_left(joints)
            time.sleep(0.005)
        self.last_joints = list(path[-1])
        if joints_diff(self.history[-1], self.last_joints) > 1e-4:
            self.history.append(list(self.last_joints))
        self.target_position = candidate
        return True

    def update(self):
        measurement = self.measurement()
        if measurement is None or not self.node.force_fresh():
            self._fault("六维力数据超时")
            return None

        _, _, axial, total, lateral = measurement
        if total >= self.args.hard_stop:
            self._fault(f"|ΔF|={total:.2f}N 超过硬停阈值")
            return measurement
        if lateral >= self.args.lateral_stop:
            self._fault(f"横向力={lateral:.2f}N 超过阈值")
            return measurement
        if not self.enabled:
            return measurement

        if self.state == "APPROACH":
            if axial >= self.args.contact:
                self.contact_frames += 1
            else:
                self.contact_frames = 0
            if self.contact_frames >= self.args.contact_frames:
                self.state = "FORCE"
            else:
                if self.descent >= self.args.max_descent - 1e-6:
                    self._fault(
                        f"已达到最大下降 {self.descent*1000:.1f}mm，"
                        "仍未检测到接触")
                    return measurement
                self._move_z(-self.args.max_speed / CONTROL_HZ)
                return measurement

        if self.state == "FORCE":
            error = self.args.target_force - axial
            if abs(error) <= self.args.force_deadband:
                return measurement
            dz = -clamp(
                self.args.force_gain * error,
                -self.args.max_speed / CONTROL_HZ,
                self.args.max_speed / CONTROL_HZ)
            self._move_z(dz)

        descent = self.start_position[2] - self.target_position[2]
        if (
            descent >= self.args.max_descent - 1e-6 and
            axial < self.args.target_force
        ):
            self._fault(
                f"已达到最大下降 {descent*1000:.1f}mm，仍未建立目标力")
        return measurement

    def retract(self):
        if self.retracted or len(self.history) <= 1:
            return
        self.enabled = False
        print(f"\n↩ 沿 {len(self.history)} 个关节目标原路退回...")
        for joints in reversed(self.history[:-1]):
            self.node.send_left(joints)
            time.sleep(0.02)
        self.node.send_left(self.start_joints)
        self.retracted = True
        print("✅ 已退回力控起点")

    @property
    def descent(self):
        return self.start_position[2] - self.target_position[2]


def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--calibration", default=DEFAULT_CALIBRATION,
        help="force_axis_cal.json 路径")
    parser.add_argument(
        "--execute", action="store_true",
        help="允许发送真实机械臂命令；不加时仅监控")
    parser.add_argument("--target-force", type=float, default=1.2)
    parser.add_argument("--contact", type=float, default=0.8)
    parser.add_argument("--hard-stop", type=float, default=4.0)
    parser.add_argument("--lateral-stop", type=float, default=3.0)
    parser.add_argument("--max-descent", type=float, default=0.008)
    parser.add_argument("--max-speed", type=float, default=0.002)
    parser.add_argument("--force-gain", type=float, default=0.0001)
    parser.add_argument("--force-deadband", type=float, default=0.1)
    parser.add_argument("--contact-frames", type=int, default=5)
    parser.add_argument("--log-dir", default=DEFAULT_LOG_DIR)
    return parser.parse_args()


def load_axis(filename):
    with open(filename) as file:
        data = json.load(file)
    axis = normalize([float(value) for value in data["u"]])
    return axis, data


def wait_for_ready(node, timeout=10.0):
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        force_ok = node.force_fresh()
        joints_ok = node.get_left_joints(max_age=1.0) is not None
        tf_ok = node.get_tcp() is not None
        service_ok = node._cartesian.service_is_ready()
        if force_ok and joints_ok and tf_ok and service_ok:
            return True
        time.sleep(0.1)
    return False


def print_status(controller, measurement):
    if measurement is None:
        return
    _, _, axial, total, lateral = measurement
    enabled = "RUN" if controller.enabled else "STOP"
    text = (
        f"\r[{enabled:4s}] {controller.state:8s}  "
        f"F_axial={axial:+5.2f}N  |ΔF|={total:5.2f}N  "
        f"F_side={lateral:5.2f}N  "
        f"Z={controller.descent*1000:5.2f}mm  "
        f"fraction={controller.last_fraction:.3f}   ")
    print(text, end="", flush=True)


def run_control(controller, csv_writer, execute):
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    tty.setcbreak(fd)
    last_print = 0.0
    try:
        while rclpy.ok():
            started = time.monotonic()
            if select.select([sys.stdin], [], [], 0.0)[0]:
                key = sys.stdin.read(1)
                if key == "q":
                    break
                if key == " ":
                    if not execute:
                        print("\n⚠ 当前是监控模式；实际运动请加 --execute")
                    else:
                        controller.set_enabled(not controller.enabled)

            measurement = controller.update()
            if measurement:
                force, delta, axial, total, lateral = measurement
                csv_writer.writerow([
                    time.time(), controller.state, int(controller.enabled),
                    *force, *delta, axial, total, lateral,
                    controller.descent, controller.last_fraction,
                ])

            now = time.monotonic()
            if now - last_print >= 0.1:
                print_status(controller, measurement)
                last_print = now

            if controller.fault_reason:
                print(f"\n⛔ {controller.fault_reason}")
                break
            elapsed = time.monotonic() - started
            time.sleep(max(0.0, 1.0 / CONTROL_HZ - elapsed))
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)


def main():
    args = parse_args()
    axis, calibration = load_axis(args.calibration)
    print(
        "加载轴向 u = "
        f"[{axis[0]:+.4f}, {axis[1]:+.4f}, {axis[2]:+.4f}]")
    print(
        f"标定推力 |ΔF|={float(calibration.get('delta_mag', 0.0)):.2f}N")
    print("⚠ 请确保 competition.py、普通遥操和关节控制器没有抢占左臂")
    print("模式：真实执行" if args.execute else "模式：仅监控（不会运动）")

    from rclpy.executors import SingleThreadedExecutor
    from rclpy.signals import SignalHandlerOptions
    rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    signal.signal(signal.SIGINT, signal.default_int_handler)
    node = ForceControlNode()
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()

    controller = None
    csv_file = None
    try:
        print("⏳ 等待力、关节、TF和 /compute_cartesian_path ...")
        if not wait_for_ready(node):
            raise RuntimeError(
                "依赖未就绪；检查 /joint_states、RSP、move_group 和 TF")
        input("保持预插入姿态静止，按 Enter 采集当前基线 F₀...")
        baseline, std = node.sample_baseline(0.5)
        if baseline is None:
            raise RuntimeError("基线采样不足")
        if max(std) > 0.5:
            raise RuntimeError(
                f"基线不稳定 σ={[round(value, 3) for value in std]}")
        print(
            f"F₀=[{baseline[0]:+.2f},{baseline[1]:+.2f},"
            f"{baseline[2]:+.2f}]N  "
            f"σ=[{std[0]:.2f},{std[1]:.2f},{std[2]:.2f}]")

        controller = ForceController(node, axis, baseline, args)
        os.makedirs(args.log_dir, exist_ok=True)
        log_path = os.path.join(
            args.log_dir,
            time.strftime("force_control_%Y%m%d_%H%M%S.csv"))
        csv_file = open(log_path, "w", newline="")
        writer = csv.writer(csv_file)
        writer.writerow([
            "time", "state", "enabled",
            "fx", "fy", "fz", "dfx", "dfy", "dfz",
            "f_axial", "f_total", "f_lateral",
            "z_descent_m", "cartesian_fraction",
        ])
        print(f"日志: {log_path}")
        print("Space=启用/暂停  q/Ctrl+C=停止并原路退回")
        run_control(controller, writer, args.execute)
    except KeyboardInterrupt:
        print("\n⚠ 收到Ctrl+C，准备原路退回；再次Ctrl+C立即中止")
    except Exception as error:
        print(f"\n❌ {error}")
    finally:
        if controller is not None:
            try:
                controller.retract()
            except KeyboardInterrupt:
                print("\n⛔ 原路退回被用户中止")
        if csv_file is not None:
            csv_file.close()
        executor.shutdown()
        node.destroy_node()
        rclpy.try_shutdown()
        print("已退出")


if __name__ == "__main__":
    main()
