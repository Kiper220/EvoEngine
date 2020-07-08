cmake_minimum_required(VERSION 3.16)
project(RTL)
set(CMAKE_CXX_STANDARD 14)

set(RTL_SOURCE_DIR ${PROJECT_SOURCE_DIR})

add_subdirectory(RTL_Types)
add_subdirectory(RTL_Math)
add_subdirectory(RTL_Window)