import os
import yaml
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory
import xacro


def load_file(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, "r") as file:
            return file.read()
    except EnvironmentError:  # parent of IOError, OSError *and* WindowsError where available
        return None


def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, "r") as file:
            return yaml.safe_load(file)
    except EnvironmentError:  # parent of IOError, OSError *and* WindowsError where available
        return None


def generate_launch_description():

    # Command-line arguments
    tutorial_arg = DeclareLaunchArgument(
        "rviz_tutorial", default_value="False", description="Tutorial flag"
    )

    db_arg = DeclareLaunchArgument(
        "db", default_value="False", description="Database flag"
    )

    # planning_context
    robot_description_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("dual_arm_v2_moveit_config"),
            "config",
            "dual_arm_v2_description.urdf.xacro",
        )
    )
    robot_description = {"robot_description": robot_description_config.toxml()}

    # robot_description_semantic_config = load_file(
    #     "dual_arm_v2_moveit_config", "config/humanoid.srdf"
    # )
    robot_description_semantic_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("dual_arm_v2_moveit_config"),
            "config",
            "dual_arm_v2_description.srdf",
        )
    )
    robot_description_semantic = {
        "robot_description_semantic": robot_description_semantic_config.toxml()
    }

    kinematics_yaml = load_yaml(
        "dual_arm_v2_moveit_config", "config/kinematics.yaml"
    )

    joint_limits_yaml = {
        "robot_description_planning": load_yaml(
            "dual_arm_v2_moveit_config", "config/joint_limits.yaml"
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
        "dual_arm_v2_moveit_config", "config/ompl_planning.yaml"
    )
    ompl_planning_pipeline_config["move_group"].update(ompl_planning_yaml)

    moveit_simple_controllers_yaml = load_yaml(
        "dual_arm_v2_moveit_config", "config/moveit_controllers.yaml"
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

    # Octomap 
    octomap_parameters = {
        "octomap_resolution": 0.05,
        "octomap_frame": "waist_yaw_link",
        "octomap_topic": "octomap_binary",
        "max_range": 5.0,
    }
    octomap_server_node = Node(
        package="octomap_server",
        executable="octomap_server_node",
        name="octomap_server",
        output="screen",
        parameters=[{"frame_id": "camera_link"},octomap_parameters],
    )
    octomap_config = load_yaml('tianyi2_moveit_config', 'config/sensors_3d.yaml')
    octomap_updater = {'octomap_frame': 'waist_yaw_link',
                        'octomap_resolution': 0.05,
                        'max_range': 10.0}
    check_octomap_node = Node(
            package='tianyi2_moveit_config',
            executable='check_octomap_server.py',
            name='octomap_checker',
            output='screen'
        )
    point_cloud_demo = Node(
        name="point_cloud_filter",
        package="dual_arm_control",
        executable="point_cloud_filter",
        output="screen",
    )

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
            octomap_updater,
            octomap_config,
        ],
        remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
    )

    # RViz
    tutorial_mode = LaunchConfiguration("rviz_tutorial")
    rviz_base = os.path.join(get_package_share_directory("dual_arm_v2_moveit_config"), "config")
    rviz_full_config = os.path.join(rviz_base, "moveit.rviz")
    rviz_empty_config = os.path.join(rviz_base, "moveit_empty.rviz")
    rviz_node_tutorial = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_empty_config],
        parameters=[
            robot_description,
            robot_description_semantic,
            ompl_planning_pipeline_config,
            kinematics_yaml,
        ],
        condition=IfCondition(tutorial_mode),
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_full_config],
        # arguments=["-d", LaunchConfiguration(rviz_full_config)],
        parameters=[
            robot_description,
            robot_description_semantic,
            ompl_planning_pipeline_config,
            kinematics_yaml,
            joint_limits_yaml,
        ],
        condition=UnlessCondition(tutorial_mode),
    )

    # Static TF
    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        output="log",
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "world", "base_footprint"],
    )

    # Publish TF
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[robot_description,{"publish_frequency": 200.0}],
        remappings=[("/robot_description", "/xarm_robot_description"),
                    ('/joint_states', '/joint_state_broadcaster/joint_states')],
    )

    # Load controllers
    load_controllers = []
    load_controllers += [
            ExecuteProcess(
                cmd=["ros2 run controller_manager spawner --inactive  moveit_left_arm_controller moveit_right_arm_controller "],
                shell=True,
                output="screen",
            )
        ]

    move_group_demo = Node(
        name="dual_arm_main",
        package="dual_arm_control",
        executable="dual_arm_main",
        output="screen",
        parameters=[robot_description,
                    robot_description_semantic,
                    ompl_planning_pipeline_config,
                    joint_limits_yaml,
                    kinematics_yaml, 
                    {'waist_link': 'waist_yaw_link',}],
        remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
    )
    
    return LaunchDescription(
        [
            tutorial_arg,
            db_arg,
            rviz_node,
            rviz_node_tutorial,
            # static_tf,
            # robot_state_publisher,
            run_move_group_node,
            octomap_server_node,
            check_octomap_node,
            point_cloud_demo,
            move_group_demo
        ]
        + load_controllers
    )
