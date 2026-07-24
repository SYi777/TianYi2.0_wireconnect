#ifndef JOINTSPACE_LPF_CONTROLLER_HPP_
#define JOINTSPACE_LPF_CONTROLLER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "endpose_body_controller/visibility_control.h"
#include "endpose_body_controller/endpose_body_controller_parameters.hpp"

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
#include "eai_manipulator_msgs/msg/warn_and_error_info.hpp"
#include "Eigen/Dense"

#include "eai_manipulator_msgs/action/joint_space.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <mutex>


#define CLASS_NAME "EndposeBodyController"

namespace endpose_body_controller
{
using CmdType = std_msgs::msg::Float64MultiArray;


struct SolveResult {
    double q1, q2, q3, q4;
    bool converged;
    int iters;
    double final_err;        // residual L2
    // 新增：正解结果与逐项误差
    double x, z, pit;        // achieved
    double ex, ez, epit;     // errors = target - achieved
};


class EndposeBodyController : public controller_interface::ControllerInterface
{
public:
    CONTROLLER__VISIBILITY_PUBLIC
    EndposeBodyController();

    CONTROLLER__VISIBILITY_PUBLIC
    ~EndposeBodyController() = default;
    
    
    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_init() override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::InterfaceConfiguration command_interface_configuration() const override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::InterfaceConfiguration state_interface_configuration() const override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_cleanup(
        const rclcpp_lifecycle::State & previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_configure(
        const rclcpp_lifecycle::State & previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_activate(
        const rclcpp_lifecycle::State & previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::CallbackReturn on_deactivate(
        const rclcpp_lifecycle::State & previous_state) override;

    CONTROLLER__VISIBILITY_PUBLIC
    controller_interface::return_type update(
        const rclcpp::Time & time, const rclcpp::Duration & period) override;

    protected:
        controller_interface::CallbackReturn read_parameters();

        std::vector<std::string> joint_names_;
        std::string interface_name_;
        int arm_idx;
        std::vector<double> joint_upper_limits = {};
        std::vector<double> joint_lower_limits = {};
        std::vector<std::string> command_interface_types_;

        std::shared_ptr<endpose_body_controller::ParamListener> param_listener_;
        endpose_body_controller::Params params_;

        realtime_tools::RealtimeBuffer<std::shared_ptr<CmdType>> rt_buffer_ptr_;
        rclcpp::Subscription<CmdType>::SharedPtr command_subscriber_;


            // Action server
        using JointSpaceAction = eai_manipulator_msgs::action::JointSpace;
        rclcpp_action::Server<JointSpaceAction>::SharedPtr action_server_;
        std::shared_ptr<rclcpp_action::ServerGoalHandle<JointSpaceAction>>
            active_goal_handle_;
        std::mutex active_goal_mutex_;
        std::atomic<bool> action_new_goal_received_;

        // Action server callbacks
        rclcpp_action::GoalResponse handle_goal(
            const rclcpp_action::GoalUUID &uuid,
            std::shared_ptr<const JointSpaceAction::Goal> goal);

        rclcpp_action::CancelResponse handle_cancel(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<JointSpaceAction>>
                goal_handle);

        void handle_accepted(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<JointSpaceAction>>
                goal_handle);


        // internal methods
        controller_interface::CallbackReturn configure_parameters();


        ruckig::Ruckig<7> otg{0.002};
        ruckig::InputParameter<7> ruckig_input;
        ruckig::OutputParameter<7> ruckig_output;

        std::array<double, 7> action_goal_pos{};

        std::atomic<int> working_mode{0}; // 0为从topic收数据 1为从action

        

        Eigen::Vector3d forward_kinematics_xz_pitch(double q1, double q2, double q3);
        SolveResult solve_ik(double x, double z, double pitch, double yaw);
        double cmd_x, cmd_z, cmd_pitch, cmd_yaw;
        double prime_cmd_x,prime_cmd_z,prime_cmd_pitch,prime_cmd_yaw;

        //temp use
        std::vector<double> appCommand_;
        std::vector<double> joint_command_start_pos_; //控制器激活时的指令位置，用于作为控制的起点，保证连续性


    private:



        rclcpp::Publisher<eai_manipulator_msgs::msg::WarnAndErrorInfo>::SharedPtr warn_and_error_info_publisher_;
        std::string get_info_name()
        {
            std::string name;
            name += CLASS_NAME;
            if (this->arm_idx == 0)
                name += "_left_arm";
            else if (this->arm_idx == 1)
                name += "_right_arm";
            else if (this->arm_idx == 2)
                name += "_body";
            else if (this->arm_idx == 3)
                name += "_head";
            else{

            }
            return name;
        }
        void pub_info_msg(std::string level, int code, std::string info)
        {
            if(!warn_and_error_info_publisher_)
            {
                warn_and_error_info_publisher_ = get_node()->create_publisher<eai_manipulator_msgs::msg::WarnAndErrorInfo>("/manipulator/warn_and_error_info", rclcpp::SystemDefaultsQoS());
            }
            // 从warn_and_error_info_publisher_发布信息
            if (warn_and_error_info_publisher_ && warn_and_error_info_publisher_->get_subscription_count() > 0) {
                eai_manipulator_msgs::msg::WarnAndErrorInfo msg;
                msg.header.stamp = get_node()->now();
                msg.header.frame_id = "";
                msg.level = level;
                msg.code = code;
                msg.source = get_info_name();
                msg.info = info;
                warn_and_error_info_publisher_->publish(msg);
            }
        }

        void pub_info_msg(int code, std::string info)
        {
            pub_info_msg("info", code, info);
        }
        void pub_warn_msg(int code, std::string info)
        {
            pub_info_msg("warn", code, info);
        }
        void pub_error_msg(int code, std::string info)
        {
            pub_info_msg("error", code, info);
        }
};
} //JOINTSPACE_LPF_CONTROLLER_HPP_


#endif