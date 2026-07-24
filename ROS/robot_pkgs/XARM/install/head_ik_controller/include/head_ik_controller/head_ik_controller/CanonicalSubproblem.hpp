#ifndef CANONICALSUBPROBLEMS_HPP
#define CANONICALSUBPROBLEMS_HPP

#include "Eigen/Dense"
#include "mr/modern_robotics.h"
#include <iostream>
namespace robotic {
using namespace Eigen;

struct CanonicalSubproblem {
    bool success = false;
};

/*
 * Paden-Kahan子问题 subproblem 1
 *  w为参考轴，r为轴上一点,从p转到q所需角度theta
 *  Inputs:
 *           p: 3x1 vector
 *           q: 3x1 vector
 *           w: 3x1 vector with norm(w) = 1
 *           r: 3x1 vector
 *  Outputs:
 *          theta: 1x1 angle (in radians)
 *          success: boolean
 * */
struct PKsub_Q1 : public CanonicalSubproblem {
    explicit PKsub_Q1(
        const Eigen::Vector3d &p,
        const Eigen::Vector3d &q,
        const Eigen::Vector3d &w,
        const Eigen::Vector3d &r,
        double tol = 1E-8)
        : p(p), q(q), w(w), r(r) {
        auto p1 = p - r;
        auto p2 = q - r;
        const auto &k = w;
        auto Kxp = k.cross(p1);
        Eigen::Matrix<double, 3, 2> A;
        A.col(0) = Kxp;
        A.col(1) = Kxp.cross(k);
        auto x = A.transpose() * p2;
        result = atan2(x(0), x(1));
        if (std::abs(p1.norm() - p2.norm()) > tol
            || std::abs(k.dot(p1) - k.dot(p2)) > tol)
            success = false;
        else
            success = true;
    }

  public:
    double result = {};

  private:
    Eigen::Vector3d p;
    Eigen::Vector3d q;
    Eigen::Vector3d w;
    Eigen::Vector3d r;
};

/*
 *  % subproblem.sp_4  Subproblem 4: Circle and plane
    % This code base on https://github.com/rpiRobotics/ik-geo.git
    %   theta = = subproblem.sp_4(h, p, k, d) finds theta such that
    %       h'*rot(k,theta)*p = d
    %   If there's no solution, minimize the least-squares residual
    %       | h'*rot(k,theta)*p - d |
    %
    %   If the problem is well-posed, there may be 1 or 2 exact solutions, or 1
    %   least-squares solution
    %   theta1 and theta2 are column vectors of the solutions
    %
    %   [theta, is_LS] = subproblem.sp_4(h, p, k, d) also produces
    %   a flag is_LS, which is true if theta is a least-squares solution
    %
    %   The problem is ill-posed if (p, k) or (h, k) are parallel
     *  Inputs:
     *           h: 3x1 vector with norm(h) = 1
     *           p: 3x1 vector
     *           k: 3x1 vector with norm(k) = 1
     *           d: 1x1
     *  Outputs:
     *          result1: 1x1 angle  (in radians)
     *          result2: 1x1 angle
     *          success: boolean
     * */

struct PKsub_Q4 : public CanonicalSubproblem {
    explicit PKsub_Q4(
        const Eigen::Vector3d &h,
        const Eigen::Vector3d &p,
        const Eigen::Vector3d &k,
        double d,
        double tol = 1E-8)
        : h(h), p(p), k(k), d(d) {
        auto A_11 = k.cross(p);
        Eigen::Matrix<double, 3, 2> A_1;
        A_1.col(0) = A_11;
        A_1.col(1) = A_11.cross(k);
        auto A = h.transpose() * A_1;
        auto b = d - (h.transpose() * k * k.transpose() * p);
        auto x_ls_tilde = A_1.transpose() * h * b;
        double norm_A_2 = A.dot(A);
        Vector2d theta;
        if (norm_A_2 > b * b) {
            auto xi = sqrt(norm_A_2 - b * b);
            Vector2d x_N_prime_tilde({A(1), -A(0)});
            auto sc_1 = x_ls_tilde + xi * x_N_prime_tilde;
            auto sc_2 = x_ls_tilde - xi * x_N_prime_tilde;
            result1 = atan2(sc_1(0), sc_1(1));
            result2 = atan2(sc_2(0), sc_2(1));
            success = true;
        } else {
            result1 = atan2(x_ls_tilde(0), x_ls_tilde(1));
            result2 = atan2(x_ls_tilde(0), x_ls_tilde(1));
            success = false; // 无解时求得是最小二乘
        }
    }

