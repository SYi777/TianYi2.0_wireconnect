// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:action/ReportMotion.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__ACTION__DETAIL__REPORT_MOTION__BUILDER_HPP_
#define CM_MSGS__ACTION__DETAIL__REPORT_MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/action/detail/report_motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_Goal_json_data
{
public:
  explicit Init_ReportMotion_Goal_json_data(::cm_msgs::action::ReportMotion_Goal & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_Goal json_data(::cm_msgs::action::ReportMotion_Goal::_json_data_type arg)
  {
    msg_.json_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Goal msg_;
};

class Init_ReportMotion_Goal_data
{
public:
  explicit Init_ReportMotion_Goal_data(::cm_msgs::action::ReportMotion_Goal & msg)
  : msg_(msg)
  {}
  Init_ReportMotion_Goal_json_data data(::cm_msgs::action::ReportMotion_Goal::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_ReportMotion_Goal_json_data(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Goal msg_;
};

class Init_ReportMotion_Goal_msg_id
{
public:
  Init_ReportMotion_Goal_msg_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_Goal_data msg_id(::cm_msgs::action::ReportMotion_Goal::_msg_id_type arg)
  {
    msg_.msg_id = std::move(arg);
    return Init_ReportMotion_Goal_data(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_Goal>()
{
  return cm_msgs::action::builder::Init_ReportMotion_Goal_msg_id();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_Result_info
{
public:
  explicit Init_ReportMotion_Result_info(::cm_msgs::action::ReportMotion_Result & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_Result info(::cm_msgs::action::ReportMotion_Result::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Result msg_;
};

class Init_ReportMotion_Result_result
{
public:
  Init_ReportMotion_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_Result_info result(::cm_msgs::action::ReportMotion_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_ReportMotion_Result_info(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_Result>()
{
  return cm_msgs::action::builder::Init_ReportMotion_Result_result();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_Feedback_status
{
public:
  Init_ReportMotion_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cm_msgs::action::ReportMotion_Feedback status(::cm_msgs::action::ReportMotion_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_Feedback>()
{
  return cm_msgs::action::builder::Init_ReportMotion_Feedback_status();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_SendGoal_Request_goal
{
public:
  explicit Init_ReportMotion_SendGoal_Request_goal(::cm_msgs::action::ReportMotion_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_SendGoal_Request goal(::cm_msgs::action::ReportMotion_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_SendGoal_Request msg_;
};

class Init_ReportMotion_SendGoal_Request_goal_id
{
public:
  Init_ReportMotion_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_SendGoal_Request_goal goal_id(::cm_msgs::action::ReportMotion_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ReportMotion_SendGoal_Request_goal(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_SendGoal_Request>()
{
  return cm_msgs::action::builder::Init_ReportMotion_SendGoal_Request_goal_id();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_SendGoal_Response_stamp
{
public:
  explicit Init_ReportMotion_SendGoal_Response_stamp(::cm_msgs::action::ReportMotion_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_SendGoal_Response stamp(::cm_msgs::action::ReportMotion_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_SendGoal_Response msg_;
};

class Init_ReportMotion_SendGoal_Response_accepted
{
public:
  Init_ReportMotion_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_SendGoal_Response_stamp accepted(::cm_msgs::action::ReportMotion_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ReportMotion_SendGoal_Response_stamp(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_SendGoal_Response>()
{
  return cm_msgs::action::builder::Init_ReportMotion_SendGoal_Response_accepted();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_GetResult_Request_goal_id
{
public:
  Init_ReportMotion_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cm_msgs::action::ReportMotion_GetResult_Request goal_id(::cm_msgs::action::ReportMotion_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_GetResult_Request>()
{
  return cm_msgs::action::builder::Init_ReportMotion_GetResult_Request_goal_id();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_GetResult_Response_result
{
public:
  explicit Init_ReportMotion_GetResult_Response_result(::cm_msgs::action::ReportMotion_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_GetResult_Response result(::cm_msgs::action::ReportMotion_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_GetResult_Response msg_;
};

class Init_ReportMotion_GetResult_Response_status
{
public:
  Init_ReportMotion_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_GetResult_Response_result status(::cm_msgs::action::ReportMotion_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ReportMotion_GetResult_Response_result(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_GetResult_Response>()
{
  return cm_msgs::action::builder::Init_ReportMotion_GetResult_Response_status();
}

}  // namespace cm_msgs


namespace cm_msgs
{

namespace action
{

namespace builder
{

class Init_ReportMotion_FeedbackMessage_feedback
{
public:
  explicit Init_ReportMotion_FeedbackMessage_feedback(::cm_msgs::action::ReportMotion_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::cm_msgs::action::ReportMotion_FeedbackMessage feedback(::cm_msgs::action::ReportMotion_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_FeedbackMessage msg_;
};

class Init_ReportMotion_FeedbackMessage_goal_id
{
public:
  Init_ReportMotion_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReportMotion_FeedbackMessage_feedback goal_id(::cm_msgs::action::ReportMotion_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ReportMotion_FeedbackMessage_feedback(msg_);
  }

private:
  ::cm_msgs::action::ReportMotion_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::action::ReportMotion_FeedbackMessage>()
{
  return cm_msgs::action::builder::Init_ReportMotion_FeedbackMessage_goal_id();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__ACTION__DETAIL__REPORT_MOTION__BUILDER_HPP_
