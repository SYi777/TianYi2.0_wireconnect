#ifndef RMPFLOW_NODE_HPP
#define RMPFLOW_NODE_HPP
/*
 * RMPflow的中间节点用于流形切换
 */

#include "RMPflow/RMPflow.hpp"

namespace RMP {
using namespace std::placeholders;
// 选择位形空间的部分自由度
namespace _SubCSpace {

    inline Eigen::VectorXd psi(std::vector<int> idx, const Eigen::VectorXd &q) {
        Eigen::VectorXd out;
        int dim_out = idx.size();
        // int dim_in = q.rows();
        out = Eigen::VectorXd::Zero(dim_out);
        for (int i = 0; i < dim_out; i++) { out(i) = q(idx.at(i)); }
        return out;
    }

    inline Eigen::MatrixXd J(std::vector<int> idx, const Eigen::VectorXd &q) {
        int dim_out = idx.size();
        int dim_in = q.rows();
        Eigen::MatrixXd J_out;
        J_out = Eigen::MatrixXd::Zero(dim_out, dim_in);
        for (int i = 0; i < dim_out; i++) {
            int j = idx.at(i);
            J_out(i, j) = 1.0;
        }
        return J_out;
    }

    inline Eigen::MatrixXd dJdt(
        std::vector<int> idx,
        const Eigen::VectorXd &q,
        const Eigen::VectorXd &dq) {
        int dim_out = idx.size();
        int dim_in = q.rows();
        Eigen::MatrixXd dot_J;
        dot_J = Eigen::MatrixXd::Zero(dim_out, dim_in);
        return dot_J;
    }

} // namespace _SubCSpace

struct SubCSpace : public Node {
    // 选择多个自由度
    SubCSpace(std::string name, Node *parent, std::vector<int> idx)
        : Node(
            name,
            idx.size(),
            parent,
            std::bind(RMP::_SubCSpace::psi, idx, _1),
            std::bind(RMP::_SubCSpace::J, idx, _1),
            std::bind(RMP::_SubCSpace::dJdt, idx, _1, _2)) {}
    // 选择单个自由度
    SubCSpace(std::string name, Node *parent, int idx)
        : Node(
            name,
            1,
            parent,
            std::bind(RMP::_SubCSpace::psi, std::vector<int>{idx}, _1),
            std::bind(RMP::_SubCSpace::J, std::vector<int>{idx}, _1),
            std::bind(RMP::_SubCSpace::dJdt, std::vector<int>{idx}, _1, _2)) {}
};

namespace _InverseSubCSpace {

    inline Eigen::VectorXd psi(std::vector<int> idx, const Eigen::VectorXd &q) {
        Eigen::VectorXd out;
        int dim_out = idx.size();
        // int dim_in = q.rows();
        out = Eigen::VectorXd::Zero(dim_out);
        for (int i = 0; i < dim_out; i++) { out(i) = -q(idx.at(i)); }
        return out;
    }

    inline Eigen::MatrixXd J(std::vector<int> idx, const Eigen::VectorXd &q) {
        int dim_out = idx.size();
        int dim_in = q.rows();
        Eigen::MatrixXd J_out;
        J_out = Eigen::MatrixXd::Zero(dim_out, dim_in);
        for (int i = 0; i < dim_out; i++) {
            int j = idx.at(i);
            J_out(i, j) = -1.0;
        }
        return J_out;
    }

    inline Eigen::MatrixXd dJdt(
        std::vector<int> idx,
        const Eigen::VectorXd &q,
        const Eigen::VectorXd &dq) {
        int dim_out = idx.size();
        int dim_in = q.rows();
        Eigen::MatrixXd dot_J;
        dot_J = Eigen::MatrixXd::Zero(dim_out, dim_in);
        return dot_J;
    }

} // namespace _InverseSubCSpace

struct InverseSubCSpace : public Node {
    // 选择多个自由度
    InverseSubCSpace(std::string name, Node *parent, std::vector<int> idx)
        : Node(
            name,
            idx.size(),
            parent,
            std::bind(RMP::_InverseSubCSpace::psi, idx, _1),
            std::bind(RMP::_InverseSubCSpace::J, idx, _1),
            std::bind(RMP::_InverseSubCSpace::dJdt, idx, _1, _2)) {}
    // 选择单个自由度
    InverseSubCSpace(std::string name, Node *parent, int idx)
        : Node(
            name,
            1,
            parent,
            std::bind(RMP::_InverseSubCSpace::psi, std::vector<int>{idx}, _1),
            std::bind(RMP::_InverseSubCSpace::J, std::vector<int>{idx}, _1),
            std::bind(
                RMP::_InverseSubCSpace::dJdt, std::vector<int>{idx}, _1, _2)) {}
};

namespace _SigmoidNode {
    struct Data {
        Eigen::VectorXd upper;
        Eigen::VectorXd lower;
    };
    inline Eigen::VectorXd psi(Data &d, const Eigen::VectorXd &q) {
        Eigen::VectorXd out;
        int dim = q.rows();
        out = q;
        for (int i = 0; i < dim; i++) {
            double sigmoid = 1 / (1 + std::exp(-q(i)));
            out(i) = d.lower(i) + sigmoid * (d.upper(i) - d.lower(i));
        }

        std::cout << "sigmoid inpuit : " << q.transpose() << std::endl;
        std::cout << "sigmoid output : " << out.transpose() << std::endl;
        std::cout << "sigmoid lower : " << d.lower.transpose() << std::endl;
        std::cout << "sigmoid upper : " << d.upper.transpose() << std::endl;
        return out;
    }

    inline Eigen::MatrixXd J(Data &d, const Eigen::VectorXd &q) {
        int dim = q.rows();
        Eigen::MatrixXd J_out;
        J_out = Eigen::MatrixXd::Zero(dim, dim);
        for (int i = 0; i < dim; i++) {
            double sigmoid = 1 / (1 + std::exp(-q(i)));
            double ds = sigmoid * (1 - sigmoid);
            J_out(i, i) = ds * (d.upper(i) - d.lower(i));
        }
        return J_out;
    }

    inline Eigen::MatrixXd
    dJdt(Data &d, const Eigen::VectorXd &q, const Eigen::VectorXd &dq) {
        int dim = q.rows();
        Eigen::MatrixXd dot_J;
        dot_J = Eigen::MatrixXd::Zero(dim, dim);
        for (int i = 0; i < dim; i++) {
            double s = 1 / (1 + std::exp(-q(i)));
            double dds = s * (1 - s) * (1 - 2 * s);
            dot_J(i, i) = dds * (d.upper(i) - d.lower(i));
        }
        return dot_J;
    }
} // namespace _SigmoidNode

struct SigmoidNode : public Node {
    // 选择多个自由度
    SigmoidNode(std::string name, Node *parent, _SigmoidNode::Data &data)
        : Node(
            name,
            data.lower.size(),
            parent,
            std::bind(RMP::_SigmoidNode::psi, data, _1),
            std::bind(RMP::_SigmoidNode::J, data, _1),
            std::bind(RMP::_SigmoidNode::dJdt, data, _1, _2)) {}
};

} // namespace RMP

#endif // RMPFLOW_NODE_HPP
