#!/usr/bin/env python3
"""Data collection — raw topic recording for imitation learning.

Records: 3 cameras (compressed) + wrench + TCP + hand state → rosbag.
obs/act framing done offline in check_dataset (avoids redundant writes).

Usage:
    ros2 run data_collect record_episode --ros-args -p obs_window:=5
    s=start  s=stop  y=keep  n=discard
"""

import os
import sys
import select
import shutil
import termios
import tty

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from rclpy.serialization import serialize_message

from rosbag2_py import SequentialWriter, StorageOptions, ConverterOptions, TopicMetadata

from sensor_msgs.msg import CompressedImage, Image as ImageMsg, JointState
from geometry_msgs.msg import WrenchStamped, PoseStamped
from std_msgs.msg import Header
import tf2_ros

try:
    from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
    HAS_BODYCTRL = True
except ImportError:
    HAS_BODYCTRL = False

TOPIC_HEAD_CAMERA = "/ob_camera_head/color/image_raw"
TOPIC_WRIST_LEFT  = "/camera_wrist_left/camera_wrist_left/color/image_rect_raw"
TOPIC_WRIST_RIGHT = "/camera_wrist/camera_wrist/color/image_rect_raw"
TOPIC_FT_LEFT     = "/arm_6dof_left"

HEAD_MOTORS = {1: "roll", 2: "pitch", 3: "yaw"}


