
#ifndef TIANGONG_HARDWARE_SINGLE_ARM_PROCESSOR_HPP_
#define TIANGONG_HARDWARE_SINGLE_ARM_PROCESSOR_HPP_

#include "Eigen/Dense"
#include <string>
#include <vector>
#include "tiangong_hardware/FiltFilt.h" 

namespace tiangong_hardware {

/**
 * @brief 单臂动力学处理器
 */
class SingleArmProcessor
{
public:
    // 构造函数声明
    SingleArmProcessor(const std::string& arm_name, const std::string& param_file);

    struct DynResult
    {
        Eigen::VectorXd pred_torque;
    };

    DynResult calculateTorque(const Eigen::VectorXd& pos, const Eigen::VectorXd& vel, double dt);
    DynResult calculateGravityTorque(const Eigen::VectorXd& pos, const Eigen::VectorXd& vel);
private:
    FiltFilt filter_;
    static const int ARM_JOINT_NUM;
    std::string arm_name_;
    bool include_motor_dynamics_;
    Eigen::MatrixXd dynamic_params_;
    Eigen::MatrixXd E1_;
    int num_reduced_params_;
    std::vector<FiltFilt::FilterState> position_filters_;
    std::vector<FiltFilt::FilterState> velocity_filters_;
    std::vector<FiltFilt::FilterState> acceleration_filters_;
    Eigen::VectorXd prev_velocities_;
    Eigen::VectorXd prev_prev_velocities_;
    Eigen::VectorXd a_;
    Eigen::VectorXd b_;

    void loadDynamicParamsROS2(const std::string& param_file);
    void initFilters();
    Eigen::VectorXd filterData(std::vector<FiltFilt::FilterState>& filters, const Eigen::VectorXd& data);
    Eigen::VectorXd calculateAcceleration(const Eigen::VectorXd& current_velocity, double dt);
    Eigen::VectorXd calculatePredictedTorque(const Eigen::VectorXd& pos, const Eigen::VectorXd& vel, const Eigen::VectorXd& acc);
    Eigen::VectorXd calculateGravityPredictedTorque (const Eigen::VectorXd& pos, const Eigen::VectorXd& vel, const Eigen::VectorXd& acc);
};

} // namespace tiangong_hardware

#endif // TIANGONG_HARDWARE_SINGLE_ARM_PROCESSOR_HPP_
