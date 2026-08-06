#!/usr/bin/env python3
"""比赛遥操 — 初始化录制 / 比赛运行

Usage:
    python3 competition.py --mode init     # 录制左右臂轨迹
    python3 competition.py --mode compete  # 比赛运行

依赖: bodyctrl + XARM(仅关节) + joint_relay + bridge + RSP + move_group + TF补全

控件映射:
    button.left[0]  → 夹爪开合
    button.left[1]  → 自锁/解锁
    button.left[2]  → 右臂轨迹正放/倒放
    joystick.left   → 恒力插入模式: TCP精细XY
    button.right[0/1] → 手动控制TCP上/下
    button.right[2] → 启动/退出恒力Z环
"""

import json, math, os, sys, time, threading, signal, select, tty, termios
from collections import deque

os.environ["RCUTILS_LOGGING_USE_STDOUT"] = "0"

import zmq, rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
from geometry_msgs.msg import WrenchStamped
from sensor_msgs.msg import JointState

# ═══════════════════════════════════════════════════════════
ZMQ_IP, ZMQ_PORT = "192.168.41.100", 5003
CONFIG_DIR = os.path.expanduser("~/WireConnect_ws/config")
WORKSPACE_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FORCE_AXIS_FILE = os.path.join(
    WORKSPACE_ROOT, "src", "tools", "force_axis_cal.json")

MOTOR_LEFT  = [11,12,13,14,15,16,17]
MOTOR_RIGHT = [21,22,23,24,25,26,27]
ARM_J_L = ["shoulder_pitch_l_joint","shoulder_roll_l_joint","shoulder_yaw_l_joint",
           "elbow_pitch_l_joint","elbow_yaw_l_joint","wrist_pitch_l_joint","wrist_roll_l_joint"]
ARM_J_R = ["shoulder_pitch_r_joint","shoulder_roll_r_joint","shoulder_yaw_r_joint",
           "elbow_pitch_r_joint","elbow_yaw_r_joint","wrist_pitch_r_joint","wrist_roll_r_joint"]
SPD_L = 8.0; CUR_L = [20.0,15.0,6.0,6.0,6.0,4.0,4.0]
SPD_R = 2.0; CUR_R = [8.0,6.0,4.0,4.0,4.0,3.0,3.0]
SPD_INSERT_L = 3.0

REF_L  = [0.026, 0.014, -0.202, -0.245, -0.038, 0.164, -0.144]
REF_R  = [0.04, -0.032, 0.077, -0.258, 0.08, 0.247, -0.084]
SAFE_TH = [math.radians(25)]*2 + [math.radians(30)]*3 + [math.radians(30)]*2
APPROACH_STEP = 0.002

JOINT_LIMITS_L = [
    (-2.96,2.96), (-0.262,2.616), (-2.96,2.96), (-2.61,0.261),
    (-2.96,2.96), (-0.785,1.05), (-1.65,1.3),
]
JOINT_LIMITS_R = [
    (-2.96,2.96), (-2.616,0.262), (-2.96,2.96), (-2.61,0.261),
    (-2.96,2.96), (-0.785,1.05), (-1.3,1.65),
]

HAND_NAMES = ["1","2","3","4","5","6"]
PRESET_OPEN  = [1.00, 1.00, 1.00, 0.85, 0.75, 0.16]
PRESET_CLOSE = [1.00, 1.00, 1.00, 0.55, 0.55, 0.16]

FORCE_XY_STEP = 0.0003  # 恒力插入时摇杆每周期XY步长(m)
MANUAL_Z_STEP = 0.0003  # 手动Z每周期步长(m)
CART_MAX_STEP = 0.002  # 连续笛卡尔路径内部插值步长(m)
CART_JUMP_THRESHOLD = 1.5
CART_MIN_FRACTION = 0.99
JOY_DEADBAND = 0.08  # 摇杆死区
CART_MAX_JOINT_STEP = math.radians(10.0)
RETURN_TRANSITION_SEC = 3.0
RIGHT_RETURN_TRANSITION_SEC = 1.0
HANGING_TOL = math.radians(5.0)
INSERT_LOOP_DT = 0.05
HOLD_PERIOD = 0.2

FORCE_FILTER_SAMPLES = 5
FORCE_TARGET = 1.2
FORCE_CONTACT = 0.8
FORCE_CONTACT_FRAMES = 5
FORCE_HARD_STOP = 4.0
FORCE_LATERAL_STOP = 3.0
MANUAL_AXIAL_WARN = 4.0
MANUAL_AXIAL_HARD_STOP = 8.0
FORCE_MAX_SPEED = 0.002       # m/s
FORCE_GAIN = 0.0001           # m/(N·周期)
FORCE_DEADBAND = 0.1
FORCE_MAX_DESCENT = 0.03      # 仅软限位，达到后保持
FORCE_BACKOFF = 0.002         # 超力后回退2mm
FORCE_STALE_SEC = 0.1


