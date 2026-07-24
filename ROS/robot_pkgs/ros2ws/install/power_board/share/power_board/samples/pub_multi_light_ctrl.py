import time

import rclpy
from rclpy.executors import SingleThreadedExecutor

from bodyctrl_msgs.msg import LightCtrl
from publisher import LightCtrlPublisher


class CustomNode(LightCtrlPublisher):

  def __init__(self):
    super().__init__()

  def start_timer(self, timer_period=0.001):
    self.idx = 0
    self.timer = self.create_timer(timer_period, self.timer_callback)

  def timer_callback(self):
    self.publish_message(LightCtrl.CMD_SYSTEM_STANDBY, f"{self.caller} call {self.idx}")

    self.idx += 1
    if self.idx >= 20:
      self.timer.cancel()
      self.running = False


def main(args=None):
  rclpy.init(args=args)

  node = CustomNode()
  executor = SingleThreadedExecutor()  # 手动创建执行器（替代默认spin）
  executor.add_node(node)

  node.start_timer()

  while rclpy.ok() and node.running:
    executor.spin_once(timeout_sec=0.01)  # 非阻塞自旋

  time.sleep(1)
  node.quit()


if __name__ == '__main__':
  main()
