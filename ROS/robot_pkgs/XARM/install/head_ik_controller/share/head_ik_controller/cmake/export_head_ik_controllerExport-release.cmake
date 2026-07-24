#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "head_ik_controller::head_ik_controller" for configuration "Release"
set_property(TARGET head_ik_controller::head_ik_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(head_ik_controller::head_ik_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhead_ik_controller.so"
  IMPORTED_SONAME_RELEASE "libhead_ik_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS head_ik_controller::head_ik_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_head_ik_controller::head_ik_controller "${_IMPORT_PREFIX}/lib/libhead_ik_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
