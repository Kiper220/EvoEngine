cmake_minimum_required(VERSION 3.16)
project(RTL::Types)
set(CMAKE_CXX_STANDARD 14)

add_library(rtl_types SHARED
        src/String.cpp
        src/Directory.cpp
        src/TCPServer.cpp
        src/FSEntity.cpp
        src/JElement.cpp
        src/Mutex.cpp
        src/Exception.cpp)

add_library(RTL::Types ALIAS rtl_types)
target_include_directories(rtl_types PUBLIC include ${RTL_SOURCE_DIR})
target_link_libraries(rtl_types pthread)
