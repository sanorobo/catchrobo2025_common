cmake_minimum_required(VERSION 3.22)

project(catchrobo2025_common LANGUAGES CXX)

string(TOUPPER ${CMAKE_PROJECT_NAME} PROJECT_NAME_UPPER)
configure_file(project_name.hpp.in include/catchrobo2025/project_name.hpp)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE
  halx
)
target_include_directories(${PROJECT_NAME} INTERFACE
  include
  ${CMAKE_CURRENT_BINARY_DIR}/include
  eigen
)
