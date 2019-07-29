set(projectSRC test.cpp)

add_executable(test
    ${projectSRC})

target_include_directories(test PRIVATE "${PROJECT_SOURCE_DIR}/src")

target_link_libraries(test PUBLIC 
    ${projectLib}
    gtest_main
    gmock_main
    pthread
    )

add_test(NAME test COMMAND test)