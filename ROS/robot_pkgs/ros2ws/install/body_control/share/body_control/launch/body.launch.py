import os

from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
from launch import LaunchDescription


def generate_launch_description():
    # 获取包路径
    body_control_dir = get_package_share_directory("body_control")

    # ros2 params
    body_params = {
        "u2c_sn": "/home/ubuntu/data/param/u2c_sn.yaml",
        "motor_arms_right": os.path.join(body_control_dir, "param/motor_arms7_right.yaml"),
        "motor_arms_left": os.path.join(body_control_dir, "param/motor_arms7_left.yaml"),
        "motor_waist": os.path.join(body_control_dir, "param/motor_waist.yaml"),
        "motor_head": os.path.join(body_control_dir, "param/motor_head.yaml"),
        "motor_legs": os.path.join(body_control_dir, "param/motor_legs.yaml"),
        "sri_6dof": os.path.join(body_control_dir, "param/sri_6dof.yaml"),
        "inspire_hands": os.path.join(body_control_dir, "param/inspire_hands.yaml"),
        "inspire_gripper": os.path.join(body_control_dir, "param", "inspire_gripper.yaml"),
    }

    # # # # # #  所有组件信息 # # # # # #

    ## 本体 -- 组件形式
    body_component = ComposableNode(
        package="body_control",
        plugin="body_control::BodyControl",
        name="bodyctrl_component",
        parameters=[body_params],
    )

    # 组件容器
    components_container = ComposableNodeContainer(
        name="body_container",
        namespace="",
        package="rclcpp_components",
        executable="component_container",
        output="screen",
        composable_node_descriptions=[
            body_component,
        ],
    )

    # 返回 launch 描述
    return LaunchDescription(
        [
            components_container,
        ]
    )
