#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tianyi_hardware::tianyi_hardware" for configuration "Release"
set_property(TARGET tianyi_hardware::tianyi_hardware APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tianyi_hardware::tianyi_hardware PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtianyi_hardware.so"
  IMPORTED_SONAME_RELEASE "libtianyi_hardware.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS tianyi_hardware::tianyi_hardware )
list(APPEND _IMPORT_CHECK_FILES_FOR_tianyi_hardware::tianyi_hardware "${_IMPORT_PREFIX}/lib/libtianyi_hardware.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
