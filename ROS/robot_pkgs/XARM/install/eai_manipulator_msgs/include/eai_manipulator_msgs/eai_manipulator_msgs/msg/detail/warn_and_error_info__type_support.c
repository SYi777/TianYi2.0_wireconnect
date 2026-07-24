// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from eai_manipulator_msgs:msg/WarnAndErrorInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__rosidl_typesupport_introspection_c.h"
#include "eai_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__functions.h"
#include "eai_manipulator_msgs/msg/detail/warn_and_error_info__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `level`
// Member `source`
// Member `info`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  eai_manipulator_msgs__msg__WarnAndErrorInfo__init(message_memory);
}

void eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_fini_function(void * message_memory)
{
  eai_manipulator_msgs__msg__WarnAndErrorInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__msg__WarnAndErrorInfo, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__msg__WarnAndErrorInfo, level),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__msg__WarnAndErrorInfo, code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__msg__WarnAndErrorInfo, source),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__msg__WarnAndErrorInfo, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_members = {
  "eai_manipulator_msgs__msg",  // message namespace
  "WarnAndErrorInfo",  // message name
  5,  // number of fields
  sizeof(eai_manipulator_msgs__msg__WarnAndErrorInfo),
  eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_member_array,  // message members
  eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_type_support_handle = {
  0,
  &eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_eai_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, msg, WarnAndErrorInfo)() {
  eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_type_support_handle.typesupport_identifier) {
    eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &eai_manipulator_msgs__msg__WarnAndErrorInfo__rosidl_typesupport_introspection_c__WarnAndErrorInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
