cmake_minimum_required(VERSION 3.21)
set(CMAKE_C_STANDARD 23)
project(homework10 LANGUAGES C)
add_subdirectory(src)
include_directories(${PROJECT_SOURCE_DIR}/include)
target_include_directories(homework10 PRIVATE include)

enable_testing()
add_subdirectory(tests)