add_executable(homework10_tests
    test_welcome.c
)

target_include_directories(homework10_tests PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(homework10_tests PRIVATE homework10_library)
add_test(NAME WelcomeTest COMMAND homework10_tests)

add_executable(test_super_assert test_super_assert.c)
target_include_directories(test_super_assert PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(test_super_assert PRIVATE SUPER_ASSERT_VERBOSE=1)
