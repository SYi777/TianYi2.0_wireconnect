import cv2

from xrocs.entity.tele_agent.tele_agent_loader import tele_agent_loader
from xrocs.entity.robot.TienKung3.tienkung3_ros2 import TienKung3Ros2Robot
from xrocs.entity.hand.hand_loader import hand_loader
# from xrocs.entity.hand.Brainco.brainco_hand_2_ros2 import BraincoHand2Ros2
from xrocs.entity.camera.camera_loader import camera_loader
# from xrocs.entity.camera.Orbbec.orbbec_camera_ros2 import OrbbecCameraRos2
from xrocs.utils.camera_utils import CameraUtils
from xrocs.common.data_type import BaseData, Coordinate, Joints, Pose, Rotation, PoseArray


from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.Rate import Rate
import numpy as np


def init_param(mc):
    

    input("enable_arm finished")
    # Robot
    mc.set_param(
        node_name="EAIHardware",
        parameter_name="kp",
        value=[20.0, 20.0, 10.0, 10.0, 7.0, 7.0, 7.0, 
               20.0, 20.0, 10.0, 10.0, 7.0, 7.0, 7.0],
        timeout_sec=3.0
    )

    mc.set_param(
        node_name="EAIHardware",
        parameter_name="kd",
        value=[1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8],
        timeout_sec=3.0
    )

    # Left
    mc.set_param(
        node_name="jointspace_arm_L_controller",
        parameter_name="vel_limits",
        # value=[1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0],
        value=[1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        timeout_sec=3.0
    )
    mc.set_param(
        node_name="jointspace_arm_L_controller",
        parameter_name="acc_limits",
        # value=[1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0],
        value=[10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        timeout_sec=3.0
    )
    mc.set_param(
        node_name="jointspace_arm_L_controller",
        parameter_name="jerk_limits",
        # value=[10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0],
        value=[10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        timeout_sec=3.0
    )
    # Right
    mc.set_param(
        node_name="jointspace_arm_R_controller",
        parameter_name="vel_limits",
        # value=[1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0],
        value=[1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        timeout_sec=3.0
    )
    mc.set_param(
        node_name="jointspace_arm_R_controller",
        parameter_name="acc_limits",
        # value=[1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0],
        value=[10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        timeout_sec=3.0
    )
    mc.set_param(
        node_name="jointspace_arm_R_controller",
        parameter_name="jerk_limits",
        # value=[10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0],
        value=[10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        timeout_sec=3.0
    )

    input("start enable_arm")

    mc.enable_arm()

    print(f"init_param finished")

if __name__ == "__main__":
    config_path = "/home/eai/Documents/configuration.toml"
    # config_path = "/home/nvidia/brianleng/yzmanip/configs/tienkung3_xrocs.toml"
    input("1")
    cfg_loader = ConfigLoader(config_path)
    input("2")
    cfg_dict = cfg_loader.get_config()
    input("3")

    node = ros2_node_manager.acquire()
    input("4")

    robot = TienKung3Ros2Robot(node=node, robot_config=cfg_dict.get("robot", {}))
    input("5")
    from xrocs.entity.robot.TienKungDex.tienkung_dex_ros2_mc import TienKungDexRos2MotionControllerSwitcher
    controller_switcher = TienKungDexRos2MotionControllerSwitcher(node=node)

    arm = robot.arm_ctrler
    head = robot.head_ctrler
    loc = robot.locomotion
    mc = robot.mc
    direct_ctrler = mc.direct_ctrler
    moveit_ctrler = mc.moveit_ctrler

    init_param(mc)
    input("6")
    controller_switcher.activate(["jointspace_arm_L_controller", "jointspace_arm_R_controller"])
    # controller_switcher.switch_controllers(activate=["jointspace_arm_L_controller", "jointspace_arm_R_controller"])
    # Arm
    left_arm_position_cmd = [-0.3, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0]
    right_arm_position_cmd = [-0.3, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0]
    arm_position_cmd = [*left_arm_position_cmd, *right_arm_position_cmd]

    import time
    for idx in range(10):
        direct_ctrler.pub_jointspace_commands_l(left_arm_position_cmd)
        direct_ctrler.pub_jointspace_commands_r(right_arm_position_cmd)
        head.set_cmd_position(target=[0.0, 0.85], timeout=1.0)  # left/right + up/down
        time.sleep(0.1)
        print(f"pub {idx}")

    input(f"continue?")

    controller_switcher.activate(["endpose_single_arm_qp_L_controller", "endpose_single_arm_qp_R_controller"])
    # controller_switcher.switch_controllers(activate=["endpose_single_arm_qp_L_controller", "endpose_single_arm_qp_R_controller"],deactivate=["jointspace_arm_L_controller", "jointspace_arm_R_controller"])

    for idx in range(10):
        direct_ctrler.pub_endposetarget_l(
            from_frame="waist_pitch_link",
            to_frame="left_tcp_link",
            target=[0.2, 0.26, -0.20, 0.043, 0.0, 0.0, 1.0],
            offset=[0.0, 0.0, 0.0],
        )
        direct_ctrler.pub_endposetarget_r(
            from_frame="waist_pitch_link",
            to_frame="right_tcp_link",
            target=[0.0, -0.36, -0.20, 0.043, 0.0, 0.0, 1.0],
            offset=[0.0, 0.0, 0.0],
        )
        time.sleep(0.1)
        print(f"pub {idx}")

    input(f"continue?")
    

    # controller_switcher.activate("moveit_left_arm_controller")
    # controller_switcher.activate("moveit_right_arm_controller")
    controller_switcher.activate(["moveit_left_arm_controller", "moveit_right_arm_controller"])
    # controller_switcher.switch_controllers(activate=["moveit_left_arm_controller", "moveit_right_arm_controller"],deactivate=["endpose_single_arm_qp_L_controller", "endpose_single_arm_qp_R_controller"])

    moveit_ctrler.reach_joints(motion_mode="left_arm", left_target_joints=Joints([-0.3, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0], num_of_dofs=7))
    wait_falg = moveit_ctrler.wait_joints_finish()
    print(f"wait_falg is {wait_falg}")

    input(f"continue?")

    leftpose = np.array([0.27, 0.37, 0.1, -0.15, -0.64, -0.17, 0.73],dtype=float)
    leftway = PoseArray(
        pose_array_data=[leftpose.tolist()],
        coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
        length_unit_type=BaseData.LengthUnitType.METER,
        rotation_form_type=Rotation.FormType.XYZW,
    )
    moveit_ctrler.reach_cartesian_pose(group='left_arm', mode='execute', use_cartesian_path=False, left_waypoints=leftway)
    wait_falgc = moveit_ctrler.wait_cartesian_pose_finish()
    print(f"wait_falgc is {wait_falgc}")

    standstus = loc.get_stand_status()
    print(f"standstus is ",standstus)

    standtarget = [0.09, -0.2, 0.8, 0, 0, 0]

    stand_status = loc.get_stand_status()
    print(f"stand_status is ",stand_status)
    target_stand = [0.0, -0.177, 0.68, 0.0, 0.0]

    # not ready
    # for idx in range(1000):
    #     loc.set_stand_cmd(standtarget, timeout=1.0)
    #     time.sleep(0.1)
    #     print(f"pub {idx}")


    # standstus = loc.get_stand_status()
    # print(f"standstus is ",standstus)
