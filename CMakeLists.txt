cmake_minimum_required(VERSION 3.22)

project(catchrobo2025_common LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE
  halx
)
target_include_directories(${PROJECT_NAME} INTERFACE
  include
)
