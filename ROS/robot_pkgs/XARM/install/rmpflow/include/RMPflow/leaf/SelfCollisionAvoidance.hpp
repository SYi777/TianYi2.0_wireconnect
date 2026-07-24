#ifndef SELFCOLLISIONAVOIDANCE_HPP
#define SELFCOLLISIONAVOIDANCE_HPP

#include "RMPflow/RMPflow.hpp"
#include "RMPflow/RMPflow_model.hpp"
namespace RMP {
using namespace std::placeholders;
/*--------------------------------- Collision Avoidance RMP
 * ---------------------------------------*/
/*    碰撞点回避
 */
namespace _SelfCollisionAvoidance {
    struct Data {
        model::ScrewModel *model_ptr1;
        model::ScrewModel *model_ptr2;
        double Rcollision = 0.1; // 碰撞球半径
        double kp = 100;
        double kd = 100;
        double lp = 0.01;
        double ld = 0.01;
        double eps_d = 5;
        double vd = 1.0;

        double lm = 0.01;
        double eps_m = 5;
        double m = 100 * 1000;

        double r = 0.02; // 彻底关闭碰撞抗拒的距离
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

} // namespace _SelfCollisionAvoidance

struct SelfCollisionAvoidance : public Leaf {
    SelfCollisionAvoidance(
        std::string name, Node *parent, _SelfCollisionAvoidance::Data &data)
        : Leaf(
            name,
            1,
            parent,
            std::bind(RMP::_SelfCollisionAvoidance::psi, data, _1),
            std::bind(RMP::_SelfCollisionAvoidance::J, data, _1),
            std::bind(RMP::_SelfCollisionAvoidance::dJdt, data, _1, _2),
            std::bind(
                RMP::_SelfCollisionAvoidance::rmp, data, _1, _2, _3, _4, _5)) {}
};

} // namespace RMP

#endif // SELFCOLLISIONAVOIDANCE_HPP
