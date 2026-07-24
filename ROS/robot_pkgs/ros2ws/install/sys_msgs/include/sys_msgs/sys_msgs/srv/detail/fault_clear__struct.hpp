// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sys_msgs:srv/FaultClear.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sys_msgs__srv__FaultClear_Request __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__srv__FaultClear_Request __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FaultClear_Request_
{
  using Type = FaultClear_Request_<ContainerAllocator>;

  explicit FaultClear_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit FaultClear_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _fault_array_type =
    std::vector<uint64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint64_t>>;
  _fault_array_type fault_array;

  // setters for named parameter idiom
  Type & set__fault_array(
    const std::vector<uint64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint64_t>> & _arg)
  {
    this->fault_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sys_msgs::srv::FaultClear_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::srv::FaultClear_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultClear_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultClear_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__srv__FaultClear_Request
    std::shared_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__srv__FaultClear_Request
    std::shared_ptr<sys_msgs::srv::FaultClear_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultClear_Request_ & other) const
  {
    if (this->fault_array != other.fault_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultClear_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultClear_Request_

// alias to use template instance with default allocator
using FaultClear_Request =
  sys_msgs::srv::FaultClear_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sys_msgs


#ifndef _WIN32
# define DEPRECATED__sys_msgs__srv__FaultClear_Response __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__srv__FaultClear_Response __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FaultClear_Response_
{
  using Type = FaultClear_Response_<ContainerAllocator>;

  explicit FaultClear_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit FaultClear_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sys_msgs::srv::FaultClear_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::srv::FaultClear_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultClear_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultClear_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__srv__FaultClear_Response
    std::shared_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__srv__FaultClear_Response
    std::shared_ptr<sys_msgs::srv::FaultClear_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultClear_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultClear_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultClear_Response_

// alias to use template instance with default allocator
using FaultClear_Response =
  sys_msgs::srv::FaultClear_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sys_msgs

namespace sys_msgs
{

namespace srv
{

struct FaultClear
{
  using Request = sys_msgs::srv::FaultClear_Request;
  using Response = sys_msgs::srv::FaultClear_Response;
};

}  // namespace srv

}  // namespace sys_msgs

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_CLEAR__STRUCT_HPP_
