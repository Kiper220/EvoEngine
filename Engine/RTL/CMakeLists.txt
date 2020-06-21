cmake_minimum_required(VERSION 3.16)
project(RTL)

set(CMAKE_CXX_STANDARD 14)

find_library(PTHREAD_LIBRARY pthread)

add_library(RTL SHARED
        Source/String.cpp
        Source/JElement.cpp
        Source/TCPServer.cpp Source/Directory.cpp)
target_include_directories(RTL PUBLIC Include)
target_link_libraries(RTL ${PTHREAD_LIBRARY})