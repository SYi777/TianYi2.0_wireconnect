
#ifndef HEADIK_HPP
#define HEADIK_HPP
#include "Eigen/Dense"
#include "head_ik_controller/Model.hpp"
namespace tianyi2 {
struct HeadModel {
    HeadModel(std::string urdf) { model = robotic::makeTianyiHeadModel(urdf); }
    robotic::ScrewModel model;
    Eigen::Matrix4d FK(Eigen::Vector3d yaw_pitch_roll);
    bool solve_head_IK(Eigen::Matrix3d Rd, Eigen::Vector3d &results);
};

} // namespace tianyi2
#endif // HEADIK_HPP
