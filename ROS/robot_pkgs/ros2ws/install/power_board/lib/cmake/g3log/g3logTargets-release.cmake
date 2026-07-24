#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "g3log" for configuration "Release"
set_property(TARGET g3log APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(g3log PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libg3log.so.2.6"
  IMPORTED_SONAME_RELEASE "libg3log.so.2"
  )

list(APPEND _IMPORT_CHECK_TARGETS g3log )
list(APPEND _IMPORT_CHECK_FILES_FOR_g3log "${_IMPORT_PREFIX}/lib/libg3log.so.2.6" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
