from __future__ import annotations

import traceback
from typing import Any

from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.utils.logger.logger_loader import logger

from xrocs.common.data_type import Joints
from xrocs.entity.robot.TienKung3.tienkung3_ros2 import TienKung3Ros2


def _wait(msg: str) -> None:
    input(f"\n{msg}\nPress ENTER to continue...")


def _feedback_cb_generic(feedback_msg: Any) -> None:
    # Feedback message types differ per action; just print the raw message.
    print(f"[feedback] {feedback_msg}")


def example_pub_topics(robot: TienKung3Ros2) -> None:
    """Test direct-controller `pub_*` APIs with proper enable/disable."""
    if not hasattr(robot, "mc"):
        logger.warning("robot.mc not enabled (controller.enable_direct/moveit_motion_controller=false). Skip MC pub test.")
        return

    mc = robot.mc.direct_ctrler

    print("\n=== [TK3 MC] pub_* topic tests ===")

    # ----
    # Arm
    # _wait("Enable ARM controllers")
    # robot.mc.enable_arm(timeout_sec=3.0)
    # try:
    #     _wait(f"Publish {mc.JOINTSPACE_COMMANDS_L_TOPIC} (7 DoF)")
    #     mc.pub_jointspace_commands_l([-0.1, 0.2, 0.0, 0.0, 0.0, -0.2, -0.3])

    #     _wait(f"Publish {mc.JOINTSPACE_COMMANDS_R_TOPIC} (7 DoF)")
    #     mc.pub_jointspace_commands_r([-0.1, -0.2, 0.0, 0.0, 0.0, -0.2, -0.3])

    #     _wait(f"Publish {mc.ENDPOSETARGET_L_TOPIC}")
    #     mc.pub_endposetarget_l(
    #         from_frame="waist_pitch_link",
    #         to_frame="left_tcp_link",
    #         target=[0.2, 0.26, -0.20, 0.043, 0.0, 0.0, 1.0],
    #         offset=[0.0, 0.0, 0.0],
    #     )

    #     _wait(f"Publish {mc.ENDPOSETARGET_R_TOPIC}")
    #     mc.pub_endposetarget_r(
    #         from_frame="waist_pitch_link",
    #         to_frame="right_tcp_link",
    #         target=[0.0, -0.26, -0.20, 0.043, 0.0, 0.0, 1.0],
    #         offset=[0.0, 0.0, 0.0],
    #     )

    #     _wait(f"Publish {mc.ENDPOSETARGET_DUAL_TOPIC}")
    #     mc.pub_endposetarget_dual(
    #         from_frame_l="waist_pitch_link",
    #         to_frame_l="left_tcp_link",
    #         target_l=[0.0, 0.26, -0.20, 0.043, 0.0, 0.0, 1.0],
    #         offset_l=[0.0, 0.0, 0.0],
    #         from_frame_r="waist_pitch_link",
    #         to_frame_r="right_tcp_link",
    #         target_r=[0.0, -0.26, -0.20, 0.043, 0.0, 0.0, 1.0],
    #         offset_r=[0.0, 0.0, 0.0],
    #         is_dual_arm_syn=False,
    #     )
    # finally:
    #     _wait("Disable ARM controllers")
    #     robot.mc.disable_arm(timeout_sec=3.0)

    # ----
    # Head
    _wait("Enable HEAD controllers")
    robot.mc.enable_head(timeout_sec=3.0)
    try:
        _wait(f"Publish {mc.JOINTSPACE_COMMANDS_HEAD_TOPIC} (len is project-specific)")
        mc.pub_jointspace_commands_head([0.2, 0.2])

        _wait(f"Publish {mc.ENDPOSETARGET_HEAD_TOPIC} (len is project-specific)")
        mc.pub_endposetarget_head([0.0, 0.0])
    finally:
        _wait("Disable HEAD controllers")
        robot.mc.disable_head(timeout_sec=3.0)

