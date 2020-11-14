cmake_minimum_required(VERSION 3.16)
project(EvoEngine)
set(CMAKE_CXX_STANDARD 14)
set(EngineSourceDirectory ${PROJECT_SOURCE_DIR})

add_subdirectory(Core/RTL)

add_executable(EngineUnitTest main.cpp)

target_link_libraries(EngineUnitTest RTL::Types RTL::Math RTL::RT)