def _joints_diff(a, b):
    if a is None or b is None: return 999
    return max(abs(a[i]-b[i]) for i in range(7))


def clamp(a, limits=JOINT_LIMITS_L):
    return [max(limits[i][0], min(limits[i][1], a[i])) for i in range(7)]

def check_safety(a, ref=REF_L):
    return all(abs(a[i]-ref[i]) < SAFE_TH[i] for i in range(7))


def _load_force_axis():
    with open(FORCE_AXIS_FILE) as file:
        data = json.load(file)
    axis = [float(value) for value in data["u"]]
    norm = math.sqrt(sum(value*value for value in axis))
    if norm < 1e-9:
        raise ValueError("force_axis_cal.json 中的 u 无效")
    return [value / norm for value in axis]


def _force_components(force, baseline, axis):
    delta = [force[i] - baseline[i] for i in range(3)]
    axial = sum(delta[i] * axis[i] for i in range(3))
    total = math.sqrt(sum(value*value for value in delta))
    lateral = math.sqrt(max(0.0, total*total - axial*axial))
    return axial, total, lateral


class BodyCtrlNode(Node):
    def __init__(self):
        super().__init__("competition")
        self._pub = self.create_publisher(CmdSetMotorPosition, "/arm/cmd_pos", 10)
        self._pub_hand = self.create_publisher(JointState, "/inspire_hand/ctrl/right_hand", 10)
        self._left_joints = None
        self._left_joints_at = 0.0
        self._right_joints = None
        self._right_joints_at = 0.0
        self._last_left_command = None
        self._last_right_command = None
        self._force_samples = deque(maxlen=200)
        self._force_at = 0.0
        self.create_subscription(JointState, "/joint_states", self._joint_state_cb, 10)
        self.create_subscription(
            WrenchStamped, "/arm_6dof_left", self._force_cb, 100)
        # 连续笛卡尔路径服务（插入微调）
        from moveit_msgs.srv import GetCartesianPath
        self._cartesian = self.create_client(GetCartesianPath, "/compute_cartesian_path")
        # TF for TCP
        import tf2_ros
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

    def _joint_state_cb(self, msg):
        values = dict(zip(msg.name, msg.position))
        if all(name in values for name in ARM_J_L):
            self._left_joints = [float(values[name]) for name in ARM_J_L]
            self._left_joints_at = time.monotonic()
        if all(name in values for name in ARM_J_R):
            self._right_joints = [float(values[name]) for name in ARM_J_R]
            self._right_joints_at = time.monotonic()

    def _force_cb(self, msg):
        force = msg.wrench.force
        self._force_samples.append((
            float(force.x), float(force.y), float(force.z)))
        self._force_at = time.monotonic()

    def force_fresh(self):
        return (
            bool(self._force_samples) and
            time.monotonic() - self._force_at <= FORCE_STALE_SEC)

    def filtered_force(self, count=FORCE_FILTER_SAMPLES):
        if not self._force_samples:
            return None
        samples = list(self._force_samples)[-count:]
        return [
            sum(sample[i] for sample in samples) / len(samples)
            for i in range(3)
        ]

    def sample_force_baseline(self, duration=0.5):
        self._force_samples.clear()
        deadline = time.monotonic() + duration
        while rclpy.ok() and time.monotonic() < deadline:
            time.sleep(0.01)
        samples = list(self._force_samples)
        if len(samples) < 20:
            return None, None
        mean = [
            sum(sample[i] for sample in samples) / len(samples)
            for i in range(3)
        ]
        std = [
            math.sqrt(
                sum((sample[i] - mean[i])**2 for sample in samples)
                / len(samples))
            for i in range(3)
        ]
        return mean, std

    def get_left_joints(self, max_age=1.0):
        if self._left_joints is None:
            return None
        if time.monotonic() - self._left_joints_at > max_age:
            return None
        return list(self._left_joints)

    def get_right_joints(self, max_age=1.0):
        if self._right_joints is None:
            return None
        if time.monotonic() - self._right_joints_at > max_age:
            return None
        return list(self._right_joints)

    def send_left(self, angles, spd=SPD_L):
        self._last_left_command = list(angles)
        _send(self._pub, MOTOR_LEFT, angles, spd, CUR_L)

    def send_right(self, angles):
        self._last_right_command = list(angles)
        _send(self._pub, MOTOR_RIGHT, angles, SPD_R, CUR_R)

    def send_hand(self, open_state):
        p = PRESET_OPEN if open_state else PRESET_CLOSE
        msg = JointState(); msg.name = HAND_NAMES; msg.position = list(p)
        self._pub_hand.publish(msg)

    def cartesian_path(self, pos, ori, seed):
        """从seed连续规划到目标TCP，返回按ARM_J_L排序的关节路径与完成比例。"""
        from geometry_msgs.msg import Point, Pose, Quaternion
        from moveit_msgs.msg import RobotState
        from moveit_msgs.srv import GetCartesianPath
        if not self._cartesian.wait_for_service(timeout_sec=0.5):
            return None, 0.0

        req = GetCartesianPath.Request()
        req.header.frame_id = "waist_yaw_link"
        req.header.stamp = self.get_clock().now().to_msg()
        req.start_state = RobotState(is_diff=True)
        req.start_state.joint_state.name = list(ARM_J_L)
        req.start_state.joint_state.position = [float(v) for v in seed]
        req.group_name = "left_arm"
        req.link_name = "left_tcp_link"
        req.waypoints = [Pose(
            position=Point(x=pos[0], y=pos[1], z=pos[2]),
            orientation=Quaternion(x=ori[0], y=ori[1], z=ori[2], w=ori[3]))]
        req.max_step = CART_MAX_STEP
        req.jump_threshold = CART_JUMP_THRESHOLD
        req.avoid_collisions = True

        future = self._cartesian.call_async(req)
        deadline = time.monotonic() + 1.0
        while rclpy.ok() and not future.done() and time.monotonic() < deadline:
            time.sleep(0.002)
        if not future.done():
            return None, 0.0
        result = future.result()
        if result is None or result.error_code.val != 1:
            return None, float(result.fraction) if result else 0.0

        trajectory = result.solution.joint_trajectory
        names = list(trajectory.joint_names)
        if not trajectory.points or not all(name in names for name in ARM_J_L):
            return None, float(result.fraction)
        indexes = [names.index(name) for name in ARM_J_L]
        path = [
            [float(point.positions[index]) for index in indexes]
            for point in trajectory.points
        ]
        return path, float(result.fraction)

    def get_tcp(self):
        """Current TCP [x,y,z,qx,qy,qz,qw] in waist_yaw_link or None."""
        try:
            t = self._tf_buf.lookup_transform("waist_yaw_link", "left_tcp_link", rclpy.time.Time(),
                                               timeout=rclpy.duration.Duration(seconds=0.3))
            r = t.transform.rotation
            return [t.transform.translation.x, t.transform.translation.y, t.transform.translation.z,
                    r.x, r.y, r.z, r.w]
        except: return None


