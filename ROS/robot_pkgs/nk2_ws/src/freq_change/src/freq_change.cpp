#include "freq_change.h"
#include <chrono>
#include <thread>
#include <cmath>

using namespace std::chrono_literals;
using namespace freq_change;

// 移除WS2_32库引用（ROS 2 Linux环境不需要）

FreqChange::FreqChange() : Node("freq_change_node")
{
    RCLCPP_DEBUG(this->get_logger(), "Initializing node...");
    myInit();
    freq_change();
}

FreqChange::~FreqChange()
{
    exit_mutex.lock();
    ifExit = true;
    exit_mutex.unlock();

    if (_freq_change_thread.joinable())
    {
        _freq_change_thread.join();
    }
    RCLCPP_INFO(this->get_logger(), "Node destroyed");
}

void FreqChange::myInit()
{
    // 声明并获取参数（ROS 2参数API）
    this->declare_parameter<int>("joint_state_topic", 1);
    this->declare_parameter<int>("loop_rate", 200);
    this->declare_parameter<int>("ctrl_mode", 3);
    this->declare_parameter<double>("filter_parameter", 0.5);
    this->declare_parameter<double>("pos_closed_loop_parameter", 10.0);

    // 获取参数值
    my_joint_state_topic = this->get_parameter("joint_state_topic").as_int();
    my_loop_rate = this->get_parameter("loop_rate").as_int();
    my_ctrl_mode = this->get_parameter("ctrl_mode").as_int();
    my_filter_parameter = this->get_parameter("filter_parameter").as_double();
    my_pos_closed_loop_parameter = this->get_parameter("pos_closed_loop_parameter").as_double();

    RCLCPP_INFO(this->get_logger(), "my_joint_state_topic = %d", my_joint_state_topic);

    // 订阅关节状态话题（ROS 2订阅者创建方式）
    sub_joint_states_14dof_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states_flex_freq",
        2,
        std::bind(&FreqChange::JointStatesCallback_14, this, std::placeholders::_1));

    // 根据关节话题类型创建不同发布者
    // 自研手臂消息类型发布者
    pub_arm_pos = this->create_publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>(
        "/arm/cmd_pos", 10);
    pub_arm_vel = this->create_publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>(
        "/arm/cmd_vel", 10);
    pub_arm_mix = this->create_publisher<bodyctrl_msgs::msg::CmdMotorCtrl>(
        "/arm/cmd_ctrl", 10);

    // 订阅自研手臂状态
    sub_arm_states_14dof_ = this->create_subscription<bodyctrl_msgs::msg::MotorStatusMsg>(
        "/arm/status",
        2,
        std::bind(&FreqChange::JointStatesCallback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "myInit completed");
}

