#!/usr/bin/env python3
"""同构臂 ZMQ → 天轶左手遥操 + 右手自动初始化

状态机:
  waiting    → 等同构臂数据
  approaching → 步进逼近 (每步0.003rad), 到达即停
  following  → 直发同构臂关节角
  locked     → 臂锁定, btn[1]回到锁定区间可重新跟随

Usage:
    python3 zmq_teleop.py
    python3 zmq_teleop.py --no-right-init
"""

import json, math, os, sys, time, threading, signal

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq, rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, Header
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition

# 电机ID映射
MOTOR_LEFT  = [11, 12, 13, 14, 15, 16, 17]
MOTOR_RIGHT = [21, 22, 23, 24, 25, 26, 27]
SPD_LEFT  = 8.0   # 左臂快速跟随
SPD_RIGHT = 1.0   # 右臂极慢
CUR_LEFT  = [20.0, 15.0, 6.0, 6.0, 6.0, 4.0, 4.0]
CUR_RIGHT = [8.0, 6.0, 4.0, 4.0, 4.0, 3.0, 3.0]

ZMQ_IP, ZMQ_PORT = "192.168.41.100", 5003

REFERENCE  = [0.026, 0.014, -0.202, -0.245, -0.038, 0.164, -0.144]
THRESHOLDS = [math.radians(25)] * 2 + [math.radians(30)] * 3 + [math.radians(30)] * 2
REENTRY_THRESH = [math.radians(25)] * 7
APPROACH_STEP = 0.002   # rad per step — 越小越慢

# 天轶左臂关节限位 (rad) — 防止自碰
JOINT_LIMITS = [
    (-2.96, 2.96),    # shoulder_pitch
    (-0.262, 2.616),  # shoulder_roll
    (-2.96, 2.96),    # shoulder_yaw
    (-2.61, 0.261),   # elbow_pitch
    (-2.96, 2.96),    # elbow_yaw
    (-0.785, 1.05),   # wrist_pitch
    (-1.65, 1.3),     # wrist_roll
]


class TeleopNode(Node):
    def __init__(self):
        super().__init__("zmq_teleop")
        self._pub_l = self.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)
    def send(self, angles, motors=MOTOR_LEFT, spd=SPD_LEFT, cur=CUR_LEFT):
        msg = CmdSetMotorPosition()
        msg.header = Header(stamp=self.get_clock().now().to_msg())
        spd_l = spd if isinstance(spd, list) else [spd]*7
        cur_l = cur if isinstance(cur, list) else [cur]*7
        msg.cmds = [SetMotorPosition(name=m, pos=a, spd=s, cur=c)
                    for m, a, s, c in zip(motors, angles, spd_l, cur_l)]
        self._pub_l.publish(msg)

def clamp_joints(a):
    """Clamp joints to TianYi safe limits."""
    return [max(lo, min(hi, a[i])) for i, (lo, hi) in enumerate(JOINT_LIMITS)]

def check_safety(a):
    return all(abs(a[i]-REFERENCE[i]) < THRESHOLDS[i] for i in range(7))

def in_reentry(a, locked):
    return all(abs(a[i]-locked[i]) < REENTRY_THRESH[i] for i in range(7))


