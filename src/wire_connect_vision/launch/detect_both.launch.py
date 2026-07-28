"""Launch detect_both_node with camera params and model paths.

Usage:
    ros2 launch wire_connect_vision detect_both.launch.py
    ros2 launch wire_connect_vision detect_both.launch.py show_display:=true
"""
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory("wire_connect_vision")
    config = os.path.join(pkg_share, "config", "camera.yaml")
    model_port = os.path.join(pkg_share, "models", "port_detect.pt")
    model_plug = os.path.join(pkg_share, "models", "plug_obb.pt")

    show_display_arg = DeclareLaunchArgument(
        "show_display", default_value="false",
        description="Show OpenCV detection window"
    )

    node = Node(
        package="wire_connect_vision",
        executable="detect_both",
        name="detect_both_node",
        output="screen",
        parameters=[
            config,
            {
                "model_port": model_port,
                "model_plug": model_plug,
                "show_display": LaunchConfiguration("show_display"),
            },
        ],
    )

    return LaunchDescription([show_display_arg, node])
