// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from eai_manipulator_msgs:srv/Mode.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__STRUCT_HPP_
#define EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__srv__Mode_Request __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__srv__Mode_Request __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Mode_Request_
{
  using Type = Mode_Request_<ContainerAllocator>;

  explicit Mode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit Mode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    int16_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const int16_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__srv__Mode_Request
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__srv__Mode_Request
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_Request_

// alias to use template instance with default allocator
using Mode_Request =
  eai_manipulator_msgs::srv::Mode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace eai_manipulator_msgs


#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__srv__Mode_Response __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__srv__Mode_Response __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Mode_Response_
{
  using Type = Mode_Response_<ContainerAllocator>;

  explicit Mode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->info = "";
    }
  }

  explicit Mode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->info = "";
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;
  using _info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_type info;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__info(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__srv__Mode_Response
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__srv__Mode_Response
    std::shared_ptr<eai_manipulator_msgs::srv::Mode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_Response_

// alias to use template instance with default allocator
using Mode_Response =
  eai_manipulator_msgs::srv::Mode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace eai_manipulator_msgs

namespace eai_manipulator_msgs
{

namespace srv
{

struct Mode
{
  using Request = eai_manipulator_msgs::srv::Mode_Request;
  using Response = eai_manipulator_msgs::srv::Mode_Response;
};

}  // namespace srv

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__SRV__DETAIL__MODE__STRUCT_HPP_