def _send(pub, motors, angles, spd, cur):
    msg = CmdSetMotorPosition()
    msg.header.stamp.sec = 0; msg.header.stamp.nanosec = 0
    s = spd if isinstance(spd, list) else [spd]*7
    c = cur if isinstance(cur, list) else [cur]*7
    msg.cmds = [SetMotorPosition(name=m, pos=a, spd=s[i], cur=c[i]) for i,(m,a) in enumerate(zip(motors, angles))]
    pub.publish(msg)


def _smoothstep(t):
    return t*t*(3.0 - 2.0*t)


def _move_left_smooth(node, start, goal, duration, spd=SPD_INSERT_L):
    """按 smoothstep 在关节空间平滑过渡，避免直接跳到目标关节角。"""
    start = clamp(start)
    goal = clamp(goal)
    steps = max(2, int(duration / 0.02))
    t0 = time.monotonic()
    for step in range(1, steps + 1):
        if not rclpy.ok():
            return False
        alpha = _smoothstep(step / steps)
        cmd = [start[i] + (goal[i] - start[i]) * alpha for i in range(7)]
        node.send_left(cmd, spd=spd)
        next_t = t0 + step * duration / steps
        time.sleep(max(0.0, next_t - time.monotonic()))
    return True


def _move_right_smooth(node, start, goal, duration):
    """右臂关节空间平滑过渡。"""
    start = clamp(start, JOINT_LIMITS_R)
    goal = clamp(goal, JOINT_LIMITS_R)
    steps = max(2, int(duration / 0.02))
    t0 = time.monotonic()
    for step in range(1, steps + 1):
        if not rclpy.ok():
            return False
        alpha = _smoothstep(step / steps)
        cmd = [start[i] + (goal[i] - start[i]) * alpha for i in range(7)]
        node.send_right(cmd)
        next_t = t0 + step * duration / steps
        time.sleep(max(0.0, next_t - time.monotonic()))
    return True


def _normalize_quat(q):
    norm = math.sqrt(sum(v*v for v in q))
    if norm < 1e-9:
        return None
    return [v / norm for v in q]


def _nearest_equivalent(joints, seed):
    """将周期关节角映射到关节限位内、且最靠近seed的等价表示。"""
    result = []
    for i, value in enumerate(joints):
        lo, hi = JOINT_LIMITS_L[i]
        options = [
            value + turns * 2.0 * math.pi
            for turns in (-1, 0, 1)
            if lo <= value + turns * 2.0 * math.pi <= hi
        ]
        if not options:
            return None
        result.append(min(options, key=lambda v: abs(v - seed[i])))
    return result


