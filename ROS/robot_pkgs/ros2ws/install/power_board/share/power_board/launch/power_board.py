#!/bin/python3

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    pkg_share = get_package_share_directory("power_board")
    params_file = os.path.join(pkg_share, "config", "params.yaml")

    return LaunchDescription(
        [
            ComposableNodeContainer(
                name="powerboard_container",
                namespace="",
                package="rclcpp_components",
                executable="component_container",
                output="screen",
                emulate_tty=True,
                composable_node_descriptions=[
                    ComposableNode(
                        package="power_board",
                        plugin="powerboard::Node",
                        name="powerboard",
                        parameters=[
                            params_file,
                        ],
                    ),
                ],
            )
        ]
    )
