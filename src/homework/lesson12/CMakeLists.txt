cmake_minimum_required(VERSION 3.15)
project(LinkedList C)

add_library(linked_list linked_list.c)

enable_testing()
add_executable(test_linked_list test_linked_list.c)
target_link_libraries(test_linked_list linked_list)
add_test(test_linked_list test_linked_list)