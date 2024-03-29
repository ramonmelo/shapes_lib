cmake_minimum_required(VERSION 3.20)
project(shapes VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# User Settings Defines

set(BUILD_STATIC_LIBS OFF CACHE BOOL "Create a static library")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Create a shared library")

# Define Source Code files

set(LIBRARY_HEADER_DIR include/${PROJECT_NAME})
set(LIBRARY_SOURCE_DIR src)

set(LIBRARY_HEADERS
    ${LIBRARY_HEADER_DIR}/Point.h
    ${LIBRARY_HEADER_DIR}/core/BasePoint.h
)

set(LIBRARY_SOURCES
    ${LIBRARY_SOURCE_DIR}/Point.cpp
    ${LIBRARY_SOURCE_DIR}/core/BasePoint.cpp
)

# Define Library

add_library(${PROJECT_NAME}
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    shapes_common
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

# Setup Test

if (ENABLE_TESTS)
    add_subdirectory(test)
endif()