// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cloud_service:msg/TraceData.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__BUILDER_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cloud_service/msg/detail/trace_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cloud_service
{

namespace msg
{

namespace builder
{

class Init_TraceData_double_val
{
public:
  explicit Init_TraceData_double_val(::cloud_service::msg::TraceData & msg)
  : msg_(msg)
  {}
  ::cloud_service::msg::TraceData double_val(::cloud_service::msg::TraceData::_double_val_type arg)
  {
    msg_.double_val = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

class Init_TraceData_bool_val
{
public:
  explicit Init_TraceData_bool_val(::cloud_service::msg::TraceData & msg)
  : msg_(msg)
  {}
  Init_TraceData_double_val bool_val(::cloud_service::msg::TraceData::_bool_val_type arg)
  {
    msg_.bool_val = std::move(arg);
    return Init_TraceData_double_val(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

class Init_TraceData_str_val
{
public:
  explicit Init_TraceData_str_val(::cloud_service::msg::TraceData & msg)
  : msg_(msg)
  {}
  Init_TraceData_bool_val str_val(::cloud_service::msg::TraceData::_str_val_type arg)
  {
    msg_.str_val = std::move(arg);
    return Init_TraceData_bool_val(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

class Init_TraceData_int_val
{
public:
  explicit Init_TraceData_int_val(::cloud_service::msg::TraceData & msg)
  : msg_(msg)
  {}
  Init_TraceData_str_val int_val(::cloud_service::msg::TraceData::_int_val_type arg)
  {
    msg_.int_val = std::move(arg);
    return Init_TraceData_str_val(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

class Init_TraceData_data_type
{
public:
  explicit Init_TraceData_data_type(::cloud_service::msg::TraceData & msg)
  : msg_(msg)
  {}
  Init_TraceData_int_val data_type(::cloud_service::msg::TraceData::_data_type_type arg)
  {
    msg_.data_type = std::move(arg);
    return Init_TraceData_int_val(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

class Init_TraceData_key
{
public:
  Init_TraceData_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TraceData_data_type key(::cloud_service::msg::TraceData::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_TraceData_data_type(msg_);
  }

private:
  ::cloud_service::msg::TraceData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::msg::TraceData>()
{
  return cloud_service::msg::builder::Init_TraceData_key();
}

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATA__BUILDER_HPP_
