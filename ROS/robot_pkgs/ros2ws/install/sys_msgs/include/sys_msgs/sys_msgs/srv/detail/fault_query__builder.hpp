// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sys_msgs:srv/FaultQuery.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_QUERY__BUILDER_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_QUERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sys_msgs/srv/detail/fault_query__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sys_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::srv::FaultQuery_Request>()
{
  return ::sys_msgs::srv::FaultQuery_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sys_msgs


namespace sys_msgs
{

namespace srv
{

namespace builder
{

class Init_FaultQuery_Response_fault_array
{
public:
  Init_FaultQuery_Response_fault_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sys_msgs::srv::FaultQuery_Response fault_array(::sys_msgs::srv::FaultQuery_Response::_fault_array_type arg)
  {
    msg_.fault_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sys_msgs::srv::FaultQuery_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sys_msgs::srv::FaultQuery_Response>()
{
  return sys_msgs::srv::builder::Init_FaultQuery_Response_fault_array();
}

}  // namespace sys_msgs

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_QUERY__BUILDER_HPP_
