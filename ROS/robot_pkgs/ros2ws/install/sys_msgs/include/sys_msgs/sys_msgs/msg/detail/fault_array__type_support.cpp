// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sys_msgs/msg/detail/fault_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace sys_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FaultArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) sys_msgs::msg::FaultArray(_init);
}

void FaultArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sys_msgs::msg::FaultArray *>(message_memory);
  typed_message->~FaultArray();
}

size_t size_function__FaultArray__fault_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sys_msgs::msg::Fault> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FaultArray__fault_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sys_msgs::msg::Fault> *>(untyped_member);
  return &member[index];
}

void * get_function__FaultArray__fault_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sys_msgs::msg::Fault> *>(untyped_member);
  return &member[index];
}

void fetch_function__FaultArray__fault_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sys_msgs::msg::Fault *>(
    get_const_function__FaultArray__fault_array(untyped_member, index));
  auto & value = *reinterpret_cast<sys_msgs::msg::Fault *>(untyped_value);
  value = item;
}

void assign_function__FaultArray__fault_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sys_msgs::msg::Fault *>(
    get_function__FaultArray__fault_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const sys_msgs::msg::Fault *>(untyped_value);
  item = value;
}

void resize_function__FaultArray__fault_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sys_msgs::msg::Fault> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FaultArray_message_member_array[1] = {
  {
    "fault_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sys_msgs::msg::Fault>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs::msg::FaultArray, fault_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__FaultArray__fault_array,  // size() function pointer
    get_const_function__FaultArray__fault_array,  // get_const(index) function pointer
    get_function__FaultArray__fault_array,  // get(index) function pointer
    fetch_function__FaultArray__fault_array,  // fetch(index, &value) function pointer
    assign_function__FaultArray__fault_array,  // assign(index, value) function pointer
    resize_function__FaultArray__fault_array  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FaultArray_message_members = {
  "sys_msgs::msg",  // message namespace
  "FaultArray",  // message name
  1,  // number of fields
  sizeof(sys_msgs::msg::FaultArray),
  FaultArray_message_member_array,  // message members
  FaultArray_init_function,  // function to initialize message memory (memory has to be allocated)
  FaultArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FaultArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FaultArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace sys_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sys_msgs::msg::FaultArray>()
{
  return &::sys_msgs::msg::rosidl_typesupport_introspection_cpp::FaultArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sys_msgs, msg, FaultArray)() {
  return &::sys_msgs::msg::rosidl_typesupport_introspection_cpp::FaultArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
