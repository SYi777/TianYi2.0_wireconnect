"""Example script for TienKung 3.0 locomotion ROS 2 interface.

This script is intended to test:
- `xrocs/entity/robot/TienKung3/tienkung3_locomotion_ros2.py`

Currently it only tests the *get* interfaces (subscriptions):
- `get_cmd_vel_status()`  from `/hric/robot/cmd_vel_status`
- `get_stand_status()`    from `/hric/robot/stand_status`
- `get_stand_cmd_status()` from `/hric/robot/stand_cmd_status`

Steps:
1) Start the ROS 2 stack that publishes the topics above.
2) Run this script and observe printed fields.

Changelog:
    - 2026-03-27: Create locomotion example script.
"""

from __future__ import annotations

import time

from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.utils.logger.logger_loader import logger

from xrocs.entity.robot.TienKung3.tienkung3_locomotion_ros2 import TienKung3LocomotionRos2


def _print_if_not_none(name: str, value) -> None:
    if value is None:
        print(f"{name}: None")
    else:
        print(f"{name}: {value}")


def example_tienkung3_locomotion_getters(loco: TienKung3LocomotionRos2) -> None:
    """Wait for status messages and print the getter outputs."""

    # Wait up to N seconds for at least one status message.
    timeout = 3.0
    deadline = time.monotonic() + timeout

    last_cmd_vel_status = None
    last_stand_status = None
    last_stand_cmd_status = None

    while time.monotonic() < deadline:
        last_cmd_vel_status = loco.get_cmd_vel_status()
        last_stand_status = loco.get_stand_status()
        last_stand_cmd_status = loco.get_stand_cmd_status()

        if last_cmd_vel_status is not None or last_stand_status is not None or last_stand_cmd_status is not None:
            break

        time.sleep(0.05)

    print("\n==== TienKung3LocomotionRos2 status getters ====")
    _print_if_not_none("cmd_vel_status [vx,vy,vz,vr,vp,vy]", last_cmd_vel_status)
    _print_if_not_none("stand_status    [x,y,z,roll,pitch,yaw]", last_stand_status)
    _print_if_not_none("stand_cmd_status [x,y,z,roll,pitch,yaw]", last_stand_cmd_status)

    # Optional: print a few updates.
    print("\nStreaming a few samples (press Ctrl+C to stop)...")
    for _ in range(10):
        _print_if_not_none("cmd_vel_status", loco.get_cmd_vel_status())
        _print_if_not_none("stand_status", loco.get_stand_status())
        _print_if_not_none("stand_cmd_status", loco.get_stand_cmd_status())
        time.sleep(0.2)


if __name__ == "__main__":
    node = ros2_node_manager.acquire()

    # Enable subscriptions for the get interfaces.
    loco = TienKung3LocomotionRos2(
        node=node,
        sub_cmd_vel_status=True,
        sub_stand_status=True,
        sub_stand_cmd_status=True,
    )

    input("press enter to test TienKung3LocomotionRos2 getters... (need /hric/robot/*_status)")
    try:
        example_tienkung3_locomotion_getters(loco)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        logger.error(f"Locomotion getter test failed: {e}")
        raise

    input("press enter to exit...")
