cmake_minimum_required(VERSION 3.20)
project(simple_env)

set(CMAKE_CXX_STANDARD 14)
add_library(daisySp STATIC lib/Utility/metro.cpp)
add_executable(simple_env main.cpp)
include_directories(lib)
