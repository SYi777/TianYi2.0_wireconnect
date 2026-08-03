"""AGX 上三路相机自启动: Orbbec head + 2x D405 wrist.

Usage (on AGX):
    source /opt/ros/humble/setup.bash
    export ROS_DOMAIN_ID=0
    source /home/nvidia/orbbec_camera_ros2/install/setup.bash
    source /home/nvidia/realsense_ros2_ws/install/setup.bash
    source ~/jyh_ws/install/setup.bash
    ros2 launch wire_connect_debug start_all_cameras.launch.py
"""

import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # Orbbec head — use official TianYi launch
    orbbec_share = get_package_share_directory("orbbec_camera")
    head_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(orbbec_share, "launch", "head_330_ty.launch.py")
        ),
    )

    # TF: head_roll_link → ob_camera_head_link (camera mounting offset)
    tf_camera = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="head_to_camera_tf",
        arguments=["0.075", "0.011", "0.074", "0", "0", "0",
                   "head_roll_link", "ob_camera_head_link"],
    )

    # Wrist cameras — direct Node
    wrist_r = Node(
        package="realsense2_camera",
        executable="realsense2_camera_node",
        name="camera_wrist",
        namespace="camera_wrist",
        parameters=[{
            "serial_no": "260522275730",
            "color_width": 640, "color_height": 480, "color_fps": 30,
            "enable_depth": False,
        }],
    )
    wrist_l = Node(
        package="realsense2_camera",
        executable="realsense2_camera_node",
        name="camera_wrist_left",
        namespace="camera_wrist_left",
        parameters=[{
            "serial_no": "260522273200",
            "color_width": 640, "color_height": 480, "color_fps": 30,
            "enable_depth": False,
        }],
    )

    return LaunchDescription([
        tf_camera,
        GroupAction([head_launch]),
        wrist_r,
        wrist_l,
    ])
