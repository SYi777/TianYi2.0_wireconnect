#!/usr/bin/env python3
"""录制/回放 TCP 位姿 (笛卡尔), 不依赖初始关节位置。

Save:  Enter → 保存当前 left_tcp_link Pose 到 JSON
Goto:  读取 JSON → /compute_ik → /plan_kinematic_path → 执行

Save Usage:
    ros2 run trajectory_bridge save_waypoint my_poses.json
Goto Usage:
    ros2 run trajectory_bridge goto_waypoint my_poses.json
"""
import json
import os
import sys
import select
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Pose, Point, Quaternion
from moveit_msgs.srv import GetPositionIK, GetMotionPlan
from moveit_msgs.msg import (PositionIKRequest, MotionPlanRequest,
    Constraints, JointConstraint, RobotState)
from std_msgs.msg import Header, Float64MultiArray
import tf2_ros

ARM_JOINTS = {
    "left": ["shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint",
              "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint"],
    "right": ["shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint",
              "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint"],
}


def save_waypoints_main():
    if len(sys.argv) < 2:
        print("Usage: ros2 run trajectory_bridge save_waypoint <file.json>")
        sys.exit(1)
    save_waypoints(sys.argv[1])


def goto_waypoints_main():
    if len(sys.argv) < 2:
        print("Usage: ros2 run trajectory_bridge goto_waypoint <file.json>")
        sys.exit(1)
    goto_waypoints(sys.argv[1])


def save_waypoints(filename: str):
    """Press Enter to save current TCP pose. q to quit."""
    rclpy.init()
    node = Node("save_waypoint", allow_undeclared_parameters=True)
    node.declare_parameter("arm", "left")
    node.declare_parameter("frame", "waist_yaw_link")
    arm = node.get_parameter("arm").value
    frame = node.get_parameter("frame").value

    tf_buf = tf2_ros.Buffer()
    tf2_ros.TransformListener(tf_buf, node)

    # load existing
    poses = []
    if os.path.exists(filename):
        with open(filename) as f:
            poses = json.load(f)
        print(f"loaded {len(poses)} existing waypoints from {filename}")
    print(f"Press Enter to SAVE {arm}_tcp_link pose → {filename}")
    print("q = quit")

    import tty, termios
    fd = sys.stdin.fileno(); old = termios.tcgetattr(fd); tty.setcbreak(fd)
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.05)
            if select.select([sys.stdin], [], [], 0)[0]:
                key = sys.stdin.read(1)
                if key == 'q':
                    break
                if key in ('\r', '\n', ' '):
                    try:
                        t = tf_buf.lookup_transform(frame, f"{arm}_tcp_link", rclpy.time.Time(),
                                                     timeout=rclpy.duration.Duration(seconds=0.5))
                        pose = {"x": t.transform.translation.x,
                                "y": t.transform.translation.y,
                                "z": t.transform.translation.z,
                                "qx": t.transform.rotation.x,
                                "qy": t.transform.rotation.y,
                                "qz": t.transform.rotation.z,
                                "qw": t.transform.rotation.w}
                        poses.append(pose)
                        print(f"  [{len(poses)}] saved: [{pose['x']:.3f}, {pose['y']:.3f}, "
                              f"{pose['z']:.3f}]")
                    except Exception as e:
                        print(f"  TF error: {e}")
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old)
        with open(filename, "w") as f:
            json.dump(poses, f, indent=2)
        print(f"\nSaved {len(poses)} poses → {filename}")
    node.destroy_node(); rclpy.try_shutdown()


def goto_waypoints(filename: str):
    """Read poses from JSON, IK+Plan+Execute each."""
    with open(filename) as f:
        poses = json.load(f)

    rclpy.init()
    node = Node("goto_waypoint", allow_undeclared_parameters=True)
    node.declare_parameter("arm", "left")
    node.declare_parameter("frame", "waist_yaw_link")
    arm = node.get_parameter("arm").value
    frame = node.get_parameter("frame").value
    joints = ARM_JOINTS[arm]
    topic = f"/jointspace_commands_{'L' if arm == 'left' else 'R'}"

    ik_client = node.create_client(GetPositionIK, "/compute_ik")
    plan_client = node.create_client(GetMotionPlan, "/plan_kinematic_path")
    joint_pub = node.create_publisher(Float64MultiArray, topic, 10)

    for i, p in enumerate(poses):
        goal = Pose(position=Point(x=p["x"], y=p["y"], z=p["z"]),
                    orientation=Quaternion(x=p["qx"], y=p["qy"], z=p["qz"], w=p["qw"]))

        # IK
        req = GetPositionIK.Request()
        req.ik_request = PositionIKRequest()
        req.ik_request.group_name = f"{arm}_arm"
        req.ik_request.robot_state = RobotState(is_diff=True)
        req.ik_request.pose_stamped.header = Header(frame_id=frame)
        req.ik_request.pose_stamped.pose = goal
        req.ik_request.timeout.sec = 3

        print(f"[{i}] IK → [{p['x']:.3f},{p['y']:.3f},{p['z']:.3f}]")
        if not ik_client.wait_for_service(timeout_sec=2.0):
            print("  IK service unavailable"); break
        future = ik_client.call_async(req)
        rclpy.spin_until_future_complete(node, future, timeout_sec=5.0)
        result = future.result()
        if result is None or result.error_code.val != 1:
            print(f"  IK FAIL"); continue
        jmap = {n: v for n, v in zip(result.solution.joint_state.name, result.solution.joint_state.position)}
        vals = [jmap.get(j, 0.0) for j in joints]
        print(f"  IK OK: {[f'{v:.3f}' for v in vals]}")

        # 直发关节
        msg = Float64MultiArray(data=vals)
        joint_pub.publish(msg)
        print(f"  [{i}/{len(poses)}] sent → press Enter for next, q=quit")
        key = input().strip().lower()
        if key == 'q':
            print("  aborted")
            break

    node.destroy_node(); rclpy.try_shutdown()
    print("all done")
