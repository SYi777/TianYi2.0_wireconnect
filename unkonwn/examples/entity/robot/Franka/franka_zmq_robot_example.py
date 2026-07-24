"""Example script demonstrating the usage of Franka zmq robot driver.

This script shows how to:
1. Initialize and connect to Franka zmq station devices
2. Get robot state (arm, hand)
3. Execute robot actions (arm, hand)

Changelog:
    - 2025-12-18 (Harvey Liu): Create Franka zmq station example script.
"""

import time
import numpy as np

from xrocs.entity.robot.Franka.franka_zmq import FrankaRobot
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.common.data_type import Coordinate, Joints, Pose, Rotation, BaseData

if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
        robot_config = config["robot"]
    else:
        robot_config = {
            "left":{
                "enable": True,
                "ip": "172.168.1.5",
                },
            "right":{
                "enable": True,
                "ip": "172.168.1.5",
            }
        }
 
    for name, cfg in robot_config.items():
        if not cfg.get("enable", False):
            print(f"Skip '{name}' UR robot initialization.")
            continue
        print(f"Connecting to Franka robot '{name}' at IP: {cfg['ip']}...")
        robot = FrankaRobot(robot_ip=cfg["ip"], arm_type=name)
        robot.connect() # 建立连接
        dofs = robot.num_dofs()
        print(f"'{name}' Franka robot connected. DOFs: {dofs}")
        time.sleep(1)

        # 读取当前机械臂状态
        cur_states = robot.get_current_states()
        print(f"cur_states:{cur_states}")
        first_joints = robot.get_current_joint().get_radian_ndarray()
        print(f"first_joints:{first_joints}")
        first_pose = robot.get_tool_cartesian_pose().get_xyz_m_rpy_radian_ndarray()
        print(f"first_pose:{first_pose}")
        
        joint_cmd = first_joints + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
        joint_cmd = Joints(joint_cmd[:7], 7, BaseData.AngleUnitType.RADIAN)
        input(f"{name}: press enter to reach joint")
        robot.reach_target_joint(joint_cmd)  # 关节空间运动, 低频长距离控制
        input(f"{name}: press enter to sync joint")
        robot.sync_target_joint(first_joints)  # 关节空间运动, 高频短距离控制
        
        tcp_cmd = first_pose + np.array([0.0, 0.0, 0.05, 0.0, 0.0, 0.0])
        tcp_cmd = Pose(Coordinate(tcp_cmd[:3]), Rotation(tcp_cmd[3:], Rotation.FormType.RPY))
        input(f"{name}: press enter to reach pose")
        robot.reach_tool_cartesian_pose(tcp_cmd) # 笛卡尔空间运动, 低频长距离控制
        input(f"{name}: press enter to sync pose")
        tcp_cmd = np.append(first_pose, 0.0) # 填充一维gripper
        robot.sync_tool_cartesian_pose(tcp_cmd) # 笛卡尔空间运动, 高频短距离控制
        
        # 夹爪控制
        input(f"{name}: press enter to sync joint")
        first_joints[7] = 1
        robot.sync_target_joint(first_joints)
        input(f"{name}: press enter to sync pose")
        tcp_cmd = tcp_cmd = np.append(first_pose, 0.5)
        robot.sync_tool_cartesian_pose(tcp_cmd)

        
        



    

    