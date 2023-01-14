cmake_minimum_required(VERSION 3.20)
project(ShapesTestApp)

set(PROJECT_SOURCE_DIR test_app/src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# Import Library
add_subdirectory(shapes)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC shapes)