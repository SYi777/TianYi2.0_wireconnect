#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dual_arm_control::plan_random_joint_goal__rosidl_generator_py" for configuration "Release"
set_property(TARGET dual_arm_control::plan_random_joint_goal__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dual_arm_control::plan_random_joint_goal__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libplan_random_joint_goal__rosidl_generator_py.so"
  IMPORTED_SONAME_RELEASE "libplan_random_joint_goal__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS dual_arm_control::plan_random_joint_goal__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_dual_arm_control::plan_random_joint_goal__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libplan_random_joint_goal__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
