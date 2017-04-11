cmake_minimum_required (VERSION 3.5.0)
project (state_machine)
set (SOURCES ./state_machine.cpp ./main.cpp)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) 

set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall")
add_executable (sm ${SOURCES})
