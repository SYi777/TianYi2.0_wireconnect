#ifndef MODEL_HPP
#define MODEL_HPP
#include <Eigen/Dense>
#include "mr/modern_robotics.h"

namespace robotic {
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

    Eigen::VectorXd theta_S, theta_B; // 用来存储expm相关的惰性求值角度
    std::vector<Eigen::Matrix4d>
        Sexp_vec; // 用来存储expm(vec2se3(s_i*theta_i))的结果
    std::vector<Eigen::Matrix4d>
        Bexp_vec; // 用来存储expm(vec2se3(b_i*theta_i))的结果
    double lazy_eps = 1e-14;

  public:
    ScrewModel() {}
    ScrewModel(Eigen::MatrixXd xi, Eigen::Matrix4d M, Eigen::Matrix4d Te)
        : xi(xi), M(M), Te(Te) {
        Tsb0 = M * Te;
        Bi = mr::Adjoint(mr::TransInv(Tsb0)) * xi;
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
        if ((theta_fk - q).norm() < lazy_eps) { return FK_; }
        theta_fk = q;
        FK_ = this->FKinSpace(q);
        return FK_;
    }

    Eigen::MatrixXd Js(Eigen::VectorXd q) {
        if ((theta_js - q).norm() < lazy_eps) { return Js_; }
        theta_js = q;
        Js_ = this->JacobianSpace(q);
        return Js_;
    }

    Eigen::MatrixXd Jb(Eigen::VectorXd q) {
        if ((theta_jb - q).norm() < lazy_eps) { return Jb_; }
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
                    dot_Jsi += mr::ad(Js_.col(i)) * Js_.col(j) * q_dot(j);
            }
            Js_dot_.col(i) = dot_Jsi;
        }
        return Js_dot_;
    }

    // 传入Js，节省一次Js计算
    Eigen::MatrixXd Js_dot(
        Eigen::VectorXd q, Eigen::VectorXd q_dot, const Eigen::MatrixXd &Js_) {
        Eigen::MatrixXd Js_dot_;
        Js_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jsi;
            dot_Jsi.setZero();
            for (int j = 0; j < 7; j++) {
                if (i > j)
                    dot_Jsi += mr::ad(Js_.col(i)) * Js_.col(j) * q_dot(j);
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
                    dot_Jbi += mr::ad(Jb_.col(i)) * Jb_.col(j) * q_dot(j);
            }
            Jb_dot_.col(i) = dot_Jbi;
        }
        return Jb_dot_;
    }

    // 传入Jb，节省一次计算
    Eigen::MatrixXd Jb_dot(
        Eigen::VectorXd q, Eigen::VectorXd q_dot, const Eigen::MatrixXd &Jb_) {
        Eigen::MatrixXd Jb_dot_;
        Jb_dot_ = Eigen::MatrixXd::Zero(6, q.rows());
        int N = q.rows();
        for (int i = 0; i < N; i++) {
            Eigen::Vector<double, 6> dot_Jbi;
            dot_Jbi.setZero();
            for (int j = 0; j < N; j++) {
                if (i < j)
                    dot_Jbi += mr::ad(Jb_.col(i)) * Jb_.col(j) * q_dot(j);
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
        Sexp_vec.at(i) = mr::MatrixExp6(mr::VecTose3(xi.col(i) * theta_i));
        return Sexp_vec.at(i);
    }
    Eigen::Matrix4d BExpm(int i, double theta_i) {
        if (std::abs(theta_i - theta_B(i)) < lazy_eps) {
            return Bexp_vec.at(i);
        }
        theta_B(i) = theta_i;
        Bexp_vec.at(i) = mr::MatrixExp6(mr::VecTose3(-1 * Bi.col(i) * theta_i));
        return Bexp_vec.at(i);
    }

    Eigen::Matrix4d FKinSpace(const Eigen::VectorXd &thetaList) {
        Eigen::Matrix4d T = Tsb0;
        for (int i = (thetaList.size() - 1); i > -1; i--) {
            T = SExpm(i, thetaList(i)) * T;
        }
        return T;
    }

    Eigen::MatrixXd JacobianSpace(const Eigen::MatrixXd &thetaList) {
        Eigen::MatrixXd Js = xi;
        Eigen::MatrixXd T = Eigen::MatrixXd::Identity(4, 4);
        for (int i = 1; i < thetaList.size(); i++) {
            T = T * SExpm(i - 1, thetaList(i - 1));
            Js.col(i) = mr::Adjoint(T) * xi.col(i);
        }

        return Js;
    }

    Eigen::MatrixXd JacobianBody(const Eigen::MatrixXd &thetaList) {
        Eigen::MatrixXd Jb = Bi;
        Eigen::MatrixXd T = Eigen::MatrixXd::Identity(4, 4);
        for (int i = thetaList.size() - 2; i >= 0; i--) {
            T = T * BExpm(i + 1, thetaList(i + 1));
            Jb.col(i) = mr::Adjoint(T) * Bi.col(i);
        }
        return Jb;
    }
};
ScrewModel
makeTianyiArmModel(std::string urdf, int idx, std::string end_frame_name);
ScrewModel
makeTianyiFullModel(std::string urdf, int idx, std::string end_frame_name);

ScrewModel makeTianyiHeadModel(std::string urdf);
} // namespace robotic

#endif // MODEL_HPP
