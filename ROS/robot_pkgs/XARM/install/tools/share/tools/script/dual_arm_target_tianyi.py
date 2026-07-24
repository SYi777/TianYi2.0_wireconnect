#!/usr/bin/env python3


import copy
from math import sin
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

node = None
dual_arm_pub = None
server = None
menu_handler = MenuHandler()
br = None
counter = 0

# Left target pose
left_px = None
left_py = None
left_pz = None
left_qx = None
left_qy = None
left_qz = None
left_qw = None

# Right target pose
right_px = None
right_py = None
right_pz = None
right_qx = None
right_qy = None
right_qz = None
right_qw = None


def frameCallback():
    global node, counter, br, dual_arm_pub
    time = node.get_clock().now()

    # Broadcast left target transform
    global left_px, left_py, left_pz, left_qx, left_qy, left_qz, left_qw
    if left_px is not None and left_py is not None and left_pz is not None and left_qx is not None and left_qy is not None and left_qz is not None and left_qw is not None:
        transform = TransformStamped()
        set_message_fields(
            transform,
            {
                'header': {'frame_id': 'base_footprint', 'stamp': time.to_msg()},
                'transform': {
                    'translation': {
                        'x': left_px,
                        'y': left_py,
                        'z': left_pz,
                    },
                    'rotation': {
                        'x': left_qx,
                        'y': left_qy,
                        'z': left_qz,
                        'w': left_qw,
                    },
                },
                'child_frame_id': 'left_target',
            },
        )
        br.sendTransform(transform)

    # Broadcast right target transform
    global right_px, right_py, right_pz, right_qx, right_qy, right_qz, right_qw
    if right_px is not None and right_py is not None and right_pz is not None and right_qx is not None and right_qy is not None and right_qz is not None and right_qw is not None:
        transform = TransformStamped()
        set_message_fields(
            transform,
            {
                'header': {'frame_id': 'base_footprint', 'stamp': time.to_msg()},
                'transform': {
                    'translation': {
                        'x': right_px,
                        'y': right_py,
                        'z': right_pz,
                    },
                    'rotation': {
                        'x': right_qx,
                        'y': right_qy,
                        'z': right_qz,
                        'w': right_qw,
                    },
                },
                'child_frame_id': 'right_target',
            },
        )
        br.sendTransform(transform)

    # Publish dual arm target pose
    if dual_arm_pub is not None and left_px is not None and right_px is not None:
        from eai_manipulator_msgs.msg import DualArmTargetPose
        dual_arm_msg = DualArmTargetPose()
        dual_arm_msg.header.stamp = time.to_msg()
        dual_arm_msg.header.frame_id = 'base'

        # Left arm info
        dual_arm_msg.target_l.position.x = float(left_px)
        dual_arm_msg.target_l.position.y = float(left_py)
        dual_arm_msg.target_l.position.z = float(left_pz)
        dual_arm_msg.target_l.orientation.x = float(left_qx)
        dual_arm_msg.target_l.orientation.y = float(left_qy)
        dual_arm_msg.target_l.orientation.z = float(left_qz)
        dual_arm_msg.target_l.orientation.w = float(left_qw)
        dual_arm_msg.from_frame_l = 'base_footprint'
        dual_arm_msg.to_frame_l = 'left_tcp_link'
        dual_arm_msg.offset_x_l = 0.0
        dual_arm_msg.offset_y_l = 0.0
        dual_arm_msg.offset_z_l = 0.0

        # Right arm info
        dual_arm_msg.target_r.position.x = float(right_px)
        dual_arm_msg.target_r.position.y = float(right_py)
        dual_arm_msg.target_r.position.z = float(right_pz)
        dual_arm_msg.target_r.orientation.x = float(right_qx)
        dual_arm_msg.target_r.orientation.y = float(right_qy)
        dual_arm_msg.target_r.orientation.z = float(right_qz)
        dual_arm_msg.target_r.orientation.w = float(right_qw)
        dual_arm_msg.from_frame_r = 'base_footprint'
        dual_arm_msg.to_frame_r = 'right_tcp_link'
        dual_arm_msg.offset_x_r = 0.0
        dual_arm_msg.offset_y_r = 0.0
        dual_arm_msg.offset_z_r = 0.0

        dual_arm_pub.publish(dual_arm_msg)

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
        if feedback.marker_name == 'left_target':
            global left_px, left_py, left_pz, left_qx, left_qy, left_qz, left_qw
            left_px = feedback.pose.position.x
            left_py = feedback.pose.position.y
            left_pz = feedback.pose.position.z
            left_qx = feedback.pose.orientation.x
            left_qy = feedback.pose.orientation.y
            left_qz = feedback.pose.orientation.z
            left_qw = feedback.pose.orientation.w
        elif feedback.marker_name == 'right_target':
            global right_px, right_py, right_pz, right_qx, right_qy, right_qz, right_qw
            right_px = feedback.pose.position.x
            right_py = feedback.pose.position.y
            right_pz = feedback.pose.position.z
            right_qx = feedback.pose.orientation.x
            right_qy = feedback.pose.orientation.y
            right_qz = feedback.pose.orientation.z
            right_qw = feedback.pose.orientation.w
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


