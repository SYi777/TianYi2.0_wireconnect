import time

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import PowerBatteryStatus
from bodyctrl_msgs.msg import PowerBoardKeyStatus
from bodyctrl_msgs.msg import PowerStatus


class PowerboardSubscriber(Node):

  def __init__(self):
    super().__init__('powerboard_subscriber')

    self.power_status_count = 0
    self.power_battery_status_count = 0
    self.power_board_key_status_count = 0
    self.start_time = self.get_clock().now()

    self.get_logger().info(
      "Powerboard Subscriber node has started.")

    self.create_subscription(
      PowerStatus,
      "/power/board/status",
      self.power_status_callback,
      10)

    self.create_subscription(
      PowerBatteryStatus,
      "/power/battery/status",
      self.power_battery_status_callback,
      10)

    self.create_subscription(
      PowerBoardKeyStatus,
      "/power/board/key_status",
      self.power_board_key_status_callback,
      10)

  def power_status_callback(self, msg):
    self.get_logger().info(f"Received PowerStatus: {msg}")
    self.power_status_count += 1

  def power_battery_status_callback(self, msg):
    self.get_logger().info(f"Received PowerBatteryStatus: {msg}")
    self.power_battery_status_count += 1

  def power_board_key_status_callback(self, msg):
    self.get_logger().info(f"Received PowerBoardKeyStatus: {msg}")
    self.power_board_key_status_count += 1

  def print_summary(self):
    self.print_time = self.get_clock().now()
    duration = self.print_time - self.start_time

    print_message = (
      f"=== Powerboard Status Summary ===\n"
      f"PowerStatus:         {self.power_status_count} times, "
      f"{self.power_status_count / duration.nanoseconds * 1e9:.2f}Hz\n"
      f"PowerBatteryStatus:  {self.power_battery_status_count} times, "
      f"{self.power_battery_status_count / duration.nanoseconds * 1e9:.2f}Hz\n"
      f"PowerBoardKeyStatus: {self.power_board_key_status_count} times, "
      f"{self.power_board_key_status_count / duration.nanoseconds * 1e9:.2f}Hz")

    if rclpy.ok():
      self.get_logger().info(print_message)
    else:
      print(print_message)


def main(args=None):
  rclpy.init(args=args)
  subscriber = PowerboardSubscriber()
  try:
    rclpy.spin(subscriber)
  except KeyboardInterrupt:
    subscriber.print_summary()
  subscriber.destroy_node()
  rclpy.shutdown()


if __name__ == '__main__':
  main()
