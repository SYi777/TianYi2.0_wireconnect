#ifndef DAMPER_HPP
#define DAMPER_HPP

#include "RMPflow/RMPflow.hpp"

namespace RMP {
using namespace std::placeholders;

namespace _Damper {
    struct Data {
        Eigen::VectorXd kd;
        Eigen::VectorXd m;
    };
    Eigen::VectorXd psi(Data &data, const Eigen::VectorXd &q);
    Eigen::MatrixXd J(Data &data, const Eigen::VectorXd &q);
    Eigen::MatrixXd
    dJdt(Data &data, const Eigen::VectorXd &q, const Eigen::VectorXd &dq);

    void
    rmp(Data &data,
        const Eigen::VectorXd &x,
        const Eigen::VectorXd &dx,
        Eigen::VectorXd &f,
        Eigen::MatrixXd &M,
        Eigen::VectorXd &a);

} // namespace _Damper
struct Damper : public Leaf {
    Damper(std::string name, Node *parent, _Damper::Data &data, int dim)
        : Leaf(
            name,
            dim,
            parent,
            std::bind(RMP::_Damper::psi, data, _1),
            std::bind(RMP::_Damper::J, data, _1),
            std::bind(RMP::_Damper::dJdt, data, _1, _2),
            std::bind(RMP::_Damper::rmp, data, _1, _2, _3, _4, _5)) {}
};
} // namespace RMP
#endif // DAMPER_HPP
