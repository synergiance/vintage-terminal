cmake_minimum_required(VERSION 3.7)
project(vintage_terminal)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(vintage_terminal ${SDL2_INCLUDE_DIRS})

add_executable(vintage_terminal main.cpp)
target_link_libraries(vintage_terminal ${SDL2_LIBRARIES} ${OPENGL_LIBRARY})
