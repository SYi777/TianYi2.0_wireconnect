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

  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_CLEAR, "clear fatal without existing error")
  time.sleep(1)

  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_OCCUR, "simulate a fatal error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_OCCUR, "simulate a fatal error")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_CLEAR, "clear fatal with one error")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_OCCUR, "simulate first fatal error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_OCCUR, "simulate second fatal error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_OCCUR, "simulate second fatal error")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_SYSTEM_ERROR_CLEAR, "clear fatal with two errors")
  time.sleep(3)

  node.quit()


if __name__ == '__main__':
  main()
