#ifndef CSPACETARGET_HPP
#define CSPACETARGET_HPP

namespace RMP {
using namespace std::placeholders;
/*--------------------------------- C-Space Target RMP
 * ---------------------------------------*/
/* 关节空间目标角度
 */
namespace _CSpaceTarget {
    struct Data {
        Eigen::VectorXd q0;
        Eigen::VectorXd kp;
        Eigen::VectorXd kd;
        Eigen::VectorXd theta;
        Eigen::VectorXd m;
    };
    inline Eigen::VectorXd psi(Data &data, const Eigen::VectorXd &q) {
        return q;
    }

    inline Eigen::MatrixXd J(Data &data, const Eigen::VectorXd &q) {
        int dim = q.rows();
        Eigen::MatrixXd J(dim, dim);
        J.setIdentity();
        return J;
    }

    inline Eigen::MatrixXd
    dJdt(Data &data, const Eigen::VectorXd &q, const Eigen::VectorXd &dq) {
        int dim = q.rows();
        Eigen::MatrixXd dot_J(dim, dim);
        dot_J.setZero();
        return dot_J;
    }

    inline void
    rmp(Data &data,
        const Eigen::VectorXd &x,
        const Eigen::VectorXd &dx,
        Eigen::VectorXd &f,
        Eigen::MatrixXd &M,
        Eigen::VectorXd &a) {
        Eigen::VectorXd diff, r;
        M = data.m.asDiagonal();
        r = Eigen::VectorXd::Zero(x.rows());
        diff = data.q0 - x;
        // 不同关节独立计算，如果误差小于theta，则为pd控制，否则p部分恒定一个误差大小theta
        for (int k = 0; k < x.rows(); ++k) {
            if (std::abs(diff(k)) < data.theta(k)) {
                r(k) = diff(k);
            } else {
                diff(k) > 0 ? (r(k) = data.theta(k)) : (r(k) = -data.theta(k));
            }
        }
        a = data.kp.cwiseProduct(r) - data.kd.cwiseProduct(dx);
        f = M * a;
    }
} // namespace _CSpaceTarget
struct CSpaceTarget : public Leaf {
    CSpaceTarget(
        std::string name, Node *parent, _CSpaceTarget::Data &data, int dim)
        : Leaf(
            name,
            dim,
            parent,
            std::bind(RMP::_CSpaceTarget::psi, data, _1),
            std::bind(RMP::_CSpaceTarget::J, data, _1),
            std::bind(RMP::_CSpaceTarget::dJdt, data, _1, _2),
            std::bind(RMP::_CSpaceTarget::rmp, data, _1, _2, _3, _4, _5)) {}
};
} // namespace RMP

#endif // CSPACETARGET_HPP
