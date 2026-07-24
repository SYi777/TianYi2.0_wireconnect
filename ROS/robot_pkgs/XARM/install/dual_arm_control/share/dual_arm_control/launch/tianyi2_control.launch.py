import os
import yaml
import xacro
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

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

    sim_flag_arg = DeclareLaunchArgument(
        "sim_flag", default_value="True", description="use sim robot"
    )

    sim_flag = LaunchConfiguration("sim_flag")

    loop_num_arg = DeclareLaunchArgument(
    "loop_num",
    default_value='1'
    )

    loop_num = LaunchConfiguration("loop_num")

    # planning_context
    robot_description_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("tianyi2_moveit_config"),
            "config",
            "tianyi2_description.urdf.xacro",
        )
    )
    robot_description = {"robot_description": robot_description_config.toxml()}

    robot_description_semantic_config = xacro.process_file(
        os.path.join(
            get_package_share_directory("tianyi2_moveit_config"),
            "config",
            "tianyi2_description.srdf",
        )
    )
    robot_description_semantic = {
        "robot_description_semantic": robot_description_semantic_config.toxml()
    }

    joint_limits_yaml = {
        "robot_description_planning": load_yaml(
            "tianyi2_moveit_config", "config/joint_limits.yaml"
        )
    }



    kinematics_yaml = load_yaml(
        "tianyi2_moveit_config", "config/kinematics.yaml"
    )

    control_params = load_yaml(
        "dual_arm_control", "config/control_params.yaml"
    )

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
    # MoveGroupInterface demo executable
    move_group_demo = Node(
        name="dual_arm_main",
        package="dual_arm_control",
        executable="dual_arm_main",
        output="screen",
        parameters=[robot_description,
                    robot_description_semantic,
                    ompl_planning_pipeline_config,
                    joint_limits_yaml,
                    control_params,
                    kinematics_yaml,
                    {"sim_flag": sim_flag},{"loop_num": loop_num}],
        remappings=[('/joint_states', '/joint_state_broadcaster/joint_states'),],
    )

    point_cloud_demo = Node(
        name="point_cloud_filter",
        package="dual_arm_control",
        executable="point_cloud_filter",
        output="screen",
    )

    return LaunchDescription([
        sim_flag_arg,
        loop_num_arg,
        move_group_demo,
        point_cloud_demo
    ])
