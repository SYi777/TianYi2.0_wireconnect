#!/usr/bin/env python3
"""Bridge: MoveIt FollowJointTrajectory → XARM topic (arm) / body_control topic (head)."""

from __future__ import annotations

import sys
import time
from typing import Dict, List

import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
from control_msgs.action import FollowJointTrajectory
from std_msgs.msg import Float64MultiArray, Header

HEAD_JOINT_TO_MOTOR: Dict[str, int] = {
    "head_roll_joint": 1, "head_pitch_joint": 2, "head_yaw_joint": 3,
}

ARM_L = [
    "shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint",
    "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint",
]
ARM_R = [
    "shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint",
    "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint",
]
HEAD = ["head_yaw_joint", "head_pitch_joint", "head_roll_joint"]


class TrajectoryBridge(Node):
    def __init__(self):
        super().__init__("trajectory_bridge")
        self.declare_parameter("debug", True)
        self.declare_parameter("head_spd", 2.0)
        self.declare_parameter("head_cur", 1.0)
        self._debug = self.get_parameter("debug").value
        self._hspd = self.get_parameter("head_spd").value
        self._hcur = self.get_parameter("head_cur").value

        self._arm_l = self.create_publisher(Float64MultiArray, "/jointspace_commands_L", 10)
        self._arm_r = self.create_publisher(Float64MultiArray, "/jointspace_commands_R", 10)
        self._head = self.create_publisher(CmdSetMotorPosition, "/head/cmd_pos", 10)

        ActionServer(self, FollowJointTrajectory, "moveit_left_arm_controller/follow_joint_trajectory",
            goal_callback=self._g("L"), cancel_callback=self._c,
            execute_callback=self._arm("L", ARM_L, self._arm_l))
        ActionServer(self, FollowJointTrajectory, "moveit_right_arm_controller/follow_joint_trajectory",
            goal_callback=self._g("R"), cancel_callback=self._c,
            execute_callback=self._arm("R", ARM_R, self._arm_r))
        ActionServer(self, FollowJointTrajectory, "moveit_head_controller/follow_joint_trajectory",
            goal_callback=self._g("H"), cancel_callback=self._c,
            execute_callback=self._head_exec)

        self.get_logger().info(f"TrajectoryBridge [{'DEBUG' if self._debug else 'NORMAL'}]")

    def _g(self, tag):
        def cb(req) -> GoalResponse:
            self.get_logger().info(f"[{tag}] {len(req.trajectory.points)}pts")
            return GoalResponse.ACCEPT
        return cb

    @staticmethod
    def _c(_) -> CancelResponse:
        return CancelResponse.ACCEPT

    def _arm(self, tag, joints, pub):
        def execute(goal_handle):
            traj = goal_handle.request.trajectory
            jn_list = list(traj.joint_names)
            try:
                idxs = [jn_list.index(j) for j in joints]
            except ValueError as e:
                self.get_logger().error(f"[{tag}] {e}")
                goal_handle.abort()
                return FollowJointTrajectory.Result()

            pts = len(traj.points)
            # Timestamps: if all zero (CHOMP bug), spread evenly over 5s
            times = [pt.time_from_start.sec + pt.time_from_start.nanosec * 1e-9 for pt in traj.points]
            if all(t == 0.0 for t in times):
                total_dur = 5.0
                times = [total_dur * i / max(pts - 1, 1) for i in range(pts)]

            result = FollowJointTrajectory.Result()
            for i, pt in enumerate(traj.points):
                pos = [float(pt.positions[ii]) for ii in idxs]
                t_sec = times[i]
                self.get_logger().info(f"[{tag}] {i+1}/{pts} t={t_sec:.2f}s {[f'{v:+.3f}' for v in pos]}")

                if self._debug:
                    try:
                        key = input(f"[{tag}] {i+1}/{pts} Enter/s/q: ").strip().lower()
                    except (EOFError, KeyboardInterrupt):
                        goal_handle.abort()
                        return FollowJointTrajectory.Result()
                    if key == "q":
                        self.get_logger().info(f"[{tag}] user abort")
                        goal_handle.abort()
                        return FollowJointTrajectory.Result()
                    elif key == "s":
                        self.get_logger().info(f"[{tag}] skip")
                        continue

                msg = Float64MultiArray()
                msg.data = pos
                pub.publish(msg)
                self.get_logger().info(f"[{tag}] sent")

                if i < pts - 1:
                    wait = max(0.05, times[i + 1] - t_sec)
                    time.sleep(wait)

            goal_handle.succeed()
            self.get_logger().info(f"[{tag}] done")
            result.error_code = FollowJointTrajectory.Result.SUCCESSFUL
            return result
        return execute

    def _head_exec(self, goal_handle):
        traj = goal_handle.request.trajectory
        jn_list = list(traj.joint_names)
        try:
            idxs = [jn_list.index(j) for j in HEAD]
        except ValueError as e:
            self.get_logger().error(f"[H] {e}")
            goal_handle.abort()
            return FollowJointTrajectory.Result()

        for pt in traj.points:
            pos = {j: float(pt.positions[i]) for j, i in zip(HEAD, idxs)}
            self.get_logger().info(f"[H] {pos}")
            msg = CmdSetMotorPosition()
            msg.header = Header(); msg.header.stamp = self.get_clock().now().to_msg()
            msg.cmds = [SetMotorPosition(name=HEAD_JOINT_TO_MOTOR[j], pos=p, spd=self._hspd, cur=self._hcur) for j, p in pos.items()]
            self._head.publish(msg)

        goal_handle.succeed()
        return FollowJointTrajectory.Result()


def main():
    rclpy.init()
    node = TrajectoryBridge()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try: executor.spin()
    except KeyboardInterrupt: pass
    finally: executor.shutdown(); node.destroy_node(); rclpy.shutdown()

if __name__ == "__main__": main()
