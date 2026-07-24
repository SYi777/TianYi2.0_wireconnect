// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cloud_service:msg/TraceDatas.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cloud_service/msg/detail/trace_datas__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cloud_service
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TraceDatas_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cloud_service::msg::TraceDatas(_init);
}

void TraceDatas_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cloud_service::msg::TraceDatas *>(message_memory);
  typed_message->~TraceDatas();
}

size_t size_function__TraceDatas__trace_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<cloud_service::msg::TraceData> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TraceDatas__trace_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<cloud_service::msg::TraceData> *>(untyped_member);
  return &member[index];
}

void * get_function__TraceDatas__trace_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<cloud_service::msg::TraceData> *>(untyped_member);
  return &member[index];
}

void fetch_function__TraceDatas__trace_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const cloud_service::msg::TraceData *>(
    get_const_function__TraceDatas__trace_array(untyped_member, index));
  auto & value = *reinterpret_cast<cloud_service::msg::TraceData *>(untyped_value);
  value = item;
}

void assign_function__TraceDatas__trace_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<cloud_service::msg::TraceData *>(
    get_function__TraceDatas__trace_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const cloud_service::msg::TraceData *>(untyped_value);
  item = value;
}

void resize_function__TraceDatas__trace_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<cloud_service::msg::TraceData> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TraceDatas_message_member_array[3] = {
  {
    "model",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service::msg::TraceDatas, model),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "event_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service::msg::TraceDatas, event_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "trace_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<cloud_service::msg::TraceData>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service::msg::TraceDatas, trace_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__TraceDatas__trace_array,  // size() function pointer
    get_const_function__TraceDatas__trace_array,  // get_const(index) function pointer
    get_function__TraceDatas__trace_array,  // get(index) function pointer
    fetch_function__TraceDatas__trace_array,  // fetch(index, &value) function pointer
    assign_function__TraceDatas__trace_array,  // assign(index, value) function pointer
    resize_function__TraceDatas__trace_array  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TraceDatas_message_members = {
  "cloud_service::msg",  // message namespace
  "TraceDatas",  // message name
  3,  // number of fields
  sizeof(cloud_service::msg::TraceDatas),
  TraceDatas_message_member_array,  // message members
  TraceDatas_init_function,  // function to initialize message memory (memory has to be allocated)
  TraceDatas_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TraceDatas_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TraceDatas_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cloud_service


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cloud_service::msg::TraceDatas>()
{
  return &::cloud_service::msg::rosidl_typesupport_introspection_cpp::TraceDatas_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cloud_service, msg, TraceDatas)() {
  return &::cloud_service::msg::rosidl_typesupport_introspection_cpp::TraceDatas_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
