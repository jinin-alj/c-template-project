cmake_minimum_required(VERSION 3.21)
project(homework13 C)
set(CMAKE_C_STANDARD 23)
add_subdirectory(src)
include_directories(include)

enable_testing()
add_subdirectory(tests)
