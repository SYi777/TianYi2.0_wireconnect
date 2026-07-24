from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Include launch files
    package_dir = get_package_share_directory('orbbec_camera')
    launch_file_dir = os.path.join(package_dir, 'launch')
    launch1_include = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'gemini_330_series.launch.py')
        ),
        launch_arguments={
            'camera_name': 'ob_camera_head',
            #'usb_port': '2-3.2',
            'device_num': '1',
            'sync_mode': 'standalone',
            'enable_left_ir': 'false',
            'enable_right_ir': 'false',
        }.items()
    )

    # Launch description
    ld = LaunchDescription([
        GroupAction([launch1_include]),
    ])

    return ld
