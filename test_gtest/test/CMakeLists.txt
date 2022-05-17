cmake_minimum_required(VERSION 3.17)
project(test)
add_executable(${PROJECT_NAME} test_all.cpp test_func.cpp)
target_link_libraries(${PROJECT_NAME} gtest gmock src util)