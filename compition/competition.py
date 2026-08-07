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
ISO_SYNC_HOST = "192.168.41.100"
ISO_SYNC_PORT = 6003
ISO_SYNC_HZ = 100.0
CONFIG_DIR = os.path.expanduser("~/WireConnect_ws/config")
WORKSPACE_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FORCE_AXIS_FILES = [
    os.path.join(os.path.dirname(os.path.abspath(__file__)), "force_axis_cal.json"),
    os.path.join(WORKSPACE_ROOT, "src", "tools", "force_axis_cal.json"),
]

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
ROT_STEP = 0.01         # 拨轮每单位旋转量(rad)
SCROLL_CHANGE_EPS = 0.002
CART_MAX_STEP = 0.002  # 连续笛卡尔路径内部插值步长(m)
CART_JUMP_THRESHOLD = 1.5
CART_MIN_FRACTION = 0.99
JOY_DEADBAND = 0.08  # 摇杆死区
CART_MAX_JOINT_STEP = math.radians(10.0)
RETURN_TRANSITION_SEC = 3.0
RIGHT_RETURN_TRANSITION_SEC = 1.0
RIGHT_REPLAY_JOIN_SEC = 0.5
HANGING_TOL = math.radians(5.0)
INSERT_LOOP_DT = 0.05
HOLD_PERIOD = 0.2

FORCE_FILTER_SAMPLES = 5
FORCE_TARGET = 1.2
FORCE_CONTACT = 0.8
FORCE_CONTACT_FRAMES = 5
FORCE_HARD_STOP = 4.0
FORCE_LATERAL_STOP = 3.0
FORCE_MAX_SPEED = 0.002       # m/s
FORCE_GAIN = 0.0001           # m/(N·周期)
FORCE_DEADBAND = 0.1
FORCE_MAX_DESCENT = 0.03      # 仅软限位，达到后保持
FORCE_BACKOFF = 0.002         # 超力后回退2mm
FORCE_STALE_SEC = 0.1

MOVEIT_ERROR_NAMES = {
    1: "SUCCESS",
    -1: "PLANNING_FAILED",
    -2: "INVALID_MOTION_PLAN",
    -6: "TIMED_OUT",
    -10: "START_STATE_IN_COLLISION",
    -12: "GOAL_IN_COLLISION",
    -15: "INVALID_GROUP_NAME",
    -17: "INVALID_ROBOT_STATE",
    -18: "INVALID_LINK_NAME",
    -21: "FRAME_TRANSFORM_FAILURE",
    -22: "COLLISION_CHECKING_UNAVAILABLE",
    -23: "ROBOT_STATE_STALE",
    -31: "NO_IK_SOLUTION",
}


def _joints_diff(a, b):
    if a is None or b is None: return 999
    return max(abs(a[i]-b[i]) for i in range(7))


def clamp(a, limits=JOINT_LIMITS_L):
    return [max(limits[i][0], min(limits[i][1], a[i])) for i in range(7)]

def check_safety(a, ref=REF_L):
    return all(abs(a[i]-ref[i]) < SAFE_TH[i] for i in range(7))


