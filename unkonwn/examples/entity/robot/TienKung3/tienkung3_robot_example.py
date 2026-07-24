"""Example script for TienKung 3.0 ROS 2 robot.

This script is intended to test:
- `xrocs/entity/robot/TienKung3/tienkung3_state_ros2.py` (RobotState subscription + typed accessors)
- Optional motor-group controllers (head/arm/waist/leg)

Steps:
1) Start the ROS 2 stack that publishes `/robot_state` (ros2_bridge_msgs/RobotState).
2) Run this script and observe printed state fields.

Changelog:
    - 2026-03-24(Sunny Gao): Create TienKung 3.0 robot example script.
"""

from __future__ import annotations

import time
import numpy as np

from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.utils.logger.logger_loader import logger

from xrocs.entity.robot.TienKung3.tienkung3_ros2 import TienKung3Ros2
from xrocs.entity.robot.TienKung3.tienkung3_controller.tienkung3_head_controller_ros2 import TienKung3HeadControllerRos2
from xrocs.entity.robot.TienKung3.tienkung3_controller.tienkung3_arm_controller_ros2 import TienKung3ArmControllerRos2
from xrocs.entity.robot.TienKung3.tienkung3_controller.tienkung3_waist_controller_ros2 import TienKung3WaistControllerRos2
from xrocs.entity.robot.TienKung3.tienkung3_pin_kinematics import TienKung3PinKinematics


def _print_if_not_none(name: str, value) -> None:
    if value is None:
        print(f"{name}: None")
    else:
        print(f"{name}: {value}")


# NOTE: Explicit tests for get_xxx_*_dict accessors (no getattr), per request.

def _test_head_dict_accessors(state) -> None:
    print("\n[DICT] head")
    print("\n[DICT] head")
    print("\n[DICT] head")
    # _print_if_not_none("head.status(dict)", state.get_head_status())
    _print_if_not_none("head.pos(dict)", state.get_head_pos_dict())
    _print_if_not_none("head.speed(dict)", state.get_head_speed_dict())
    _print_if_not_none("head.current(dict)", state.get_head_current_dict())
    _print_if_not_none("head.temperature(dict)", state.get_head_temperature_dict())
    _print_if_not_none("head.mos_temperature(dict)", state.get_head_mos_temperature_dict())
    _print_if_not_none("head.error(dict)", state.get_head_error_dict())


def _test_waist_dict_accessors(state) -> None:
    print("\n[DICT] waist")
    print("\n[DICT] waist")
    print("\n[DICT] waist")
    # _print_if_not_none("waist.status(dict)", state.get_waist_status())
    _print_if_not_none("waist.pos(dict)", state.get_waist_pos_dict())
    _print_if_not_none("waist.speed(dict)", state.get_waist_speed_dict())
    _print_if_not_none("waist.current(dict)", state.get_waist_current_dict())
    _print_if_not_none("waist.temperature(dict)", state.get_waist_temperature_dict())
    _print_if_not_none("waist.mos_temperature(dict)", state.get_waist_mos_temperature_dict())
    _print_if_not_none("waist.error(dict)", state.get_waist_error_dict())


def _test_leg_dict_accessors(state) -> None:
    print("\n[DICT] leg")
    print("\n[DICT] leg")
    print("\n[DICT] leg")
    # _print_if_not_none("leg.status(dict)", state.get_leg_status())
    _print_if_not_none("leg.pos(dict)", state.get_leg_pos_dict())
    _print_if_not_none("leg.speed(dict)", state.get_leg_speed_dict())
    _print_if_not_none("leg.current(dict)", state.get_leg_current_dict())
    _print_if_not_none("leg.temperature(dict)", state.get_leg_temperature_dict())
    _print_if_not_none("leg.mos_temperature(dict)", state.get_leg_mos_temperature_dict())
    _print_if_not_none("leg.error(dict)", state.get_leg_error_dict())


def _test_arm_dict_accessors(state) -> None:
    print("\n[DICT] arm")
    print("\n[DICT] arm")
    print("\n[DICT] arm")
    # _print_if_not_none("arm.status(dict)", state.get_arm_status())
    _print_if_not_none("arm.pos(dict)", state.get_arm_pos_dict())
    _print_if_not_none("arm.speed(dict)", state.get_arm_speed_dict())
    _print_if_not_none("arm.current(dict)", state.get_arm_current_dict())
    _print_if_not_none("arm.temperature(dict)", state.get_arm_temperature_dict())
    _print_if_not_none("arm.mos_temperature(dict)", state.get_arm_mos_temperature_dict())
    _print_if_not_none("arm.error(dict)", state.get_arm_error_dict())


