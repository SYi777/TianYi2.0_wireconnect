#ifndef SE3OTG_BASE_HPP
#define SE3OTG_BASE_HPP
#include <Eigen/Dense>

#include "math_utils.hpp"

namespace SE3OTG {

    struct SE3OTG_BASE {
        void init(Eigen::Matrix3d R, Eigen::Vector3d p) {
            this->R_ = R;
            this->p_ = p;
        }

        virtual void update(Eigen::Matrix3d R_target, Eigen::Vector3d p_target) = 0;

        Eigen::Matrix4d getOutPut_T() {
            return SE3OTG::utils::RpToTrans(R_, p_);
        }

        Eigen::Matrix3d getOutPut_R() {
            return R_;
        }

        Eigen::Vector3d getOutPut_p() {
            return p_;
        }

    protected:
        Eigen::Matrix3d R_;
        Eigen::Vector3d p_;
    };

} // namespace SE3OTG

#endif //SE3OTG_BASE_HPP
