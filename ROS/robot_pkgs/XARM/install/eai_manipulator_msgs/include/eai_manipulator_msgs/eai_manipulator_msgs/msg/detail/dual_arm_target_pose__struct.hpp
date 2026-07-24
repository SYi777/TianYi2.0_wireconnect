// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from eai_manipulator_msgs:msg/DualArmTargetPose.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_HPP_
#define EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_HPP_

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
// Member 'target_l'
// Member 'target_r'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__eai_manipulator_msgs__msg__DualArmTargetPose __attribute__((deprecated))
#else
# define DEPRECATED__eai_manipulator_msgs__msg__DualArmTargetPose __declspec(deprecated)
#endif

namespace eai_manipulator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DualArmTargetPose_
{
  using Type = DualArmTargetPose_<ContainerAllocator>;

  explicit DualArmTargetPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    target_l(_init),
    target_r(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_frame_l = "";
      this->to_frame_l = "";
      this->offset_x_l = 0.0f;
      this->offset_y_l = 0.0f;
      this->offset_z_l = 0.0f;
      this->from_frame_r = "";
      this->to_frame_r = "";
      this->offset_x_r = 0.0f;
      this->offset_y_r = 0.0f;
      this->offset_z_r = 0.0f;
      this->is_dual_arm_syn = false;
    }
  }

  explicit DualArmTargetPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    target_l(_alloc, _init),
    from_frame_l(_alloc),
    to_frame_l(_alloc),
    target_r(_alloc, _init),
    from_frame_r(_alloc),
    to_frame_r(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_frame_l = "";
      this->to_frame_l = "";
      this->offset_x_l = 0.0f;
      this->offset_y_l = 0.0f;
      this->offset_z_l = 0.0f;
      this->from_frame_r = "";
      this->to_frame_r = "";
      this->offset_x_r = 0.0f;
      this->offset_y_r = 0.0f;
      this->offset_z_r = 0.0f;
      this->is_dual_arm_syn = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _target_l_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_l_type target_l;
  using _from_frame_l_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_frame_l_type from_frame_l;
  using _to_frame_l_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_frame_l_type to_frame_l;
  using _offset_x_l_type =
    float;
  _offset_x_l_type offset_x_l;
  using _offset_y_l_type =
    float;
  _offset_y_l_type offset_y_l;
  using _offset_z_l_type =
    float;
  _offset_z_l_type offset_z_l;
  using _target_r_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_r_type target_r;
  using _from_frame_r_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_frame_r_type from_frame_r;
  using _to_frame_r_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_frame_r_type to_frame_r;
  using _offset_x_r_type =
    float;
  _offset_x_r_type offset_x_r;
  using _offset_y_r_type =
    float;
  _offset_y_r_type offset_y_r;
  using _offset_z_r_type =
    float;
  _offset_z_r_type offset_z_r;
  using _is_dual_arm_syn_type =
    bool;
  _is_dual_arm_syn_type is_dual_arm_syn;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__target_l(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target_l = _arg;
    return *this;
  }
  Type & set__from_frame_l(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->from_frame_l = _arg;
    return *this;
  }
  Type & set__to_frame_l(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_frame_l = _arg;
    return *this;
  }
  Type & set__offset_x_l(
    const float & _arg)
  {
    this->offset_x_l = _arg;
    return *this;
  }
  Type & set__offset_y_l(
    const float & _arg)
  {
    this->offset_y_l = _arg;
    return *this;
  }
  Type & set__offset_z_l(
    const float & _arg)
  {
    this->offset_z_l = _arg;
    return *this;
  }
  Type & set__target_r(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target_r = _arg;
    return *this;
  }
  Type & set__from_frame_r(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->from_frame_r = _arg;
    return *this;
  }
  Type & set__to_frame_r(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_frame_r = _arg;
    return *this;
  }
  Type & set__offset_x_r(
    const float & _arg)
  {
    this->offset_x_r = _arg;
    return *this;
  }
  Type & set__offset_y_r(
    const float & _arg)
  {
    this->offset_y_r = _arg;
    return *this;
  }
  Type & set__offset_z_r(
    const float & _arg)
  {
    this->offset_z_r = _arg;
    return *this;
  }
  Type & set__is_dual_arm_syn(
    const bool & _arg)
  {
    this->is_dual_arm_syn = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__eai_manipulator_msgs__msg__DualArmTargetPose
    std::shared_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__eai_manipulator_msgs__msg__DualArmTargetPose
    std::shared_ptr<eai_manipulator_msgs::msg::DualArmTargetPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DualArmTargetPose_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->target_l != other.target_l) {
      return false;
    }
    if (this->from_frame_l != other.from_frame_l) {
      return false;
    }
    if (this->to_frame_l != other.to_frame_l) {
      return false;
    }
    if (this->offset_x_l != other.offset_x_l) {
      return false;
    }
    if (this->offset_y_l != other.offset_y_l) {
      return false;
    }
    if (this->offset_z_l != other.offset_z_l) {
      return false;
    }
    if (this->target_r != other.target_r) {
      return false;
    }
    if (this->from_frame_r != other.from_frame_r) {
      return false;
    }
    if (this->to_frame_r != other.to_frame_r) {
      return false;
    }
    if (this->offset_x_r != other.offset_x_r) {
      return false;
    }
    if (this->offset_y_r != other.offset_y_r) {
      return false;
    }
    if (this->offset_z_r != other.offset_z_r) {
      return false;
    }
    if (this->is_dual_arm_syn != other.is_dual_arm_syn) {
      return false;
    }
    return true;
  }
  bool operator!=(const DualArmTargetPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DualArmTargetPose_

// alias to use template instance with default allocator
using DualArmTargetPose =
  eai_manipulator_msgs::msg::DualArmTargetPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__MSG__DETAIL__DUAL_ARM_TARGET_POSE__STRUCT_HPP_
