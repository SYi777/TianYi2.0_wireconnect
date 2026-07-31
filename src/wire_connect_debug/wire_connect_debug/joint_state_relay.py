#!/usr/bin/env python3
"""Relay + merge joint_states from robot + inspire hand → /joint_states

Sources:
  /joint_state_broadcaster/joint_states  (body + arm joints)
  /inspire_hand/state/left_hand          (6 finger DOFs)
  /inspire_hand/state/right_hand         (6 finger DOFs)

Inspire hand index → URDF joint name (left):
  1 → left_thumb_1      4 → left_middle_1
  2 → left_thumb_2      5 → left_ring_1
  3 → left_index_1      6 → left_little_1

Mimic joints computed from multipliers in URDF:
  thumb_3 = thumb_2 * 1.1425    thumb_4 = thumb_3 * 0.7508
  *_2 = *_1 * 1.1169 (index, middle, ring, little)
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState


# inspire hand index → URDF joint name (independent joints only)
LEFT_HAND_MAP = {
    '1': 'left_thumb_1_joint',
    '2': 'left_thumb_2_joint',
    '3': 'left_index_1_joint',
    '4': 'left_middle_1_joint',
    '5': 'left_ring_1_joint',
    '6': 'left_little_1_joint',
}
RIGHT_HAND_MAP = {
    '1': 'right_thumb_1_joint',
    '2': 'right_thumb_2_joint',
    '3': 'right_index_1_joint',
    '4': 'right_middle_1_joint',
    '5': 'right_ring_1_joint',
    '6': 'right_little_1_joint',
}

# mimic rules: (dependent_joint, source_joint, multiplier)
LEFT_MIMIC = [
    ('left_thumb_3_joint', 'left_thumb_2_joint', 1.1425),
    ('left_thumb_4_joint', 'left_thumb_3_joint', 0.7508),
    ('left_index_2_joint', 'left_index_1_joint', 1.1169),
    ('left_middle_2_joint', 'left_middle_1_joint', 1.1169),
    ('left_ring_2_joint', 'left_ring_1_joint', 1.1169),
    ('left_little_2_joint', 'left_little_1_joint', 1.1169),
]
RIGHT_MIMIC = [
    ('right_thumb_3_joint', 'right_thumb_2_joint', 1.1425),
    ('right_thumb_4_joint', 'right_thumb_3_joint', 0.7508),
    ('right_index_2_joint', 'right_index_1_joint', 1.1169),
    ('right_middle_2_joint', 'right_middle_1_joint', 1.1169),
    ('right_ring_2_joint', 'right_ring_1_joint', 1.1169),
    ('right_little_2_joint', 'right_little_1_joint', 1.1169),
]


class JointStateRelay(Node):
    def __init__(self):
        super().__init__("joint_state_relay")
        self._pub = self.create_publisher(JointState, "/joint_states", 10)

        # body + arm joints
        self._body_js = JointState()
        self.create_subscription(JointState,
            "/joint_state_broadcaster/joint_states", self._cb_body, 10)

        # hand states
        self._left_hand = {}
        self._right_hand = {}
        self.create_subscription(JointState,
            "/inspire_hand/state/left_hand", self._cb_left, 10)
        self.create_subscription(JointState,
            "/inspire_hand/state/right_hand", self._cb_right, 10)

        # publish merged state at 50Hz
        self.create_timer(0.02, self._publish)
        self.get_logger().info("joint_state_relay: body + inspire hand → /joint_states")

    def _cb_body(self, msg: JointState):
        self._body_js = msg

    def _cb_left(self, msg: JointState):
        self._left_hand = dict(zip(msg.name, msg.position))

    def _cb_right(self, msg: JointState):
        self._right_hand = dict(zip(msg.name, msg.position))

    def _publish(self):
        if not self._body_js.name:
            return

        out = JointState()
        out.header.stamp = self.get_clock().now().to_msg()
        out.header.frame_id = "base"

        # copy body/arm joints
        out.name = list(self._body_js.name)
        out.position = list(self._body_js.position)
        out.velocity = list(self._body_js.velocity) if self._body_js.velocity else [0.0] * len(out.name)
        out.effort = list(self._body_js.effort) if self._body_js.effort else [0.0] * len(out.name)

        # merge left hand
        for idx, jname in LEFT_HAND_MAP.items():
            if idx in self._left_hand:
                out.name.append(jname)
                out.position.append(float(self._left_hand[idx]))
                out.velocity.append(0.0)
                out.effort.append(0.0)

        # left mimic joints
        for dep, src, mult in LEFT_MIMIC:
            if src in out.name:
                src_idx = out.name.index(src)
                out.name.append(dep)
                out.position.append(out.position[src_idx] * mult)
                out.velocity.append(0.0)
                out.effort.append(0.0)

        # merge right hand
        for idx, jname in RIGHT_HAND_MAP.items():
            if idx in self._right_hand:
                out.name.append(jname)
                out.position.append(float(self._right_hand[idx]))
                out.velocity.append(0.0)
                out.effort.append(0.0)

        # right mimic joints
        for dep, src, mult in RIGHT_MIMIC:
            if src in out.name:
                src_idx = out.name.index(src)
                out.name.append(dep)
                out.position.append(out.position[src_idx] * mult)
                out.velocity.append(0.0)
                out.effort.append(0.0)

        self._pub.publish(out)


def main():
    rclpy.init()
    node = JointStateRelay()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
