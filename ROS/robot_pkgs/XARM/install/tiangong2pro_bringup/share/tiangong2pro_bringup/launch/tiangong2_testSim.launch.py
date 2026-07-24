#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, TimerAction, SetEnvironmentVariable
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

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

    # Initialize Arguments
    gui = LaunchConfiguration("gui")

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
        ]
    )

    robot_description = {"robot_description": robot_description_content}
    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("tiangong2pro_bringup"),
            "config",
            "tiangong2_test.yaml",
        ]
    )
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("tiangong2pro_bringup"), "rviz", "urdf_config.rviz"]
    )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_controllers],
        output="both",
        remappings=[
            ("~/robot_description", "/robot_description"),
        ],
        arguments=["--ros-args", "--log-level", "info"],  # 设置日志等级为info
    )
    robot_state_pub_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )
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
        condition=IfCondition(gui),
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )


    empty_L_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["empty_L_controller"],
    )

    empty_R_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["empty_R_controller"],
    )

    empty_body_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["empty_body_controller"],
    )

    empty_head_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["empty_head_controller"],
    )


    jointspace_arm_L_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["jointspace_arm_L_controller", "--inactive"],
    )

    jointspace_arm_R_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["jointspace_arm_R_controller", "--inactive"],
    )

    jointspace_body_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["jointspace_body_controller", "--inactive"],
    )

    jointspace_head_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["jointspace_head_controller", "--inactive"],
    )




    # endpose_single_arm_L_controller_spawner2 = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["endpose_single_arm_L_controller_qp", "--inactive"],
    # )

    # endpose_single_arm_R_controller_spawner2 = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["endpose_single_arm_R_controller_qp", "--inactive"],
    # )



    endpose_single_arm_qp_L_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["endpose_single_arm_qp_L_controller", "--inactive"],
    )

    endpose_single_arm_qp_R_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["endpose_single_arm_qp_R_controller", "--inactive"],
    )
    jointspace_ruckig_qp_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["jointspace_ruckig_qp_controller", "--inactive"],
    )
    endpose_dual_arm_qp_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["endpose_dual_arm_qp_controller", "--inactive"],
    )
    nodes = [
        control_node,
        robot_state_pub_node,
        joint_state_broadcaster_spawner,
        rviz_node,
        static_tf,
        static_tf_base,
        # empty_L_controller_spawner,                 # 空控制器，保持当前位置,默认激活
        # empty_R_controller_spawner,
        empty_body_controller_spawner,
        empty_head_controller_spawner,
        jointspace_ruckig_qp_controller_spawner,   # 关节空间 ruckig + qp 控制器，默认不激活
        jointspace_arm_L_controller_spawner,        # 关节控制器 ruckig
        jointspace_arm_R_controller_spawner,
        jointspace_body_controller_spawner,
        jointspace_head_controller_spawner,
        endpose_single_arm_qp_L_controller,             # 单臂 qp
        endpose_single_arm_qp_R_controller,
        endpose_dual_arm_qp_controller,                 # 双臂 qp

        



    ]

    return LaunchDescription(declared_arguments + nodes)

# #!/usr/bin/env python3
# import os
# import yaml
# import xacro
# from launch import LaunchDescription
# from launch.actions import DeclareLaunchArgument, TimerAction
# from launch.conditions import IfCondition
# from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

# from launch_ros.actions import Node
# from launch_ros.substitutions import FindPackageShare
# from ament_index_python.packages import get_package_share_directory

# def load_yaml(package_name, file_path):
#     package_path = get_package_share_directory(package_name)
#     absolute_file_path = os.path.join(package_path, file_path)

#     try:
#         with open(absolute_file_path, "r") as file:
#             return yaml.safe_load(file)
#     except EnvironmentError:  # parent of IOError, OSError *and* WindowsError where available
#         return None

# def generate_launch_description():
#     # Declare arguments
#     declared_arguments = []
#     declared_arguments.append(
#         DeclareLaunchArgument(
#             "gui",
#             default_value="false",
#             description="Start RViz2 automatically with this launch file.",
#         )
#     )

