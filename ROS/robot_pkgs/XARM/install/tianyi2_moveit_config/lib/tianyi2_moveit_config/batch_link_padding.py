#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from moveit_msgs.msg import PlanningScene, LinkPadding

# 你的机器人所有 link
LINKS_TO_PAD = [
    "base",
    "first_leg_pitch_link",
    "second_leg_pitch_link",
    "waist_pitch_link",
    "waist_yaw_link",
    "head_yaw_link",
    "head_pitch_link",
    "head_roll_link",
    "shoulder_pitch_l_link",
    "shoulder_roll_l_link",
    "shoulder_yaw_l_link",
    "elbow_pitch_l_link",
    "elbow_yaw_l_link",
    "wrist_pitch_l_link",
    "wrist_roll_l_link",
    "L_base_link",
    "left_thumb_1",
    "left_thumb_2",
    "left_thumb_3",
    "left_thumb_4",
    "left_index_1",
    "left_index_2",
    "left_middle_1",
    "left_middle_2",
    "left_ring_1",
    "left_ring_2",
    "left_little_1",
    "left_little_2",
    "R_base_link",
    "right_thumb_1",
    "right_thumb_2",
    "right_thumb_3",
    "right_thumb_4",
    "left_tcp_link",
    "shoulder_pitch_r_link",
    "shoulder_roll_r_link",
    "shoulder_yaw_r_link",
    "elbow_pitch_r_link",
    "elbow_yaw_r_link",
    "wrist_pitch_r_link",
    "wrist_roll_r_link",
    "right_index_1",
    "right_index_2",
    "right_middle_1",
    "right_middle_2",
    "right_ring_1",
    "right_ring_2",
    "right_little_1",
    "right_little_2",
    "right_tcp_link",
]

PADDING_VALUE = 0.02  # 统一 2cm

class BatchLinkPadding(Node):
    def __init__(self):
        super().__init__('batch_link_padding')
        self.pub = self.create_publisher(PlanningScene, '/planning_scene', 10)
        # 定时发布一次即可
        self.timer = self.create_timer(1.5, self.publish_padding)

    def publish_padding(self):
        msg = PlanningScene()
        msg.is_diff = True
        msg.link_padding = [LinkPadding(link_name=l, padding=PADDING_VALUE) for l in LINKS_TO_PAD]
        self.pub.publish(msg)
        # self.get_logger().info(f'Published {PADDING_VALUE}m padding for {len(LINKS_TO_PAD)} links.')

def main(args=None):
    rclpy.init(args=args)
    node = BatchLinkPadding()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
