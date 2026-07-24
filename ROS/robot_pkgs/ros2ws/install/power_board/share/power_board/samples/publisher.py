import os
import sys
import time

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import LightCtrl


class Publisher(Node):

  def __init__(self, msg_type, topic_name, queue_size=10, retries=10):
    module = sys.modules[self.__class__.__module__]
    self.caller = os.path.basename(module.__file__).split(".")[0]
    self.running = True

    super().__init__(self.caller)
    self.publisher_ = self.create_publisher(msg_type, topic_name, queue_size)

    exit_flag = False
    while rclpy.ok() and not exit_flag:
      sub_info = self.get_subscriptions_info_by_topic(topic_name)
      if sub_info:
        self.get_logger().info(f"Found {len(sub_info)} subscriber(s) to {topic_name}")
        break
      else:
        self.get_logger().info(f"No subscribers to {topic_name} yet, waiting...")
        time.sleep(0.5)
        retries -= 1

      exit_flag = retries <= 0

    if exit_flag:
      self.get_logger().error(f"Exiting due to timeout while waiting for subscribers to {topic_name}.")
      self.quit()

  def quit(self):
    self.destroy_node()
    rclpy.shutdown()


class LightCtrlPublisher(Publisher):

  def __init__(self):
    super().__init__(LightCtrl, LightCtrl.TOPIC_NAME)

  def publish_message(self, cmd, desc):
    msg = LightCtrl()
    msg.header.stamp = self.get_clock().now().to_msg()
    msg.cmd = cmd
    msg.caller_msg = desc
    msg.caller_id = self.caller
    self.publisher_.publish(msg)
    self.get_logger().info('Publishing cmd:%d "%s"' % (msg.cmd, msg.caller_msg))