  public:
    double result1 = {};
    double result2 = {};

  private:
    Eigen::Vector3d h;
    Eigen::Vector3d p;
    Eigen::Vector3d k;
    double d;
};

/*
 * Paden-Kahan子问题 subproblem 2
 *  w1,w2为参考轴，r为两轴交点,从p转到q所需角度theta
 *  Inputs:
 *           p: 3x1 vector
 *           q: 3x1 vector
 *           w1: 3x1 vector with norm(w) = 1
 *           w2: 3x1 vector with norm(w) = 1
 *           r: 3x1 vector
 *  Outputs:
 *          result1: 2x1 angle  (in radians)
 *          result2: 2x1 angle  (in radians)
 *          success: boolean
 * */
struct PKsub_Q2 : public CanonicalSubproblem {
    explicit PKsub_Q2(
        const Eigen::Vector3d &p,
        const Eigen::Vector3d &q,
        const Eigen::Vector3d &w1,
        const Eigen::Vector3d &w2,
        const Eigen::Vector3d &r,
        double tol = 1E-8)
        : p(p), q(q), w1(w1), w2(w2), r(r) {
        auto p2 = p - r;
        auto p1 = q - r;
        auto k1 = -w1;
        const auto &k2 = w2;
        auto p1_nrm = p1 / p1.norm();
        auto p2_nrm = p2 / p2.norm();

        PKsub_Q4 subq4_1(k2, p1_nrm, k1, k2.dot(p2_nrm));
        PKsub_Q4 subq4_2(k1, p2_nrm, k2, k1.dot(p1_nrm));
        bool is_LS = abs(p1.norm() - p2.norm()) > tol || !subq4_1.success
                     || !subq4_2.success;

        success = !is_LS;

        result1(0) = subq4_1.result1;
        result1(1) = subq4_2.result2;

        result2(0) = subq4_1.result2;
        result2(1) = subq4_2.result1;
    }

  public:
    Vector2d result1 = {};
    Vector2d result2 = {};

  private:
    Eigen::Vector3d p;
    Eigen::Vector3d q;
    Eigen::Vector3d w1;
    Eigen::Vector3d w2;
    Eigen::Vector3d r;
};

/*
 * Paden-Kahan子问题 subproblem 3
 *  w参考轴，r为轴上一点,从p转到距q点d的位置，所需角度theta
 *  Inputs:
 *           p: 3x1 vector
 *           q: 3x1 vector
 *           w: 3x1 vector with norm(w) = 1
 *           r: 3x1 vector
 *           d: 1x1 double
 *  Outputs:
 *          result1: 1x1 angle  (in radians)
 *          result2: 1x1 angle  (in radians)
 *          success: boolean
 * */
struct PKsub_Q3 : public CanonicalSubproblem {
    explicit PKsub_Q3(
        const Eigen::Vector3d &p,
        const Eigen::Vector3d &q,
        const Eigen::Vector3d &w,
        const Eigen::Vector3d &r,
        double d,
        double tol = 1E-8)
        : p(p), q(q), w(w), r(r), d(d) {
        // auto p1 = p - r;
        // auto p2 = q - r;
        // auto k = w;

        // PKsub_Q4 solver(p2, p1, k, 0.5*(p1.dot(p1) + p2.dot(p2) - d*d));

        auto u = p - r;
        auto v = q - r;
        auto u_p = u - w * w.transpose() * u;
        auto v_p = v - w * w.transpose() * v;

        double temp = w.transpose() * (p - q);
        double ddp = d * d - temp * temp;

        double theta0 =
            std::atan2(w.transpose() * u_p.cross(v_p), u_p.transpose() * v_p);
        double unorm = u_p.norm();
        double vnorm = v_p.norm();
        double num = unorm * unorm + vnorm * vnorm - ddp;
        double den = 2 * unorm * vnorm;
        if (std::abs(num) > den) {
            success = false;
            result1 = theta0;
            result2 = theta0;
        } else {
            double delta = std::acos(num / den);
            success = true;
            result1 = theta0 + delta;
            result2 = theta0 - delta;
        }
    }

  public:
    double result1 = {};
    double result2 = {};

