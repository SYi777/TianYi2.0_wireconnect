"""Launch both D405 wrist cameras on AGX.

Usage (on AGX):
    ros2 launch data_collect wrist_cameras.launch.py

Left:  serial 260522273200  namespace camera_wrist_left
Right: serial 260522275730  namespace camera_wrist
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # Right wrist (260522275730)
        Node(
            package="realsense2_camera",
            executable="realsense2_camera_node",
            name="camera_wrist",
            namespace="camera_wrist",
            parameters=[{
                "serial_no": "260522275730",
                "color_width": 640,
                "color_height": 480,
                "color_fps": 30,
                "depth_width": 640,
                "depth_height": 480,
                "depth_fps": 30,
                "enable_depth": False,  # only color needed for imitation learning
                "enable_infra1": False,
                "enable_infra2": False,
            }],
        ),
        # Left wrist (260522273200)
        Node(
            package="realsense2_camera",
            executable="realsense2_camera_node",
            name="camera_wrist_left",
            namespace="camera_wrist_left",
            parameters=[{
                "serial_no": "260522273200",
                "color_width": 640,
                "color_height": 480,
                "color_fps": 30,
                "depth_width": 640,
                "depth_height": 480,
                "depth_fps": 30,
                "enable_depth": False,
                "enable_infra1": False,
                "enable_infra2": False,
            }],
        ),
    ])
