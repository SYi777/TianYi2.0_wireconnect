"""TienYi 2.0 Pro motion-controller MoveIt! example (via station).

WARNING: this script sends real motion commands.
It is interactive by default and pauses before every command.
Keep the robot clear and ready to e-stop.
"""

from __future__ import annotations

from xrocs.common.data_type import BaseData, Coordinate, Joints, Pose, PoseArray, Rotation
from xrocs.tests.TienYi2Pro._common import build_station, confirm, shutdown_station
from xrocs.utils.logger.logger_loader import logger


def example_tf_queries(moveit) -> None:
    """Read-only TF frame queries (no motion)."""
    print("get_left_tcp_pose", moveit.get_left_tcp_pose())
    print("get_right_tcp_pose", moveit.get_right_tcp_pose())
    print("get_head_pose", moveit.get_head_pose())
    print("get_head_camera_pose", moveit.get_head_camera_pose())
    print("get_transformation_between_frames(waist->left_tcp)",
        moveit.get_transformation_between_frames("waist_yaw_link", "left_tcp_link"))


def example_joints(moveit) -> None:
    # ---- Left arm (single target point) ----
    confirm("MoveIt! move LEFT arm to a joint target")
    print("reach_joints_and_wait(left_arm)", moveit.reach_joints_and_wait(
        motion_mode="left_arm",
        left_target_joints=Joints([0.1, 0.1, 0.0, -0.4, 0.0, 0.0, 0.2], num_of_dofs=7),
        vel_scale=0.1, acc_scale=0.1, timeout=30.0))

    # ---- Right arm (single target point) ----
    confirm("MoveIt! move RIGHT arm to a joint target")
    print("reach_joints_and_wait(right_arm)", moveit.reach_joints_and_wait(
        motion_mode="right_arm",
        right_target_joints=Joints([0.1, -0.1, 0.0, -0.4, 0.0, 0.0, -0.2], num_of_dofs=7),
        vel_scale=0.1, acc_scale=0.1, timeout=30.0))

    # ---- Dual arm (single target point, non-blocking send + explicit wait) ----
    confirm("MoveIt! move BOTH arms (non-blocking send + explicit wait)")
    accepted = moveit.reach_joints(
        motion_mode="dual_arm",
        left_target_joints=Joints([0.1, 0.2, 0.0, -0.3, 0.0, 0.0, 0.0], num_of_dofs=7),
        right_target_joints=Joints([0.1, -0.2, 0.0, -0.3, 0.0, 0.0, 0.0], num_of_dofs=7),
        vel_scale=0.1, acc_scale=0.1)
    print("reach_joints(dual_arm) accepted", accepted)
    if accepted:
        print("wait_joints_finish", moveit.wait_joints_finish(timeout=30.0))

    # ---- Dual arm (multi-waypoint trajectory) ----
    confirm("MoveIt! move BOTH arms through a 3-point joint trajectory")
    left_trajectory = [
        Joints([0.1, 0.2, 0.0, -0.3, 0.2, 0.0, 0.0], num_of_dofs=7),
        Joints([0.1, 0.2, 0.0, -0.4, 0.3, 0.0, 0.0], num_of_dofs=7),
        Joints([0.1, 0.2, 0.0, -0.4, 0.3, 0.0, 0.2], num_of_dofs=7),
    ]
    right_trajectory = [
        Joints([0.1, -0.2, 0.0, -0.3, 0.2, 0.0, 0.0], num_of_dofs=7),
        Joints([0.1, -0.2, 0.0, -0.4, 0.3, 0.0, 0.0], num_of_dofs=7),
        Joints([0.1, -0.2, 0.0, -0.4, 0.3, 0.0, 0.2], num_of_dofs=7),
    ]
    print("reach_joints_and_wait(dual_arm, multi-waypoint)", moveit.reach_joints_and_wait(
        motion_mode="dual_arm",
        left_target_joints=left_trajectory,
        right_target_joints=right_trajectory,
        vel_scale=0.1, acc_scale=0.1, timeout=60.0))


def example_cartesian(moveit) -> None:
    """Cartesian-space control in the ``waist_yaw_link`` frame.

    Pose layout is [x, y, z, qx, qy, qz, qw] (XYZW quaternion).
    """
    # ---- Left arm (single waypoint) ----
    confirm("MoveIt! move LEFT arm through a Cartesian waypoint (waist_yaw_link)")
    left_waypoints = PoseArray(
        pose_array_data=[[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0]],
        coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
        rotation_form_type=Rotation.FormType.XYZW,
    )
    print("reach_cartesian_and_wait(left_arm)", moveit.reach_cartesian_and_wait(
        group="left_arm", mode="plan_and_execute",
        left_motion_id=1, left_waypoints=left_waypoints,
        vel_scale=0.1, acc_scale=0.1, timeout=30.0))

    # ---- Dual arm (multi-waypoint trajectory) ----
    confirm("MoveIt! move BOTH arms through a 2-point Cartesian trajectory (waist_yaw_link)")
    dual_left_waypoints = PoseArray(
        pose_array_data=[
            [0.1, 0.40, -0.15, 0.0, 0.0, 0.0, 1.0],
            [0.1, 0.3, -0.2, 0.0, 0.0, 0.0, 1.0],
        ],
        coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
        rotation_form_type=Rotation.FormType.XYZW,
    )
    dual_right_waypoints = PoseArray(
        pose_array_data=[
            [0.1, -0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
            [0.1, -0.3, -0.2, 0.0, 0.0, 0.0, 1.0],
        ],
        coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
        rotation_form_type=Rotation.FormType.XYZW,
    )
    print("reach_cartesian_and_wait(dual_arm)", moveit.reach_cartesian_and_wait(
        group="dual_arm", mode="plan_and_execute",
        left_motion_id=0, left_waypoints=dual_left_waypoints,
        right_motion_id=0, right_waypoints=dual_right_waypoints,
        vel_scale=0.1, acc_scale=0.1, timeout=60.0))


def main() -> None:
    station = None
    try:
        station = build_station()
        robot = station.get_robot_handle().get("robot")
        moveit = robot.mc.moveit_ctrler

        logger.warning("This script sends MOTION commands. Keep the robot clear and ready to e-stop.")
        confirm("Begin mc_moveit examples")

        # TF queries are read-only; do them first.
        example_tf_queries(moveit)

        confirm("Enable ARM before MoveIt! joint/cartesian motions")
        robot.mc.enable_arm(timeout_sec=3.0)

        example_joints(moveit)
        example_cartesian(moveit)

        confirm("Disable ARM (clean-up)")
        robot.mc.disable_arm(timeout_sec=3.0)
        logger.success("mc_moveit examples finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
