"""基础设施一键启动：TF补全 + joint_states转发 + 轨迹桥接

Usage:
    ros2 launch wire_connect_debug infrastructure.launch.py
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([

        # 1. 相机 TF 链补全 (camera_link → ob_camera_head_link)
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="camera_tf_fix",
            arguments=["0", "0", "0", "0", "0", "0", "camera_link", "ob_camera_head_link"],
            output="log",
        ),

        # 2. joint_relay — 只转发body+arm，手指映射后续再修
        Node(
            package="wire_connect_debug",
            executable="joint_relay",
            name="joint_relay",
            output="screen",
        ),

        # 3. 轨迹桥接 (MoveIt → /jointspace_commands_L/R)
        Node(
            package="trajectory_bridge",
            executable="trajectory_bridge",
            name="trajectory_bridge",
            output="screen",
            parameters=[{"debug": False}],
        ),

    ])
