"""Launch data recording node on notebook.

Usage:
    ros2 launch data_collect record.launch.py
    ros2 launch data_collect record.launch.py obs_window:=10
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("obs_window", default_value="5"),
        DeclareLaunchArgument("head_roll", default_value="0.0"),
        DeclareLaunchArgument("head_pitch", default_value="0.435"),
        DeclareLaunchArgument("head_yaw", default_value="0.0"),
        DeclareLaunchArgument("output_dir", default_value=""),
        DeclareLaunchArgument("episode_prefix", default_value="ep"),

        Node(
            package="data_collect",
            executable="record_episode",
            name="record_episode",
            output="screen",
            parameters=[{
                "obs_window": LaunchConfiguration("obs_window"),
                "head_roll": LaunchConfiguration("head_roll"),
                "head_pitch": LaunchConfiguration("head_pitch"),
                "head_yaw": LaunchConfiguration("head_yaw"),
                "output_dir": LaunchConfiguration("output_dir"),
                "episode_prefix": LaunchConfiguration("episode_prefix"),
            }],
        ),
    ])
