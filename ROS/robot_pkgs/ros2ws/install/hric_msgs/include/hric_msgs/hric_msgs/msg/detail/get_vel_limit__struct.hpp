// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/GetVelLimit.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__GetVelLimit __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__GetVelLimit __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetVelLimit_
{
  using Type = GetVelLimit_<ContainerAllocator>;

  explicit GetVelLimit_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_vel_limit_walk = 0.0;
      this->x_vel_limit_run = 0.0;
      this->x_vel_limit_halfwalk = 0.0;
    }
  }

  explicit GetVelLimit_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_vel_limit_walk = 0.0;
      this->x_vel_limit_run = 0.0;
      this->x_vel_limit_halfwalk = 0.0;
    }
  }

  // field types and members
  using _x_vel_limit_walk_type =
    double;
  _x_vel_limit_walk_type x_vel_limit_walk;
  using _x_vel_limit_run_type =
    double;
  _x_vel_limit_run_type x_vel_limit_run;
  using _x_vel_limit_halfwalk_type =
    double;
  _x_vel_limit_halfwalk_type x_vel_limit_halfwalk;

  // setters for named parameter idiom
  Type & set__x_vel_limit_walk(
    const double & _arg)
  {
    this->x_vel_limit_walk = _arg;
    return *this;
  }
  Type & set__x_vel_limit_run(
    const double & _arg)
  {
    this->x_vel_limit_run = _arg;
    return *this;
  }
  Type & set__x_vel_limit_halfwalk(
    const double & _arg)
  {
    this->x_vel_limit_halfwalk = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::msg::GetVelLimit_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::GetVelLimit_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::GetVelLimit_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::GetVelLimit_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__GetVelLimit
    std::shared_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__GetVelLimit
    std::shared_ptr<hric_msgs::msg::GetVelLimit_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetVelLimit_ & other) const
  {
    if (this->x_vel_limit_walk != other.x_vel_limit_walk) {
      return false;
    }
    if (this->x_vel_limit_run != other.x_vel_limit_run) {
      return false;
    }
    if (this->x_vel_limit_halfwalk != other.x_vel_limit_halfwalk) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetVelLimit_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetVelLimit_

// alias to use template instance with default allocator
using GetVelLimit =
  hric_msgs::msg::GetVelLimit_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__GET_VEL_LIMIT__STRUCT_HPP_
