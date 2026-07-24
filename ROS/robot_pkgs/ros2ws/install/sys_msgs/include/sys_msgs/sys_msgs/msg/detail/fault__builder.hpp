// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT__BUILDER_HPP_
#define SYS_MSGS__MSG__DETAIL__FAULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sys_msgs/msg/detail/fault__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sys_msgs
{

namespace msg
{

namespace builder
{

class Init_Fault_status
{
public:
  explicit Init_Fault_status(::sys_msgs::msg::Fault & msg)
  : msg_(msg)
  {}
  ::sys_msgs::msg::Fault status(::sys_msgs::msg::Fault::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sys_msgs::msg::Fault msg_;
};

class Init_Fault_code
{
public:
  explicit Init_Fault_code(::sys_msgs::msg::Fault & msg)
  : msg_(msg)
  {}
  Init_Fault_status code(::sys_msgs::msg::Fault::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_Fault_status(msg_);
  }

private:
  ::sys_msgs::msg::Fault msg_;
};

class Init_Fault_time_stamp_ms
{
public:
  Init_Fault_time_stamp_ms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fault_code time_stamp_ms(::sys_msgs::msg::Fault::_time_stamp_ms_type arg)
  {
    msg_.time_stamp_ms = std::move(arg);
    return Init_Fault_code(msg_);
  }

private:
  ::sys_msgs::msg::Fault msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::msg::Fault>()
{
  return sys_msgs::msg::builder::Init_Fault_time_stamp_ms();
}

}  // namespace sys_msgs

#endif  // SYS_MSGS__MSG__DETAIL__FAULT__BUILDER_HPP_
