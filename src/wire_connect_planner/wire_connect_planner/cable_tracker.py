#!/usr/bin/env python3
"""cable_tracker — 两段式规划 + 执行 + 遮挡保护。

Pipeline:
  1. ArmTarget 进来 → 算 approach_pose (上方10cm) + grasp_pose (目标位置)
  2. 第一段 OMPL:  当前 TCP → approach_pose  (绕开障碍物)
  3. 第二段 Cartesian: approach_pose → grasp_pose  (直线下插，碰撞检测)

  短距离(<5cm): 跳过 OMPL，直接 Cartesian
  test_mode:     当前 TCP → z+10cm，仅 Cartesian
  keyboard 模式: 直接用消息中的位姿，仅 OMPL
"""

import math
import time
import enum
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Point, Quaternion
from moveit_msgs.srv import GetPositionIK, GetMotionPlan, GetCartesianPath
from moveit_msgs.msg import (
    MotionPlanRequest, Constraints, JointConstraint, PositionIKRequest, RobotState,
)
from std_msgs.msg import Header, Float64MultiArray

from wire_connect_msgs.msg import ArmTarget

ARM_L = [
    "shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint",
    "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint",
]
ARM_R = [
    "shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint",
    "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint",
]

CARTESIAN_THRESHOLD = 0.05  # 5cm: below this skip OMPL, go straight Cartesian


class State(enum.IntEnum):
    IDLE = 0
    PLANNING = 1
    EXECUTING = 2
    TRACKING = 3


