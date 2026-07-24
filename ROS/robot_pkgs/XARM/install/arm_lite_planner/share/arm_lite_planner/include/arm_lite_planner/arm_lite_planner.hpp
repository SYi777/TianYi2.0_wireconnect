#ifndef ARM_LITE_PLANNER__ARM_LITE_PLANNER_HPP_
#define ARM_LITE_PLANNER__ARM_LITE_PLANNER_HPP_

#include <array>
#include <map>
#include <mutex>
#include <optional>
#include <random>
#include <string>
#include <vector>

#include <jsoncpp/json/json.h>
#include <kdl/chain.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/jntarray.hpp>

#include <cm_msgs/action/report_motion.hpp>
#include <cm_msgs/srv/common_stream_ros2.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include <controller_manager_msgs/srv/list_controllers.hpp>
#include <controller_manager_msgs/srv/switch_controller.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/empty.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>

namespace arm_lite_planner
{

using CommonStreamRos2 = cm_msgs::srv::CommonStreamRos2;
using FollowJointTrajectory = control_msgs::action::FollowJointTrajectory;
using ReportMotion = cm_msgs::action::ReportMotion;

enum class ReportChannel
{
  Joint,
  Cartesian,
};

struct ArmConfig
{
  std::string name;
  std::string base_link;
  std::string tip_link;
  std::vector<std::string> joint_names;
  std::vector<double> lower_limits;
  std::vector<double> upper_limits;
  std::vector<double> velocity_limits;
  std::vector<double> acceleration_limits;
  std::vector<double> jerk_limits;
};

struct ControlResult
{
  bool success = false;
  int error_code = -1;
  std::string message;
};

struct TrajectoryBundle
{
  bool has_left = false;
  bool has_right = false;
  trajectory_msgs::msg::JointTrajectory left_trajectory;
  trajectory_msgs::msg::JointTrajectory right_trajectory;
  std::string group_name;
  ReportChannel report_channel = ReportChannel::Cartesian;
  int left_motion_id = 0;
  int right_motion_id = 0;
};

class ArmLitePlanner : public rclcpp::Node
{
public:
  ArmLitePlanner();

private:
  struct ArmRuntime
  {
    ArmConfig config;
    KDL::Chain chain;
    std::unique_ptr<KDL::ChainFkSolverPos_recursive> fk_solver;
    std::unique_ptr<KDL::ChainIkSolverPos_LMA> ik_solver;
  };

  struct ExecutionMonitor
  {
    bool active = false;
    bool expect_left = false;
    bool expect_right = false;
    bool left_done = false;
    bool right_done = false;
    bool left_success = false;
    bool right_success = false;
    int left_error_code = -1;
    int right_error_code = -1;
    std::string group_name;
    ReportChannel report_channel = ReportChannel::Cartesian;
    int left_motion_id = 0;
    int right_motion_id = 0;
  };

  bool initialize_robot_model();
  void setup_interfaces();
  void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);

  bool joint_space_control_callback(
    const std::shared_ptr<CommonStreamRos2::Request> request,
    std::shared_ptr<CommonStreamRos2::Response> response);
  bool dual_arm_waypoints_callback(
    const std::shared_ptr<CommonStreamRos2::Request> request,
    std::shared_ptr<CommonStreamRos2::Response> response);
  bool controller_enable_callback(
    const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
    std::shared_ptr<std_srvs::srv::SetBool::Response> response);

  bool handle_joint_request(const Json::Value &root, TrajectoryBundle &bundle, std::string &error);
  bool handle_cartesian_request(const Json::Value &root, TrajectoryBundle &bundle, std::string &error);

  bool build_joint_bundle(
    const std::string &group,
    const std::vector<std::vector<double>> &joint_waypoints,
    double vel_scale,
    double acc_scale,
    double jerk_scale,
    ReportChannel report_channel,
    TrajectoryBundle &bundle,
    std::string &error);
  bool build_cartesian_bundle(
    const std::string &group,
    const std::string &frame_id,
    const std::vector<geometry_msgs::msg::PoseStamped> &left_waypoints,
    const std::vector<geometry_msgs::msg::PoseStamped> &right_waypoints,
    bool use_cartesian_path,
    double vel_scale,
    double acc_scale,
    double jerk_scale,
    int left_motion_id,
    int right_motion_id,
    TrajectoryBundle &bundle,
    std::string &error);

  bool plan_joint_targets_for_arm(
    const ArmRuntime &arm,
    const std::vector<std::vector<double>> &targets,
    double vel_scale,
    double acc_scale,
    double jerk_scale,
    trajectory_msgs::msg::JointTrajectory &trajectory,
    std::string &error);
  bool plan_pose_targets_for_arm(
    const ArmRuntime &arm,
    const std::vector<geometry_msgs::msg::PoseStamped> &waypoints,
    const std::string &frame_id,
    bool use_cartesian_path,
    double vel_scale,
    double acc_scale,
    double jerk_scale,
    trajectory_msgs::msg::JointTrajectory &trajectory,
    std::string &error);

  bool get_current_joint_state(
    const std::vector<std::string> &joint_names,
    std::vector<double> &positions,
    std::vector<double> &velocities) const;
  bool get_current_joint_positions(
    const std::vector<std::string> &joint_names,
    std::vector<double> &positions) const;
  bool solve_ik(
    const ArmRuntime &arm,
    const geometry_msgs::msg::Pose &target_pose,
    const std::vector<double> &seed,
    std::vector<double> &solution) const;
  bool compute_fk(
    const ArmRuntime &arm,
    const std::vector<double> &joint_positions,
    geometry_msgs::msg::Pose &pose) const;
  bool transform_pose_to_base(
    const std::string &source_frame,
    const geometry_msgs::msg::Pose &input,
    geometry_msgs::msg::Pose &output) const;

