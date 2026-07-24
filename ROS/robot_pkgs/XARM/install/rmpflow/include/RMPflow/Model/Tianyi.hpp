#ifndef RMPflow_Model_TIANYI_HPP
#define RMPflow_Model_TIANYI_HPP

#include "RMPflow/RMPflow_model.hpp"

namespace RMP::model {
ScrewModel makeTianyiArmModel(
    std::string urdf,
    int idx,
    std::string end_frame_name = "wrist_roll_l_link");
ScrewModel makeTianyiFullModel(
    std::string urdf,
    int idx,
    std::string end_frame_name = "wrist_roll_l_link");
}

#endif // RMPflow_Model_TIANYI_HPP
