"""Example script demonstrating the usage of TY robot driver.

This script shows how to:
1. Initialize and connect to TY robot devices
2. Read and Control robot (head, arm, waist, leg, moveit)

Changelog:
    - 2025-12-11 (Harvey Liu): Create TY robot example script.
    - 2026-03-13 (Sunny Gao): Fix ros2controller bugs.
"""

from __future__ import annotations
import time

from xrocs.core.config_loader import ConfigLoader
from xrocs.utils.path_manager import path_manager
from xrocs.entity.robot.TienYi2.tienyi2_ros2 import TienYi2Ros2Robot
from xrocs.utils.ros2_node_manager import ros2_node_manager
from xrocs.common.data_type import BaseData, Coordinate, Joints, Pose, Rotation, PoseArray
from xrocs.utils.logger.logger_loader import logger


def example_tienyi2_head():
    # 头部
    # 获取头部关节值
    head_cur_joints = robot.head_ctrler.get_current_joint() # (roll, pitch, yaw)
    print(f"当前头部关节值: {head_cur_joints}")

    # 头部控制
    head_ctrl_mode = 2
    if robot_config.get("controller", {}).get("enable_head_controller", False):
        if head_ctrl_mode == 1:
            head_joints_cmd = [
                            {"name": 1, "pos": 0.0, "spd": 0.5, "cur": 4.0},
                            {"name": 2, "pos": 0.2, "spd": 0.5, "cur": 3.0},
                            {"name": 3, "pos": 0.0, "spd": 0.75, "cur": 4.0}
                            ]
        elif head_ctrl_mode == 2:
            head_joints_cmd = [0.0, 0.0, 0.0]
        robot.head_ctrler.set_cmd_pos(head_joints_cmd)

def example_tienyi2_arm():
    # 双臂
    dual_arm_controller = robot.dual_arm_ctrler
    # 获取当前双臂关节值
    arm_cur_joints = dual_arm_controller.get_current_joint()
    print(f"当前双臂关节值: {arm_cur_joints}")

    # 双臂控制 (set_cmd_pos,set_cmd_pos_freq_change,set_cmd_ctrl,sync_target_joint, sync_ctrl_target_joint)
    arm_mode = "position"
    if robot_config.get("controller", {}).get("enable_dual_arm_controller", False):
        _enable_freq_change = robot_config.get("controller", {}).get("enable_dual_arm_freq_change", False)
        left_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        right_arm_cmd = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        arm_joints_cmd = left_arm_cmd+right_arm_cmd
        if arm_mode == "position":
            dual_arm_controller.sync_target_joint(arm_joints_cmd, flex_freq=_enable_freq_change)
        elif arm_mode == "hybrid":
            dual_arm_controller.sync_ctrl_target_joint(arm_joints_cmd)
    
    # 双臂速度控制测试(set_cmd_vel)
        time.sleep(2)
        print("测试双臂速度接口")
        move_time = 1
        start_time = time.monotonic()
        while time.monotonic() - start_time  < move_time:
            dual_arm_controller.set_cmd_vel(
                [
                    {"name": 14, "spd": -0.1, "cur": 15.0},
                ]
            )
            time.sleep(0.01)
        start_time = time.monotonic()
        while time.monotonic() - start_time < move_time:
            dual_arm_controller.set_cmd_vel(
                [
                    {"name": 14, "spd": 0.0, "cur": 15.0},
                ]
            )
            time.sleep(0.01)
    # reach target joint,
        if arm_cur_joints is not None:
            dual_arm_controller.reach_target_joint(arm_cur_joints)

def example_tienyi2_waist():
    # 腰部
    waist_controller = robot.waist_ctrler
    if robot_config.get("controller", {}).get("sub_waist_status", False):
        waist_cur_pose = waist_controller.get_current_joint().get_radian_ndarray()
        print(f"当前腰部姿态: {waist_cur_pose}")
    # 腰部控制
    waist_ctrl_mode = "position"  
    if robot_config.get("controller", {}).get("enable_waist_controller", False):
        waist_cmd = [0.0, 0.0] # 31, 32
        if waist_ctrl_mode == "position":
            waist_controller.set_cmd_pos(waist_cmd)
        elif waist_ctrl_mode == "pose":
            waist_controller.set_yaw_cmd_pos(waist_cmd[0])

