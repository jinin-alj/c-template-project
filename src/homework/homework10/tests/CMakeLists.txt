add_executable(homework10_tests
    test_welcome.c
)

target_include_directories(homework10_tests PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(homework10_tests PRIVATE homework10_library)
add_test(NAME WelcomeTest COMMAND homework10_tests)
