#pragma once

#include <ucbp/ucbp.h>
#include <thread>
#include "ZeroerrMotorDevice.h"

namespace zeroerr {

class ZeroerrMotorGroup : public ucbp::MotorDeviceGroup {
public:
    virtual std::shared_ptr<ucbp::Device> GenerateDevice(int& name, std::vector<int>& canIds, int& slaveId, int& channel,
        std::vector<int>& passages, int& type, int& mode, int& protocol, double& rateWork, double& rateReq) override {

            //EyouMotorDevice(int name, int slave, int channel, int passageReq, int passageResp, uint16_t id, Mode mode, Type type, double rateWork, double rateReq);
        return std::make_shared<ZeroerrMotorDevice>(name, slaveId, channel, passages[0], passages[1], canIds[0], (ZeroerrMotorDevice::Mode)mode, rateWork, rateReq);
    }
};

}