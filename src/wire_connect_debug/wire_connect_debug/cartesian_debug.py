#!/usr/bin/env python3
"""cartesian_debug — 笛卡尔直线插值调试工具。

功能:
  - 按键设定目标 TCP 位姿 (6-DOF)
  - [空格] 调用 /compute_cartesian_path（直线插值 + 每1cm做碰撞检测）
  - 显示 fraction (完成度), 轨迹点数, 是否有碰撞
  - [Enter] 在机器人上执行
  - [t] 切换到 OMPL test_mode 对比

依赖: move_group 已启动 (提供 /compute_cartesian_path 服务)

平移:  w/s X前后  a/d Y左右  q/e Z上下
旋转:  i/k 绕X    j/l 绕Y    u/o 绕Z
步长:  r/R  平移±1cm  f/F  旋转±1°
动作:  [空格] 笛卡尔规划  [Enter] 执行  [c] 重置  [h] 帮助  [Esc] 退出
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
from moveit_msgs.srv import GetCartesianPath
from moveit_msgs.msg import RobotState, Constraints
from std_msgs.msg import Header, Float64MultiArray
import tf2_ros


STEP_LIN = 0.02
STEP_ROT = 5.0
CART_MAX_STEP = 0.01  # 1cm interpolation step


class CartesianDebug(Node):
    def __init__(self):
        super().__init__("cartesian_debug")

        self.declare_parameter("arm", "left")
        self.declare_parameter("frame", "waist_yaw_link")
        self.declare_parameter("step_lin", STEP_LIN)
        self.declare_parameter("step_rot", STEP_ROT)
        self.declare_parameter("cart_max_step", CART_MAX_STEP)

        self._arm = self.get_parameter("arm").value
        self._frame = self.get_parameter("frame").value

        # TF
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # Cartesian path client
        self._cart_client = self.create_client(GetCartesianPath, "/compute_cartesian_path")

        # joint publisher (execution)
        topic = f"/jointspace_commands_{'L' if self._arm == 'left' else 'R'}"
        self._joint_pub = self.create_publisher(Float64MultiArray, topic, 10)

        # target pose (init from TF)
        self._x, self._y, self._z = 0.0, 0.0, 0.0
        self._roll, self._pitch, self._yaw = 0.0, 0.0, 0.0
        self._step_lin = STEP_LIN
        self._step_rot = math.radians(STEP_ROT)

        # last plan result
        self._plan_fraction = 0.0
        self._plan_pts = 0
        self._plan_traj = None
        self._plan_msg = ""

        self._print_help()
        # wait for TF and sync initial state
        while rclpy.ok() and not self._sync_from_tf():
            self.get_logger().info("waiting for TF...", throttle_duration_sec=2.0)
            rclpy.spin_once(self, timeout_sec=0.5)
        self._print_state()

    # ── TF ──────────────────────────────────────────────────────────
    def _sync_from_tf(self) -> bool:
        try:
            t = self._tf_buf.lookup_transform(
                self._frame, f"{self._arm}_tcp_link", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.5))
            self._x = t.transform.translation.x
            self._y = t.transform.translation.y
            self._z = t.transform.translation.z
            q = t.transform.rotation
            self._roll, self._pitch, self._yaw = _quat_to_rpy(q.x, q.y, q.z, q.w)
            self.get_logger().info(
                f"synced TCP: [{self._x:.3f},{self._y:.3f},{self._z:.3f}]  "
                f"rpy=[{math.degrees(self._roll):.0f},{math.degrees(self._pitch):.0f},{math.degrees(self._yaw):.0f}]°")
            return True
        except Exception as e:
            self.get_logger().debug(f"TF lookup failed: {e}")
            return False

    # ── Cartesian planning ──────────────────────────────────────────
    def _plan(self):
        tcp = self._get_tcp_pose()
        if tcp is None:
            self._plan_msg = "TF 获取失败"
            return

        goal = Pose(
            position=Point(x=self._x, y=self._y, z=self._z),
            orientation=_rpy_to_quat(self._roll, self._pitch, self._yaw),
        )

        req = GetCartesianPath.Request()
        req.header = Header(frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        req.start_state = RobotState(is_diff=True)
        req.group_name = f"{self._arm}_arm"
        req.link_name = f"{self._arm}_tcp_link"
        req.waypoints = [tcp, goal]
        req.max_step = self.get_parameter("cart_max_step").value
        req.jump_threshold = 1.5
        req.avoid_collisions = True
        req.path_constraints = Constraints()

        self.get_logger().info(f"planning... [{self._x:.3f},{self._y:.3f},{self._z:.3f}]")

        if not self._cart_client.wait_for_service(timeout_sec=3.0):
            self._plan_msg = "服务 /compute_cartesian_path 不可达"
            return

        future = self._cart_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)

        if not future.done():
            self._plan_msg = "规划超时"
            return

        result = future.result()
        if result is None:
            self._plan_msg = "服务返回空"
            return

        self._plan_fraction = result.fraction
        self._plan_traj = result.solution.joint_trajectory
        self._plan_pts = len(self._plan_traj.points) if self._plan_traj else 0

        if result.error_code.val == 1 and result.fraction >= 0.99:
            self._plan_msg = (f"\033[32mOK\033[0m  fraction=1.000  "
                              f"{self._plan_pts} pts  (无碰,可达)")
        elif result.error_code.val == 1 and result.fraction > 0:
            self._plan_msg = (f"\033[33mPARTIAL\033[0m  fraction={result.fraction:.3f}  "
                              f"{self._plan_pts} pts  (中途碰撞或IK失败)")
        else:
            self._plan_msg = (f"\033[31mFAIL\033[0m  code={result.error_code.val}  "
                              f"fraction={result.fraction:.3f}")

        self.get_logger().info(self._plan_msg.replace("\033[32m","").replace("\033[0m","")
                               .replace("\033[33m","").replace("\033[31m","").replace("\033[0m",""))

    def _get_tcp_pose(self):
        try:
            t = self._tf_buf.lookup_transform(
                self._frame, f"{self._arm}_tcp_link", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.5))
            return Pose(
                position=Point(x=t.transform.translation.x,
                               y=t.transform.translation.y,
                               z=t.transform.translation.z),
                orientation=t.transform.rotation,
            )
        except Exception:
            return None

    # ── execution ───────────────────────────────────────────────────
    def _execute(self):
        if self._plan_traj is None or self._plan_pts == 0:
            self._plan_msg = "没有可执行的轨迹 — 先按空格规划"
            return

        pts = self._plan_traj.points
        self.get_logger().info(f"executing {len(pts)} points...")
        t_prev = 0.0
        for pt in pts:
            msg = Float64MultiArray(data=list(pt.positions[:7]))
            self._joint_pub.publish(msg)
            t_cur = pt.time_from_start.sec + pt.time_from_start.nanosec * 1e-9
            dt = max(t_cur - t_prev, 0.01)
            time.sleep(dt)
            t_prev = t_cur
        self._plan_msg = "\033[32m执行完成\033[0m"
        self.get_logger().info("execution done")

    # ── display ─────────────────────────────────────────────────────
    def _print_state(self):
        roll_d = math.degrees(self._roll)
        pitch_d = math.degrees(self._pitch)
        yaw_d = math.degrees(self._yaw)
        q = _rpy_to_quat(self._roll, self._pitch, self._yaw)

        dist = math.sqrt(
            (self._x - (self._get_tcp_pose().position.x if self._get_tcp_pose() else 0))**2 +
            (self._y - (self._get_tcp_pose().position.y if self._get_tcp_pose() else 0))**2 +
            (self._z - (self._get_tcp_pose().position.z if self._get_tcp_pose() else 0))**2
        ) if self._get_tcp_pose() else 0

        sys.stdout.write(
            f"\r  TARGET [{self._x:+.3f} {self._y:+.3f} {self._z:+.3f}] m  "
            f"RPY [R:{roll_d:+6.1f} P:{pitch_d:+6.1f} Y:{yaw_d:+6.1f}]°  "
            f"Δ={dist:.3f}m  step:{self._step_lin*100:.0f}cm/{math.degrees(self._step_rot):.0f}°  "
            f"plan: {self._plan_msg}" + " " * 20)
        sys.stdout.flush()

    @staticmethod
    def _print_help():
        print("""
