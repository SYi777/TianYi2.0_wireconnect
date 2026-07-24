// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:srv/CommonStreamRos2.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__BUILDER_HPP_
#define CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/srv/detail/common_stream_ros2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_CommonStreamRos2_Request_data
{
public:
  explicit Init_CommonStreamRos2_Request_data(::cm_msgs::srv::CommonStreamRos2_Request & msg)
  : msg_(msg)
  {}
  ::cm_msgs::srv::CommonStreamRos2_Request data(::cm_msgs::srv::CommonStreamRos2_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::CommonStreamRos2_Request msg_;
};

class Init_CommonStreamRos2_Request_json_data
{
public:
  explicit Init_CommonStreamRos2_Request_json_data(::cm_msgs::srv::CommonStreamRos2_Request & msg)
  : msg_(msg)
  {}
  Init_CommonStreamRos2_Request_data json_data(::cm_msgs::srv::CommonStreamRos2_Request::_json_data_type arg)
  {
    msg_.json_data = std::move(arg);
    return Init_CommonStreamRos2_Request_data(msg_);
  }

private:
  ::cm_msgs::srv::CommonStreamRos2_Request msg_;
};

class Init_CommonStreamRos2_Request_msg_id
{
public:
  Init_CommonStreamRos2_Request_msg_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommonStreamRos2_Request_json_data msg_id(::cm_msgs::srv::CommonStreamRos2_Request::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_CommonStreamRos2_Request_json_data(msg_);
  }

private:
  ::cm_msgs::srv::CommonStreamRos2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::CommonStreamRos2_Request>()
{
  return cm_msgs::srv::builder::Init_CommonStreamRos2_Request_msg_id();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace srv
{

namespace builder
{

class Init_CommonStreamRos2_Response_info
{
public:
  explicit Init_CommonStreamRos2_Response_info(::cm_msgs::srv::CommonStreamRos2_Response & msg)
  : msg_(msg)
  {}
  ::cm_msgs::srv::CommonStreamRos2_Response info(::cm_msgs::srv::CommonStreamRos2_Response::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::srv::CommonStreamRos2_Response msg_;
};

class Init_CommonStreamRos2_Response_result
{
public:
  Init_CommonStreamRos2_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommonStreamRos2_Response_info result(::cm_msgs::srv::CommonStreamRos2_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_CommonStreamRos2_Response_info(msg_);
  }

private:
  ::cm_msgs::srv::CommonStreamRos2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::srv::CommonStreamRos2_Response>()
{
  return cm_msgs::srv::builder::Init_CommonStreamRos2_Response_result();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__SRV__DETAIL__COMMON_STREAM_ROS2__BUILDER_HPP_
