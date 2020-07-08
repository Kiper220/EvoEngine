cmake_minimum_required(VERSION 3.16)
project(RTL::Math)
set(CMAKE_CXX_STANDARD 14)

add_library(rtl_math SHARED
        src/IVector2.cpp
        src/Matrix3.cpp
        src/Quaternion.cpp
        src/Triangle.cpp
        src/Vector2.cpp
        src/Vector3.cpp)

add_library(RTL::Math ALIAS rtl_math)
target_include_directories(rtl_math PUBLIC include ${RTL_SOURCE_DIR})

set_target_properties(rtl_math
        PROPERTIES
        EXECUTABLE_OUTPUT_PATH "${EngineSourceDirectory}/BIN/EvoEngine"
        LIBRARY_OUTPUT_DIRECTORY "${EngineSourceDirectory}/BIN/EvoEngine/lib"
        RUNTIME_OUTPUT_DIRECTORY  "${EngineSourceDirectory}/BIN/EvoEngine"
        )