  trajectory_msgs::msg::JointTrajectory generate_joint_trajectory(
    const std::vector<std::string> &joint_names,
    const std::vector<std::vector<double>> &waypoints,
    const std::vector<double> &initial_velocity,
    const std::vector<double> &velocity_limits,
    const std::vector<double> &acceleration_limits,
    const std::vector<double> &jerk_limits,
    double vel_scale,
    double acc_scale,
    double jerk_scale) const;

  std::vector<geometry_msgs::msg::Pose> interpolate_pose_segment(
    const geometry_msgs::msg::Pose &start_pose,
    const geometry_msgs::msg::Pose &target_pose,
    double position_step) const;
  std::vector<double> sample_random_joint_target(const ArmConfig &config);
  bool validate_joint_vector(const ArmConfig &config, const std::vector<double> &values, std::string &error) const;
  bool execute_bundle(const TrajectoryBundle &bundle, std::string &error);
  void scale_dual_bundle_for_sync(TrajectoryBundle &bundle) const;
  void scale_trajectory_to_duration(
    trajectory_msgs::msg::JointTrajectory &trajectory,
    double target_duration) const;
  double trajectory_duration(const trajectory_msgs::msg::JointTrajectory &trajectory) const;

  void send_left_goal(const trajectory_msgs::msg::JointTrajectory &trajectory);
  void send_right_goal(const trajectory_msgs::msg::JointTrajectory &trajectory);
  void handle_action_result(
    bool is_left,
    const rclcpp_action::ClientGoalHandle<FollowJointTrajectory>::WrappedResult &result);
  void finalize_execution_if_ready();
  void send_joint_result_srv(const std::string &group_name, const ControlResult &result);
  void send_cartesian_result_srv(
    const std::string &group_name,
    const ControlResult &result,
    int left_motion_id,
    int right_motion_id);
  void send_report_action(
    const rclcpp_action::Client<ReportMotion>::SharedPtr &client,
    const std::string &action_name,
    const std::string &json_data);
  bool wait_for_action_server(
    const rclcpp_action::Client<FollowJointTrajectory>::SharedPtr &client,
    const std::string &name) const;
  bool wait_for_report_service(
    const rclcpp::Client<CommonStreamRos2>::SharedPtr &client,
    const std::string &name) const;
  bool wait_for_report_action_server(
    const rclcpp_action::Client<ReportMotion>::SharedPtr &client,
    const std::string &name) const;
  void publish_moveit_auto_switch_trigger(const TrajectoryBundle &bundle);
  bool wait_for_moveit_controllers_active(const TrajectoryBundle &bundle, std::string &error);
  bool set_moveit_controllers_enabled(bool enabled, std::string &message);
  std::string to_compact_json(const Json::Value &value) const;

  ArmRuntime left_arm_;
  ArmRuntime right_arm_;
  std::string joint_state_topic_;
  double control_period_sec_ = 0.02;
  double cartesian_step_size_ = 0.01;
  std::string moveit_auto_switch_trigger_topic_ = "moveit_commands_dual";
  bool publish_moveit_auto_switch_trigger_ = true;
  bool prefer_controller_switch_service_ = false;
  double moveit_controller_activation_timeout_sec_ = 3.0;
  bool enable_joint_report_ = false;
  bool enable_cartesian_report_ = false;
  std::string joint_report_service_name_ = "/joint_action_report";
  std::string joint_report_action_name_ = "/joint_action_report_action";
  std::string cartesian_report_service_name_ = "/waypoints_action_report";
  std::string cartesian_report_action_name_ = "/waypoints_action_report_action";

  mutable std::mutex joint_state_mutex_;
  std::map<std::string, double> current_joint_positions_;
  std::map<std::string, double> current_joint_velocities_;

  std::mutex execution_mutex_;
  ExecutionMonitor execution_monitor_;
  std::optional<TrajectoryBundle> cached_cartesian_bundle_;

  std::random_device random_device_;
  std::mt19937 random_generator_;

  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
  rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr moveit_auto_switch_trigger_pub_;
  rclcpp::Service<CommonStreamRos2>::SharedPtr joint_space_control_srv_;
  rclcpp::Service<CommonStreamRos2>::SharedPtr dual_arm_waypoints_srv_;
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr controller_enable_srv_;
  rclcpp::CallbackGroup::SharedPtr controller_switch_callback_group_;
  rclcpp::Client<controller_manager_msgs::srv::SwitchController>::SharedPtr
    activate_controller_client_;
  rclcpp::Client<controller_manager_msgs::srv::ListControllers>::SharedPtr
    list_controllers_client_;
  rclcpp::Client<controller_manager_msgs::srv::SwitchController>::SharedPtr switch_controller_client_;

  rclcpp_action::Client<FollowJointTrajectory>::SharedPtr left_action_client_;
  rclcpp_action::Client<FollowJointTrajectory>::SharedPtr right_action_client_;

  rclcpp::Client<CommonStreamRos2>::SharedPtr waypoints_service_report_client_;
  rclcpp::Client<CommonStreamRos2>::SharedPtr joint_service_report_client_;
  rclcpp_action::Client<ReportMotion>::SharedPtr waypoints_action_report_action_client_;
  rclcpp_action::Client<ReportMotion>::SharedPtr joint_action_report_action_client_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
};

}  // namespace arm_lite_planner

#endif  // ARM_LITE_PLANNER__ARM_LITE_PLANNER_HPP_
