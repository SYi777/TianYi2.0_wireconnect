// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__BUILDER_HPP_
#define SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sys_msgs/msg/detail/fault_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sys_msgs
{

namespace msg
{

namespace builder
{

class Init_FaultArray_fault_array
{
public:
  Init_FaultArray_fault_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sys_msgs::msg::FaultArray fault_array(::sys_msgs::msg::FaultArray::_fault_array_type arg)
  {
    msg_.fault_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sys_msgs::msg::FaultArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::msg::FaultArray>()
{
  return sys_msgs::msg::builder::Init_FaultArray_fault_array();
}

}  // namespace sys_msgs

#endif  // SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__BUILDER_HPP_
