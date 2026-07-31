#!/usr/bin/env python3
"""Keyboard teleop — 6-DOF TCP 微调 + IK/规划/执行。

平移:  w/s  X前后   a/d  Y左右   q/e  Z上下
旋转:  i/k  绕X     j/l  绕Y     u/o  绕Z
步长:  t/T  平移±1cm  r/R  旋转±1°
动作:  空格  执行规划   c  重置为当前TCP   h  帮助   Esc  退出

需要 cable_tracker 在另一个终端运行（非 test_mode）。
"""

import sys
import tty
import termios
import select
import math
import time

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Point, Quaternion
import tf2_ros

from wire_connect_msgs.msg import ArmTarget

# ── defaults ──────────────────────────────────────────────────────────
STEP_LIN = 0.02    # metres
STEP_ROT = 5.0     # degrees


class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__("keyboard_teleop")

        self.declare_parameter("arm", "left")
        self.declare_parameter("frame", "waist_yaw_link")
        self.declare_parameter("step_lin", STEP_LIN)
        self.declare_parameter("step_rot", STEP_ROT)

        self._arm = self.get_parameter("arm").value
        self._frame = self.get_parameter("frame").value

        # TF
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # publisher → cable_tracker subscribes /vision/left_target
        self._pub = self.create_publisher(ArmTarget, f"/vision/{self._arm}_target", 10)

        # current target pose (initialised from TF)
        self._x, self._y, self._z = 0.0, 0.0, 0.0
        self._roll, self._pitch, self._yaw = 0.0, 0.0, 0.0

        self._step_lin = STEP_LIN
        self._step_rot = math.radians(STEP_ROT)

        self._print_help()
        self._last_display = ""
        # wait for TF and sync initial state
        self.get_logger().info("waiting for TF...")
        while rclpy.ok() and not self._sync_from_tf():
            rclpy.spin_once(self, timeout_sec=0.5)
        self._print_state()
        # live status refresh every 0.3s
        self.create_timer(0.3, lambda: self._print_state())

    # ── TF ──────────────────────────────────────────────────────────
    def _sync_from_tf(self) -> bool:
        try:
            t = self._tf_buf.lookup_transform(
                self._frame, f"{self._arm}_tcp_link", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.5))
            self._x = t.transform.translation.x
            self._y = t.transform.translation.y
            self._z = t.transform.translation.z
            # decompose rotation → RPY
            q = t.transform.rotation
            self._roll, self._pitch, self._yaw = _quat_to_rpy(q.x, q.y, q.z, q.w)
            self.get_logger().info(f"synced TCP: pos=[{self._x:.3f},{self._y:.3f},{self._z:.3f}]  "
                                   f"rpy=[{math.degrees(self._roll):.0f},{math.degrees(self._pitch):.0f},{math.degrees(self._yaw):.0f}]°")
            return True
        except Exception as e:
            self.get_logger().debug(f"TF lookup failed: {e}")
            return False

    # ── execute ─────────────────────────────────────────────────────
    def _execute(self):
        """Publish ArmTarget for cable_tracker to consume."""
        sys.stdout.write("\n")  # newline before ROS log output
        sys.stdout.flush()
        msg = ArmTarget()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._frame
        msg.arm = self._arm
        msg.pose = Pose(
            position=Point(x=self._x, y=self._y, z=self._z),
            orientation=_rpy_to_quat(self._roll, self._pitch, self._yaw),
        )
        msg.cable_yaw = self._yaw
        msg.cable_z = self._z
        msg.plug_id = -1  # keyboard target
        self._pub.publish(msg)
        self.get_logger().info(
            f"→ sent target pos=[{self._x:.3f},{self._y:.3f},{self._z:.3f}]  "
            f"rpy=[{math.degrees(self._roll):.0f},{math.degrees(self._pitch):.0f},{math.degrees(self._yaw):.0f}]°")

    def _print_state(self):
        roll_d = math.degrees(self._roll)
        pitch_d = math.degrees(self._pitch)
        yaw_d = math.degrees(self._yaw)
        q = _rpy_to_quat(self._roll, self._pitch, self._yaw)
        line = (f"\r  POS [{self._x:+.3f} {self._y:+.3f} {self._z:+.3f}] m  "
                f"RPY [R:{roll_d:+6.1f} P:{pitch_d:+6.1f} Y:{yaw_d:+6.1f}]°  "
                f"QUAT [x:{q.x:+.3f} y:{q.y:+.3f} z:{q.z:+.3f} w:{q.w:+.3f}]  "
                f"step:{self._step_lin*100:.0f}cm/{math.degrees(self._step_rot):.0f}°  ")
        # only re-print if changed (avoid spam)
        if line != self._last_display:
            sys.stdout.write(line)
            sys.stdout.flush()
            self._last_display = line

    @staticmethod
    def _print_help():
        print("\n┌─────────────────────────────────────────────┐")
        print("│  平移: w/s X  a/d Y  q/e Z                   │")
        print("│  旋转: i/k 绕X  j/l 绕Y  u/o 绕Z            │")
        print("│  步长: t/T  平移±1cm  r/R  旋转±1°          │")
        print("│  动作: [空格] 执行  c 重置TCP  h 帮助  Esc 退出 │")
        print("└─────────────────────────────────────────────┘\n")

    # ── key handler ─────────────────────────────────────────────────
    def handle_key(self, key: str):
        if key == ' ':
            self._execute()
        elif key == 'c':
            self._sync_from_tf()
            self._print_state()
        elif key == 'h':
            self._print_help()
        elif key == 'p':
            self._print_state()
        elif key == 't':
            self._step_lin = max(0.005, self._step_lin + 0.01)
            self._print_state()
        elif key == 'T':
            self._step_lin = max(0.005, self._step_lin - 0.01)
            self._print_state()
        elif key == 'r':
            self._step_rot = max(math.radians(1), self._step_rot + math.radians(1))
            self._print_state()
        elif key == 'R':
            self._step_rot = max(math.radians(1), self._step_rot - math.radians(1))
            self._print_state()
        else:
            self._adjust(key)

    def _adjust(self, key: str):
        """Apply translation or rotation step."""
        # translation (world axes)
        d = self._step_lin
        if key == 'w':
            self._x += d
        elif key == 's':
            self._x -= d
        elif key == 'a':
            self._y += d
        elif key == 'd':
            self._y -= d
        elif key == 'q':
            self._z += d
        elif key == 'e':
            self._z -= d
        # rotation around world axes
        elif key == 'i':
            self._roll += self._step_rot
        elif key == 'k':
            self._roll -= self._step_rot
        elif key == 'j':
            self._pitch += self._step_rot
        elif key == 'l':
            self._pitch -= self._step_rot
        elif key == 'u':
            self._yaw += self._step_rot
        elif key == 'o':
            self._yaw -= self._step_rot
        else:
            return
        self._print_state()


