// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cloud_service:msg/CommandAck.idl
// generated code does not contain a copyright notice

#ifndef CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_HPP_
#define CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cloud_service__msg__CommandAck __attribute__((deprecated))
#else
# define DEPRECATED__cloud_service__msg__CommandAck __declspec(deprecated)
#endif

namespace cloud_service
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CommandAck_
{
  using Type = CommandAck_<ContainerAllocator>;

  explicit CommandAck_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = 0ll;
      this->cmd_id = 0l;
      this->code = 0l;
      this->message = "";
    }
  }

  explicit CommandAck_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_id = 0ll;
      this->cmd_id = 0l;
      this->code = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _msg_id_type =
    int64_t;
  _msg_id_type msg_id;
  using _cmd_id_type =
    int32_t;
  _cmd_id_type cmd_id;
  using _code_type =
    int32_t;
  _code_type code;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__msg_id(
    const int64_t & _arg)
  {
    this->msg_id = _arg;
    return *this;
  }
  Type & set__cmd_id(
    const int32_t & _arg)
  {
    this->cmd_id = _arg;
    return *this;
  }
  Type & set__code(
    const int32_t & _arg)
  {
    this->code = _arg;
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
    cloud_service::msg::CommandAck_<ContainerAllocator> *;
  using ConstRawPtr =
    const cloud_service::msg::CommandAck_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cloud_service::msg::CommandAck_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cloud_service::msg::CommandAck_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::CommandAck_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::CommandAck_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cloud_service::msg::CommandAck_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cloud_service::msg::CommandAck_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cloud_service::msg::CommandAck_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cloud_service::msg::CommandAck_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cloud_service__msg__CommandAck
    std::shared_ptr<cloud_service::msg::CommandAck_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cloud_service__msg__CommandAck
    std::shared_ptr<cloud_service::msg::CommandAck_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CommandAck_ & other) const
  {
    if (this->msg_id != other.msg_id) {
      return false;
    }
    if (this->cmd_id != other.cmd_id) {
      return false;
    }
    if (this->code != other.code) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const CommandAck_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CommandAck_

// alias to use template instance with default allocator
using CommandAck =
  cloud_service::msg::CommandAck_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cloud_service

#endif  // CLOUD_SERVICE__MSG__DETAIL__COMMAND_ACK__STRUCT_HPP_
