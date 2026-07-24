// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace msg
{

namespace builder
{

class Init_WarnAndErrorInfo_info
{
public:
  explicit Init_WarnAndErrorInfo_info(::eai_manipulator_msgs::msg::WarnAndErrorInfo & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo info(::eai_manipulator_msgs::msg::WarnAndErrorInfo::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo msg_;
};

class Init_WarnAndErrorInfo_source
{
public:
  explicit Init_WarnAndErrorInfo_source(::eai_manipulator_msgs::msg::WarnAndErrorInfo & msg)
  : msg_(msg)
  {}
  Init_WarnAndErrorInfo_info source(::eai_manipulator_msgs::msg::WarnAndErrorInfo::_source_type arg)
  {
    msg_.source = std::move(arg);
    return Init_WarnAndErrorInfo_info(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo msg_;
};

class Init_WarnAndErrorInfo_code
{
public:
  explicit Init_WarnAndErrorInfo_code(::eai_manipulator_msgs::msg::WarnAndErrorInfo & msg)
  : msg_(msg)
  {}
  Init_WarnAndErrorInfo_source code(::eai_manipulator_msgs::msg::WarnAndErrorInfo::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_WarnAndErrorInfo_source(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo msg_;
};

class Init_WarnAndErrorInfo_level
{
public:
  explicit Init_WarnAndErrorInfo_level(::eai_manipulator_msgs::msg::WarnAndErrorInfo & msg)
  : msg_(msg)
  {}
  Init_WarnAndErrorInfo_code level(::eai_manipulator_msgs::msg::WarnAndErrorInfo::_level_type arg)
  {
    msg_.level = std::move(arg);
    return Init_WarnAndErrorInfo_code(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo msg_;
};

class Init_WarnAndErrorInfo_header
{
public:
  Init_WarnAndErrorInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WarnAndErrorInfo_level header(::eai_manipulator_msgs::msg::WarnAndErrorInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WarnAndErrorInfo_level(msg_);
  }

private:
  ::eai_manipulator_msgs::msg::WarnAndErrorInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::msg::WarnAndErrorInfo>()
{
  return eai_manipulator_msgs::msg::builder::Init_WarnAndErrorInfo_header();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__WARN_AND_ERROR_INFO__BUILDER_HPP_
