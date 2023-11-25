cmake_minimum_required(VERSION 3.1)
project(draw)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.c)

# 指定编译命令为g++，使用c++17，可以多线程
set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pthread  -fdiagnostics-color  -std=c11")

# 指定输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SRC_LIST})

