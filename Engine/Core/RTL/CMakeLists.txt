cmake_minimum_required(VERSION 3.16)
project(RTL)
set(CMAKE_CXX_STANDARD 14)

set(RTL_SOURCE_DIR ${PROJECT_SOURCE_DIR})

add_library(glad SHARED Extention/Linux/glad/gl/src/glad.c)
target_include_directories(glad PUBLIC Extention/Linux/glad/gl/include)

set_target_properties(glad
        PROPERTIES
        EXECUTABLE_OUTPUT_PATH "${EngineSourceDirectory}/BIN/EvoEngine"
        LIBRARY_OUTPUT_DIRECTORY "${EngineSourceDirectory}/BIN/EvoEngine/lib"
        RUNTIME_OUTPUT_DIRECTORY  "${EngineSourceDirectory}/BIN/EvoEngine"
        )

add_subdirectory(RTL_Types)
add_subdirectory(RTL_Math)
add_subdirectory(RTL_Window)
add_subdirectory(RTL_RT)