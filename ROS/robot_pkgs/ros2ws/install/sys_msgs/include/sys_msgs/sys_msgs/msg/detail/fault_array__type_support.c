// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sys_msgs/msg/detail/fault_array__rosidl_typesupport_introspection_c.h"
#include "sys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sys_msgs/msg/detail/fault_array__functions.h"
#include "sys_msgs/msg/detail/fault_array__struct.h"


// Include directives for member types
// Member `fault_array`
#include "sys_msgs/msg/fault.h"
// Member `fault_array`
#include "sys_msgs/msg/detail/fault__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sys_msgs__msg__FaultArray__init(message_memory);
}

void sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_fini_function(void * message_memory)
{
  sys_msgs__msg__FaultArray__fini(message_memory);
}

size_t sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__size_function__FaultArray__fault_array(
  const void * untyped_member)
{
  const sys_msgs__msg__Fault__Sequence * member =
    (const sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return member->size;
}

const void * sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_const_function__FaultArray__fault_array(
  const void * untyped_member, size_t index)
{
  const sys_msgs__msg__Fault__Sequence * member =
    (const sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_function__FaultArray__fault_array(
  void * untyped_member, size_t index)
{
  sys_msgs__msg__Fault__Sequence * member =
    (sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return &member->data[index];
}

void sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__fetch_function__FaultArray__fault_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sys_msgs__msg__Fault * item =
    ((const sys_msgs__msg__Fault *)
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_const_function__FaultArray__fault_array(untyped_member, index));
  sys_msgs__msg__Fault * value =
    (sys_msgs__msg__Fault *)(untyped_value);
  *value = *item;
}

void sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__assign_function__FaultArray__fault_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sys_msgs__msg__Fault * item =
    ((sys_msgs__msg__Fault *)
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_function__FaultArray__fault_array(untyped_member, index));
  const sys_msgs__msg__Fault * value =
    (const sys_msgs__msg__Fault *)(untyped_value);
  *item = *value;
}

bool sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__resize_function__FaultArray__fault_array(
  void * untyped_member, size_t size)
{
  sys_msgs__msg__Fault__Sequence * member =
    (sys_msgs__msg__Fault__Sequence *)(untyped_member);
  sys_msgs__msg__Fault__Sequence__fini(member);
  return sys_msgs__msg__Fault__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_member_array[1] = {
  {
    "fault_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__msg__FaultArray, fault_array),  // bytes offset in struct
    NULL,  // default value
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__size_function__FaultArray__fault_array,  // size() function pointer
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_const_function__FaultArray__fault_array,  // get_const(index) function pointer
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__get_function__FaultArray__fault_array,  // get(index) function pointer
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__fetch_function__FaultArray__fault_array,  // fetch(index, &value) function pointer
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__assign_function__FaultArray__fault_array,  // assign(index, value) function pointer
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__resize_function__FaultArray__fault_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_members = {
  "sys_msgs__msg",  // message namespace
  "FaultArray",  // message name
  1,  // number of fields
  sizeof(sys_msgs__msg__FaultArray),
  sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_member_array,  // message members
  sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_init_function,  // function to initialize message memory (memory has to be allocated)
  sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_type_support_handle = {
  0,
  &sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sys_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, msg, FaultArray)() {
  sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, msg, Fault)();
  if (!sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_type_support_handle.typesupport_identifier) {
    sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sys_msgs__msg__FaultArray__rosidl_typesupport_introspection_c__FaultArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
