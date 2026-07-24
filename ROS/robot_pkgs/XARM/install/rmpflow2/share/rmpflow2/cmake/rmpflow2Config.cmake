# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rmpflow2_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rmpflow2_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rmpflow2_FOUND FALSE)
  elseif(NOT rmpflow2_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rmpflow2_FOUND FALSE)
  endif()
  return()
endif()
set(_rmpflow2_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rmpflow2_FIND_QUIETLY)
  message(STATUS "Found rmpflow2: 0.0.0 (${rmpflow2_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rmpflow2' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rmpflow2_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rmpflow2_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${rmpflow2_DIR}/${_extra}")
endforeach()
