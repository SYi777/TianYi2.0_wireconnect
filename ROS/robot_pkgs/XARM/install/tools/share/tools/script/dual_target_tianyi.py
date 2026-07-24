#!/usr/bin/env python3
import copy
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
server_l = None
server_r = None
menu_handler = MenuHandler()
br = None
counter = 0

# 左臂初始位姿（全部用float类型）
px_l, py_l, pz_l = 0.15, 0.2, 0.6
qx_l, qy_l, qz_l, qw_l = 0.0, 0.0, 0.0, 1.0

# 右臂初始位姿（全部用float类型）
px_r, py_r, pz_r = 0.15, -0.2, 0.6
qx_r, qy_r, qz_r, qw_r = 0.0, 0.0, 0.0, 1.0

is_dual_arm_syn = False


def frameCallback():
    global counter
    time = node.get_clock().now()

    # 发布左臂TF
    transform_l = TransformStamped()
    set_message_fields(transform_l, {
        'header': {'frame_id': 'base_footprint', 'stamp': time.to_msg()},
        'child_frame_id': 'left_target',
        'transform': {
            'translation': {'x': px_l, 'y': py_l, 'z': pz_l},
            'rotation': {'x': qx_l, 'y': qy_l, 'z': qz_l, 'w': qw_l}
        }
    })
    br.sendTransform(transform_l)

    # 发布右臂TF
    transform_r = TransformStamped()
    set_message_fields(transform_r, {
        'header': {'frame_id': 'base_footprint', 'stamp': time.to_msg()},
        'child_frame_id': 'right_target',
        'transform': {
            'translation': {'x': px_r, 'y': py_r, 'z': pz_r},
            'rotation': {'x': qx_r, 'y': qy_r, 'z': qz_r, 'w': qw_r}
        }
    })
    br.sendTransform(transform_r)

    # 发布双臂消息
    try:
        from eai_manipulator_msgs.msg import DualArmTargetPose
        dual_arm_msg = DualArmTargetPose()
        dual_arm_msg.header = transform_l.header

        # 左臂信息
        dual_arm_msg.target_l.position.x = px_l
        dual_arm_msg.target_l.position.y = py_l
        dual_arm_msg.target_l.position.z = pz_l
        dual_arm_msg.target_l.orientation.x = qx_l
        dual_arm_msg.target_l.orientation.y = qy_l
        dual_arm_msg.target_l.orientation.z = qz_l
        dual_arm_msg.target_l.orientation.w = qw_l
        dual_arm_msg.from_frame_l = 'base_footprint'
        dual_arm_msg.to_frame_l = 'left_tcp_link'
        dual_arm_msg.offset_x_l = dual_arm_msg.offset_y_l = dual_arm_msg.offset_z_l = 0.0

        # 右臂信息
        dual_arm_msg.target_r.position.x = px_r
        dual_arm_msg.target_r.position.y = py_r
        dual_arm_msg.target_r.position.z = pz_r
        dual_arm_msg.target_r.orientation.x = qx_r
        dual_arm_msg.target_r.orientation.y = qy_r
        dual_arm_msg.target_r.orientation.z = qz_r
        dual_arm_msg.target_r.orientation.w = qw_r
        dual_arm_msg.from_frame_r = 'base_footprint'
        dual_arm_msg.to_frame_r = 'right_tcp_link'
        dual_arm_msg.offset_x_r = dual_arm_msg.offset_y_r = dual_arm_msg.offset_z_r = 0.0

        dual_arm_msg.is_dual_arm_syn = is_dual_arm_syn
        dual_arm_pub.publish(dual_arm_msg)
    except Exception as e:
        node.get_logger().warn(f"Failed to publish dual arm msg: {str(e)}")

    counter += 1


def processFeedbackLeft(feedback):
    global px_l, py_l, pz_l, qx_l, qy_l, qz_l, qw_l
    if feedback.event_type == InteractiveMarkerFeedback.POSE_UPDATE:
        px_l = feedback.pose.position.x
        py_l = feedback.pose.position.y
        pz_l = feedback.pose.position.z
        qx_l = feedback.pose.orientation.x
        qy_l = feedback.pose.orientation.y
        qz_l = feedback.pose.orientation.z
        qw_l = feedback.pose.orientation.w

        node.get_logger().info(
            f"Left arm dragged: Pos({px_l:.3f}, {py_l:.3f}, {pz_l:.3f}) "
            f"Quat({qw_l:.3f}, {qx_l:.3f}, {qy_l:.3f}, {qz_l:.3f})"
        )

        server_l.setPose(feedback.marker_name, feedback.pose)
        server_l.applyChanges()


def processFeedbackRight(feedback):
    global px_r, py_r, pz_r, qx_r, qy_r, qz_r, qw_r
    if feedback.event_type == InteractiveMarkerFeedback.POSE_UPDATE:
        px_r = feedback.pose.position.x
        py_r = feedback.pose.position.y
        pz_r = feedback.pose.position.z
        qx_r = feedback.pose.orientation.x
        qy_r = feedback.pose.orientation.y
        qz_r = feedback.pose.orientation.z
        qw_r = feedback.pose.orientation.w

        node.get_logger().info(
            f"Right arm dragged: Pos({px_r:.3f}, {py_r:.3f}, {pz_r:.3f}) "
            f"Quat({qw_r:.3f}, {qx_r:.3f}, {qy_r:.3f}, {qz_r:.3f})"
        )

        server_r.setPose(feedback.marker_name, feedback.pose)
        server_r.applyChanges()


def normalizeQuaternion(quat):
    """标准化四元数，避免旋转后四元数不合法"""
    norm = quat.x**2 + quat.y**2 + quat.z**2 + quat.w**2
    if norm < 1e-6:
        quat.w = 1.0
        return
    s = 1.0 / norm**0.5
    quat.x *= s
    quat.y *= s
    quat.z *= s
    quat.w *= s


