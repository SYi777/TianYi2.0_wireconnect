#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "single_arm_qp2_controller::single_arm_qp2_controller" for configuration "Release"
set_property(TARGET single_arm_qp2_controller::single_arm_qp2_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(single_arm_qp2_controller::single_arm_qp2_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsingle_arm_qp2_controller.so"
  IMPORTED_SONAME_RELEASE "libsingle_arm_qp2_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS single_arm_qp2_controller::single_arm_qp2_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_single_arm_qp2_controller::single_arm_qp2_controller "${_IMPORT_PREFIX}/lib/libsingle_arm_qp2_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
