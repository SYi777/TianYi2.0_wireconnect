#ifndef FREQ_CHANGE_H
#define FREQ_CHANGE_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "bodyctrl_msgs/msg/motor_status_msg.hpp"
#include "bodyctrl_msgs/msg/cmd_set_motor_speed.hpp"
#include "bodyctrl_msgs/msg/cmd_set_motor_position.hpp"
#include "bodyctrl_msgs/msg/cmd_motor_ctrl.hpp"
#include <mutex>
#include <thread>
#include <atomic>

namespace freq_change
{
    class FreqChange : public rclcpp::Node
    {
    public:
        // 构造函数和析构函数
        FreqChange();
        ~FreqChange();

        // 初始化函数
        void myInit();

        // 频率更改相关函数
        bool freq_change();
        bool freq_change_loop(int mode);

        // 回调函数
        void JointStatesCallback_14(const sensor_msgs::msg::JointState::SharedPtr msg);
        void JointStatesCallback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg);

        // 发布函数
        void Joints_vel_Pub(int dof, int *iJointName, float *vel, float *current,
                           rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr pub);
        
        void Joints_pos_Pub(int dof, int *iJointName, float *pos, float *vel, float *current,
                           rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr pub);
        
        void Joints_mix_Pub(int dof, int *iJointName, float *fkp, float *fkd,
                           float *fPos, float *fSpeed, float *fTorque,
                           rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr pub);

    private:
        // 订阅者
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_joint_states_14dof_;
        rclcpp::Subscription<bodyctrl_msgs::msg::MotorStatusMsg>::SharedPtr sub_arm_states_14dof_;

        // 发布者
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr pub_arm_pos;
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr pub_arm_vel;
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr pub_arm_mix;
        
        // 备用发布者（可能用于不同模式）
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr pub_arm_pos_left;
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr pub_arm_pos_right;
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr pub_arm_vel_left;
        rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr pub_arm_vel_right;

        // 线程相关
        std::thread _freq_change_thread;
        std::mutex exit_mutex;
        std::atomic<bool> ifExit{false};

        // 互斥锁
        std::mutex left_arm_mutex;
        std::mutex right_arm_mutex;
        std::mutex left_arm_mutex_14;
        std::mutex right_arm_mutex_14;

        // 左臂状态变量
        float left_arm_current_pos[7] = {0};
        float left_arm_current_spd[7] = {0};
        float left_arm_last_pos_14[7] = {0};
        float left_arm_current_pos_14[7] = {0};
        float left_arm_current_spd_14[7] = {0};
        float left_last_send_pos[7] = {0};
        float left_last_send_spd[7] = {0};

        // 右臂状态变量
        float right_arm_current_pos[7] = {0};
        float right_arm_current_spd[7] = {0};
        float right_arm_last_pos_14[7] = {0};
        float right_arm_current_pos_14[7] = {0};
        float right_arm_current_spd_14[7] = {0};
        float right_last_send_pos[7] = {0};
        float right_last_send_spd[7] = {0};

        // 右臂限位参数
        float right_arm_max_limit[7] = {0};
        float right_arm_min_limit[7] = {0};

        // 时间和频率变量
        rclcpp::Time last_time_;
        double recFrequency = 0.0;

        // 配置参数
        int my_joint_state_topic = 3;
        int my_loop_rate = 200;
        int my_ctrl_mode = 3;
        double my_filter_parameter = 0.5;
        double my_pos_closed_loop_parameter = 10.0;

        // ID范围参数
        int my_head_start_id = 0;
        int my_head_id_num = 0;
        int my_left_arm_start_id = 0;
        int my_left_arm_id_num = 0;
        int my_right_arm_start_id = 0;
        int my_right_arm_id_num = 0;
        int my_waist_start_id = 0;
        int my_waist_id_num = 0;
        int my_left_leg_start_id = 0;
        int my_left_leg_id_num = 0;
        int my_right_leg_start_id = 0;
        int my_right_leg_id_num = 0;
    };
} // namespace freq_change

#endif // FREQ_CHANGE_H
    