def example_tienkung3_state(robot: TienKung3Ros2) -> None:
    """Read and print TienKung 3.0 state fields."""
    if not hasattr(robot, "state"):
        logger.warning("robot.state not enabled (controller.sub_robot_state=false). Skip state test.")
        return

    state = robot.state

    # Wait at least one message.
    timeout = 3.0
    deadline = time.monotonic() + timeout
    # while time.monotonic() < deadline and state._state is None:
    while time.monotonic() < deadline and state._get_state_snapshot() is None:
        time.sleep(0.05)

    # if state._state is None:
    if state._get_state_snapshot() is None:
        raise RuntimeError("No /robot_state received. Please check ROS 2 network and ros2_bridge_msgs.")

    print("\n==== TienKung3 RobotState (parsed) ====")

    # ===== Dict-based accessors (显式调用 get_head_pos_dict 等) =====
    print("\n---- Dict accessors (explicit) ----")
    _test_head_dict_accessors(state)
    _test_waist_dict_accessors(state)
    _test_leg_dict_accessors(state)
    _test_arm_dict_accessors(state)

    # ===== List-based accessors (原有，对照) =====
    print("\n---- List accessors ----")

    # Head
    _print_if_not_none("head.pos(list)", state.get_head_pos_list())
    _print_if_not_none("head.speed(list)", state.get_head_speed_list())
    _print_if_not_none("head.current(list)", state.get_head_current_list())
    _print_if_not_none("head.temperature(list)", state.get_head_temperature_list())
    _print_if_not_none("head.mos_temperature(list)", state.get_head_mos_temperature_list())
    _print_if_not_none("head.error(list)", state.get_head_error_list())

    # Waist
    _print_if_not_none("waist.pos(list)", state.get_waist_pos_list())
    _print_if_not_none("waist.speed(list)", state.get_waist_speed_list())
    _print_if_not_none("waist.current(list)", state.get_waist_current_list())
    _print_if_not_none("waist.temperature(list)", state.get_waist_temperature_list())
    _print_if_not_none("waist.mos_temperature(list)", state.get_waist_mos_temperature_list())
    _print_if_not_none("waist.error(list)", state.get_waist_error_list())

    # Leg
    _print_if_not_none("leg.pos(list)", state.get_leg_pos_list())
    _print_if_not_none("leg.speed(list)", state.get_leg_speed_list())
    _print_if_not_none("leg.current(list)", state.get_leg_current_list())
    _print_if_not_none("leg.temperature(list)", state.get_leg_temperature_list())
    _print_if_not_none("leg.mos_temperature(list)", state.get_leg_mos_temperature_list())
    _print_if_not_none("leg.error(list)", state.get_leg_error_list())

    # Arm
    _print_if_not_none("arm.pos(list)", state.get_arm_pos_list())
    _print_if_not_none("arm.speed(list)", state.get_arm_speed_list())
    _print_if_not_none("arm.current(list)", state.get_arm_current_list())
    _print_if_not_none("arm.temperature(list)", state.get_arm_temperature_list())
    _print_if_not_none("arm.mos_temperature(list)", state.get_arm_mos_temperature_list())
    _print_if_not_none("arm.error(list)", state.get_arm_error_list())

    # IMU
    _print_if_not_none("imu.quaternion(list)", state.get_imu_quaternion_list())
    _print_if_not_none("imu.euler(list)", state.get_imu_euler_list())
    _print_if_not_none("imu.angular_velocity(list)", state.get_imu_angular_velocity_list())
    _print_if_not_none("imu.linear_acceleration(list)", state.get_imu_linear_acceleration_list())
    _print_if_not_none("imu.orientation_covariance(list)", state.get_imu_orientation_covariance_list())
    _print_if_not_none("imu.angular_velocity_covariance(list)", state.get_imu_angular_velocity_covariance_list())
    _print_if_not_none("imu.linear_acceleration_covariance(list)", state.get_imu_linear_acceleration_covariance_list())
    _print_if_not_none("imu.error", state.get_imu_error())


