cmake_minimum_required(VERSION 3.20)
project(ProjectShapes VERSION 0.0.1 LANGUAGES CXX)

# Options

option(ENABLE_TESTS "Build Unit tests" OFF)

# Include Test

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(lib/googletest)
endif()

# Include Libs

set(PROJECTS_DIR projects)

add_subdirectory(${PROJECTS_DIR}/shapes_common)
add_subdirectory(${PROJECTS_DIR}/shapes)