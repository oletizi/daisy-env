cmake_minimum_required(VERSION 3.20)
project(daisy_env)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME daisy_env)

### Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

### DaisySP
add_subdirectory(lib/DaisySP)
#https://github.com/oletizi/DaisySP.git
#include(ExternalProject)
#ExternalProject_Add(DaisySP
#        GIT_REPOSITORY https://github.com/oletizi/DaisySP.git
#        UPDATE_DISCONNECTED true
#        PREFIX build/DaisySP
#        TMP_DIR build/tmp
#        CONFIGURE_COMMAND ""
#        BUILD_COMMAND make
#        )

### rtaudio
#add_subdirectory(lib/rtaudio)

### rtmidi
#add_subdirectory(lib/rtmidi)

### MPC
#add_subdirectory(lib/mpc/src)


### executables
add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(${DAISY_SP_PATH})
include_directories(/usr/local/include)

target_link_libraries(${PROJECT_NAME} DaisySP ${CONAN_LIBS})


### Tests
add_subdirectory(test)