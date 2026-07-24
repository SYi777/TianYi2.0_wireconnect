cmake_minimum_required(VERSION 3.18)

project(lyre_examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(
    -Wall
    -Wextra
  )
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(rclcpp REQUIRED)

find_package(lyre_msgs REQUIRED)

file(GLOB SRC_FILES_ src/*.cpp)

# absolute path
foreach(SRC_FILE ${SRC_FILES_})
  # relative path, e.g. src/play_file_srv.cpp
  file(RELATIVE_PATH relative_file "${CMAKE_SOURCE_DIR}" "${SRC_FILE}")
  # file name, e.g. play_file_srv.cpp
  get_filename_component(file_name ${SRC_FILE} NAME)
  # base name, e.g. play_file_srv
  string(REGEX REPLACE "\\.[^.]*$" "" target_name ${file_name})
  # prefixed target name, e.g. lyre_example_play_file_srv
  set(target_name "lyre_example_${target_name}")

  add_executable(${target_name}
    ${relative_file}
  )

  ament_target_dependencies(${target_name}
    rclcpp
    lyre_msgs
  )

  install(TARGETS ${target_name}
    RUNTIME DESTINATION bin
  )

  unset(relative_file)
  unset(file_name)
endforeach()

install(DIRECTORY cli/ DESTINATION cli)
install(DIRECTORY res/ DESTINATION res)
install(DIRECTORY src/ DESTINATION src)
install(FILES
  CMakeLists.txt
  package.xml
  README.md
  DESTINATION .
)

ament_package()
