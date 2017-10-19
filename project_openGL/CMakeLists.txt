cmake_minimum_required(VERSION 2.6)

# Enable c++11 
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

project(Project_OpenGL)
 
include_directories(Include)
link_directories(${PROJECT_SOURCE_DIR}/Lib/Windows)

set(OPENGL_SOURCES Src/glad.cpp)
set(MAIN_SOURCES Src/tutorial1.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
 
add_library(opengl ${OPENGL_SOURCES})
add_executable(main ${MAIN_SOURCES})
target_link_libraries(main opengl glfw3)