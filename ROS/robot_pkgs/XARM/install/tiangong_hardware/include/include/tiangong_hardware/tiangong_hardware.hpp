
#ifndef TIANGONG_HARDWARE_HPP_
#define TIANGONG_HARDWARE_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/clock.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp/logger.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"


#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/node_options.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "bodyctrl_msgs/msg/motor_status_msg.hpp"
#include "bodyctrl_msgs/msg/cmd_set_motor_position.hpp"
#include "bodyctrl_msgs/msg/set_motor_position.hpp"
#include "bodyctrl_msgs/msg/cmd_set_motor_speed.hpp"
#include "bodyctrl_msgs/msg/cmd_motor_ctrl.hpp"
#include "bodyctrl_msgs/msg/motor_ctrl.hpp"

#include "eai_manipulator_msgs/srv/mode.hpp"
#include "eai_manipulator_msgs/srv/info.hpp"

#include "tiangong_hardware/control_algorithm.hpp"


namespace tiangong_hardware
{
class TiangongHardware : public hardware_interface::SystemInterface{
public:
    RCLCPP_SHARED_PTR_DEFINITIONS(TiangongHardware)

    hardware_interface::CallbackReturn on_init(
        const hardware_interface::HardwareInfo & info) override;

    std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

    std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;


    hardware_interface::return_type prepare_command_mode_switch(
        const std::vector<std::string> & start_interfaces,
        const std::vector<std::string> & stop_interfaces) override;

    hardware_interface::return_type perform_command_mode_switch(
        const std::vector<std::string> & start_interfaces,
        const std::vector<std::string> & stop_interfaces) override;


    hardware_interface::CallbackReturn on_activate(
        const rclcpp_lifecycle::State & previous_state) override;

    hardware_interface::CallbackReturn on_deactivate(
        const rclcpp_lifecycle::State & previous_state) override;

    hardware_interface::return_type read(
        const rclcpp::Time & time, const rclcpp::Duration & period) override;

    hardware_interface::return_type write(
        const rclcpp::Time & time, const rclcpp::Duration & period) override;
    /// Get the logger of the SystemInterface.
    /**
     * \return logger of the SystemInterface.
     */
    rclcpp::Logger get_logger() const { return *logger_; }

    /// Get the clock of the SystemInterface.
    /**
     * \return clock of the SystemInterface.
     */
    rclcpp::Clock::SharedPtr get_clock() const { return clock_; }

private:
    // Parameters
    double hw_start_sec_;
    double hw_stop_sec_;
    double hw_slowdown_;

    // Objects for logging
    std::shared_ptr<rclcpp::Logger> logger_;
    rclcpp::Clock::SharedPtr clock_;

    // Store the commands 
    std::vector<double> hw_commands_positions_;
    std::vector<double> hw_commands_velocities_;
    std::vector<double> hw_commands_efforts_;

    // Store the states
    std::vector<std::string> hw_states_names_;
    std::vector<double> hw_states_positions_;
    std::vector<double> hw_states_velocities_;
    std::vector<double> hw_states_efforts_;

    double start_time;

    
    // Enum defining at which control level we are
    // Dumb way of maintaining the command_interface type per joint.
    enum integration_level_t : std::uint8_t
    {
        UNDEFINED = 0,
        POSITION = 1,
        VELOCITY = 2,
        ACCELERATION = 3
    };

    // Active control mode for each actuator
    std::vector<integration_level_t> control_level_;


    // 天轶硬件相关
    rclcpp::Node::SharedPtr node_;

    // 订阅机器人状态
    rclcpp::Subscription<bodyctrl_msgs::msg::MotorStatusMsg>::SharedPtr arm_state_sub;
    rclcpp::Subscription<bodyctrl_msgs::msg::MotorStatusMsg>::SharedPtr head_state_sub;

    // 发布机器人命令
    bool use_pd_mode_ = true;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr arm_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr arm_pd_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr arm_vel_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr head_publisher_;

    // 订阅机器人命令用于检测避免和其他topic冲突
    rclcpp::TimerBase::SharedPtr external_publisher_check_timer_;  // 定时检测外部发布者

    void arm_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);
    void head_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);

    void arm_cmd_pos_callback(const bodyctrl_msgs::msg::CmdSetMotorPosition::SharedPtr msg);
    void arm_cmd_ctrl_callback(const bodyctrl_msgs::msg::CmdMotorCtrl::SharedPtr msg);

    // 检测外部发布者的方法
    rclcpp::Subscription<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr arm_cmd_pos_sub_;
    rclcpp::Subscription<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr arm_cmd_ctrl_sub_;
    std::atomic<int> arm_cmd_received{0};
    std::atomic<int> arm_cmd_send_count{0};
    


    void check_external_publishers();
    std::atomic<bool> external_arm_cmd_publisher_exists{false};   // 是否有外部发布者发布 arm cmd
    std::atomic<bool> external_head_cmd_publisher_exists{false};  // 是否有外部发布者发布 head cmd

    sensor_msgs::msg::JointState arm_state;
    sensor_msgs::msg::JointState head_state;

    
    std::atomic<bool> get_arm_state;
    std::atomic<bool> get_head_state;
    
    std::atomic<bool> arm_enable{false};
    bool arm_enable_last{false};
    std::atomic<bool> head_enable{false};
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_arm_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_head_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_all_enable_service_;

    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_arm_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_head_enable_service_;
    

    std::atomic<int> send_count_after_disable{0};
    std::atomic<uint64_t> enable_count{0};
    std::atomic<int> body_control_watchdog{10};

    // 机械臂工作模式 0：柔顺 1：高刚度 2：重力补偿 3:位置
    // 4 左手柔顺右手位置 5 左手位置右手柔顺
    std::atomic<int> arm_mode_{0};  
    int arm_mode_last{0};
    

    rclcpp::Service<eai_manipulator_msgs::srv::Mode>::SharedPtr set_arm_mode_service_;
    rclcpp::Service<eai_manipulator_msgs::srv::Mode>::SharedPtr get_arm_mode_service_;
    
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_cb_handle_;
    std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> parameters_interface_;


    rclcpp::Service<eai_manipulator_msgs::srv::Info>::SharedPtr debug_service_;  
    
    std::vector<double> current_value_;
    std::vector<double> kp_;
    std::vector<double> kd_;
    std::vector<double> kt_;
    double kp_velocity;

    ControlAlgorithm algo;

};


}  // namespace tiangong_hardware

#endif  // TIANGONG_HARDWARE_HPP_
