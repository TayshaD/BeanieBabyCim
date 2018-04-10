cmake_minimum_required(VERSION 3.9)
project(BeanieBabySim)

set(CMAKE_CXX_STANDARD 14)

set(SRC_DIR src)
set(INC_DIR include)
set(TEST_DIR test)

include_directories(${INC_DIR})

add_subdirectory(cpr)

include_directories(${CPR_INCLUDE_DIRS})

file(GLOB_RECURSE BeanieBabySim_SRC ${INC_DIR}/*.h ${SRC_DIR}/*.cpp)

add_executable(BeanieBabySim ${BeanieBabySim_SRC})
target_link_libraries(BeanieBabySim ${CPR_LIBRARIES})