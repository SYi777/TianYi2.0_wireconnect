from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
import sys
import yaml
from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
from ament_index_python.packages import get_package_share_directory

# launch 启动入口
def generate_launch_description():
    # 底盘控制
    chassis_install_dir = get_package_share_directory('chassis')
    chassis_params = {
        "chassis_config" : os.path.join(chassis_install_dir, 'param/chassis_param.yaml'),
    }
    chassis_control_node =Node(
        package = "chassis",
        executable = 'chassis_control',
        name = 'chassis_control',
        output = 'screen',
        parameters = [chassis_params]
    )    

    # 返回 launch 描述
    return LaunchDescription([
        chassis_control_node
    ])