class CableTracker(Node):
    def __init__(self):
        super().__init__("cable_tracker")

        self.declare_parameter("arm", "left")
        self.declare_parameter("approach_z", 0.10)
        self.declare_parameter("retry_max", 3)
        self.declare_parameter("track_threshold", 0.03)
        self.declare_parameter("occlusion_z_jump", 0.05)
        self.declare_parameter("target_timeout", 3.0)
        self.declare_parameter("vel_scale", 0.3)
        self.declare_parameter("acc_scale", 0.3)
        self.declare_parameter("planning_time", 3.0)
        self.declare_parameter("cart_max_step", 0.01)
        self.declare_parameter("cart_jump_thresh", 1.5)
        self.declare_parameter("block_timeout", 5.0)   # block failed plug for N seconds
        self.declare_parameter("frame", "waist_yaw_link")
        self.declare_parameter("test_mode", False)

        self._arm = self.get_parameter("arm").value
        self._z_approach = self.get_parameter("approach_z").value
        self._retry_max = self.get_parameter("retry_max").value
        self._track_thresh = self.get_parameter("track_threshold").value
        self._occ_thresh = self.get_parameter("occlusion_z_jump").value
        self._frame = self.get_parameter("frame").value
        self._joints = ARM_L if self._arm == "left" else ARM_R
        self._cart_thresh = self.get_parameter("cartesian_threshold").value

        # TF
        import tf2_ros
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # subscriber
        self._target = None
        self._last_t = self.get_clock().now()
        self.create_subscription(ArmTarget, f"/vision/{self._arm}_target", self._cb_target, 10)

        # service clients
        self._ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self._plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")
        self._cart_client = self.create_client(GetCartesianPath, "/compute_cartesian_path")

        # joint publisher (execution)
        topic = f"/jointspace_commands_{'L' if self._arm == 'left' else 'R'}"
        self._joint_pub = self.create_publisher(Float64MultiArray, topic, 10)

        # state machine
        self._state = State.IDLE
        self._locked_target = None
        self._retry = 0
        self._busy = False
        self._track_z = None
        self._test_done = False
        self._block_timeout = self.get_parameter("block_timeout").value
        self._blocked_plugs = {}      # plug_id → block_start_time
        self._plan_fail_start = None  # when current planning started failing

        # two-phase trajectory buffer
        self._traj_ompl = None     # phase 1 trajectory
        self._traj_cart = None     # phase 2 trajectory
        self._approach_pose = None # intermediate waypoint for Cartesian phase

        self.create_timer(0.2, self._tick)
        self.get_logger().info(f"cable_tracker ready arm={self._arm}  [OMPL+Cartesian]")

    def _cb_target(self, msg: ArmTarget):
        self._target = msg
        self._last_t = self.get_clock().now()

    # ── state machine ────────────────────────────────────────────────
    def _tick(self):
        if self._state == State.IDLE:
            self._handle_idle()
        elif self._state == State.PLANNING:
            self._handle_planning()
        elif self._state == State.TRACKING:
            self._handle_tracking()

    def _handle_idle(self):
        if self._busy:
            return
        test = self.get_parameter("test_mode").value
        if test and self._test_done:
            return
        if not test and self._target is None:
            return

        # check if target is blocked (planning failed within block_timeout)
        if not test and self._target is not None:
            pid = getattr(self._target, 'plug_id', -1)
            if pid in self._blocked_plugs:
                elapsed = (self.get_clock().now() - self._blocked_plugs[pid]).nanoseconds / 1e9
                if elapsed < self._block_timeout:
                    self.get_logger().debug(f"plug {pid} blocked ({elapsed:.1f}s < {self._block_timeout}s)")
                    return
                # timeout expired → retry
                del self._blocked_plugs[pid]
                self.get_logger().info(f"plug {pid} block expired → retry")

        self._locked_target = self._target
        self._state = State.PLANNING
        self._retry = 0
        self._plan_fail_start = None
        self.get_logger().info("IDLE → PLANNING")

    def _handle_planning(self):
        if self._busy or self._retry >= self._retry_max:
            if self._retry >= self._retry_max:
                # check if we should block this target
                self._maybe_block_target()
                self._state = State.IDLE
            return
        self._busy = True
        self._retry += 1
        if self._retry == 1:
            self._plan_fail_start = self.get_clock().now()
        self.get_logger().info(f"attempt {self._retry}/{self._retry_max}")
        self._start_plan()

    def _maybe_block_target(self):
        """If planning has been failing for > block_timeout, mark plug as blocked."""
        target = self._locked_target
        if target is None:
            return
        pid = getattr(target, 'plug_id', -1)
        if pid < 0:
            return
        if self._plan_fail_start is None:
            return
        elapsed = (self.get_clock().now() - self._plan_fail_start).nanoseconds / 1e9
        if elapsed >= self._block_timeout:
            self._blocked_plugs[pid] = self.get_clock().now()
            self.get_logger().warn(
                f"plug {pid} blocked ({elapsed:.1f}s fails) — will skip for {self._block_timeout}s")
            self._locked_target = None  # release lock so new target can take over

    def _handle_tracking(self):
        if self._target is None:
            elapsed = (self.get_clock().now() - self._last_t).nanoseconds / 1e9
            if elapsed > self.get_parameter("target_timeout").value:
                return
            return
        t = self._target
        locked = self._locked_target
        if locked is None:
            self._state = State.IDLE
            return
        dx = abs(t.pose.position.x - locked.pose.position.x)
        dy = abs(t.pose.position.y - locked.pose.position.y)
        dz = abs(t.cable_z - locked.cable_z)
        dist = math.sqrt(dx*dx + dy*dy + dz*dz)
        if dist > self._track_thresh:
            if self._track_z is not None and (t.cable_z - self._track_z) > self._occ_thresh:
                self.get_logger().info("occlusion ignored", throttle_duration_sec=1.0)
            else:
                self.get_logger().info(f"cable moved {dist:.3f}m → re-plan")
                self._locked_target = t
                self._state = State.PLANNING
                self._retry = 0
                self._busy = False

    # ── planning entry ───────────────────────────────────────────────
    def _start_plan(self):
        """Decide: OMPL + Cartesian (two-phase) or Cartesian only (short distance)."""
        tcp = self._get_tcp_pose()
        if tcp is None:
            self.get_logger().error("cannot get current TCP pose")
            self._busy = False
            return

        # compute target poses
        test = self.get_parameter("test_mode").value
        target = self._locked_target

        if test:
            # test mode: current TCP z+10cm, keep current orientation, OMPL only
            approach = Pose(
                position=Point(x=tcp.position.x, y=tcp.position.y,
                               z=tcp.position.z + self._z_approach),
                orientation=tcp.orientation,
            )
            self._approach_pose = approach
            self.get_logger().info(
                f"TEST  TCP [{tcp.position.x:.3f},{tcp.position.y:.3f},{tcp.position.z:.3f}] → "
                f"[{approach.position.x:.3f},{approach.position.y:.3f},{approach.position.z:.3f}]  "
                f"keep orientation  OMPL only")
            # test mode: execute directly after OMPL, no Cartesian phase 2
            self._call_ompl(approach, self._execute_trajectories)
            return

        if target is not None and getattr(target, 'plug_id', 0) == -1:
            # keyboard teleop: use exact pose, OMPL only
            goal = target.pose
            self._approach_pose = goal  # for execution
            dist = math.sqrt(
                (goal.position.x - tcp.position.x)**2 +
                (goal.position.y - tcp.position.y)**2 +
                (goal.position.z - tcp.position.z)**2)
            self.get_logger().info(
                f"KEYBOARD  TCP [{tcp.position.x:.3f},{tcp.position.y:.3f},{tcp.position.z:.3f}] → "
                f"[{goal.position.x:.3f},{goal.position.y:.3f},{goal.position.z:.3f}]  "
                f"dist={dist:.3f}m  OMPL only")
            self._call_ompl(goal, self._ompl_phase1_done)
            return

        # vision mode: cable detection → approach above cable only (OMPL, keep TCP orientation)
        approach_pose = Pose(
            position=Point(x=target.pose.position.x,
                           y=target.pose.position.y,
                           z=target.cable_z + self._z_approach),
            orientation=tcp.orientation,
        )
        self._approach_pose = approach_pose

        dist = math.sqrt(
            (approach_pose.position.x - tcp.position.x)**2 +
            (approach_pose.position.y - tcp.position.y)**2 +
            (approach_pose.position.z - tcp.position.z)**2)

        self.get_logger().info(
            f"VISION  TCP [{tcp.position.x:.3f},{tcp.position.y:.3f},{tcp.position.z:.3f}] → "
            f"approach [{approach_pose.position.x:.3f},{approach_pose.position.y:.3f},"
            f"{approach_pose.position.z:.3f}]  dist={dist:.3f}m  OMPL only")

        # OMPL only for now (Cartesian phase 2 pending finger joint fix)
        self._call_ompl(approach_pose, self._execute_trajectories)

    # ── OMPL phase ───────────────────────────────────────────────────
    def _call_ompl(self, goal_pose: Pose, done_cb):
        """IK → OMPL plan with joint constraints."""
        req = GetPositionIK.Request()
        req.ik_request = PositionIKRequest()
        req.ik_request.group_name = f"{self._arm}_arm"
        req.ik_request.robot_state = RobotState(is_diff=True)
        req.ik_request.pose_stamped.header = Header(
            frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        req.ik_request.pose_stamped.pose = goal_pose
        req.ik_request.timeout.sec = 3

        self.get_logger().info(f"OMPL IK → [{goal_pose.position.x:.3f},"
                               f"{goal_pose.position.y:.3f},{goal_pose.position.z:.3f}]")
        if not self._ik_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("IK service not available")
            self._busy = False
            return
        self._ik_client.call_async(req).add_done_callback(
            lambda f: self._ik_cb(f, done_cb))

    def _ik_cb(self, future, done_cb):
        result = future.result()
        if result is None or result.error_code.val != 1:
            code = result.error_code.val if result else 'None'
            self.get_logger().warn(f"OMPL IK failed code={code}")
            self._busy = False
            return

        joints = result.solution.joint_state
        jmap = {n: p for n, p in zip(joints.name, joints.position)}
        vals = [jmap.get(j, 0.0) for j in self._joints]

        self.get_logger().info(f"OMPL IK OK → {[f'{v:.3f}' for v in vals]}")

        # build MotionPlanRequest with joint constraints
        jcs = [JointConstraint(joint_name=j, position=v,
                tolerance_above=0.05, tolerance_below=0.05, weight=1.0)
               for j, v in zip(self._joints, vals)]
        req = MotionPlanRequest()
        req.group_name = f"{self._arm}_arm"
        req.pipeline_id = "ompl"
        req.planner_id = ""
        req.num_planning_attempts = 5
        req.allowed_planning_time = self.get_parameter("planning_time").value
        req.max_velocity_scaling_factor = self.get_parameter("vel_scale").value
        req.max_acceleration_scaling_factor = self.get_parameter("acc_scale").value
        req.start_state = RobotState(is_diff=True)
        req.goal_constraints = [Constraints(joint_constraints=jcs)]

        self.get_logger().info("OMPL planning with joint constraints...")
        if not self._plan_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("plan service not available")
            self._busy = False
            return
        self._plan_client.call_async(GetMotionPlan.Request(motion_plan_request=req)
            ).add_done_callback(lambda f: self._ompl_cb(f, done_cb))

    def _ompl_cb(self, future, done_cb):
        result = future.result()
        if result is None or result.motion_plan_response.error_code.val != 1:
            code = result.motion_plan_response.error_code.val if result else 'None'
            self.get_logger().warn(f"OMPL plan failed code={code}")
            self._busy = False
            return

        traj = result.motion_plan_response.trajectory
        self.get_logger().info(f"OMPL plan OK — {len(traj.joint_trajectory.points)} points")
        self._traj_ompl = traj
        done_cb()

    # ── Cartesian phase ──────────────────────────────────────────────
    def _call_cartesian(self, start_pose: Pose, goal_pose: Pose, done_cb):
        """Cartesian path: straight line from start to goal, collision checked."""
        req = GetCartesianPath.Request()
        req.header = Header(frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        req.start_state = RobotState(is_diff=True)
        req.group_name = f"{self._arm}_arm"
        req.link_name = f"{self._arm}_tcp_link"
        req.waypoints = [start_pose, goal_pose]
        req.max_step = self.get_parameter("cart_max_step").value
        req.jump_threshold = self.get_parameter("cart_jump_thresh").value
        req.avoid_collisions = True
        req.path_constraints = Constraints()

        self.get_logger().info(f"Cartesian → [{goal_pose.position.x:.3f},"
                               f"{goal_pose.position.y:.3f},{goal_pose.position.z:.3f}]")
        if not self._cart_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("Cartesian service not available")
            self._busy = False
            return
        self._cart_client.call_async(req).add_done_callback(
            lambda f: self._cartesian_cb(f, done_cb))

    def _cartesian_cb(self, future, done_cb):
        result = future.result()
        if result is None:
            self.get_logger().error("Cartesian service failed")
            self._busy = False
            return

        fraction = result.fraction
        if result.error_code.val == 1 and fraction >= 0.99:
            traj = result.solution.joint_trajectory
            self.get_logger().info(f"Cartesian OK — {len(traj.points)} points  fraction={fraction:.3f}")
            self._traj_cart = traj
            done_cb()
        else:
            self.get_logger().warn(
                f"Cartesian failed  code={result.error_code.val}  fraction={fraction:.3f}")
            self._busy = False

    # ── phase completion callbacks ───────────────────────────────────
    def _ompl_phase1_done(self):
        """Phase 1 (OMPL) complete → start Phase 2 (Cartesian from approach to grasp)."""
        if self._approach_pose is None:
            self._execute_trajectories()
            return

        target = self._locked_target
        # test mode or keyboard mode: no phase 2, execute phase 1 only
        if target is None or getattr(target, 'plug_id', 0) == -1:
            self._execute_trajectories()
            return

        # vision mode: Cartesian from approach to grasp
        grasp_pose = Pose(
            position=Point(x=target.pose.position.x,
                           y=target.pose.position.y,
                           z=target.cable_z),
            orientation=_palm_orientation(target.cable_yaw),
        )
        self._call_cartesian(self._approach_pose, grasp_pose, self._cartesian_done)

    def _cartesian_done(self):
        """Both phases complete → execute."""
        self._execute_trajectories()

    # ── execution ────────────────────────────────────────────────────
    def _execute_trajectories(self):
        """Concatenate OMPL + Cartesian trajectories and publish."""
        self._busy = False
        self._state = State.EXECUTING

        # collect all points from both phases
        all_points = []
        if self._traj_ompl is not None:
            all_points.extend(self._traj_ompl.joint_trajectory.points)
        if self._traj_cart is not None:
            all_points.extend(self._traj_cart.points)

        if not all_points:
            self.get_logger().error("no trajectory to execute")
            self._state = State.IDLE
            return

        self.get_logger().info(f"executing {len(all_points)} points total...")

        t_prev = 0.0
        for pt in all_points:
            msg = Float64MultiArray(data=list(pt.positions[:7]))
            self._joint_pub.publish(msg)
            t_cur = pt.time_from_start.sec + pt.time_from_start.nanosec * 1e-9
            dt = max(t_cur - t_prev, 0.01)
            time.sleep(dt)
            t_prev = t_cur

        # cleanup
        self._traj_ompl = None
        self._traj_cart = None

        test = self.get_parameter("test_mode").value
        if test:
            self.get_logger().info("test done → IDLE")
            self._state = State.IDLE
            self._test_done = True
        else:
            self._state = State.TRACKING
            if self._locked_target:
                self._track_z = self._locked_target.cable_z
            self.get_logger().info("execution done → TRACKING")

    # ── TF helpers ───────────────────────────────────────────────────
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


# ── helpers ──────────────────────────────────────────────────────────

def _palm_orientation(cable_yaw: float) -> Quaternion:
    """TCP Z↓(palm∥table), TCP Y⊥cable direction."""
    perp_yaw = cable_yaw + math.pi / 2
    cy, sy = math.cos(perp_yaw), math.sin(perp_yaw)
    x_dir = (-cy, -sy, 0.0)
    y_dir = (cy, sy, 0.0)
    z_dir = (0.0, 0.0, -1.0)
    return _rotmat_to_quat(x_dir, y_dir, z_dir)


def _rotmat_to_quat(x, y, z) -> Quaternion:
    trace = x[0] + y[1] + z[2]
    if trace > 0:
        s = math.sqrt(trace + 1.0) * 2
        return Quaternion(w=0.25 * s, x=(y[2] - z[1]) / s,
                          y=(z[0] - x[2]) / s, z=(x[1] - y[0]) / s)
    elif x[0] > y[1] and x[0] > z[2]:
        s = math.sqrt(1.0 + x[0] - y[1] - z[2]) * 2
        return Quaternion(w=(y[2] - z[1]) / s, x=0.25 * s,
                          y=(y[0] + x[1]) / s, z=(z[0] + x[2]) / s)
    elif y[1] > z[2]:
        s = math.sqrt(1.0 + y[1] - x[0] - z[2]) * 2
        return Quaternion(w=(z[0] - x[2]) / s, x=(y[0] + x[1]) / s,
                          y=0.25 * s, z=(z[1] + y[2]) / s)
    else:
        s = math.sqrt(1.0 + z[2] - x[0] - y[1]) * 2
        return Quaternion(w=(x[1] - y[0]) / s, x=(z[0] + x[2]) / s,
                          y=(z[1] + y[2]) / s, z=0.25 * s)


# ── main ─────────────────────────────────────────────────────────────

def main():
    rclpy.init()
    node = CableTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        try: rclpy.shutdown()
        except: pass


if __name__ == "__main__":
    main()
