#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tiangong_hardware::tiangong_hardware" for configuration "Release"
set_property(TARGET tiangong_hardware::tiangong_hardware APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tiangong_hardware::tiangong_hardware PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtiangong_hardware.so"
  IMPORTED_SONAME_RELEASE "libtiangong_hardware.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS tiangong_hardware::tiangong_hardware )
list(APPEND _IMPORT_CHECK_FILES_FOR_tiangong_hardware::tiangong_hardware "${_IMPORT_PREFIX}/lib/libtiangong_hardware.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
