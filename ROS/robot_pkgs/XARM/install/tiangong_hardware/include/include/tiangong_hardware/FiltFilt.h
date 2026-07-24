#ifndef FILTFILT_H

#define FILTFILT_H

#include <Eigen/Dense>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>
#include <stdexcept>
class FiltFilt {
public:
    FiltFilt(); // 构造函数不传递滤波器系数
    //struct RobotData;
    struct RobotData {
        Eigen::VectorXd t;            // 时间向量
        Eigen::MatrixXd q;            // 原始位置 (num_samples x 7)
        Eigen::MatrixXd qd;           // 原始速度 (num_samples x 7)
        Eigen::MatrixXd cur;          // 原始电流 (num_samples x 7)
        Eigen::MatrixXd q_fltrd;      // 滤波后位置
        Eigen::MatrixXd qd_fltrd;     // 滤波后速度
        Eigen::MatrixXd q2d_est;      // 估计加速度
        Eigen::MatrixXd cur_fltrd;    // 滤波后电流
    };
    struct JointUrdf{
        std::string armType;
        Eigen::Vector3d origin_xyz;
        Eigen::Vector3d origin_rpy;
        Eigen::Vector3d axis;
    };
    // 滤波器状态结构体（每个数据通道独立一个）
    struct FilterState 
    {
        Eigen::VectorXd a_coeff;    // 分母系数
        Eigen::VectorXd b_coeff;    // 分子系数
        std::vector<double> in_buf; // 输入缓冲区
        std::vector<double> out_buf;// 输出缓冲区
        size_t pos = 0;             // 环形缓冲区位置

        // 初始化滤波器
        void initialize(const Eigen::VectorXd& a, const Eigen::VectorXd& b) 
        {
            a_coeff = a;
            b_coeff = b;
            in_buf.resize(b.size(), 0.0);
            out_buf.resize(a.size()-1, 0.0);
            pos = 0;
        }
    };
     // -------------------------- 矩阵声明（维度固定） --------------------------
    // 1. 左臂观测矩阵（不含电机动力学）：70行×45列
    static const Eigen::Matrix<double, 70, 45> EVT2_LeftArm_ObservationMatrixQR;
    // 2. 左臂观测矩阵（含电机动力学）：77行×50列
    static const Eigen::Matrix<double, 77, 50> EVT2_LeftArm_ObservationMatrixWithMotorDynamicsQR;
    // 3. 右臂观测矩阵（不含电机动力学）：70行×45列
    static const Eigen::Matrix<double, 70, 45> EVT2_RightArm_ObservationMatrixQR;
    // 4. 右臂观测矩阵（含电机动力学）：77行×50列
    static const Eigen::Matrix<double, 77, 50> EVT2_RightArm_ObservationMatrixWithMotorDynamicsQR;
    // -------------------------------------------------------------------
    int num_joints_arm;
    std::vector<JointUrdf> jointsRightArm;
    std::vector<JointUrdf> jointsLeftArm;
    void initializeJoints();
    Eigen::Matrix3d rotx(double theta);
    Eigen::Matrix3d roty(double theta);
    Eigen::Matrix3d rotz(double theta);
    Eigen::Matrix3d RotAxis(const Eigen::Vector3d& axis, double theta);

    Eigen::VectorXd filtfiltData(const Eigen::VectorXd& sig, const Eigen::VectorXd a, const Eigen::VectorXd b);
    void filterData(const Eigen::VectorXd& a_pos, const Eigen::VectorXd& b_pos,
                          const Eigen::VectorXd& a_vel, const Eigen::VectorXd& b_vel,
                          const Eigen::VectorXd& a_acc, const Eigen::VectorXd& b_acc,
                          const Eigen::VectorXd& a_cur, const Eigen::VectorXd& b_cur,
                          RobotData& data) ;
    std::array <Eigen::Matrix4d,7> forwardkinematics_ArmUrdf(const std::vector<JointUrdf>& jointsArm,const Eigen::VectorXd& theta);
    Eigen::MatrixXd Y_code_jointEvtArm(const std::vector<JointUrdf>& jointsArm,const Eigen::VectorXd& q,const Eigen::VectorXd& dq,const Eigen::VectorXd& ddq);

