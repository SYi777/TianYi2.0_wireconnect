#!/usr/bin/env python3


import copy
from math import sin, atan2
from random import random
import sys

from geometry_msgs.msg import Point
from geometry_msgs.msg import TransformStamped
from interactive_markers import InteractiveMarkerServer
from interactive_markers import MenuHandler
import rclpy
from rosidl_runtime_py import set_message_fields
from tf2_ros.transform_broadcaster import TransformBroadcaster
from visualization_msgs.msg import InteractiveMarker
from visualization_msgs.msg import InteractiveMarkerControl
from visualization_msgs.msg import InteractiveMarkerFeedback
from visualization_msgs.msg import Marker
from std_msgs.msg import Float64MultiArray

node = None
pose_pub = None
server = None
menu_handler = MenuHandler()
br = None
counter = 0
print_counter = 0

px = None
py = None
pz = None
qx = None
qy = None
qz = None
qw = None


def frameCallback():
    global node, counter, br, pose_pub, print_counter
    time = node.get_clock().now()
    transform = TransformStamped()
    global px, py, pz, qx, qy, qz, qw
    if px is not None and py is not None and pz is not None and qx is not None and qy is not None and qz is not None and qw is not None:
        set_message_fields(
            transform,
            {
                'header': {'frame_id': 'base', 'stamp': time.to_msg()},
                'transform': {
                    'translation': {
                        'x': px,
                        'y': py - 0.5,
                        'z': pz,
                    },
                    'rotation': {
                        'x': qx,
                        'y': qy,
                        'z': qz,
                        'w': qw,
                    },
                },
                'child_frame_id': 'left_target',
            },
        )
        br.sendTransform(transform)
        # 发布当前目标位姿
    if pose_pub is not None and px is not None and py is not None and pz is not None and qx is not None and qy is not None and qz is not None and qw is not None:
        # 从四元数计算 pitch 角度 (绕Y轴旋转)
        pitch = atan2(2 * (qw * qy + qx * qz), 1 - 2 * (qy * qy + qz * qz))

        pose_msg = Float64MultiArray()
        pose_msg.data = [float(px), float(pz), float(pitch), 0.0]
        pose_pub.publish(pose_msg)

        # 每秒打印一次发送的内容
        print_counter += 1
        if print_counter >= 100:
            print(f"[Publisher] x={px:.4f}, z={pz:.4f}, pitch={pitch:.4f}, 0.0")
            print_counter = 0

    counter += 1


def processFeedback(feedback):
    log_prefix = (
        f"Feedback from marker '{feedback.marker_name}' / control '{feedback.control_name}'"
    )

    log_mouse = ''
    if feedback.mouse_point_valid:
        log_mouse = (
            f'{feedback.mouse_point.x}, {feedback.mouse_point.y}, '
            f'{feedback.mouse_point.z} in frame {feedback.header.frame_id}'
        )

    if feedback.event_type == InteractiveMarkerFeedback.BUTTON_CLICK:
        node.get_logger().info(f'{log_prefix}: button click at {log_mouse}')
    elif feedback.event_type == InteractiveMarkerFeedback.MENU_SELECT:
        node.get_logger().info(
            f'{log_prefix}: menu item {feedback.menu_entry_id} clicked at {log_mouse}'
        )
    elif feedback.event_type == InteractiveMarkerFeedback.POSE_UPDATE:
        node.get_logger().info(
            f'{log_prefix}: pose changed\n'
            f'position: '
            f'{feedback.pose.position.x}, {feedback.pose.position.y}, {feedback.pose.position.z}\n'
            f'orientation: '
            f'{feedback.pose.orientation.w}, {feedback.pose.orientation.x}, '
            f'{feedback.pose.orientation.y}, {feedback.pose.orientation.z}\n'
            f'frame: {feedback.header.frame_id} '
            f'time: {feedback.header.stamp.sec} sec, '
            f'{feedback.header.stamp.nanosec} nsec'
        )
        global px, py, pz, qx, qy, qz, qw
        px = feedback.pose.position.x
        py = feedback.pose.position.y
        pz = feedback.pose.position.z
        qx = feedback.pose.orientation.x
        qy = feedback.pose.orientation.y
        qz = feedback.pose.orientation.z
        qw = feedback.pose.orientation.w
    elif feedback.event_type == InteractiveMarkerFeedback.MOUSE_DOWN:
        node.get_logger().info(f'{log_prefix}: mouse down at {log_mouse}')
    elif feedback.event_type == InteractiveMarkerFeedback.MOUSE_UP:
        node.get_logger().info(f'{log_prefix}: mouse up at {log_mouse}')


