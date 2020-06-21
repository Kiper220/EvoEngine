cmake_minimum_required(VERSION 3.16)
project(EvoEngine)

add_subdirectory(RVM)
add_subdirectory(RTL)
add_subdirectory(RTMath)
add_subdirectory(RTGraphics)

find_package(Boost REQUIRED)

add_executable(EvoEngine main.cpp)
target_link_libraries(EvoEngine ${Boost_LIBRARIES} RTGraphics RTL RTMath RVM ${OPENGL_LIBRARIES}  ${GLEW_LIBRARIES} ${GLM_LIBRARIES} glm ${SDL2_LIBRARIES})
#glfw ${GLUT_LIBRARY}
target_include_directories(EvoEngine PUBLIC ${Boost_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
target_include_directories(RTMath PUBLIC ${PROJECT_SOURCE_DIR})
