cmake_minimum_required(VERSION 2.8.4)
project(BLUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra -Wshadow -Warray-bounds -pedantic")

set(SOURCE_FILES blue_extern_decl.cpp blue_alu.cpp blue_interpreter.cpp blue_ops.cpp blue_file.cpp main.cpp)
add_executable(Blue ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(Blue)