def example_tienyi2_leg():
    # 腿部
    leg_controller = robot.leg_ctrler
    # 获取当前腿部关节值
    if robot_config.get("controller", {}).get("sub_leg_status", False):
        leg_joints = leg_controller.get_pos()
        print(f"当前腿部姿态: {leg_joints}")

    leg_cmd = [0.0, 0.0]  # 51, 52
    # 腿部速度控制
    leg_controller.set_cmd_pos(target=leg_cmd)

class MoveItTools:

    def __init__(self):
        self.moveit_ctrler = robot.ros2controller.moveit_ctrler
        self.joint_vel_scale = 0.1
        self.joint_acc_scale = 0.1
        self.pose_vel_scale = 0.1
        self.pose_acc_scale = 0.1

    def moveit_reach_joints(self, left_joints = None, right_joints = None, wait_finish = True, group = 'dual_arm'):

        if left_joints is not None:
            left_joints = Joints(data=list(left_joints), num_of_dofs=7, angle_unit_type=BaseData.AngleUnitType.RADIAN)

        if right_joints is not None:
            right_joints = Joints(data=list(right_joints), num_of_dofs=7, angle_unit_type=BaseData.AngleUnitType.RADIAN)

        self.moveit_ctrler.reach_joints(
            motion_mode=group, left_target_joints=left_joints, right_target_joints=right_joints,
            vel_scale=self.joint_vel_scale, acc_scale=self.joint_acc_scale)

        if wait_finish:
            logger.info("Waiting for Joints Control Action to Finish...")
            self.moveit_ctrler.wait_joints_finish()
            logger.info("Joints Control Action Finished.")
    
    def moveit_reach_cartesian_pose(
            self,
            group: Literal["left_arm", "right_arm", "dual_arm"],
            waypoints_list=None,
            wait_finish = True):
        if 'left' in group:
            left_waypoints_list = list(waypoints_list)
            right_waypoints_list = None
        elif 'right' in group:
            right_waypoints_list = list(waypoints_list)
            left_waypoints_list = None
        else:
            raise ValueError("Group must be either 'left_arm', 'right_arm' or 'dual_arm'")

        self.moveit_ctrler.reach_cartesian_pose(
            group=group,
            use_cartesian_path=False,
            left_waypoints=PoseArray(
                pose_array_data=left_waypoints_list,
                coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
                length_unit_type=BaseData.LengthUnitType.METER,
                rotation_form_type=Rotation.FormType.XYZW,
            ),
            right_waypoints=PoseArray(
                pose_array_data=right_waypoints_list,
                coordinate_system_type=Coordinate.CoordinateSystem.WAIST_YAW_LINK,
                length_unit_type=BaseData.LengthUnitType.METER,
                rotation_form_type=Rotation.FormType.XYZW,
            ),
            vel_scale=self.pose_vel_scale,
            acc_scale=self.pose_acc_scale,
        )
        if wait_finish:
            logger.info("Waiting for Waypoints Action to Finish...")
            result = self.moveit_ctrler.wait_cartesian_pose_finish()
            print('result:', result)
            logger.info("Waypoints Action Finished.")
            return result
        else:
            return True
        