def _validate_joint_path(path, seed, max_step):
    """规范化并逐点检查MoveIt轨迹，禁止中途切换IK分支。"""
    result = []
    previous = list(seed)
    largest_jump = 0.0
    for joints in path:
        joints = _nearest_equivalent(joints, previous)
        if joints is None:
            return None, None
        jump = _joints_diff(joints, previous)
        largest_jump = max(largest_jump, jump)
        if jump > max_step:
            return None, largest_jump
        result.append(clamp(joints))
        previous = joints
    return result, largest_jump


# ═══════════════════ 初始化模式 ═══════════════════

def mode_init(node, sock):
    os.makedirs(CONFIG_DIR, exist_ok=True)

    # 右手
    print("🤖 右手: [空格]开始录制, [空格]结束")
    rt = record_arm(
        node, sock, "right", MOTOR_RIGHT, REF_R, SPD_R, CUR_R, JOINT_LIMITS_R)
    f = os.path.join(CONFIG_DIR, "right_traj.json")
    with open(f, "w") as fh: json.dump(rt, fh, indent=2)
    print(f"💾 右手 {len(rt)}帧")
    print("⏳ 自锁5s...")
    for _ in range(100): node.send_right(rt[-1]); time.sleep(0.05)
    print("◀ 倒放...")
    for a in reversed(rt): node.send_right(a); time.sleep(0.012)

    # 左手
    print("🤖 左手: [空格]录制, [空格]结束")
    lt = record_arm(
        node, sock, "left", MOTOR_LEFT, REF_L, SPD_L, CUR_L, JOINT_LIMITS_L)
    f = os.path.join(CONFIG_DIR, "left_traj.json")
    with open(f, "w") as fh: json.dump(lt, fh, indent=2)
    print(f"💾 左手 {len(lt)}帧")
    print("⏳ 自锁5s...")
    for _ in range(100): node.send_left(lt[-1]); time.sleep(0.05)
    print("◀ 倒放...")
    for a in reversed(lt): node.send_left(a); time.sleep(0.012)
    print("✅ 初始化完成")


def record_arm(node, sock, side, motors, ref, spd, cur, limits):
    traj = []; recording = False; last_sent = None
    hand_angles = list(ref); start_angles = list(ref); state = "waiting"
    fd = sys.stdin.fileno(); old = termios.tcgetattr(fd); tty.setcbreak(fd)
    while True:
        try:
            while True:
                d = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
                a = d.get("arm",{}).get("position",{}).get(side)
                if a and len(a)==7: hand_angles = [float(x) for x in a]
        except zmq.Again: pass
        if select.select([sys.stdin], [], [], 0)[0]:
            key = sys.stdin.read(1)
            if key == ' ':
                if recording: termios.tcsetattr(fd, termios.TCSADRAIN, old); return traj
                else: recording = True; traj = []; print(f"\n🔴 录{side}...")
        if state == "waiting":
            if not check_safety(hand_angles, ref): time.sleep(0.1); continue
            state = "approaching"
        if state == "approaching":
            done = True
            for i in range(7):
                d = hand_angles[i]-start_angles[i]
                if abs(d)<0.001: continue
                done = False; start_angles[i] += max(-APPROACH_STEP, min(APPROACH_STEP, d))
            if done: state = "following"
            else: _send(node._pub, motors, clamp(start_angles, limits), spd, cur); time.sleep(0.02); continue
        if state == "following":
            cl = clamp(hand_angles, limits)
            if last_sent != cl:
                _send(node._pub, motors, cl, spd, cur)
                if recording: traj.append(list(cl))
                last_sent = list(cl)
            continue
        time.sleep(0.01)


# ═══════════════════ 比赛模式 ═══════════════════

def mode_compete(node, sock):
    fr = os.path.join(CONFIG_DIR, "right_traj.json")
    fl = os.path.join(CONFIG_DIR, "left_traj.json")
    with open(fr) as f: rt = json.load(f)
    with open(fl) as f: lt = json.load(f)
    node._force_axis = _load_force_axis()
    print(
        "💪 加载力控轴向 u="
        f"[{node._force_axis[0]:+.3f},"
        f"{node._force_axis[1]:+.3f},"
        f"{node._force_axis[2]:+.3f}]")

    # 右臂由左手第三键手动正放/倒放，避免程序启动后立即运动。
    node._competition_right_traj = rt
    node._competition_left_traj = lt
    node._right_at_target = False
    node._right_traj_index = 0
    print("🎥 右臂等待：左手第三键正放，再按一次倒放")

    while rclpy.ok():
        # ── 左臂遥操 ──
        print("🤖 左臂: 等5s安全检查...")
        time.sleep(5)
        _teleop_loop(node, sock, rt, lt)
        # 循环继续


