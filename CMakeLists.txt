cmake_minimum_required(VERSION 3.10)
project(Example)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
) 
#set(LIB_OPENGL_DIR /lib/x86_64-linux-gnu/)
#add_library()

add_executable(${CMAKE_PROJECT_NAME} ./src/Main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE OpenGL)

