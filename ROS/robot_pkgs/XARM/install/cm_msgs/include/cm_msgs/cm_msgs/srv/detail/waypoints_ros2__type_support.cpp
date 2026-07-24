// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cm_msgs:srv/WaypointsRos2.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cm_msgs/srv/detail/waypoints_ros2__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cm_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void WaypointsRos2_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cm_msgs::srv::WaypointsRos2_Request(_init);
}

void WaypointsRos2_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cm_msgs::srv::WaypointsRos2_Request *>(message_memory);
  typed_message->~WaypointsRos2_Request();
}

size_t size_function__WaypointsRos2_Request__left_waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WaypointsRos2_Request__left_waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return &member[index];
}

void * get_function__WaypointsRos2_Request__left_waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return &member[index];
}

void fetch_function__WaypointsRos2_Request__left_waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::PoseStamped *>(
    get_const_function__WaypointsRos2_Request__left_waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::PoseStamped *>(untyped_value);
  value = item;
}

void assign_function__WaypointsRos2_Request__left_waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::PoseStamped *>(
    get_function__WaypointsRos2_Request__left_waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::PoseStamped *>(untyped_value);
  item = value;
}

void resize_function__WaypointsRos2_Request__left_waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  member->resize(size);
}

size_t size_function__WaypointsRos2_Request__right_waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WaypointsRos2_Request__right_waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return &member[index];
}

void * get_function__WaypointsRos2_Request__right_waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  return &member[index];
}

void fetch_function__WaypointsRos2_Request__right_waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::PoseStamped *>(
    get_const_function__WaypointsRos2_Request__right_waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::PoseStamped *>(untyped_value);
  value = item;
}

void assign_function__WaypointsRos2_Request__right_waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::PoseStamped *>(
    get_function__WaypointsRos2_Request__right_waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::PoseStamped *>(untyped_value);
  item = value;
}

void resize_function__WaypointsRos2_Request__right_waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::PoseStamped> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WaypointsRos2_Request_message_member_array[2] = {
  {
    "left_waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseStamped>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs::srv::WaypointsRos2_Request, left_waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__WaypointsRos2_Request__left_waypoints,  // size() function pointer
    get_const_function__WaypointsRos2_Request__left_waypoints,  // get_const(index) function pointer
    get_function__WaypointsRos2_Request__left_waypoints,  // get(index) function pointer
    fetch_function__WaypointsRos2_Request__left_waypoints,  // fetch(index, &value) function pointer
    assign_function__WaypointsRos2_Request__left_waypoints,  // assign(index, value) function pointer
    resize_function__WaypointsRos2_Request__left_waypoints  // resize(index) function pointer
  },
  {
    "right_waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseStamped>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs::srv::WaypointsRos2_Request, right_waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__WaypointsRos2_Request__right_waypoints,  // size() function pointer
    get_const_function__WaypointsRos2_Request__right_waypoints,  // get_const(index) function pointer
    get_function__WaypointsRos2_Request__right_waypoints,  // get(index) function pointer
    fetch_function__WaypointsRos2_Request__right_waypoints,  // fetch(index, &value) function pointer
    assign_function__WaypointsRos2_Request__right_waypoints,  // assign(index, value) function pointer
    resize_function__WaypointsRos2_Request__right_waypoints  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WaypointsRos2_Request_message_members = {
  "cm_msgs::srv",  // message namespace
  "WaypointsRos2_Request",  // message name
  2,  // number of fields
  sizeof(cm_msgs::srv::WaypointsRos2_Request),
  WaypointsRos2_Request_message_member_array,  // message members
  WaypointsRos2_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  WaypointsRos2_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WaypointsRos2_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WaypointsRos2_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cm_msgs::srv::WaypointsRos2_Request>()
{
  return &::cm_msgs::srv::rosidl_typesupport_introspection_cpp::WaypointsRos2_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cm_msgs, srv, WaypointsRos2_Request)() {
  return &::cm_msgs::srv::rosidl_typesupport_introspection_cpp::WaypointsRos2_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cm_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void WaypointsRos2_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cm_msgs::srv::WaypointsRos2_Response(_init);
}

void WaypointsRos2_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cm_msgs::srv::WaypointsRos2_Response *>(message_memory);
  typed_message->~WaypointsRos2_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WaypointsRos2_Response_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs::srv::WaypointsRos2_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs::srv::WaypointsRos2_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WaypointsRos2_Response_message_members = {
  "cm_msgs::srv",  // message namespace
  "WaypointsRos2_Response",  // message name
  2,  // number of fields
  sizeof(cm_msgs::srv::WaypointsRos2_Response),
  WaypointsRos2_Response_message_member_array,  // message members
  WaypointsRos2_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  WaypointsRos2_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WaypointsRos2_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WaypointsRos2_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cm_msgs::srv::WaypointsRos2_Response>()
{
  return &::cm_msgs::srv::rosidl_typesupport_introspection_cpp::WaypointsRos2_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cm_msgs, srv, WaypointsRos2_Response)() {
  return &::cm_msgs::srv::rosidl_typesupport_introspection_cpp::WaypointsRos2_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "cm_msgs/srv/detail/waypoints_ros2__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace cm_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers WaypointsRos2_service_members = {
  "cm_msgs::srv",  // service namespace
  "WaypointsRos2",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<cm_msgs::srv::WaypointsRos2>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t WaypointsRos2_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WaypointsRos2_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<cm_msgs::srv::WaypointsRos2>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::cm_msgs::srv::rosidl_typesupport_introspection_cpp::WaypointsRos2_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::cm_msgs::srv::WaypointsRos2_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::cm_msgs::srv::WaypointsRos2_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cm_msgs, srv, WaypointsRos2)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<cm_msgs::srv::WaypointsRos2>();
}

#ifdef __cplusplus
}
#endif
