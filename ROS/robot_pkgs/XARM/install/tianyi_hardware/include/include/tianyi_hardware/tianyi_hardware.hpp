
#ifndef TIANYI_HARDWARE_HPP_
#define TIANYI_HARDWARE_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "eai_manipulator_msgs/msg/warn_and_error_info.hpp"
#include "rclcpp/clock.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp/logger.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"

#include "mutex"
#include "realtime_tools/mutex.hpp"
#include "realtime_tools/realtime_buffer.hpp"

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
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include "bodyctrl_msgs/msg/cmd_set_motor_cur_tor.hpp"
#include "bodyctrl_msgs/msg/set_motor_cur_tor.hpp"
#include "ruckig/ruckig.hpp"

#include "eai_manipulator_msgs/srv/mode.hpp"
#include "eai_manipulator_msgs/srv/info.hpp"

#include "tianyi_hardware/control_algorithm.hpp"
#include "tianyi_hardware/stability_checker.hpp"
// #include "tianyi_hardware/xarm_torch.hpp"

#define CLASS_NAME "TianyiHardware"

namespace tianyi_hardware
{
class TianyiHardware : public hardware_interface::SystemInterface{
public:
    RCLCPP_SHARED_PTR_DEFINITIONS(TianyiHardware)

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
        
    const std::string& getRobotType() const { return robot_type;}
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
    std::vector<double> hw_left_ft_snesor_;
    std::vector<double> hw_right_ft_snesor_;
    std::vector<double> last_joint_commands; // 上一个周期接收的关节位置指令值
    std::vector<double> joint_commands; // 当前接收到的关节位置指令值
    std::string robot_type;
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
    rclcpp::Subscription<bodyctrl_msgs::msg::MotorStatusMsg>::SharedPtr waist_state_sub;
    rclcpp::Subscription<bodyctrl_msgs::msg::MotorStatusMsg>::SharedPtr leg_state_sub;
    rclcpp::Subscription<geometry_msgs::msg::WrenchStamped>::SharedPtr left_ft_sensor_sub;
    rclcpp::Subscription<geometry_msgs::msg::WrenchStamped>::SharedPtr right_ft_sensor_sub;

    // 发布机器人命令
    bool use_pd_mode_ = true;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr arm_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr arm_pd_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr arm_vel_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr head_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr waist_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr leg_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorCurTor>::SharedPtr arm_cur_publisher_;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr arm_publisher_debug;
    rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr arm_pd_publisher_debug;

    // 定期检测外部发布者
    rclcpp::TimerBase::SharedPtr external_publisher_check_timer_;

    // 检测外部发布者的方法
    void check_external_publishers();
    std::atomic<bool> external_arm_cmd_publisher_exists{false};    // 是否有外部发布者发布 arm cmd
    std::atomic<bool> external_head_cmd_publisher_exists{false};   // 是否有外部发布者发布 head cmd
    std::atomic<bool> external_waist_cmd_publisher_exists{false};  // 是否有外部发布者发布 waist cmd
    std::atomic<bool> external_leg_cmd_publisher_exists{false};     // 是否有外部发布者发布 leg cmd

    void arm_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);
    void head_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);
    void waist_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);
    void leg_state_callback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);
    void left_ft_sensor_callback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg);
    void right_ft_sensor_callback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg);
    
    sensor_msgs::msg::JointState arm_state;
    sensor_msgs::msg::JointState head_state;
    sensor_msgs::msg::JointState waist_state;
    sensor_msgs::msg::JointState leg_state;

    std::mutex arm_state_mutex;
    std::mutex head_state_mutex;
    std::mutex waist_state_mutex;
    std::mutex leg_state_mutex;

    std::vector<double> left_ft_sensor;
    std::vector<double> right_ft_sensor;

    
    std::atomic<bool> get_arm_state;
    std::atomic<bool> get_head_state;
    std::atomic<bool> get_waist_state;
    std::atomic<bool> get_leg_state;
    std::atomic<bool> get_left_ft_sensor;
    std::atomic<bool> get_right_ft_sensor;
    
    std::atomic<bool> arm_enable{false};
    bool arm_enable_last{false};
    std::atomic<bool> waist_enable{false};
    std::atomic<bool> leg_enable{false};
    std::atomic<bool> head_enable{false};
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_arm_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_waist_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_leg_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_head_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr set_all_enable_service_;

    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_arm_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_waist_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_leg_enable_service_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr get_head_enable_service_;


    

    std::atomic<int> send_count_after_disable{0};       // 初始化为0，避免启动时下发数据
    std::atomic<uint64_t> enable_count{0};
    std::atomic<int> body_control_watchdog{10};

    std::atomic<int> arm_mode_{0};  // 机械臂工作模式 0：柔顺 1：高刚度 2：重力补偿
    int arm_mode_last{0};
    rclcpp::Service<eai_manipulator_msgs::srv::Mode>::SharedPtr set_arm_mode_service_;  
    rclcpp::Service<eai_manipulator_msgs::srv::Mode>::SharedPtr get_arm_mode_service_;  

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_cb_handle_;
    std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> parameters_interface_;


    rclcpp::Service<eai_manipulator_msgs::srv::Info>::SharedPtr debug_service_;  

    float leg1_pos;
    std::vector<double> current_value_;
    std::vector<double> kp_;
    std::vector<double> kd_;
    std::vector<double> kt_;
    std::vector<double> leg_waist_spd; // 51 52 31 32
    std::vector<double> vel_ruckig; // 51 52 31 32
    double kp_velocity;
    double safety_margin;

    ControlAlgorithm algo;

    rclcpp::Publisher<eai_manipulator_msgs::msg::WarnAndErrorInfo>::SharedPtr
        warn_and_error_info_publisher_;

    std::unique_ptr<StaticStabilityChecker> checker_;

    std::unique_ptr<ruckig::Ruckig<21>> otg_joint;
    ruckig::InputParameter<21> input_joint;
    ruckig::OutputParameter<21> output_joint;

    // xarm_torch::ModelWrapper arm_left_model;
    // xarm_torch::ModelWrapper arm_right_model;

};


}  // namespace tianyi_hardware

#endif  // TIANYI_HARDWARE_HPP_
