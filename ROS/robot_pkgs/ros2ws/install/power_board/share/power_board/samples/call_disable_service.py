import rclpy

from change_mode_caller import ChangeModeCaller


def main(args=None):
  rclpy.init()

  node = ChangeModeCaller()
  future = node.send_request("disable")
  rclpy.spin_until_future_complete(node, future, timeout_sec=5)

  response = future.result()
  if response is None:
    node.get_logger().error("timeout")
  else:
    node.get_logger().info(f"response: {response.result}")

  node.destroy_node()
  rclpy.shutdown()

if __name__ == "__main__":
  main()
