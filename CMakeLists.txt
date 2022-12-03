cmake_minimum_required(VERSION 3.23)
project(interpolation_and_regression)

set(CMAKE_CXX_STANDARD 14)

add_executable(interpolation_and_regression main.cpp interpolation.cpp regression.cpp headers.h)