def example_tienyi2_ros2ctrl():
    if not robot_config.get("controller", {}).get("enable_ros2control", False):
            print("配置未开启ROS2控制")
            return
    ros2controller = robot.ros2controller

    input("press enter to test jointspace controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["jointspace_arm_L_controller", "jointspace_arm_R_controller"])
    for _ in range(3):
        ros2controller.exec_jointspace_arm_L_controller(target=[0.2, 0.2, 0.0, -0.2, 0.0, 0.0, 0.0])
        ros2controller.exec_jointspace_arm_R_controller(target=[0.2, -0.2, 0.0, -0.2, 0.0, 0.0, 0.0])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["jointspace_arm_L_controller", "jointspace_arm_R_controller"])

    input("press enter to test jointspace collisionfree controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["jointspace_arm_L_collisionfree_controller", "jointspace_arm_R_collisionfree_controller"])
    for _ in range(3):
        ros2controller.exec_jointspace_arm_L_collisionfree_controller(target=[0.2, 0.2, 0.0, -0.2, 0.0, 0.0, 0.3])
        ros2controller.exec_jointspace_arm_R_collisionfree_controller(target=[0.2, -0.2, 0.0, -0.2, 0.0, 0.0, 0.3])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["jointspace_arm_L_collisionfree_controller", "jointspace_arm_R_collisionfree_controller"])

    input("press enter to test jointspace ruckig qp controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["jointspace_ruckig_qp_controller"])
    ros2controller.exec_jointspace_ruckig_qp_controller(target=[0.0, 0.4, 0.0, 0., 0.0, 0., 0.0, 0.0, -0.4, 0.0, 0., 0.0, 0., 0.0])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["jointspace_ruckig_qp_controller"])

    input("press enter to test jointspace head controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["jointspace_head_controller"])
    ros2controller.exec_jointspace_head_controller(target=[0.1, -0.2, 0.1])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["jointspace_head_controller"])

    input("press enter to test endpose single arm left qp controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["endpose_single_arm_qp_L_controller"])
    left_ee_pose = [0.35281, 0.58985, 0.95388-0.09, 0.49998, -0.56081, -0.33894, 0.56624]  # xyz + xyzw
    ros2controller.exec_endpose_single_arm_qp_L_controller(
        from_frame="base", to_frame="left_tcp_link", target=left_ee_pose, offset=[0.0, 0.0, 0.0])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["endpose_single_arm_qp_L_controller"])

    input("press enter to test endpose single arm right qp controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["endpose_single_arm_qp_R_controller"])
    left_ee_pose = [0.35283, -0.58588, 0.9416-0.09, -0.39031, -0.49167, 0.43424, 0.64603]  # xyz + xyzw
    ros2controller.exec_endpose_single_arm_qp_R_controller(
        from_frame="base", to_frame="right_tcp_link", target=left_ee_pose, offset=[0.0, 0.0, 0.0])
    time.sleep(5)
    ros2controller._controller_switcher.switch_controllers(deactivate=["endpose_single_arm_qp_R_controller"])


    print(f"initialize MoveItTools")
    moveit_tool = MoveItTools()
    input("press enter to test moveit controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["moveit_left_arm_controller", "moveit_right_arm_controller"])
    moveit_tool.moveit_reach_joints([0.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0], [0.0, -0.4, 0.0, 0.0, 0.0, 0.0, 0.0])
    moveit_tool.moveit_reach_joints([0.0, 0.8, 0.0, 0.0, 0.0, 0.0, 0.0], [0.0, -0.8, 0.0, 0.0, 0.0, 0.0, 0.0])
    moveit_tool.moveit_reach_joints([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0], [0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
    ros2controller._controller_switcher.switch_controllers(deactivate=["moveit_left_arm_controller", "moveit_right_arm_controller"])

    input("press enter to test moveit cartesian controller...")
    ros2controller._controller_switcher.switch_controllers(activate=["moveit_left_arm_controller"])
    moveit_tool.moveit_reach_joints(left_joints=[0.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0], group="left_arm")
    moveit_tool.moveit_reach_joints(left_joints=[-0.52333, 0.52333, 0.52333, -0.52333, -0.52333, -0.52333, -0.52333], group="left_arm")
    ros2controller._controller_switcher.switch_controllers(deactivate=["moveit_left_arm_controller"])

    input("press enter to test moveit cartesian controller 2...")
    ros2controller._controller_switcher.switch_controllers(activate=["moveit_left_arm_controller", "moveit_right_arm_controller"])
    moveit_tool.moveit_reach_cartesian_pose(
        group="left_arm",
        waypoints_list=[
            [0.35111, 0.54808, 0.066436, 0.21958, -0.57554, -0.22764, 0.75413],])
    moveit_tool.moveit_reach_cartesian_pose(
        group="left_arm",
        waypoints_list=[
            [0.35111, 0.54808-0.1, 0.066436, 0.21958, -0.57554, -0.22764, 0.75413],])
    ros2controller._controller_switcher.switch_controllers(deactivate=["moveit_left_arm_controller", "moveit_right_arm_controller"])

    input("press enter to test moveit cartesian dual arm controller...")
    time.sleep(3)
    tcp_pose_l = moveit_tool.moveit_ctrler.get_left_tcp_pose()
    print(tcp_pose_l)





    input("press enter to test obstacle perception...")
    moveit_tool.moveit_ctrler.enable_obstacle_perception()
    input("1")
    moveit_tool.moveit_ctrler.disable_obstacle_perception()
    input("2")



    input("press enter to test moveit obstacle interface...")
    print("测试MoveIt!障碍物添加接口.")
    box_pose = Pose(coordinate=Coordinate(
        data=[1.0, 1.0, 1.0,],
        length_unit_type=BaseData.LengthUnitType.METER,
    ),
        rotation=Rotation(
        data=[0.0, 0.0, 0.0, 1.0],
        rotation_form_type=Rotation.FormType.XYZW,
    ))

    if moveit_tool.moveit_ctrler.add_obstacle(sharp_type='BOX', object_name='obstacle1', dimensions=[0.5, 0.5, 0.5], pose=box_pose):
        input("障碍物添加成功\n")

    if moveit_tool.moveit_ctrler.remove_obstacle('obstacle1'):
        input("障碍物删除成功\n")

    if moveit_tool.moveit_ctrler.add_obstacles([
        {"sharp_type": "BOX",
         "object_name": "obstacle1",
         "dimensions": [1, 1, 1],
         "pose": box_pose},
        {"sharp_type": "SPHERE",
         "object_name": "obstacle2",
         "dimensions": [1],
         "pose": box_pose}
    ]):
        input("障碍物添加成功\n")

    # if robot.moveit_ctrl.remove_obstacle('obstacle1'):
    #     print("obstacle1障碍物删除成功\n")
    # if robot.moveit_ctrl.remove_obstacle('obstacle2'):
    #     print("obstacle2障碍物删除成功\n")
    if moveit_tool.moveit_ctrler.remove_all_obstacles():
        input("所有障碍物删除成功\n")
   

if __name__ == "__main__":
    auto_read_config = False
    if auto_read_config:
        config_path = path_manager.config_toml_path
        cfg_loader = ConfigLoader(config_path)
        config = cfg_loader.get_config()
        robot_config = config["robot"]
    else:
        robot_config = {
            "enable": True,
            "controller": {
                "enable_head_controller": True,
                "sub_head_status": True,
                "enable_dual_arm_controller": True,
                "sub_arm_status": True,
                "enable_dual_arm_freq_change": False,
                "enable_waist_controller": True,
                "sub_waist_status": True,
                "enable_leg_controller": True,
                "sub_leg_status": True,
                "enable_moveit_controller": True,
                "enable_ros2control": True,
            }
        }

    node = ros2_node_manager.acquire()
    robot = TienYi2Ros2Robot(node=node, robot_config=robot_config)
    time.sleep(1)

    # if robot_config.get("controller", {}).get("enable_head_controller", False):
    #     input("press enter to test head...")
    #     example_tienyi2_head()
    # if robot_config.get("controller", {}).get("enable_dual_arm_controller", False):
    #     input("press enter to test arm...")
    #     example_tienyi2_arm()
    # if robot_config.get("controller", {}).get("enable_waist_controller", False):
    #     input("press enter to test waist...")
    #     example_tienyi2_waist()
    # if robot_config.get("controller", {}).get("enable_leg_controller", False):
    #     input("press enter to test leg...")
    #     example_tienyi2_leg()

    if robot_config.get("controller", {}).get("enable_ros2control", False):
        input("press enter to test ros2ctrl...")
        example_tienyi2_ros2ctrl()