#pragma once

#include <torch/script.h>
#include <Eigen/Dense>
#include <vector>

namespace xarm_torch {
    // 从C++数组创建输入张量
inline torch::Tensor createInputFromArray(const std::vector<float>& values, int batch_size = 1) {
    // 创建张量: shape = (batch_size, input_dim)
    int input_dim = static_cast<int>(values.size());
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    torch::Tensor input = torch::from_blob(
        const_cast<float*>(values.data()),
        {batch_size, input_dim},
        options
    ).clone();  // clone()确保数据独立
    return input;
}

// 从单个样本创建输入
inline torch::Tensor createInputFromSingleSample(const std::vector<float>& values) {
    return createInputFromArray(values, 1);
}

// 从多个样本创建批量输入
inline torch::Tensor createBatchInput(const std::vector<std::vector<float>>& samples) {
    int batch_size = samples.size();
    int input_dim = samples[0].size();
    
    // 创建连续的内存块
    std::vector<float> flat_data;
    flat_data.reserve(batch_size * input_dim);
    for (const auto& sample : samples) {
        if (sample.size() != input_dim) {
            throw std::runtime_error("所有样本的维度必须相同");
        }
        flat_data.insert(flat_data.end(), sample.begin(), sample.end());
    }
    
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    return torch::from_blob(flat_data.data(), {batch_size, input_dim}, options).clone();
}


// 创建全零或全一的测试输入
inline torch::Tensor createTestInput(int batch_size, int input_dim, bool use_ones = false) {
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    if (use_ones) {
        return torch::ones({batch_size, input_dim}, options);
    } else {
        return torch::zeros({batch_size, input_dim}, options);
    }
}

// 从Eigen向量创建输入张量
inline torch::Tensor createInputFromEigenVector(const Eigen::VectorXf& eigen_vec, int batch_size = 1) {
    // Eigen向量转PyTorch张量
    int input_dim = eigen_vec.size();
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    
    // 如果batch_size=1，直接创建 (1, input_dim) 的张量
    if (batch_size == 1) {
        return torch::from_blob(
            const_cast<float*>(eigen_vec.data()),
            {1, input_dim},
            options
        ).clone();
    } else {
        // 批量输入：复制向量batch_size次
        std::vector<float> flat_data;
        flat_data.reserve(batch_size * input_dim);
        for (int i = 0; i < batch_size; i++) {
            for (int j = 0; j < input_dim; j++) {
                flat_data.push_back(eigen_vec(j));
            }
        }
        return torch::from_blob(flat_data.data(), {batch_size, input_dim}, options).clone();
    }
}


// 从Eigen矩阵创建批量输入张量
inline torch::Tensor createInputFromEigenMatrix(const Eigen::MatrixXf& eigen_mat) {
    // Eigen矩阵: (rows, cols) -> PyTorch张量: (batch_size, input_dim)
    int batch_size = eigen_mat.rows();
    int input_dim = eigen_mat.cols();
    
    // 将Eigen矩阵数据复制到连续内存
    std::vector<float> flat_data;
    flat_data.reserve(batch_size * input_dim);
    for (int i = 0; i < batch_size; i++) {
        for (int j = 0; j < input_dim; j++) {
            flat_data.push_back(eigen_mat(i, j));
        }
    }
    
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    return torch::from_blob(flat_data.data(), {batch_size, input_dim}, options).clone();
}

// 从Eigen Map创建输入（零拷贝，但需要确保数据生命周期）
// 支持const和非const的Eigen::Map
inline torch::Tensor createInputFromEigenMap(const Eigen::Map<Eigen::VectorXf>& eigen_map, int batch_size = 1) {
    int input_dim = eigen_map.size();
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    return torch::from_blob(
        const_cast<float*>(eigen_map.data()),
        {batch_size, input_dim},
        options
    ).clone();  // clone()确保数据独立，避免生命周期问题
}

// 从const Eigen::Map创建输入
inline torch::Tensor createInputFromEigenMap(const Eigen::Map<const Eigen::VectorXf>& eigen_map, int batch_size = 1) {
    int input_dim = eigen_map.size();
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);
    return torch::from_blob(
        const_cast<float*>(eigen_map.data()),
        {batch_size, input_dim},
        options
    ).clone();  // clone()确保数据独立，避免生命周期问题
}


// ========== PyTorch张量转Eigen ==========

