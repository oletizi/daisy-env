cmake_minimum_required(VERSION 3.20)
project(daisy_env)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_TEST_NAME daisy_env_tests)
set(PROJECT_NAME daisy_env)
### Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

### DaisySP-old as a library
add_library(DaisySP STATIC lib/DaisySP/Utility/metro.cpp)

### executables
add_executable(${PROJECT_NAME} main.cpp test.cpp)
add_executable(${PROJECT_TEST_NAME} test.cpp test_daisysp.cpp)

include_directories(lib/DaisySP-old)
target_link_libraries(${PROJECT_NAME} DaisySP ${CONAN_LIBS})
target_link_libraries(${PROJECT_TEST_NAME} DaisySP ${CONAN_LIBS})
target_link_libraries(${PROJECT_TEST_NAME} gcov)
