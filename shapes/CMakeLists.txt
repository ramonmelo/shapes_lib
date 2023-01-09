cmake_minimum_required(VERSION 3.20)

# Defines
set(PROJECT_NAME
    shapes
)

set(LIBRARY_NAME
    shapes
)

set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)

set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/Point.h
)

set(LIBRARY_SOURCE_DIR
    src
)

set(LIBRARY_SOURCES
    ${LIBRARY_SOURCE_DIR}/Point.cpp
    ${LIBRARY_SOURCE_DIR}/utils.h
)

project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add_subdirectory(test)