#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "endpose_wholebody_controller::endpose_wholebody_controller" for configuration "Release"
set_property(TARGET endpose_wholebody_controller::endpose_wholebody_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(endpose_wholebody_controller::endpose_wholebody_controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libendpose_wholebody_controller.so"
  IMPORTED_SONAME_RELEASE "libendpose_wholebody_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS endpose_wholebody_controller::endpose_wholebody_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_endpose_wholebody_controller::endpose_wholebody_controller "${_IMPORT_PREFIX}/lib/libendpose_wholebody_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