def _teleop_loop(node, sock, right_traj, left_traj):
    """左臂遥操→自锁→插入→返回→下一轮"""
    hand_angles = list(REF_L)
    start_angles = node.get_left_joints(max_age=2.0) or list(REF_L)
    last_sent = list(start_angles); state = "waiting"
    locked = False; locked_pos = None
    hand_open = False
    btn_prev = [False]*5
    btn_right_prev = [False]*3
    insert_target = None
    insert_base_ori = None
    last_insert_sent = None
    last_hold_at = 0.0
    ik_warn_at = 0.0
    force_baseline = None
    force_state = "IDLE"
    force_contact_count = 0
    force_start_z = None
    force_backoff_goal_z = None
    force_status_at = 0.0
    force_warn_at = 0.0
    force_fault_was_manual = False
    force_enabled = False
    b, r, joy = [], [], [0.0, 0.0]

    while rclpy.ok():
        # ZMQ drain
        try:
            while True:
                d = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
                a = d.get("arm",{}).get("position",{}).get("left")
                b = d.get("button",{}).get("left",[])
                r = d.get("button",{}).get("right",[])
                joy = d.get("joystick",{}).get("left",[0.0,0.0])
                if a and len(a)==7: hand_angles = [float(x) for x in a]
        except zmq.Again: pass

        btn0 = bool(b[0]) if len(b)>0 else False
        btn1 = bool(b[1]) if len(b)>1 else False
        btn2 = bool(b[2]) if len(b)>2 else False
        btnR0 = bool(r[0]) if len(r)>0 else False
        btnR1 = bool(r[1]) if len(r)>1 else False
        btnR2 = bool(r[2]) if len(r)>2 else False
        btnR2_edge = btnR2 and not btn_right_prev[2]
        btn_right_prev[0] = btnR0
        btn_right_prev[1] = btnR1
        btn_right_prev[2] = btnR2
        right_replay_finished = False

        # 右臂轨迹只允许在左臂遥操阶段正放/倒放。
        if btn2 and not btn_prev[2]:
            if locked:
                print("⚠ 插入模式中忽略右臂回放")
            else:
                left_hold = (
                    node.get_left_joints(max_age=2.0) or
                    node._last_left_command or
                    list(last_sent or start_angles))
                reverse = getattr(node, '_right_at_target', False)
                print("◀ 左手第三键触发右臂倒放..." if reverse
                      else "▶ 左手第三键触发右臂正放...")
                indexes = (range(len(right_traj)-1, -1, -1)
                           if reverse else range(len(right_traj)))
                for frame, index in enumerate(indexes):
                    node.send_right(right_traj[index])
                    node._right_traj_index = index
                    if frame % 4 == 0:
                        node.send_left(left_hold, spd=SPD_INSERT_L)
                    time.sleep(0.012)
                node._right_at_target = not reverse
                start_angles = (
                    node.get_left_joints(max_age=2.0) or list(left_hold))
                last_sent = list(start_angles)
                state = "approaching"
                right_replay_finished = True
                print("  右臂已回悬垂" if reverse else "  右臂到位, 自锁")
                print("  左臂开始步进同步同构臂...")
        btn_prev[2] = btn2

        if right_replay_finished:
            # 下一轮先读取最新ZMQ关节角，再由approaching平滑恢复跟随。
            btn_prev[0] = btn0
            btn_prev[1] = btn1
            time.sleep(0.02)
            continue

        # 夹爪
        if btn0 and not btn_prev[0]:
            hand_open = not hand_open; node.send_hand(hand_open)
        btn_prev[0] = btn0

        # ── 自锁切换 ──
        if btn1 and not btn_prev[1]:
            if locked:
                # 解锁 → 插入完成, 返回悬垂
                print("✅ 插入完成 → 返回悬垂")
                _return_to_hanging(node, left_traj, last_insert_sent or locked_pos)
                btn_prev[1] = btn1
                return  # 退出内层循环, 外层 while 重新开始
            else:
                # 自锁当前TCP位姿，不再强制切换到固定插入朝向。
                locked_pos = node.get_left_joints(max_age=2.0) or list(last_sent or hand_angles)
                tcp = node.get_tcp()
                current_ori = _normalize_quat(tcp[3:7]) if tcp else None
                if tcp is None or current_ori is None:
                    print("⚠ 当前TCP获取失败，未进入插入模式")
                    node.send_left(locked_pos, spd=SPD_INSERT_L)
                else:
                    print(
                        "⏳ 采集当前姿态力基线 F₀："
                        "请确保插头尚未接触插座并保持静止...")
                    force_baseline, force_std = node.sample_force_baseline(0.5)
                    if force_baseline is None or max(force_std) > 0.5:
                        print(
                            "⚠ 力基线采集失败或不稳定，未进入插入模式 "
                            f"σ={force_std}")
                        node.send_left(locked_pos, spd=SPD_INSERT_L)
                    else:
                        insert_target = list(tcp[:3])
                        insert_base_ori = current_ori
                        last_insert_sent = clamp(locked_pos)
                        last_hold_at = time.monotonic()
                        force_enabled = False
                        force_state = "MANUAL"
                        force_contact_count = 0
                        force_start_z = tcp[2]
                        force_backoff_goal_z = None
                        force_status_at = 0.0
                        locked = True
                        print(
                            "🔒 已锁定当前TCP姿态，"
                            f"F₀=[{force_baseline[0]:+.2f},"
                            f"{force_baseline[1]:+.2f},"
                            f"{force_baseline[2]:+.2f}]N")
                        print(
                            "🎮 共享插入: 摇杆=精细XY，"
                            "右键0/1=手动Z上/下，"
                            f"右键2=切换{FORCE_TARGET:.1f}N恒力环；"
                            "拨轮暂禁")
        btn_prev[1] = btn1

        # ── locked: 插入模式 ──
        if locked:
            if getattr(node, '_right_at_target', False):
                node.send_right(right_traj[-1])
            # 手柄左右方向与base X相反，取负号使操作方向符合直觉。
            jx = -float(joy[0]) if len(joy)>0 and abs(float(joy[0])) > JOY_DEADBAND else 0.0
            jy = float(joy[1]) if len(joy)>1 and abs(float(joy[1])) > JOY_DEADBAND else 0.0
            dz = 0.0
            axial = total = lateral = float("nan")

            if btnR2_edge:
                if force_enabled:
                    force_enabled = False
                    force_state = "MANUAL"
                    print("\n🕹 已退出恒力环，恢复手动Z")
                elif force_state in ("FAULT", "PAUSED"):
                    force_enabled = False
                    force_state = "MANUAL"
                    force_backoff_goal_z = None
                    print("\n✅ 已确认安全状态，恢复手动Z；再次按键可启动恒力环")
                elif force_state == "DEPTH_LIMIT":
                    print("\n⚠ 已到Z软限位，请先手动上升")
                elif node.force_fresh():
                    force_enabled = True
                    force_state = "APPROACH"
                    force_contact_count = 0
                    print(
                        f"\n💪 启动恒力环：接触阈值={FORCE_CONTACT:.1f}N，"
                        f"目标={FORCE_TARGET:.1f}N")
                else:
                    print("\n⚠ 六维力数据未就绪，无法启动恒力环")

            force = node.filtered_force()
            if force is None or not node.force_fresh():
                if force_state != "PAUSED":
                    print("\n⚠ 六维力数据超时，暂停共享插入")
                force_enabled = False
                force_state = "PAUSED"
            else:
                axial, total, lateral = _force_components(
                    force, force_baseline, node._force_axis)

                if force_state not in ("FAULT", "PAUSED", "DEPTH_LIMIT"):
                    if force_state == "MANUAL":
                        safety_trip = (
                            abs(axial) >= MANUAL_AXIAL_HARD_STOP or
                            lateral >= FORCE_LATERAL_STOP)
                        reason = (
                            f"手动轴向力={axial:.2f}N"
                            if abs(axial) >= MANUAL_AXIAL_HARD_STOP
                            else f"横向力={lateral:.2f}N")
                        if (
                            not safety_trip and
                            abs(axial) >= MANUAL_AXIAL_WARN and
                            time.monotonic() - force_warn_at > 1.0
                        ):
                            print(
                                f"\n⚠ 手动压紧轴向力={axial:.2f}N，"
                                f"{MANUAL_AXIAL_HARD_STOP:.1f}N时硬停")
                            force_warn_at = time.monotonic()
                    else:
                        safety_trip = (
                            total >= FORCE_HARD_STOP or
                            lateral >= FORCE_LATERAL_STOP)
                        reason = (
                            f"|ΔF|={total:.2f}N"
                            if total >= FORCE_HARD_STOP
                            else f"横向力={lateral:.2f}N")

                    if safety_trip:
                        print(f"\n⛔ {reason}，自动回退{FORCE_BACKOFF*1000:.0f}mm并暂停")
                        force_fault_was_manual = force_state == "MANUAL"
                        force_enabled = False
                        force_state = "FAULT"
                        force_backoff_goal_z = min(
                            force_start_z,
                            insert_target[2] + FORCE_BACKOFF)

                if force_state == "APPROACH":
                    if axial >= FORCE_CONTACT:
                        force_contact_count += 1
                    else:
                        force_contact_count = 0
                    if force_contact_count >= FORCE_CONTACT_FRAMES:
                        force_state = "FORCE"
                        print(
                            f"\n✅ 检测到接触，进入恒力模式 "
                            f"F={axial:.2f}N")
                    else:
                        dz = -FORCE_MAX_SPEED * INSERT_LOOP_DT
                elif force_state == "FORCE":
                    error = FORCE_TARGET - axial
                    if abs(error) > FORCE_DEADBAND:
                        dz = -max(
                            -FORCE_MAX_SPEED * INSERT_LOOP_DT,
                            min(
                                FORCE_MAX_SPEED * INSERT_LOOP_DT,
                                FORCE_GAIN * error))
                elif force_state == "FAULT" and force_backoff_goal_z is not None:
                    remaining = force_backoff_goal_z - insert_target[2]
                    force_is_safe = (
                        (abs(axial) < MANUAL_AXIAL_HARD_STOP
                         if force_fault_was_manual
                         else total < FORCE_HARD_STOP) and
                        lateral < FORCE_LATERAL_STOP)
                    if (
                        remaining <= 1e-6 and
                        force_is_safe
                    ):
                        force_state = "MANUAL"
                        force_backoff_goal_z = None
                        print("\n✅ 超力回退完成，自动恢复手动Z")
                    else:
                        dz = max(
                            0.0,
                            min(
                                2.0 * FORCE_MAX_SPEED * INSERT_LOOP_DT,
                                remaining))
                elif force_state == "MANUAL":
                    dz = (
                        (MANUAL_Z_STEP if btnR0 else 0.0) -
                        (MANUAL_Z_STEP if btnR1 else 0.0))
                elif force_state == "DEPTH_LIMIT" and btnR0:
                    dz = MANUAL_Z_STEP
                    force_state = "MANUAL"

            descent = force_start_z - insert_target[2]
            if (
                force_state in ("MANUAL", "APPROACH", "FORCE") and
                dz < 0.0 and
                descent - dz >= FORCE_MAX_DESCENT
            ):
                dz = -max(0.0, FORCE_MAX_DESCENT - descent)
                force_enabled = False
                force_state = "DEPTH_LIMIT"
                print(
                    f"\n⚠ 达到Z软限位 {FORCE_MAX_DESCENT*1000:.1f}mm，"
                    "保持当前位置，不自动返回")

            movement_enabled = force_state not in (
                "FAULT", "PAUSED", "DEPTH_LIMIT")
            if not movement_enabled:
                jx = jy = 0.0

            has_motion = abs(jx)>0 or abs(jy)>0 or abs(dz)>1e-9
            if has_motion:
                # 单一Cartesian请求同时合成人工XY与自动恒力Z，姿态保持不变。
                candidate_target = [
                    insert_target[0] + jx * FORCE_XY_STEP,
                    insert_target[1] + jy * FORCE_XY_STEP,
                    insert_target[2] + dz,
                ]
                raw_path, fraction = node.cartesian_path(
                    candidate_target, insert_base_ori, seed=last_insert_sent)
                path, jump = _validate_joint_path(
                    raw_path, last_insert_sent, CART_MAX_JOINT_STEP) if raw_path else (None, None)
                if path and fraction >= CART_MIN_FRACTION:
                    point_delay = min(0.02, INSERT_LOOP_DT / max(len(path), 1))
                    for joints in path:
                        node.send_left(joints, spd=SPD_INSERT_L)
                        if point_delay > 0:
                            time.sleep(point_delay)
                    last_insert_sent = list(path[-1])
                    insert_target = candidate_target
                    last_hold_at = time.monotonic()
                elif time.monotonic() - ik_warn_at > 1.0:
                    if raw_path and path is None and jump is not None:
                        detail = f"轨迹关节跳变 {math.degrees(jump):.1f}°"
                    else:
                        detail = f"Cartesian fraction={fraction:.3f}"
                    print(f"⚠ 连续笛卡尔路径失败（{detail}），保持上一位置")
                    force_enabled = False
                    force_state = "PAUSED"
                    ik_warn_at = time.monotonic()

            now = time.monotonic()
            if now - force_status_at >= 0.5:
                depth = (force_start_z - insert_target[2]) * 1000.0
                print(
                    f"\r💪 {force_state:11s} "
                    f"Fz={axial:+4.2f}N |ΔF|={total:4.2f}N "
                    f"F侧={lateral:4.2f}N Z={depth:5.1f}mm   ",
                    end="", flush=True)
                force_status_at = now

            # bodyctrl 只需低频刷新保持，不在静止时重复求 IK。
            if last_insert_sent and time.monotonic() - last_hold_at >= HOLD_PERIOD:
                node.send_left(last_insert_sent, spd=SPD_INSERT_L)
                last_hold_at = time.monotonic()
            time.sleep(INSERT_LOOP_DT); continue

        # ── unlocked: 遥操模式 ──
        if state == "waiting":
            if not check_safety(hand_angles): time.sleep(0.1); continue
            print("→ 逼近..."); state = "approaching"

        if state == "approaching":
            done = True
            for i in range(7):
                d = hand_angles[i] - start_angles[i]
                if abs(d) < 0.001: continue
                done = False; start_angles[i] += max(-APPROACH_STEP, min(APPROACH_STEP, d))
            if done: print("→ 跟随"); state = "following"
            else: node.send_left(clamp(start_angles)); time.sleep(0.02); continue

        if state == "following":
            cl = clamp(hand_angles)
            if last_sent != cl: node.send_left(cl); last_sent = list(cl)
            time.sleep(0.005)
            continue

        time.sleep(0.01)


