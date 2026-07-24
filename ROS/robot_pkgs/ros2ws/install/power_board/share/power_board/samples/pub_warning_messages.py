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

  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_CLEAR, "clear warning without existing error")
  time.sleep(1)

  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_OCCUR, "simulate a warning error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_OCCUR, "simulate a warning error")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_CLEAR, "clear warning with one error")
  time.sleep(3)

  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_OCCUR, "simulate first warning error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_OCCUR, "simulate second warning error")
  time.sleep(1)
  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_OCCUR, "simulate second warning error")
  time.sleep(3)
  node.publish_message(LightCtrl.CMD_SYSTEM_WARN_CLEAR, "clear warning with two errors")
  time.sleep(3)

  node.quit()


if __name__ == '__main__':
  main()
