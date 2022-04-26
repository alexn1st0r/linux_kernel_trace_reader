cmake_minimum_required (VERSION 2.8)
project (linux_kernel_trace_reader)

include_directories(../ ../vendor/googletest/googletest/include ../vendor/googletest/googlemock/include)
add_executable(linux_kernel_trace_reader_tests linux_kernel_trace_reader_tests.cpp ../lib/linux_kernel_trace_reader.cpp)
target_link_libraries(linux_kernel_trace_reader_tests gmock gtest)
