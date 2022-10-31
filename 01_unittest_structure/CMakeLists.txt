cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 11)

project(01_unittest_structure VERSION 0.1.0)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_library(commonLib LibraryCode.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp commonLib)

add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner commonLib ${GTEST_LIBRARIES} pthread)