  private:
    Eigen::Vector3d p;
    Eigen::Vector3d q;
    Eigen::Vector3d w;
    Eigen::Vector3d r;
    double d;
};

/*
 * 子问题PRR，将点p经过PRR得到q,要求三个轴两两垂直
 *  给定平移轴v1，旋转轴w2，旋转轴w3, w2轴上点p2, w3轴上点p3
 *  Inputs:
 *           p: 3x1 vector
 *           q: 3x1 vector
 *           v1: 3x1 vector with norm = 1
 *           w2: 3x1 vector with norm = 1
 *           w3: 3x1 vector with norm = 1
 *           p2: 3x1 vector
 *           p3: 1x1 3x1 vector
 *  Outputs:
 *          result1: 3x1 angle  (in radians)
 *          result2: 3x1 angle  (in radians)
 *          result3: 3x1 angle  (in radians)
 *          result4: 3x1 angle  (in radians)
 *          success: boolean x 4
 *
 * */
struct PKsub_PRR : public CanonicalSubproblem {
    explicit PKsub_PRR(
        const Eigen::Vector3d &p,
        const Eigen::Vector3d &q,
        const Eigen::Vector3d &v1,
        const Eigen::Vector3d &w2,
        const Eigen::Vector3d &w3,
        const Eigen::Vector3d &p2,
        const Eigen::Vector3d &p3) {
        bool flag3 = false;
        bool flag2_1 = false;
        bool flag2_2 = false;

        // 构造投影
        auto r3 = p3 + w3 * w3.transpose() * (p - p3);
        auto u31 = p - r3;

        auto r2 = p2 + w2 * w2.transpose() * (q - p2);
        auto u11 = q - r2;

        auto u12 = u11 - v1 * v1.transpose() * u11;

        // 计算theta3
        auto fc1 = w2 * w2.transpose() * (r2 - r3);
        double fr3_length_square = u31.dot(u31) - fc1.dot(fc1);
        double fr3_length = {};
        if (fr3_length_square >= 0) // 开方之前需要为正
        {
            fr3_length = sqrt(fr3_length_square);
            flag3 = true;
        } else {
            fr3_length = 0;
            flag3 = false; // 无解
        }

        auto u32_1 = fc1 + fr3_length * v1;
        auto u32_2 = fc1 - fr3_length * v1;

        auto cos_theta3_1 = u31.dot(u32_1) / u31.norm() / u32_1.norm();
        auto cos_theta3_2 = u31.dot(u32_2) / u31.norm() / u32_2.norm();

        auto theta3_1 = acos(cos_theta3_1);
        auto theta3_2 = acos(cos_theta3_2);

        // 判断方向
        if (u31.cross(u32_1).dot(w3) < 0) theta3_1 = -theta3_1;

        if (u31.cross(u32_2).dot(w3) < 0) theta3_2 = -theta3_2;

        Eigen::Matrix<double, 6, 1> s3;
        s3 << w3, p3.cross(w3);
        Eigen::Vector4d p_coor({p(0), p(1), p(2), 1});

        auto c1_coor_1 = mr::MatrixExp6(mr::VecTose3(s3) * theta3_1) * p_coor;
        auto c1_coor_2 = mr::MatrixExp6(mr::VecTose3(s3) * theta3_2) * p_coor;

        Eigen::Vector3d c1_1(
            {c1_coor_1(0), c1_coor_1(1), c1_coor_1(2)}); // c1第一个解
        Eigen::Vector3d c1_2(
            {c1_coor_2(0), c1_coor_2(1), c1_coor_2(2)}); // c1第二个解

        // theta2 for case theta3_1
        Eigen::Vector3d c1 = c1_1; // 对c1第一个解求后续
        Eigen::Vector3d u21 = c1 - r2;
        double nc2_length_square =
            u21.dot(u21) - u12.dot(u12); // 这里需要判断 开方之前需要为正
        double nc2_length = {};
        if (nc2_length_square >= 0) {
            nc2_length = sqrt(nc2_length_square);
            flag2_1 = true;
        } else {
            nc2_length = 0;
            flag2_1 = false;
        }

        Eigen::Vector3d u22_1 = u12 + nc2_length * v1;
        Eigen::Vector3d u22_2 = u12 - nc2_length * v1;
        double cos_theta2_1 =
            u21.dot(u22_1) / u21.norm() / u22_1.norm(); // 除之前需要判断除0
        double cos_theta2_2 =
            u21.dot(u22_2) / u21.norm() / u22_2.norm(); // 除之前需要判断除0
        double theta2_1 = acos(cos_theta2_1); //% 反三角函数需要确保[-1 1]
        double theta2_2 = acos(cos_theta2_2);

        // 判断方向
        if (u21.cross(u22_1).dot(w2) < 0) theta2_1 = -theta2_1;
        if (u21.cross(u22_2).dot(w2) < 0) theta2_2 = -theta2_2;

        Eigen::Matrix<double, 6, 1> s2;
        s2 << w2, p2.cross(w2);

        Eigen::Vector4d c2_coor_1 =
            mr::MatrixExp6(mr::VecTose3(s2) * theta2_1) * c1_coor_1;
        Eigen::Vector4d c2_coor_2 =
            mr::MatrixExp6(mr::VecTose3(s2) * theta2_2) * c1_coor_1;
        Eigen::Vector3d c2_1(
            {c2_coor_1(0), c2_coor_1(1), c2_coor_1(2)}); // c2第一个解
        Eigen::Vector3d c2_2(
            {c2_coor_2(0), c2_coor_2(1), c2_coor_2(2)}); // c2第二个解

        double theta1_1 = (q - c2_1).dot(v1); // 对应theta1第一个解
        double theta1_2 = (q - c2_2).dot(v1); // 对应theta2第二个解
        result.at(0) = Eigen::Vector3d({theta1_1, theta2_1, theta3_1});
        result.at(1) = Eigen::Vector3d({theta1_2, theta2_2, theta3_1});

        // theta2 for case theta3_2
        c1 = c1_2;
        u21 = c1 - r2;
        nc2_length_square =
            u21.dot(u21) - u12.dot(u12); // 这里需要判断 开方之前需要为正
        if (nc2_length_square >= 0) {
            nc2_length = sqrt(nc2_length_square);
            flag2_2 = true;
        } else {
            nc2_length = 0;
            flag2_2 = false;
        }

        u22_1 = u12 + nc2_length * v1;
        u22_2 = u12 - nc2_length * v1;
        cos_theta2_1 =
            u21.dot(u22_1) / u21.norm() / u22_1.norm(); // 除之前需要判断除0
        cos_theta2_2 =
            u21.dot(u22_2) / u21.norm() / u22_2.norm(); // 除之前需要判断除0
        theta2_1 = acos(cos_theta2_1); //% 反三角函数需要确保[-1 1]
        theta2_2 = acos(cos_theta2_2);

        // 判断方向
        if (u21.cross(u22_1).dot(w2) < 0) theta2_1 = -theta2_1;
        if (u21.cross(u22_2).dot(w2) < 0) theta2_2 = -theta2_2;

        s2 << w2, p2.cross(w2);

        c2_coor_1 = mr::MatrixExp6(mr::VecTose3(s2) * theta2_1) * c1_coor_2;
        c2_coor_2 = mr::MatrixExp6(mr::VecTose3(s2) * theta2_2) * c1_coor_2;
        c2_1 = Eigen::Vector3d(
            {c2_coor_1(0), c2_coor_1(1), c2_coor_1(2)}); // c2第一个解
        c2_2 = Eigen::Vector3d(
            {c2_coor_2(0), c2_coor_2(1), c2_coor_2(2)}); // c2第二个解
        theta1_1 = (q - c2_1).dot(v1); // 对应theta1第一个解
        theta1_2 = (q - c2_2).dot(v1); // 对应theta2第二个解

        result.at(2) = Eigen::Vector3d({theta1_1, theta2_1, theta3_2});
        result.at(3) = Eigen::Vector3d({theta1_2, theta2_2, theta3_2});

        // 判断各个解是否有效
        if (flag3 && flag2_1 && flag2_2) success_sub = {true, true, true, true};
        else if (flag3 && flag2_1 && ~flag2_2)
            success_sub = {true, true, false, false};
        else if (flag3 && ~flag2_1 && flag2_2)
            success_sub = {false, false, true, true};
        else
            success_sub = {false, false, false, false};

        success = success_sub[0] || success_sub[1] || success_sub[2]
                  || success_sub[3];
    }

  public:
    std::array<Eigen::Vector3d, 4> result;
    std::array<bool, 4> success_sub;
};

} // namespace robotic

#endif // CANONICALSUBPROBLEMS_HPP
