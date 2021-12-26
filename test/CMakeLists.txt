set(PROJECT_TEST_NAME daisy_env_tests)
set(PROJECT_TEST_REALTIME_NAME test_host_realtime)
### test library
add_library(testlib STATIC ${PROJECT_SOURCE_DIR}/lib/test/primitive/saw.cpp)

### Tests
add_executable(${PROJECT_TEST_NAME} test.cpp test_daisysp.cpp) # <=== TESTING: add test files here
add_executable(${PROJECT_TEST_REALTIME_NAME} test_host_realtime.cpp) # <=== REALTIME: add realtime on-host tests here
target_include_directories(testlib PUBLIC ${PROJECT_SOURCE_DIR}/lib/test)
target_link_libraries(${PROJECT_TEST_NAME} DaisySP ${CONAN_LIBS})
target_link_libraries(${PROJECT_TEST_REALTIME_NAME} DaisySP ${CONAN_LIBS} /usr/local/lib/librtaudio.dylib testlib)
