"""TienYi 2.0 Pro motor-group controller example (via station).

Shows how to drive the per-part low-level controllers exposed on the robot handles (``TienKung3ControllerBaseRos2`` API).

WARNING: this script sends real motion commands. It is interactive by default and pauses before every command.
Keep the robot clear and ready to e-stop.
"""

from __future__ import annotations

from xrocs.tests.TienYi2Pro._common import build_station, confirm, shutdown_station
from xrocs.utils.logger.logger_loader import logger


def example_head_controller(robot) -> None:
    """Send a small set of head commands (position / force-position)."""
    head = robot.head_ctrler
    dof = len(head._motor_config.names)
    zeros = [0.0] * dof

    cmds = [
        zeros,
        [0.2, 0.0, 0.0],
        zeros,
        [0.0, 0.2, 0.0],
        zeros,
        [0.0, 0.0, 0.2],
        zeros,
    ]

    for cmd in cmds:
        confirm(f"head_ctrler.set_cmd_position {cmd}")
        head.set_cmd_position(cmd, timeout=3.0, pub_interval=0.1)
        print("head.pos read-back", robot.state.get_head_pos_list())


def example_arm_controller(robot) -> None:
    """Send a small set of arm commands (position / force-position)."""
    arm = robot.arm_ctrler
    dof = len(arm._motor_config.names)
    zeros = [0.0] * dof

    cmds = [
        zeros,
        [-0.5, 0.2, 0.4, -0.5, 0.5, -0.4, -0.3, 0.5, -0.2, -0.4, -0.5, -0.5, -0.4, 0.3],
        zeros,
        [-0.5, 0.2, 0.4, -0.5, 0.5, -0.4, -0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
        zeros,
        [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, -0.2, -0.4, -0.5, -0.5, -0.4, 0.3],
        zeros
    ]
    
    for cmd in cmds:
        confirm(f"arm_ctrler.set_cmd_position {cmd}")
        arm.set_cmd_position(cmd, timeout=3.0, pub_interval=0.1)
        print("arm.pos read-back", robot.state.get_arm_pos_list())


def example_waist_controller(robot) -> None:
    """Send a small set of waist commands (position / force-position)."""
    waist = robot.waist_ctrler
    dof = len(waist._motor_config.names)
    zeros = [0.0] * dof

    cmds = [
        zeros,
        [0.1, 0.0],
        zeros,
        [0.0, 0.1],
        zeros,
    ]

    for cmd in cmds:
        confirm(f"waist_ctrler.set_cmd_position {cmd}")
        waist.set_cmd_position(cmd, timeout=3.0, pub_interval=0.1)
        print("waist.pos read-back", robot.state.get_waist_pos_list())


def example_leg_controller(robot) -> None:
    """Send a small set of leg commands (position / force-position)."""
    leg = robot.leg_ctrler
    dof = len(leg._motor_config.names)
    zeros = [0.0] * dof

    cmds = [
        zeros,
        [-0.05, 0.0],
        zeros,
        [0.0, 0.05],
        zeros,
    ]

    for cmd in cmds:
        confirm(f"leg_ctrler.set_cmd_position {cmd}")
        leg.set_cmd_position(cmd, timeout=3.0, pub_interval=0.1)
        print("leg.pos read-back", robot.state.get_leg_pos_list())


def main() -> None:
    station = None
    try:
        station = build_station()
        robot = station.get_robot_handle().get("robot")

        logger.warning("This script sends MOTION commands. Keep the robot clear and ready to e-stop.")

        confirm("Begin head controller examples")
        example_head_controller(robot)

        confirm("Begin arm controller examples")
        example_arm_controller(robot)

        confirm("Begin waist controller examples")
        example_waist_controller(robot)

        confirm("Begin leg controller examples")
        example_leg_controller(robot)

        logger.success("Controller examples finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
