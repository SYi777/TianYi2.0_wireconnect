// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_HPP_
#define CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__msg__PoseActionStatus __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__msg__PoseActionStatus __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PoseActionStatus_
{
  using Type = PoseActionStatus_<ContainerAllocator>;

  explicit PoseActionStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resp_frame_id = 0ul;
      this->hand_move_success = 0;
      this->head_move_success = 0;
      this->gripper_move_success = 0;
    }
  }

  explicit PoseActionStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resp_frame_id = 0ul;
      this->hand_move_success = 0;
      this->head_move_success = 0;
      this->gripper_move_success = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _resp_frame_id_type =
    uint32_t;
  _resp_frame_id_type resp_frame_id;
  using _hand_move_success_type =
    uint8_t;
  _hand_move_success_type hand_move_success;
  using _head_move_success_type =
    uint8_t;
  _head_move_success_type head_move_success;
  using _gripper_move_success_type =
    uint8_t;
  _gripper_move_success_type gripper_move_success;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__resp_frame_id(
    const uint32_t & _arg)
  {
    this->resp_frame_id = _arg;
    return *this;
  }
  Type & set__hand_move_success(
    const uint8_t & _arg)
  {
    this->hand_move_success = _arg;
    return *this;
  }
  Type & set__head_move_success(
    const uint8_t & _arg)
  {
    this->head_move_success = _arg;
    return *this;
  }
  Type & set__gripper_move_success(
    const uint8_t & _arg)
  {
    this->gripper_move_success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::msg::PoseActionStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::msg::PoseActionStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::PoseActionStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::PoseActionStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__msg__PoseActionStatus
    std::shared_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__msg__PoseActionStatus
    std::shared_ptr<cm_msgs::msg::PoseActionStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseActionStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->resp_frame_id != other.resp_frame_id) {
      return false;
    }
    if (this->hand_move_success != other.hand_move_success) {
      return false;
    }
    if (this->head_move_success != other.head_move_success) {
      return false;
    }
    if (this->gripper_move_success != other.gripper_move_success) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseActionStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseActionStatus_

// alias to use template instance with default allocator
using PoseActionStatus =
  cm_msgs::msg::PoseActionStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__STRUCT_HPP_
