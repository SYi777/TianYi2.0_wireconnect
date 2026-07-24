// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_HPP_
#define CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_HPP_

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
// Member 'left_hand_pose_req'
// Member 'right_hand_pose_req'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__msg__HandPoseReq __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__msg__HandPoseReq __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandPoseReq_
{
  using Type = HandPoseReq_<ContainerAllocator>;

  explicit HandPoseReq_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    left_hand_pose_req(_init),
    right_hand_pose_req(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hand_move_enable = 0;
      this->hand_side = 0;
      this->hand_reset = 0;
      this->head_move_enable = 0;
      this->gripper_move_enable = 0;
      this->gripper_side = 0;
      this->finger_status = 0;
      this->little_finger = 0.0f;
      this->ring_finger = 0.0f;
      this->middle_finger = 0.0f;
      this->index_finger = 0.0f;
      this->thumb_bending = 0.0f;
      this->thumb_rotating = 0.0f;
    }
  }

  explicit HandPoseReq_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    left_hand_pose_req(_alloc, _init),
    right_hand_pose_req(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hand_move_enable = 0;
      this->hand_side = 0;
      this->hand_reset = 0;
      this->head_move_enable = 0;
      this->gripper_move_enable = 0;
      this->gripper_side = 0;
      this->finger_status = 0;
      this->little_finger = 0.0f;
      this->ring_finger = 0.0f;
      this->middle_finger = 0.0f;
      this->index_finger = 0.0f;
      this->thumb_bending = 0.0f;
      this->thumb_rotating = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _hand_move_enable_type =
    uint8_t;
  _hand_move_enable_type hand_move_enable;
  using _hand_side_type =
    uint8_t;
  _hand_side_type hand_side;
  using _hand_reset_type =
    uint8_t;
  _hand_reset_type hand_reset;
  using _left_hand_pose_req_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _left_hand_pose_req_type left_hand_pose_req;
  using _right_hand_pose_req_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _right_hand_pose_req_type right_hand_pose_req;
  using _head_move_enable_type =
    uint8_t;
  _head_move_enable_type head_move_enable;
  using _rpy_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _rpy_type rpy;
  using _gripper_move_enable_type =
    uint8_t;
  _gripper_move_enable_type gripper_move_enable;
  using _gripper_side_type =
    uint8_t;
  _gripper_side_type gripper_side;
  using _finger_status_type =
    uint8_t;
  _finger_status_type finger_status;
  using _little_finger_type =
    float;
  _little_finger_type little_finger;
  using _ring_finger_type =
    float;
  _ring_finger_type ring_finger;
  using _middle_finger_type =
    float;
  _middle_finger_type middle_finger;
  using _index_finger_type =
    float;
  _index_finger_type index_finger;
  using _thumb_bending_type =
    float;
  _thumb_bending_type thumb_bending;
  using _thumb_rotating_type =
    float;
  _thumb_rotating_type thumb_rotating;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__hand_move_enable(
    const uint8_t & _arg)
  {
    this->hand_move_enable = _arg;
    return *this;
  }
  Type & set__hand_side(
    const uint8_t & _arg)
  {
    this->hand_side = _arg;
    return *this;
  }
  Type & set__hand_reset(
    const uint8_t & _arg)
  {
    this->hand_reset = _arg;
    return *this;
  }
  Type & set__left_hand_pose_req(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->left_hand_pose_req = _arg;
    return *this;
  }
  Type & set__right_hand_pose_req(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->right_hand_pose_req = _arg;
    return *this;
  }
  Type & set__head_move_enable(
    const uint8_t & _arg)
  {
    this->head_move_enable = _arg;
    return *this;
  }
  Type & set__rpy(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->rpy = _arg;
    return *this;
  }
  Type & set__gripper_move_enable(
    const uint8_t & _arg)
  {
    this->gripper_move_enable = _arg;
    return *this;
  }
  Type & set__gripper_side(
    const uint8_t & _arg)
  {
    this->gripper_side = _arg;
    return *this;
  }
  Type & set__finger_status(
    const uint8_t & _arg)
  {
    this->finger_status = _arg;
    return *this;
  }
  Type & set__little_finger(
    const float & _arg)
  {
    this->little_finger = _arg;
    return *this;
  }
  Type & set__ring_finger(
    const float & _arg)
  {
    this->ring_finger = _arg;
    return *this;
  }
  Type & set__middle_finger(
    const float & _arg)
  {
    this->middle_finger = _arg;
    return *this;
  }
  Type & set__index_finger(
    const float & _arg)
  {
    this->index_finger = _arg;
    return *this;
  }
  Type & set__thumb_bending(
    const float & _arg)
  {
    this->thumb_bending = _arg;
    return *this;
  }
  Type & set__thumb_rotating(
    const float & _arg)
  {
    this->thumb_rotating = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::msg::HandPoseReq_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::msg::HandPoseReq_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::HandPoseReq_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::HandPoseReq_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__msg__HandPoseReq
    std::shared_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__msg__HandPoseReq
    std::shared_ptr<cm_msgs::msg::HandPoseReq_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandPoseReq_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->hand_move_enable != other.hand_move_enable) {
      return false;
    }
    if (this->hand_side != other.hand_side) {
      return false;
    }
    if (this->hand_reset != other.hand_reset) {
      return false;
    }
    if (this->left_hand_pose_req != other.left_hand_pose_req) {
      return false;
    }
    if (this->right_hand_pose_req != other.right_hand_pose_req) {
      return false;
    }
    if (this->head_move_enable != other.head_move_enable) {
      return false;
    }
    if (this->rpy != other.rpy) {
      return false;
    }
    if (this->gripper_move_enable != other.gripper_move_enable) {
      return false;
    }
    if (this->gripper_side != other.gripper_side) {
      return false;
    }
    if (this->finger_status != other.finger_status) {
      return false;
    }
    if (this->little_finger != other.little_finger) {
      return false;
    }
    if (this->ring_finger != other.ring_finger) {
      return false;
    }
    if (this->middle_finger != other.middle_finger) {
      return false;
    }
    if (this->index_finger != other.index_finger) {
      return false;
    }
    if (this->thumb_bending != other.thumb_bending) {
      return false;
    }
    if (this->thumb_rotating != other.thumb_rotating) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandPoseReq_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandPoseReq_

// alias to use template instance with default allocator
using HandPoseReq =
  cm_msgs::msg::HandPoseReq_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__STRUCT_HPP_
