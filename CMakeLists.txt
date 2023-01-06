cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME test_shapes)

set(PROJECT_SOURCE_DIR src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
)

set(PROJECT_LIB_DIR
    shapes
)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

foreach(LIBRARY ${PROJECT_LIB_DIR})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_DIR})
