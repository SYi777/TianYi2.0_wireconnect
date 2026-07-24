// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sys_msgs:msg/FaultArray.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_HPP_
#define SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'fault_array'
#include "sys_msgs/msg/detail/fault__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sys_msgs__msg__FaultArray __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__msg__FaultArray __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FaultArray_
{
  using Type = FaultArray_<ContainerAllocator>;

  explicit FaultArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit FaultArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _fault_array_type =
    std::vector<sys_msgs::msg::Fault_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sys_msgs::msg::Fault_<ContainerAllocator>>>;
  _fault_array_type fault_array;

  // setters for named parameter idiom
  Type & set__fault_array(
    const std::vector<sys_msgs::msg::Fault_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sys_msgs::msg::Fault_<ContainerAllocator>>> & _arg)
  {
    this->fault_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sys_msgs::msg::FaultArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::msg::FaultArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::msg::FaultArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::msg::FaultArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__msg__FaultArray
    std::shared_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__msg__FaultArray
    std::shared_ptr<sys_msgs::msg::FaultArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultArray_ & other) const
  {
    if (this->fault_array != other.fault_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultArray_

// alias to use template instance with default allocator
using FaultArray =
  sys_msgs::msg::FaultArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sys_msgs

#endif  // SYS_MSGS__MSG__DETAIL__FAULT_ARRAY__STRUCT_HPP_
