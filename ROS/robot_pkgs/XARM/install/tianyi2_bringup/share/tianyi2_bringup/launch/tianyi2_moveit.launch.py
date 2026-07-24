#!/usr/bin/env python3
import os
import yaml
import xacro
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory

def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, "r") as file:
            return yaml.safe_load(file)
    except EnvironmentError:  # parent of IOError, OSError *and* WindowsError where available
        return None

def generate_launch_description():
    # Declare arguments
    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            "gui",
            default_value="false",
            description="Start RViz2 automatically with this launch file.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_octomap",
            default_value="false",
            description="Start OctoMap integration for MoveIt.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_demo",
            default_value="true",
            description="Start the dual_arm_main demo node.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_point_cloud_filter",
            default_value="false",
            description="Start the point cloud filter node.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_octomap_checker",
            default_value="false",
            description="Start the OctoMap checker helper node.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "enable_safe_padding",
            default_value="false",
            description="Start the planning scene padding helper node.",
        )
    )

    # Initialize Arguments
    gui = LaunchConfiguration("gui")
    enable_octomap = LaunchConfiguration("enable_octomap")
    enable_demo = LaunchConfiguration("enable_demo")
    enable_point_cloud_filter = LaunchConfiguration("enable_point_cloud_filter")
    enable_octomap_checker = LaunchConfiguration("enable_octomap_checker")
    enable_safe_padding = LaunchConfiguration("enable_safe_padding")
     # Get URDF via xacro
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("tianyi2_bringup"),
                    "config",
                    "tianyi2_complete.urdf.xacro",
                ]
            ),
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    
    robot_description_semantic_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("tianyi2_moveit_config"),
            "config",
            "tianyi2.0_complete.srdf",
        )
    )
    robot_description_semantic = {
        "robot_description_semantic": robot_description_semantic_config.toxml()
    }

    kinematics_yaml = load_yaml(
        "tianyi2_moveit_config", "config/kinematics.yaml"
    )

    joint_limits_yaml = {
        "robot_description_planning": load_yaml(
            "tianyi2_moveit_config", "config/joint_limits.yaml"
        )
    }

    # Planning Functionality
    ompl_planning_pipeline_config = {
        "move_group": {
            "planning_plugin": "ompl_interface/OMPLPlanner",
            "request_adapters": """default_planner_request_adapters/AddTimeOptimalParameterization default_planner_request_adapters/ResolveConstraintFrames default_planner_request_adapters/FixWorkspaceBounds default_planner_request_adapters/FixStartStateBounds default_planner_request_adapters/FixStartStateCollision default_planner_request_adapters/FixStartStatePathConstraints""",
            "start_state_max_bounds_error": 0.1,
        }
    }
    ompl_planning_yaml = load_yaml(
        "tianyi2_moveit_config", "config/ompl_planning.yaml"
    )
    ompl_planning_pipeline_config["move_group"].update(ompl_planning_yaml)

    moveit_simple_controllers_yaml = load_yaml(
        "tianyi2_moveit_config", "config/moveit_controllers.yaml"
    )

    trajectory_execution = {
        "moveit_manage_controllers": True,
        "trajectory_execution.allowed_execution_duration_scaling": 1.2,
        "trajectory_execution.allowed_goal_duration_margin": 0.5,
        "trajectory_execution.allowed_start_tolerance": 0.05,
    }

    # Keep state updates for clients, but stop broadcasting the full planning
    # scene by default to reduce idle CPU usage.
    planning_scene_monitor_parameters = {
        "publish_planning_scene": False,
        "publish_geometry_updates": False,
        "publish_state_updates": True,
        "publish_transforms_updates": False,
    }

    # Load  ExecuteTaskSolutionCapability so we can execute found solutions in simulation
    move_group_capabilities = {
        "capabilities": "move_group/ExecuteTaskSolutionCapability"
    }

    # Octomap
    octomap_parameters = {
        "octomap_resolution": 0.05,
        "octomap_frame": "waist_yaw_link",
        "octomap_topic": "octomap_binary",
        "max_range": 5.0,
    }
    octomap_config = load_yaml('tianyi2_moveit_config', 'config/sensors_3d.yaml')
    octomap_updater = {'octomap_frame': 'waist_yaw_link',
                        'octomap_resolution': 0.05,
                        'max_range': 10.0}
    planning_scene_yaml = load_yaml(
    'tianyi2_moveit_config',
    'config/planning_scene.yaml'
    )
    move_group_common_parameters = [
        robot_description,
        robot_description_semantic,
        kinematics_yaml,
        joint_limits_yaml,
        planning_scene_yaml,
        ompl_planning_pipeline_config,
        trajectory_execution,
        moveit_simple_controllers_yaml,
        planning_scene_monitor_parameters,
        move_group_capabilities,
    ]

    # Start the actual move_group node/action server
    run_move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=move_group_common_parameters,
        condition=UnlessCondition(enable_octomap),
    )
    run_move_group_with_octomap_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=move_group_common_parameters + [
            octomap_updater,
            octomap_config,
        ],
        condition=IfCondition(enable_octomap),
    )
    
    move_group_demo = Node(
        name="dual_arm_main",
        package="dual_arm_control",
        executable="dual_arm_main",
        output="screen",
        condition=IfCondition(enable_demo),
        parameters=[
                    robot_description,
                    robot_description_semantic,
                    ompl_planning_pipeline_config,
                    joint_limits_yaml,
                    kinematics_yaml, 
                    {'waist_link': 'waist_yaw_link',}],
    )
    
    # ----------------------
    # MoveIt 控制器 Spawner (延时启动避免冲突)

    other_controller_spawner = TimerAction(
        period=2.0,
        actions=[Node(
            package="controller_manager",
            executable="spawner",
            arguments=["--inactive", 
            "moveit_left_arm_controller",
            "moveit_right_arm_controller",
            # "moveit_head_controller",
            # "moveit_dual_arm_controller",
            # "moveit_trunk_controller",
            # "moveit_body_controller",
            ]
        )]
    )

    # ----------------------
    point_cloud_demo = Node(
        name="point_cloud_filter",
        package="dual_arm_control",
        executable="point_cloud_filter",
        output="screen",
        condition=IfCondition(enable_point_cloud_filter),
    )

    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("tianyi2_moveit_config"),
                "launch",
                "moveit_rviz.launch.py",
            )
        ),
        condition=IfCondition(gui),
    )

    nodes = [
        run_move_group_node,
        run_move_group_with_octomap_node,
        other_controller_spawner,
        rviz_launch,
        move_group_demo,
        point_cloud_demo,
        Node(
            package="octomap_server",
            executable="octomap_server_node",
            name="octomap_server",
            output="screen",
            parameters=[{"frame_id": "camera_link"}, octomap_parameters],
            condition=IfCondition(enable_octomap),
        ),
        Node(
            package='tianyi2_moveit_config',
            executable='check_octomap_server.py',
            name='octomap_checker',
            output='screen',
            condition=IfCondition(enable_octomap_checker),
        ),
        Node(
            package='tianyi2_moveit_config',
            executable='batch_link_padding.py',
            name='safe_padding',
            output='screen',
            condition=IfCondition(enable_safe_padding),
        )
    ]

    return LaunchDescription(declared_arguments + nodes)