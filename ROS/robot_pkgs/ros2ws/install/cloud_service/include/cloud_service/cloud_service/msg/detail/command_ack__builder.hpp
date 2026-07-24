// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__BUILDER_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cloud_service/msg/detail/command_ack__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cloud_service
{

namespace msg
{

namespace builder
{

class Init_CommandAck_message
{
public:
  explicit Init_CommandAck_message(::cloud_service::msg::CommandAck & msg)
  : msg_(msg)
  {}
  ::cloud_service::msg::CommandAck message(::cloud_service::msg::CommandAck::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::msg::CommandAck msg_;
};

class Init_CommandAck_code
{
public:
  explicit Init_CommandAck_code(::cloud_service::msg::CommandAck & msg)
  : msg_(msg)
  {}
  Init_CommandAck_message code(::cloud_service::msg::CommandAck::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_CommandAck_message(msg_);
  }

private:
  ::cloud_service::msg::CommandAck msg_;
};

class Init_CommandAck_cmd_id
{
public:
  explicit Init_CommandAck_cmd_id(::cloud_service::msg::CommandAck & msg)
  : msg_(msg)
  {}
  Init_CommandAck_code cmd_id(::cloud_service::msg::CommandAck::_cmd_id_type arg)
  {
    msg_.cmd_id = std::move(arg);
    return Init_CommandAck_code(msg_);
  }

private:
  ::cloud_service::msg::CommandAck msg_;
};

class Init_CommandAck_msg_id
{
public:
  Init_CommandAck_msg_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommandAck_cmd_id msg_id(::cloud_service::msg::CommandAck::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_CommandAck_cmd_id(msg_);
  }

private:
  ::cloud_service::msg::CommandAck msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::msg::CommandAck>()
{
  return cloud_service::msg::builder::Init_CommandAck_msg_id();
}

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__BUILDER_HPP_
