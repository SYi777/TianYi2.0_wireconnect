# Install script for directory: /home/ubuntu/nk2_ws/src/bodyctrl_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ubuntu/nk2_ws/install/bodyctrl_msgs")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/bodyctrl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_c/bodyctrl_msgs/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/opt/ros/humble/lib/python3.10/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/library_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_typesupport_fastrtps_c/bodyctrl_msgs/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_cpp/bodyctrl_msgs/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_typesupport_fastrtps_cpp/bodyctrl_msgs/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_typesupport_introspection_c/bodyctrl_msgs/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bodyctrl_msgs/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_typesupport_introspection_cpp/bodyctrl_msgs/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/libbodyctrl_msgs__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs-0.0.0-py3.10.egg-info" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_python/bodyctrl_msgs/bodyctrl_msgs.egg-info/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs" TYPE DIRECTORY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/home/ubuntu/nk2_ws/install/bodyctrl_msgs/local/lib/python3.10/dist-packages/bodyctrl_msgs"
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs:/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs:/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs:/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/bodyctrl_msgs/bodyctrl_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_generator_py/bodyctrl_msgs/libbodyctrl_msgs__rosidl_generator_py.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so"
         OLD_RPATH "/home/ubuntu/nk2_ws/build/bodyctrl_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbodyctrl_msgs__rosidl_generator_py.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/Alarm.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/AlarmArray.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdMotorCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetMotorCurTor.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetMotorDistance.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetMotorPosition.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetMotorSpeed.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetTsHandCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetTsHandPosition.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/CmdSetWaistMotorPos.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/Euler.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/Exception.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/ExceptionArray.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/Imu.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorName.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatus1.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatusMsg.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatusMsg1.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatusMsg2.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/MotorStatusMsgPlate.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/NodeState.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/PowerBatteryStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/PowerBoardCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/PowerBoardKeyStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/PowerLightCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/PowerStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SbusData.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetMotorCurTor.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetMotorDistance.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetMotorPosition.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetMotorSpeed.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetTsHandCtrl.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetTsHandCtrlItem.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SetTsHandPosition.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/Sri.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/SriName.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/TsHandName.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/TsHandStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/TsHandStatusMsg.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/msg/WaistMotorStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/GetAngleAct.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/GetError.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/GetForceAct.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/GetStatus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/JointSetZero.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/MotorInit.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/MotorResetPosition.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/MotorStart.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/MotorStop.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/Movement.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/PlanEefLine.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/PlanEefRelLine.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/PlanJointTraj.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/ResetMotorZeroOffset.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetAngle.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetAngleFlexible.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetClearError.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetForce.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetMotorZeroOffset.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/SetSpeed.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/VersionUpgrade.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_adapter/bodyctrl_msgs/srv/XSensImuInit.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/Alarm.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/AlarmArray.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdMotorCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetMotorCurTor.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetMotorDistance.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetMotorPosition.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetMotorSpeed.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetTsHandCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetTsHandPosition.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/CmdSetWaistMotorPos.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/Euler.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/Exception.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/ExceptionArray.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/Imu.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorName.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatus1.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatusMsg.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatusMsg1.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatusMsg2.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/MotorStatusMsgPlate.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/NodeState.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/PowerBatteryStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/PowerBoardCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/PowerBoardKeyStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/PowerLightCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/PowerStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SbusData.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetMotorCurTor.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetMotorDistance.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetMotorPosition.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetMotorSpeed.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetTsHandCtrl.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetTsHandCtrlItem.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SetTsHandPosition.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/Sri.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/SriName.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/TsHandName.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/TsHandStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/TsHandStatusMsg.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/msg" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/msg/WaistMotorStatus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/GetAngleAct.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetAngleAct_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetAngleAct_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/GetError.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetError_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetError_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/GetForceAct.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetForceAct_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetForceAct_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/GetStatus.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetStatus_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/GetStatus_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/JointSetZero.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/JointSetZero_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/JointSetZero_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/MotorInit.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorInit_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorInit_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/MotorResetPosition.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorResetPosition_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorResetPosition_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/MotorStart.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorStart_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorStart_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/MotorStop.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorStop_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/MotorStop_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/Movement.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/Movement_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/Movement_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/PlanEefLine.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanEefLine_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanEefLine_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/PlanEefRelLine.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanEefRelLine_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanEefRelLine_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/PlanJointTraj.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanJointTraj_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/PlanJointTraj_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/ResetMotorZeroOffset.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/ResetMotorZeroOffset_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/ResetMotorZeroOffset_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetAngle.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetAngle_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetAngle_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetAngleFlexible.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetAngleFlexible_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetAngleFlexible_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetClearError.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetClearError_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetClearError_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetForce.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetForce_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetForce_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetMotorZeroOffset.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetMotorZeroOffset_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetMotorZeroOffset_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/SetSpeed.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetSpeed_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/SetSpeed_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/VersionUpgrade.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/VersionUpgrade_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/VersionUpgrade_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/srv/XSensImuInit.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/XSensImuInit_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/srv" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/srv/XSensImuInit_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/bodyctrl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/bodyctrl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/environment" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_index/share/ament_index/resource_index/packages/bodyctrl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_cppExport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_typesupport_fastrtps_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/bodyctrl_msgs__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport.cmake"
         "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/CMakeFiles/Export/share/bodyctrl_msgs/cmake/export_bodyctrl_msgs__rosidl_generator_pyExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs/cmake" TYPE FILE FILES
    "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_core/bodyctrl_msgsConfig.cmake"
    "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/ament_cmake_core/bodyctrl_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bodyctrl_msgs" TYPE FILE FILES "/home/ubuntu/nk2_ws/src/bodyctrl_msgs/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/nk2_ws/build/bodyctrl_msgs/bodyctrl_msgs__py/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ubuntu/nk2_ws/build/bodyctrl_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