def example_act_actions(robot: TienKung3Ros2) -> None:
    """Test direct-controller `act_*` APIs with proper enable/disable."""
    if not hasattr(robot, "mc"):
        logger.warning("robot.mc not enabled (controller.enable_direct/moveit_motion_controller=false). Skip MC action test.")
        return

    mc = robot.mc.direct_ctrler

    print("\n=== [TK3 MC] act_* action tests ===")

    _wait("Enable ARM controllers (for arm actions)")
    robot.mc.enable_arm(timeout_sec=3.0)
    try:
        _wait(f"Call action {mc.JOINTSPACE_ARM_L_CONTROLLER_ACTION_NAME} (7 DoF)")
        success, msg = mc.act_jointspace_arm_L_controller(
            target=[0.0, 0.1, 0.0, -0.2, 0.0, 0.0, 0.0],
            feedback_callback=_feedback_cb_generic,
            timeout_sec=30.0,
        )
        print(f"Result: success={success}, msg={msg}")

        _wait(f"Call action {mc.JOINTSPACE_ARM_R_CONTROLLER_ACTION_NAME} (7 DoF)")
        success, msg = mc.act_jointspace_arm_R_controller(
            target=[0.0, -0.1, 0.0, -0.2, 0.0, 0.0, 0.0],
            feedback_callback=_feedback_cb_generic,
            timeout_sec=30.0,
        )
        print(f"Result: success={success}, msg={msg}")

        _wait(f"Call action {mc.ENDPOSE_SINGLE_ARM_QP_L_CONTROLLER_ACTION_NAME}")
        success, msg = mc.act_endpose_single_arm_qp_L_controller(
            from_frame="waist_pitch_link",
            to_frame="left_tcp_link",
            target=[0.40, 0.20, 0.20, 0.0, 0.0, 0.0, 1.0],
            offset=[0.0, 0.0, 0.0],
            feedback_callback=_feedback_cb_generic,
            timeout_sec=30.0,
        )
        print(f"Result: success={success}, msg={msg}")

        _wait(f"Call action {mc.ENDPOSE_SINGLE_ARM_QP_R_CONTROLLER_ACTION_NAME}")
        success, msg = mc.act_endpose_single_arm_qp_R_controller(
            from_frame="waist_pitch_link",
            to_frame="right_tcp_link",
            target=[0.40, -0.20, 0.20, 0.0, 0.0, 0.0, 1.0],
            offset=[0.0, 0.0, 0.0],
            feedback_callback=_feedback_cb_generic,
            timeout_sec=30.0,
        )
        print(f"Result: success={success}, msg={msg}")
    finally:
        _wait("Disable ARM controllers")
        robot.mc.disable_arm(timeout_sec=3.0)


def example_moveit_joints(robot: TienKung3Ros2) -> None:
    """Test MoveIt! joint-space APIs: left_arm, right_arm, and dual_arm modes."""
    if not hasattr(robot, "mc"):
        logger.warning("robot.mc not enabled (controller.enable_direct/moveit_motion_controller=false). Skip MoveIt! joints test.")
        return

    moveit = robot.mc.moveit_ctrler

    print("\n=== [TK3 MC] MoveIt! joint-space tests ===")

    _wait("Enable ARM controllers (for MoveIt! joint-space control)")
    robot.mc.enable_arm(timeout_sec=3.0)
    try:
        # ---- Left arm ----
        _wait("MoveIt! reach_joints_and_wait — left_arm")
        left_target = Joints([-0.5, 0.5, 0.5, -0.5, -0.5, -0.5, -0.5], num_of_dofs=7)
        success = moveit.reach_joints_and_wait(
            motion_mode="left_arm",
            left_target_joints=left_target,
            vel_scale=0.1,
            acc_scale=0.1,
            timeout=30.0,
        )
        print(f"Result: success={success}")

        # ---- Right arm ----
        _wait("MoveIt! reach_joints_and_wait — right_arm")
        right_target = Joints([-0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5], num_of_dofs=7)
        success = moveit.reach_joints_and_wait(
            motion_mode="right_arm",
            right_target_joints=right_target,
            vel_scale=0.1,
            acc_scale=0.1,
            timeout=30.0,
        )
        print(f"Result: success={success}")

        # ---- Dual arm (non-blocking send + explicit wait) ----
        _wait("MoveIt! reach_joints + wait_joints_finish — dual_arm")
        left_target_dual = Joints([0.0, 0.1, 0.0, -0.3, 0.0, 0.1, 0.0], num_of_dofs=7)
        right_target_dual = Joints([0.0, -0.1, 0.0, -0.3, 0.0, 0.1, 0.0], num_of_dofs=7)
        accepted = moveit.reach_joints(
            motion_mode="dual_arm",
            left_target_joints=left_target_dual,
            right_target_joints=right_target_dual,
            vel_scale=0.1,
            acc_scale=0.1,
        )
        print(f"Request accepted: {accepted}")
        if accepted:
            success = moveit.wait_joints_finish(timeout=30.0)
            print(f"Motion completed: success={success}")
    finally:
        _wait("Disable ARM controllers")
        robot.mc.disable_arm(timeout_sec=3.0)
def main() -> None:
    node = None
    try:
        node = ros2_node_manager.acquire()

        robot_config = {
            "enable": True,
            "controller": {
                "sub_robot_state": False,
                "enable_direct_motion_controller": True,
                "enable_moveit_motion_controller": True,
            },
        }

        robot = TienKung3Ros2(node=node, robot_config=robot_config)

        # NOTE: This script is intentionally interactive to avoid accidentally
        # sending a burst of motion commands to a real robot.
        #example_pub_topics(robot)
        #example_act_actions(robot)
        example_moveit_joints(robot)

    except KeyboardInterrupt:
        print("Interrupted.")
    except Exception as e:
        print(f"Error occurred: {e}")
        traceback.print_exc()
    finally:
        if node is not None:
            ros2_node_manager.release()


if __name__ == "__main__":
    main()
