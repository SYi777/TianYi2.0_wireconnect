#!/usr/bin/env python3
# Copyright 2024 PAL Robotics S.L.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions

from std_srvs.srv import SetBool


def main(args=None):
    rclpy.init(args=args, signal_handler_options=SignalHandlerOptions.NO)
    parser = argparse.ArgumentParser(description="Control auto switch mode for controller manager")
    parser.add_argument(
        "-c",
        "--controller-manager",
        type=str,
        default="controller_manager",
        help="Controller manager name",
    )
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument(
        "--enable",
        action="store_true",
        help="Enable auto switch mode",
    )
    group.add_argument(
        "--disable",
        action="store_true",
        help="Disable auto switch mode",
    )

    args_cli = parser.parse_args()
    node = Node("auto_switch_mode_cli")

    cm = args_cli.controller_manager.strip("/")
    service_name = "/" + cm + "/auto_switch_mode"
    client = node.create_client(SetBool, service_name)

    if not client.wait_for_service(timeout_sec=5.0):
        node.get_logger().error(f"Service {service_name} not available")
        node.destroy_node()
        rclpy.shutdown()
        return 1

    request = SetBool.Request()
    request.data = args_cli.enable

    node.get_logger().info(f"Calling service {service_name} with data={request.data}")

    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future, timeout_sec=5.0)

    if future.result() is not None:
        response = future.result()
        if response.success:
            node.get_logger().info(f"Success: {response.message}")
        else:
            node.get_logger().error(f"Failed: {response.message}")
        node.destroy_node()
        rclpy.shutdown()
        return 0 if response.success else 1
    else:
        node.get_logger().error("Service call failed")
        node.destroy_node()
        rclpy.shutdown()
        return 1


if __name__ == "__main__":
    main()
