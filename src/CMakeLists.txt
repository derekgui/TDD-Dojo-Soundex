set(projectLib ${PROJECT_NAME})

file(GLOB libSRC *.h *.cpp)

add_library(${projectLib} OBJECT ${libSRC})

target_link_libraries(${projectLib})