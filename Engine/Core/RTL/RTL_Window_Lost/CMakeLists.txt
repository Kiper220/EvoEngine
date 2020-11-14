cmake_minimum_required(VERSION 3.16)
project(RTL::Window)
set(CMAKE_CXX_STANDARD 14)

set(RTL_Window_WIN32_SRC
        src/WWindow/PWindow.cpp)
set(RTL_Window_XLIB_SRC
        src/XWindow/PWindow.cpp)

if(${CMAKE_SYSTEM} MATCHES "Linux")
    message(STATUS "RWindow: window create target: Xlib")
    add_library(rtl_window SHARED src/Window.cpp
            ${RTL_Window_XLIB_SRC})
    add_library(RTL::Window ALIAS rtl_window)
    target_link_libraries(rtl_window RTL::Types RTL::Math X11 GLX Xrender)
    target_include_directories(rtl_window PUBLIC include/XWindow)

elseif(WIN32)
    message(FATAL_ERROR "This platform not supported")
else()
    message(FATAL_ERROR "This platform not supported")
endif()

target_include_directories(rtl_window PUBLIC include ${RTL_SOURCE_DIR})