#     # Initialize Arguments
#     gui = LaunchConfiguration("gui")

#     # Get URDF via xacro
#     robot_description_content = Command(
#         [
#             PathJoinSubstitution([FindExecutable(name="xacro")]),
#             " ",
#             PathJoinSubstitution(
#                 [
#                     FindPackageShare("tianyi2_bringup"),
#                     "config",
#                     "tianyi2_description.urdf.xacro",
#                 ]
#             ),
#         ]
#     )
#     robot_description = {"robot_description": robot_description_content}
#     robot_description_semantic_config = xacro.process_file(
#         os.path.join(
#             get_package_share_directory("tianyi2_moveit_config"),
#             "config",
#             "tianyi2_description.srdf",
#         )
#     )
#     robot_description_semantic = {
#         "robot_description_semantic": robot_description_semantic_config.toxml()
#     }

#     kinematics_yaml = load_yaml(
#         "tianyi2_moveit_config", "config/kinematics.yaml"
#     )

#     joint_limits_yaml = {
#         "robot_description_planning": load_yaml(
#             "tianyi2_moveit_config", "config/joint_limits.yaml"
#         )
#     }

#     # Planning Functionality
#     ompl_planning_pipeline_config = {
#         "move_group": {
#             "planning_plugin": "ompl_interface/OMPLPlanner",
#             "request_adapters": """default_planner_request_adapters/AddTimeOptimalParameterization default_planner_request_adapters/ResolveConstraintFrames default_planner_request_adapters/FixWorkspaceBounds default_planner_request_adapters/FixStartStateBounds default_planner_request_adapters/FixStartStateCollision default_planner_request_adapters/FixStartStatePathConstraints""",
#             "start_state_max_bounds_error": 0.1,
#         }
#     }
#     ompl_planning_yaml = load_yaml(
#         "tianyi2_moveit_config", "config/ompl_planning.yaml"
#     )
#     ompl_planning_pipeline_config["move_group"].update(ompl_planning_yaml)

#     moveit_simple_controllers_yaml = load_yaml(
#         "tianyi2_moveit_config", "config/moveit_controllers.yaml"
#     )

#     trajectory_execution = {
#         "moveit_manage_controllers": True,
#         "trajectory_execution.allowed_execution_duration_scaling": 1.2,
#         "trajectory_execution.allowed_goal_duration_margin": 0.5,
#         "trajectory_execution.allowed_start_tolerance": 0.05,
#     }

#     planning_scene_monitor_parameters = {
#         "publish_planning_scene": True,
#         "publish_geometry_updates": True,
#         "publish_state_updates": True,
#         "publish_transforms_updates": True,
#     }

#     # Load  ExecuteTaskSolutionCapability so we can execute found solutions in simulation
#     move_group_capabilities = {
#         "capabilities": "move_group/ExecuteTaskSolutionCapability"
#     }
    
#     # Start the actual move_group node/action server
#     run_move_group_node = Node(
#         package="moveit_ros_move_group",
#         executable="move_group",
#         output="screen",
#         parameters=[
#             robot_description,
#             robot_description_semantic,
#             kinematics_yaml,
#             joint_limits_yaml,
#             ompl_planning_pipeline_config,
#             trajectory_execution,
#             moveit_simple_controllers_yaml,
#             planning_scene_monitor_parameters,
#             move_group_capabilities,
#         ],
#         # remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
#     )
    
#     robot_controllers = PathJoinSubstitution(
#         [
#             FindPackageShare("tianyi2_bringup"),
#             "config",
#             "tianyi2_controllers.yaml",
#         ]
#     )
#     rviz_config_file = PathJoinSubstitution(
#         [FindPackageShare("tianyi2_bringup"), "rviz", "urdf_config.rviz"]
#     )

