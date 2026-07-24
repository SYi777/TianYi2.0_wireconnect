#ifndef COLLISIONAVOIDANCE_HPP
#define COLLISIONAVOIDANCE_HPP

#include "RMPflow/RMPflow.hpp"
#include "RMPflow/RMPflow_model.hpp"
namespace RMP {
using namespace std::placeholders;
/*--------------------------------- Collision Avoidance RMP
 * ---------------------------------------*/
/*    碰撞点回避
 */
namespace _CollisionAvoidance {
    struct Data {
        model::ScrewModel *model_ptr;
        Eigen::Vector3d x0{0, 0, 0}; // 碰撞点
        double Rcollision = 0.1;     // 碰撞球半径
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

} // namespace _CollisionAvoidance

struct CollisionAvoidance : public Leaf {
    CollisionAvoidance(
        std::string name, Node *parent, _CollisionAvoidance::Data &data)
        : Leaf(
            name,
            1,
            parent,
            std::bind(RMP::_CollisionAvoidance::psi, data, _1),
            std::bind(RMP::_CollisionAvoidance::J, data, _1),
            std::bind(RMP::_CollisionAvoidance::dJdt, data, _1, _2),
            std::bind(
                RMP::_CollisionAvoidance::rmp, data, _1, _2, _3, _4, _5)) {}
};

} // namespace RMP

#endif // COLLISIONAVOIDANCE_HPP
