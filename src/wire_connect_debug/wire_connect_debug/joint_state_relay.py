#!/usr/bin/env python3
"""Relay /joint_state_broadcaster/joint_states → /joint_states"""
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

class JointStateRelay(Node):
    def __init__(self):
        super().__init__("joint_state_relay")
        self._pub = self.create_publisher(JointState, "/joint_states", 10)
        self.create_subscription(JointState,
            "/joint_state_broadcaster/joint_states",
            lambda m: self._pub.publish(m), 10)
        self.get_logger().info("relaying joint_states")

def main():
    rclpy.init()
    node = JointStateRelay()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally: node.destroy_node(); rclpy.try_shutdown()

if __name__ == "__main__":
    main()
