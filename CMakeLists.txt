cmake_minimum_required(VERSION 3.20)
project(simple_env)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(DaisySP STATIC lib/DaisySP/Utility/metro.cpp)
add_executable(simple_env main.cpp)
add_executable(tests test_daisysp.cpp)

include_directories(lib/DaisySP)
target_link_libraries(simple_env DaisySP ${CONAN_LIBS})
target_link_libraries(tests DaisySP ${CONAN_LIBS})
