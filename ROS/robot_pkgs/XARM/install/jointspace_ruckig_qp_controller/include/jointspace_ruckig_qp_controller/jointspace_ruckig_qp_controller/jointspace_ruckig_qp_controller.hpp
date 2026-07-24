#ifndef JOINTSPACE_LPF_CONTROLLER_HPP_
#define JOINTSPACE_LPF_CONTROLLER_HPP_

#include <memory>
#include <string>
#include <vector>
#include <fmt/core.h>
#include "jointspace_ruckig_qp_controller/visibility_control.h"
#include "jointspace_ruckig_qp_controller/jointspace_ruckig_qp_controller_parameters.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
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
#include "geometry_msgs/msg/pose.hpp"
#include "Eigen/Dense"
#include "rmpflow2/all.hpp"
// #include "RMPflow/Model/Tianyi.hpp"
#include "SE3OTG/all.hpp"
#include "mr/modern_robotics.h"
#include <pinocchio/parsers/sample-models.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>

#include "eai_manipulator_msgs/msg/arm_target_pose.hpp"
#include "eai_manipulator_msgs/msg/warn_and_error_info.hpp"
#include <OsqpEigen/OsqpEigen.h>

#define CLASS_NAME "JointspaceRuckigQpController"
namespace pin = pinocchio;

namespace jointspace_ruckig_qp_controller {
using CmdType = std_msgs::msg::Float64MultiArray;

class JointspaceRuckigQpController
    : public controller_interface::ControllerInterface {
  public:
    CONTROLLER__VISIBILITY_PUBLIC
    JointspaceRuckigQpController();

    CONTROLLER__VISIBILITY_PUBLIC
    ~JointspaceRuckigQpController() = default;

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
    int robot_idx;
    int robot_dof;

    int numTest = 0;
    Eigen::Vector<double, 14> joint_upper_limits;
    Eigen::Vector<double, 14> joint_lower_limits;
    Eigen::Vector<double, 14> speed_limits;
    Eigen::Vector<double, 14> acc_limits;

    Eigen::Vector<double, 14> joint_home_pos;
    double dis_err_bound{0.2};
    double ori_err_bound{1.0};
    std::vector<std::string> command_interface_types_;
    std::vector<std::string> state_interface_types_;
    std::map<int, int>
        command_to_state_map_; // 将command中的idx映射为state中的idx
    std::map<int, int>
        state_to_pinocchio_map_; // 将state中的idx映射为pinocchio中的idx
    std::map<int, int> command_to_pinocchio_map_;
    std::shared_ptr<jointspace_ruckig_qp_controller::ParamListener>
        param_listener_;
    jointspace_ruckig_qp_controller::Params params_;

    realtime_tools::RealtimeBuffer<std::shared_ptr<CmdType>> rt_buffer_ptr_;
    rclcpp::Subscription<CmdType>::SharedPtr command_subscriber_;

    // internal methods
    controller_interface::CallbackReturn configure_parameters();

    ruckig::Ruckig<14> otg{0.004};
    ruckig::InputParameter<14> ruckig_input;
    ruckig::OutputParameter<14> ruckig_output;
    ruckig::Result last_res;

    Eigen::Matrix4d
        Tsb; // 目标位姿，腰部到法兰盘, s系是waist_yaw_link，b系是法兰盘
    Eigen::Matrix4d T_waist_yaw_select;  // 腰部到选定的坐标系
    Eigen::Matrix4d T_wrist_roll_select; // 末端到选定的坐标系
    Eigen::Matrix4d TargetInputPose;
    std::string from_frame{};
    std::string to_frame{};
    Eigen::Vector3d endpose_offset;
    // std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    // std::unique_ptr<tf2_ros::TransformListener> tf_listener_;

    Eigen::Matrix4d T_current_save; // 用于保存跟踪过程中的当前位姿

    // temp use
    std::vector<double> appCommand_;

    pin::Model model_;
    pinocchio::Data data_;

    pin::Model model1_;
    pinocchio::Data data1_;

    RMP::model::PinocchioModel rmp_model;
    Eigen::VectorXd q_rmp, v_rmp, a_rmp;

    // RMP::model::ScrewModel arm_model, model_x, model_y, model_z;
    // RMP::model::ScrewModel model_link2, model_link4, model_link7;

    // std::vector<RMP::model::ScrewModel> collision_model_vec;    //
    // 手臂上的碰撞球信息 std::vector<double> collision_sphere_vec; //
    // 碰撞球半径

    std::atomic<bool> collision_check_{false};

    SE3OTG::SE3_fix_step se3otg;

    Eigen::Vector<double, 14> theta, speed, acc;

    Eigen::VectorXd theta_robot,
        speed_robot; // 机器人全体关节角和角速度，当前真实值
    Eigen::VectorXd q_pin, v_pin, a_pin;

    Eigen::VectorXd m_testlp;
    Eigen::MatrixXd m_test_conA;
    Eigen::VectorXd last_resultQP;
    double safe_d = 0.02;

  private:
    void read_waist_yaw_select_from_param();
    void read_wrist_roll_select_from_param();

    void updateCollision(Eigen::VectorXd &nowq);
    Eigen::VectorXd WQP(const Eigen::VectorXd &nowQ, const Eigen::VectorXd &Qr);
    rclcpp::Publisher<eai_manipulator_msgs::msg::WarnAndErrorInfo>::SharedPtr
        warn_and_error_info_publisher_;
    std::string get_info_name() {
        std::string name;
        name += CLASS_NAME;
        if (this->arm_idx == 0) name += "_left_arm";
        else if (this->arm_idx == 1)
            name += "_right_arm";
        else if (this->arm_idx == 2)
            name += "_body";
        else if (this->arm_idx == 3)
            name += "_head";
        else if (this->arm_idx == 4)
            name += "_dual_arm";
        else if (this->arm_idx == 5)
            name += "_waist_pitch";
        else if (this->arm_idx == 6)
            name += "_waist_yaw";
        else {}
        return name;
    }
    void pub_info_msg(std::string level, int code, std::string info) {
        if (!warn_and_error_info_publisher_) {
            warn_and_error_info_publisher_ =
                get_node()
                    ->create_publisher<
                        eai_manipulator_msgs::msg::WarnAndErrorInfo>(
                        "/manipulator/warn_and_error_info",
                        rclcpp::SystemDefaultsQoS());
        }
        // 从warn_and_error_info_publisher_发布信息
        if (warn_and_error_info_publisher_
            && warn_and_error_info_publisher_->get_subscription_count() > 0) {
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

    void pub_info_msg(int code, std::string info) {
        pub_info_msg("info", code, info);
    }
    void pub_warn_msg(int code, std::string info) {
        pub_info_msg("warn", code, info);
    }
    void pub_error_msg(int code, std::string info) {
        pub_info_msg("error", code, info);
    }

    void update_current_data_from_robot();
};
} // namespace jointspace_ruckig_qp_controller

#endif