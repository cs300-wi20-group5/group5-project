cmake_minimum_required(VERSION 3.15)
project(cs300_wi20)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs300_wi20 src/class_functions.cpp src/classes.h)

add_subdirectory(src)
add_subdirectory(Google_tests)