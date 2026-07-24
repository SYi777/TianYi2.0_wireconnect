#ifndef __HUMANOIDROBOT_H
#define __HUMANOIDROBOT_H

#include <kdl/chain.hpp>
#include <Eigen/Dense>

#define FREQUENCY 400.0 // 机器人的通信频率

class RobotPart // 机器人的某个部位
{
private:
    
public:
    KDL::Chain chain;
    unsigned int freedom = 0; // 自由度
    Eigen::VectorXd qUpLimit; // 关节上限
    Eigen::VectorXd qLowLimit; // 关节下限
    Eigen::VectorXd qDLimit; // 关节转速限制
    Eigen::VectorXd qDDLimit; // 关节加速度限制
    Eigen::VectorXd qJerkLimit; // 关节加加速度限制
    RobotPart();
    ~RobotPart();
};

class HumanoidRobot // 机器人整体
{
private:

public:
    RobotPart arm_right;
    HumanoidRobot();
    ~HumanoidRobot();
};

#endif
