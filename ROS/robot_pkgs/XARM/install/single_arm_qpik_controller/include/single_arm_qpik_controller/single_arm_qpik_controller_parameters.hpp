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



namespace single_arm_qpik_controller {

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
        int64_t robot_idx = 0;
        int64_t arm_idx = 0;
        std::vector<double> joint_upper_limits = {};
        std::vector<double> joint_lower_limits = {};
        std::vector<double> vel_limits = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
        std::vector<double> acc_limits = {10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0};
        std::vector<double> jerk_limits = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0};
        double dis_err_bound = 0.2;
        double ori_err_bound = 1.0;
        std::vector<double> joint_home_pos = {};
        double otg_r_step = 0.01;
        double otg_p_step = 0.01;
        bool collision_check = true;
        std::vector<double> EE_offset = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        std::vector<double> Cspace_weight = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
        double orientation_weight = 1000.0;
        double position_weight = 10000.0;
        double damping_weight = 1.0;
        double singular_avoid_weight = 1.0;
        std::string from_frame = "base";
        std::string to_frame = "left_tcp_link";
        int64_t step_threshold = 2000;
        double dis_threshold = 0.005;
        double ori_threshold = 0.005;
        // for detecting if the parameter struct has been updated
        rclcpp::Time __stamp;
    };
    struct StackParams {
        int64_t robot_idx = 0;
        int64_t arm_idx = 0;
        double dis_err_bound = 0.2;
        double ori_err_bound = 1.0;
        double otg_r_step = 0.01;
        double otg_p_step = 0.01;
        bool collision_check = true;
        double orientation_weight = 1000.0;
        double position_weight = 10000.0;
        double damping_weight = 1.0;
        double singular_avoid_weight = 1.0;
        int64_t step_threshold = 2000;
        double dis_threshold = 0.005;
        double ori_threshold = 0.005;
    };

  class ParamListener{
  public:
    // throws rclcpp::exceptions::InvalidParameterValueException on initialization if invalid parameter are loaded
    template <typename NodeT>
    ParamListener(NodeT node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  std::string const& prefix = "")
    : ParamListener(parameters_interface, rclcpp::get_logger("single_arm_qpik_controller"), prefix) {
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
      output.robot_idx = params.robot_idx;
      output.arm_idx = params.arm_idx;
      output.dis_err_bound = params.dis_err_bound;
      output.ori_err_bound = params.ori_err_bound;
      output.otg_r_step = params.otg_r_step;
      output.otg_p_step = params.otg_p_step;
      output.collision_check = params.collision_check;
      output.orientation_weight = params.orientation_weight;
      output.position_weight = params.position_weight;
      output.damping_weight = params.damping_weight;
      output.singular_avoid_weight = params.singular_avoid_weight;
      output.step_threshold = params.step_threshold;
      output.dis_threshold = params.dis_threshold;
      output.ori_threshold = params.ori_threshold;

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
        if (param.get_name() == (prefix_ + "robot_idx")) {
            updated_params.robot_idx = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "arm_idx")) {
            updated_params.arm_idx = param.as_int();
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
        if (param.get_name() == (prefix_ + "otg_r_step")) {
            updated_params.otg_r_step = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "otg_p_step")) {
            updated_params.otg_p_step = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "collision_check")) {
            updated_params.collision_check = param.as_bool();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "EE_offset")) {
            updated_params.EE_offset = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "Cspace_weight")) {
            updated_params.Cspace_weight = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "orientation_weight")) {
            updated_params.orientation_weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "position_weight")) {
            updated_params.position_weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "damping_weight")) {
            updated_params.damping_weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "singular_avoid_weight")) {
            updated_params.singular_avoid_weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "from_frame")) {
            updated_params.from_frame = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "to_frame")) {
            updated_params.to_frame = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "step_threshold")) {
            updated_params.step_threshold = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "dis_threshold")) {
            updated_params.dis_threshold = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "ori_threshold")) {
            updated_params.ori_threshold = param.as_double();
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
      if (!parameters_interface_->has_parameter(prefix_ + "robot_idx")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "robot idx, tianyi = 0, tiangong = 1";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.robot_idx);
          parameters_interface_->declare_parameter(prefix_ + "robot_idx", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "arm_idx")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "arm idx, left = 0, right = 1";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.arm_idx);
          parameters_interface_->declare_parameter(prefix_ + "arm_idx", parameter, descriptor);
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
      if (!parameters_interface_->has_parameter(prefix_ + "collision_check")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "true 开启碰撞检查， false 关闭碰撞检查";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.collision_check);
          parameters_interface_->declare_parameter(prefix_ + "collision_check", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "EE_offset")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "末端参考偏移 x y z r p y";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.EE_offset);
          parameters_interface_->declare_parameter(prefix_ + "EE_offset", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "Cspace_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "关节空间权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.Cspace_weight);
          parameters_interface_->declare_parameter(prefix_ + "Cspace_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "orientation_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "姿态跟踪权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.orientation_weight);
          parameters_interface_->declare_parameter(prefix_ + "orientation_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "position_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "位置跟踪权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.position_weight);
          parameters_interface_->declare_parameter(prefix_ + "position_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "damping_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "阻尼权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.damping_weight);
          parameters_interface_->declare_parameter(prefix_ + "damping_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "singular_avoid_weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "奇异点回避权重";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.singular_avoid_weight);
          parameters_interface_->declare_parameter(prefix_ + "singular_avoid_weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "from_frame")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "参考系";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.from_frame);
          parameters_interface_->declare_parameter(prefix_ + "from_frame", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "to_frame")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "目标系";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.to_frame);
          parameters_interface_->declare_parameter(prefix_ + "to_frame", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "step_threshold")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "action中优化步数阈值";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.step_threshold);
          parameters_interface_->declare_parameter(prefix_ + "step_threshold", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "dis_threshold")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "action中距离阈值";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.dis_threshold);
          parameters_interface_->declare_parameter(prefix_ + "dis_threshold", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "ori_threshold")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "action中姿态阈值";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.ori_threshold);
          parameters_interface_->declare_parameter(prefix_ + "ori_threshold", parameter, descriptor);
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
      param = parameters_interface_->get_parameter(prefix_ + "robot_idx");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "robot_idx") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.robot_idx = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "arm_idx");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "arm_idx") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.arm_idx = param.as_int();
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
      param = parameters_interface_->get_parameter(prefix_ + "dis_err_bound");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "dis_err_bound") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.dis_err_bound = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "ori_err_bound");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "ori_err_bound") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.ori_err_bound = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "joint_home_pos");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "joint_home_pos") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.joint_home_pos = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "otg_r_step");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "otg_r_step") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.otg_r_step = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "otg_p_step");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "otg_p_step") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.otg_p_step = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "collision_check");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "collision_check") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.collision_check = param.as_bool();
      param = parameters_interface_->get_parameter(prefix_ + "EE_offset");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "EE_offset") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.EE_offset = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "Cspace_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "Cspace_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.Cspace_weight = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "orientation_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "orientation_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.orientation_weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "position_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "position_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.position_weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "damping_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "damping_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.damping_weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "singular_avoid_weight");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "singular_avoid_weight") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.singular_avoid_weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "from_frame");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "from_frame") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.from_frame = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "to_frame");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "to_frame") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.to_frame = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "step_threshold");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "step_threshold") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.step_threshold = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "dis_threshold");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "dis_threshold") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.dis_threshold = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "ori_threshold");
      RCLCPP_DEBUG_STREAM(logger_, (prefix_ + "ori_threshold") << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.ori_threshold = param.as_double();


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

} // namespace single_arm_qpik_controller
