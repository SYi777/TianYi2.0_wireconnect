import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import xacro


def generate_launch_description():
    spawn_moveit_controllers = LaunchConfiguration("spawn_moveit_controllers")
    controller_manager_timeout = LaunchConfiguration("controller_manager_timeout")

    robot_description_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("tiangong2dex_moveit_config"),
            "config",
            "tiangong2dex_upperbody.urdf.xacro",
        )
    )

    planner_node = Node(
        package="arm_lite_planner",
        executable="arm_lite_planner",
        name="tiangong2dex_lite_planner",
        output="screen",
        parameters=[
            {"robot_description": robot_description_config.toxml()},
            {"joint_state_topic": "/joint_state_broadcaster/joint_states"},
            {"base_link": "waist_pitch_link"},
            {"left_tip_link": "left_tcp_link"},
            {"right_tip_link": "right_tcp_link"},
            {"left_controller_action": "/moveit_left_arm_controller/follow_joint_trajectory"},
            {"right_controller_action": "/moveit_right_arm_controller/follow_joint_trajectory"},
            {"control_period_sec": 0.02},
            {"cartesian_step_size": 0.01},
        ],
    )

    moveit_left_arm_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "--inactive",
            "moveit_left_arm_controller",
            "--controller-manager",
            "/controller_manager",
            "--controller-manager-timeout",
            controller_manager_timeout,
        ],
        condition=IfCondition(spawn_moveit_controllers),
    )

    moveit_right_arm_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "--inactive",
            "moveit_right_arm_controller",
            "--controller-manager",
            "/controller_manager",
            "--controller-manager-timeout",
            controller_manager_timeout,
        ],
        condition=IfCondition(spawn_moveit_controllers),
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "spawn_moveit_controllers",
                default_value="true",
                description="Spawn MoveIt arm controllers for trajectory execution.",
            ),
            DeclareLaunchArgument(
                "controller_manager_timeout",
                default_value="30.0",
                description="Timeout in seconds for controller spawner to wait for controller_manager.",
            ),
            moveit_left_arm_controller_spawner,
            moveit_right_arm_controller_spawner,
            planner_node,
        ]
    )