def example_tienkung3_head_controller(robot: TienKung3Ros2) -> None:
    """Test `TienKung3HeadControllerRos2` by publishing a few commands.

    Requires the `/head/cmd` topic to be connected to the robot (or simulator) side.
    """
    if not hasattr(robot, "head_ctrler"):
        logger.warning("robot.head_ctrler not enabled (controller.enable_head_controller=false). Skip head controller test.")
        return

    head: TienKung3HeadControllerRos2 = robot.head_ctrler

    # Two motors per config: [1, 2]
    input("press enter to send head POSITION cmd: [0.0, 0.0] ...")
    head.set_cmd_position([0.0, 0.0], timeout=0.2)
    time.sleep(0.5)

    input("press enter to send head FORCE_POSITION cmd: [0.2, -0.2] ...")
    head.set_cmd_force_position([0.2, 0.2], timeout=0.5)
    time.sleep(0.8)

    input("press enter to send head VELOCITY cmd (dict form, with pos) ...")
    head_names = head._motor_config.names
    head_pos = None
    if hasattr(robot, "state"):
        head_pos = robot.state.get_head_pos_list()
    if not head_pos:
        head_pos = [0.0] * len(head_names)

    head_vel_dicts = [
        {"name": head_names[0], "spd": 0.2, "cur": head._motor_config.cur[0], "pos": float(head_pos[0])},
        {"name": head_names[1], "spd": -0.2, "cur": head._motor_config.cur[1], "pos": float(head_pos[1])},
    ]
    head.set_cmd_velocity(head_vel_dicts, timeout=0.5)
    time.sleep(0.8)
    head.set_cmd_velocity([
        {"name": head_names[0], "spd": 0.0, "cur": head._motor_config.cur[0], "pos": float(head_pos[0])},
        {"name": head_names[1], "spd": 0.0, "cur": head._motor_config.cur[1], "pos": float(head_pos[1])},
    ], timeout=0.2)

    input("press enter to send head DISTANCE cmd: [0.1, -0.1] ...")
    head.set_cmd_distance([0.1, -0.1], timeout=0.5)
    time.sleep(0.8)

    input("press enter to send head POSITION cmd back to [0.0, 0.0] ...")
    head.set_cmd_position([0.0, 0.0], timeout=0.5)
    time.sleep(0.8)

    # Print state again if enabled.
    if hasattr(robot, "state"):
        print("\nAfter head control, read back from /robot_state:")
        _print_if_not_none("head.pos(dict)", robot.state.get_head_pos_dict())
        _print_if_not_none("head.pos(list)", robot.state.get_head_pos_list())


