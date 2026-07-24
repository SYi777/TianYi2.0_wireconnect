// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/HandPoseReq.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/hand_pose_req__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_HandPoseReq_thumb_rotating
{
public:
  explicit Init_HandPoseReq_thumb_rotating(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  ::cm_msgs::msg::HandPoseReq thumb_rotating(::cm_msgs::msg::HandPoseReq::_thumb_rotating_type arg)
  {
    msg_.thumb_rotating = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_thumb_bending
{
public:
  explicit Init_HandPoseReq_thumb_bending(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_thumb_rotating thumb_bending(::cm_msgs::msg::HandPoseReq::_thumb_bending_type arg)
  {
    msg_.thumb_bending = std::move(arg);
    return Init_HandPoseReq_thumb_rotating(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_index_finger
{
public:
  explicit Init_HandPoseReq_index_finger(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_thumb_bending index_finger(::cm_msgs::msg::HandPoseReq::_index_finger_type arg)
  {
    msg_.index_finger = std::move(arg);
    return Init_HandPoseReq_thumb_bending(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_middle_finger
{
public:
  explicit Init_HandPoseReq_middle_finger(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_index_finger middle_finger(::cm_msgs::msg::HandPoseReq::_middle_finger_type arg)
  {
    msg_.middle_finger = std::move(arg);
    return Init_HandPoseReq_index_finger(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_ring_finger
{
public:
  explicit Init_HandPoseReq_ring_finger(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_middle_finger ring_finger(::cm_msgs::msg::HandPoseReq::_ring_finger_type arg)
  {
    msg_.ring_finger = std::move(arg);
    return Init_HandPoseReq_middle_finger(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_little_finger
{
public:
  explicit Init_HandPoseReq_little_finger(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_ring_finger little_finger(::cm_msgs::msg::HandPoseReq::_little_finger_type arg)
  {
    msg_.little_finger = std::move(arg);
    return Init_HandPoseReq_ring_finger(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_finger_status
{
public:
  explicit Init_HandPoseReq_finger_status(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_little_finger finger_status(::cm_msgs::msg::HandPoseReq::_finger_status_type arg)
  {
    msg_.finger_status = std::move(arg);
    return Init_HandPoseReq_little_finger(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_gripper_side
{
public:
  explicit Init_HandPoseReq_gripper_side(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_finger_status gripper_side(::cm_msgs::msg::HandPoseReq::_gripper_side_type arg)
  {
    msg_.gripper_side = std::move(arg);
    return Init_HandPoseReq_finger_status(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_gripper_move_enable
{
public:
  explicit Init_HandPoseReq_gripper_move_enable(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_gripper_side gripper_move_enable(::cm_msgs::msg::HandPoseReq::_gripper_move_enable_type arg)
  {
    msg_.gripper_move_enable = std::move(arg);
    return Init_HandPoseReq_gripper_side(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_rpy
{
public:
  explicit Init_HandPoseReq_rpy(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_gripper_move_enable rpy(::cm_msgs::msg::HandPoseReq::_rpy_type arg)
  {
    msg_.rpy = std::move(arg);
    return Init_HandPoseReq_gripper_move_enable(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_head_move_enable
{
public:
  explicit Init_HandPoseReq_head_move_enable(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_rpy head_move_enable(::cm_msgs::msg::HandPoseReq::_head_move_enable_type arg)
  {
    msg_.head_move_enable = std::move(arg);
    return Init_HandPoseReq_rpy(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_right_hand_pose_req
{
public:
  explicit Init_HandPoseReq_right_hand_pose_req(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_head_move_enable right_hand_pose_req(::cm_msgs::msg::HandPoseReq::_right_hand_pose_req_type arg)
  {
    msg_.right_hand_pose_req = std::move(arg);
    return Init_HandPoseReq_head_move_enable(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_left_hand_pose_req
{
public:
  explicit Init_HandPoseReq_left_hand_pose_req(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_right_hand_pose_req left_hand_pose_req(::cm_msgs::msg::HandPoseReq::_left_hand_pose_req_type arg)
  {
    msg_.left_hand_pose_req = std::move(arg);
    return Init_HandPoseReq_right_hand_pose_req(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_hand_reset
{
public:
  explicit Init_HandPoseReq_hand_reset(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_left_hand_pose_req hand_reset(::cm_msgs::msg::HandPoseReq::_hand_reset_type arg)
  {
    msg_.hand_reset = std::move(arg);
    return Init_HandPoseReq_left_hand_pose_req(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_hand_side
{
public:
  explicit Init_HandPoseReq_hand_side(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_hand_reset hand_side(::cm_msgs::msg::HandPoseReq::_hand_side_type arg)
  {
    msg_.hand_side = std::move(arg);
    return Init_HandPoseReq_hand_reset(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_hand_move_enable
{
public:
  explicit Init_HandPoseReq_hand_move_enable(::cm_msgs::msg::HandPoseReq & msg)
  : msg_(msg)
  {}
  Init_HandPoseReq_hand_side hand_move_enable(::cm_msgs::msg::HandPoseReq::_hand_move_enable_type arg)
  {
    msg_.hand_move_enable = std::move(arg);
    return Init_HandPoseReq_hand_side(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

class Init_HandPoseReq_header
{
public:
  Init_HandPoseReq_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandPoseReq_hand_move_enable header(::cm_msgs::msg::HandPoseReq::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HandPoseReq_hand_move_enable(msg_);
  }

private:
  ::cm_msgs::msg::HandPoseReq msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::HandPoseReq>()
{
  return cm_msgs::msg::builder::Init_HandPoseReq_header();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__HAND_POSE_REQ__BUILDER_HPP_
