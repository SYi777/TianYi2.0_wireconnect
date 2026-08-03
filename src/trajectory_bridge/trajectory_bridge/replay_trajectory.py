#!/usr/bin/env python3
"""回放录制的轨迹，逐个点发到 /jointspace_commands_L/R.

Usage:
    ros2 run trajectory_bridge replay_trajectory init_trajectories.json
"""
import json
import sys
import time
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray


ARM_JOINTS = {
    "left":  ["shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint",
              "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint"],
    "right": ["shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint",
              "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint"],
}


class ReplayNode(Node):
    def __init__(self, filename):
        super().__init__("replay_trajectory")
        with open(filename) as f:
            self._trajs = json.load(f)
        self._pub_l = self.create_publisher(Float64MultiArray, "/jointspace_commands_L", 10)
        self._pub_r = self.create_publisher(Float64MultiArray, "/jointspace_commands_R", 10)
        self._pub = {"left": self._pub_l, "right": self._pub_r}
        self.get_logger().info(f"loaded {len(self._trajs)} trajectories")

    def replay_all(self, step_delay=0.1):
        for i, traj in enumerate(self._trajs):
            arm = traj["arm"]
            names = traj["joint_names"]
            pts = traj["points"]
            arm_joints = ARM_JOINTS[arm]
            idxs = [names.index(j) for j in arm_joints]

            self.get_logger().info(f"[{i}] {arm} arm  {len(pts)} pts")
            for j, pt in enumerate(pts):
                vals = [pt[ii] for ii in idxs]
                msg = Float64MultiArray(data=vals)
                self._pub[arm].publish(msg)
                time.sleep(step_delay)
            self.get_logger().info(f"[{i}] done")


def main():
    if len(sys.argv) < 2:
        print(f"Usage: ros2 run trajectory_bridge replay_trajectory <file.json>")
        sys.exit(1)
    rclpy.init()
    node = ReplayNode(sys.argv[1])
    try:
        node.replay_all()
        node.get_logger().info("all done")
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