def _return_to_hanging(node, left_traj, start_hint):
    """3s关节插值到录制终点 → 倒放回悬垂"""
    start = node.get_left_joints(max_age=2.0) or list(start_hint)
    target = list(left_traj[-1])
    print("  3s返回录制终点...")
    if not _move_left_smooth(
            node, start, target, RETURN_TRANSITION_SEC, spd=SPD_INSERT_L):
        return
    print("  ◀ 倒放回悬垂...")
    for a in reversed(left_traj): node.send_left(a); time.sleep(0.012)


def _nearest_trajectory_index(current, trajectory):
    return min(
        range(len(trajectory)),
        key=lambda idx: sum((current[i] - trajectory[idx][i])**2 for i in range(7)))


def _left_return_to_hanging_nearest(node, left_traj):
    """Ctrl+C时从左臂当前位置接入最近轨迹点，再倒放回悬垂。"""
    current = node.get_left_joints(max_age=2.0) or node._last_left_command
    if current is None:
        print("  ⚠ 无左臂当前关节状态，跳过左臂自动回收")
        return
    if _joints_diff(current, left_traj[0]) <= HANGING_TOL:
        print("  左臂已在悬垂位置")
        return

    nearest = _nearest_trajectory_index(current, left_traj)
    join_delta = _joints_diff(current, left_traj[nearest])
    print(
        f"  左臂接入最近轨迹点 {nearest}/{len(left_traj)-1}，"
        f"最大关节差={math.degrees(join_delta):.1f}°...")
    if not _move_left_smooth(
            node, current, left_traj[nearest],
            RETURN_TRANSITION_SEC, spd=SPD_INSERT_L):
        return
    print("  ◀ 左臂从最近点倒放回悬垂...")
    for angles in reversed(left_traj[:nearest + 1]):
        node.send_left(angles)
        time.sleep(0.012)


