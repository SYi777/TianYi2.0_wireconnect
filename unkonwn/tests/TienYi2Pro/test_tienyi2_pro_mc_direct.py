"""TienYi 2.0 Pro motion-controller DIRECT example (via station).

WARNING: this script sends real motion commands. It is interactive by default and pauses before every command.
Keep the robot clear and ready to e-stop.
"""

from __future__ import annotations

import time
from typing import Any

from xrocs.tests.TienYi2Pro._common import build_station, confirm, shutdown_station
from xrocs.utils.logger.logger_loader import logger


def _feedback(feedback_msg: Any) -> None:
    logger.info(f"[feedback] {feedback_msg}")


def example_motor_group_enable(robot) -> None:
    mc = robot.mc
    confirm("mc.enable_arm")
    print("enable_arm", mc.enable_arm(timeout_sec=3.0))


def example_set_arm_mode(robot) -> None:
    confirm("mc.set_arm_mode(3) high stiffness (position loop)")
    print("set_arm_mode(3)", robot.mc.set_arm_mode(3, timeout_sec=3.0))


def example_direct_topics(robot) -> None:
    mc = robot.mc
    direct = robot.mc.direct_ctrler

    confirm("Enable ARM before joint-space topic publishing")
    mc.enable_arm(timeout_sec=3.0)

    confirm("direct_ctrler.pub_jointspace_commands_l (7 DoF)")
    mc.activate_controllers(["jointspace_arm_L_controller"], via_http=True, timeout_sec=3.0)
    direct.pub_jointspace_commands_l([0.1, 0.1, 0.0, -0.4, 0.0, 0.0, 0.3])
    time.sleep(3.0)
    mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)

    confirm("direct_ctrler.pub_jointspace_commands_r (7 DoF)")
    mc.activate_controllers(["jointspace_arm_R_controller"], via_http=True, timeout_sec=3.0)
    direct.pub_jointspace_commands_r([0.1, -0.1, 0.0, -0.4, 0.0, 0.0, -0.3])
    time.sleep(3.0)
    mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)

    confirm("direct_ctrler.pub_endposetarget_l")
    mc.activate_controllers(["endpose_single_arm_qp_L_controller"], via_http=True, timeout_sec=3.0)
    direct.pub_endposetarget_l(
        from_frame="waist_yaw_link",
        to_frame="left_tcp_link",
        target=[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
        offset=[0.0, 0.0, 0.0],
    )
    time.sleep(3.0)
    mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)

    confirm("direct_ctrler.pub_endposetarget_r")
    mc.activate_controllers(["endpose_single_arm_qp_R_controller"], via_http=True, timeout_sec=3.0)
    direct.pub_endposetarget_r(
        from_frame="waist_yaw_link",
        to_frame="right_tcp_link",
        target=[0.1, -0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
        offset=[0.0, 0.0, 0.0],
    )
    time.sleep(3.0)
    mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)


def example_direct_actions(robot) -> None:
    mc = robot.mc
    direct = robot.mc.direct_ctrler

    confirm("Enable ARM before action calls")
    mc.enable_arm(timeout_sec=3.0)

    confirm("direct_ctrler.act_jointspace_arm_L_controller")
    mc.activate_controllers(["jointspace_arm_L_controller"], via_http=True, timeout_sec=3.0)
    print("act_jointspace_arm_L_controller", direct.act_jointspace_arm_L_controller(
        target=[0.1, 0.2, 0.0, -0.2, 0.0, 0.0, 0.0],
        feedback_callback=_feedback,
        timeout_sec=30.0))

    confirm("direct_ctrler.act_jointspace_arm_R_controller")
    mc.activate_controllers(["jointspace_arm_R_controller"], via_http=True, timeout_sec=3.0)
    print("act_jointspace_arm_R_controller", direct.act_jointspace_arm_R_controller(
        target=[0.1, -0.2, 0.0, -0.2, 0.0, 0.0, 0.0],
        feedback_callback=_feedback, timeout_sec=30.0))

    confirm("direct_ctrler.act_endpose_single_arm_qp_L_controller")
    print("act_endpose_single_arm_qp_L_controller", direct.act_endpose_single_arm_qp_L_controller(
        from_frame="waist_yaw_link",
        to_frame="left_tcp_link",
        target=[0.1, 0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
        offset=[0.0, 0.0, 0.0],
        feedback_callback=_feedback,
        timeout_sec=30.0))
    time.sleep(3.0)
    mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)


def example_direct_reachability(robot) -> None:
    direct = robot.mc.direct_ctrler
    confirm("srv_check IK L")
    robot.mc.activate_controllers(["endpose_single_arm_qp_L_controller"], via_http=True, timeout_sec=3.0)
    print("srv_check IK L", direct.srv_check_endpose_single_arm_qp_L_reachability(
        from_frame="waist_yaw_link",
        to_frame="left_tcp_link",
        # target=[0.1, 0.35, -0.3, 0.0, 0.0, 0.0, 1.0],
        target=[0.1, 0.35, -0.7, 0.0, 0.0, 0.0, 1.0],
        offset=[0.0, 0.0, 0.0]))

    confirm("srv_check IK R")
    robot.mc.activate_controllers(["endpose_single_arm_qp_R_controller"], via_http=True, timeout_sec=3.0)
    print("srv_check IK R", direct.srv_check_endpose_single_arm_qp_R_reachability(
        from_frame="waist_yaw_link",
        to_frame="right_tcp_link",
        target=[0.1, -0.35, -0.2, 0.0, 0.0, 0.0, 1.0],
        offset=[0.0, 0.0, 0.0]))
    time.sleep(3.0)
    robot.mc.deactivate_all_controllers(via_http=True, timeout_sec=3.0)


def example_warn_error_info(robot) -> None:
    mc = robot.mc
    print("get_warn_error_info(EAIHardware)", mc.get_warn_error_info(source="EAIHardware", history=5))
    mc.clear_warn_error_info()


def example_disable(robot) -> None:
    mc = robot.mc
    confirm("mc.disable_arm")
    mc.disable_arm(timeout_sec=3.0)


def main() -> None:
    station = None
    try:
        station = build_station()
        robot = station.get_robot_handle().get("robot")

        logger.warning("This script sends MOTION commands. Keep the robot clear and ready to e-stop.")
        confirm("Begin mc_direct examples")

        example_motor_group_enable(robot)
        example_set_arm_mode(robot)
        example_direct_reachability(robot)
        example_direct_topics(robot)
        example_direct_actions(robot)
        example_warn_error_info(robot)
        example_disable(robot)
        logger.success("mc_direct examples finished.")
    except KeyboardInterrupt:
        logger.warning("Interrupted by user.")
    finally:
        shutdown_station(station)


if __name__ == "__main__":
    main()
