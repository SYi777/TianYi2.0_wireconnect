from __future__ import annotations

import time
import numpy as np

from xrocs.utils.trajectory_interpolation import Bezier, Polynomial5Interpolation
from xrocs.entity.station.TienKungDex.tienkung_dex_ros2_station import TienKungDexRos2Station


def example_polynomial_5():
    n_step = 100
    start_pose = np.asarray([0., 0., 0., 0., 0., 0.])
    end_pose = np.asarray([0.1, 0.2, 0.3, 10., 20., 30.])
    ndim = len(start_pose)
    start_v = np.zeros(ndim)
    end_v = np.zeros(ndim)
    start_a = np.zeros(ndim)
    end_a = np.zeros(ndim)
    start_t = np.zeros(ndim)
    end_t = np.asarray([n_step] * ndim)
    polynomial_5_interpolator = Polynomial5Interpolation(start_pose, end_pose, start_v, end_v, start_a, end_a, start_t, end_t)

    time = np.zeros(ndim)
    for step in range(1, n_step + 1):
        point_pos, vel_cmd, acc_cmd = polynomial_5_interpolator.get_point(time + step)
        print(point_pos, vel_cmd, acc_cmd)


def example_bezier_joints():
    start_joints = np.array([0, 0, 0, 0, 0, 0, 0])
    j01 = np.array([-0.5, 0.1, 0.0, -1.1, 0.0, 0.0, 0.0])
    j02 = np.array([-0.5, 0.1, 1.0, -1.1, 0.0, 0.0, 0.0])
    j03 = np.array([-0.5, 0, 0, 0, 0, 0, 0])
    target_joints = np.array([start_joints, j01, j02, j03])
    curve = Bezier._generate_bezier_joint_trajectory(target_joints=target_joints)
    print(curve)


def example_tienkung_dex_left_arm_bezier_curve():
    right_joints = np.array([0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0])
    left_joints_1 = np.array([0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0])
    left_joints_2 = np.array([0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0])
    left_joints_3 = np.array([-0.5, 0.5, 0, 0, 0, 0, 0])
    target_joints = np.array([left_joints_1, left_joints_2, left_joints_3])
    curve = Bezier._generate_bezier_joint_trajectory(target_joints=target_joints, curve_interval_points_num=200)

    robot_config = {
        "enable": True,
        "controller": {
            "enable_dual_arm_controller": True,
        }
    }

    robot_station=TienKungDexRos2Station(robot_dict=robot_config )

    action = {}
    for target_joints in curve:
        action["arm"] = {"position": {"left": target_joints, "right": right_joints}}
        # input("press to continue")
        robot_station.execute_action(action=action)
        time.sleep(0.01)


if __name__ == "__main__":
    example_tienkung_dex_left_arm_bezier_curve()
