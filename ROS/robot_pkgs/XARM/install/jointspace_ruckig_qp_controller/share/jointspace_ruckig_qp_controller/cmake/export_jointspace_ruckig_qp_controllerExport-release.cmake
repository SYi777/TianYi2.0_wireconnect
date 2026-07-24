#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "jointspace_ruckig_qp_controller::jointspace_ruckig_qp_controller" for configuration "Release"
set_property(TARGET jointspace_ruckig_qp_controller::jointspace_ruckig_qp_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jointspace_ruckig_qp_controller::jointspace_ruckig_qp_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjointspace_ruckig_qp_controller.so"
  IMPORTED_SONAME_RELEASE "libjointspace_ruckig_qp_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS jointspace_ruckig_qp_controller::jointspace_ruckig_qp_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_jointspace_ruckig_qp_controller::jointspace_ruckig_qp_controller "${_IMPORT_PREFIX}/lib/libjointspace_ruckig_qp_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
