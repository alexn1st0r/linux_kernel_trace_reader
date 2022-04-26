cmake_minimum_required (VERSION 2.8)
project (linux_kernel_trace_reader)

set(CMAKE_CXX_FLAGS  "-std=c++14 -g -ggdb -O0")

add_subdirectory(vendor/googletest)
add_subdirectory(tests)
