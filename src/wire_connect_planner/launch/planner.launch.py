"""Launch cable_tracker for one arm.

Usage:
    ros2 launch wire_connect_planner planner.launch.py arm:=left
    ros2 launch wire_connect_planner planner.launch.py arm:=right
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    arm_arg = DeclareLaunchArgument("arm", default_value="left",
                                     description="Arm to control: left or right")
    test_arg = DeclareLaunchArgument("test_mode", default_value="false",
                                     description="Test mode: TCP + 10cm up, no vision needed")

    node = Node(
        package="wire_connect_planner",
        executable="cable_tracker",
        name="cable_tracker",
        output="screen",
        parameters=[{
            "arm": LaunchConfiguration("arm"),
            "test_mode": LaunchConfiguration("test_mode"),
        }],
    )

    return LaunchDescription([arm_arg, test_arg, node])
