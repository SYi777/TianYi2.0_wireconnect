#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='freq_change',
            executable='freq_change_node',
            name='freq_change_node',
            output='screen',
            parameters=[
                {'joint_state_topic': 4},
                {'loop_rate': 200},
                {'ctrl_mode': 4},
                {'filter_parameter': 0.5},
                {'pos_closed_loop_parameter': 10.0}
            ]
        )
    ])
    
