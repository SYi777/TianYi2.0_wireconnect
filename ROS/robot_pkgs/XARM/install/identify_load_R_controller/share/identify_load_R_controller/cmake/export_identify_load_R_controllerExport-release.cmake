#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "identify_load_R_controller::identify_load_R_controller" for configuration "Release"
set_property(TARGET identify_load_R_controller::identify_load_R_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(identify_load_R_controller::identify_load_R_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libidentify_load_R_controller.so"
  IMPORTED_SONAME_RELEASE "libidentify_load_R_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS identify_load_R_controller::identify_load_R_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_identify_load_R_controller::identify_load_R_controller "${_IMPORT_PREFIX}/lib/libidentify_load_R_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
