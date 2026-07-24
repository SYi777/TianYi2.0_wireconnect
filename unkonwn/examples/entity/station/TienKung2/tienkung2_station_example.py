"""Example script demonstrating the usage of TK station driver.

This script shows how to:
1. Initialize and connect to TK station devices
2. Get robot state (head, arm, waist, leg, hand, force sensor)
3. Execute robot actions (head, arm, waist, leg, hand)

Changelog:
    - 2025-12-10 (Harvey Liu): Create TK station example script.
"""

from __future__ import annotations
import time
import numpy as np

from xrocs.entity.station.TienKung2.tienkung2_ros2_station import TienKung2Ros2Station
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
        "waist_pose": np.ndarray,    # dofs=4,, [roll,pitch,yaw,z]； config["robot"]["controller"] 需 enable_waist_controller
        "leg_move_velocity": Any,    # 腿部速度；config["robot"]["controller"] 需 enable_leg_controller
        "hand_joints": {             # 手部关节；config["hand"][hand_name] 需 sub_hand_joints=True
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
        }
    }
    '''   
    obs = robot_station.get_robot_state()
    print(f"obs:{obs}")
    print(obs.keys())

    return obs

def example_execute_action():
    # 控制接口
    action = {}
    # 头部控制：station 预期 {"head": {"position": cmd}}
    head_ctrl_mode = 1
    if robot_config.get("controller", {}).get("enable_head_controller", False):
        if head_ctrl_mode == 1:
            head_joints_cmd = [
                {"name": 1, "pos": 0.0, "spd": 0.5, "cur": 4.0},
                {"name": 2, "pos": 0.0, "spd": 0.5, "cur": 3.0},
                {"name": 3, "pos": 0.0, "spd": 0.5, "cur": 4.0}
                ]
        elif head_ctrl_mode == 2:
            head_joints_cmd = [0.0, 0.0, 0.1]
        action["head"] = {"position": head_joints_cmd}

    
    if robot_config.get("controller", {}).get("enable_dual_arm_controller", False):
        left_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        right_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        action["arm"] = {"position": {"left": left_arm_cmd, "right": right_arm_cmd}}

    # 腰部控制：station 预期 {"waist": {"position": cmd}}
    waist_ctrl_mode = "yaw_only"  
    if robot_config.get("controller", {}).get("enable_waist_controller", False):
        if waist_ctrl_mode == "hold":
            ws = obs.get("waist_pose")
            waist_cmd = np.array([ws.get("roll", 0.0), ws.get("pitch", 0.0), ws.get("yaw", 0.0), ws.get("z", 0.88)])
        elif waist_ctrl_mode == "set":
            waist_cmd = np.array([0.0, 0.0, 0.3, 0.88])
        elif waist_ctrl_mode == "yaw_only":
            waist_cmd = np.array([0.0])
        action["waist"] = {"position": waist_cmd}

    # 腿部控制：station 预期 {"leg": {"move_velocity": [vx,vy,vz,wx,wy,wz]}}
    leg_ctrl_mode = "stop"  # "stop" 静止；"move" 指定速度
    if robot_config.get("controller", {}).get("enable_leg_controller", False):
        if leg_ctrl_mode == "stop":
            leg_vel_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        elif leg_ctrl_mode == "move":
            leg_vel_cmd = [0.05, 0.0, 0.0, 0.0, 0.0, 0.0]  
        action["leg"] = {"move_velocity": leg_vel_cmd}

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

    # 执行控制
    if action:
        input("Press to execute action")
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
                    "sub_hand_state": True,
                    "sub_hand_joints": True
                },
                "right": {
                    "enable": True,
                    "type": "InspireHand3Ros2",
                    "hand_name": "right",
                    "sub_hand_state": True,
                    "sub_hand_joints": True
                }
            },
            "robot": {
                "enable": True,
                "controller": {
                    "enable_head_controller": True,
                    "sub_head_status": True,
                    "enable_dual_arm_controller": True,
                    "sub_arm_status": True,
                    "enable_dual_arm_freq_change": False,
                    "enable_waist_controller": False,
                    "sub_float_base_rpyz_status": False,
                    "enable_leg_controller": False,
                    "sub_leg_vel": False,
                    "enable_moveit_controller": False,
                    },
                "arm": {
                    "mode": "position"
                    }
            },
            "force_sensor": {
                "left": {
                    "enable": True,
                    "type": "SrisensorRos2",
                },
                "right": {
                    "enable": True,
                    "type": "SrisensorRos2",
                }
            },
            "chattts": {
                "url": "http://10.10.100.100:9966/tts",
                "http_timeout": 1.0
            },
        }
    robot_config = config.get("robot", {}) 
    
    robot_station=TienKung2Ros2Station(
        robot_dict=robot_config,
        camera_dict=config.get("camera", {}),
        hand_dict=config.get("hand", {}),
        force_sensor_dict=config.get("force_sensor", {}),
        control_rate_hz=config.get("basic", {}).get("control_rate_hz", 100)
    )
    time.sleep(1)


    obs = example_get_obs()
    example_execute_action()
    
      
    