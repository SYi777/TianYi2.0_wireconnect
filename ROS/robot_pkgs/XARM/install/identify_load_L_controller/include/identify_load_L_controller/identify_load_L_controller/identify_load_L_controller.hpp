#ifndef JOINTSPACE_LPF_CONTROLLER_HPP_
#define JOINTSPACE_LPF_CONTROLLER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "identify_load_L_controller/visibility_control.h"
#include "identify_load_L_controller/identify_load_L_controller_parameters.hpp"

#include "controller_interface/controller_interface.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_buffer.hpp"
#include "realtime_tools/lock_free_queue.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "control_msgs/msg/multi_dof_command.hpp"
#include "control_msgs/msg/multi_dof_state_stamped.hpp"
#include "control_toolbox/pid_ros.hpp"
#include "controller_interface/controller_interface.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_buffer.hpp"
#include "realtime_tools/realtime_publisher.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include "control_msgs/msg/joint_controller_state.hpp"
#include "control_msgs/msg/pid_state.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "ruckig/ruckig.hpp"
#include "identify_load_L_controller/HumanoidRobot.h"

namespace identify_load_L_controller {
using CmdType = std_msgs::msg::Float64MultiArray;

class IdentifyLoadLController
    : public controller_interface::ControllerInterface {
  public:
    CONTROLLER__VISIBILITY_PUBLIC
    IdentifyLoadLController();

    CONTROLLER__VISIBILITY_PUBLIC
    ~IdentifyLoadLController() = default;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_init() override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::InterfaceConfiguration
    command_interface_configuration() const override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::InterfaceConfiguration
    state_interface_configuration() const override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn
    on_cleanup(const rclcpp_lifecycle::State &previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn
    on_configure(const rclcpp_lifecycle::State &previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn
    on_activate(const rclcpp_lifecycle::State &previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn
    on_deactivate(const rclcpp_lifecycle::State &previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::return_type
    update(const rclcpp::Time &time, const rclcpp::Duration &period) override;

  protected:
    controller_interface::CallbackReturn read_parameters();

    std::vector<std::string> joint_names_;
    std::string interface_name_;
    int arm_idx;

    std::vector<double> joint_upper_limits = {};
    std::vector<double> joint_lower_limits = {};
    std::vector<std::string> command_interface_types_;
    std::vector<std::string> state_interface_types_;

    std::shared_ptr<identify_load_L_controller::ParamListener> param_listener_;
    identify_load_L_controller::Params params_;

    realtime_tools::RealtimeBuffer<std::shared_ptr<CmdType>> rt_buffer_ptr_;
    rclcpp::Subscription<CmdType>::SharedPtr joints_command_subscriber_;

    // internal methods
    controller_interface::CallbackReturn configure_parameters();

    ruckig::Ruckig<7> otg{0.002};
    ruckig::InputParameter<7> ruckig_input;
    ruckig::OutputParameter<7> ruckig_output;

    HumanoidRobot robot;

    std::vector<double> q_ident[6]; // 用于标定的关节角

    bool arrival = false;        // 是否到达过初始位置
    bool ident_complete = false; // 负载辨识是否完成
    bool print_once = false;
    bool get_initial_state = false;

    unsigned int record_count = 0;
    unsigned int arrival_count = 0;

    Eigen::VectorXd sensorDataAve[6];
    Eigen::VectorXd sensorDataSum[6];

    Eigen::MatrixXd forceMatrixGroup; // 公式6的矩阵
    Eigen::MatrixXd rotationGroup;    // 公式20的矩阵
    Eigen::VectorXd torqueGroup;
    Eigen::VectorXd forceGroup;

    Eigen::Vector3d forceZeroDrift;
    Eigen::Vector3d torqueZeroDrift;

    Eigen::Vector3d XYZ = {0.0, 0.0, 0.0};
    Eigen::Vector3d LxLyLz = {0.0, 0.0, 0.0};
    Eigen::Vector3d MgxMgyMgz = {0.0, 0.0, 0.0};

    const unsigned int arm_freedom = 7;

    KDL::Frame current_cartpos;

    // temp use
    std::vector<double> appCommand_;

  private:
};
} // namespace identify_load_L_controller

#endif