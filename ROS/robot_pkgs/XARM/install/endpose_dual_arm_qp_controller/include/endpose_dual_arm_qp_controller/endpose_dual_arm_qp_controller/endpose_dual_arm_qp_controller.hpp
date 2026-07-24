#ifndef JOINTSPACE_LPF_CONTROLLER_HPP_
#define JOINTSPACE_LPF_CONTROLLER_HPP_
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <fmt/core.h>
#include "endpose_dual_arm_qp_controller/visibility_control.h"
#include "endpose_dual_arm_qp_controller_parameters.hpp"
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
#include "RMPflow/all.hpp"
#include "RMPflow/Model/Tianyi.hpp"
#include "SE3OTG/all.hpp"
#include "mr/modern_robotics.h"
#include <pinocchio/parsers/sample-models.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>

#include "eai_manipulator_msgs/msg/dual_arm_target_pose.hpp"
#include "eai_manipulator_msgs/msg/warn_and_error_info.hpp"
#include <OsqpEigen/OsqpEigen.h>

#define CLASS_NAME "EndposeDualArmQpController"
namespace pin = pinocchio;

namespace endpose_dual_arm_qp_controller {
using CmdType = eai_manipulator_msgs::msg::DualArmTargetPose;

class EndposeDualArmQpController
    : public controller_interface::ControllerInterface {
  public:
    CONTROLLER__VISIBILITY_PUBLIC
    EndposeDualArmQpController();

    CONTROLLER__VISIBILITY_PUBLIC
    ~EndposeDualArmQpController() = default;

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
    std::map<int, int>
        command_to_pinocchio_map_; // 将command中的idx映射为pinocchio中的idx

    std::shared_ptr<endpose_dual_arm_qp_controller::ParamListener>
        param_listener_;
    endpose_dual_arm_qp_controller::Params params_;

    realtime_tools::RealtimeBuffer<std::shared_ptr<CmdType>> rt_buffer_ptr_;
    rclcpp::Subscription<CmdType>::SharedPtr command_subscriber_;

    // internal methods
    controller_interface::CallbackReturn configure_parameters();

    ruckig::Ruckig<14> otg{0.002};
    ruckig::InputParameter<14> ruckig_input;
    ruckig::OutputParameter<14> ruckig_output;

    Eigen::Matrix4d
        Tsb_L; // 目标位姿，腰部到法兰盘, s系是waist_yaw_link，b系是法兰盘
    Eigen::Matrix4d
        Tsb_R; // 目标位姿，腰部到法兰盘, s系是waist_yaw_link，b系是法兰盘

    Eigen::Matrix4d T_waist_yaw_select;  // 腰部到选定的坐标系
    Eigen::Matrix4d T_wrist_roll_select; // 末端到选定的坐标系
    // Eigen::Matrix4d T_wrist_roll_select;    // 末端到选定的坐标系

    Eigen::Matrix4d TargetInputPose_L;
    Eigen::Matrix4d TargetInputPose_R;
    std::string from_frame_L{};
    std::string from_frame_R{};

    std::string to_frame_L{};
    std::string to_frame_R{};

    Eigen::Vector3d endpose_offset_L;
    Eigen::Vector3d endpose_offset_R;

    // std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    // std::unique_ptr<tf2_ros::TransformListener> tf_listener_;

    Eigen::Matrix4d T_current_save_L; // 用于保存跟踪过程中的当前位姿
    Eigen::Matrix4d T_current_save_R; // 用于保存跟踪过程中的当前位姿

    // temp use
    std::vector<double> appCommand_;

    pin::Model model_;
    pinocchio::Data data_;

    pin::Model model1_;
    pinocchio::Data data1_;

    RMP::model::ScrewModel arm_model, model_x, model_y, model_z;
    RMP::model::ScrewModel model_link2, model_link4, model_link7;

    std::vector<RMP::model::ScrewModel>
        collision_model_vec;                  // 手臂上的碰撞球信息
    std::vector<double> collision_sphere_vec; // 碰撞球半径

    std::atomic<bool> collision_check_{false};

    SE3OTG::SE3_fix_step se3otg_L;
    SE3OTG::SE3_fix_step se3otg_R;

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
    Eigen::MatrixXd
    projectToNullSpace(const Eigen::MatrixXd &Ja, const Eigen::MatrixXd &Jb);

    bool last_is_dual_arm_syn_ = false; // 上一周期的同步模式状态
    Eigen::Matrix4d mat_r2l_;        // 双臂相对位姿（右臂到左臂）
    Eigen::Matrix4d mat_r2l_now;     // 双臂相对位姿（右臂到左臂）
    Eigen::MatrixXd jacobian_R_in_L; // 右臂在左臂坐标系下的雅可比
    bool current_is_syn = false;
    std::ofstream filetest;
    // std::string filePath1 = "test.txt";
    // add
    //  collision
    void updateCollision(Eigen::VectorXd &nowq);
    void clamp_theta_to_joint_limits();
    Eigen::VectorXd interfaceWQP(
        Eigen::VectorXd &nowq, Eigen::VectorXd &error, double ctrl_period);
    Eigen::VectorXd
    WQP(const Eigen::MatrixXd &Jl,
        const Eigen::MatrixXd &Jr,
        Eigen::VectorXd &car_err,
        const Eigen::VectorXd &nowQ,
        const Eigen::VectorXd &Qr,
        double ctrl_period);
    // Eigen::VectorXd m_jacobL;
    // rmp
    struct RMPMetricParams {
        double sigma_a = 0.1;
        double alpha_min = 0.50;
        double sigma_b = 0.9;   // 控制 beta 的尺度（越大衰减越慢）
        double b_gain = 1200.0; // d≈0 时放大倍数
        double mu_near = 3.0;
        double mu_far = 0.0;
        double eps_norm = 1e-9;
        // 新增
        double beta_p = 1.0; // β 的幂指数（等效于 1/(1+(d/σ)^p) 里 p）
        double gamma = 2.0; // 强化小误差区（β^gamma）
        double min_scale = 1000.0; // 最小放大（>1 则远端也保留一定权重）
    };

    // 模仿 nvida 的 RMP
    // 设计（让误差小的拥有较高权重保持精度，误差大的拥有较低权重但不会低于阈值，大误差也不会由突变的速度）
    // 位置误差的 RMP 度量函数
    // err: 位置误差向量
    // p: RMPMetricParams 结构体，包含参数
    Eigen::MatrixXd rmpMetricPos(
        const Eigen::Ref<const Eigen::VectorXd> &err,
        const RMPMetricParams &p) {
        const int N = static_cast<int>(err.size());
        const double d2 = err.squaredNorm();
        const double d = std::sqrt(d2);
        // α 可以先固定为 1：仅用
        // mu_near（各向同性）。若想远端各向异性，放开注释并设 mu_far>mu_near
        const double alpha = 1.0;
        // const double alpha = (1.0 - p.alpha_min) * std::exp(-d2 / (2.0 *
        // p.sigma_a * p.sigma_a))
        //                    + p.alpha_min;
        // ---- 改 1：使用“重尾”的 β： 1 / (1 + (d/σ)^p)
        // p.beta_p 越小（>=1），衰减越慢；sigma_b 越大，衰减越慢
        const double denom =
            1.0 + std::pow(d / std::max(p.sigma_b, 1e-12), p.beta_p);
        double beta = 1.0 / denom;
        // ---- 改 2：γ 次幂，进一步凸显“小误差=大权重”
        beta = std::pow(beta, p.gamma);
        // 单位方向、投影
        Eigen::VectorXd n = err;
        if (d > p.eps_norm) n /= d;
        else {
            n.setZero(N);
            n(0) = 1.0;
        }
        const Eigen::MatrixXd S = n * n.transpose();
        const Eigen::MatrixXd M_near =
            p.mu_near * Eigen::MatrixXd::Identity(N, N);
        const Eigen::MatrixXd M_far = p.mu_far * S;
        const Eigen::MatrixXd M_mix = alpha * M_near + (1.0 - alpha) * M_far;
        // 原来是 1 与 b_gain 间插值；这里保留，但加入最小下限
        double scale = 1.0 + (p.b_gain - 1.0) * beta;
        scale =
            std::max(scale, p.min_scale); // ---- 改 3：保证远端权重不至于太小
        Eigen::MatrixXd M = scale * M_mix;
        M.diagonal().array() += 1e-12; // SPD 保底
        return M;
    }

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
} // namespace endpose_dual_arm_qp_controller

#endif