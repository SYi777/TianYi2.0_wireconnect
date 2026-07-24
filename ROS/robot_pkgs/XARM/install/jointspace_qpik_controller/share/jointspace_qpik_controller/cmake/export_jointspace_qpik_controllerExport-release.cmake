#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "jointspace_qpik_controller::jointspace_qpik_controller" for configuration "Release"
set_property(TARGET jointspace_qpik_controller::jointspace_qpik_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jointspace_qpik_controller::jointspace_qpik_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjointspace_qpik_controller.so"
  IMPORTED_SONAME_RELEASE "libjointspace_qpik_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS jointspace_qpik_controller::jointspace_qpik_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_jointspace_qpik_controller::jointspace_qpik_controller "${_IMPORT_PREFIX}/lib/libjointspace_qpik_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
