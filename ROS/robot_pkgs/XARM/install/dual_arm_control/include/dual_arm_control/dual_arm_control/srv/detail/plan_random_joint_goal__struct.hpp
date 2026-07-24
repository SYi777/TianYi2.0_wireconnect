// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dual_arm_control:srv/PlanRandomJointGoal.idl
// generated code does not contain a copyright notice

#ifndef DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_HPP_
#define DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Request __declspec(deprecated)
#endif

namespace dual_arm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlanRandomJointGoal_Request_
{
  using Type = PlanRandomJointGoal_Request_<ContainerAllocator>;

  explicit PlanRandomJointGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
    }
  }

  explicit PlanRandomJointGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : group_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
    }
  }

  // field types and members
  using _group_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _group_name_type group_name;

  // setters for named parameter idiom
  Type & set__group_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->group_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Request
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Request
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRandomJointGoal_Request_ & other) const
  {
    if (this->group_name != other.group_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRandomJointGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRandomJointGoal_Request_

// alias to use template instance with default allocator
using PlanRandomJointGoal_Request =
  dual_arm_control::srv::PlanRandomJointGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dual_arm_control


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Response __declspec(deprecated)
#endif

namespace dual_arm_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlanRandomJointGoal_Response_
{
  using Type = PlanRandomJointGoal_Response_<ContainerAllocator>;

  explicit PlanRandomJointGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit PlanRandomJointGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _joint_values_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_values_type joint_values;
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__joint_values(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_values = _arg;
    return *this;
  }
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Response
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dual_arm_control__srv__PlanRandomJointGoal_Response
    std::shared_ptr<dual_arm_control::srv::PlanRandomJointGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRandomJointGoal_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->joint_values != other.joint_values) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRandomJointGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRandomJointGoal_Response_

// alias to use template instance with default allocator
using PlanRandomJointGoal_Response =
  dual_arm_control::srv::PlanRandomJointGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dual_arm_control

namespace dual_arm_control
{

namespace srv
{

struct PlanRandomJointGoal
{
  using Request = dual_arm_control::srv::PlanRandomJointGoal_Request;
  using Response = dual_arm_control::srv::PlanRandomJointGoal_Response;
};

}  // namespace srv

}  // namespace dual_arm_control

#endif  // DUAL_ARM_CONTROL__SRV__DETAIL__PLAN_RANDOM_JOINT_GOAL__STRUCT_HPP_
