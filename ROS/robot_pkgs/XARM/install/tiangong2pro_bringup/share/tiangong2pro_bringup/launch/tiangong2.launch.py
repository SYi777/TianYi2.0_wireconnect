

#!/usr/bin/env python3
import os
import yaml
import xacro
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, OpaqueFunction
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
            "enable_remappings",
            default_value="true",
            description="Enable topic remappings for compatibility (EAIHardware topics).",
        )
    )

    # Initialize Arguments
    gui = LaunchConfiguration("gui")
    hardware = LaunchConfiguration("hardware")
    enable_remappings = LaunchConfiguration("enable_remappings")

    # Get URDF via xacro
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("tiangong2pro_bringup"),
                    "config",
                    "tiangong2_description.urdf.xacro",
                ]
            ),
            " ",
            "hardware:=",
            hardware,
        ]
    )
    robot_description = {"robot_description": robot_description_content}
    # robot_description_semantic_config = xacro.process_file(
    #     os.path.join(
    #         get_package_share_directory("tianyi2_moveit_config"),
    #         "config",
    #         "tianyi2_description.srdf",
    #     )
    # )
    # robot_description_semantic = {
    #     "robot_description_semantic": robot_description_semantic_config.toxml()
    # }

    # kinematics_yaml = load_yaml(
    #     "tianyi2_moveit_config", "config/kinematics.yaml"
    # )

    # joint_limits_yaml = {
    #     "robot_description_planning": load_yaml(
    #         "tianyi2_moveit_config", "config/joint_limits.yaml"
    #     )
    # }

    # # Planning Functionality
    # ompl_planning_pipeline_config = {
    #     "move_group": {
    #         "planning_plugin": "ompl_interface/OMPLPlanner",
    #         "request_adapters": """default_planner_request_adapters/AddTimeOptimalParameterization default_planner_request_adapters/ResolveConstraintFrames default_planner_request_adapters/FixWorkspaceBounds default_planner_request_adapters/FixStartStateBounds default_planner_request_adapters/FixStartStateCollision default_planner_request_adapters/FixStartStatePathConstraints""",
    #         "start_state_max_bounds_error": 0.1,
    #     }
    # }
    # ompl_planning_yaml = load_yaml(
    #     "tianyi2_moveit_config", "config/ompl_planning.yaml"
    # )
    # ompl_planning_pipeline_config["move_group"].update(ompl_planning_yaml)

    # moveit_simple_controllers_yaml = load_yaml(
    #     "tianyi2_moveit_config", "config/moveit_controllers.yaml"
    # )

    # trajectory_execution = {
    #     "moveit_manage_controllers": True,
    #     "trajectory_execution.allowed_execution_duration_scaling": 1.2,
    #     "trajectory_execution.allowed_goal_duration_margin": 0.5,
    #     "trajectory_execution.allowed_start_tolerance": 0.05,
    # }

    # planning_scene_monitor_parameters = {
    #     "publish_planning_scene": True,
    #     "publish_geometry_updates": True,
    #     "publish_state_updates": True,
    #     "publish_transforms_updates": True,
    # }

    # # Load  ExecuteTaskSolutionCapability so we can execute found solutions in simulation
    # move_group_capabilities = {
    #     "capabilities": "move_group/ExecuteTaskSolutionCapability"
    # }
    
    # # Start the actual move_group node/action server
    # run_move_group_node = Node(
    #     package="moveit_ros_move_group",
    #     executable="move_group",
    #     output="screen",
    #     parameters=[
    #         robot_description,
    #         robot_description_semantic,
    #         kinematics_yaml,
    #         joint_limits_yaml,
    #         ompl_planning_pipeline_config,
    #         trajectory_execution,
    #         moveit_simple_controllers_yaml,
    #         planning_scene_monitor_parameters,
    #         move_group_capabilities,
    #     ],
    #     # remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
    # )
    
    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("tiangong2pro_bringup"),
            "config",
            "tiangong2_controllers.yaml",
        ]
    )
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("tiangong2pro_bringup"), "rviz", "urdf_config.rviz"]
    )

    # 使用OpaqueFunction来根据参数动态创建control_node
    def create_control_node(context):
        enable_remaps = context.launch_configurations.get('enable_remappings', 'true').lower() == 'true'
        
        # 基础remapping（始终需要）
        remappings = [
            ("~/robot_description", "/xarm_robot_description"),
            ("/robot_description", "/xarm_robot_description")
        ]
        
        # 根据参数决定是否添加额外的remapping
        if enable_remaps:
            remappings.extend([
                ("/EAIHardware/arm/cmd_ctrl", "/arm/cmd_ctrl"),
                ("/EAIHardware/arm/cmd_pos", "/arm/cmd_pos"),
                ("/EAIHardware/arm/cmd_vel", "/arm/cmd_vel"),
                ("/EAIHardware/head/cmd_pos", "/head/cmd_pos"),
            ])
        
        control_node = Node(
            package="controller_manager",
            executable="ros2_control_node",
            parameters=[robot_controllers,
            {"run_type": hardware},
            {"robot_type": "tiangong2pro"},
            ],
            output="both",
            remappings=remappings,
            arguments=["--ros-args", "--log-level", "info"],
        )
        
        return [control_node]
    
    # 创建control_node（使用OpaqueFunction）
    control_node_action = OpaqueFunction(function=create_control_node)
    robot_state_pub_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
        remappings=[("/robot_description", "/xarm_robot_description"),
                    ('/joint_states', '/joint_state_broadcaster/joint_states')],  # 重映射 robot_description
    )
        # Static TF
    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        output="log",
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_footprint", "waist_yaw_link"],
    )
    static_tf_base = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        output="log",
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_footprint", "base"],
    )


    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            robot_description,
            # robot_description_semantic,
            # ompl_planning_pipeline_config,
            # kinematics_yaml,
            # joint_limits_yaml,
        ],
        remappings=[('/joint_states', '/joint_state_broadcaster/joint_states')],

        condition=IfCondition(gui),
    )

    # 原有控制器 Spawner
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    other_controllers_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["--inactive", 
        "empty_L_controller", 
        "empty_R_controller",
        "empty_head_controller",
        "jointspace_arm_L_controller",
        "jointspace_arm_R_controller",
        "jointspace_dual_arm_controller",
        "jointspace_head_controller",
        "jointspace_single_arm_qpik_L_controller",
        "jointspace_single_arm_qpik_R_controller",
        "endpose_head_controller",
        "endpose_single_arm_qpik_L_controller",
        "endpose_single_arm_qpik_R_controller",
        "jointspace_ruckig_qp_controller",
        "endpose_single_arm_qp_L_controller",
        "endpose_single_arm_qp_R_controller",
        "endpose_single_arm_qp2_L_controller",
        "endpose_single_arm_qp2_R_controller",
        "endpose_dual_arm_qp_controller",
        ],
    )


    # Log analyser node for monitoring manipulator warnings and errors
    log_analyser_node = Node(
        package="tools",
        executable="log_analyser",
        name="log_analyser",
        output="screen",
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
        control_node_action,
        robot_state_pub_node,
        TimerAction(
            period=1.0,
            actions=[joint_state_broadcaster_spawner]
        ),
        rviz_node,
        static_tf,
        static_tf_base,
        TimerAction(
            period=2.0,
            actions=[other_controllers_spawner]
        ),
    ]

    return LaunchDescription(declared_arguments + nodes)

