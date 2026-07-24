// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sys_msgs:msg/Fault.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_HPP_
#define SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sys_msgs__msg__Fault __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__msg__Fault __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Fault_
{
  using Type = Fault_<ContainerAllocator>;

  explicit Fault_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_stamp_ms = 0ull;
      this->code = 0ull;
      this->status = 0;
    }
  }

  explicit Fault_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_stamp_ms = 0ull;
      this->code = 0ull;
      this->status = 0;
    }
  }

  // field types and members
  using _time_stamp_ms_type =
    uint64_t;
  _time_stamp_ms_type time_stamp_ms;
  using _code_type =
    uint64_t;
  _code_type code;
  using _status_type =
    uint16_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__time_stamp_ms(
    const uint64_t & _arg)
  {
    this->time_stamp_ms = _arg;
    return *this;
  }
  Type & set__code(
    const uint64_t & _arg)
  {
    this->code = _arg;
    return *this;
  }
  Type & set__status(
    const uint16_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t STATUS_CLEAR =
    0u;
  static constexpr uint16_t STATUS_ACTIVE =
    1u;

  // pointer types
  using RawPtr =
    sys_msgs::msg::Fault_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::msg::Fault_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::msg::Fault_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::msg::Fault_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::msg::Fault_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::msg::Fault_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::msg::Fault_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::msg::Fault_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::msg::Fault_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::msg::Fault_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__msg__Fault
    std::shared_ptr<sys_msgs::msg::Fault_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__msg__Fault
    std::shared_ptr<sys_msgs::msg::Fault_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Fault_ & other) const
  {
    if (this->time_stamp_ms != other.time_stamp_ms) {
      return false;
    }
    if (this->code != other.code) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Fault_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Fault_

// alias to use template instance with default allocator
using Fault =
  sys_msgs::msg::Fault_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t Fault_<ContainerAllocator>::STATUS_CLEAR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t Fault_<ContainerAllocator>::STATUS_ACTIVE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace sys_msgs

#endif  // SYS_MSGS__MSG__DETAIL__FAULT__STRUCT_HPP_
