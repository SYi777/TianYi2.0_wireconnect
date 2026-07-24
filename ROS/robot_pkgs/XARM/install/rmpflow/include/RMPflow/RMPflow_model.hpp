#ifndef RMPFLOW_MODEL_HPP
#define RMPFLOW_MODEL_HPP

#include <Eigen/Dense>
#include "RMPflow/math_utils.hpp"
#include <iostream>
#include <pinocchio/parsers/sample-models.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <pinocchio/algorithm/frames.hpp>



namespace RMP::model {
struct ScrewModel {
    Eigen::MatrixXd xi; // s系旋量轴
    Eigen::MatrixXd Bi;
    Eigen::Matrix4d M;    // 末端位姿矩阵
    Eigen::Matrix4d Te;   // 末端位姿偏移，表示在b系
    Eigen::Matrix4d Tsb0; // Tsb0 = M * Text
private:
    // 优化计算速度，采用惰性求值
    Eigen::VectorXd theta_fk, theta_jb, theta_js;
    Eigen::Matrix4d FK_;
    Eigen::MatrixXd Jb_, Js_;

    Eigen::VectorXd theta_S, theta_B;       // 用来存储expm相关的惰性求值角度
    std::vector<Eigen::Matrix4d> Sexp_vec;  // 用来存储expm(vec2se3(s_i*theta_i))的结果
    std::vector<Eigen::Matrix4d> Bexp_vec;  // 用来存储expm(vec2se3(b_i*theta_i))的结果
    double lazy_eps = 1e-14;
public:
    ScrewModel() {}
    ScrewModel(Eigen::MatrixXd xi, Eigen::Matrix4d M, Eigen::Matrix4d Te)
        : xi(xi), M(M), Te(Te) {
        Tsb0 = M * Te;
        Bi = utils::Adjoint(utils::TransInv(Tsb0)) * xi;
        int dim = xi.cols();

        Eigen::VectorXd Z = Eigen::VectorXd::Zero(dim);
        theta_S = Eigen::VectorXd::Ones(dim);
        theta_B = Eigen::VectorXd::Ones(dim);
        Sexp_vec.resize(dim);
        Bexp_vec.resize(dim);

        for (int k = 0; k < dim; k++) {
            Eigen::Matrix4d Sexp = SExpm(k, Z(k));
            Eigen::Matrix4d Bexp = BExpm(k, Z(k));
            Sexp_vec.at(k) = Sexp;
            Bexp_vec.at(k) = Bexp;
        }
        theta_S = Z;
        theta_B = Z;

        theta_fk = Eigen::VectorXd::Ones(dim);
        theta_jb = Eigen::VectorXd::Ones(dim);
        theta_js = Eigen::VectorXd::Ones(dim);
        Eigen::VectorXd::Ones(dim);

        FK_ = this->FK(Z);
        Jb_ = this->Jb(Z);
        Js_ = this->Js(Z);
        theta_fk = Z;
        theta_jb = Z;
        theta_js = Z;
    }

    Eigen::Matrix4d FK(Eigen::VectorXd q) {
        if ((theta_fk - q).norm() < lazy_eps) {
            return FK_;
        }
        theta_fk = q;
        FK_ = this->FKinSpace(q);
        return FK_;
    }

    Eigen::MatrixXd Js(Eigen::VectorXd q) {
        if ((theta_js - q).norm() < lazy_eps) {
            return Js_;
        }
        theta_js = q;
        Js_ = this->JacobianSpace(q);
        return Js_;
    }

    Eigen::MatrixXd Jb(Eigen::VectorXd q) {
        if ((theta_jb - q).norm() < lazy_eps) {
            return Jb_;
        }
        theta_jb = q;
        Jb_ = this->JacobianBody(q);
        return Jb_;
    }

    Eigen::MatrixXd Js_dot(Eigen::VectorXd q, Eigen::VectorXd q_dot) {
        Eigen::MatrixXd Js_dot_;
        Eigen::MatrixXd Js_;
        Js_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        Js_ = this->Js(q);
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jsi;
            dot_Jsi.setZero();
            for (int j = 0; j < 7; j++) {
                if (i > j)
                    dot_Jsi += utils::ad(Js_.col(i)) * Js_.col(j) * q_dot(j);
            }
            Js_dot_.col(i) = dot_Jsi;
        }
        return Js_dot_;
    }

