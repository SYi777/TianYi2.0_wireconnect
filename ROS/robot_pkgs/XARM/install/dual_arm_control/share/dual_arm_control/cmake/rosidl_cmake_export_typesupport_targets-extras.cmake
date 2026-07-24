# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:plan_random_joint_goal__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:plan_random_joint_goal__rosidl_typesupport_fastrtps_c;__rosidl_typesupport_introspection_c:plan_random_joint_goal__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:plan_random_joint_goal__rosidl_typesupport_c;__rosidl_generator_cpp:plan_random_joint_goal__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:plan_random_joint_goal__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_cpp:plan_random_joint_goal__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:plan_random_joint_goal__rosidl_typesupport_cpp;__rosidl_generator_py:plan_random_joint_goal__rosidl_generator_py")

# populate dual_arm_control_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "dual_arm_control::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'dual_arm_control' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND dual_arm_control_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
