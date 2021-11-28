cmake_minimum_required(VERSION 3.20)
project(daisy_env)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_TEST_NAME daisy_env_tests)
set(PROJECT_NAME daisy_env)

### Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

### DaisySP as a library (not as a subdirectory, since we want to build it for the host platform, not the Daisy
set(DAISY_SP_PATH lib/DaisySP/Source)
add_library(DaisySP STATIC ${DAISY_SP_PATH}/Utility/metro.cpp)

### executables
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_TEST_NAME} test.cpp test_daisysp.cpp)
add_executable(host_audiomidi host_audiomidi.cpp)

### XXX: Don't do this. Use conan instead.
include_directories(${DAISY_SP_PATH})
include_directories(/usr/local/include)

target_link_libraries(${PROJECT_NAME} DaisySP ${CONAN_LIBS})
target_link_libraries(${PROJECT_TEST_NAME} DaisySP ${CONAN_LIBS})
target_link_libraries(host_audiomidi DaisySP ${CONAN_LIBS} /usr/local/lib/librtaudio.dylib)
