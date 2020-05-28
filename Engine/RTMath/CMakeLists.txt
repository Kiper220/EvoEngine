cmake_minimum_required(VERSION 3.16)
project(RTMath)

set(CMAKE_CXX_STANDARD 14)

add_library(RTMath SHARED
        Source/STDTypes/Vector3.cpp
        Source/STDTypes/Vector2.cpp
        Source/STDTypes/Quaternion.cpp
        Source/STDTypes/Matrix3.cpp
        Source/Collision/Triangle.cpp)
target_include_directories(RTMath PUBLIC Include)