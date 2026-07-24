#ifndef STABILITY_CHECKER_HPP
#define STABILITY_CHECKER_HPP

#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/center-of-mass.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/kinematics.hpp>

#include <Eigen/Dense>
#include <vector>
#include <string>
#include <memory>

class StaticStabilityChecker {
public:
    // 构造函数
    StaticStabilityChecker(const std::string& urdf_path);
    
    // 检查关节角配置下的稳定性
    struct StabilityResult {
        bool is_stable;                     // 是否稳定
        Eigen::Vector2d com_projection;     // 质心在地面的投影
    };
    
    StabilityResult checkStability(const Eigen::VectorXd& joint_angles);
    
    // 设置参数
    void setSafetyMargin(double margin) { safety_margin_ = margin; }
    void setWheelContactPoints(const std::vector<Eigen::Vector3d>& points);
    
    // 获取信息
    Eigen::Vector3d getCurrentCoM() const;

    pinocchio::Model model_;
    
private:
    // 内部计算函数
    void computeSupportPolygon();
    
    // 机器人模型和数据
    pinocchio::Data data_;
    
    // 支撑多边形相关
    std::vector<Eigen::Vector3d> wheel_contact_points_;  // 轮子接地点
    std::vector<Eigen::Vector2d> support_polygon_;       // 支撑多边形
    std::vector<Eigen::Vector2d> safe_polygon_;          // 安全多边形(缩小版)
    
    // 参数
    double safety_margin_;     // 安全裕度
    Eigen::Vector3d current_com_;
};

// 凸包计算辅助类
class ConvexHull {
public:
    // 计算凸包
    static std::vector<Eigen::Vector2d> computeGrahamScan(
        const std::vector<Eigen::Vector2d>& points);
    
private:
    static double cross(const Eigen::Vector2d& o, 
                       const Eigen::Vector2d& a, 
                       const Eigen::Vector2d& b);
};

// 几何工具函数
namespace GeometryUtils {
    // 射线法判断点是否在凸包内部
    bool isPointInPolygon(const Eigen::Vector2d& p,
                         const std::vector<Eigen::Vector2d>& polygon);
    // 使用安全裕度优化后的凸包
    std::vector<Eigen::Vector2d> offsetPolygon(
        const std::vector<Eigen::Vector2d>& polygon,
        double offset);
}

#endif // STABILITY_CHECKER_HPP