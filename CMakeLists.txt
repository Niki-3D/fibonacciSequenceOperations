cmake_minimum_required(VERSION 3.30)
project(PD3_Fib)

set(CMAKE_CXX_STANDARD 20)

# Add the main program executable
add_executable(PD3_Fib main.cpp fib.cpp)

# Collect all test files
set(TEST_SOURCES
        Tests/test1.cpp
        Tests/test2.cpp
        Tests/test3.cpp
)

# Create a test executable for each test
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE} fib.cpp)
endforeach()

# Optionally, if you want to run the tests automatically (with CTest)
enable_testing()

# If you want to group all tests together as a single target:
add_custom_target(run_tests
        COMMAND ${CMAKE_BINARY_DIR}/test1
        COMMAND ${CMAKE_BINARY_DIR}/test2
        COMMAND ${CMAKE_BINARY_DIR}/test3
        DEPENDS test1 test2 test3
)
