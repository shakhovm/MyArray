cmake_minimum_required(VERSION 3.14)
project(MyArray)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest-master/googletest)
add_executable(my_array main.cpp MyArray.h)
target_link_libraries(my_array gtest gtest_main)