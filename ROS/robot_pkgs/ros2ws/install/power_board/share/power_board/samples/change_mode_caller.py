import json

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.srv import VersionUpgrade

class ChangeModeCaller(Node):

  def __init__(self):
    super().__init__("change_mode_caller")
    self.cli = self.create_client(VersionUpgrade, "/powerboard/change/mode")

    while not self.cli.wait_for_service(timeout_sec=1.0):
      self.get_logger().info("service not available, waiting again...")
    self.get_logger().info("service available")

    self.req = VersionUpgrade.Request()

  def send_request(self, mode):
    self.get_logger().info(f"calling service for mode: {mode}")
    self.req.param = json.dumps({"cmd": "CMD_CHANGE_MODE", "param": {"mode": mode}})
    return self.cli.call_async(self.req)
