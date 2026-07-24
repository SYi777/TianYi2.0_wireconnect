#ifndef JOINTLIMIT_HPP
#define JOINTLIMIT_HPP
#include "rmpflow2/RMPflow.hpp"
namespace RMP {
using namespace std::placeholders;

namespace _JointLimit {
    struct Data {
        Eigen::VectorXd lower;
        Eigen::VectorXd upper;
        double kp = 100.0;
        double kd = 20.0;
        double lp = 0.01;
        double eps_p = 1.0;
        double m = 100000.0;
        double lm = 0.01;
        double eps_m = 1.0;
        double vm = 1.0;
    };

    Eigen::VectorXd psi_lower(Data &data, const Eigen::VectorXd &q);
    Eigen::MatrixXd J_lower(Data &data, const Eigen::VectorXd &q);
    Eigen::VectorXd psi_upper(Data &data, const Eigen::VectorXd &q);
    Eigen::MatrixXd J_upper(Data &data, const Eigen::VectorXd &q);
    Eigen::MatrixXd
    dJdt(Data &data, const Eigen::VectorXd &q, const Eigen::VectorXd &dq);

    void
    rmp(Data &data,
        const Eigen::VectorXd &x,
        const Eigen::VectorXd &dx,
        Eigen::VectorXd &f,
        Eigen::MatrixXd &M,
        Eigen::VectorXd &a);

} // namespace _JointLimit

struct JointLimitLower : public Leaf {
    JointLimitLower(
        std::string name, Node *parent, _JointLimit::Data &data, int dim)
        : Leaf(
            name,
            dim,
            parent,
            std::bind(RMP::_JointLimit::psi_lower, data, _1),
            std::bind(RMP::_JointLimit::J_lower, data, _1),
            std::bind(RMP::_JointLimit::dJdt, data, _1, _2),
            std::bind(RMP::_JointLimit::rmp, data, _1, _2, _3, _4, _5)) {}
};

struct JointLimitUpper : public Leaf {
    JointLimitUpper(
        std::string name, Node *parent, _JointLimit::Data &data, int dim)
        : Leaf(
            name,
            dim,
            parent,
            std::bind(RMP::_JointLimit::psi_upper, data, _1),
            std::bind(RMP::_JointLimit::J_upper, data, _1),
            std::bind(RMP::_JointLimit::dJdt, data, _1, _2),
            std::bind(RMP::_JointLimit::rmp, data, _1, _2, _3, _4, _5)) {}
};

} // namespace RMP

#endif // JOINTLIMIT_HPP
