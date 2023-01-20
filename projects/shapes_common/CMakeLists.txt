cmake_minimum_required(VERSION 3.20)
project(shapes_common VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Define Source Code files

set(LIBRARY_HEADER_DIR include/${PROJECT_NAME})
set(LIBRARY_SOURCE_DIR src)

set(LIBRARY_HEADERS
    ${LIBRARY_HEADER_DIR}/utils.h
)

set(LIBRARY_SOURCERS
    ${LIBRARY_SOURCE_DIR}/utils.cpp
)

# Define Library

add_library(${PROJECT_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCERS}
)

# Define API

## Internal API
target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_HEADER_DIR}>
)

## Public API
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

## Export API
set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES
        PUBLIC_HEADER "${LIBRARY_HEADERS}"
)

# Define Install

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)