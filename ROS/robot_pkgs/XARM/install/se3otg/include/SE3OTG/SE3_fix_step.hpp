#ifndef SE3_FIX_STEP_HPP
#define SE3_FIX_STEP_HPP

#include <Eigen/Dense>
#include "SE3OTG/math_utils.hpp"
#include "SE3OTG/SE3OTG_base.hpp"

namespace SE3OTG {

struct SE3_fix_step : public SE3OTG_BASE{
public:
  SE3_fix_step() : SE3OTG_BASE() {}
  void update(Eigen::Matrix3d R_target, Eigen::Vector3d p_target) override;
  double R_step = 1e-2;
  double p_step = 1e-2;
};

} // namespace SE3OTG

#endif // SE3_FIX_STEP_HPP
