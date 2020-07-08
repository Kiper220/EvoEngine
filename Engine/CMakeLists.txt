cmake_minimum_required(VERSION 3.16)
project(EvoEngine)
set(CMAKE_CXX_STANDARD 14)
set(EngineSourceDirectory ${PROJECT_SOURCE_DIR})

add_subdirectory(Core/RTL)

add_executable(EngineUnitTest main.cpp Core/RTL/RTL.h)

target_link_libraries(EngineUnitTest RTL::Types RTL::Math RTL::Window)

set_target_properties(EngineUnitTest
        PROPERTIES
        EXECUTABLE_OUTPUT_PATH "${EngineSourceDirectory}/BIN/EvoEngine"
        LIBRARY_OUTPUT_DIRECTORY "${EngineSourceDirectory}/BIN/EvoEngine/lib"
        RUNTIME_OUTPUT_DIRECTORY  "${EngineSourceDirectory}/BIN/EvoEngine"
        )