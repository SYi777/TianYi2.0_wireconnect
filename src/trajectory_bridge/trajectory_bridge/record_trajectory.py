#!/usr/bin/env python3
"""录制 RViz 拖动规划的轨迹，保存为 JSON 供初始化脚本回放。

监听 moveit_*_arm_controller/follow_joint_trajectory action，
每次 RViz Plan&Execute 成功后保存轨迹到文件。

Usage:
    ros2 run trajectory_bridge record_trajectory --ros-args -p output:=init_sequence.json
"""
import json
import os
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from control_msgs.action import FollowJointTrajectory


class TrajectoryRecorder(Node):
    def __init__(self):
        super().__init__("record_trajectory")
        self.declare_parameter("output", "init_trajectories.json")
        self._out = self.get_parameter("output").value
        self._records = []

        for arm in ("left", "right"):
            ActionServer(self, FollowJointTrajectory,
                f"moveit_{arm}_arm_controller/follow_joint_trajectory",
                goal_callback=self._g, cancel_callback=self._c,
                execute_callback=self._exec(arm))

        self.get_logger().info(f"recording → {self._out}")

    def _g(self, _): return GoalResponse.ACCEPT
    def _c(self, _): return CancelResponse.ACCEPT

    def _exec(self, arm):
        def cb(goal_handle):
            traj = goal_handle.request.trajectory
            pts = [{"positions": list(pt.positions), "velocities": list(pt.velocities),
                    "time": pt.time_from_start.sec + pt.time_from_start.nanosec * 1e-9}
                   for pt in traj.points]
            record = {"arm": arm, "joint_names": list(traj.joint_names), "points": pts}
            self._records.append(record)
            goal_handle.succeed()
            self.get_logger().info(f"[{arm}] recorded {len(pts)} pts")
            self._save()
            return FollowJointTrajectory.Result()
        return cb

    def _save(self):
        # save compact: only positions for replay
        compact = []
        for r in self._records:
            pos_only = [p["positions"] for p in r["points"]]
            compact.append({"arm": r["arm"], "joint_names": r["joint_names"], "points": pos_only})
        with open(self._out, "w") as f:
            json.dump(compact, f, indent=2)
        self.get_logger().info(f"saved {len(compact)} trajectories → {self._out}")


def main():
    rclpy.init()
    node = TrajectoryRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
