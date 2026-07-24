import time

import rclpy

from bodyctrl_msgs.msg import LightCtrl
from publisher import LightCtrlPublisher


class CustomNode(LightCtrlPublisher):

  def __init__(self):
    super().__init__()


def main(args=None):
  rclpy.init(args=args)

  node = CustomNode()
  if not rclpy.ok():
    return

  time.sleep(1)

  node.publish_message(LightCtrl.CMD_OTA_QUIT, "quit")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_OTA_START, "starting")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_OTA_START, "starting")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_OTA_QUIT, "quit")
  time.sleep(3)

  node.quit()


if __name__ == '__main__':
  main()
