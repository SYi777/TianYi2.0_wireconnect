// Copyright (c) 2025 System Group, Embodied BU.
//
// All rights reserved. This program and the accompanying materials are made
// available under the terms of the BSD License which accompany this
// distribution.
//
// @file play_url_srv.cpp
//
// Created on: 2025/08/28.
//     Author: Robin Yue.

#include <chrono>
#include <memory>

#include "lyre_msgs/srv/play_url.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("lyre_examples");

  rclcpp::Client<lyre_msgs::srv::PlayUrl>::SharedPtr client =
      node->create_client<lyre_msgs::srv::PlayUrl>(
          lyre_msgs::srv::PlayUrl::Request::SERVICE_NAME);

  auto request = std::make_shared<lyre_msgs::srv::PlayUrl::Request>();
  request->url =
      "https://cdn.pixabay.com/download/audio/2022/03/24/"
      "audio_090b7abf24.mp3?filename=shaker5-in-5s-8ths-103930.mp3";

  std::chrono::milliseconds interval = std::chrono::milliseconds{1000};
  while (!client->wait_for_service(interval)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                   "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  if (rclcpp::spin_until_future_complete(node, result) ==
      rclcpp::FutureReturnCode::SUCCESS) {
    auto response = result.get();
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                "The service was called successfully.");
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service.");
  }

  rclcpp::shutdown();

  return 0;
}