def example_tienkung3_arm_controller(robot: TienKung3Ros2) -> None:
    """Test `TienKung3ArmControllerRos2` by publishing a few commands.

    Requires the `/arm/cmd` topic to be connected to the robot (or simulator) side.

    Note: Arm usually has more DoFs; this example sends small commands to each joint.
    """
    if not hasattr(robot, "arm_ctrler"):
        logger.warning("robot.arm_ctrler not enabled (controller.enable_arm_controller=false). Skip arm controller test.")
        return

    arm: TienKung3ArmControllerRos2 = robot.arm_ctrler

    dof = len(arm._motor_config.names)
    zeros = [0.0] * dof

    input(f"press enter to send arm POSITION cmd (zeros), dof={dof} ...")
    arm.set_cmd_position(zeros, timeout=0.2)
    time.sleep(0.5)

    # Force-position: small target offset on first two joints (if present)
    fp = [-0.1, 0.2, 0.0, 0.0, 0.0, -0.2, -0.3, -0.1, -0.2, 0.0, 0.0, 0.0, -0.2, -0.3]
    input("press enter to send arm FORCE_POSITION cmd ")
    arm.set_cmd_force_position(fp, timeout=0.5)
    time.sleep(0.8)



    input(f"press enter to send arm POSITION cmd (same as FP target), dof={dof} ...")
    arm.set_cmd_position(fp, timeout=0.5)

    # Velocity (dict form, with pos)
    input("press enter to send arm VELOCITY cmd (dict form, with pos) ...")
    arm_names = arm._motor_config.names
    arm_pos = None
    if hasattr(robot, "state"):
        arm_pos = robot.state.get_arm_pos_list()
    if not arm_pos:
        # arm_pos = [-0.2, 0.4, 0.0, 0.0, 0.0, -0.4, -0.6, -0.2, -0.4, 0.0, 0.0, 0.0, -0.4, -0.6]
        arm_pos = [0.0] * len(arm_names)


    arm_vel_dicts = []
    for i, mid in enumerate(arm_names):
        spd = 0.5
        # if i == 5:
        #     spd = -0.3
        # if i == 12:
        #     spd = -0.3
        arm_vel_dicts.append(
            {
                "name": mid,
                "spd": float(spd),
                "cur": arm._motor_config.cur[i],
                "pos": float(arm_pos[i]) if i < len(arm_pos) else 0.0,
            }
        )

    arm_vel_lists = [float(v["spd"]) for v in arm_vel_dicts]
    print(arm_vel_lists)
    print("===================")

    print(arm_vel_dicts)
    input("press enter to send arm VELOCITY cmd (dict form, with pos) ...")
    

    arm.set_cmd_velocity(arm_vel_lists, timeout=1.0)
    # arm.set_cmd_velocity(arm_vel_dicts, timeout=1.0)
    time.sleep(2)
    # arm.set_cmd_velocity([0.0] * dof, timeout=0.2)

    input(f"press enter to send arm POSITION cmd (zeros), dof={dof} ...")
    arm.set_cmd_position(zeros, timeout=0.2)
    time.sleep(0.5)

    # Force-position: small target offset on first two joints (if present)
    fp = [-0.1, 0.2, 0.0, 0.0, 0.0, -0.2, -0.3, -0.1, -0.2, 0.0, 0.0, 0.0, -0.2, -0.3]
    input("press enter to send arm FORCE_POSITION cmd ")
    arm.set_cmd_force_position(fp, timeout=0.5)
    time.sleep(0.8)


    # Distance (incremental)
    dist = [-0.1, 0.2, 0.0, -1, 0.0, -0.2, -0.3, -0.1, -0.2, 0.0, -1, 0.0, -0.2, -0.3]
    input("press enter to send arm DISTANCE cmd")
    arm.set_cmd_distance(dist, timeout=0.5)
    time.sleep(0.8)

    # Current (only supported on arm in this codebase)
    # cur = [1.5,0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
    # input("press enter to send arm CURRENT cmd ")
    # try:
    #     arm.set_cmd_current(cur, timeout=0.5)
    # except NotImplementedError as e:
    #     logger.warning(f"Skip arm CURRENT test: {e}")
    # time.sleep(0.8)

    input("press enter to send arm POSITION cmd back to zeros ...")
    arm.set_cmd_position(zeros, timeout=0.5)
    time.sleep(0.8)

    if hasattr(robot, "state"):
        print("\nAfter arm control, read back from /robot_state:")
        _print_if_not_none("arm.pos(dict)", robot.state.get_arm_pos_dict())
        _print_if_not_none("arm.pos(list)", robot.state.get_arm_pos_list())


