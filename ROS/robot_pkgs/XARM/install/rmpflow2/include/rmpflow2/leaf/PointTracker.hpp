#ifndef POINTTRACKER_HPP
#define POINTTRACKER_HPP
#include "rmpflow2/RMPflow.hpp"
#include "rmpflow2/RMPflow_model.hpp"

namespace RMP {
using namespace std::placeholders;
/*--------------------------------- Target RMP
 * ---------------------------------------*/
/*    将控制点运动向目标点
 */
namespace _PointTracker {
    struct Data {
        model::PinocchioModel *model_ptr;
        std::string frame_name;
        std::vector<int> select_idx;
        Eigen::Vector3d x0{0, 0, 0};
        double kp = 100;
        double kd = 20;
        double eps = 0.1;
        double b = 2;
        double alpha_min = 0.1;
        double sigma_a = 0.2;  // 使用M_near的范围
        double sigma_b = 0.05; // 使用b被近端增强的范围
        double m_near = 100 * 100;
        double m_far = 100 * 10;
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

} // namespace _PointTracker

struct PointTracker : public Leaf {
    PointTracker(std::string name, Node *parent, _PointTracker::Data &data)
        : Leaf(
            name,
            3,
            parent,
            std::bind(RMP::_PointTracker::psi, data, _1),
            std::bind(RMP::_PointTracker::J, data, _1),
            std::bind(RMP::_PointTracker::dJdt, data, _1, _2),
            std::bind(RMP::_PointTracker::rmp, data, _1, _2, _3, _4, _5)) {
        this->data = data;
    }
    void collectInfo(std::vector<NodeInfo> &all_info) override {
        NodeInfo info;
        // 先收集本节点信息
        info.x = this->x;
        info.dx = this->dx;
        info.a = this->a;
        info.f = this->f;
        info.M = this->M;
        info.node_name = this->name;
        std::ostringstream stream;
        stream << "err_norm = " << (data.x0 - this->x).norm();
        info.extra_info = stream.str();
        all_info.push_back(info);
    }
    _PointTracker::Data data;
};
} // namespace RMP
#endif // POINTTRACKER_HPP
