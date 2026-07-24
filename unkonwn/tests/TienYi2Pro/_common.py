"""Shared helpers for the TienYi 2.0 Pro station example/test scripts."""

from __future__ import annotations

import os
from typing import Optional

from xrocs.entity.robot.TienYi2Pro.tienyi2_pro_ros2 import TienYi2ProRos2Robot
from xrocs.entity.station.TienYi2Pro.tienyi2_pro_ros2_station import TienYi2ProRos2Station
from xrocs.utils.logger.logger_loader import logger


# When False, motion prompts are skipped (read-only / non-interactive runs).
INTERACTIVE: bool = os.environ.get("XROCS_TEST_NONINTERACTIVE", "0") != "1"


def confirm(prompt: str) -> None:
    """Pause until the operator presses ENTER before next step.

    When ``XROCS_TEST_NONINTERACTIVE=1`` the prompt is logged and skipped.

    Args:
        prompt: Description of the next action.
    """
    if INTERACTIVE:
        input(f"\n>>> {prompt}\n    Press ENTER to continue (Ctrl+C to abort)...")
    else:
        logger.info(f">>> [auto] {prompt}")


def build_station() -> TienYi2ProRos2Station:
    """Build the single TienYi 2.0 Pro station instance used by a test script.

    Returns:
        The initialized ``TienYi2ProRos2Station`` (a process-wide singleton).
    """
    robot_dict = {
        "enable": True,
        "controller": {
            "sub_robot_state": True,
            "enable_pin_kine": True,
            "enable_head_controller": True,
            "enable_arm_controller": True,
            "enable_waist_controller": True,
            "enable_leg_controller": True,
            "enable_direct_motion_controller": True,
            "enable_moveit_motion_controller": True,
            "arm": {
                "motor": {
                    "spd": [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
                    # "spd": [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
                    # "spd": [0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1],
                    "cur": [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0]
                },
            },
        }
    }

    hand_dict = {}
    camera_dict = {
        "head": {
            "enable": True,
            "type": "OrbbecCameraRos2",
            "camera_name": "ob_camera_head",
            "use_compress_rgb": True,
            "use_compress_depth": False,
            "is_use_time_synchronizer": True,
        },
    }
    force_sensor_dict = {}
    control_rate_hz = 100.0

    logger.info("Building TienYi2ProRos2Station...")
    station = TienYi2ProRos2Station(
        robot_dict=robot_dict,
        camera_dict=camera_dict,
        hand_dict=hand_dict,
        force_sensor_dict=force_sensor_dict,
        control_rate_hz=control_rate_hz,
    )
    logger.success("Station ready.")
    return station


def shutdown_station(station: Optional[TienYi2ProRos2Station]) -> None:
    """Best-effort station shutdown (releases the shared ROS 2 node)."""
    if station is None:
        return

    try:
        station.shutdown()
    except Exception as e:
        logger.warning(f"Station shutdown raised (ignored): {e}")


def get_robot(station: TienYi2ProRos2Station) -> TienYi2ProRos2Robot:
    """Return the ``TienYi2ProRos2Robot`` handle from the station."""
    return station.get_robot_handle().get("robot")