void FreqChange::JointStatesCallback_14(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    if (!msg)
    {
        RCLCPP_WARN(this->get_logger(), "Received empty JointState message.");
        return;
    }

    rclcpp::Time current_time = this->now();
    rclcpp::Duration duration = current_time - last_time_;

    // 计算接收频率
    if (duration.seconds() > 0)
    {
        recFrequency = 1.0 / duration.seconds();
    }
    last_time_ = current_time;

    size_t joint_count1 = msg->position.size();
    size_t joint_count2 = msg->velocity.size();

    if (joint_count1 == 14 && joint_count2 == 14)
    {
        for (int i = 0; i < 7; i++)
        {
            std::lock_guard<std::mutex> lock(left_arm_mutex_14);

            // 数据有效性检查
            if (std::isnan(left_arm_current_pos_14[i]) || std::isnan(msg->position[i]) ||
                std::isnan(msg->velocity[i]) || left_arm_current_pos_14[i] > 1000 ||
                msg->position[i] > 1000 || msg->velocity[i] > 1000)
            {
                return;
            }

            left_arm_last_pos_14[i] = left_arm_current_pos_14[i];
            left_arm_current_pos_14[i] = msg->position[i];
            left_arm_current_spd_14[i] = msg->velocity[i];
        }

        for (int i = 7; i < 14; i++)
        {
            std::lock_guard<std::mutex> lock(right_arm_mutex_14);

            // 数据有效性检查
            if (std::isnan(right_arm_current_pos_14[i - 7]) || std::isnan(msg->position[i - 7]) ||
                std::isnan(msg->velocity[i - 7]) || right_arm_current_pos_14[i - 7] > 1000 ||
                msg->position[i - 7] > 1000 || msg->velocity[i - 7] > 1000)
            {
                return;
            }

            right_arm_last_pos_14[i - 7] = right_arm_current_pos_14[i - 7];
            right_arm_current_pos_14[i - 7] = msg->position[i];
            right_arm_current_spd_14[i - 7] = msg->velocity[i];
        }
    }
    else if (joint_count1 == 16 && joint_count2 == 16)
    {
        for (int i = 0; i < 7; i++)
        {
            std::lock_guard<std::mutex> lock(left_arm_mutex_14);

            if (std::isnan(left_arm_current_pos_14[i]) || std::isnan(msg->position[i]) ||
                std::isnan(msg->velocity[i]) || left_arm_current_pos_14[i] > 1000 ||
                msg->position[i] > 1000 || msg->velocity[i] > 1000)
            {
                return;
            }

            left_arm_last_pos_14[i] = left_arm_current_pos_14[i];
            left_arm_current_pos_14[i] = msg->position[i];
            left_arm_current_spd_14[i] = msg->velocity[i];
        }

        for (int i = 8; i < 15; i++)
        {
            std::lock_guard<std::mutex> lock(right_arm_mutex_14);

            if (std::isnan(right_arm_current_pos_14[i - 8]) || std::isnan(msg->position[i - 8]) ||
                std::isnan(msg->velocity[i - 8]) || right_arm_current_pos_14[i - 8] > 1000 ||
                msg->position[i - 8] > 1000 || msg->velocity[i - 8] > 1000)
            {
                return;
            }

            right_arm_last_pos_14[i - 8] = right_arm_current_pos_14[i - 8];
            right_arm_current_pos_14[i - 8] = msg->position[i];
            right_arm_current_spd_14[i - 8] = msg->velocity[i];
        }
    }
    else
    {
        RCLCPP_WARN(this->get_logger(), "JointState dof is not 14 or 16");
        RCLCPP_INFO(this->get_logger(), "Received pos JointState with %zu joints.", joint_count1);
        RCLCPP_INFO(this->get_logger(), "Received vel JointState with %zu joints.", joint_count2);
    }
}

void FreqChange::JointStatesCallback(const bodyctrl_msgs::msg::MotorStatusMsg::SharedPtr msg)
{
    for (auto &motorStatus : msg->status)
    {
        // 处理左臂电机状态
        if (motorStatus.name >= 11 && motorStatus.name <= 17)
        {
            std::lock_guard<std::mutex> lock(left_arm_mutex);
            int idx = motorStatus.name - 11;
            left_arm_current_pos[idx] = motorStatus.pos;
            left_arm_current_spd[idx] = motorStatus.speed;
        }
        // 处理右臂电机状态
        else if (motorStatus.name >= 21 && motorStatus.name <= 27)
        {
            std::lock_guard<std::mutex> lock(right_arm_mutex);
            int idx = motorStatus.name - 21;
            right_arm_current_pos[idx] = motorStatus.pos;
            right_arm_current_spd[idx] = motorStatus.speed;
        }
    }
}

bool FreqChange::freq_change()
{
    if (_freq_change_thread.joinable())
    {
        RCLCPP_WARN(this->get_logger(), "_freq_change_thread is already running.");
        return false;
    }
    RCLCPP_INFO(this->get_logger(), "freq_change_loop start");
    _freq_change_thread = std::thread(std::bind(&FreqChange::freq_change_loop, this, my_ctrl_mode));
    return true;
}

