// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__BUILDER_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cloud_service/msg/detail/trace_datas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cloud_service
{

namespace msg
{

namespace builder
{

class Init_TraceDatas_trace_array
{
public:
  explicit Init_TraceDatas_trace_array(::cloud_service::msg::TraceDatas & msg)
  : msg_(msg)
  {}
  ::cloud_service::msg::TraceDatas trace_array(::cloud_service::msg::TraceDatas::_trace_array_type arg)
  {
    msg_.trace_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cloud_service::msg::TraceDatas msg_;
};

class Init_TraceDatas_event_name
{
public:
  explicit Init_TraceDatas_event_name(::cloud_service::msg::TraceDatas & msg)
  : msg_(msg)
  {}
  Init_TraceDatas_trace_array event_name(::cloud_service::msg::TraceDatas::_event_name_type arg)
  {
    msg_.event_name = std::move(arg);
    return Init_TraceDatas_trace_array(msg_);
  }

private:
  ::cloud_service::msg::TraceDatas msg_;
};

class Init_TraceDatas_model
{
public:
  Init_TraceDatas_model()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TraceDatas_event_name model(::cloud_service::msg::TraceDatas::_model_type arg)
  {
    msg_.model = std::move(arg);
    return Init_TraceDatas_event_name(msg_);
  }

private:
  ::cloud_service::msg::TraceDatas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cloud_service::msg::TraceDatas>()
{
  return cloud_service::msg::builder::Init_TraceDatas_model();
}

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__TRACE_DATAS__BUILDER_HPP_