#     control_node = Node(
#         package="controller_manager",
#         executable="ros2_control_node",
#         parameters=[robot_controllers],
#         output="both",
#         remappings=[("~/robot_description", "/robot_description")],
#         arguments=["--ros-args", "--log-level", "info"],
#     )
#     robot_state_pub_node = Node(
#         package="robot_state_publisher",
#         executable="robot_state_publisher",
#         output="both",
#         parameters=[robot_description],
#     )
#     rviz_node = Node(
#         package="rviz2",
#         executable="rviz2",
#         name="rviz2",
#         output="log",
#         arguments=["-d", rviz_config_file],
#         parameters=[
#             robot_description,
#             robot_description_semantic,
#             ompl_planning_pipeline_config,
#             kinematics_yaml,
#             joint_limits_yaml,
#         ],
#         condition=IfCondition(gui),
#     )

#     # 原有控制器 Spawner
#     joint_state_broadcaster_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["joint_state_broadcaster"],
#     )

#     empty_L_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["empty_L_controller"],
#     )
#     empty_R_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["empty_R_controller"],
#     )
#     empty_body_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["empty_body_controller"],
#     )
#     empty_head_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["empty_head_controller"],
#     )

#     jointspace_arm_L_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_arm_L_controller", "--inactive"],
#     )
#     jointspace_arm_R_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_arm_R_controller", "--inactive"],
#     )
#     jointspace_body_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_body_controller", "--inactive"],
#     )
#     jointspace_head_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_head_controller", "--inactive"],
#     )

#     jointspace_arm_L_collisionfree_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_arm_L_collisionfree_controller", "--inactive"],
#     )
#     jointspace_ruckig_qp_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_ruckig_qp_controller", "--inactive"],
#     )
#     jointspace_arm_R_collisionfree_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["jointspace_arm_R_collisionfree_controller", "--inactive"],
#     )

#     endpose_head_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_head_controller", "--inactive"],
#     )

#     endpose_body_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_body_controller", "--inactive"],
#     )

#     endpose_single_arm_rmp_L_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_single_arm_rmp_L_controller", "--inactive"],
#     )
#     endpose_single_arm_rmp_R_controller_spawner = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_single_arm_rmp_R_controller", "--inactive"],
#     )

#     endpose_single_arm_qp_L_controller = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_single_arm_qp_L_controller", "--inactive"],
#     )

#     endpose_single_arm_qp_R_controller = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_single_arm_qp_R_controller", "--inactive"],
#     )

#     endpose_dual_arm_qp_controller = Node(
#         package="controller_manager",
#         executable="spawner",
#         arguments=["endpose_dual_arm_qp_controller", "--inactive"],
#     )

#     # Log analyser node for monitoring manipulator warnings and errors
#     log_analyser_node = Node(
#         package="tools",
#         executable="log_analyser",
#         name="log_analyser",
#         output="screen",
#     )

#     nodes = [
#         control_node,
#         robot_state_pub_node,
#         joint_state_broadcaster_spawner,
#         rviz_node,
#         log_analyser_node,

#         empty_L_controller_spawner,             # 空控制器
#         empty_R_controller_spawner,
#         empty_body_controller_spawner,
#         empty_head_controller_spawner,
        
#         jointspace_arm_L_controller_spawner,    # 关节空间控制器
#         jointspace_arm_R_controller_spawner,
#         jointspace_body_controller_spawner,
#         jointspace_head_controller_spawner,

#         jointspace_arm_L_collisionfree_controller_spawner,
#         jointspace_arm_R_collisionfree_controller_spawner,
        
#         endpose_head_controller_spawner,        # 头和身体末端控制器
#         endpose_body_controller_spawner,
        
#         endpose_single_arm_rmp_L_controller_spawner,    # 单臂 rmp 
#         endpose_single_arm_rmp_R_controller_spawner,
        
#         endpose_single_arm_qp_L_controller,             # 单臂 qp
#         endpose_single_arm_qp_R_controller,
        
#         endpose_dual_arm_qp_controller,                 # 双臂 qp
        
#     ]

#     return LaunchDescription(declared_arguments + nodes)

