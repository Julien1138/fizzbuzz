cmake_minimum_required(VERSION 3.16)
project(fizzbuzz CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(fizzbuzz_lib src/fizzbuzz.cpp src/rules/divisor_rule.cpp)
target_include_directories(fizzbuzz_lib PUBLIC src)

add_executable(fizzbuzz src/main.cpp)
target_link_libraries(fizzbuzz PRIVATE fizzbuzz_lib)

enable_testing()
add_subdirectory(test)
