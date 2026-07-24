"""Example script demonstrating the usage of UR station driver.

This script shows how to:
1. Initialize and connect to UR station devices
2. Get robot state (arm, hand)
3. Execute robot actions (arm, hand)

Changelog:
    - 2025-12-18 (Harvey Liu): Create UR station example script.
"""

import time
import numpy as np

from xrocs.entity.station.UR.ur_station import URStation
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

def example_get_obs():
    # 读取状态接口
    '''
    obs = {
        "arm_joints": {
            "left": np.ndarray,      # dofs=7 radian
            "right": np.ndarray      # dofs=7,), radian
        },
        "arm_pose": {                # 同上，正解得到 TCP 位姿
            "left": np.ndarray,      # dofs=7, xyz(m)+xyzw
            "right": np.ndarray      # dofs=7, xyz(m)+xyzw
        },
        "hand_joints": {             # 手部关节(夹爪为1dofs,灵巧手为6dofs)
            "left": np.ndarray,
            "right": np.ndarray
        },
        "images":{
            "wrist": np.ndarray,
            "top": np.ndarray
        },
        "depths":{
            "wrist": np.ndarray,
            "top": np.ndarray
        },
    } 
    '''   
    obs = robot_station.get_obs()
    print(f"obs:{obs}")
    print(obs.keys())

def example_execute_action():
    # 控制接口
    action = {}

    # 手臂控制：station 预期 {"arm": {"position": {"left": cmd, "right": cmd}}}
    cur_left_joint = robot_station.get_robot_state()["arm_joints"]["left"]
    cur_right_joint = robot_station.get_robot_state()["arm_joints"]["right"]
    left_arm_cmd = cur_left_joint + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0])
    right_arm_cmd = cur_right_joint + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0])
    action["arm"] = {"position": {"left": left_arm_cmd, "right": right_arm_cmd}}

    # 手部控制：station 预期 {"hand": {"position": {"left": cmd, "right": cmd}}}
    hand_ctrl_dofs = 1
    hand_handles = robot_station.get_gripper_handle()
    if hand_handles:
        if hand_ctrl_dofs == 1 :
            left_hand_positions  = np.array([1.0])
            right_hand_positions = np.array([1.0])
        elif hand_ctrl_dofs == 6 :
            left_hand_positions  = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
            right_hand_positions = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
        
        hand_cmd = {}
        if "left" in hand_handles:
            hand_cmd["left"] = left_hand_positions
        if "right" in hand_handles:
            hand_cmd["right"] = right_hand_positions
        action["hand"] = {
            "position": hand_cmd
            }


    # 执行控制
    if action:
        robot_station.execute_action(action)



if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
    else:
        config = {
            "hand": {
                "left": {
                    "enable": True,
                    "type": "Robotiq2f85Ur",
                    "ip": "172.168.1.13"
                },
                "right": {
                    "enable": True,
                    "type": "Robotiq2f85Ur",
                    "ip": "172.168.1.17"
                }
            },
            "robot": {
                "left":{
                    "enable": True,
                    "ip": "172.168.1.13",
                },
                "right":{
                    "enable": True,
                    "ip": "172.168.1.17",
                }
            },
            "camera": {
                "left":{
                    "enable": True,
                    "type": "OrbbecCameraRos2",
                    "camera_name": "left_camera",
                    "use_compress_rgb": True,
                    "use_compress_depth": True,
            },
            }
        }
 
    robot_station = URStation(
        robot_dict=config.get("robot", {}),
        hand_dict=config.get("hand", {}),
        camera_dict=config.get("camera", {}),
        force_sensor_dict=config.get("force_sensor", {}),
        control_rate_hz=config.get("basic", {}).get("control_rate_hz", 100.0)
    )
    robot_station.connect()
    time.sleep(1)

    obs = example_get_obs()
    example_execute_action()

    

    