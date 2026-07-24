#ifndef TIANYI_CONTROL_ALGORITHM_HPP_
#define TIANYI_CONTROL_ALGORITHM_HPP_

#include "Eigen/Dense"
#include <memory>                
#include "rclcpp/rclcpp.hpp"   
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/model.hpp"
#include <pinocchio/algorithm/crba.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/compute-all-terms.hpp>
#include <pinocchio/spatial/explog.hpp> 
#include "tiangong_hardware/ReadRobotParameters.h"

#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>

namespace tiangong_hardware
{

class ControlAlgorithm
{
public:
    ControlAlgorithm(){};
    ~ControlAlgorithm() = default;

    void init();
    void update(const Eigen::Vector<double, 17>& target_pos, const Eigen::Vector<double, 17>& current_pos, Eigen::Vector<double, 14>& dual_arm_extra_torq);
    void update(const Eigen::Vector<double, 17>& target_pos, const Eigen::Vector<double, 17>& current_pos, const Eigen::Vector<double, 17>& current_vel, Eigen::Vector<double, 14>& dual_arm_extra_torq);
    void setArmMode(int mode){
        this->mode = mode;
        if (this->mode != last_mode)
        {
            mode_time = 0.0;
            mode_count = 0;
        }
    }

    void setdt(double dt){
        this->dt = dt;
    }
    void setRobotType(const std::string& type) { robot_type_ = type;}
private:
    // 负载参数结构体
    struct LoadPayParams 
    {
        double load_mass = 0.0; 
        Eigen::Vector3d load_com = Eigen::Vector3d::Zero(); 
        Eigen::Matrix3d load_inertia = Eigen::Matrix3d::Zero(); 
    };
    std::string robot_type_;
    // Pinocchio模型
    pinocchio::Model model_;
    pinocchio::Data data_;

    // 机器人动力学参数
    RobotParameters left_arm_params_;
    RobotParameters right_arm_params_;
    std::vector<double> left_arm_noline_friction_alpha_;  
    std::vector<double> right_arm_noline_friction_alpha_; 
    Eigen::VectorXd left_friction_params_;                
    Eigen::VectorXd right_friction_params_;             
    Eigen::VectorXd gain_left_; 
    Eigen::VectorXd gain_right_; 
    Eigen::VectorXd gain_friction_left_; 
    Eigen::VectorXd gain_friction_right_; 
    // 负载参数
    LoadPayParams left_load_pay_; 
    LoadPayParams right_load_pay_;  

    // 关节/Frame映射
    std::unordered_map<std::string, pinocchio::FrameIndex> frame_name_to_id_;
    std::vector<size_t> left_arm_joint_indices_;         
    std::vector<size_t> right_arm_joint_indices_;       
    std::vector<std::string> left_arm_joint_names_;
    std::vector<std::string> right_arm_joint_names_;

    // 滤波相关
    double filter_alpha_ = 0.8;
    Eigen::Vector<double, 7> left_vel_filtered_;
    Eigen::Vector<double, 7> right_vel_filtered_;
    Eigen::Vector<double, 7> prev_left_vel_filtered_;
    Eigen::Vector<double, 7> prev_right_vel_filtered_;

    // 控制模式相关
    int mode{0};
    double mode_time{0.0};   //当前mode的运行时间
    double mode_count{0.0};  // 当前mode的运行计数
    double dt{0.0};

    // 上一周期数据
    int last_mode{-1};
    Eigen::Vector<double, 17> last_target_pos;
    Eigen::Vector<double, 17> last_pos;
    //关节最大前馈力矩限制
    const std::array<double, 7> joint_max_feedforward_torque_limits  = {15.0, 20.0, 9.0, 8.0, 4.0, 1.5, 1.5};
    const std::array<double, 7> joint_min_feedforward_torque_limits  = {-18.0, -20.0, -9.0, -8.0, -4.0, -1.5, -1.5};

    void initializeModel();
    void updateDynamicParameters();
    void createJointIndexMap();
    bool loadLoadPayParams(const std::string& yaml_path, const std::string& load_name, LoadPayParams& load_params);
    void addLoadToTCP(const std::string& tcp_link_name, const LoadPayParams& load_params, const std::string& load_name);
    bool readGainParams(const std::string& yaml_path);
    Eigen::VectorXd calculateFrictionTorque(
        const std::vector<size_t>& joint_indices,  
        const std::vector<double>& alpha,          
        const Eigen::VectorXd& friction_params,    
        const Eigen::VectorXd& qd_filtered         
    );
    static Eigen::MatrixXd nonline_frictionRegressor(const Eigen::VectorXd& qd_fltrd, const std::vector<double>& alpha);
};

} // namespace tiangong_hardware

#endif  // TIANYI_CONTROL_ALGORITHM_HPP_
