// auto-generated DO NOT EDIT

#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <mutex>
#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <rclcpp/logger.hpp>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <parameter_traits/parameter_traits.hpp>

#include <rsl/static_string.hpp>
#include <rsl/static_vector.hpp>
#include <rsl/parameter_validators.hpp>



namespace endpose_dual_arm_qp_controller {

// Use validators from RSL
using rsl::unique;
using rsl::subset_of;
using rsl::fixed_size;
using rsl::size_gt;
using rsl::size_lt;
using rsl::not_empty;
using rsl::element_bounds;
using rsl::lower_element_bounds;
using rsl::upper_element_bounds;
using rsl::bounds;
using rsl::lt;
using rsl::gt;
using rsl::lt_eq;
using rsl::gt_eq;
using rsl::one_of;
using rsl::to_parameter_result_msg;

// temporarily needed for backwards compatibility for custom validators
using namespace parameter_traits;

template <typename T>
[[nodiscard]] auto to_parameter_value(T value) {
    return rclcpp::ParameterValue(value);
}

template <size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticString<capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_string(value));
}

template <typename T, size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticVector<T, capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_vector(value));
}
    struct Params {
        std::vector<std::string> joints = {};
        std::string interface_name = "position";
        std::vector<std::string> states = {"shoulder_pitch_l_joint", "shoulder_roll_l_joint", "shoulder_yaw_l_joint", "elbow_pitch_l_joint", "elbow_yaw_l_joint", "wrist_pitch_l_joint", "wrist_roll_l_joint", "shoulder_pitch_r_joint", "shoulder_roll_r_joint", "shoulder_yaw_r_joint", "elbow_pitch_r_joint", "elbow_yaw_r_joint", "wrist_pitch_r_joint", "wrist_roll_r_joint", "first_leg_pitch_joint", "second_leg_pitch_joint", "waist_pitch_joint", "waist_yaw_joint", "head_yaw_joint", "head_pitch_joint", "head_roll_joint"};
        std::vector<std::string> state_interface_name = {"position", "velocity"};
        int64_t arm_idx = 0;
        int64_t robot_idx = 0;
        std::vector<double> joint_upper_limits = {};
        std::vector<double> joint_lower_limits = {};
        std::vector<double> vel_limits = {};
        std::vector<double> acc_limits = {};
        std::vector<double> jerk_limits = {};
        std::vector<double> base_transform = {-0.049182, 0.0, -0.68, 0.0, 0.0, 0.0, 1.0};
        std::vector<double> target_transform = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
        double dis_err_bound = 0.2;
        double ori_err_bound = 1.0;
        std::vector<double> joint_home_pos = {};
        std::vector<double> collision_r = {};
        std::vector<double> collision_freeBall_pos = {110.0, 110.0, 110.0, 0.1};
        std::vector<double> OriWeight = {1.0, 1.0, 1.0};
        double otg_r_step = 0.01;
        double otg_p_step = 0.01;
        double redundant_degrees_left = 0.0;
        double redundant_degrees_right = 0.0;
        double redundant_degrees_weight = 0.0;
        bool collision_check = false;
        // for detecting if the parameter struct has been updated
        rclcpp::Time __stamp;
    };
    struct StackParams {
        int64_t arm_idx = 0;
        int64_t robot_idx = 0;
        double dis_err_bound = 0.2;
        double ori_err_bound = 1.0;
        double otg_r_step = 0.01;
        double otg_p_step = 0.01;
        double redundant_degrees_left = 0.0;
        double redundant_degrees_right = 0.0;
        double redundant_degrees_weight = 0.0;
        bool collision_check = false;
    };

  class ParamListener{
  public:
    // throws rclcpp::exceptions::InvalidParameterValueException on initialization if invalid parameter are loaded
    template <typename NodeT>
    ParamListener(NodeT node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  std::string const& prefix = "")
    : ParamListener(parameters_interface, rclcpp::get_logger("endpose_dual_arm_qp_controller"), prefix) {
      RCLCPP_DEBUG(logger_, "ParameterListener: Not using node logger, recommend using other constructors to use a node logger");
    }

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  rclcpp::Logger logger, std::string const& prefix = "")
    : prefix_{prefix},
      logger_{std::move(logger)} {
      if (!prefix_.empty() && prefix_.back() != '.') {
        prefix_ += ".";
      }

      parameters_interface_ = parameters_interface;
      declare_params();
      auto update_param_cb = [this](const std::vector<rclcpp::Parameter> &parameters){return this->update(parameters);};
      handle_ = parameters_interface_->add_on_set_parameters_callback(update_param_cb);
      clock_ = rclcpp::Clock();
    }

    Params get_params() const{
      std::lock_guard<std::mutex> lock(mutex_);
      return params_;
    }

    /**
     * @brief Tries to update the parsed Params object
     * @param params_in The Params object to update
     * @return true if the Params object was updated, false if it was already up to date or the mutex could not be locked
     * @note This function tries to lock the mutex without blocking, so it can be used in a RT loop
     */
    bool try_update_params(Params & params_in) const {
      std::unique_lock<std::mutex> lock(mutex_, std::try_to_lock);
      if (lock.owns_lock()) {
        if (const bool is_old = params_in.__stamp != params_.__stamp; is_old) {
          params_in = params_;
          return true;
        }
      }
      return false;
    }

    /**
     * @brief Tries to get the current Params object
     * @param params_in The Params object to fill with the current parameters
     * @return true if mutex can be locked, false if mutex could not be locked
     * @note The parameters are only filled, when the mutex can be locked and the params timestamp is different
     * @note This function tries to lock the mutex without blocking, so it can be used in a RT loop
     */
    bool try_get_params(Params & params_in) const {
      if (mutex_.try_lock()) {
        if (const bool is_old = params_in.__stamp != params_.__stamp; is_old) {
          params_in = params_;
        }
        mutex_.unlock();
        return true;
      }
      return false;
    }

    bool is_old(Params const& other) const {
      std::lock_guard<std::mutex> lock(mutex_);
      return params_.__stamp != other.__stamp;
    }

    StackParams get_stack_params() {
      Params params = get_params();
      StackParams output;
      output.arm_idx = params.arm_idx;
      output.robot_idx = params.robot_idx;
      output.dis_err_bound = params.dis_err_bound;
      output.ori_err_bound = params.ori_err_bound;
      output.otg_r_step = params.otg_r_step;
      output.otg_p_step = params.otg_p_step;
      output.redundant_degrees_left = params.redundant_degrees_left;
      output.redundant_degrees_right = params.redundant_degrees_right;
      output.redundant_degrees_weight = params.redundant_degrees_weight;
      output.collision_check = params.collision_check;

      return output;
    }

    void refresh_dynamic_parameters() {
      auto updated_params = get_params();
      // TODO remove any destroyed dynamic parameters

      // declare any new dynamic parameters
      rclcpp::Parameter param;

    }

    rcl_interfaces::msg::SetParametersResult update(const std::vector<rclcpp::Parameter> &parameters) {
      auto updated_params = get_params();

      for (const auto &param: parameters) {
        if (param.get_name() == (prefix_ + "joints")) {
            updated_params.joints = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "interface_name")) {
            updated_params.interface_name = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "states")) {
            updated_params.states = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "state_interface_name")) {
            updated_params.state_interface_name = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "arm_idx")) {
            updated_params.arm_idx = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "robot_idx")) {
            updated_params.robot_idx = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joint_upper_limits")) {
            updated_params.joint_upper_limits = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joint_lower_limits")) {
            updated_params.joint_lower_limits = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "vel_limits")) {
            updated_params.vel_limits = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "acc_limits")) {
            updated_params.acc_limits = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "jerk_limits")) {
            updated_params.jerk_limits = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "base_transform")) {
            updated_params.base_transform = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "target_transform")) {
            updated_params.target_transform = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "dis_err_bound")) {
            updated_params.dis_err_bound = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "ori_err_bound")) {
            updated_params.ori_err_bound = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joint_home_pos")) {
            updated_params.joint_home_pos = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "collision_r")) {
            updated_params.collision_r = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "collision_freeBall_pos")) {
            updated_params.collision_freeBall_pos = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "OriWeight")) {
            updated_params.OriWeight = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "otg_r_step")) {
            updated_params.otg_r_step = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "otg_p_step")) {
            updated_params.otg_p_step = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "redundant_degrees_left")) {
            updated_params.redundant_degrees_left = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "redundant_degrees_right")) {
            updated_params.redundant_degrees_right = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "redundant_degrees_weight")) {
            updated_params.redundant_degrees_weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "collision_check")) {
            updated_params.collision_check = param.as_bool();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
      }

      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
      if (user_callback_) {
         user_callback_(updated_params);
      }
      return rsl::to_parameter_result_msg({});
    }

    void declare_params(){
      auto updated_params = get_params();
      // declare all parameters and give default values to non-required ones
      if (!parameters_interface_->has_parameter(prefix_ + "joints")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the joints to control";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joints);
          parameters_interface_->declare_parameter(prefix_ + "joints", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "interface_name")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the interface to command";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.interface_name);
          parameters_interface_->declare_parameter(prefix_ + "interface_name", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "states")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the joints to get state";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.states);
          parameters_interface_->declare_parameter(prefix_ + "states", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "state_interface_name")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the interface to command";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.state_interface_name);
          parameters_interface_->declare_parameter(prefix_ + "state_interface_name", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "arm_idx")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "arm idx, left = 0, right = 1";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.arm_idx);
          parameters_interface_->declare_parameter(prefix_ + "arm_idx", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "robot_idx")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "robot idx, tianyi = 0, tiangong = 1";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.robot_idx);
          parameters_interface_->declare_parameter(prefix_ + "robot_idx", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joint_upper_limits")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "存储各关节的上限";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joint_upper_limits);
          parameters_interface_->declare_parameter(prefix_ + "joint_upper_limits", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joint_lower_limits")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "存储各关节的下限";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joint_lower_limits);
          parameters_interface_->declare_parameter(prefix_ + "joint_lower_limits", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "vel_limits")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "关节速度上限";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.vel_limits);
          parameters_interface_->declare_parameter(prefix_ + "vel_limits", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "acc_limits")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "关节加速度上限";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.acc_limits);
          parameters_interface_->declare_parameter(prefix_ + "acc_limits", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "jerk_limits")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "关节加速度上限";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.jerk_limits);
          parameters_interface_->declare_parameter(prefix_ + "jerk_limits", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "base_transform")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "腰部坐标系到目标坐标系基底的变换";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.base_transform);
          parameters_interface_->declare_parameter(prefix_ + "base_transform", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "target_transform")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "法兰盘坐标系到目标坐标系的变换";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.target_transform);
          parameters_interface_->declare_parameter(prefix_ + "target_transform", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "dis_err_bound")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "距离跟踪误差限， 单位米";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.dis_err_bound);
          parameters_interface_->declare_parameter(prefix_ + "dis_err_bound", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "ori_err_bound")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "姿态跟踪误差限， 单位弧度";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.ori_err_bound);
          parameters_interface_->declare_parameter(prefix_ + "ori_err_bound", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joint_home_pos")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "各个关节的零空间期望角度，一般给关节中位";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joint_home_pos);
          parameters_interface_->declare_parameter(prefix_ + "joint_home_pos", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "collision_r")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "碰撞小球半径,身体2,关节7,freeball1";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.collision_r);
          parameters_interface_->declare_parameter(prefix_ + "collision_r", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "collision_freeBall_pos")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "自由碰撞小球xyz半径(半径做抽象参数)";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.collision_freeBall_pos);
          parameters_interface_->declare_parameter(prefix_ + "collision_freeBall_pos", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "OriWeight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "优化中姿态控制权重 0.0-1.0";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.OriWeight);
          parameters_interface_->declare_parameter(prefix_ + "OriWeight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "otg_r_step")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "姿态跟踪插值步长";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.otg_r_step);
          parameters_interface_->declare_parameter(prefix_ + "otg_r_step", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "otg_p_step")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "位置跟踪插值步长";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.otg_p_step);
          parameters_interface_->declare_parameter(prefix_ + "otg_p_step", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "redundant_degrees_left")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "优化中三关节参考角度（软约束--填满自由度用）";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.redundant_degrees_left);
          parameters_interface_->declare_parameter(prefix_ + "redundant_degrees_left", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "redundant_degrees_right")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "优化中三关节参考角度（软约束--填满自由度用）";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.redundant_degrees_right);
          parameters_interface_->declare_parameter(prefix_ + "redundant_degrees_right", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "redundant_degrees_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "优化中三关节参考角度（软约束--填满自由度用）的权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.redundant_degrees_weight);
          parameters_interface_->declare_parameter(prefix_ + "redundant_degrees_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "collision_check")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "true 开启碰撞检查， false 关闭碰撞检查";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.collision_check);
          parameters_interface_->declare_parameter(prefix_ + "collision_check", parameter, descriptor);
      }
      // get parameters and fill struct fields
      rclcpp::Parameter param;
      param = parameters_interface_->get_parameter(prefix_ + "joints");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "joints") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.joints = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "interface_name");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "interface_name") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.interface_name = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "states");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "states") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.states = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "state_interface_name");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "state_interface_name") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.state_interface_name = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "arm_idx");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "arm_idx") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.arm_idx = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "robot_idx");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "robot_idx") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.robot_idx = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "joint_upper_limits");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "joint_upper_limits") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.joint_upper_limits = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "joint_lower_limits");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "joint_lower_limits") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.joint_lower_limits = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "vel_limits");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "vel_limits") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.vel_limits = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "acc_limits");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "acc_limits") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.acc_limits = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "jerk_limits");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "jerk_limits") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.jerk_limits = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "base_transform");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "base_transform") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.base_transform = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "target_transform");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "target_transform") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.target_transform = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "dis_err_bound");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "dis_err_bound") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.dis_err_bound = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "ori_err_bound");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "ori_err_bound") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.ori_err_bound = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "joint_home_pos");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "joint_home_pos") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.joint_home_pos = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "collision_r");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "collision_r") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.collision_r = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "collision_freeBall_pos");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "collision_freeBall_pos") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.collision_freeBall_pos = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "OriWeight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "OriWeight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.OriWeight = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "otg_r_step");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "otg_r_step") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.otg_r_step = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "otg_p_step");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "otg_p_step") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.otg_p_step = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "redundant_degrees_left");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "redundant_degrees_left") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.redundant_degrees_left = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "redundant_degrees_right");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "redundant_degrees_right") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.redundant_degrees_right = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "redundant_degrees_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "redundant_degrees_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.redundant_degrees_weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "collision_check");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "collision_check") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.collision_check = param.as_bool();


      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
    }

    using userParameterUpdateCB = std::function<void(const Params&)>;
    void setUserCallback(const userParameterUpdateCB& callback){
      user_callback_ = callback;
    }

    void clearUserCallback(){
      user_callback_ = {};
    }

    private:
      void update_internal_params(Params updated_params) {
        std::lock_guard<std::mutex> lock(mutex_);
        params_ = std::move(updated_params);
      }

      std::string prefix_;
      Params params_;
      rclcpp::Clock clock_;
      std::shared_ptr<rclcpp::node_interfaces::OnSetParametersCallbackHandle> handle_;
      std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> parameters_interface_;
      userParameterUpdateCB user_callback_;

      rclcpp::Logger logger_;
      std::mutex mutable mutex_;
  };

} // namespace endpose_dual_arm_qp_controller
