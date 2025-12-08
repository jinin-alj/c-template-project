add_library(homework10_library
    welcome.c
    main.c
)

target_include_directories(homework10_library PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(homework10 main.c)
target_link_libraries(homework10 PRIVATE homework10_library)