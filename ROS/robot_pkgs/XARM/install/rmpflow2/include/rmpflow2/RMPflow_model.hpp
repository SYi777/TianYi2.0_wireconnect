#ifndef RMPFLOW_MODEL_HPP
#define RMPFLOW_MODEL_HPP

#include <Eigen/Dense>
#include "rmpflow2/math_utils.hpp"
#include <iostream>
#include <pinocchio/parsers/sample-models.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>



namespace RMP::model {
namespace pin = pinocchio;

struct PinocchioModel {
    void init(std::string urdf) {
        pin::urdf::buildModel(urdf, model);
        data = pinocchio::Data(model);
    }

    void updateRobotKinematics(Eigen::VectorXd q, Eigen::VectorXd v) {
        pin::forwardKinematics(model, data, q);
        pin::updateFramePlacements(model, data);
        pin::computeJointJacobians(model, data, q);
        pin::computeJointJacobiansTimeVariation(model, data, q, v);
    }

    Eigen::Matrix4d FK(std::string frame_name) {
        return data.oMf[model.getFrameId(frame_name)].toHomogeneousMatrix();
    }
    
    Eigen::MatrixXd Js(std::string frame_name) {
        
        Eigen::MatrixXd Js_pin = pin::getFrameJacobian(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::WORLD);

        return utils::switch_w_v(Js_pin);
    }

    Eigen::MatrixXd Js_dot(std::string frame_name) {
        
        Eigen::MatrixXd Js_dot;
        Js_dot = Eigen::MatrixXd::Zero(6, model.nv);

        pin::getFrameJacobianTimeVariation(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::WORLD, Js_dot);

        return utils::switch_w_v(Js_dot);
    }
    
    Eigen::MatrixXd Jb(std::string frame_name) {
        
        Eigen::MatrixXd Jb_pin = pin::getFrameJacobian(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::LOCAL);

        return utils::switch_w_v(Jb_pin);
    }

    Eigen::MatrixXd Jb_dot(std::string frame_name) {
        
        Eigen::MatrixXd Jb_dot;
        Jb_dot = Eigen::MatrixXd::Zero(6, model.nv);

        pin::getFrameJacobianTimeVariation(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::LOCAL, Jb_dot);

        return utils::switch_w_v(Jb_dot);
    }

    Eigen::MatrixXd Ja(std::string frame_name){
        Eigen::MatrixXd Ja_pin = pin::getFrameJacobian(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::LOCAL_WORLD_ALIGNED);
        return utils::switch_w_v(Ja_pin);
    }

    Eigen::MatrixXd Ja_dot(std::string frame_name) {
        
        Eigen::MatrixXd Ja_dot;
        Ja_dot = Eigen::MatrixXd::Zero(6, model.nv);

        pin::getFrameJacobianTimeVariation(model, data, model.getFrameId(frame_name), pin::ReferenceFrame::LOCAL_WORLD_ALIGNED, Ja_dot);

        return utils::switch_w_v(Ja_dot);
    }
    

    pin::Model model;
    pin::Data data;
};

} // namespace RMP::model

#endif // RMPFLOW_MODEL_HPP
