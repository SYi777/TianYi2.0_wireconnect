// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sys_msgs/msg/detail/fault__rosidl_typesupport_introspection_c.h"
#include "sys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sys_msgs/msg/detail/fault__functions.h"
#include "sys_msgs/msg/detail/fault__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sys_msgs__msg__Fault__init(message_memory);
}

void sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_fini_function(void * message_memory)
{
  sys_msgs__msg__Fault__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_member_array[3] = {
  {
    "time_stamp_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__msg__Fault, time_stamp_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__msg__Fault, code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__msg__Fault, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_members = {
  "sys_msgs__msg",  // message namespace
  "Fault",  // message name
  3,  // number of fields
  sizeof(sys_msgs__msg__Fault),
  sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_member_array,  // message members
  sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_init_function,  // function to initialize message memory (memory has to be allocated)
  sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_type_support_handle = {
  0,
  &sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sys_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, msg, Fault)() {
  if (!sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_type_support_handle.typesupport_identifier) {
    sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sys_msgs__msg__Fault__rosidl_typesupport_introspection_c__Fault_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
