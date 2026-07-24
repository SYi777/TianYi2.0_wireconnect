#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "se3otg::se3otg" for configuration "Release"
set_property(TARGET se3otg::se3otg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(se3otg::se3otg PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libse3otg.so.1.0.0"
  IMPORTED_SONAME_RELEASE "libse3otg.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS se3otg::se3otg )
list(APPEND _IMPORT_CHECK_FILES_FOR_se3otg::se3otg "${_IMPORT_PREFIX}/lib/libse3otg.so.1.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
