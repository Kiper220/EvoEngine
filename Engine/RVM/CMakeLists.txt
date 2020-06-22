cmake_minimum_required(VERSION 3.12.4)
project(RVM)

set(CMAKE_CXX_STANDARD 14)

add_library(RVM SHARED
        Source/RunTimeApplication.cpp)

target_include_directories(RVM PUBLIC Include)