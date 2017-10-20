cmake_minimum_required(VERSION 2.6)

# Enable c++11 
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

project(Project_OpenGL)
 
include_directories(Include)
#link_directories(${PROJECT_SOURCE_DIR}/Lib/Windows)
link_directories(${PROJECT_SOURCE_DIR}/Lib/Linux)


set(OPENGL_SOURCES Src/glad.cpp)
set(MAIN_SOURCES Src/tutorial1.cpp)


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
 
add_library(opengl ${OPENGL_SOURCES})
add_executable(main ${MAIN_SOURCES})
target_link_libraries(main opengl glfw)


add_subdirectory(LibSrc)