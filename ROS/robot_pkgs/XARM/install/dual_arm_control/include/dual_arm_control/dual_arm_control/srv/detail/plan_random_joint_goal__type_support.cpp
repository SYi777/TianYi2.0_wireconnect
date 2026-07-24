// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dual_arm_control
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PlanRandomJointGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dual_arm_control::srv::PlanRandomJointGoal_Request(_init);
}

void PlanRandomJointGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dual_arm_control::srv::PlanRandomJointGoal_Request *>(message_memory);
  typed_message->~PlanRandomJointGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlanRandomJointGoal_Request_message_member_array[1] = {
  {
    "group_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control::srv::PlanRandomJointGoal_Request, group_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlanRandomJointGoal_Request_message_members = {
  "dual_arm_control::srv",  // message namespace
  "PlanRandomJointGoal_Request",  // message name
  1,  // number of fields
  sizeof(dual_arm_control::srv::PlanRandomJointGoal_Request),
  PlanRandomJointGoal_Request_message_member_array,  // message members
  PlanRandomJointGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PlanRandomJointGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlanRandomJointGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlanRandomJointGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace dual_arm_control


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dual_arm_control::srv::PlanRandomJointGoal_Request>()
{
  return &::dual_arm_control::srv::rosidl_typesupport_introspection_cpp::PlanRandomJointGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dual_arm_control, srv, PlanRandomJointGoal_Request)() {
  return &::dual_arm_control::srv::rosidl_typesupport_introspection_cpp::PlanRandomJointGoal_Request_message_type_support_handle;
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
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.hpp"
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

namespace dual_arm_control
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PlanRandomJointGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dual_arm_control::srv::PlanRandomJointGoal_Response(_init);
}

void PlanRandomJointGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dual_arm_control::srv::PlanRandomJointGoal_Response *>(message_memory);
  typed_message->~PlanRandomJointGoal_Response();
}

size_t size_function__PlanRandomJointGoal_Response__joint_values(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PlanRandomJointGoal_Response__joint_values(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__PlanRandomJointGoal_Response__joint_values(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__PlanRandomJointGoal_Response__joint_values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__PlanRandomJointGoal_Response__joint_values(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__PlanRandomJointGoal_Response__joint_values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__PlanRandomJointGoal_Response__joint_values(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__PlanRandomJointGoal_Response__joint_values(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlanRandomJointGoal_Response_message_member_array[4] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control::srv::PlanRandomJointGoal_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_values",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control::srv::PlanRandomJointGoal_Response, joint_values),  // bytes offset in struct
    nullptr,  // default value
    size_function__PlanRandomJointGoal_Response__joint_values,  // size() function pointer
    get_const_function__PlanRandomJointGoal_Response__joint_values,  // get_const(index) function pointer
    get_function__PlanRandomJointGoal_Response__joint_values,  // get(index) function pointer
    fetch_function__PlanRandomJointGoal_Response__joint_values,  // fetch(index, &value) function pointer
    assign_function__PlanRandomJointGoal_Response__joint_values,  // assign(index, value) function pointer
    resize_function__PlanRandomJointGoal_Response__joint_values  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<trajectory_msgs::msg::JointTrajectory>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dual_arm_control::srv::PlanRandomJointGoal_Response, trajectory),  // bytes offset in struct
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
    offsetof(dual_arm_control::srv::PlanRandomJointGoal_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlanRandomJointGoal_Response_message_members = {
  "dual_arm_control::srv",  // message namespace
  "PlanRandomJointGoal_Response",  // message name
  4,  // number of fields
  sizeof(dual_arm_control::srv::PlanRandomJointGoal_Response),
  PlanRandomJointGoal_Response_message_member_array,  // message members
  PlanRandomJointGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PlanRandomJointGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlanRandomJointGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlanRandomJointGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace dual_arm_control


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dual_arm_control::srv::PlanRandomJointGoal_Response>()
{
  return &::dual_arm_control::srv::rosidl_typesupport_introspection_cpp::PlanRandomJointGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dual_arm_control, srv, PlanRandomJointGoal_Response)() {
  return &::dual_arm_control::srv::rosidl_typesupport_introspection_cpp::PlanRandomJointGoal_Response_message_type_support_handle;
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
// #include "dual_arm_control/srv/detail/plan_random_joint_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace dual_arm_control
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers PlanRandomJointGoal_service_members = {
  "dual_arm_control::srv",  // service namespace
  "PlanRandomJointGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<dual_arm_control::srv::PlanRandomJointGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t PlanRandomJointGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlanRandomJointGoal_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace dual_arm_control


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<dual_arm_control::srv::PlanRandomJointGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::dual_arm_control::srv::rosidl_typesupport_introspection_cpp::PlanRandomJointGoal_service_type_support_handle;
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
        ::dual_arm_control::srv::PlanRandomJointGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::dual_arm_control::srv::PlanRandomJointGoal_Response
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dual_arm_control, srv, PlanRandomJointGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<dual_arm_control::srv::PlanRandomJointGoal>();
}

#ifdef __cplusplus
}
#endif
