#pragma once
#include "controller_manager/controller_manager.hpp"

#include <iostream>
#include <memory>

#include "std_srvs/srv/empty.hpp"
#include <vector>
#include <string>

namespace controller_manager
{

/**
 * @brief 获取所有处于 active 状态的控制器
 * @param controllers_all 所有控制器的列表
 * @return active状态的控制器列表
 */
std::vector<controller_manager_msgs::msg::ControllerState> get_activated_controllers(
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers_all);

/**
 * @brief 获取所有处于非 active 状态的控制器
 * @param controllers_all 所有控制器的列表
 * @return 非active状态的控制器列表
 */
std::vector<controller_manager_msgs::msg::ControllerState> get_inactive_controllers(
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers_all);

/**
 * @brief 根据名称查找控制器
 * @param controllers_all 所有控制器的列表
 * @param name 要查找的控制器名称
 * @return 找到的控制器，未找到返回默认构造的ControllerState
 */
controller_manager_msgs::msg::ControllerState get_controller_by_name(
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers_all,
  const std::string & name);

/**
 * @brief 检查两个控制器是否存在冲突
 * @param controller1 第一个控制器
 * @param controller2 第二个控制器
 * @return 存在冲突返回true，否则返回false
 */
bool is_controller_conflict(
  const controller_manager_msgs::msg::ControllerState & controller1,
  const controller_manager_msgs::msg::ControllerState & controller2);

/**
 * @brief 获取与目标控制器冲突的所有控制器
 * @param target_controller 目标控制器
 * @param controllers_all 所有控制器的列表
 * @return 冲突的控制器列表
 */
std::vector<controller_manager_msgs::msg::ControllerState> get_conflicting_controllers(
  const controller_manager_msgs::msg::ControllerState & target_controller,
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers_all);

/**
 * @brief 检查一组控制器中是否存在相互冲突的控制器
 * @param controllers 要检查的控制器组
 * @return 存在冲突返回true，否则返回false
 */
bool has_conflict_in_controllers(
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers);

/**
 * @brief 获取第二组中与第一组冲突的控制器
 * @param controllers1 第一组控制器
 * @param controllers2 第二组控制器
 * @return 第二组中与第一组冲突的控制器列表
 */
std::vector<controller_manager_msgs::msg::ControllerState> get_conflicting_controllers_between_groups(
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers1,
  const std::vector<controller_manager_msgs::msg::ControllerState> & controllers2);
}
