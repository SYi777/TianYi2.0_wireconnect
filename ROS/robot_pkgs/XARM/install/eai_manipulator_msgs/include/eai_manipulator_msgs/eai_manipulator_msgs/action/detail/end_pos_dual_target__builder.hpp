// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eai_manipulator_msgs:action/EndPosDualTarget.idl
// generated code does not contain a copyright notice

#ifndef EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__BUILDER_HPP_
#define EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "eai_manipulator_msgs/action/detail/end_pos_dual_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_Goal_target
{
public:
  Init_EndPosDualTarget_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_Goal target(::eai_manipulator_msgs::action::EndPosDualTarget_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_Goal>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_Goal_target();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_Result_result_msg
{
public:
  explicit Init_EndPosDualTarget_Result_result_msg(::eai_manipulator_msgs::action::EndPosDualTarget_Result & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_Result result_msg(::eai_manipulator_msgs::action::EndPosDualTarget_Result::_result_msg_type arg)
  {
    msg_.result_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_Result msg_;
};

class Init_EndPosDualTarget_Result_success
{
public:
  Init_EndPosDualTarget_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_Result_result_msg success(::eai_manipulator_msgs::action::EndPosDualTarget_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_EndPosDualTarget_Result_result_msg(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_Result>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_Result_success();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_Feedback_feedback_msg
{
public:
  explicit Init_EndPosDualTarget_Feedback_feedback_msg(::eai_manipulator_msgs::action::EndPosDualTarget_Feedback & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_Feedback feedback_msg(::eai_manipulator_msgs::action::EndPosDualTarget_Feedback::_feedback_msg_type arg)
  {
    msg_.feedback_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_Feedback msg_;
};

class Init_EndPosDualTarget_Feedback_current_err
{
public:
  Init_EndPosDualTarget_Feedback_current_err()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_Feedback_feedback_msg current_err(::eai_manipulator_msgs::action::EndPosDualTarget_Feedback::_current_err_type arg)
  {
    msg_.current_err = std::move(arg);
    return Init_EndPosDualTarget_Feedback_feedback_msg(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_Feedback>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_Feedback_current_err();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_SendGoal_Request_goal
{
public:
  explicit Init_EndPosDualTarget_SendGoal_Request_goal(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request goal(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request msg_;
};

class Init_EndPosDualTarget_SendGoal_Request_goal_id
{
public:
  Init_EndPosDualTarget_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_SendGoal_Request_goal goal_id(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_EndPosDualTarget_SendGoal_Request_goal(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Request>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_SendGoal_Request_goal_id();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_SendGoal_Response_stamp
{
public:
  explicit Init_EndPosDualTarget_SendGoal_Response_stamp(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response stamp(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response msg_;
};

class Init_EndPosDualTarget_SendGoal_Response_accepted
{
public:
  Init_EndPosDualTarget_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_SendGoal_Response_stamp accepted(::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_EndPosDualTarget_SendGoal_Response_stamp(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_SendGoal_Response>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_SendGoal_Response_accepted();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_GetResult_Request_goal_id
{
public:
  Init_EndPosDualTarget_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request goal_id(::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Request>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_GetResult_Request_goal_id();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_GetResult_Response_result
{
public:
  explicit Init_EndPosDualTarget_GetResult_Response_result(::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response result(::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response msg_;
};

class Init_EndPosDualTarget_GetResult_Response_status
{
public:
  Init_EndPosDualTarget_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_GetResult_Response_result status(::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_EndPosDualTarget_GetResult_Response_result(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_GetResult_Response>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_GetResult_Response_status();
}

}  // namespace eai_manipulator_msgs


namespace eai_manipulator_msgs
{

namespace action
{

namespace builder
{

class Init_EndPosDualTarget_FeedbackMessage_feedback
{
public:
  explicit Init_EndPosDualTarget_FeedbackMessage_feedback(::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage feedback(::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage msg_;
};

class Init_EndPosDualTarget_FeedbackMessage_goal_id
{
public:
  Init_EndPosDualTarget_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EndPosDualTarget_FeedbackMessage_feedback goal_id(::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_EndPosDualTarget_FeedbackMessage_feedback(msg_);
  }

private:
  ::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::eai_manipulator_msgs::action::EndPosDualTarget_FeedbackMessage>()
{
  return eai_manipulator_msgs::action::builder::Init_EndPosDualTarget_FeedbackMessage_goal_id();
}

}  // namespace eai_manipulator_msgs

#endif  // EAI_MANIPULATOR_MSGS__ACTION__DETAIL__END_POS_DUAL_TARGET__BUILDER_HPP_
