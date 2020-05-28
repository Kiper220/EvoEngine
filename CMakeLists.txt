cmake_minimum_required(VERSION 3.16)
project(Game)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_BUILD_FILES_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR})

set(PROJECT_DIR ${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
#find_package(GLUT)
#find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
endif()

add_subdirectory(Engine)