def _right_return_to_hanging(node, right_traj):
    """从右臂当前状态衔接到最近轨迹点，再倒放回悬垂。"""
    current = node.get_right_joints(max_age=2.0) or node._last_right_command
    if current is None:
        print("  ⚠ 无右臂当前关节状态，跳过右臂自动回收")
        return
    if _joints_diff(current, right_traj[0]) <= HANGING_TOL:
        print("  右臂已在悬垂位置")
        node._right_at_target = False
        node._right_traj_index = 0
        return

    nearest = _nearest_trajectory_index(current, right_traj)
    print(f"  右臂衔接轨迹点 {nearest}/{len(right_traj)-1}...")
    if not _move_right_smooth(
            node, current, right_traj[nearest], RIGHT_RETURN_TRANSITION_SEC):
        return
    print("  ◀ 右臂倒放回悬垂...")
    for angles in reversed(right_traj[:nearest + 1]):
        node.send_right(angles)
        time.sleep(0.012)
    node._right_at_target = False
    node._right_traj_index = 0


def _recover_competition_to_hanging(node):
    """Ctrl+C安全回收：先右臂，再左臂。"""
    right_traj = getattr(node, '_competition_right_traj', None)
    left_traj = getattr(node, '_competition_left_traj', None)
    if not right_traj or not left_traj:
        print("⚠ 比赛轨迹尚未加载，无法自动回收")
        return

    print("🛟 Ctrl+C安全回收：先处理右臂")
    _right_return_to_hanging(node, right_traj)

    print("🛟 处理左臂")
    _left_return_to_hanging_nearest(node, left_traj)
    print("✅ 双臂安全回收完成")


