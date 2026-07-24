#ifndef RMPFLOW_HPP
#define RMPFLOW_HPP

#pragma once
#include <memory>
#include <Eigen/Dense>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
namespace RMP {

/*
 *  auto psi = [](const Eigen::VectorXd& q) -> Eigen::VectorXd {}
 *  auto J = [](const Eigen::VectorXd& q) -> Eigen::MatrixXd {}
 *  auto dJ = [](const Eigen::VectorXd& q, const Eigen::VectorXd& dq) ->
 * Eigen::MatrixXd {} auto rmp = [](const Eigen::VectorXd& q, const
 * Eigen::VectorXd& dq, Eigen::VectorXd& f, Eigen::MatrixXd& M) {}
 */

typedef std::function<Eigen::VectorXd(const Eigen::VectorXd &)> psi_func;
typedef std::function<Eigen::MatrixXd(const Eigen::VectorXd &)> J_func;
typedef std::function<Eigen::MatrixXd(
    const Eigen::VectorXd &, const Eigen::VectorXd &)>
    dJ_func;

// x, dx, f, M, a
typedef std::function<void(
    const Eigen::VectorXd &,
    const Eigen::VectorXd &,
    Eigen::VectorXd &,
    Eigen::MatrixXd &,
    Eigen::VectorXd &)>
    RMP_func;

struct NodeInfo {
    std::string node_name;
    Eigen::VectorXd x;
    Eigen::VectorXd dx;
    Eigen::VectorXd f;
    Eigen::VectorXd a;
    Eigen::MatrixXd M;
    std::string extra_info;
};

class Node {
  public:
    Node(
        std::string name,
        int dim,
        Node *parent,
        psi_func psi,
        J_func J,
        dJ_func dJ,
        bool verbose = false);
    virtual ~Node() {}

    virtual void add_child(Node *child);

    virtual void pushforward();

    virtual void pullback();

    virtual void printinfo();

    virtual void collectInfo(std::vector<NodeInfo> &all_info);

    virtual void destroy();

    // 树结构
    std::string name;
    Node *parent;
    std::vector<Node *> children;

    // 状态
    Eigen::VectorXd x;  //状态
    Eigen::VectorXd dx; //状态微分
    int dim;            // 状态维度

    // 数据
    Eigen::VectorXd f; // 力
    Eigen::VectorXd a; // 加速度
    Eigen::MatrixXd M; // 惯性/黎曼度规

    // 模型
    psi_func psi; // 转移函数，输入父节点x，输出子节点x
    J_func J;     // 雅可比函数，输入父节点x，输出雅可比
    dJ_func dJ; // 雅可比的导数，输入父节点x,dx, 输出雅可比的导数

    bool verbose;
    bool time_analysis;
};

class Root : public Node {
  public:
    Root(int dim) : Node("root", dim, nullptr, nullptr, nullptr, nullptr) {}

    void set_root_state(const Eigen::VectorXd &x, const Eigen::VectorXd &dx);

    void pushforward() override;

    Eigen::VectorXd resolve();

    Eigen::VectorXd solve(Eigen::VectorXd x, Eigen::VectorXd dx);
};

class Leaf : public Node {
  public:
    Leaf(
        std::string name,
        int dim,
        Node *parent,
        psi_func psi,
        J_func J,
        dJ_func dJ,
        RMP_func rmp)
        : Node(name, dim, parent, psi, J, dJ), rmp_func(rmp) {}
    virtual void eval_leaf();

    void pullback() override;

    void add_child(Node *child) override;

    virtual void update_params();

    virtual void update();

    RMP_func rmp_func;
};

} // namespace RMP

#endif // RMPFLOW_HPP
