#ifndef TARGETAXIS_HPP
#define TARGETAXIS_HPP

#include "RMPflow/RMPflow.hpp"
#include "RMPflow/RMPflow_model.hpp"
namespace RMP {
using namespace std::placeholders;

namespace _TargetAxis {
    struct Data {
        model::ScrewModel *model_ptr;
        Eigen::Vector3d n0{1, 0, 0};
        double kp = 100;
        double kd = 20;
        double b = 2;
        double sigma_b = 0.05; // 使用b被近端增强的范围
        double m = 100 * 100;
    };
    Eigen::VectorXd psi(Data &data, int idx, const Eigen::VectorXd &q);
    Eigen::MatrixXd J(Data &data, int idx, const Eigen::VectorXd &q);
    Eigen::MatrixXd dJdt(
        Data &data,
        int idx,
        const Eigen::VectorXd &q,
        const Eigen::VectorXd &dq);

    void
    rmp(Data &data,
        int idx,
        const Eigen::VectorXd &x,
        const Eigen::VectorXd &dx,
        Eigen::VectorXd &f,
        Eigen::MatrixXd &M,
        Eigen::VectorXd &a);

} // namespace _TargetAxis

struct TargetAxis : public Leaf {
    TargetAxis(std::string name, Node *parent, _TargetAxis::Data &data, int idx)
        : Leaf(
            name,
            3,
            parent,
            std::bind(RMP::_TargetAxis::psi, data, idx, _1),
            std::bind(RMP::_TargetAxis::J, data, idx, _1),
            std::bind(RMP::_TargetAxis::dJdt, data, idx, _1, _2),
            std::bind(RMP::_TargetAxis::rmp, data, idx, _1, _2, _3, _4, _5)) {}
};
} // namespace RMP

#endif // TARGETAXIS_HPP
