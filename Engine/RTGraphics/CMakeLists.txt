cmake_minimum_required(VERSION 3.12.4)
project(RTGraphics)

set(CMAKE_CXX_STANDARD 14)

add_library(RTGraphics SHARED 2D/Source/UI.cpp)
target_link_libraries(RTGraphics RTL RTMath)

target_include_directories(RTGraphics PUBLIC 2D/Include)