#ifndef SE3_SQUAD_HPP
#define SE3_SQUAD_HPP

#include <Eigen/Dense>
#include "SE3OTG/math_utils.hpp"
#include "SE3OTG/SE3OTG_base.hpp"

namespace SE3OTG {

struct SE3_SQUAD : public SE3OTG_BASE{
public:
    SE3_SQUAD() : SE3OTG_BASE() {}
    void init(Eigen::Matrix3d R, Eigen::Vector3d p){
        this->R_last_ = R;
        this->R_ = R;
        this->p_ = p;

        double T = 1.0 / (5 * R_step * 250);
        if (T <= 0.0) {
            // 处理无效输入
            T = 1.0;
        }
        double exponent = -1.0 / (250.0 * T);
        double denom = 1.0 - std::exp(exponent);
        double k_val = 1.0 / denom;
        // 四舍五入到最近整数
        num_interpolation_ = static_cast<int>(std::round(k_val));
        if (num_interpolation_ < 2) num_interpolation_ = 2;
    }
    void update(Eigen::Matrix3d R_target, Eigen::Vector3d p_target) override;
    double R_step = 1e-2;
    double p_step = 1e-2;
    int num_interpolation_ = 100;
protected:
    Eigen::Matrix3d R_last_;
};

} // namespace SE3OTG

#endif // SE3_SQUAD_HPP
