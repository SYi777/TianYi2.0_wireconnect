// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cloud_service:srv/RemoteCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cloud_service/srv/detail/remote_ctrl__rosidl_typesupport_introspection_c.h"
#include "cloud_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cloud_service/srv/detail/remote_ctrl__functions.h"
#include "cloud_service/srv/detail/remote_ctrl__struct.h"


// Include directives for member types
// Member `payload`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cloud_service__srv__RemoteCtrl_Request__init(message_memory);
}

void cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_fini_function(void * message_memory)
{
  cloud_service__srv__RemoteCtrl_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_member_array[3] = {
  {
    "msg_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__srv__RemoteCtrl_Request, msg_id),  // bytes offset in struct
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
    offsetof(cloud_service__srv__RemoteCtrl_Request, cmd_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "payload",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__srv__RemoteCtrl_Request, payload),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_members = {
  "cloud_service__srv",  // message namespace
  "RemoteCtrl_Request",  // message name
  3,  // number of fields
  sizeof(cloud_service__srv__RemoteCtrl_Request),
  cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_member_array,  // message members
  cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_type_support_handle = {
  0,
  &cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cloud_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Request)() {
  if (!cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_type_support_handle.typesupport_identifier) {
    cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cloud_service__srv__RemoteCtrl_Request__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cloud_service/srv/detail/remote_ctrl__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cloud_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cloud_service/srv/detail/remote_ctrl__functions.h"
// already included above
// #include "cloud_service/srv/detail/remote_ctrl__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cloud_service__srv__RemoteCtrl_Response__init(message_memory);
}

void cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_fini_function(void * message_memory)
{
  cloud_service__srv__RemoteCtrl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_member_array[2] = {
  {
    "code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cloud_service__srv__RemoteCtrl_Response, code),  // bytes offset in struct
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
    offsetof(cloud_service__srv__RemoteCtrl_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_members = {
  "cloud_service__srv",  // message namespace
  "RemoteCtrl_Response",  // message name
  2,  // number of fields
  sizeof(cloud_service__srv__RemoteCtrl_Response),
  cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_member_array,  // message members
  cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_type_support_handle = {
  0,
  &cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cloud_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Response)() {
  if (!cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_type_support_handle.typesupport_identifier) {
    cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cloud_service__srv__RemoteCtrl_Response__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cloud_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cloud_service/srv/detail/remote_ctrl__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_members = {
  "cloud_service__srv",  // service namespace
  "RemoteCtrl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_Request_message_type_support_handle,
  NULL  // response message
  // cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_Response_message_type_support_handle
};

static rosidl_service_type_support_t cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_type_support_handle = {
  0,
  &cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cloud_service
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl)() {
  if (!cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_type_support_handle.typesupport_identifier) {
    cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cloud_service, srv, RemoteCtrl_Response)()->data;
  }

  return &cloud_service__srv__detail__remote_ctrl__rosidl_typesupport_introspection_c__RemoteCtrl_service_type_support_handle;
}
