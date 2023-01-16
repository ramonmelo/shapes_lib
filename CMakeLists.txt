cmake_minimum_required(VERSION 3.20)
project(shapes VERSION 0.0.1 LANGUAGES CXX)

# User Settings Defines

set(BUILD_STATIC_LIBS OFF CACHE BOOL "Create a static library")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Create a shared library")

## Define Source Code files

set(LIBRARY_HEADERS_DIR include/${PROJECT_NAME})
set(LIBRARY_SOURCE_DIR src)

set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/Point.h
)

set(LIBRARY_SOURCES
    ${LIBRARY_SOURCE_DIR}/Point.cpp
    ${LIBRARY_SOURCE_DIR}/utils.h
)

## Define Library

if (BUILD_STATIC_LIBS)
    add_library(${PROJECT_NAME} STATIC
        ${LIBRARY_HEADERS}
        ${LIBRARY_SOURCES}
    )
endif()

if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED
        ${LIBRARY_HEADERS}
        ${LIBRARY_SOURCES}
    )
endif()

## Define API

target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${LIBRARY_HEADERS})

## Define Install

set(OUTPUT_DEBUG_DIR Debug/${PROJECT_NAME})
set(OUTPUT_RELEASE_DIR Release/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
  CONFIGURATIONS Debug
  RUNTIME DESTINATION ${OUTPUT_DEBUG_DIR}/lib
  LIBRARY DESTINATION ${OUTPUT_DEBUG_DIR}/lib
  PUBLIC_HEADER DESTINATION ${OUTPUT_DEBUG_DIR}/include)

install(TARGETS ${PROJECT_NAME}
  CONFIGURATIONS Release
  RUNTIME DESTINATION ${OUTPUT_RELEASE_DIR}/lib
  LIBRARY DESTINATION ${OUTPUT_RELEASE_DIR}/lib
  PUBLIC_HEADER DESTINATION ${OUTPUT_RELEASE_DIR}/include)


# Setup Test

# add_subdirectory(test)