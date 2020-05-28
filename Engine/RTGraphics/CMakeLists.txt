cmake_minimum_required(VERSION 3.16)
project(RTGraphics)

set(CMAKE_CXX_STANDARD 14)

add_library(RTGraphics SHARED 2D/Source/Window3D.cpp)

target_include_directories(RTGraphics PUBLIC ${PROJECT_SOURCE_DIR})