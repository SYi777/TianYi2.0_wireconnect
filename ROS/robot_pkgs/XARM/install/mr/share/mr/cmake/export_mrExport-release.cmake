#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mr::mr" for configuration "Release"
set_property(TARGET mr::mr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(mr::mr PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmr.so.1.0.0"
  IMPORTED_SONAME_RELEASE "libmr.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS mr::mr )
list(APPEND _IMPORT_CHECK_FILES_FOR_mr::mr "${_IMPORT_PREFIX}/lib/libmr.so.1.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
