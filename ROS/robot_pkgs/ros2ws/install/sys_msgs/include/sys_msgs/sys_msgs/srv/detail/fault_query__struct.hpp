// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sys_msgs:srv/FaultQuery.idl
// generated code does not contain a copyright notice

#ifndef SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_HPP_
#define SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sys_msgs__srv__FaultQuery_Request __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__srv__FaultQuery_Request __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FaultQuery_Request_
{
  using Type = FaultQuery_Request_<ContainerAllocator>;

  explicit FaultQuery_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FaultQuery_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__srv__FaultQuery_Request
    std::shared_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__srv__FaultQuery_Request
    std::shared_ptr<sys_msgs::srv::FaultQuery_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultQuery_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultQuery_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultQuery_Request_

// alias to use template instance with default allocator
using FaultQuery_Request =
  sys_msgs::srv::FaultQuery_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sys_msgs


// Include directives for member types
// Member 'fault_array'
#include "sys_msgs/msg/detail/fault__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sys_msgs__srv__FaultQuery_Response __attribute__((deprecated))
#else
# define DEPRECATED__sys_msgs__srv__FaultQuery_Response __declspec(deprecated)
#endif

namespace sys_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FaultQuery_Response_
{
  using Type = FaultQuery_Response_<ContainerAllocator>;

  explicit FaultQuery_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit FaultQuery_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sys_msgs__srv__FaultQuery_Response
    std::shared_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sys_msgs__srv__FaultQuery_Response
    std::shared_ptr<sys_msgs::srv::FaultQuery_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultQuery_Response_ & other) const
  {
    if (this->fault_array != other.fault_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultQuery_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultQuery_Response_

// alias to use template instance with default allocator
using FaultQuery_Response =
  sys_msgs::srv::FaultQuery_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sys_msgs

namespace sys_msgs
{

namespace srv
{

struct FaultQuery
{
  using Request = sys_msgs::srv::FaultQuery_Request;
  using Response = sys_msgs::srv::FaultQuery_Response;
};

}  // namespace srv

}  // namespace sys_msgs

#endif  // SYS_MSGS__SRV__DETAIL__FAULT_QUERY__STRUCT_HPP_
