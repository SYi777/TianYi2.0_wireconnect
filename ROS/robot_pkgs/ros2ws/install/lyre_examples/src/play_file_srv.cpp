// Copyright (c) 2025 System Group, Embodied BU.
//
// All rights reserved. This program and the accompanying materials are made
// available under the terms of the BSD License which accompany this
// distribution.
//
// @file play_file_srv.cpp
//
// Created on: 2025/08/28.
//     Author: Robin Yue.

#include <chrono>
#include <filesystem>
#include <memory>

#include "ament_index_cpp/get_package_share_directory.hpp"
#include "lyre_msgs/srv/play_file.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("lyre_examples");

  std::string project_share_directory =
      ament_index_cpp::get_package_share_directory("lyre_examples");
  auto share_directory =
      std::filesystem::path(project_share_directory).parent_path();
  auto res_directory = share_directory.parent_path();
  auto project_install_directory = share_directory.parent_path();
  auto file_path = project_install_directory / "res" / "test.mp3";

  rclcpp::Client<lyre_msgs::srv::PlayFile>::SharedPtr client =
      node->create_client<lyre_msgs::srv::PlayFile>(
          lyre_msgs::srv::PlayFile::Request::SERVICE_NAME);

  auto request = std::make_shared<lyre_msgs::srv::PlayFile::Request>();
  request->path = file_path;

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
