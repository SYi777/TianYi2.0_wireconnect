// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from eai_manipulator_msgs:srv/Mode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "eai_manipulator_msgs/srv/detail/mode__rosidl_typesupport_introspection_c.h"
#include "eai_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "eai_manipulator_msgs/srv/detail/mode__functions.h"
#include "eai_manipulator_msgs/srv/detail/mode__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  eai_manipulator_msgs__srv__Mode_Request__init(message_memory);
}

void eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_fini_function(void * message_memory)
{
  eai_manipulator_msgs__srv__Mode_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_member_array[1] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__srv__Mode_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_members = {
  "eai_manipulator_msgs__srv",  // message namespace
  "Mode_Request",  // message name
  1,  // number of fields
  sizeof(eai_manipulator_msgs__srv__Mode_Request),
  eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_member_array,  // message members
  eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_type_support_handle = {
  0,
  &eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_eai_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Request)() {
  if (!eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_type_support_handle.typesupport_identifier) {
    eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &eai_manipulator_msgs__srv__Mode_Request__rosidl_typesupport_introspection_c__Mode_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "eai_manipulator_msgs/srv/detail/mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "eai_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "eai_manipulator_msgs/srv/detail/mode__functions.h"
// already included above
// #include "eai_manipulator_msgs/srv/detail/mode__struct.h"


// Include directives for member types
// Member `info`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  eai_manipulator_msgs__srv__Mode_Response__init(message_memory);
}

void eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_fini_function(void * message_memory)
{
  eai_manipulator_msgs__srv__Mode_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_member_array[2] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eai_manipulator_msgs__srv__Mode_Response, result),  // bytes offset in struct
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
    offsetof(eai_manipulator_msgs__srv__Mode_Response, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_members = {
  "eai_manipulator_msgs__srv",  // message namespace
  "Mode_Response",  // message name
  2,  // number of fields
  sizeof(eai_manipulator_msgs__srv__Mode_Response),
  eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_member_array,  // message members
  eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_type_support_handle = {
  0,
  &eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_eai_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Response)() {
  if (!eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_type_support_handle.typesupport_identifier) {
    eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &eai_manipulator_msgs__srv__Mode_Response__rosidl_typesupport_introspection_c__Mode_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "eai_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "eai_manipulator_msgs/srv/detail/mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_members = {
  "eai_manipulator_msgs__srv",  // service namespace
  "Mode",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_Request_message_type_support_handle,
  NULL  // response message
  // eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_Response_message_type_support_handle
};

static rosidl_service_type_support_t eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_type_support_handle = {
  0,
  &eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_eai_manipulator_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode)() {
  if (!eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_type_support_handle.typesupport_identifier) {
    eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eai_manipulator_msgs, srv, Mode_Response)()->data;
  }

  return &eai_manipulator_msgs__srv__detail__mode__rosidl_typesupport_introspection_c__Mode_service_type_support_handle;
}