┌──────────────────────────────────────────────────────┐
│  Cartesian Debug — 笛卡尔直线插值 + 碰撞检测            │
│                                                      │
│  平移: w/s X前后  a/d Y左右  q/e Z上下                 │
│  旋转: i/k 绕X    j/l 绕Y    u/o 绕Z                  │
│  步长: r/R  平移±1cm  f/F  旋转±1°                    │
│                                                      │
│  [空格] 笛卡尔规划 (直线插值 + 碰撞检测)                 │
│  [Enter] 在机器人上执行                                │
│  [c]     重置为当前 TCP                               │
│  [h]     帮助  [Esc] 退出                             │
└──────────────────────────────────────────────────────┘
""")

    # ── key handler ─────────────────────────────────────────────────
    def handle_key(self, key: str):
        if key == ' ':
            self._plan()
        elif key == '\r' or key == '\n':
            self._execute()
        elif key == 'c':
            self._sync_from_tf()
        elif key == 'h':
            self._print_help()
        elif key == 'r':
            self._step_lin = max(0.005, self._step_lin + 0.01)
        elif key == 'R':
            self._step_lin = max(0.005, self._step_lin - 0.01)
        elif key == 'f':
            self._step_rot = max(math.radians(1), self._step_rot + math.radians(1))
        elif key == 'F':
            self._step_rot = max(math.radians(1), self._step_rot - math.radians(1))
        else:
            d = self._step_lin
            if key == 'w':    self._x += d
            elif key == 's':  self._x -= d
            elif key == 'a':  self._y += d
            elif key == 'd':  self._y -= d
            elif key == 'q':  self._z += d
            elif key == 'e':  self._z -= d
            elif key == 'i':  self._roll += self._step_rot
            elif key == 'k':  self._roll -= self._step_rot
            elif key == 'j':  self._pitch += self._step_rot
            elif key == 'l':  self._pitch -= self._step_rot
            elif key == 'u':  self._yaw += self._step_rot
            elif key == 'o':  self._yaw -= self._step_rot
        self._print_state()


# ── quaternion helpers ────────────────────────────────────────────────

def _quat_to_rpy(x, y, z, w):
    sinr_cosp = 2.0 * (w * x + y * z)
    cosr_cosp = 1.0 - 2.0 * (x * x + y * y)
    roll = math.atan2(sinr_cosp, cosr_cosp)
    sinp = 2.0 * (w * y - z * x)
    pitch = math.asin(max(-1.0, min(1.0, sinp)))
    siny_cosp = 2.0 * (w * z + x * y)
    cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
    yaw = math.atan2(siny_cosp, cosy_cosp)
    return roll, pitch, yaw


def _rpy_to_quat(roll, pitch, yaw):
    cy = math.cos(yaw * 0.5); sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5); sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5); sr = math.sin(roll * 0.5)
    return Quaternion(
        x=sr * cp * cy - cr * sp * sy,
        y=cr * sp * cy + sr * cp * sy,
        z=cr * cp * sy - sr * sp * cy,
        w=cr * cp * cy + sr * sp * sy,
    )


# ── non-blocking keyboard ─────────────────────────────────────────────

def get_key():
    if select.select([sys.stdin], [], [], 0.0)[0]:
        return sys.stdin.read(1)
    return ''


# ── main ──────────────────────────────────────────────────────────────

def main():
    rclpy.init()
    node = CartesianDebug()

    fd = sys.stdin.fileno()
    old = termios.tcgetattr(fd)
    tty.setcbreak(fd)

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
            key = get_key()
            if key == '\x1b':
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