// 将PyTorch张量转换为Eigen向量（单样本输出）
inline Eigen::VectorXf tensorToEigenVector(const torch::Tensor& tensor) {
    // 确保张量在CPU上且是连续内存
    torch::Tensor cpu_tensor = tensor.to(torch::kCPU).contiguous();
    
    // 检查维度
    if (cpu_tensor.dim() > 2) {
        throw std::runtime_error("张量维度超过2，无法转换为向量");
    }
    
    // 展平为一维
    torch::Tensor flat = cpu_tensor.flatten();
    int size = flat.size(0);
    
    // 创建Eigen向量
    Eigen::VectorXf eigen_vec(size);
    
    // 复制数据
    float* data_ptr = flat.data_ptr<float>();
    std::memcpy(eigen_vec.data(), data_ptr, size * sizeof(float));
    
    return eigen_vec;
}

// 将PyTorch张量转换为Eigen矩阵（批量输出）
inline Eigen::MatrixXf tensorToEigenMatrix(const torch::Tensor& tensor) {
    // 确保张量在CPU上且是连续内存
    torch::Tensor cpu_tensor = tensor.to(torch::kCPU).contiguous();
    
    // 检查维度
    if (cpu_tensor.dim() > 2) {
        throw std::runtime_error("张量维度超过2，无法转换为矩阵");
    }
    
    int rows, cols;
    if (cpu_tensor.dim() == 1) {
        // 一维张量：转换为行向量
        rows = 1;
        cols = cpu_tensor.size(0);
    } else {
        // 二维张量：(batch_size, feature_dim)
        rows = cpu_tensor.size(0);
        cols = cpu_tensor.size(1);
    }
    
    // 创建Eigen矩阵
    Eigen::MatrixXf eigen_mat(rows, cols);
    
    // 复制数据（注意Eigen是列优先，PyTorch是行优先）
    float* data_ptr = cpu_tensor.data_ptr<float>();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            eigen_mat(i, j) = data_ptr[i * cols + j];
        }
    }
    
    return eigen_mat;
}

// 将PyTorch张量转换为Eigen Map（零拷贝视图，注意数据生命周期）
inline Eigen::Map<Eigen::VectorXf> tensorToEigenMapVector(torch::Tensor& tensor) {
    // 确保张量在CPU上且是连续内存
    tensor = tensor.to(torch::kCPU).contiguous();
    
    // 展平为一维
    torch::Tensor flat = tensor.flatten();
    int size = flat.size(0);
    
    // 创建Eigen Map（零拷贝）
    float* data_ptr = flat.data_ptr<float>();
    return Eigen::Map<Eigen::VectorXf>(data_ptr, size);
}

// 将PyTorch张量转换为Eigen Map矩阵（零拷贝视图）
inline Eigen::Map<Eigen::MatrixXf> tensorToEigenMapMatrix(torch::Tensor& tensor) {
    // 确保张量在CPU上且是连续内存
    tensor = tensor.to(torch::kCPU).contiguous();
    
    int rows, cols;
    if (tensor.dim() == 1) {
        rows = 1;
        cols = tensor.size(0);
    } else {
        rows = tensor.size(0);
        cols = tensor.size(1);
    }
    
    // 创建Eigen Map（零拷贝，注意PyTorch是行优先）
    float* data_ptr = tensor.data_ptr<float>();
    return Eigen::Map<Eigen::MatrixXf>(data_ptr, rows, cols);
}


struct ModelWrapper {
    torch::jit::script::Module model;
    ModelWrapper() {}

    void init(const std::string& model_path){
        try {
            model = torch::jit::load(model_path, torch::kCPU);
            model.eval();
            model.to(torch::kCPU);
            std::cout << model_path <<" 模型加载成功！" << std::endl;
        } catch (const c10::Error& e) {
            std::cerr << model_path << " 模型加载失败. Error: " << e.what() << std::endl;
            throw std::runtime_error("模型加载失败");
        }
    }

    template<size_t batch_size, size_t input_dim>
    void warmup() {
        for (int i = 0; i < 10; ++i) {
            Eigen::MatrixXf dummy_input = Eigen::MatrixXf::Random(batch_size, input_dim);
            forward(dummy_input);
        }
    }

    Eigen::MatrixXf forward(const Eigen::MatrixXf& input) {
        torch::Tensor input_tensor = createInputFromEigenMatrix(input);
        std::vector<torch::jit::IValue> inputs;
        inputs.push_back(input_tensor);
        torch::Tensor output = model.forward(inputs).toTensor();
        return tensorToEigenMatrix(output);
    }
};

}