def make6DofMarker(server, marker_name, init_position):
    """创建可拖动+单轴旋转的6自由度标记"""
    int_marker = InteractiveMarker()
    int_marker.header.frame_id = 'base_footprint'
    int_marker.header.stamp = node.get_clock().now().to_msg()
    int_marker.pose.position = init_position
    int_marker.scale = 0.2  # 标记整体缩放，控制坐标轴和立方体大小
    int_marker.name = marker_name
    int_marker.description = f"Drag cube (3D move/rotate) or axes (rotate only)"

    # -------------------------- 1. 基础立方体（支持3D拖动+旋转） --------------------------
    box_control = InteractiveMarkerControl()
    box_control.interaction_mode = InteractiveMarkerControl.MOVE_ROTATE_3D  # 立方体支持3D拖动+旋转
    box_control.always_visible = True

    box_marker = Marker()
    box_marker.type = Marker.CUBE
    box_marker.scale.x = int_marker.scale * 0.6
    box_marker.scale.y = int_marker.scale * 0.6
    box_marker.scale.z = int_marker.scale * 0.6
    # 颜色区分左右臂
    if "left" in marker_name:
        box_marker.color.r, box_marker.color.g, box_marker.color.b = 0.0, 0.0, 1.0
    else:
        box_marker.color.r, box_marker.color.g, box_marker.color.b = 1.0, 0.0, 0.0
    box_marker.color.a = 0.8
    box_control.markers.append(box_marker)
    int_marker.controls.append(box_control)

    # -------------------------- 2. 新增单轴旋转控制（X/Y/Z轴，支持拖动旋转） --------------------------
    # 定义每个轴的旋转配置：(x, y, z, 轴名称, 颜色R, G, B)
    rotate_axes = [
        (1.0, 0.0, 0.0, "rotate_x", 1.0, 0.0, 0.0),  # X轴（红）
        (0.0, 1.0, 0.0, "rotate_y", 0.0, 1.0, 0.0),  # Y轴（绿）
        (0.0, 0.0, 1.0, "rotate_z", 0.0, 0.0, 1.0)   # Z轴（蓝）
    ]

    for ax_x, ax_y, ax_z, ctrl_name, r, g, b in rotate_axes:
        rotate_ctrl = InteractiveMarkerControl()

        # 正确构造控制的 orientation：
        # 把 axis 放到 x,y,z，把 w 设为 1.0，再做标准化 —— 这是常用的简便做法。
        rotate_ctrl.orientation.x = ax_x
        rotate_ctrl.orientation.y = ax_y
        rotate_ctrl.orientation.z = ax_z
        rotate_ctrl.orientation.w = 1.0
        normalizeQuaternion(rotate_ctrl.orientation)

        # 单轴旋转
        rotate_ctrl.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        # 控件相对于标记姿态（你也可以改成 FIXED）
        rotate_ctrl.orientation_mode = InteractiveMarkerControl.INHERIT

        # 可视化箭头（不变）
        axis_marker = Marker()
        axis_marker.type = Marker.ARROW
        axis_marker.scale.x = 0.18
        axis_marker.scale.y = 0.04
        axis_marker.scale.z = 0.04
        axis_marker.points = [
            Point(x=0.0, y=0.0, z=0.0),
            Point(x=ax_x * 0.18, y=ax_y * 0.18, z=ax_z * 0.18)
        ]
        axis_marker.color.r = r
        axis_marker.color.g = g
        axis_marker.color.b = b
        axis_marker.color.a = 0.50
        rotate_ctrl.markers.append(axis_marker)

        rotate_ctrl.name = ctrl_name
        int_marker.controls.append(rotate_ctrl)

    # -------------------------- 3. 绑定反馈并初始化 --------------------------
    feedback_cb = processFeedbackLeft if "left" in marker_name else processFeedbackRight
    server.insert(int_marker, feedback_callback=feedback_cb)
    menu_handler.apply(server, marker_name)
    server.applyChanges()
    node.get_logger().info(f"Created 6DOF marker (move+rotate): {marker_name}")


if __name__ == '__main__':
    rclpy.init(args=sys.argv)
    node = rclpy.create_node('dual_arm_draggable_node')
    br = TransformBroadcaster(node)

    # 1. 创建定时器
    timer = node.create_timer(0.01, frameCallback)

    # 2. 初始化发布者
    try:
        from eai_manipulator_msgs.msg import DualArmTargetPose
        dual_arm_pub = node.create_publisher(DualArmTargetPose, '/endposetarget_Dual', 10)
    except ImportError:
        node.get_logger().error("Failed to import DualArmTargetPose! Check msg package path.")
        rclpy.shutdown()
        sys.exit(1)

    # 3. 初始化交互服务器
    server_l = InteractiveMarkerServer(node, 'left_arm_interactive_server')
    server_r = InteractiveMarkerServer(node, 'right_arm_interactive_server')

    # 4. 创建初始位置（确保是float类型）
    left_init_pos = Point(x=px_l, y=py_l, z=pz_l)
    right_init_pos = Point(x=px_r, y=py_r, z=pz_r)
    make6DofMarker(server_l, 'left_arm_marker', left_init_pos)
    make6DofMarker(server_r, 'right_arm_marker', right_init_pos)

    # 5. 启动节点
    node.get_logger().info("Dual arm node ready! RViz操作：拖动立方体（3D移动/旋转）或坐标轴（单轴旋转）")
    rclpy.spin(node)

    # 6. 清理资源
    server_l.shutdown()
    server_r.shutdown()
    rclpy.shutdown()
