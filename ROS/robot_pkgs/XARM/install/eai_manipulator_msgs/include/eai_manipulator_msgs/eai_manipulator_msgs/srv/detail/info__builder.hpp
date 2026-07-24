// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:srv/Info.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/srv/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::Info_Request>()
{
  return ::eai_manipulator_msgs::srv::Info_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace srv
{

namespace builder
{

class Init_Info_Response_info
{
public:
  Init_Info_Response_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::eai_manipulator_msgs::srv::Info_Response info(::eai_manipulator_msgs::srv::Info_Response::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::srv::Info_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::srv::Info_Response>()
{
  return eai_manipulator_msgs::srv::builder::Init_Info_Response_info();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__INFO__BUILDER_HPP_
