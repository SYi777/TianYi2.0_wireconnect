"""Example script demonstrating the usage of Franka station driver.

This script shows how to:
1. Initialize and connect to Franka station devices
2. Get robot state (arm, hand)
3. Execute robot actions (arm, hand)

Changelog:
    - 2025-12-18 (Harvey Liu): Create Franka station example script.
"""

import time
import numpy as np

from xrocs.entity.station.FrankaStd.franka_rs_dual_zmq import FrankaDualRS
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
    left_arm_cmd = cur_left_joint + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5])
    right_arm_cmd = cur_right_joint + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5])
    action["arm"] = {"position": {"left": left_arm_cmd, "right": right_arm_cmd}}

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
            "robot": {
                "arm":{
                    "ip":{
                        "left": "172.168.1.5",
                        "right": "172.168.1.5"
                    }
                },
                "hand":{
                    "ip":{
                        "left": "172.168.1.5",
                        "right": "172.168.1.5"
                    }
                }
            },
            "camera":{
                "wrist_left":{
                    "enable": True,
                    "type": "RealSenseCameraRos2",
                    "port": 4281,
                    "host": "127.0.0.1",
                }
            }
        }
    
    
    robot_station = FrankaDualRS(
        robot_dict=config["robot"]["arm"]["ip"],
        hand_dict=config["robot"]["hand"]["ip"],
        camera_dict=config.get("camera", {})
    )
    robot_station.connect()
    time.sleep(1)

    obs = example_get_obs()
    example_execute_action()

    

    