def example_tienkung3_waist_controller(robot: TienKung3Ros2) -> None:
    """Test `TienKung3WaistControllerRos2` by publishing a few commands.

    Requires the `/waist/cmd` topic to be connected to the robot (or simulator) side.
    """
    if not hasattr(robot, "waist_ctrler"):
        logger.warning("robot.waist_ctrler not enabled (controller.enable_waist_controller=false). Skip waist controller test.")
        return

    waist: TienKung3WaistControllerRos2 = robot.waist_ctrler

    dof = len(waist._motor_config.names)
    zeros = [0.0] * dof

    input(f"press enter to send waist POSITION cmd (zeros), dof={dof} ...")
    waist.set_cmd_position(zeros, timeout=0.2)
    time.sleep(0.5)

    fp = [0.2,0.2,0.2]
    input("press enter to send waist FORCE_POSITION cmd (small offsets) ...")
    waist.set_cmd_force_position(fp, timeout=0.5)
    time.sleep(0.8)

    # Velocity (dict form, with pos)
    input("press enter to send waist VELOCITY cmd (dict form, with pos) ...")
    waist_names = waist._motor_config.names
    waist_pos = None
    if hasattr(robot, "state"):
        waist_pos = robot.state.get_waist_pos_list()
    if not waist_pos:
        waist_pos = [0.0] * len(waist_names)

    waist_vel_dicts = []
    for i, mid in enumerate(waist_names):
        spd = 0.0
        if i == 0:
            spd = 0.2
        waist_vel_dicts.append(
            {
                "name": int(mid),
                "spd": float(spd),
                "cur": waist._motor_config.cur[i] if i < len(waist._motor_config.cur) else 0.0,
                "pos": float(waist_pos[i]) if i < len(waist_pos) else 0.0,
            }
        )
    waist_vel_lists = [float(v["spd"]) for v in waist_vel_dicts]
    print(waist_vel_lists)
    print("===================")
    print(waist_vel_dicts)  
    input("press enter to send waist VELOCITY cmd ")
    waist.set_cmd_velocity(waist_vel_lists, timeout=0.5)

    # waist.set_cmd_velocity(waist_vel_dicts, timeout=0.5)
    # time.sleep(0.8)
    waist.set_cmd_velocity([
        {
            "name": int(mid),
            "spd": 0.0,
            "cur": waist._motor_config.cur[i] if i < len(waist._motor_config.cur) else 0.0,
            "pos": float(waist_pos[i]) if i < len(waist_pos) else 0.0,
        }
        for i, mid in enumerate(waist_names)
    ], timeout=0.2)

    dist = zeros.copy()
    dist[0] = 0.05
    input("press enter to send waist DISTANCE cmd (small increment) ...")
    waist.set_cmd_distance(dist, timeout=0.5)
    time.sleep(0.8)

    input("press enter to send waist POSITION cmd back to zeros ...")
    waist.set_cmd_position(zeros, timeout=0.5)
    time.sleep(0.8)

    if hasattr(robot, "state"):
        print("\nAfter waist control, read back from /robot_state:")
        _print_if_not_none("waist.pos(dict)", robot.state.get_waist_pos_dict())
        _print_if_not_none("waist.pos(list)", robot.state.get_waist_pos_list())


def example_tienkung3_pin_kinematics() -> None:
    """Smoke test for `tienkung3_pin_kinematics.py` forward kinematics helpers."""
    kin = TienKung3PinKinematics()
    state = robot.state

    head_q = state.get_head_pos_list()
    left_q = state.get_arm_pos_list()[:7] if state.get_arm_pos_list() else [0.0] * 7
    right_q = state.get_arm_pos_list()[7:14] if state.get_arm_pos_list() and len(state.get_arm_pos_list()) >= 14 else [0.0] * 7

    print("\n==== TienKung3PinKinematics FK smoke test ====")
    _print_if_not_none("left_tcp_pose", kin.get_left_tcp_pose(np.array(left_q)))
    _print_if_not_none("right_tcp_pose", kin.get_right_tcp_pose(np.array(right_q)))
    _print_if_not_none("head_pose", kin.get_head_pose(np.array(head_q)))
    _print_if_not_none("head_to_left_tcp_pose", kin.get_head_to_left_tcp_pose(np.array(head_q), np.array(left_q)))
    _print_if_not_none("head_to_right_tcp_pose", kin.get_head_to_right_tcp_pose(np.array(head_q), np.array(right_q)))


if __name__ == "__main__":
    auto_read_config = False

    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
        robot_config = config["robot"]
    else:
        # Minimal config for testing state subscription; controllers are optional.
        robot_config = {
            "enable": True,
            "controller": {
                "enable_pin_kine": False,

                "sub_robot_state": False,
                "enable_head_controller": False,
                "enable_arm_controller": False,
                "enable_waist_controller": True,
                "enable_leg_controller": False,
            },
        }

    node = ros2_node_manager.acquire()
    robot = TienKung3Ros2(node=node, robot_config=robot_config)

    input("press enter to test TienKung3StateRos2... (need /robot_state)")
    example_tienkung3_state(robot)

    input("press enter to test TienKung3HeadControllerRos2... (need /head/cmd consumer)")
    example_tienkung3_head_controller(robot)

    input("press enter to test TienKung3ArmControllerRos2... (need /arm/cmd consumer)")
    example_tienkung3_arm_controller(robot)

    input("press enter to test TienKung3WaistControllerRos2... (need /waist/cmd consumer)")
    example_tienkung3_waist_controller(robot)

    input("press enter to test TienKung3PinKinematics... (no ROS needed)")
    example_tienkung3_pin_kinematics()

    # Keep process alive briefly so you can observe continuous updates if desired.
    input("press enter to exit...")
