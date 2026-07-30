import os
from launch import LaunchDescription
from launch_ros.actions import Node
from moveit_configs_utils import MoveItConfigsBuilder
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder("tianyi2.0_complete", package_name="tianyi2_moveit_config")
        .planning_pipelines(
            default_planning_pipeline="ompl",
            pipelines={"ompl": {
                "planning_plugin": "ompl_interface/OMPLPlanner",
                "request_adapters": [
                    "default_planning_request_adapters/ResolveConstraintFrames",
                    "default_planning_request_adapters/ValidateWorkspaceBounds",
                    "default_planning_request_adapters/CheckStartStateBounds",
                    "default_planning_request_adapters/CheckStartStateCollision",
                ],
                "response_adapters": [
                    "default_planning_response_adapters/AddTimeOptimalParameterization",
                    "default_planning_response_adapters/ValidateSolution",
                    "default_planning_response_adapters/DisplayMotionPath",
                ],
            }},
        )
        .to_moveit_configs()
    )

    cfg = moveit_config.to_dict()
    # Force: no CHOMP
    cfg["default_planning_pipeline"] = "ompl"
    cfg["planning_pipelines"] = ["ompl"]
    cfg.pop("chomp_planning_pipeline", None)

    node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[cfg],
    )

    return LaunchDescription([node])
