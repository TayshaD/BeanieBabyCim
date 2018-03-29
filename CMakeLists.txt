cmake_minimum_required(VERSION 3.10)
project(BeanieBabySim)

set(CMAKE_CXX_STANDARD 14)

set(SRC_DIR src)
set(INC_DIR include)
set(TEST_DIR test)

file(GLOB_RECURSE BeanieBabySim_SRC ${INC_DIR}/*.h ${SRC_DIR}/*.cpp)

add_executable(BeanieBabySim src/main.cpp include/Simulation.h)