    // 传入Js，节省一次Js计算
    Eigen::MatrixXd Js_dot(Eigen::VectorXd q, Eigen::VectorXd q_dot, const Eigen::MatrixXd& Js_) {
        Eigen::MatrixXd Js_dot_;
        Js_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jsi;
            dot_Jsi.setZero();
            for (int j = 0; j < 7; j++) {
                if (i > j)
                    dot_Jsi += utils::ad(Js_.col(i)) * Js_.col(j) * q_dot(j);
            }
            Js_dot_.col(i) = dot_Jsi;
        }
        return Js_dot_;
    }

    Eigen::MatrixXd Jb_dot(Eigen::VectorXd q, Eigen::VectorXd q_dot) {
        Eigen::MatrixXd Jb_dot_;
        Eigen::MatrixXd Jb_;
        Jb_ = this->Jb(q);
        Jb_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jbi;
            dot_Jbi.setZero();
            for (int j = 0; j < N; j++) {
                if (i < j)
                    dot_Jbi += utils::ad(Jb_.col(i)) * Jb_.col(j) * q_dot(j);
            }
            Jb_dot_.col(i) = dot_Jbi;
        }
        return Jb_dot_;
    }

    // 传入Jb，节省一次计算
    Eigen::MatrixXd Jb_dot(Eigen::VectorXd q, Eigen::VectorXd q_dot, const Eigen::MatrixXd& Jb_) {
        Eigen::MatrixXd Jb_dot_;
        Jb_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jbi;
            dot_Jbi.setZero();
            for (int j = 0; j < N; j++) {
                if (i < j)
                    dot_Jbi += utils::ad(Jb_.col(i)) * Jb_.col(j) * q_dot(j);
            }
            Jb_dot_.col(i) = dot_Jbi;
        }
        return Jb_dot_;
    }

private:
    Eigen::Matrix4d SExpm(int i, double theta_i) {
        if (std::abs(theta_i - theta_S(i)) < lazy_eps) {
            return Sexp_vec.at(i);
        }
        theta_S(i) = theta_i;
        Sexp_vec.at(i) = utils::MatrixExp6(utils::VecTose3(xi.col(i) * theta_i));
        return Sexp_vec.at(i);
    }
    Eigen::Matrix4d BExpm(int i, double theta_i) {
        if (std::abs(theta_i - theta_B(i)) < lazy_eps) {
            return Bexp_vec.at(i);
        }
        theta_B(i) = theta_i;
        Bexp_vec.at(i) = utils::MatrixExp6(utils::VecTose3(-1 * Bi.col(i) * theta_i));
        return Bexp_vec.at(i);
    }

    Eigen::Matrix4d FKinSpace(const Eigen::VectorXd &thetaList) {
        Eigen::Matrix4d T = Tsb0;
        for (int i = (thetaList.size() - 1); i > -1; i--) {
            T = SExpm(i, thetaList(i)) * T;
        }
        return T;
    }

    Eigen::MatrixXd
    JacobianSpace(const Eigen::MatrixXd &thetaList) {
        Eigen::MatrixXd Js = xi;
        Eigen::MatrixXd T = Eigen::MatrixXd::Identity(4, 4);
        for (int i = 1; i < thetaList.size(); i++) {
            T = T * SExpm(i - 1, thetaList(i - 1));
            Js.col(i) = utils::Adjoint(T) * xi.col(i);
        }

        return Js;
    }

    Eigen::MatrixXd
    JacobianBody(const Eigen::MatrixXd &thetaList) {
        Eigen::MatrixXd Jb = Bi;
        Eigen::MatrixXd T = Eigen::MatrixXd::Identity(4, 4);
        for (int i = thetaList.size() - 2; i >= 0; i--) {
            T = T * BExpm(i + 1, thetaList(i + 1));
            Jb.col(i) = utils::Adjoint(T) * Bi.col(i);
        }
        return Jb;
    }

};
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
    

    pin::Model model;
    pin::Data data;
};

} // namespace RMP::model

#endif // RMPFLOW_MODEL_HPP
