// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/PoseActionStatus.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/pose_action_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_PoseActionStatus_gripper_move_success
{
public:
  explicit Init_PoseActionStatus_gripper_move_success(::cm_msgs::msg::PoseActionStatus & msg)
  : msg_(msg)
  {}
  ::cm_msgs::msg::PoseActionStatus gripper_move_success(::cm_msgs::msg::PoseActionStatus::_gripper_move_success_type arg)
  {
    msg_.gripper_move_success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::PoseActionStatus msg_;
};

class Init_PoseActionStatus_head_move_success
{
public:
  explicit Init_PoseActionStatus_head_move_success(::cm_msgs::msg::PoseActionStatus & msg)
  : msg_(msg)
  {}
  Init_PoseActionStatus_gripper_move_success head_move_success(::cm_msgs::msg::PoseActionStatus::_head_move_success_type arg)
  {
    msg_.head_move_success = std::move(arg);
    return Init_PoseActionStatus_gripper_move_success(msg_);
  }

private:
  ::cm_msgs::msg::PoseActionStatus msg_;
};

class Init_PoseActionStatus_hand_move_success
{
public:
  explicit Init_PoseActionStatus_hand_move_success(::cm_msgs::msg::PoseActionStatus & msg)
  : msg_(msg)
  {}
  Init_PoseActionStatus_head_move_success hand_move_success(::cm_msgs::msg::PoseActionStatus::_hand_move_success_type arg)
  {
    msg_.hand_move_success = std::move(arg);
    return Init_PoseActionStatus_head_move_success(msg_);
  }

private:
  ::cm_msgs::msg::PoseActionStatus msg_;
};

class Init_PoseActionStatus_resp_frame_id
{
public:
  explicit Init_PoseActionStatus_resp_frame_id(::cm_msgs::msg::PoseActionStatus & msg)
  : msg_(msg)
  {}
  Init_PoseActionStatus_hand_move_success resp_frame_id(::cm_msgs::msg::PoseActionStatus::_resp_frame_id_type arg)
  {
    msg_.resp_frame_id = std::move(arg);
    return Init_PoseActionStatus_hand_move_success(msg_);
  }

private:
  ::cm_msgs::msg::PoseActionStatus msg_;
};

class Init_PoseActionStatus_header
{
public:
  Init_PoseActionStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseActionStatus_resp_frame_id header(::cm_msgs::msg::PoseActionStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PoseActionStatus_resp_frame_id(msg_);
  }

private:
  ::cm_msgs::msg::PoseActionStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::PoseActionStatus>()
{
  return cm_msgs::msg::builder::Init_PoseActionStatus_header();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__POSE_ACTION_STATUS__BUILDER_HPP_