    void setLowPassFilter(const Eigen::VectorXd& a, const Eigen::VectorXd& b);
    double realtimeLowPassFilter(const Eigen::VectorXd& b, const Eigen::VectorXd& a,double input);
    static double process(FiltFilt::FilterState& state, double input);
    Eigen::MatrixXd readdata(std::string filepath);
    void buildObservationMatrices(const std::vector<JointUrdf>& jointsArm,const Eigen::Ref<const Eigen::MatrixXd>& q,         // numSteps x numJoints
        const Eigen::Ref<const Eigen::MatrixXd>& qd_fltrd,   // numSteps x numJoints
        const Eigen::Ref<const Eigen::MatrixXd>& q2d_est,    // numSteps x numJoints
        const Eigen::Ref<const Eigen::MatrixXd>& i_fltrd,    // numSteps x numJoints
        //const Eigen::Ref<const Eigen::MatrixXd>& E1,         // numBaseParams x numReducedParams
        const Eigen::Ref<const Eigen::VectorXd>& drvGains,   // numJoints x 1
        bool motorDynamicsIncluded,
        Eigen::MatrixXd& Wb,                          // 输出观测矩阵
        Eigen::VectorXd& Tau);                        // 输出扭矩向量
    void ordinaryLeastSquareEstimation(const Eigen::Ref<const Eigen::VectorXd>& Tau, 
            const Eigen::Ref<const Eigen::MatrixXd>& Wb, 
            Eigen::VectorXd& pi_OLS) ;
    Eigen::MatrixXd get_base_params_qr(const std::vector<JointUrdf>& jointsArm,bool includeMotorDynamics);
    Eigen::MatrixXd regressorWithMotorDynamics(const std::vector<JointUrdf>& jointsArm,const Eigen::VectorXd& q,const Eigen::VectorXd& dq,const Eigen::VectorXd& ddq);
    Eigen::MatrixXd frictionRegressor(const Eigen::VectorXd& qd_fltrd);
    void calculateDynamicThresholds(const Eigen::VectorXd& qd_fltrd, const Eigen::VectorXd& Fs,const Eigen::VectorXd& beita,
                                    const Eigen::VectorXd& Fv,       const Eigen::VectorXd& alpha,const Eigen::VectorXd& Fc,
                                    const Eigen::VectorXd& xigema,   const Eigen::VectorXd& yuzhi_up,const Eigen::VectorXd& yuzhi_down,
                                    Eigen::VectorXd& dynamic_yuzhi_up, Eigen::VectorXd& dynamic_yuzhi_down);
    void AdmittanceJointControl(
                                    const Eigen::VectorXd& tau_ext,
                                    const Eigen::VectorXd& delta_pos,
                                    const Eigen::VectorXd& delta_vel,
                                    const Eigen::VectorXd& M,
                                    const Eigen::VectorXd& D,
                                    const Eigen::VectorXd& K,
                                    double dt, // 新增时间步长参数
                                    Eigen::VectorXd& delta_vel_out);
    double AdmittanceJointControl(const double& tau_ext, const double& delta_pos, const double& delta_vel, 
                                  const double& M, const double& D, const double& K);
    void load_regressor_right_arm(const double in1[7], const double in2[7],
                                     const double in3[7], double Y_l[70]);
    void Regressor_payload_right_arm(const Eigen::Matrix<double, 7, 1>& in1, 
                                        const Eigen::Matrix<double, 7, 1>& in2, 
                                        const Eigen::Matrix<double, 7, 1>& in3, 
                                        Eigen::Matrix<double, 7, 10>& Y_l); 
    void load_regressor_left_arm(const double in1[7], const double in2[7],
                                     const double in3[7], double Y_l[70]);
    void Regressor_payload_left_arm(const Eigen::Matrix<double, 7, 1>& in1, 
                                        const Eigen::Matrix<double, 7, 1>& in2, 
                                        const Eigen::Matrix<double, 7, 1>& in3, 
                                        Eigen::Matrix<double, 7, 10>& Y_l); 
private:
    //void designButterworthFilter(int order, double sampleRate, double cutoffFreq, Eigen::VectorXd& a, Eigen::VectorXd& b);
    void filtData(const Eigen::VectorXd& sig, Eigen::VectorXd& sout, const Eigen::VectorXd& a, const Eigen::VectorXd& b, const Eigen::VectorXd& zi);
    void signalExtend(const Eigen::VectorXd& sig, Eigen::VectorXd& sout, int nfact);
    void dataRollover(const Eigen::VectorXd& sig, Eigen::VectorXd& sout);
    Eigen::VectorXd ComputeZi(const Eigen::VectorXd& a, const Eigen::VectorXd& b);
    double realfilter(const Eigen::VectorXd& b, const Eigen::VectorXd& a, double input);
    
    Eigen::Matrix3d skew(const Eigen::Vector3d& v);
    // 实现 kew 函数 将 3D 向量转换为3*6矩阵
    Eigen::MatrixXd kew(const Eigen::Vector3d& x);
    
    // 滤波器状态
    std::vector<double> inputHistory_; // 历史输入
    std::vector<double> outputHistory_; // 历史输出
};

#endif // FILTFILT_H