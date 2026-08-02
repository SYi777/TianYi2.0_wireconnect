#!/usr/bin/env python3
"""Publish gripper TF frame relative to TCP for RViz visualization.
Offset in TCP frame [dx, dy, dz] (m), no rotation.

Usage:
    ros2 run wire_connect_debug gripper_tf_publisher --ros-args -p dx:=0.02 -p dy:=-0.15 -p dz:=-0.10
"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
import tf2_ros


class GripperTFPublisher(Node):
    def __init__(self):
        super().__init__("gripper_tf_publisher")
        self.declare_parameter("dx", 0.02)
        self.declare_parameter("dy", -0.15)
        self.declare_parameter("dz", -0.10)
        self.declare_parameter("rate", 30.0)

        self._tf_broadcaster = tf2_ros.TransformBroadcaster(self)
        self.create_timer(1.0 / self.get_parameter("rate").value, self._publish)
        self.get_logger().info("publishing left_tcp_link → left_gripper_link")

    def _publish(self):
        dx = self.get_parameter("dx").value
        dy = self.get_parameter("dy").value
        dz = self.get_parameter("dz").value

        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "left_tcp_link"
        t.child_frame_id  = "left_gripper_link"
        t.transform.translation.x = dx
        t.transform.translation.y = dy
        t.transform.translation.z = dz
        t.transform.rotation.w = 1.0
        self._tf_broadcaster.sendTransform(t)


def main():
    rclpy.init()
    node = GripperTFPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
