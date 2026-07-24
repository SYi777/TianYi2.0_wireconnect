// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cloud_service:srv/RemoteCtrl.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__BUILDER_HPP_
#define CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cloud_service/srv/detail/remote_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cloud_service
{

namespace srv
{

namespace builder
{

class Init_RemoteCtrl_Request_payload
{
public:
  explicit Init_RemoteCtrl_Request_payload(::cloud_service::srv::RemoteCtrl_Request & msg)
  : msg_(msg)
  {}
  ::cloud_service::srv::RemoteCtrl_Request payload(::cloud_service::srv::RemoteCtrl_Request::_payload_type arg)
  {
    msg_.payload = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::srv::RemoteCtrl_Request msg_;
};

class Init_RemoteCtrl_Request_cmd_id
{
public:
  explicit Init_RemoteCtrl_Request_cmd_id(::cloud_service::srv::RemoteCtrl_Request & msg)
  : msg_(msg)
  {}
  Init_RemoteCtrl_Request_payload cmd_id(::cloud_service::srv::RemoteCtrl_Request::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_RemoteCtrl_Request_payload(msg_);
  }

private:
  ::cloud_service::srv::RemoteCtrl_Request msg_;
};

class Init_RemoteCtrl_Request_msg_id
{
public:
  Init_RemoteCtrl_Request_msg_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RemoteCtrl_Request_cmd_id msg_id(::cloud_service::srv::RemoteCtrl_Request::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_RemoteCtrl_Request_cmd_id(msg_);
  }

private:
  ::cloud_service::srv::RemoteCtrl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::srv::RemoteCtrl_Request>()
{
  return cloud_service::srv::builder::Init_RemoteCtrl_Request_msg_id();
}

}  // namespace cloud_service


namespace cloud_service
{

namespace srv
{

namespace builder
{

class Init_RemoteCtrl_Response_message
{
public:
  explicit Init_RemoteCtrl_Response_message(::cloud_service::srv::RemoteCtrl_Response & msg)
  : msg_(msg)
  {}
  ::cloud_service::srv::RemoteCtrl_Response message(::cloud_service::srv::RemoteCtrl_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::srv::RemoteCtrl_Response msg_;
};

class Init_RemoteCtrl_Response_code
{
public:
  Init_RemoteCtrl_Response_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RemoteCtrl_Response_message code(::cloud_service::srv::RemoteCtrl_Response::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_RemoteCtrl_Response_message(msg_);
  }

private:
  ::cloud_service::srv::RemoteCtrl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::srv::RemoteCtrl_Response>()
{
  return cloud_service::srv::builder::Init_RemoteCtrl_Response_code();
}

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__SRV__DETAIL__REMOTE_CTRL__BUILDER_HPP_
