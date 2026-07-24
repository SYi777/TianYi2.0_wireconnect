# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_se3otg_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED se3otg_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(se3otg_FOUND FALSE)
  elseif(NOT se3otg_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(se3otg_FOUND FALSE)
  endif()
  return()
endif()
set(_se3otg_CONFIG_INCLUDED TRUE)

# output package information
if(NOT se3otg_FIND_QUIETLY)
  message(STATUS "Found se3otg: 0.0.0 (${se3otg_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'se3otg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${se3otg_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(se3otg_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${se3otg_DIR}/${_extra}")
endforeach()
