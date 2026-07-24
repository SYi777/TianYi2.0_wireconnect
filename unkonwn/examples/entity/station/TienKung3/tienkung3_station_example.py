
from __future__ import annotations
import time
import numpy as np

from xrocs.entity.station.TienKung3.tienkung3_ros2_station import TienKung3Ros2Station
from xrocs.entity.robot.TienKung3.tienkung3_ros2 import TienKung3Ros2Robot
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

if __name__ == "__main__":
    auto_read_config = True
    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
    else:
        pass

    robot_config = config.get("robot", {}) 
    
    # robot_station=TienKung3Ros2Station(
    #     robot_dict=robot_config,
    #     camera_dict=config.get("camera", {}),
    #     hand_dict=config.get("hand", {}),
    #     force_sensor_dict=config.get("force_sensor", {}),
    #     control_rate_hz=config.get("basic", {}).get("control_rate_hz", 100)
    # )
    # time.sleep(1)
    
    # obs = robot_station.get_robot_state()
    # for k, v in obs.items():
    #     print(f"{k}:{v}")
    
    action = {}

    arm_left_cmd = [0.2, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0]
    arm_right_cmd = [0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0]
    action["arm"] = {"position": {"left": arm_left_cmd, "right": arm_right_cmd}}

    
    # input("press to execute")
    # robot: TienKung3Ros2Robot = robot_station.get_robot_handle()["robot"]
    # robot.mc.enable_arm()
    # robot_station.execute_action(action=action)


    from xrocs.utils.ros2_node_manager import ros2_node_manager
    node = ros2_node_manager.acquire()

    robot = TienKung3Ros2Robot(node=node, robot_config=robot_config)
    robot.mc.enable_arm()
    left_arm_position_cmd = action.get('arm', {}).get('position', {}).get('left', [])
    right_arm_position_cmd = action.get('arm', {}).get('position', {}).get('right', [])
    arm_position_cmd = [*left_arm_position_cmd, *right_arm_position_cmd]
    robot.arm_ctrler.set_cmd_position(arm_position_cmd)