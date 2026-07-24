#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_srvs.srv import Trigger
from octomap_msgs.msg import Octomap
from threading import Lock

class OctomapChecker(Node):
    def __init__(self):
        super().__init__('octomap_checker')
        self.map_received = False
        self.lock = Lock()
        self.srv = self.create_service(Trigger, 'check_octomap', self.check_callback)
        self.sub = self.create_subscription(
            Octomap,
            '/octomap_full',  # 或你实际的 Octomap 话题名
            self.map_callback,
            10
        )

    def map_callback(self, msg):
        with self.lock:
            if msg.data:
                self.map_received = True
                self.get_logger().info('Octomap received!')

    def check_callback(self, request, response):
        with self.lock:
            if self.map_received:
                response.success = True
                response.message = 'Octomap has data.'
            else:
                response.success = False
                response.message = 'No Octomap data received.'
        return response

def main(args=None):
    rclpy.init(args=args)
    node = OctomapChecker()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
