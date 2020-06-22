cmake_minimum_required(VERSION 3.12.4)
project(EvoEngine)

add_subdirectory(RVM)
add_subdirectory(RTL)
add_subdirectory(RTMath)
add_subdirectory(RTGraphics)

add_executable(EvoEngine main.cpp)
target_link_libraries(EvoEngine RTGraphics RTL RTMath RVM ${OPENGL_LIBRARIES})
target_include_directories(EvoEngine PUBLIC ${Boost_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
target_include_directories(RTMath PUBLIC ${PROJECT_SOURCE_DIR})
