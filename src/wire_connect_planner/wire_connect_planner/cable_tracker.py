#!/usr/bin/env python3
"""cable_tracker — 收 ArmTarget → 加桌面障碍物 → OMPL 避碰规划 → 执行。

Subscribes:
  /vision/left_target   (ArmTarget)
  /vision/right_target  (ArmTarget)

Uses:
  move_group action  (moveit_msgs/action/MoveGroup)
  /planning_scene    (moveit_msgs/msg/PlanningScene)
  trajectory_bridge  (FollowJointTrajectory → XARM)
"""

import math
from collections import deque

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from geometry_msgs.msg import Pose, Point, Quaternion
from shape_msgs.msg import SolidPrimitive
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import (
    MotionPlanRequest, Constraints, PositionConstraint, OrientationConstraint,
    BoundingVolume, RobotState, PlanningScene, PlanningSceneWorld, CollisionObject,
    WorkspaceParameters,
)
from builtin_interfaces.msg import Duration
from std_msgs.msg import Header

from wire_connect_msgs.msg import ArmTarget, TableInfo

# ── arm joint names (must match URDF) ─────────────────────────────────
ARM_L = [
    "shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint",
    "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint",
]
ARM_R = [
    "shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint",
    "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint",
]


class CableTracker(Node):
    def __init__(self):
        super().__init__("cable_tracker")

        # ── parameters ───────────────────────────────────────────────
        self.declare_parameter("arm", "left")
        self.declare_parameter("approach_z_offset", 0.10)   # 10cm above cable
        self.declare_parameter("table_z_offset", -0.02)     # obstacle 2cm below cable
        self.declare_parameter("table_thickness", 0.05)     # box thickness
        self.declare_parameter("table_x_center", 0.65)      # table center in waist_yaw_link
        self.declare_parameter("table_size_xy", [1.2, 0.8]) # table XY extent
        self.declare_parameter("vel_scale", 0.3)
        self.declare_parameter("acc_scale", 0.3)
        self.declare_parameter("planning_time", 3.0)
        self.declare_parameter("frame", "waist_yaw_link")

        self._arm = self.get_parameter("arm").value
        self._z_offset = self.get_parameter("approach_z_offset").value
        self._table_dz = self.get_parameter("table_z_offset").value
        self._table_h = self.get_parameter("table_thickness").value
        self._frame = self.get_parameter("frame").value

        arm_joints = ARM_L if self._arm == "left" else ARM_R
        group = f"{self._arm}_arm"

        # ── subscribers ──────────────────────────────────────────────
        self._target = None
        self._table_info = None
        self.create_subscription(
            ArmTarget, f"/vision/{self._arm}_target", self._cb_target, 10)
        self.create_subscription(
            TableInfo, "/vision/table", self._cb_table, 10)

        # ── scene publisher ──────────────────────────────────────────
        self._scene_pub = self.create_publisher(PlanningScene, "/planning_scene", 10)

        # ── move_group action client ─────────────────────────────────
        self._mg_client = ActionClient(self, MoveGroup, "/move_action")
        self._busy = False
        self._table_published = False

        # ── timer ────────────────────────────────────────────────────
        self.create_timer(0.2, self._tick)

        self.get_logger().info(f"cable_tracker ready (arm={self._arm}, group={group})")

    # ── callbacks ────────────────────────────────────────────────────
    def _cb_target(self, msg: ArmTarget):
        self._target = msg

    def _cb_table(self, msg: TableInfo):
        if msg.valid:
            self._table_info = msg
            if not self._table_published:
                self._publish_table(msg)

    # ── main loop ────────────────────────────────────────────────────
    def _tick(self):
        if self._busy or self._target is None:
            return

        target = self._target
        cable_z = target.cable_z

        # 1. update table obstacle (first time from TableInfo, or fallback)
        if not self._table_published:
            if self._table_info is not None:
                self._publish_table(self._table_info)
                self._table_published = True
            else:
                # fallback: infer from cable position
                self.get_logger().warn("no TableInfo yet, using cable fallback", throttle_duration_sec=5.0)

        # 2. compute goal pose — 10cm above cable, hand back up
        goal = Pose()
        goal.position = Point(
            x=target.pose.position.x,
            y=target.pose.position.y,
            z=cable_z + self._z_offset,
        )
        goal.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)

        # 3. plan + execute
        self._busy = True
        self._send_goal(goal)

    # ── table obstacle ───────────────────────────────────────────────
    def _publish_table(self, info: TableInfo):
        """Add a box obstacle from TableInfo (depth-based desktop detection)."""
        w = info.x_max - info.x_min
        h = info.y_max - info.y_min
        if w <= 0 or h <= 0:
            self.get_logger().warn("invalid table dimensions, skipping")
            return

        box = SolidPrimitive(type=SolidPrimitive.BOX,
                             dimensions=[float(w), float(h), self._table_h])

        # centre XY, top below detected surface
        cx = (info.x_min + info.x_max) / 2.0
        cy = (info.y_min + info.y_max) / 2.0
        cz = info.z + self._table_dz - self._table_h / 2.0

        co = CollisionObject()
        co.header = Header(frame_id=self._frame, stamp=self.get_clock().now().to_msg())
        co.id = "table_obstacle"
        co.operation = CollisionObject.ADD
        co.primitives = [box]
        co.primitive_poses = [Pose(position=Point(x=cx, y=cy, z=cz))]

        scene = PlanningScene()
        scene.world = PlanningSceneWorld(collision_objects=[co])
        scene.is_diff = True
        self._scene_pub.publish(scene)
        self.get_logger().info(
            f"table box {w:.2f}×{h:.2f}×{self._table_h}  "
            f"top={info.z + self._table_dz:.3f}  "
            f"xy=[{info.x_min:.2f},{info.x_max:.2f}]×[{info.y_min:.2f},{info.y_max:.2f}]")

    # ── planning ─────────────────────────────────────────────────────
    def _send_goal(self, goal: Pose):
        """Send a MotionPlanRequest to move_group via action."""
        arm_joints = ARM_L if self._arm == "left" else ARM_R
        group = f"{self._arm}_arm"

        # position constraint: tcp at goal position
        pos_con = PositionConstraint()
        pos_con.header = Header(frame_id=self._frame)
        pos_con.link_name = f"{self._arm}_tcp_link"
        pos_con.target_point_offset = Point(x=0.0, y=0.0, z=0.0)
        # small bounding box around target
        pos_con.constraint_region = BoundingVolume()
        pos_con.constraint_region.primitives = [
            SolidPrimitive(type=SolidPrimitive.BOX, dimensions=[0.01, 0.01, 0.01]),
        ]
        pos_con.constraint_region.primitive_poses = [goal]
        pos_con.weight = 1.0

        # orientation constraint: tcp at goal orientation
        ori_con = OrientationConstraint()
        ori_con.header = Header(frame_id=self._frame)
        ori_con.link_name = f"{self._arm}_tcp_link"
        ori_con.orientation = goal.orientation
        ori_con.absolute_x_axis_tolerance = 0.3
        ori_con.absolute_y_axis_tolerance = 0.3
        ori_con.absolute_z_axis_tolerance = 0.3
        ori_con.weight = 1.0

        constraints = Constraints(
            position_constraints=[pos_con],
            orientation_constraints=[ori_con],
        )

        req = MotionPlanRequest()
        req.group_name = group
        req.pipeline_id = "ompl"
        req.planner_id = "RRTConnectkConfigDefault"
        req.num_planning_attempts = 5
        req.allowed_planning_time = self.get_parameter("planning_time").value
        req.max_velocity_scaling_factor = self.get_parameter("vel_scale").value
        req.max_acceleration_scaling_factor = self.get_parameter("acc_scale").value
        req.goal_constraints = [constraints]
        req.workspace_parameters = WorkspaceParameters(
            header=Header(frame_id=self._frame),
            min_corner=Point(x=0.0, y=-0.8, z=-0.3),
            max_corner=Point(x=1.2, y=0.8, z=0.8),
        )
        # start state from current joint_states (move_group reads it automatically)
        req.start_state = RobotState(is_diff=True)

        self.get_logger().info(
            f"planning {group} → [{goal.position.x:.3f}, {goal.position.y:.3f}, {goal.position.z:.3f}]"
        )
        self._mg_client.wait_for_server(timeout_sec=5.0)
        self._mg_client.send_goal_async(
            MoveGroup.Goal(request=req),
        ).add_done_callback(self._done_cb)

    def _done_cb(self, future):
        self._busy = False
        result = future.result()
        if result is None:
            self.get_logger().error("move_group action failed")
            return
        code = result.result.error_code
        if code.val == 1:  # SUCCESS
            self.get_logger().info("plan + execute SUCCESS")
        else:
            self.get_logger().error(f"plan failed: error_code={code.val}")


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
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
