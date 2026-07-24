import os

from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import ComposableNodeContainer
from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode
from launch import LaunchDescription


def generate_launch_description():
    # 获取包路径
    body_control_dir = get_package_share_directory("body_control")

    # ros2 params
    body_params = {
        "u2c_sn": "/home/ubuntu/data/param/u2c_sn.yaml",
        "motor_arms_right": os.path.join(body_control_dir, "param/motor_arms7_right.yaml"),
        "motor_arms_left": os.path.join(body_control_dir, "param/motor_arms7_left.yaml"),
        "motor_waist": os.path.join(body_control_dir, "param/motor_waist.yaml"),
        "motor_head": os.path.join(body_control_dir, "param/motor_head.yaml"),
        "motor_legs": os.path.join(body_control_dir, "param/motor_legs.yaml"),
        "sri_6dof": os.path.join(body_control_dir, "param/sri_6dof.yaml"),
        "inspire_hands": os.path.join(body_control_dir, "param/inspire_hands.yaml"),
        "inspire_gripper": os.path.join(body_control_dir, "param", "inspire_gripper.yaml"),
    }

    # # # # # #  所有 components 信息 # # # # # #

    ## 本体 -- 组件形式
    body_component = ComposableNode(
        package="body_control",
        plugin="body_control::BodyControl",
        name="bodyctrl_component",
        parameters=[body_params],
    )

    ## 电源板 -- 组件形式
    powerboard_component = ComposableNode(
        package="power_board",
        plugin="com::xhumanoid::PowerBoardNodelet",
        name="power_board_node",
        extra_arguments=[{"use_intra_process_comms": True}],
        parameters=[
            {"com_port": "/dev/ttyS1"},
            {"enable_power_light": "1"},
            {"enable_power_status": "1"},
            {"enable_power_battery_status": "1"},
            {"enable_power_board_key_status": "1"},
            {"enable_power_set_timestamp": "1"},
        ],
    )

    # 诊断 -- 组件形式
    diagnose_component = ComposableNode(
        package="diagnose",
        plugin="debugger::DebuggerNodelet",
        name="diagnose_tiangong2_upgrade_node",
        extra_arguments=[{"use_intra_process_comms": True}],
        parameters=[{"xml_config_file": "param/tianyi2.0_pro.xml"}],
    )

    # 组件容器
    components_container = ComposableNodeContainer(
        name="body_container",
        namespace="",
        package="rclcpp_components",
        executable="component_container",
        output="screen",
        composable_node_descriptions=[
            body_component,
            powerboard_component,
            diagnose_component,
        ],
    )

    # # # # # # 所有 nodes 信息 # # # # # #

    ## 底盘  slamware_ros_sdk_server_node
    # 不要删除，后边有可能再启用
    # 底盘控制直接调用了相关库，官方的sdk没有加进来
    # slamware_node = Node(
    #     package='slamware_ros_sdk',
    #     executable='slamware_ros_sdk_server_node',
    #     name='slamware_ros_sdk_server_node',
    #     output='screen',
    #     parameters=[{
    #         'ip_address': '192.168.11.1',
    #         'angle_compensate': True,
    #         'fixed_odom_map_tf': True,
    #         'raw_ladar_data': False,
    #         'robot_frame': 'base_link',
    #         'odom_frame': 'odom',
    #         'laser_frame': 'laser',
    #         'map_frame': 'slamware_map',
    #         'robot_pose_frame': 'robot_pose',
    #         'odometry_pub_period': 0.05,
    #         'robot_pose_pub_period': 0.05,
    #         'scan_pub_period': 0.1,
    #         'map_pub_period': 0.2,
    #         'path_pub_period': 0.1,
    #         'imu_raw_data_period': 0.1,
    #         'virtual_walls_pub_period': 1.0,
    #         'virtual_tracks_pub_period': 1.0,
    #         'basic_sensors_values_pub_period': 1.0,
    #         'vel_control_topic': 'cmd_vel',
    #         'ladar_data_clockwise': True,
    #         'pub_accumulate_odometry': False,
    #         'robot_pose_topic': 'robot_pose',
    #     }],
    #     remappings=[
    #         ('scan', 'scan'),
    #         ('odom', 'odom'),
    #         ('map', 'slamware_map'),
    #         ('map_metadata', 'map_metadata'),
    #         ('global_plan_path', 'global_plan_path'),
    #     ],
    #     arguments=['--ros-args', '--log-level', 'fatal']  # 屏蔽 error 以下日志
    # )

    # 遥控器
    remote_ctl_node = Node(
        package="usb_sbus",
        executable="usb_sbus_node",
        name="usb_sbus",
        # namespace = 'usb_sbus',
        output="screen",
    )

    # 底盘控制
    body_control_dir = get_package_share_directory("chassis")
    chassis_params = {
        "chassis_config": os.path.join(body_control_dir, "param/chassis_param.yaml"),
    }
    chassis_control_node = Node(
        package="chassis",
        executable="chassis_control",
        name="chassis_control",
        output="screen",
        parameters=[chassis_params],
    )

    # 测试程序(用于在部署机器时，测试软件连通性)

    # 预制动作

    # 返回 launch 描述
    return LaunchDescription(
        [
            # 组件容器
            components_container,
            # 所有 node
            remote_ctl_node,
            chassis_control_node,
        ]
    )