def _load_force_axis():
    force_axis_file = next(
        (path for path in FORCE_AXIS_FILES if os.path.isfile(path)), None)
    if force_axis_file is None:
        raise FileNotFoundError(
            "找不到力轴标定文件，已检查: " + ", ".join(FORCE_AXIS_FILES))
    with open(force_axis_file) as file:
        data = json.load(file)
    axis = [float(value) for value in data["u"]]
    norm = math.sqrt(sum(value*value for value in axis))
    if norm < 1e-9:
        raise ValueError("force_axis_cal.json 中的 u 无效")
    return [value / norm for value in axis], force_axis_file


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

    def cartesian_path(
            self, pos, ori, seed, *,
            avoid_collisions=True,
            jump_threshold=CART_JUMP_THRESHOLD):
        """返回连续关节路径、完成比例和MoveIt诊断原因。"""
        from geometry_msgs.msg import Point, Pose, Quaternion
        from moveit_msgs.msg import RobotState
        from moveit_msgs.srv import GetCartesianPath
        if not self._cartesian.wait_for_service(timeout_sec=0.5):
            return None, 0.0, "服务 /compute_cartesian_path 不可用"

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
        req.jump_threshold = jump_threshold
        req.avoid_collisions = avoid_collisions

        future = self._cartesian.call_async(req)
        deadline = time.monotonic() + 1.0
        while rclpy.ok() and not future.done() and time.monotonic() < deadline:
            time.sleep(0.002)
        if not future.done():
            return None, 0.0, "Cartesian服务响应超时"
        result = future.result()
        if result is None:
            return None, 0.0, "Cartesian服务返回空结果"
        error_code = int(result.error_code.val)
        if error_code != 1:
            error_name = MOVEIT_ERROR_NAMES.get(
                error_code, f"MoveIt错误码{error_code}")
            return None, float(result.fraction), error_name

        trajectory = result.solution.joint_trajectory
        names = list(trajectory.joint_names)
        if not trajectory.points or not all(name in names for name in ARM_J_L):
            return None, float(result.fraction), "轨迹为空或缺少左臂关节"
        indexes = [names.index(name) for name in ARM_J_L]
        path = [
            [float(point.positions[index]) for index in indexes]
            for point in trajectory.points
        ]
        return path, float(result.fraction), "SUCCESS"

    def get_tcp(self):
        """Current TCP [x,y,z,qx,qy,qz,qw] in waist_yaw_link or None."""
        try:
            t = self._tf_buf.lookup_transform("waist_yaw_link", "left_tcp_link", rclpy.time.Time(),
                                               timeout=rclpy.duration.Duration(seconds=0.3))
            r = t.transform.rotation
            return [t.transform.translation.x, t.transform.translation.y, t.transform.translation.z,
                    r.x, r.y, r.z, r.w]
        except: return None


class IsomorphicSyncController:
    """在独立线程中以100Hz发送机器人关节状态给同构臂。"""
    def __init__(self, node):
        self._node = node
        self._enabled = threading.Event()
        self._stop = threading.Event()
        self._ready = threading.Event()
        self._stopped_ack = threading.Event()
        self._stopped_ack.set()
        self._thread = threading.Thread(
            target=self._run, name="isomorphic_sync", daemon=True)
        self._thread.start()
        if not self._ready.wait(timeout=1.0):
            raise RuntimeError("同构臂同步线程启动失败")

    def _run(self):
        context = zmq.Context()
        publisher = context.socket(zmq.PUB)
        publisher.setsockopt(zmq.LINGER, 0)
        publisher.connect(f"tcp://{ISO_SYNC_HOST}:{ISO_SYNC_PORT}")
        time.sleep(0.1)

        def send_stop(repeats=3):
            for _ in range(repeats):
                publisher.send(json.dumps({
                    "type": "get_xtele",
                }).encode("utf-8"))
                time.sleep(0.01)

        # 主动清除工控机可能残留的反向同步状态。
        send_stop(repeats=10)
        self._ready.set()
        was_syncing = False
        last_stop_sent = 0.0
        period = 1.0 / ISO_SYNC_HZ
        try:
            while not self._stop.is_set():
                if self._enabled.is_set():
                    left = self._node.get_left_joints(max_age=1.0)
                    right = self._node.get_right_joints(max_age=1.0)
                    if left is not None and right is not None:
                        position = list(left) + list(right) + [0.0]
                        publisher.send(json.dumps({
                            "type": "sync_xtele",
                            "position": position,
                        }).encode("utf-8"))
                        was_syncing = True
                        self._stopped_ack.clear()
                    self._stop.wait(period)
                else:
                    now = time.monotonic()
                    if was_syncing or now - last_stop_sent >= 0.5:
                        send_stop()
                        was_syncing = False
                        last_stop_sent = time.monotonic()
                    self._stopped_ack.set()
                    self._stop.wait(0.02)
        finally:
            if was_syncing:
                send_stop()
            self._stopped_ack.set()
            publisher.close()
            context.destroy()

    def start(self):
        self._stopped_ack.clear()
        self._enabled.set()

    def stop(self):
        self._enabled.clear()
        self._stopped_ack.wait(timeout=0.3)

    def shutdown(self):
        self.stop()
        self._stop.set()
        self._thread.join(timeout=1.0)


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


def _quat_multiply(a, b):
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return [
        aw*bx + ax*bw + ay*bz - az*by,
        aw*by - ax*bz + ay*bw + az*bx,
        aw*bz + ax*by - ay*bx + az*bw,
        aw*bw - ax*bx - ay*by - az*bz,
    ]


def _rotate_local_x(orientation, angle):
    half = angle / 2.0
    return _quat_multiply(
        orientation, [math.sin(half), 0.0, 0.0, math.cos(half)])


