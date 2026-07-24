#pragma once

#include <ucbp/ucbp.h>
#include <mutex>
#include <functional>
#include <list>

namespace zeroerr {

class ZeroerrMotorDevice : public ucbp::MotorDevice {
public:
    enum class Mode : int {
        // 原生模式支持
        PV = 1,    // 轮廓速度模式，上报位置、速度和错误

        // 带规划的模式支持
        UPP = 11,   // 目标位置匀速规划模式（Uniform speed Planning mode for target Position），上报位置和错误
    }; 
    ZeroerrMotorDevice(int name, int slave, int channel, int passageReq, int passageResp, uint16_t id, Mode mode, double rateWork, double rateReq);

    void CmdSetMotorPosition(float position, float maxSpeed);
    void CmdSetMotorSpeed(double vel);

    void Init() override;
    virtual void Enable() override;
    void CheckLost() override;

protected:
    enum class MotionIns : uint32_t {
        CS_POSITION = 0x08,     // 周期同步位置模式
        CS_TORQUE = 0x0A,       // 周期同步扭矩模式
        CS_VELOCITY = 0x09,       // 周期同步速度模式
    };
    int slave;
    int passageReq;
    int passageResp;
    bool passageRespNotActive = true;

    uint16_t id;
    LockFreeQueue<DeviceMessage*> reqQueue;
    std::mutex mtxOpt;
    bool started = false;
    int skipCount = 0;
    uint32_t readyCode = 0;

    // motor data cache
    int DriverEnable = 3;// =1时表示电机使能，=0时表示电机失能,初始化一个非状态数
    int DriverMode = 0; // 记录每个电机当前的运行模式
    int ReceivePos = 0;  //接收到的各电机位置信息，编码器脉冲数
    int ReceiveVel = 0;  //接收到的各电机速度信息，编码器脉冲数
    int RatedCurrent = 0;  // 额定电流
    int ReceiveCurrent = 0;  //接收到的各电机速度信息
    long EncoderRes = 524288; // 编码器分辨率 各电机需要自己配置
    
    double Trans2Deg = (double)360/ EncoderRes;
    double ReceivePosDeg = 0;    //各电机位置信息转换为deg
    double ReceiveVelDeg = 0;    //各电机位置信息转换为deg/s
    signed short int SignedCurrent = 0;  //电流由无符号数转为有符号数
    // bool MotorCon = false;   // 用于记录通讯正常的电机数
    int ErrorCode;  //电机错误码603Fh
    std::mutex mtxStatus;
    bool statusReady[4] = {0};  // 0 - 速度；1 - 位置；2 - 电流；3 - 错误码
    bool running = true;

    std::mutex mtxSet;
    float targetPos = 0;
    double maxSpeed = 0;
    int maxSpeedSetting = 0;
    int lastTargetPos = 0;

    std::chrono::system_clock::time_point timeLastResp;

    static const uint32_t MASTER_ID = 127;
    // 速度模式参数
    double targetVel = 0;

    ZeroerrMotorDevice() = default;

protected:
    virtual void OnRequest(int passage, DeviceMessage& msg) override;
    virtual void OnResponse(int passage, DeviceMessage& msg) override;

    // 通用功能函数
    void Run();
    void GetInfo(DeviceMessage& msg);
    void PendRequest(ucbp::canopen::sdo::Request& req, int sleepMs = 0);
    bool PendHeartBeat(int skip, int sleepMs = 0);
    void StartHeartBeat();
    bool EnableMotor();
    bool DisableMotor();
    void GetMotorStatus();
    // 由于电机实现不同，启动时状态字不同。可以重写此方法，来进行不同的状态字处理
    virtual void OnStatusWord(uint32_t word);

    // PV模式函数
    virtual void RunPVMode();
    // 可重写此方法，来处理加速度配置
    void SetPVAccDec();
    bool SetPVMode();

    // UPP模式函数
    virtual void RunUPPMode();
    bool SetUPPMode();
    
    void SetMotorMode(MotionIns modeCode);

private:
    int motorNum = 6;//2*腰 + 2*腿
    unsigned int motorNameIds[6] = {31,32, 51,52};
    int motorDirection[6] = {1,-1, -1,1, 1,1};
    double motorOffset[6] = {0.0,0.0, 0.0,0.0, 0.0,0.0};
    double zeroOffset = 0.0;
    int nDirection = 1;

};

}