def makeBox(msg, color_r=0.5, color_g=0.5, color_b=0.5):
    marker = Marker()

    marker.type = Marker.CUBE
    marker.scale.x = msg.scale * 0.5
    marker.scale.y = msg.scale * 0.5
    marker.scale.z = msg.scale * 0.5
    marker.color.r = color_r
    marker.color.g = color_g
    marker.color.b = color_b
    marker.color.a = 0.5

    return marker


def makeBoxControl(msg, color_r=0.5, color_g=0.5, color_b=0.5):
    control = InteractiveMarkerControl()
    control.always_visible = True
    control.markers.append(makeBox(msg, color_r, color_g, color_b))
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


def make6DofMarker(fixed, interaction_mode, position, name, description, show_6dof=False, color_r=0.5, color_g=0.5, color_b=0.5):
    int_marker = InteractiveMarker()
    int_marker.header.frame_id = 'base_footprint'
    int_marker.pose.position = position
    int_marker.scale = 0.1

    int_marker.name = name
    int_marker.description = description

    # insert a box with custom color
    makeBoxControl(int_marker, color_r, color_g, color_b)
    int_marker.controls[0].interaction_mode = interaction_mode

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
        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 1.0
        control.orientation.y = 0.0
        control.orientation.z = 0.0
        normalizeQuaternion(control.orientation)
        control.name = 'rotate_x'
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

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

        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 0.0
        control.orientation.y = 1.0
        control.orientation.z = 0.0
        normalizeQuaternion(control.orientation)
        control.name = 'rotate_z'
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

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

        control = InteractiveMarkerControl()
        control.orientation.w = 1.0
        control.orientation.x = 0.0
        control.orientation.y = 0.0
        control.orientation.z = 1.0
        normalizeQuaternion(control.orientation)
        control.name = 'move_y'
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        if fixed:
            control.orientation_mode = InteractiveMarkerControl.FIXED
        int_marker.controls.append(control)

    server.insert(int_marker, feedback_callback=processFeedback)
    menu_handler.apply(server, int_marker.name)


if __name__ == '__main__':
    rclpy.init(args=sys.argv)
    node = rclpy.create_node('dual_arm_target_node')
    br = TransformBroadcaster(node)

    # create a timer to update the published transforms
    timer = node.create_timer(0.01, frameCallback)
    from geometry_msgs.msg import Pose
    from eai_manipulator_msgs.msg import DualArmTargetPose

    dual_arm_pub = node.create_publisher(DualArmTargetPose, '/endposetarget_Dual', 10)

    server = InteractiveMarkerServer(node, 'dual_arm_target')

    # Left target initial pose
    left_px = 0.15
    left_py = 0.2
    left_pz = 0.6
    left_qx, left_qy, left_qz, left_qw = (0, 0, 0, 1)

    # Right target initial pose
    right_px = 0.15
    right_py = -0.2
    right_pz = 0.6
    right_qx, right_qy, right_qz, right_qw = (0, 0, 0, 1)

    # Create left target marker (blue)
    left_position = Point(x=left_px, y=left_py, z=left_pz)
    make6DofMarker(False, InteractiveMarkerControl.MOVE_ROTATE_3D, left_position,
                   'left_target', 'left_target', True, color_r=0.0, color_g=0.0, color_b=1.0)

    # Create right target marker (red)
    right_position = Point(x=right_px, y=right_py, z=right_pz)
    make6DofMarker(False, InteractiveMarkerControl.MOVE_ROTATE_3D, right_position,
                   'right_target', 'right_target', True, color_r=1.0, color_g=0.0, color_b=0.0)

    server.applyChanges()

    rclpy.spin(node)
    server.shutdown()
