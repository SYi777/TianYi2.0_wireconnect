#!/usr/bin/env python3
"""bodyctrl → /joint_states 转发 (替代 XARM joint_state_broadcaster)

订阅 bodyctrl motor status → 映射 URDF 关节名 → 发布 JointState
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from bodyctrl_msgs.msg import MotorStatusMsg

# 电机ID → URDF 关节名 (与 joint_state_relay 互补, 这边只管 body+arm)
MOTOR_TO_JOINT = {
    1: "head_roll_joint",   2: "head_pitch_joint",   3: "head_yaw_joint",
    # 左臂
    11: "shoulder_pitch_l_joint", 12: "shoulder_roll_l_joint",  13: "shoulder_yaw_l_joint",
    14: "elbow_pitch_l_joint",    15: "elbow_yaw_l_joint",    16: "wrist_pitch_l_joint",
    17: "wrist_roll_l_joint",
    # 右臂
    21: "shoulder_pitch_r_joint", 22: "shoulder_roll_r_joint",  23: "shoulder_yaw_r_joint",
    24: "elbow_pitch_r_joint",    25: "elbow_yaw_r_joint",    26: "wrist_pitch_r_joint",
    27: "wrist_roll_r_joint",
    # 身体
    31: "waist_yaw_joint",  32: "waist_pitch_joint",
    51: "first_leg_pitch_joint", 52: "second_leg_pitch_joint",
}


class BodyctrlBridge(Node):
    def __init__(self):
        super().__init__("bodyctrl_bridge")
        self._pub = self.create_publisher(JointState, "/joint_states", 10)
        self._pos = {}

        self.create_subscription(MotorStatusMsg, "/arm/status", self._cb_arm, 10)
        self.create_subscription(MotorStatusMsg, "/head/status", self._cb_head, 10)
        self.create_subscription(MotorStatusMsg, "/waist/status", self._cb_waist, 10)
        self.create_subscription(MotorStatusMsg, "/leg/status", self._cb_leg, 10)

        self.create_timer(0.02, self._publish)  # 50Hz
        self.get_logger().info("bodyctrl_bridge → /joint_states")

    def _store(self, msg: MotorStatusMsg):
        for s in msg.status:
            self._pos[s.name] = float(s.pos)

    _cb_arm = _store; _cb_head = _store; _cb_waist = _store; _cb_leg = _store

    def _publish(self):
        js = JointState()
        js.header.stamp = self.get_clock().now().to_msg()
        js.header.frame_id = "base"
        for mid, jname in sorted(MOTOR_TO_JOINT.items()):
            if mid in self._pos:
                js.name.append(jname)
                js.position.append(self._pos[mid])
                js.velocity.append(0.0)
                js.effort.append(0.0)
        self._pub.publish(js)


def main():
    rclpy.init(); rclpy.spin(BodyctrlBridge()); rclpy.shutdown()

if __name__ == "__main__": main()
