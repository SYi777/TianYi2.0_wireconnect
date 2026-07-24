"""Example script demonstrating the usage of UR robot driver.

This script shows how to:
1. Initialize and connect to UR station devices
2. Get robot state (arm, hand)
3. Execute robot actions (arm, hand)

Changelog:
    - 2025-12-18 (Harvey Liu): Create UR station example script.
"""

import time
import numpy as np

from xrocs.entity.robot.UR.ur import URRobot
from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.common.data_type import Coordinate, Joints, Pose, Rotation, BaseData

def set_parm(robot: URRobot):
    """Set parameters for the UR robot.

    Args:
        robot: An instance of URRobot.
    """
    # Set speed and acceleration
    robot.set_tcp_speed(0.1)  # tcp_speed: The TCP/tool speed of the robot, in m/s.
    robot.set_tcp_acceleration(0.1)  # tcp_acceleration: The TCP/tool acceleration of the robot, in m/s^2.
    robot.set_joint_speed(0.1) # joint_speed: The joint speed of the leading axis, in rad/s.
    robot.set_joint_acceleration(0.1)  # joint_acceleration: The joint acceleration of the leading axis, in rad/s^2.


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
                "ip": "172.168.1.13",
                },
            "right":{
                "enable": True,
                "ip": "172.168.1.17",
            }
        }
 
    for name, cfg in robot_config.items():
        if not cfg.get("enable", False):
            print(f"Skip '{name}' UR robot initialization.")
            continue
        print(f"Connecting to UR robot '{name}' at IP: {cfg['ip']}...")
        robot = URRobot(robot_ip=cfg["ip"])
        robot.connect() # 建立连接
        set_parm(robot)
        dofs = robot.num_dofs()
        print(f"'{name}' UR robot connected. DOFs: {dofs}")
        time.sleep(1)

        # 读取当前机械臂状态
        first_joints = robot.get_current_joint().get_radian_ndarray()
        print(f"first_joints:{first_joints}")
        first_pose = robot.get_tool_cartesian_pose().get_xyz_m_rpy_radian_ndarray()
        print(f"first_pose:{first_pose}")

        joint_cmd = first_joints + np.array([0.05, 0.0, 0.0, 0.0, 0.0, 0.0])
        joint_cmd = Joints(joint_cmd, dofs, BaseData.AngleUnitType.RADIAN)
        input(f"{name}: press enter to reach joint")
        robot.reach_target_joint(joint_cmd)  # 关节空间运动, 低频长距离控制
        input(f"{name}: press enter to sync joint")
        robot.sync_target_joint(first_joints)  # 关节空间运动, 高频短距离控制
        
        tcp_cmd = first_pose + np.array([0.0, 0.0, -0.05, 0.0, 0.0, 0.0])
        tcp_cmd = Pose(Coordinate(tcp_cmd[:3]), Rotation(tcp_cmd[3:], Rotation.FormType.RPY))
        input(f"{name}: press enter to reach pose")
        robot.reach_tool_cartesian_pose(tcp_cmd) # 笛卡尔空间运动, 低频长距离控制
        input(f"{name}: press enter to sync pose")
        robot.sync_tool_cartesian_pose(first_pose) # 笛卡尔空间运动, 高频短距离控制

        
        



    

    