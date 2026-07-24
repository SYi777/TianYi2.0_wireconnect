#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tianyi_controller::tianyi_controller" for configuration "Release"
set_property(TARGET tianyi_controller::tianyi_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tianyi_controller::tianyi_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtianyi_controller.so"
  IMPORTED_SONAME_RELEASE "libtianyi_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS tianyi_controller::tianyi_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_tianyi_controller::tianyi_controller "${_IMPORT_PREFIX}/lib/libtianyi_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
