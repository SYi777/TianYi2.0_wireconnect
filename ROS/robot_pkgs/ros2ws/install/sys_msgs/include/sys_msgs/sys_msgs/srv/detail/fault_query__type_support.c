// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sys_msgs:srv/FaultQuery.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sys_msgs/srv/detail/fault_query__rosidl_typesupport_introspection_c.h"
#include "sys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sys_msgs/srv/detail/fault_query__functions.h"
#include "sys_msgs/srv/detail/fault_query__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sys_msgs__srv__FaultQuery_Request__init(message_memory);
}

void sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_fini_function(void * message_memory)
{
  sys_msgs__srv__FaultQuery_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__srv__FaultQuery_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_members = {
  "sys_msgs__srv",  // message namespace
  "FaultQuery_Request",  // message name
  1,  // number of fields
  sizeof(sys_msgs__srv__FaultQuery_Request),
  sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_member_array,  // message members
  sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_type_support_handle = {
  0,
  &sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sys_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Request)() {
  if (!sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_type_support_handle.typesupport_identifier) {
    sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sys_msgs__srv__FaultQuery_Request__rosidl_typesupport_introspection_c__FaultQuery_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sys_msgs/srv/detail/fault_query__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sys_msgs/srv/detail/fault_query__functions.h"
// already included above
// #include "sys_msgs/srv/detail/fault_query__struct.h"


// Include directives for member types
// Member `fault_array`
#include "sys_msgs/msg/fault.h"
// Member `fault_array`
#include "sys_msgs/msg/detail/fault__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sys_msgs__srv__FaultQuery_Response__init(message_memory);
}

void sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_fini_function(void * message_memory)
{
  sys_msgs__srv__FaultQuery_Response__fini(message_memory);
}

size_t sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__size_function__FaultQuery_Response__fault_array(
  const void * untyped_member)
{
  const sys_msgs__msg__Fault__Sequence * member =
    (const sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return member->size;
}

const void * sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_const_function__FaultQuery_Response__fault_array(
  const void * untyped_member, size_t index)
{
  const sys_msgs__msg__Fault__Sequence * member =
    (const sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_function__FaultQuery_Response__fault_array(
  void * untyped_member, size_t index)
{
  sys_msgs__msg__Fault__Sequence * member =
    (sys_msgs__msg__Fault__Sequence *)(untyped_member);
  return &member->data[index];
}

void sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__fetch_function__FaultQuery_Response__fault_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sys_msgs__msg__Fault * item =
    ((const sys_msgs__msg__Fault *)
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_const_function__FaultQuery_Response__fault_array(untyped_member, index));
  sys_msgs__msg__Fault * value =
    (sys_msgs__msg__Fault *)(untyped_value);
  *value = *item;
}

void sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__assign_function__FaultQuery_Response__fault_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sys_msgs__msg__Fault * item =
    ((sys_msgs__msg__Fault *)
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_function__FaultQuery_Response__fault_array(untyped_member, index));
  const sys_msgs__msg__Fault * value =
    (const sys_msgs__msg__Fault *)(untyped_value);
  *item = *value;
}

bool sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__resize_function__FaultQuery_Response__fault_array(
  void * untyped_member, size_t size)
{
  sys_msgs__msg__Fault__Sequence * member =
    (sys_msgs__msg__Fault__Sequence *)(untyped_member);
  sys_msgs__msg__Fault__Sequence__fini(member);
  return sys_msgs__msg__Fault__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_member_array[1] = {
  {
    "fault_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sys_msgs__srv__FaultQuery_Response, fault_array),  // bytes offset in struct
    NULL,  // default value
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__size_function__FaultQuery_Response__fault_array,  // size() function pointer
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_const_function__FaultQuery_Response__fault_array,  // get_const(index) function pointer
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__get_function__FaultQuery_Response__fault_array,  // get(index) function pointer
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__fetch_function__FaultQuery_Response__fault_array,  // fetch(index, &value) function pointer
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__assign_function__FaultQuery_Response__fault_array,  // assign(index, value) function pointer
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__resize_function__FaultQuery_Response__fault_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_members = {
  "sys_msgs__srv",  // message namespace
  "FaultQuery_Response",  // message name
  1,  // number of fields
  sizeof(sys_msgs__srv__FaultQuery_Response),
  sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_member_array,  // message members
  sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_type_support_handle = {
  0,
  &sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sys_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Response)() {
  sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, msg, Fault)();
  if (!sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_type_support_handle.typesupport_identifier) {
    sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sys_msgs__srv__FaultQuery_Response__rosidl_typesupport_introspection_c__FaultQuery_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sys_msgs/srv/detail/fault_query__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_members = {
  "sys_msgs__srv",  // service namespace
  "FaultQuery",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_Request_message_type_support_handle,
  NULL  // response message
  // sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_Response_message_type_support_handle
};

static rosidl_service_type_support_t sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_type_support_handle = {
  0,
  &sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sys_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery)() {
  if (!sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_type_support_handle.typesupport_identifier) {
    sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sys_msgs, srv, FaultQuery_Response)()->data;
  }

  return &sys_msgs__srv__detail__fault_query__rosidl_typesupport_introspection_c__FaultQuery_service_type_support_handle;
}
