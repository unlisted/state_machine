cmake_minimum_required (VERSION 3.5.0)
project (state_machine)

include_directories(include)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON) 

set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -S -masm=intel")
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall")

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bins)
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

subdirs(src)
add_executable(sm main.cpp)
target_link_libraries(sm statemachine)