def goto_right_init(node):
    p = os.path.expanduser("~/WireConnect_ws/src/trajectory_bridge/config/init_poses.json")
    if not os.path.exists(p): p = os.path.expanduser("~/init_poses.json")
    if not os.path.exists(p): print("⚠ init_poses.json not found"); return
    with open(p) as f: poses = json.load(f)
    print(f"🤖 右手初始化: {len(poses)} 个位姿")
    from geometry_msgs.msg import Pose, Point, Quaternion
    from moveit_msgs.srv import GetPositionIK
    from moveit_msgs.msg import PositionIKRequest, RobotState
    import tf2_ros
    tf_buf = tf2_ros.Buffer(); tf2_ros.TransformListener(tf_buf, node)
    ik = node.create_client(GetPositionIK, "/compute_ik")
    pr = node.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)
    JJ = ["shoulder_pitch_r_joint","shoulder_roll_r_joint","shoulder_yaw_r_joint",
          "elbow_pitch_r_joint","elbow_yaw_r_joint","wrist_pitch_r_joint","wrist_roll_r_joint"]

    # find nearest waypoint to start
    try:
        t = tf_buf.lookup_transform("waist_yaw_link", "right_tcp_link", rclpy.time.Time(),
                                     timeout=rclpy.duration.Duration(seconds=1.0))
        cx, cy, cz = t.transform.translation.x, t.transform.translation.y, t.transform.translation.z
        dists = [math.sqrt((p["x"]-cx)**2 + (p["y"]-cy)**2 + (p["z"]-cz)**2) for p in poses]
        nearest_idx = dists.index(min(dists))
        print(f"  最近位姿: [{nearest_idx}] 距离={min(dists):.3f}m")
        poses = poses[nearest_idx:]  # 从最近走到最后
    except Exception:
        print("  TF lookup failed, using original order")

    from moveit_msgs.msg import MotionPlanRequest, Constraints, JointConstraint, RobotState as MRS
    from moveit_msgs.srv import GetMotionPlan
    plan_client = node.create_client(GetMotionPlan, "/plan_kinematic_path")
    pr = node.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)

    for i, po in enumerate(poses):
        g = Pose(position=Point(x=po["x"],y=po["y"],z=po["z"]),
                  orientation=Quaternion(x=po["qx"],y=po["qy"],z=po["qz"],w=po["qw"]))
        rq = GetPositionIK.Request()
        rq.ik_request = PositionIKRequest(group_name="right_arm", robot_state=MRS(is_diff=True))
        rq.ik_request.pose_stamped.header.frame_id = "waist_yaw_link"
        rq.ik_request.pose_stamped.pose = g; rq.ik_request.timeout.sec = 3
        print(f"  [{i+1}/{len(poses)}] → [{po['x']:.3f},{po['y']:.3f},{po['z']:.3f}]")
        if not ik.wait_for_service(timeout_sec=2): print("    IK unavailable"); break
        f = ik.call_async(rq); rclpy.spin_until_future_complete(node, f, timeout_sec=5)
        r = f.result()
        if r is None or r.error_code.val != 1: print("    IK FAIL"); continue
        jm = dict(zip(r.solution.joint_state.name, r.solution.joint_state.position))
        target = [jm.get(j,0.0) for j in JJ]

        # Only use OMPL for first waypoint (below→above table), then direct
        if i == 0:
            jcs = [JointConstraint(joint_name=j, position=v, tolerance_above=0.05, tolerance_below=0.05, weight=1.0)
                   for j, v in zip(JJ, target)]
            prq = MotionPlanRequest()
            prq.group_name = "right_arm"; prq.pipeline_id = "ompl"; prq.planner_id = ""
            prq.num_planning_attempts = 5; prq.allowed_planning_time = 3.0
            prq.max_velocity_scaling_factor = 0.3; prq.max_acceleration_scaling_factor = 0.3
            prq.start_state = MRS(is_diff=True)
            prq.goal_constraints = [Constraints(joint_constraints=jcs)]
            print(f"    OMPL...")
            if plan_client.wait_for_service(timeout_sec=2):
                pf = plan_client.call_async(GetMotionPlan.Request(motion_plan_request=prq))
                rclpy.spin_until_future_complete(node, pf, timeout_sec=10)
                pr_plan = pf.result()
                if pr_plan and pr_plan.motion_plan_response.error_code.val == 1:
                    traj = pr_plan.motion_plan_response.trajectory
                    print(f"    OMPL OK {len(traj.joint_trajectory.points)} pts → executing")
                    t_prev = 0.0
                    for pt in traj.joint_trajectory.points:
                        vals = [pt.positions[JJ.index(j)] if j in JJ else 0.0 for j in JJ]
                        msg = CmdSetMotorPosition()
                        msg.header = Header()
                        msg.cmds = [SetMotorPosition(name=m, pos=a, spd=SPD_RIGHT, cur=CUR_RIGHT[i2])
                                    for i2, (m, a) in enumerate(zip(MOTOR_RIGHT, vals))]
                        pr.publish(msg)
                        t_cur = pt.time_from_start.sec + pt.time_from_start.nanosec * 1e-9
                        time.sleep(max(t_cur - t_prev, 0.05)); t_prev = t_cur
                    continue  # skip direct send below
            print(f"    OMPL failed, falling back to direct")
        # Direct send (for i>0 or OMPL fallback)
        for _ in range(30):
            msg = CmdSetMotorPosition()
            msg.header = Header()
            msg.cmds = [SetMotorPosition(name=m, pos=a, spd=SPD_RIGHT, cur=CUR_RIGHT[i2])
                        for i2, (m, a) in enumerate(zip(MOTOR_RIGHT, target))]
            pr.publish(msg); time.sleep(0.1)
    print("✅ 右手初始化完成")
    print("✅ 右手初始化完成")