# ═══════════════════ main ═══════════════════

def main():
    from rclpy.signals import SignalHandlerOptions
    # 第一次Ctrl+C只打断主流程，保持ROS上下文存活以执行双臂安全回收。
    rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    signal.signal(signal.SIGINT, signal.default_int_handler)
    node = BodyCtrlNode()
    from rclpy.executors import SingleThreadedExecutor
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()
    time.sleep(0.5)

    ctx = zmq.Context(); sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.CONFLATE, 1); sock.setsockopt(zmq.SUBSCRIBE, b"")
    sock.connect(f"tcp://{ZMQ_IP}:{ZMQ_PORT}"); sock.setsockopt(zmq.RCVTIMEO, 200)

    mode = sys.argv[sys.argv.index("--mode")+1] if "--mode" in sys.argv else "init"
    try:
        if mode == "init":
            mode_init(node, sock)
        elif mode == "compete":
            mode_compete(node, sock)
        else:
            raise ValueError(f"未知模式: {mode}")
    except KeyboardInterrupt:
        print("\n⚠ 收到Ctrl+C，开始安全回收；再次Ctrl+C可立即中止")
        if mode == "compete":
            try:
                _recover_competition_to_hanging(node)
            except KeyboardInterrupt:
                print("\n⛔ 安全回收被用户中止")
    finally:
        sock.close(linger=0); ctx.destroy()
        executor.shutdown()
        spin_thread.join(timeout=1.0)
        node.destroy_node(); rclpy.try_shutdown()
    print("✅ 已退出")

if __name__ == "__main__": main()