bool FreqChange::freq_change_loop(int mode)
{
    RCLCPP_INFO(this->get_logger(), "freq_change_loop is running.");

    last_time_ = this->now();
    auto pub_arm = this->create_publisher<std_msgs::msg::Float64MultiArray>(
        "ArmReceiveCanData", 1000);
    std_msgs::msg::Float64MultiArray ArmReceiveCanData;
    ArmReceiveCanData.data.resize(6 * 7 + 1);

    rclcpp::Rate loop_rate(my_loop_rate);

    // 初始化发送位置
    for (int i = 0; i < 7; i++)
    {
        left_last_send_pos[i] = left_arm_current_pos[i];
        right_last_send_pos[i] = right_arm_current_pos[i];
    }

    if (mode == 4)
    {
        my_pos_closed_loop_parameter = 0;
    }

    while (rclcpp::ok())
    {
        exit_mutex.lock();
        if (ifExit)
        {
            exit_mutex.unlock();
            break;
        }
        exit_mutex.unlock();

        rclcpp::Time current_time = this->now();
        rclcpp::Duration time_since_last_msg = current_time - last_time_;

        // 检查数据接收状态
        if (std::abs(recFrequency) < 0.00001)
        {
            loop_rate.sleep();
            continue;
        }
        if (time_since_last_msg.seconds() > 0.04)
        {
            RCLCPP_WARN(this->get_logger(), "No data received for more than 0.04 seconds!");
            recFrequency = 0.0;
            loop_rate.sleep();
            continue;
        }

        int iName_left[7] = {11, 12, 13, 14, 15, 16, 17};
        int iName_right[7] = {21, 22, 23, 24, 25, 26, 27};
        float Plan_Pos_left[7] = {0};
        float Plan_Pos_right[7] = {0};
        float Plan_Vel_left[7] = {4, 4, 4, 4, 4, 4, 4};
        float Plan_Vel_right[7] = {4, 4, 4, 4, 4, 4, 4};
        float Plan_Vel_send_left[7] = {0};
        float Plan_Vel_send_right[7] = {0};
        float Plan_Current[7] = {12, 9, 4, 4, 4, 3, 3};
        // float Plan_Current[7] = {9.7, 5.3, 2, 2, 2, 1.7, 1.7};
        float current_2_torque[7] = {3.207, 2.28, 5.589, 5.589, 3.35, 2.3, 2.3};
        float fkp_left[7] = {500, 400, 200, 200, 200, 100, 100};
        float fkd_left[7] = {20, 15, 10, 10, 10, 5, 5};
        float fkp_right[7] = {500, 400, 200, 200, 200, 100, 100};
        float fkd_right[7] = {20, 15, 10, 10, 10, 5, 5};
        float fTorque[7] = {0};
        float dis_left[7] = {0};
        float dis_right[7] = {0};

        // 计算规划位置和速度
        for (int i = 0; i < 7; i++)
        {
            // 处理左臂
            {
                std::lock_guard<std::mutex> lock(left_arm_mutex_14);
                Plan_Pos_left[i] = left_arm_current_pos_14[i] * my_filter_parameter +
                                   (1 - my_filter_parameter) * left_last_send_pos[i];
                left_last_send_pos[i] = Plan_Pos_left[i];

                Plan_Vel_left[i] = left_arm_current_spd_14[i] * my_filter_parameter +
                                   (1 - my_filter_parameter) * left_last_send_spd[i];
                left_last_send_spd[i] = Plan_Vel_left[i];

                dis_left[i] = Plan_Pos_left[i] - left_arm_current_pos[i];
            }

            Plan_Vel_send_left[i] = Plan_Vel_left[i] + my_pos_closed_loop_parameter * dis_left[i];

            // 处理右臂
            {
                std::lock_guard<std::mutex> lock(right_arm_mutex_14);
                Plan_Pos_right[i] = right_arm_current_pos_14[i] * my_filter_parameter +
                                    (1 - my_filter_parameter) * right_last_send_pos[i];
                right_last_send_pos[i] = Plan_Pos_right[i];

                Plan_Vel_right[i] = right_arm_current_spd_14[i] * my_filter_parameter +
                                    (1 - my_filter_parameter) * right_last_send_spd[i];
                right_last_send_spd[i] = Plan_Vel_right[i];

                dis_right[i] = Plan_Pos_right[i] - right_arm_current_pos[i];
            }

            Plan_Vel_send_right[i] = Plan_Vel_right[i] + my_pos_closed_loop_parameter * dis_right[i];

            // 速度限幅
            Plan_Vel_send_left[i] = std::clamp(Plan_Vel_send_left[i], -6.0f, 6.0f);
            Plan_Vel_send_right[i] = std::clamp(Plan_Vel_send_right[i], -6.0f, 6.0f);

            // 电流限幅计算
            float temp_left = std::abs((fkp_left[i] * (Plan_Pos_left[i] - left_arm_current_pos[i]) +
                                        fkd_left[i] * (Plan_Vel_left[i] - left_arm_current_spd[i]) +
                                        fTorque[i]) /
                                       current_2_torque[i]);
            if (temp_left > std::abs(Plan_Current[i]))
            {
                fkp_left[i] = fkp_left[i] / temp_left * std::abs(Plan_Current[i]);
                fkd_left[i] = fkd_left[i] / temp_left * std::abs(Plan_Current[i]);
            }

            float temp_right = std::abs((fkp_right[i] * (Plan_Pos_right[i] - right_arm_current_pos[i]) +
                                         fkd_right[i] * (Plan_Vel_right[i] - right_arm_current_spd[i]) +
                                         fTorque[i]) /
                                        current_2_torque[i]);
            if (temp_right > std::abs(Plan_Current[i]))
            {
                fkp_right[i] = fkp_right[i] / temp_right * std::abs(Plan_Current[i]);
                fkd_right[i] = fkd_right[i] / temp_right * std::abs(Plan_Current[i]);
            }

            // 位置限位检查
            if ((right_arm_current_pos[i] > right_arm_max_limit[i] && Plan_Vel_send_right[i] > 0) ||
                (right_arm_current_pos[i] < right_arm_min_limit[i] && Plan_Vel_send_right[i] < 0))
            {
                Plan_Vel_send_right[i] = 0;
            }

            // 填充发布数据
            ArmReceiveCanData.data[1 + 6 * i] = -left_arm_current_pos[i];
            ArmReceiveCanData.data[2 + 6 * i] = 0;
            ArmReceiveCanData.data[3 + 6 * i] = right_arm_current_pos[i];
            ArmReceiveCanData.data[4 + 6 * i] = -left_arm_current_spd[i];
            ArmReceiveCanData.data[5 + 6 * i] = Plan_Vel_send_right[i];
            ArmReceiveCanData.data[6 + 6 * i] = right_arm_current_spd[i];
        }

        pub_arm->publish(ArmReceiveCanData);

        // 根据控制模式发布指令
        switch (mode)
        {
        case 1:
            if (my_joint_state_topic == 1 || my_joint_state_topic == 2)
            {
                Joints_pos_Pub(7, iName_left, Plan_Pos_left, Plan_Vel_left, Plan_Current, pub_arm_pos_left);
                Joints_pos_Pub(7, iName_right, Plan_Pos_right, Plan_Vel_right, Plan_Current, pub_arm_pos_right);
            }
            else if (my_joint_state_topic == 3)
            {
                Joints_pos_Pub(7, iName_left, Plan_Pos_left, Plan_Vel_left, Plan_Current, pub_arm_pos);
                Joints_pos_Pub(7, iName_right, Plan_Pos_right, Plan_Vel_right, Plan_Current, pub_arm_pos);
            }
            break;

        case 2:
            RCLCPP_INFO(this->get_logger(), "case 02");
            break;

        case 3:
            if (my_joint_state_topic == 1 || my_joint_state_topic == 2)
            {
                Joints_vel_Pub(7, iName_left, Plan_Vel_send_left, Plan_Current, pub_arm_vel_left);
                Joints_vel_Pub(7, iName_right, Plan_Vel_send_right, Plan_Current, pub_arm_vel_right);
            }
            else if (my_joint_state_topic == 3)
            {
                Joints_vel_Pub(7, iName_left, Plan_Vel_send_left, Plan_Current, pub_arm_vel);
                Joints_vel_Pub(7, iName_right, Plan_Vel_send_right, Plan_Current, pub_arm_vel);
            }
            break;

        case 4:
            Joints_mix_Pub(7, iName_left, fkp_left, fkd_left, Plan_Pos_left, Plan_Vel_left, fTorque, pub_arm_mix);
            Joints_mix_Pub(7, iName_right, fkp_right, fkd_right, Plan_Pos_right, Plan_Vel_right, fTorque, pub_arm_mix);
            RCLCPP_INFO(this->get_logger(), "case 04");
            break;

        default:
            RCLCPP_INFO(this->get_logger(), "mode= %d, DEFAULT", mode);
            break;
        }

        loop_rate.sleep();
    }

    return true;
}

