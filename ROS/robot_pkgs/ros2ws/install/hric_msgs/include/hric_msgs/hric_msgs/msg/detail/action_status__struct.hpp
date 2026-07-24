// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/ActionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__ActionStatus __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__ActionStatus __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActionStatus_
{
  using Type = ActionStatus_<ContainerAllocator>;

  explicit ActionStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motion_number = 0ul;
      this->is_motion = false;
    }
  }

  explicit ActionStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motion_number = 0ul;
      this->is_motion = false;
    }
  }

  // field types and members
  using _motion_number_type =
    uint32_t;
  _motion_number_type motion_number;
  using _is_motion_type =
    bool;
  _is_motion_type is_motion;

  // setters for named parameter idiom
  Type & set__motion_number(
    const uint32_t & _arg)
  {
    this->motion_number = _arg;
    return *this;
  }
  Type & set__is_motion(
    const bool & _arg)
  {
    this->is_motion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::msg::ActionStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::ActionStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::ActionStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::ActionStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__ActionStatus
    std::shared_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__ActionStatus
    std::shared_ptr<hric_msgs::msg::ActionStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActionStatus_ & other) const
  {
    if (this->motion_number != other.motion_number) {
      return false;
    }
    if (this->is_motion != other.is_motion) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActionStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActionStatus_

// alias to use template instance with default allocator
using ActionStatus =
  hric_msgs::msg::ActionStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__ACTION_STATUS__STRUCT_HPP_
