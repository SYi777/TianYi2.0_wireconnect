#!/usr/bin/env python3
"""cable_tracker — IK + OMPL 规划 + 执行 + 遮挡保护。

Pipeline:
  1. ArmTarget 进来 → 算目标 Pose
  2. /compute_ik → 7维关节角
  3. joint_constraints 规划 (OMPL, 带桌面障碍物)
  4. 轨迹 → trajectory_bridge → XARM
"""

import math
import enum
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Point, Quaternion
from moveit_msgs.srv import GetPositionIK, GetMotionPlan
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
        self.declare_parameter("frame", "waist_yaw_link")
        self.declare_parameter("test_mode", False)
        self.declare_parameter("test_x", 0.35)
        self.declare_parameter("test_y", 0.20)
        self.declare_parameter("test_z", -0.10)

        self._arm = self.get_parameter("arm").value
        self._z_approach = self.get_parameter("approach_z").value
        self._retry_max = self.get_parameter("retry_max").value
        self._track_thresh = self.get_parameter("track_threshold").value
        self._occ_thresh = self.get_parameter("occlusion_z_jump").value
        self._frame = self.get_parameter("frame").value
        self._joints = ARM_L if self._arm == "left" else ARM_R

        # subscriber
        self._target = None
        self._last_t = self.get_clock().now()
        self.create_subscription(ArmTarget, f"/vision/{self._arm}_target", self._cb_target, 10)

        # IK + Planning service clients
        self._ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self._plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")

        # joint publisher (execution)
        topic = f"/jointspace_commands_{'L' if self._arm == 'left' else 'R'}"
        self._joint_pub = self.create_publisher(Float64MultiArray, topic, 10)

        # state machine
        self._state = State.IDLE
        self._locked_target = None
        self._retry = 0
        self._busy = False
        self._track_z = None

        self.create_timer(0.2, self._tick)
        self.get_logger().info(f"cable_tracker ready arm={self._arm}")

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
        if not test and self._target is None:
            return
        self._locked_target = self._target  # may be None in test mode
        self._state = State.PLANNING
        self._retry = 0
        self.get_logger().info("IDLE → PLANNING")

    def _handle_planning(self):
        if self._busy or self._retry >= self._retry_max:
            if self._retry >= self._retry_max:
                self.get_logger().error(f"failed after {self._retry_max} retries")
                self._state = State.IDLE
            return
        self._busy = True
        self._retry += 1
        self.get_logger().info(f"attempt {self._retry}/{self._retry_max}")
        self._call_ik(self._locked_target)

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

    # ── IK ───────────────────────────────────────────────────────────
    def _call_ik(self, target: ArmTarget):
        goal = Pose()
        if self.get_parameter("test_mode").value:
            goal.position = Point(
                x=self.get_parameter("test_x").value,
                y=self.get_parameter("test_y").value,
                z=self.get_parameter("test_z").value,
            )
        else:
            goal.position = Point(
                x=target.pose.position.x,
                y=target.pose.position.y,
                z=target.cable_z + self._z_approach,
            )
        goal.orientation = Quaternion(w=1.0)  # identity first, orientation later

        req = GetPositionIK.Request()
        req.ik_request = PositionIKRequest()
        req.ik_request.group_name = f"{self._arm}_arm"
        req.ik_request.robot_state = RobotState(is_diff=True)
        req.ik_request.pose_stamped.header = Header(
            frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        req.ik_request.pose_stamped.pose = goal
        req.ik_request.timeout.sec = 3

        self.get_logger().info(
            f"IK → [{goal.position.x:.3f},{goal.position.y:.3f},{goal.position.z:.3f}] "
            f"q=[{goal.orientation.x:.3f},{goal.orientation.y:.3f},{goal.orientation.z:.3f},{goal.orientation.w:.3f}]")
        self._ik_client.call_async(req).add_done_callback(self._ik_cb)

    def _ik_cb(self, future):
        result = future.result()
        if result is None or result.error_code.val != 1:
            self.get_logger().warn(f"IK failed code={result.error_code.val if result else 'None'}")
            self._busy = False
            return  # retry on next tick

        joints = result.solution.joint_state
        # extract 7 arm joints
        jmap = {n: p for n, p in zip(joints.name, joints.position)}
        vals = [jmap.get(j, 0.0) for j in self._joints]

        self.get_logger().info(f"IK OK → {[f'{v:.3f}' for v in vals]}")
        self._call_planner(vals)

    # ── planning ─────────────────────────────────────────────────────
    def _call_planner(self, joint_vals: list):
        stamp = self.get_clock().now().to_msg()
        jcs = [
            JointConstraint(
                joint_name=j, position=v,
                tolerance_above=0.05, tolerance_below=0.05, weight=1.0,
            )
            for j, v in zip(self._joints, joint_vals)
        ]
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

        self.get_logger().info("planning with joint constraints...")
        self._plan_client.call_async(GetMotionPlan.Request(motion_plan_request=req)
            ).add_done_callback(self._plan_cb)

    def _plan_cb(self, future):
        self._busy = False
        result = future.result()
        if result is None:
            self.get_logger().error("plan service failed")
            return
        code = result.motion_plan_response.error_code
        if code.val == 1:
            traj = result.motion_plan_response.trajectory
            pts = len(traj.joint_trajectory.points)
            self.get_logger().info(f"plan OK — {pts} points, executing...")
            self._state = State.EXECUTING
            # execute via jointspace_commands
            for pt in traj.joint_trajectory.points:
                msg = Float64MultiArray(data=list(pt.positions[:7]))
                self._joint_pub.publish(msg)
            self._state = State.TRACKING
            if self._locked_target:
                self._track_z = self._locked_target.cable_z
        else:
            self.get_logger().warn(f"plan failed code={code.val}")


# ── helpers ──────────────────────────────────────────────────────────

def _compute_orientation(cable_yaw: float, arm: str) -> Quaternion:
    thumb_yaw = cable_yaw + (math.pi / 2 if arm == "left" else -math.pi / 2)
    cp, sp = math.cos(-math.pi / 4), math.sin(-math.pi / 4)
    ct, st = math.cos(thumb_yaw / 2), math.sin(thumb_yaw / 2)
    return Quaternion(x=ct * sp, y=st * sp, z=st * cp, w=ct * cp)


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
