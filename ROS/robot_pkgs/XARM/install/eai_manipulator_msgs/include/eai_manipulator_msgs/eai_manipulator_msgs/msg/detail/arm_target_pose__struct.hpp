// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from eai_manipulator_msgs:msg/ArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_HPP_

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
// Member 'target'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__msg__ArmTargetPose __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__msg__ArmTargetPose __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmTargetPose_
{
  using Type = ArmTargetPose_<ContainerAllocator>;

  explicit ArmTargetPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    target(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_frame = "";
      this->to_frame = "";
      this->offset_x = 0.0f;
      this->offset_y = 0.0f;
      this->offset_z = 0.0f;
    }
  }

  explicit ArmTargetPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    target(_alloc, _init),
    from_frame(_alloc),
    to_frame(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_frame = "";
      this->to_frame = "";
      this->offset_x = 0.0f;
      this->offset_y = 0.0f;
      this->offset_z = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _target_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_type target;
  using _from_frame_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_frame_type from_frame;
  using _to_frame_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_frame_type to_frame;
  using _offset_x_type =
    float;
  _offset_x_type offset_x;
  using _offset_y_type =
    float;
  _offset_y_type offset_y;
  using _offset_z_type =
    float;
  _offset_z_type offset_z;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__target(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target = _arg;
    return *this;
  }
  Type & set__from_frame(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->from_frame = _arg;
    return *this;
  }
  Type & set__to_frame(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_frame = _arg;
    return *this;
  }
  Type & set__offset_x(
    const float & _arg)
  {
    this->offset_x = _arg;
    return *this;
  }
  Type & set__offset_y(
    const float & _arg)
  {
    this->offset_y = _arg;
    return *this;
  }
  Type & set__offset_z(
    const float & _arg)
  {
    this->offset_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__msg__ArmTargetPose
    std::shared_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__msg__ArmTargetPose
    std::shared_ptr<eai_manipulator_msgs::msg::ArmTargetPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmTargetPose_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    if (this->from_frame != other.from_frame) {
      return false;
    }
    if (this->to_frame != other.to_frame) {
      return false;
    }
    if (this->offset_x != other.offset_x) {
      return false;
    }
    if (this->offset_y != other.offset_y) {
      return false;
    }
    if (this->offset_z != other.offset_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmTargetPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmTargetPose_

// alias to use template instance with default allocator
using ArmTargetPose =
  eai_manipulator_msgs::msg::ArmTargetPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__ARM_TARGET_POSE__STRUCT_HPP_
