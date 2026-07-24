// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from controller_manager_msgs:srv/Debug.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__SRV__DETAIL__DEBUG__BUILDER_HPP_
#define CONTROLLER_MANAGER_MSGS__SRV__DETAIL__DEBUG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "controller_manager_msgs/srv/detail/debug__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace controller_manager_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::controller_manager_msgs::srv::Debug_Request>()
{
  return ::controller_manager_msgs::srv::Debug_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace controller_manager_msgs


namespace controller_manager_msgs
{

namespace srv
{

namespace builder
{

class Init_Debug_Response_debug_info
{
public:
  Init_Debug_Response_debug_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::controller_manager_msgs::srv::Debug_Response debug_info(::controller_manager_msgs::srv::Debug_Response::_debug_info_type arg)
  {
    msg_.debug_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controller_manager_msgs::srv::Debug_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::controller_manager_msgs::srv::Debug_Response>()
{
  return controller_manager_msgs::srv::builder::Init_Debug_Response_debug_info();
}

}  // namespace controller_manager_msgs

#endif  // CONTROLLER_MANAGER_MSGS__SRV__DETAIL__DEBUG__BUILDER_HPP_
