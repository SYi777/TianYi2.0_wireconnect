// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sys_msgs:srv/FaultClear.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__BUILDER_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sys_msgs/srv/detail/fault_clear__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sys_msgs
{

namespace srv
{

namespace builder
{

class Init_FaultClear_Request_fault_array
{
public:
  Init_FaultClear_Request_fault_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sys_msgs::srv::FaultClear_Request fault_array(::sys_msgs::srv::FaultClear_Request::_fault_array_type arg)
  {
    msg_.fault_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sys_msgs::srv::FaultClear_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::srv::FaultClear_Request>()
{
  return sys_msgs::srv::builder::Init_FaultClear_Request_fault_array();
}

}  // namespace sys_msgs


namespace sys_msgs
{

namespace srv
{

namespace builder
{

class Init_FaultClear_Response_success
{
public:
  Init_FaultClear_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sys_msgs::srv::FaultClear_Response success(::sys_msgs::srv::FaultClear_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sys_msgs::srv::FaultClear_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::srv::FaultClear_Response>()
{
  return sys_msgs::srv::builder::Init_FaultClear_Response_success();
}

}  // namespace sys_msgs

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__BUILDER_HPP_
