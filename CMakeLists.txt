cmake_minimum_required(VERSION 3.9)
project(BeanieBabySim)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR src)
set(INC_DIR include)
set(TEST_DIR test)

include_directories(${INC_DIR})
file(GLOB_RECURSE BeanieBabySim_SRC ${INC_DIR}/*.h ${SRC_DIR}/*.cpp)

add_subdirectory(cpr)
include_directories(${CPR_INCLUDE_DIRS})

add_executable(BeanieBabyTest ${SRC_DIR}/BeanieBaby.cpp ${TEST_DIR}/TestMain.cpp ${TEST_DIR}/BeanieBabyTest.cpp)
target_link_libraries(BeanieBabyTest ${CPR_LIBRARIES})

add_executable(BeanieBabySim ${BeanieBabySim_SRC})
target_link_libraries(BeanieBabySim ${CPR_LIBRARIES})