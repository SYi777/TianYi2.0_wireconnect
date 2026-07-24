"""TienYi 2.0 Pro forward-kinematics example (via station)."""

from __future__ import annotations

import time

import numpy as np

from xrocs.tests.TienYi2Pro._common import build_station, shutdown_station
from xrocs.utils.logger.logger_loader import logger

np.set_printoptions(precision=5, suppress=True)


def get_live_joints(robot):
    """Return (head_q, left_q, right_q) from the live state, falling back to zeros."""
    head_q, left_q, right_q = np.zeros(3), np.zeros(7), np.zeros(7)

    if not hasattr(robot, "state"):
        return head_q, left_q, right_q

    deadline = time.monotonic() + 2.0
    while time.monotonic() < deadline and robot.state._get_state_snapshot() is None:
        time.sleep(0.05)

    head_list = robot.state.get_head_pos_list()
    left_list = robot.state.get_left_arm_pos_list()
    right_list = robot.state.get_right_arm_pos_list()
    if head_list:
        head_q = np.asarray(head_list)
    if left_list:
        left_q = np.asarray(left_list)
    if right_list:
        right_q = np.asarray(right_list)

    print("===== Live State =====")
    print("Head joints", head_q)
    print("Left arm joints", left_q)
    print("Right arm joints", right_q)

    return head_q, left_q, right_q


def example_model_info(kin) -> None:
    """Use the model-introspection helpers."""
    joint_names = kin.get_joint_names()
    print("===== Model Info =====")
    print("#joints", len(joint_names))
    print("joint names", joint_names)
    print("#frames", len(kin.get_all_frame_names()))


def example_fk(kin, head_q, left_q, right_q) -> None:
    """Use the arm / head forward-kinematics helpers."""
    print("===== Forward Kinematics =====")
    print("get_left_tcp_pose", kin.get_left_tcp_pose(left_q).get_xyz_m_xyzw_ndarray())
    print("get_right_tcp_pose", kin.get_right_tcp_pose(right_q).get_xyz_m_xyzw_ndarray())
    print("get_head_pose", kin.get_head_pose(head_q).get_xyz_m_xyzw_ndarray())
    print("get_head_to_left_tcp_pose", kin.get_head_to_left_tcp_pose(head_q, left_q).get_xyz_m_xyzw_ndarray())
    print("get_head_to_right_tcp_pose", kin.get_head_to_right_tcp_pose(head_q, right_q).get_xyz_m_xyzw_ndarray())


def main() -> None:
    """Build the station and run all forward-kinematics examples."""
    station = None
    try:
        station = build_station()
        robot = station.get_robot_handle().get("robot")
        kin = robot.pin_kine

        head_q, left_q, right_q = get_live_joints(robot)
        example_model_info(kin)
        example_fk(kin, head_q, left_q, right_q)
        logger.success("Kinematics examples finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
