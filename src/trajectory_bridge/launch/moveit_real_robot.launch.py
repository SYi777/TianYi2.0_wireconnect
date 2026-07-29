"""Launch MoveIt move_group + RViz + TrajectoryBridge for real robot control.

Usage:
    source /opt/ros/humble/setup.bash
    source ~/WireConnect_ws/ROS/urdf_ws/install/setup.bash
    source ~/WireConnect_ws/moveit_ws/install/setup.bash
    source ~/WireConnect_ws/ROS/ros2ws/install/setup.bash
    ros2 launch trajectory_bridge moveit_real_robot.launch.py

RViz 中拖拽末端球 → move_group 规划 → bridge 发布 /arm/cmd_pos → 机器人执行
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # ---- args ----
    use_rviz_arg = DeclareLaunchArgument(
        "rviz", default_value="true", description="Launch RViz"
    )

    # ---- MoveIt move_group ----
    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[
            {
                # Use the robot's real /joint_states (via DDS), NOT fake
                "robot_description": "",   # filled by move_group from param server
            },
        ],
        # If the notebook and robot are on the same DDS domain, /joint_states
        # from the robot will be visible directly.
        # remappings=[],
    )

    # ---- Trajectory bridge ----
    bridge_node = Node(
        package="trajectory_bridge",
        executable="trajectory_bridge",
        name="trajectory_bridge",
        output="screen",
    )

    # ---- RViz ----
    rviz_config = os.path.join(
        get_package_share_directory("tianyi2_moveit_config"),
        "config",
        "moveit.rviz",
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config],
        condition=IfCondition(LaunchConfiguration("rviz")),
    )

    return LaunchDescription([
        use_rviz_arg,
        move_group_node,
        bridge_node,
        rviz_node,
    ])
