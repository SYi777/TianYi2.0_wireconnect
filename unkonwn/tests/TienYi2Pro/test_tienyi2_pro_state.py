"""TienYi 2.0 Pro robot-state read-back example (via station).

Read-only: never sends a command, so it is safe to run whenever ``/robot_state`` is being published.
"""

from __future__ import annotations

import time

from xrocs.tests.TienYi2Pro._common import build_station, shutdown_station
from xrocs.utils.logger.logger_loader import logger


def wait_for_state(state, timeout: float = 3.0) -> bool:
    """Block until the first ``/robot_state`` message arrives."""
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        if state._get_state_snapshot() is not None:
            return True
        time.sleep(0.05)
    return False


def example_head_state(state) -> None:
    """Read the head-motor accessors (head motors [1, 2])."""
    print("===== Head Stete =====")
    print("head.pos(list)", state.get_head_pos_list())
    print("head.pos(dict)", state.get_head_pos_dict())
    print("head.speed(list)", state.get_head_speed_list())
    print("head.current(list)", state.get_head_current_list())
    print("head.temperature(list)", state.get_head_temperature_list())
    print("head.mos_temperature(list)", state.get_head_mos_temperature_list())
    print("head.error(dict)", state.get_head_error_dict())


def example_waist_state(state) -> None:
    """Read the waist-motor accessors (waist motors [31, 32, 33])."""
    print("===== Waist Stete =====")
    print("waist.pos(list)", state.get_waist_pos_list())
    print("waist.speed(list)", state.get_waist_speed_list())
    print("waist.current(list)", state.get_waist_current_list())
    print("waist.temperature(list)", state.get_waist_temperature_list())
    print("waist.error(dict)", state.get_waist_error_dict())


def example_leg_state(state) -> None:
    """Read the leg-motor accessors (leg motors [51-56, 61-66])."""
    print("===== Leg Stete =====")
    print("leg.pos(list)", state.get_leg_pos_list())
    print("left_leg.pos(list)", state.get_left_leg_pos_list())
    print("right_leg.pos(list)", state.get_right_leg_pos_list())
    print("leg.error(dict)", state.get_leg_error_dict())


def example_arm_state(state) -> None:
    """Read the arm-motor accessors (arm motors [11-17, 21-27])."""
    print("===== Arm Stete =====")
    print("arm.pos(list)", state.get_arm_pos_list())
    print("left_arm.pos(list)", state.get_left_arm_pos_list())
    print("right_arm.pos(list)", state.get_right_arm_pos_list())
    print("arm.current(list)", state.get_arm_current_list())
    print("arm.error(dict)", state.get_arm_error_dict())


def main() -> None:
    station = None
    try:
        station = build_station()
        robot = station.get_robot_handle().get("robot")
        state = robot.state

        if not wait_for_state(state):
            logger.error("No /robot_state received within timeout. Check the ROS 2 stack.")
            return

        example_head_state(state)
        example_waist_state(state)
        example_leg_state(state)
        example_arm_state(state)
        logger.success("State read-back example finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
