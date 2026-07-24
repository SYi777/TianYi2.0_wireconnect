#!/usr/bin/env python3
import os
from telnetlib import NOP
import yaml
import xacro
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
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
            "hardware",
            default_value="sim",
            description="Hardware type: 'sim' for mock components, 'real' for real hardware.",
            choices=["sim", "real"],
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            "auto",
            default_value="false",
            description="controller auto activate: 'true' for auto activate, 'false' for manual activate.",
            choices=["true", "false"],
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "lite_planner",
            default_value="false",
            description="Start arm_lite_planner and spawn inactive MoveIt arm controllers.",
            choices=["true", "false"],
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "controller_manager_timeout",
            default_value="30.0",
            description="Timeout in seconds for controller spawners waiting for controller_manager.",
        )
    )

    # Initialize Arguments
    gui = LaunchConfiguration("gui")
    hardware = LaunchConfiguration("hardware")
    auto_activate = LaunchConfiguration("auto")
    lite_planner = LaunchConfiguration("lite_planner")
    controller_manager_timeout = LaunchConfiguration("controller_manager_timeout")
    

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
            " ",
            "hardware:=",
            hardware,
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

    planning_scene_monitor_parameters = {
        "publish_planning_scene": True,
        "publish_geometry_updates": True,
        "publish_state_updates": True,
        "publish_transforms_updates": True,
    }

    # Load  ExecuteTaskSolutionCapability so we can execute found solutions in simulation
    move_group_capabilities = {
        "capabilities": "move_group/ExecuteTaskSolutionCapability"
    }
    
    # Start the actual move_group node/action server
    run_move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[
            robot_description,
            robot_description_semantic,
            kinematics_yaml,
            joint_limits_yaml,
            ompl_planning_pipeline_config,
            trajectory_execution,
            moveit_simple_controllers_yaml,
            planning_scene_monitor_parameters,
            move_group_capabilities,
        ],
        # remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
    )
    
    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("tianyi2_bringup"),
            "config",
            "tianyi2_controllers.yaml",
        ]
    )
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("tianyi2_bringup"), "rviz", "urdf_config.rviz"]
    )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            robot_controllers,
            {"run_type": hardware},
            {"robot_type": "tianyi2"},
        ],
        output="both",
        remappings=[("~/robot_description", "/xarm_robot_description"), ("/robot_description", "/xarm_robot_description")],
        arguments=["--ros-args", "--log-level", "info"],
    )
    robot_state_pub_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
        remappings=[("/robot_description", "/xarm_robot_description")],
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            robot_description,
            robot_description_semantic,
            ompl_planning_pipeline_config,
            kinematics_yaml,
            joint_limits_yaml,
        ],
        condition=IfCondition(gui),
    )

    # 原有控制器 Spawner
    activate_default_controllers_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    empty_controllers_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "--inactive",
            "empty_L_controller",
            "empty_R_controller",
            "empty_body_controller",
            "empty_head_controller",
        ],
    )

    other_controllers_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["--inactive", 
        "jointspace_arm_L_controller",
        "jointspace_arm_R_controller",
        # "jointspace_dual_arm_controller",
        "endpose_wholebody_controller",
        "jointspace_body_controller",
        "jointspace_body3joints_controller",
        "jointspace_head_controller",
        "jointspace_waist_pitch_controller",
        "jointspace_waist_yaw_controller",
        "jointspace_ruckig_qp_controller",
        "identify_load_L_controller",
        "identify_load_R_controller",
        "endpose_head_controller",
        "endpose_body_controller",
        "endpose_single_arm_qpik_L_controller",
        "endpose_single_arm_qpik_R_controller",
        "jointspace_single_arm_qpik_L_controller",
        "jointspace_single_arm_qpik_R_controller",
        "endpose_single_arm_qp_L_controller",
        "endpose_single_arm_qp_R_controller",
        "endpose_dual_arm_qp_controller",
        "endpose_single_arm_qp2_L_controller",
        "endpose_single_arm_qp2_R_controller",
        # "wholebody_qpik_controller",
        ]
    )

    # Log analyser node for monitoring manipulator warnings and errors
    log_analyser_node = Node(
        package="tools",
        executable="log_analyser",
        name="log_analyser",
        output="screen",
    )

    auto_activate_controllers = Node(
        package="xarm_manager",
        executable="xarm_manager",
        name="xarm_manager",
        output="screen",
        condition=IfCondition(auto_activate),
        parameters=[
            {"robot_type": "tianyi2"},
        ],
    )

    lite_planner_node = Node(
        package="arm_lite_planner",
        executable="arm_lite_planner",
        name="tianyi2_lite_planner",
        output="screen",
        condition=IfCondition(lite_planner),
        parameters=[
            robot_description,
            {"joint_state_topic": "/joint_states"},
            {"base_link": "waist_yaw_link"},
            {"left_tip_link": "left_tcp_link"},
            {"right_tip_link": "right_tcp_link"},
            {"moveit_auto_switch_trigger_topic": "/moveit_commands_dual"},
            {"publish_moveit_auto_switch_trigger": True},
            {"prefer_controller_switch_service": False},
            {"moveit_controller_activation_timeout_sec": 8.0},
            {"left_controller_action": "/moveit_left_arm_controller/follow_joint_trajectory"},
            {"right_controller_action": "/moveit_right_arm_controller/follow_joint_trajectory"},
            {
                "left_joint_names": [
                    "shoulder_pitch_l_joint",
                    "shoulder_roll_l_joint",
                    "shoulder_yaw_l_joint",
                    "elbow_pitch_l_joint",
                    "elbow_yaw_l_joint",
                    "wrist_pitch_l_joint",
                    "wrist_roll_l_joint",
                ]
            },
            {
                "left_joint_lower_limits": [-2.96, -0.262, -2.96, -2.61, -2.96, -0.785, -1.65]
            },
            {
                "left_joint_upper_limits": [2.96, 2.616, 2.96, 0.261, 2.96, 1.05, 1.3]
            },
            {
                "left_joint_velocity_limits": [3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0]
            },
            {
                "left_joint_acceleration_limits": [30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0]
            },
            {
                "right_joint_names": [
                    "shoulder_pitch_r_joint",
                    "shoulder_roll_r_joint",
                    "shoulder_yaw_r_joint",
                    "elbow_pitch_r_joint",
                    "elbow_yaw_r_joint",
                    "wrist_pitch_r_joint",
                    "wrist_roll_r_joint",
                ]
            },
            {
                "right_joint_lower_limits": [-2.96, -2.616, -2.96, -2.61, -2.96, -0.785, -1.3]
            },
            {
                "right_joint_upper_limits": [2.96, 0.262, 2.96, 0.261, 2.96, 1.05, 1.65]
            },
            {
                "right_joint_velocity_limits": [3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0]
            },
            {
                "right_joint_acceleration_limits": [30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0]
            },
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
        condition=IfCondition(lite_planner),
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
        condition=IfCondition(lite_planner),
    )

    ros_log_analyser_node = Node(
        package="tools",
        executable="ros_log_analyser",
        name="ros_log_analyser",
        output="screen",
    )
    camera_head_to_camera_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        arguments=[
            "0", "0", "0",        # xyz
            "1.57", "-1.57", "0",  # rpy
            "camera_head_link",
            "camera_link",
        ],
    )
    nodes = [
        camera_head_to_camera_tf,
        ros_log_analyser_node,
        log_analyser_node,
        TimerAction(
            period=1.0,
            actions=[control_node],
        ),
        TimerAction(
            period=1.5,
            actions=[robot_state_pub_node]
        ),
        TimerAction(
            period=2.0,
            actions=[activate_default_controllers_spawner]
        ),
        TimerAction(
            period=2.5,
            actions=[rviz_node]
        ),
        TimerAction(
            period=3.0,
            actions=[empty_controllers_spawner]
        ),
        TimerAction(
            period=3.5,
            actions=[other_controllers_spawner]
        ),
        TimerAction(
            period=4.0,
            actions=[moveit_left_arm_controller_spawner, moveit_right_arm_controller_spawner]
        ),
        TimerAction(
            period=5.0,
            actions=[auto_activate_controllers]
        ),
        TimerAction(
            period=5.5,
            actions=[lite_planner_node]
        ),
    ]

    return LaunchDescription(declared_arguments + nodes)

