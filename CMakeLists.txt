cmake_minimum_required(VERSION 3.8)

set(ProjectName TddDojoSoundex)

project(${ProjectName} CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#project output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory(test)
add_subdirectory(googletest)
add_subdirectory(src)

