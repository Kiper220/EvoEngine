cmake_minimum_required(VERSION 3.16)
project(RTL::Audio)
set(CMAKE_CXX_STANDARD 14)

add_library(rtl_rt src/RVM.cpp)
add_library(RTL::RT ALIAS rtl_rt)

target_include_directories(rtl_rt PUBLIC include ${RTL_SOURCE_DIR})
target_link_libraries(rtl_rt RTL::Types RTL::Math)
