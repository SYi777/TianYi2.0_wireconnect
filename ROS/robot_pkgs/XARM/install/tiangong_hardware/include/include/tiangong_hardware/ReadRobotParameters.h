#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <Eigen/Dense>
#include <stdexcept>
#include <iostream>
struct RobotParameters {
    std::vector<double> noline_friction_alpha;
    std::vector<double> Motor_Ia;
    std::vector<double> link_masses;
    std::vector<Eigen::Vector3d> link_coms;
    std::vector<Eigen::Matrix3d> link_inertias;
    Eigen::Matrix<double, 21, 1> friction_params;
    
    // 参数描述信息
    std::map<std::string, std::string> param_descriptions;
};

inline RobotParameters loadRobotParameters(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        throw std::runtime_error("无法打开文件: " + filename);
    }


    // 1. 读取魔数（8字节）
    char magic[9] = {0};
    in.read(magic, 8);
    
    // 检查魔数（允许末尾有空格填充）
    std::string expected_magic = "ROBOPARAM";
    bool is_valid = true;
    for (int i = 0; i < 8; ++i) {
        char expected = (i < expected_magic.size()) ? expected_magic[i] : ' ';
        if (magic[i] != expected) {
            is_valid = false;
            break;
        }
    }
    
    if (!is_valid) {
        // 打印调试信息
        std::cerr << "实际魔数: [";
        for (int i = 0; i < 8; ++i) {
            std::cerr << (magic[i] ? magic[i] : ' ');
        }
        std::cerr << "]" << std::endl;
        throw std::runtime_error("魔数不匹配（期望 'ROBOPARAM'）");
    }

    // 2. 读取版本号
    uint8_t version;
    in.read(reinterpret_cast<char*>(&version), 1);
    if (version != 1) {
        throw std::runtime_error("版本号应为1");
    }

    RobotParameters params;
    std::map<std::string, std::vector<double>> param_map;

    auto readString = [&]() {
        uint16_t len;
        in.read(reinterpret_cast<char*>(&len), 2);
        std::string str(len, '\0');
        in.read(&str[0], len);
        return str;
    };

    auto readVector = [&]() {
        uint64_t count;
        in.read(reinterpret_cast<char*>(&count), 8);
        std::vector<double> vec(count);
        in.read(reinterpret_cast<char*>(vec.data()), count * sizeof(double));
        return vec;
    };

    // 读取所有参数段
    while (in.peek() != EOF) {
        std::string name = readString();
        std::string description = readString();
        std::vector<double> data = readVector();

        params.param_descriptions[name] = description;
        param_map[name] = data;
    }

    // 解析参数到结构体
    try {
        // 1. 非线性摩擦系数
        params.noline_friction_alpha = param_map.at("noline_friction_alpha");
        
        // 2. 电机电流参数
        params.Motor_Ia = param_map.at("Motor_Ia");
        
        // 3. 连杆质量
        params.link_masses = param_map.at("link_masses");
        
        // 4. 连杆质心位置
        size_t link_count = params.link_masses.size();
        params.link_coms.reserve(link_count);
        for (size_t i = 1; i <= link_count; ++i) {
            std::string key = "link_coms_";
            if (i < 10) key += "0";
            key += std::to_string(i);
            auto& vec = param_map.at(key);
            params.link_coms.emplace_back(vec[0], vec[1], vec[2]);
        }
        
        // 5. 连杆惯性张量
        params.link_inertias.reserve(link_count);
        for (size_t i = 1; i <= link_count; ++i) {
            std::string key = "link_inertia_";
            if (i < 10) key += "0";
            key += std::to_string(i);
            auto& vec = param_map.at(key);
            
            Eigen::Matrix3d mat;
            // 按列优先顺序填充矩阵
            for (int col = 0; col < 3; ++col) {
                for (int row = 0; row < 3; ++row) {
                    mat(row, col) = vec[col * 3 + row];
                }
            }
            params.link_inertias.push_back(mat);
        }
        
        // 6. 摩擦参数
        auto& vec = param_map.at("friction_params");
        for (int i = 0; i < 21; ++i) {
            params.friction_params(i) = vec[i];
        }
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("缺少必要的参数: " + std::string(e.what()));
    }

    return params;
}


