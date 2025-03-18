cmake_minimum_required(VERSION 3.30)
project(PD3_Fib)

set(CMAKE_CXX_STANDARD 20)

add_executable(PD3_Fib main.cpp fib.cpp)

add_executable(test1 test1.cpp fib.cpp)
add_executable(test2 test2.cpp fib.cpp)
add_executable(test3 test3.cpp fib.cpp)