// 修改Joints_vel_Pub函数定义，使用正确的消息类型
void FreqChange::Joints_vel_Pub(int dof, int *iJointName, float *vel, float *current,
                                rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorSpeed>::SharedPtr pub)
{
    bodyctrl_msgs::msg::CmdSetMotorSpeed msg;
    msg.header.stamp = this->now();
    msg.cmds.clear();

    for (int i = 0; i < dof; i++)
    {
        bodyctrl_msgs::msg::SetMotorSpeed cmd;
        cmd.name = iJointName[i];
        cmd.spd = vel[i];
        cmd.cur = current[i];
        RCLCPP_INFO(this->get_logger(), "Joints_vel_Pub - %d, vel: %f, current: %f",
                    iJointName[i], vel[i], current[i]);
        msg.cmds.push_back(cmd);
    }
    pub->publish(msg);
}

// 修改Joints_pos_Pub函数定义，使用正确的消息类型
void FreqChange::Joints_pos_Pub(int dof, int *iJointName, float *pos, float *vel, float *current,
                                rclcpp::Publisher<bodyctrl_msgs::msg::CmdSetMotorPosition>::SharedPtr pub)
{
    bodyctrl_msgs::msg::CmdSetMotorPosition msg;
    msg.header.stamp = this->now();
    msg.cmds.clear();

    for (int i = 0; i < dof; i++)
    {
        bodyctrl_msgs::msg::SetMotorPosition cmd;
        cmd.name = iJointName[i];
        cmd.pos = pos[i];
        cmd.spd = vel[i];
        cmd.cur = current[i];
        msg.cmds.push_back(cmd);
    }
    pub->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Joints_pos_Pub finish");
}

void FreqChange::Joints_mix_Pub(int dof, int *iJointName, float *fkp, float *fkd,
                                float *fPos, float *fSpeed, float *fTorque,
                                rclcpp::Publisher<bodyctrl_msgs::msg::CmdMotorCtrl>::SharedPtr pub)
{
    bodyctrl_msgs::msg::CmdMotorCtrl msg;
    msg.header.stamp = this->now();
    msg.cmds.clear();

    for (int i = 0; i < dof; i++)
    {
        bodyctrl_msgs::msg::MotorCtrl cmd;
        cmd.name = iJointName[i];
        cmd.kp = fkp[i];
        cmd.kd = fkd[i];
        cmd.pos = fPos[i];
        cmd.spd = fSpeed[i];
        cmd.tor = fTorque[i];
        msg.cmds.push_back(cmd);
    }
    pub->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Joints_mix_Pub finish");
}

// 主函数入口
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FreqChange>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
