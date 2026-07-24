// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cloud_service:srv/Register.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__SRV__DETAIL__REGISTER__BUILDER_HPP_
#define CLOUD_SERVICE__SRV__DETAIL__REGISTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cloud_service/srv/detail/register__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cloud_service
{

namespace srv
{

namespace builder
{

class Init_Register_Request_handler_service_name
{
public:
  explicit Init_Register_Request_handler_service_name(::cloud_service::srv::Register_Request & msg)
  : msg_(msg)
  {}
  ::cloud_service::srv::Register_Request handler_service_name(::cloud_service::srv::Register_Request::_handler_service_name_type arg)
  {
    msg_.handler_service_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::srv::Register_Request msg_;
};

class Init_Register_Request_cmd_id
{
public:
  Init_Register_Request_cmd_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Register_Request_handler_service_name cmd_id(::cloud_service::srv::Register_Request::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_Register_Request_handler_service_name(msg_);
  }

private:
  ::cloud_service::srv::Register_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::srv::Register_Request>()
{
  return cloud_service::srv::builder::Init_Register_Request_cmd_id();
}

}  // namespace cloud_service


namespace cloud_service
{

namespace srv
{

namespace builder
{

class Init_Register_Response_success
{
public:
  Init_Register_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cloud_service::srv::Register_Response success(::cloud_service::srv::Register_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::srv::Register_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::srv::Register_Response>()
{
  return cloud_service::srv::builder::Init_Register_Response_success();
}

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__SRV__DETAIL__REGISTER__BUILDER_HPP_
