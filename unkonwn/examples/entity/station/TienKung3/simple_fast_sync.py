import numpy as np

from xrocs.core.config_loader import ConfigLoader
from xrocs.entity.camera.camera_loader import camera_loader
from xrocs.entity.hand.hand_loader import hand_loader
from xrocs.entity.robot.TienKung3.tienkung3_ros2 import TienKung3Ros2Robot
from xrocs.entity.tele_agent.tele_agent_loader import tele_agent_loader
from xrocs.utils.logger.logger_loader import logger
from xrocs.utils.Rate import Rate
from xrocs.utils.ros2_node_manager import ros2_node_manager


def init_param(mc):
    kp = list(np.array([20.0, 20.0, 10.0, 10.0, 7.0, 7.0, 7.0, 20.0, 20.0, 10.0, 10.0, 7.0, 7.0, 7.0]) * 1.4)
    kd = list(np.array([1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8]) * 1.2)
    mc.set_param(node_name="EAIHardware", parameter_name="kp", value=kp, timeout_sec=3.0)
    mc.set_param(node_name="EAIHardware", parameter_name="kd", value=kd, timeout_sec=3.0)

    vel_limits = [1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0]  # [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0]
    acc_limits = [1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0]  # [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0]
    jerk_limits = [10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0]  # [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0]
    mc.set_param(node_name="jointspace_arm_L_controller", parameter_name="vel_limits", value=vel_limits, timeout_sec=3.0)
    mc.set_param(node_name="jointspace_arm_L_controller", parameter_name="acc_limits", value=acc_limits, timeout_sec=3.0)
    mc.set_param(node_name="jointspace_arm_L_controller", parameter_name="jerk_limits", value=jerk_limits, timeout_sec=3.0)
    mc.set_param(node_name="jointspace_arm_R_controller", parameter_name="vel_limits", value=vel_limits, timeout_sec=3.0)
    mc.set_param(node_name="jointspace_arm_R_controller", parameter_name="acc_limits", value=acc_limits, timeout_sec=3.0)
    mc.set_param(node_name="jointspace_arm_R_controller", parameter_name="jerk_limits", value=jerk_limits, timeout_sec=3.0)

    mc.enable_arm()

    logger.success("Parameters initialized.")


def activate_js_controller(node):
    from xrocs.entity.robot.TienKungDex.tienkung_dex_ros2_mc import TienKungDexRos2MotionControllerSwitcher
    controller_switcher = TienKungDexRos2MotionControllerSwitcher(node=node)
    controller_switcher.activate(["jointspace_arm_L_controller", "jointspace_arm_R_controller"])


if __name__ == "__main__":
    tele_agent_name = "ServoTeleCore"
    config_path = "/home/eai/Documents/configuration.toml"
    
    cfg_loader = ConfigLoader(config_path)
    cfg_dict = cfg_loader.get_config()
    
    tele_agent = tele_agent_loader.instantiate_tele_agent(name=tele_agent_name)
    node = ros2_node_manager.acquire()

    robot = TienKung3Ros2Robot(node=node, robot_config=cfg_dict.get("robot", {}))
    hand_dict = hand_loader.instantiate_hands(hand_cfgs=cfg_dict.get("hand", {}))
    
    arm = robot.arm_ctrler
    head = robot.head_ctrler
    mc = robot.mc
    direct_ctrler = mc.direct_ctrler
    
    init_param(mc)
    activate_js_controller(node)

    rate = Rate(100.0)
    logger.info("Start teleoperation control...")

    while True:
        # Load action
        action = tele_agent.act_dict()
        # logger.debug(f"action: {action}")
        
        # Arm
        left_arm_position_cmd = action.get('arm', {}).get('position', {}).get('left', [])
        right_arm_position_cmd = action.get('arm', {}).get('position', {}).get('right', [])
        # logger.debug(f"left_arm_position_cmd: {left_arm_position_cmd}")
        # logger.debug(f"right_arm_position_cmd: {right_arm_position_cmd}")
        direct_ctrler.pub_jointspace_commands_l(left_arm_position_cmd)
        direct_ctrler.pub_jointspace_commands_r(right_arm_position_cmd)

        # Hand
        for hand_name, hand in hand_dict.items():
            hand_cmd = action.get('hand', {}).get('position', {}).get(hand_name)
            hand.sync_target_joint(hand_cmd)

        rate.sleep()

    # head.set_cmd_position(target=[0.0, 0.85], timeout=1.0)
