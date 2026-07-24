// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cloud_service/msg/detail/command_ack__rosidl_typesupport_introspection_c.h"
#include "cloud_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cloud_service/msg/detail/command_ack__functions.h"
#include "cloud_service/msg/detail/command_ack__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cloud_service__msg__CommandAck__init(message_memory);
}

void cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_fini_function(void * message_memory)
{
  cloud_service__msg__CommandAck__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_member_array[4] = {
  {
    "msg_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__CommandAck, msg_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__CommandAck, cmd_id),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__CommandAck, code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__msg__CommandAck, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_members = {
  "cloud_service__msg",  // message namespace
  "CommandAck",  // message name
  4,  // number of fields
  sizeof(cloud_service__msg__CommandAck),
  cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_member_array,  // message members
  cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_init_function,  // function to initialize message memory (memory has to be allocated)
  cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_type_support_handle = {
  0,
  &cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cloud_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, msg, CommandAck)() {
  if (!cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_type_support_handle.typesupport_identifier) {
    cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cloud_service__msg__CommandAck__rosidl_typesupport_introspection_c__CommandAck_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