def main():
    rclpy.init(); node = TeleopNode()
    # proper spin in background
    def _spin():
        while rclpy.ok(): rclpy.spin_once(node, timeout_sec=0.01); time.sleep(0.001)
    spin_t = threading.Thread(target=_spin, daemon=True); spin_t.start()
    time.sleep(0.5)  # discovery

    if "--no-right-init" not in sys.argv:
        print("⚠ 右手已独立为 zmq_teleop_right.py, 请单独运行")
        # goto_right_init removed — use zmq_teleop_right.py instead

    ctx = zmq.Context(); sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1); sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{ZMQ_IP}:{ZMQ_PORT}"); sock.setsockopt(zmq.RCVTIMEO, 200)

    state = "waiting"; start_angles = None; locked_pos = None
    btn_prev = False; hand_angles = list(REFERENCE); last_sent = None

    print("🎮 同构臂遥操"); print("   btn[1]=锁定/重入跟随")

    try:
        while rclpy.ok():
            pressed = False
            try:
                while True:
                    d = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
                    a = d.get("arm",{}).get("position",{}).get("left")
                    b = d.get("button",{}).get("left",[])
                    if len(b) > 1: pressed = bool(b[1])
                    if a and len(a) == 7: hand_angles = [float(x) for x in a]
            except zmq.Again: pass

            # button toggle
            if pressed and not btn_prev:
                if state in ("waiting","approaching","following"):
                    if locked_pos is None: locked_pos = list(hand_angles)
                    state = "locked"; print(f"🔒 锁定 (锁定位={[f'{x:.2f}' for x in locked_pos]})")
                elif state == "locked":
                    if in_reentry(hand_angles, locked_pos):
                        state = "approaching"; print("✅ 重入遥操")
                    else:
                        print("⚠ 不在锁定区间, 无法启动遥操")
            btn_prev = pressed

            if state == "locked": time.sleep(0.02); continue

            if state == "waiting":
                # first entry: check vs reference. re-entry: check vs locked_pos
                if locked_pos is not None and len(locked_pos) == 7:
                    if not in_reentry(hand_angles, locked_pos):
                        print("⚠ 同构臂不在锁定区间, 等待..."); time.sleep(0.1); continue
                    start_angles = list(locked_pos)
                else:
                    if not check_safety(hand_angles):
                        print("⚠ 同构臂远离悬垂位, 遥操未启动"); time.sleep(0.1); continue
                    start_angles = list(REFERENCE)
                print(f"→ 步进逼近 (step={APPROACH_STEP:.4f})..."); state = "approaching"

            if state == "approaching":
                done = True
                for i in range(7):
                    d = hand_angles[i] - start_angles[i]
                    if abs(d) < 0.001: continue
                    done = False
                    start_angles[i] += max(-APPROACH_STEP, min(APPROACH_STEP, d))
                if done:
                    print("✅ 逼近完成 → 跟随"); state = "following"
                else:
                    node.send(clamp_joints(start_angles)); time.sleep(0.02); continue

            if state == "following":
                clamped = clamp_joints(hand_angles)
                if last_sent != clamped:
                    node.send(clamped); last_sent = list(clamped)
                locked_pos = list(clamped)
                continue

            time.sleep(0.01)

    finally: sock.close(); ctx.destroy(); node.destroy_node(); rclpy.try_shutdown(); print("✅ 已退出")

if __name__ == "__main__": main()
