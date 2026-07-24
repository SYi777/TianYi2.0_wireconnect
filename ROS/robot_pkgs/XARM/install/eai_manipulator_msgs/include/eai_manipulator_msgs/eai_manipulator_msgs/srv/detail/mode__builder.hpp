// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:srv/Mode.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/srv/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace srv
{

namespace builder
{

class Init_Mode_Request_mode
{
public:
  Init_Mode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::eai_manipulator_msgs::srv::Mode_Request mode(::eai_manipulator_msgs::srv::Mode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::Mode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::Mode_Request>()
{
  return eai_manipulator_msgs::srv::builder::Init_Mode_Request_mode();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace srv
{

namespace builder
{

class Init_Mode_Response_info
{
public:
  explicit Init_Mode_Response_info(::eai_manipulator_msgs::srv::Mode_Response & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::srv::Mode_Response info(::eai_manipulator_msgs::srv::Mode_Response::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::Mode_Response msg_;
};

class Init_Mode_Response_result
{
public:
  Init_Mode_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mode_Response_info result(::eai_manipulator_msgs::srv::Mode_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_Mode_Response_info(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::Mode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::Mode_Response>()
{
  return eai_manipulator_msgs::srv::builder::Init_Mode_Response_result();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__BUILDER_HPP_
