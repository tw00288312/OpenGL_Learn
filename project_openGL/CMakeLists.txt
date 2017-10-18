cmake_minimum_required(VERSION 2.6)
project(Project_OpenGL)
 
include_directories(Include)
#link_directories(Lib/Windows)

#find_library(RESULT glfw3)

set(GRAPH_SOURCES Src/glad.cpp)
set(MAIN_SOURCES Src/tutorial1.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
 
add_library(graph ${GRAPH_SOURCES})
add_executable(main ${MAIN_SOURCES})
target_link_libraries(main graph)