def _rotate_base_z(orientation, angle):
    half = angle / 2.0
    return _quat_multiply(
        [0.0, 0.0, math.sin(half), math.cos(half)], orientation)


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


def _closest_joint_limit(joints):
    closest = None
    for i, value in enumerate(joints):
        lo, hi = JOINT_LIMITS_L[i]
        margin = min(value - lo, hi - value)
        if closest is None or margin < closest[1]:
            closest = (ARM_J_L[i], margin, value, lo, hi)
    return closest


def _diagnose_cartesian_failure(
        node, target, orientation, seed,
        raw_path, validated_path, jump, fraction, service_reason):
    """只做诊断复算，不执行返回的无碰撞/无跳变保护轨迹。"""
    if raw_path and validated_path is None:
        if jump is None:
            return "轨迹包含超出软件关节限位的解"
        return (
            f"IK分支跳变 {math.degrees(jump):.1f}° "
            f"(允许上限{math.degrees(CART_MAX_JOINT_STEP):.1f}°)")

    no_collision_path, no_collision_fraction, no_collision_reason = (
        node.cartesian_path(
            target, orientation, seed, avoid_collisions=False))
    if no_collision_path and no_collision_fraction >= CART_MIN_FRACTION:
        return (
            "碰撞检查阻止运动 "
            f"(关闭碰撞后fraction={no_collision_fraction:.3f})")

    no_jump_path, no_jump_fraction, no_jump_reason = node.cartesian_path(
        target, orientation, seed,
        avoid_collisions=False, jump_threshold=0.0)
    if no_jump_path and no_jump_fraction >= CART_MIN_FRACTION:
        _, no_jump_size = _validate_joint_path(
            no_jump_path, seed, CART_MAX_JOINT_STEP)
        jump_text = (
            f"，候选关节跳变={math.degrees(no_jump_size):.1f}°"
            if no_jump_size is not None else "")
        return f"接近奇异位或IK分支不连续{jump_text}"

    closest = _closest_joint_limit(seed)
    if closest and closest[1] < math.radians(8.0):
        name, margin, value, lo, hi = closest
        return (
            f"关节接近限位: {name} 余量={math.degrees(margin):.1f}° "
            f"当前={value:.3f} 范围=[{lo:.3f},{hi:.3f}]")

    reasons = "/".join(dict.fromkeys([
        service_reason, no_collision_reason, no_jump_reason]))
    return (
        "无连续IK解：可能处于奇异位、工作空间边界或目标不可达 "
        f"(fraction={fraction:.3f}, no_collision={no_collision_fraction:.3f}, "
        f"no_jump={no_jump_fraction:.3f}, {reasons})")


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
    node._force_axis, force_axis_file = _load_force_axis()
    print(
        "💪 加载力控轴向 u="
        f"[{node._force_axis[0]:+.3f},"
        f"{node._force_axis[1]:+.3f},"
        f"{node._force_axis[2]:+.3f}] "
        f"({force_axis_file})")
    if not hasattr(node, "_iso_sync"):
        node._iso_sync = IsomorphicSyncController(node)
    print(
        f"🔄 同构臂反向同步已就绪 → "
        f"{ISO_SYNC_HOST}:{ISO_SYNC_PORT} ({ISO_SYNC_HZ:.0f}Hz)")

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
    lock_setup_failed = False
    hand_open = False
    btn_prev = [False]*5
    btn_right_prev = [False]*3
    insert_target = None
    insert_base_ori = None
    insert_target_ori = None
    scroll_baseline_l = None
    scroll_baseline_r = None
    last_rot_x = 0.0
    last_rot_z = 0.0
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
    force_enabled = False
    force_baseline_valid = False
    control_reason = "正常"
    b, r, joy = [], [], [0.0, 0.0]
    scr_l, scr_r = 0.0, 0.0

    while rclpy.ok():
        # ZMQ drain
        try:
            while True:
                d = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
                a = d.get("arm",{}).get("position",{}).get("left")
                b = d.get("button",{}).get("left",[])
                r = d.get("button",{}).get("right",[])
                joy = d.get("joystick",{}).get("left",[0.0,0.0])
                scroll = d.get("scroll", {})
                scr_l = scroll.get("left", 0)
                scr_r = scroll.get("right", 0)
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
                right_current = (
                    node.get_right_joints(max_age=2.0) or
                    node._last_right_command)
                if right_current is not None:
                    nearest = _nearest_trajectory_index(
                        right_current, right_traj)
                    join_diff = _joints_diff(
                        right_current, right_traj[nearest])
                    print(
                        f"  右臂最近轨迹点 "
                        f"{nearest}/{len(right_traj)-1}，"
                        f"接入差值={math.degrees(join_diff):.1f}°")
                    if join_diff > math.radians(1.0):
                        _move_right_smooth(
                            node, right_current, right_traj[nearest],
                            RIGHT_REPLAY_JOIN_SEC)
                else:
                    nearest = int(getattr(
                        node, '_right_traj_index', 0))
                    print(
                        f"⚠ 无右臂实时关节状态，使用记录轨迹点 {nearest}")

                # 同一进程内沿用上次方向；重启后若已在终点则自动倒放。
                reverse = (
                    getattr(node, '_right_at_target', False) or
                    nearest >= len(right_traj) - 2)
                print("◀ 左手第三键触发右臂倒放..." if reverse
                      else "▶ 左手第三键触发右臂正放...")
                indexes = (
                    range(nearest, -1, -1)
                    if reverse else range(nearest, len(right_traj)))
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
                # 解除机器人→同构臂反向同步，恢复同构臂→机器人遥操。
                print("\n✅ 插入完成 → 切回正常同构臂遥操")
                node._iso_sync.stop()
                time.sleep(0.1)
                latest_master = _recv_latest_master_left(
                    sock, hand_angles)
                locked = False
                force_enabled = False
                force_state = "IDLE"
                force_baseline_valid = False
                current = (
                    node.get_left_joints(max_age=2.0) or
                    list(last_insert_sent or locked_pos))
                start_angles = list(current)
                last_sent = list(current)
                hand_angles = (
                    list(latest_master)
                    if latest_master is not None else list(current))
                state = "approaching"
                btn_prev[1] = btn1
                print("🔄 已停止反向同步，左臂短步进吸收残差")
                time.sleep(0.02)
                continue
            else:
                # 自锁当前TCP位姿，不再强制切换到固定插入朝向。
                # 进入插入前确保同构臂反向同步已关闭。
                node._iso_sync.stop()
                locked_pos = node.get_left_joints(max_age=2.0) or list(last_sent or hand_angles)
                tcp = node.get_tcp()
                current_ori = _normalize_quat(tcp[3:7]) if tcp else None
                if tcp is None or current_ori is None:
                    lock_setup_failed = True
                    print(
                        "⚠ 当前TCP获取失败，机器人保持关节锁定；"
                        "再次按左手第二键重试")
                    node.send_left(locked_pos, spd=SPD_INSERT_L)
                else:
                    force_baseline = None
                    force_baseline_valid = False
                    insert_target = list(tcp[:3])
                    insert_base_ori = current_ori
                    insert_target_ori = list(current_ori)
                    scroll_baseline_l = float(scr_l)
                    scroll_baseline_r = float(scr_r)
                    last_rot_x = 0.0
                    last_rot_z = 0.0
                    last_insert_sent = clamp(locked_pos)
                    last_hold_at = time.monotonic()
                    force_enabled = False
                    force_state = "MANUAL"
                    force_contact_count = 0
                    force_start_z = tcp[2]
                    force_backoff_goal_z = None
                    force_status_at = 0.0
                    lock_setup_failed = False
                    control_reason = "纯手动控制（未启用六维力）"
                    locked = True
                    node._iso_sync.start()
                    print("🔒 已锁定当前TCP姿态，进入纯手动插入")
                    print("🔄 已切换为机器人→同构臂反向跟随")
                    print(
                        "🎮 共享插入: 摇杆=精细XY，拨轮=姿态，"
                        "右键0/1=手动Z上/下，"
                        f"右键2=切换{FORCE_TARGET:.1f}N恒力环")
        btn_prev[1] = btn1

        if lock_setup_failed:
            node.send_left(locked_pos, spd=SPD_INSERT_L)
            time.sleep(INSERT_LOOP_DT)
            continue

        # ── locked: 插入模式 ──
        if locked:
            if getattr(node, '_right_at_target', False):
                node.send_right(right_traj[-1])
            # 同构手柄XY与base平面方向均相反，两个轴全部取反。
            jx = -float(joy[0]) if len(joy)>0 and abs(float(joy[0])) > JOY_DEADBAND else 0.0
            jy = -float(joy[1]) if len(joy)>1 and abs(float(joy[1])) > JOY_DEADBAND else 0.0
            dz = 0.0
            axial = total = lateral = float("nan")
            desired_orientation = insert_target_ori
            orientation_changed = False

            if btnR2_edge:
                if force_enabled:
                    force_enabled = False
                    force_state = "MANUAL"
                    control_reason = "人工退出恒力环"
                    print("\n🕹 已退出恒力环，恢复手动Z")
                elif force_state in ("FAULT", "PAUSED"):
                    force_enabled = False
                    force_state = "MANUAL"
                    force_backoff_goal_z = None
                    control_reason = "故障已确认，手动模式"
                    print("\n✅ 已确认安全状态，恢复手动Z；再次按键可启动恒力环")
                elif force_state == "DEPTH_LIMIT":
                    print("\n⚠ 已到Z软限位，请先手动上升")
                elif node.force_fresh():
                    if not force_baseline_valid:
                        print(
                            "\n⏳ 姿态已改变，启动恒力前重新采集F₀；"
                            "请确保尚未接触插座并保持静止...")
                        force_baseline, force_std = (
                            node.sample_force_baseline(0.5))
                        force_baseline_valid = (
                            force_baseline is not None and
                            max(force_std) <= 0.5)
                    if force_baseline_valid:
                        force_enabled = True
                        force_state = "APPROACH"
                        force_contact_count = 0
                        control_reason = "寻找接触"
                        print(
                            f"\n💪 启动恒力环："
                            f"接触阈值={FORCE_CONTACT:.1f}N，"
                            f"目标={FORCE_TARGET:.1f}N")
                    else:
                        print(
                            f"\n⚠ 力基线重新采集失败 σ={force_std}，"
                            "保持手动模式")
                else:
                    print("\n⚠ 六维力数据未就绪，无法启动恒力环")

            force_control_active = force_state in (
                "APPROACH", "FORCE", "FAULT")
            if force_control_active:
                force = node.filtered_force()
                if force is None or not node.force_fresh():
                    if time.monotonic() - force_warn_at > 1.0:
                        print(
                            "\n⚠ 六维力数据超时，退出恒力环；"
                            "手动控制继续可用")
                        force_warn_at = time.monotonic()
                    force_enabled = False
                    if force_state in ("APPROACH", "FORCE"):
                        force_state = "MANUAL"
                        control_reason = "恒力退出，纯手动控制"
                else:
                    axial, total, lateral = _force_components(
                        force, force_baseline, node._force_axis)

                    if force_state in ("APPROACH", "FORCE"):
                        safety_trip = (
                            total >= FORCE_HARD_STOP or
                            lateral >= FORCE_LATERAL_STOP)
                        reason = (
                            f"|ΔF|={total:.2f}N"
                            if total >= FORCE_HARD_STOP
                            else f"横向力={lateral:.2f}N")
                        if safety_trip:
                            print(
                                f"\n⛔ {reason}，自动回退"
                                f"{FORCE_BACKOFF*1000:.0f}mm并退出恒力")
                            force_enabled = False
                            force_state = "FAULT"
                            control_reason = reason
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
                            control_reason = "恒力环运行中"
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
                    elif (
                        force_state == "FAULT" and
                        force_backoff_goal_z is not None
                    ):
                        remaining = (
                            force_backoff_goal_z - insert_target[2])
                        force_is_safe = (
                            total < FORCE_HARD_STOP and
                            lateral < FORCE_LATERAL_STOP)
                        if remaining <= 1e-6 and force_is_safe:
                            force_state = "MANUAL"
                            force_backoff_goal_z = None
                            control_reason = "超力回退完成"
                            print(
                                "\n✅ 超力回退完成，自动恢复纯手动控制")
                        else:
                            dz = max(
                                0.0,
                                min(
                                    2.0 * FORCE_MAX_SPEED *
                                    INSERT_LOOP_DT,
                                    remaining))
            if force_state == "MANUAL":
                dz = (
                    (MANUAL_Z_STEP if btnR0 else 0.0) -
                    (MANUAL_Z_STEP if btnR1 else 0.0))
            elif force_state == "DEPTH_LIMIT" and btnR0:
                dz = MANUAL_Z_STEP
                force_state = "MANUAL"
                control_reason = "已离开Z软限位"

            if force_state == "MANUAL":
                rot_x = (
                    (float(scr_l) - scroll_baseline_l) * ROT_STEP
                    if scroll_baseline_l is not None else 0.0)
                rot_z = (
                    (float(scr_r) - scroll_baseline_r) * ROT_STEP
                    if scroll_baseline_r is not None else 0.0)
                orientation_changed = (
                    abs(rot_x - last_rot_x) > SCROLL_CHANGE_EPS or
                    abs(rot_z - last_rot_z) > SCROLL_CHANGE_EPS)
                if orientation_changed:
                    desired_orientation = _rotate_base_z(
                        _rotate_local_x(insert_base_ori, rot_x), rot_z)

            descent = force_start_z - insert_target[2]
            if (
                force_state in ("MANUAL", "APPROACH", "FORCE") and
                dz < 0.0 and
                descent - dz >= FORCE_MAX_DESCENT
            ):
                dz = -max(0.0, FORCE_MAX_DESCENT - descent)
                force_enabled = False
                force_state = "DEPTH_LIMIT"
                control_reason = "达到Z软限位"
                print(
                    f"\n⚠ 达到Z软限位 {FORCE_MAX_DESCENT*1000:.1f}mm，"
                    "保持当前位置，不自动返回")

            movement_enabled = force_state not in (
                "FAULT", "PAUSED", "DEPTH_LIMIT")
            if not movement_enabled:
                jx = jy = 0.0

            has_motion = (
                abs(jx)>0 or abs(jy)>0 or abs(dz)>1e-9 or
                orientation_changed)
            if has_motion:
                # 单一Cartesian请求同时合成人工XY与自动恒力Z，姿态保持不变。
                candidate_target = [
                    insert_target[0] + jx * FORCE_XY_STEP,
                    insert_target[1] + jy * FORCE_XY_STEP,
                    insert_target[2] + dz,
                ]
                raw_path, fraction, service_reason = node.cartesian_path(
                    candidate_target, desired_orientation,
                    seed=last_insert_sent)
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
                    insert_target_ori = list(desired_orientation)
                    if orientation_changed:
                        last_rot_x = rot_x
                        last_rot_z = rot_z
                        force_baseline_valid = False
                        control_reason = "姿态已改变，恒力启动时将重采F₀"
                    last_hold_at = time.monotonic()
                    if force_state == "MANUAL" and not orientation_changed:
                        control_reason = "手动控制正常"
                    elif force_state == "APPROACH":
                        control_reason = "寻找接触"
                    elif force_state == "FORCE":
                        control_reason = "恒力环运行中"
                elif time.monotonic() - ik_warn_at > 1.0:
                    detail = _diagnose_cartesian_failure(
                        node, candidate_target, desired_orientation,
                        last_insert_sent, raw_path, path, jump,
                        fraction, service_reason)
                    print(f"\n⚠ 无法控制：{detail}；保持上一位置")
                    force_enabled = False
                    force_state = "PAUSED"
                    control_reason = detail
                    ik_warn_at = time.monotonic()

            now = time.monotonic()
            if now - force_status_at >= 0.5:
                depth = (force_start_z - insert_target[2]) * 1000.0
                if force_state in ("APPROACH", "FORCE", "FAULT"):
                    print(
                        f"\r💪 {force_state:11s} "
                        f"F轴={axial:+4.2f}N |ΔF|={total:4.2f}N "
                        f"F侧={lateral:4.2f}N Z={depth:5.1f}mm "
                        f"原因={control_reason[:52]:52s}",
                        end="", flush=True)
                else:
                    print(
                        f"\r🕹 {force_state:11s} "
                        f"Z={depth:5.1f}mm 力控=OFF "
                        f"原因={control_reason[:52]:52s}",
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


def _recv_latest_master_left(sock, latest=None):
    try:
        while True:
            data = json.loads(sock.recv(zmq.NOBLOCK).decode("utf-8"))
            angles = data.get("arm", {}).get("position", {}).get("left")
            if angles and len(angles) == 7:
                latest = [float(value) for value in angles]
    except (zmq.Again, json.JSONDecodeError, UnicodeDecodeError):
        pass
    return latest


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

    sync = getattr(node, "_iso_sync", None)
    if sync is not None:
        sync.stop()
    print("🛟 Ctrl+C安全回收：先处理右臂")
    _right_return_to_hanging(node, right_traj)

    print("🛟 处理左臂")
    _left_return_to_hanging_nearest(node, left_traj)
    print("✅ 双臂已从各自最近轨迹点倒放回悬垂")


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
        sync = getattr(node, "_iso_sync", None)
        if sync is not None:
            sync.shutdown()
        executor.shutdown()
        spin_thread.join(timeout=1.0)
        node.destroy_node(); rclpy.try_shutdown()
    print("✅ 已退出")

if __name__ == "__main__": main()
