#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "wholebody_qpik_controller::wholebody_qpik_controller" for configuration "Release"
set_property(TARGET wholebody_qpik_controller::wholebody_qpik_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(wholebody_qpik_controller::wholebody_qpik_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwholebody_qpik_controller.so"
  IMPORTED_SONAME_RELEASE "libwholebody_qpik_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS wholebody_qpik_controller::wholebody_qpik_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_wholebody_qpik_controller::wholebody_qpik_controller "${_IMPORT_PREFIX}/lib/libwholebody_qpik_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