class RecordEpisode(Node):
    def __init__(self):
        super().__init__("record_episode")

        self.declare_parameter("obs_window", 5)
        self.declare_parameter("head_roll", 0.0)
        self.declare_parameter("head_pitch", 0.435)
        self.declare_parameter("head_yaw", 0.0)
        self.declare_parameter("output_dir", os.path.expanduser("~/bags"))
        self.declare_parameter("episode_prefix", "ep")
        self.declare_parameter("frame", "waist_yaw_link")
        self.declare_parameter("arm", "left")

        self._obs_window = self.get_parameter("obs_window").value
        self._out_dir = self.get_parameter("output_dir").value
        self._prefix = self.get_parameter("episode_prefix").value
        self._frame = self.get_parameter("frame").value
        self._arm = self.get_parameter("arm").value

        # TF for TCP
        self._tf_buf = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buf, self)

        # head publisher
        self._head_pub = None
        if HAS_BODYCTRL:
            self._head_pub = self.create_publisher(CmdSetMotorPosition, "/head/cmd_pos", 10)

        # subscribers — write directly to bag when recording
        qos_img = QoSProfile(depth=5, reliability=ReliabilityPolicy.BEST_EFFORT)
        self._latest_head = None
        self._latest_left = None
        self._latest_right = None
        self._latest_ft = None
        self._latest_hand = None

        self.create_subscription(ImageMsg, TOPIC_HEAD_CAMERA, self._cb_head, qos_img)
        self.create_subscription(ImageMsg, TOPIC_WRIST_LEFT, self._cb_left, qos_img)
        self.create_subscription(ImageMsg, TOPIC_WRIST_RIGHT, self._cb_right, qos_img)
        self.create_subscription(WrenchStamped, TOPIC_FT_LEFT, self._cb_ft, 10)
        # bag writer
        self._writer = None
        self._bag_path = ""
        self._recording = False

        # episode counter
        self._ep_idx = self._find_next_episode()

        # TCP timer (50Hz — TCP moves slowly, no need for 30Hz)
        self._latest_tcp = None
        self.create_timer(0.02, self._tcp_timer)

        self._set_head()
        self.get_logger().info(f"ready  obs_window={self._obs_window}  dir={self._out_dir}")
        self.get_logger().info("arm mode=2 gravity-comp → drag to demonstrate")

    # ── subscribers ──────────────────────────────────────────────────
    def _cb_head(self, msg: ImageMsg):
        self._latest_head = msg
        if self._recording and self._writer:
            self._writer.write(TOPIC_HEAD_CAMERA, serialize_message(msg),
                               self.get_clock().now().nanoseconds)

    def _cb_left(self, msg: ImageMsg):
        self._latest_left = msg
        if self._recording and self._writer:
            self._writer.write(TOPIC_WRIST_LEFT, serialize_message(msg),
                               self.get_clock().now().nanoseconds)

    def _cb_right(self, msg: ImageMsg):
        self._latest_right = msg
        if self._recording and self._writer:
            self._writer.write(TOPIC_WRIST_RIGHT, serialize_message(msg),
                               self.get_clock().now().nanoseconds)

    def _cb_ft(self, msg: WrenchStamped):
        self._latest_ft = msg
        if self._recording and self._writer:
            self._writer.write(TOPIC_FT_LEFT, serialize_message(msg),
                               self.get_clock().now().nanoseconds)

    def _tcp_timer(self):
        """Publish TCP pose at 50Hz."""
        tcp = self._get_tcp_pose()
        if tcp is not None and self._recording and self._writer:
            tcp.header.stamp = self.get_clock().now().to_msg()
            self._writer.write("/tcp_pose", serialize_message(tcp),
                               self.get_clock().now().nanoseconds)

    def _get_tcp_pose(self):
        try:
            t = self._tf_buf.lookup_transform(
                self._frame, f"{self._arm}_tcp_link", rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.3))
            pose = PoseStamped()
            pose.header.frame_id = self._frame
            pose.pose.position.x = t.transform.translation.x
            pose.pose.position.y = t.transform.translation.y
            pose.pose.position.z = t.transform.translation.z
            pose.pose.orientation = t.transform.rotation
            return pose
        except Exception:
            return None

    # ── bag ───────────────────────────────────────────────────────────
    def _start_bag(self):
        os.makedirs(self._out_dir, exist_ok=True)
        self._bag_path = os.path.join(self._out_dir, f"{self._prefix}_{self._ep_idx:04d}")
        self.get_logger().info(f"recording → {self._bag_path}")

        self._writer = SequentialWriter()
        storage = StorageOptions(uri=self._bag_path, storage_id="sqlite3")
        storage.storage_config_uri = ""
        converter = ConverterOptions(
            input_serialization_format="cdr", output_serialization_format="cdr")
        self._writer.open(storage, converter)

        for t in [
            TopicMetadata(name=TOPIC_HEAD_CAMERA, type="sensor_msgs/msg/Image",
                          serialization_format="cdr"),
            TopicMetadata(name=TOPIC_WRIST_LEFT, type="sensor_msgs/msg/Image",
                          serialization_format="cdr"),
            TopicMetadata(name=TOPIC_WRIST_RIGHT, type="sensor_msgs/msg/Image",
                          serialization_format="cdr"),
            TopicMetadata(name=TOPIC_FT_LEFT, type="geometry_msgs/msg/WrenchStamped",
                          serialization_format="cdr"),
            TopicMetadata(name="/tcp_pose", type="geometry_msgs/msg/PoseStamped",
                          serialization_format="cdr"),
        ]:
            self._writer.create_topic(t)

        self._recording = True

    def _stop_bag(self) -> str:
        self._recording = False
        if self._writer:
            del self._writer
            self._writer = None
        return self._bag_path

    # ── head ──────────────────────────────────────────────────────────
    def _set_head(self):
        if not self._head_pub:
            return
        msg = CmdSetMotorPosition()
        msg.header = Header(stamp=self.get_clock().now().to_msg())
        msg.cmds = [
            SetMotorPosition(name=1, pos=self.get_parameter("head_roll").value,  spd=2.0, cur=1.0),
            SetMotorPosition(name=2, pos=self.get_parameter("head_pitch").value, spd=2.0, cur=1.0),
            SetMotorPosition(name=3, pos=self.get_parameter("head_yaw").value,   spd=2.0, cur=1.0),
        ]
        self._head_pub.publish(msg)
        self.get_logger().info(f"head → roll={msg.cmds[0].pos:.3f} "
                               f"pitch={msg.cmds[1].pos:.3f} yaw={msg.cmds[2].pos:.3f}")

    def _find_next_episode(self):
        os.makedirs(self._out_dir, exist_ok=True)
        idx = 0
        while os.path.exists(os.path.join(self._out_dir, f"{self._prefix}_{idx:04d}")):
            idx += 1
        return idx

    def run(self):
        fd = sys.stdin.fileno()
        old = termios.tcgetattr(fd)
        tty.setcbreak(fd)
        self.get_logger().info("s=start  s=stop  y=keep  n=discard  Esc=quit")

        try:
            while rclpy.ok():
                rclpy.spin_once(self, timeout_sec=0.02)
                if select.select([sys.stdin], [], [], 0)[0]:
                    key = sys.stdin.read(1)
                    if key in ('s', 'S'):
                        if not self._recording:
                            self._start_bag()
                            self._print(f"REC ● ep {self._ep_idx:04d}  s=stop")
                        else:
                            self._stop_bag()
                            self._print(f"stopped  y=keep  n=discard")
                    elif key in ('y', 'Y') and not self._recording and self._writer is None:
                        self._ep_idx += 1
                        self.get_logger().info(f"kept ep {self._ep_idx - 1:04d}")
                        self._print("s=start next")
                    elif key in ('n', 'N') and not self._recording and self._writer is None:
                        if os.path.exists(self._bag_path):
                            shutil.rmtree(self._bag_path)
                        self.get_logger().info(f"discarded ep {self._ep_idx:04d}")
                        self._bag_path = ""
                        self._print("s=start next")
                    elif key == '\x1b':
                        self.get_logger().info("quit")
                        break
        except KeyboardInterrupt:
            pass
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old)
            if self._recording:
                self._stop_bag()

    @staticmethod
    def _print(msg: str):
        sys.stdout.write(f"\r  [{msg}]" + " " * 30)
        sys.stdout.flush()


def main():
    rclpy.init()
    node = RecordEpisode()
    try:
        node.run()
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