def alignMarker(feedback):
    pose = feedback.pose

    pose.position.x = round(pose.position.x - 0.5) + 0.5
    pose.position.y = round(pose.position.y - 0.5) + 0.5

    node.get_logger().info(
        f'{feedback.marker_name}: aligning position = {feedback.pose.position.x}, '
        f'{feedback.pose.position.y}, {feedback.pose.position.z} to '
        f'{pose.position.x}, {pose.position.y}, {pose.position.z}'
    )

    server.setPose(feedback.marker_name, pose)
    server.applyChanges()


def rand(min_, max_):
    return min_ + random() * (max_ - min_)


def makeBox(msg):
    marker = Marker()

    marker.type = Marker.CUBE
    marker.scale.x = msg.scale * 0.5
    marker.scale.y = msg.scale * 0.5
    marker.scale.z = msg.scale * 0.5
    marker.color.r = 0.5
    marker.color.g = 0.5
    marker.color.b = 0.5
    marker.color.a = 0.5

    return marker


def makeBoxControl(msg):
    control = InteractiveMarkerControl()
    control.always_visible = True
    control.markers.append(makeBox(msg))
    msg.controls.append(control)
    return control


def saveMarker(int_marker):
    server.insert(int_marker, feedback_callback=processFeedback)


def normalizeQuaternion(quaternion_msg):
    norm = quaternion_msg.x ** 2 + quaternion_msg.y ** 2 + quaternion_msg.z ** 2 + quaternion_msg.w ** 2
    s = norm ** (-0.5)
    quaternion_msg.x *= s
    quaternion_msg.y *= s
    quaternion_msg.z *= s
    quaternion_msg.w *= s


def make6DofMarker(fixed, interaction_mode, position, show_6dof=False):
    int_marker = InteractiveMarker()
    int_marker.header.frame_id = 'base'
    int_marker.pose.position = position
    int_marker.scale = 0.1

    int_marker.name = 'waist_target_xz'
    int_marker.description = 'waist_target_xz'

    # insert a box
    makeBoxControl(int_marker)
    # 不设置 box 的 interaction_mode，避免允许自由移动

    if fixed:
        int_marker.name += '_fixed'
        int_marker.description += '\n(fixed orientation)'

    if interaction_mode != InteractiveMarkerControl.NONE:
        control_modes_dict = {
            InteractiveMarkerControl.MOVE_3D: 'MOVE_3D',
            InteractiveMarkerControl.ROTATE_3D: 'ROTATE_3D',
            InteractiveMarkerControl.MOVE_ROTATE_3D: 'MOVE_ROTATE_3D'
        }

    if show_6dof:
        # X轴移动控制
        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 1.0
        control.orientation.y = 0.0
        control.orientation.z = 0.0
        normalizeQuaternion(control.orientation)
        control.name = 'move_x'
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

        # Z轴移动控制 (使用 y=1 表示垂直方向)
        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 0.0
        control.orientation.y = 1.0
        control.orientation.z = 0.0
        normalizeQuaternion(control.orientation)
        control.name = 'move_z'
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

        # Y轴旋转控制 - 按照原始代码: w=1, z=1
        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 0.0
        control.orientation.y = 0.0
        control.orientation.z = 1.0
        normalizeQuaternion(control.orientation)
        control.name = 'rotate_y'
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

    server.insert(int_marker, feedback_callback=processFeedback)
    menu_handler.apply(server, int_marker.name)


if __name__ == '__main__':
    rclpy.init(args=sys.argv)
    node = rclpy.create_node('waist_target_xz_node')
    br = TransformBroadcaster(node)

    # create a timer to update the published transforms
    timer = node.create_timer(0.01, frameCallback)

    pose_pub = node.create_publisher(Float64MultiArray, '/endposetarget_Body', 10)

    server = InteractiveMarkerServer(node, 'waist_target_xz')

    # global px, py, pz, qx, qy, qz, qw
    px = 0.05
    py = 0.5
    pz = 0.68
    qx, qy, qz, qw = (0, 0, 0, 1)

    position = Point(x=px, y=py, z=pz)

    make6DofMarker(False, InteractiveMarkerControl.NONE, position, True)

    server.applyChanges()

    rclpy.spin(node)
    server.shutdown()