# ── quaternion helpers ────────────────────────────────────────────────

def _quat_to_rpy(x, y, z, w):
    """Quaternion → roll, pitch, yaw (radians, intrinsic ZYX)."""
    sinr_cosp = 2.0 * (w * x + y * z)
    cosr_cosp = 1.0 - 2.0 * (x * x + y * y)
    roll = math.atan2(sinr_cosp, cosr_cosp)
    sinp = 2.0 * (w * y - z * x)
    if abs(sinp) >= 1.0:
        pitch = math.copysign(math.pi / 2.0, sinp)
    else:
        pitch = math.asin(sinp)
    siny_cosp = 2.0 * (w * z + x * y)
    cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
    yaw = math.atan2(siny_cosp, cosy_cosp)
    return roll, pitch, yaw


def _rpy_to_quat(roll, pitch, yaw):
    """RPY (radians) → Quaternion (intrinsic ZYX)."""
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)
    return Quaternion(
        x=sr * cp * cy - cr * sp * sy,
        y=cr * sp * cy + sr * cp * sy,
        z=cr * cp * sy - sr * sp * cy,
        w=cr * cp * cy + sr * sp * sy,
    )


# ── non-blocking keyboard ─────────────────────────────────────────────

def get_key():
    """Non-blocking read of a single character. Returns '' if no key pressed."""
    if select.select([sys.stdin], [], [], 0.0)[0]:
        return sys.stdin.read(1)
    return ''


# ── main ──────────────────────────────────────────────────────────────

def main():
    rclpy.init()
    node = KeyboardTeleop()

    # save terminal settings
    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    tty.setcbreak(fd)

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.01)
            key = get_key()
            if key == '\x1b':  # Esc
                print("\nexit.")
                break
            if key:
                node.handle_key(key)
    except KeyboardInterrupt:
        pass
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
