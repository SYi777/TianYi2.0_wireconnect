"""Example script demonstrating the usage of TY station driver.

This script shows how to:
1. Initialize and connect to TY station devices
2. Get robot state (head, arm, waist, leg, hand, force sensor, chassis)
3. Execute robot actions (head, arm, waist, leg, hand, chassis)

Changelog:
    - 2025-12-10 (Harvey Liu): Create TY station example script.
"""

import time
import numpy as np

from xrocs.entity.station.TienYi2.tienyi2_ros2_station import TienYi2Ros2Station
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager

def example_get_obs():
    # 读取状态接口
    '''
    obs = {
        "head_joints": np.ndarray,   # dofs=3, radian   config["robot"]["controller"] 需 enable_head_controller
        "head_pose": np.ndarray,     # dofs=7, xyz(m)+xyzw    head_joints 正解
        "arm_joints": {              # config["robot"]["controller"] 需 enable_dual_arm_controller
            "left": np.ndarray,      # dofs=7 radian
            "right": np.ndarray      # dofs=7,), radian
        },
        "arm_pose": {                # 同上，正解得到 TCP 位姿
            "left": np.ndarray,      # dofs=7, xyz(m)+xyzw
            "right": np.ndarray      # dofs=7, xyz(m)+xyzw
        },
        "waist_joints": np.ndarray,  # dofs=2,, 对应腰部31、32电机； config["robot"]["controller"] 需 enable_waist_controller
        "leg_joints": Any,           # dofs=2,, 对应腰部51、52电机； config["robot"]["controller"] 需 enable_leg_controller
        "hand_joints": {             # 手部关节； config["hand"][hand_name] 需 sub_hand_joints=True
            "left": np.ndarray,
            "right": np.ndarray
        },
        "hand_touch": {              # 手部触觉/力；config["hand"][hand_name] 需 sub_hand_touch=True
            "left": Any,
            "right": Any
        },
        "end_effector_force": {      # 末端力；config["force_sensor"] 需 enable=true, type=Srisensor
            "left": Any,
            "right": Any
        },
        "chassis_state": {           # 底盘状态；config["chassis"] 需 enable=true, type="Slamtec"
            "chassis_twist": np.ndarray,  # dofs=3, 底盘速度 [linear_x, linear_y, angular_z]
    } 
    '''   
    obs = robot_station.get_robot_state()
    print(f"obs:{obs}")
    print(obs.keys())

def example_execute_action():
    # 控制接口
    action = {}
    # 头部控制：station 预期 {"head": {"position": cmd}}
    head_ctrl_mode = 1
    if config.get("robot",{}).get("controller", {}).get("enable_head_controller", False):
        if head_ctrl_mode == 1:
            head_joints_cmd = [
                {"name": 1, "pos": 0.0, "spd": 0.5, "cur": 4.0},
                {"name": 2, "pos": 0.0, "spd": 0.5, "cur": 3.0},
                {"name": 3, "pos": 0.0, "spd": 0.5, "cur": 4.0}
                ]
        elif head_ctrl_mode == 2:
            head_joints_cmd = [0.0, 0.0, 0.1]
        action["head"] = {"position": head_joints_cmd}

    
    if config.get("robot",{}).get("controller", {}).get("enable_dual_arm_controller", False):
        left_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        right_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        action["arm"] = {"position": {"left": left_arm_cmd, "right": right_arm_cmd}}

    # 腰部控制：station 预期 {"waist": {"position/pose": cmd}}
    waist_ctrl_mode = "hold"  
    if config.get("controller", {}).get("enable_waist_controller", False):
        if waist_ctrl_mode == "hold":
            cur_waist_joints = obs.get("waist_pose")
            waist_cmd = [
                {"name": 31, "pos": float(cur_waist_joints[0]), "spd": 1.0, "cur": 10.0},
                {"name": 32, "pos": float(cur_waist_joints[1]), "spd": 1.0, "cur": 10.0}
            ]
            action["waist"] = {"position": waist_cmd}
        elif waist_ctrl_mode == "set":
            waist_cmd = np.array([0.0, 0.0])
            action["waist"] = {"position": waist_cmd}
        elif waist_ctrl_mode == "yaw_only":
            waist_cmd = np.array([0.0])
            action["waist"] = {"pose": waist_cmd}

    # 腿部控制：station 预期 {"leg": {"position": cmd}}
    leg_ctrl_mode = "hold"  
    if config.get("controller", {}).get("enable_leg_controller", False):
        if leg_ctrl_mode == "hold":
            cur_leg_joints = obs.get("leg_pose")
            leg_cmd = [
                {"name": 51, "pos": float(cur_leg_joints[0]), "spd": 1.0, "cur": 10.0},
                {"name": 52, "pos": float(cur_leg_joints[1]), "spd": 1.0, "cur": 10.0}
            ]
        elif leg_ctrl_mode == "set":
            leg_cmd = np.array([0.0, 0.0])
        action["leg"] = {"position": leg_cmd}

    # 手部控制：station 预期 {"hand": {"position": {"left": cmd, "right": cmd}}}
    hand_ctrl_dofs = 1
    hand_handles = robot_station.get_gripper_handle()
    if hand_handles:
        if hand_ctrl_dofs == 1 :
            left_hand_positions  = np.array([0.0])
            right_hand_positions = np.array([0.0])
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

    # 底盘控制：station 预期 {"chassis": [linear_x, linear_y, angular_z]}
    chassis_cmd = np.array([0.5, 0.0, 0.0])  # m/s, m/s, rad/s
    action["chassis"] = chassis_cmd


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
                    "type": "InspireHand3Ros2",
                    "hand_name": "left",
                    "sub_hand_state": True
                },
                "right": {
                    "enable": True,
                    "type": "InspireHand3Ros2",
                    "hand_name": "right",
                    "sub_hand_state": True
                }
            },
            "robot": {
                "enable": True,
                "controller": {
                    "enable_head_controller": True,
                    "sub_head_status": True,
                    "enable_dual_arm_controller": True,
                    "sub_arm_status": True,
                    "enable_dual_arm_freq_change": True,
                    "enable_ros2control": True,
                }
            },
            "force_sensor": {
                "enable": False,
                "type": "Srisensor"
            },
            "chattts": {
                "url": "http://10.10.100.100:9966/tts",
                "http_timeout": 1.0
            },
        }
 
    robot_station = TienYi2Ros2Station(
        robot_dict=config.get("robot", {}),
        camera_dict=config.get("camera", {}),
        hand_dict=config.get("hand", {}),
        force_sensor_dict=config.get("force_sensor", {}),
        control_rate_hz=config.get("basic", {}).get("control_rate_hz", 100)
    )
    time.sleep(1)

    obs = example_get_obs()
    example_execute_action()

    

    