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
)

set(LIBRARY_SOURCES
    ${LIBRARY_SOURCE_DIR}/Point.cpp
    ${LIBRARY_SOURCE_DIR}/utils.h
)

# Define Library

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

# Define API

if (TARGET ${PROJECT_NAME})

    ## Internal API
    target_include_directories(${PROJECT_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
    )

    ## Public API
    target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

    ## Export API
    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${LIBRARY_HEADERS})

endif()

# Define Install

if (TARGET ${PROJECT_NAME})

    install(TARGETS ${PROJECT_NAME}
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})

endif()

# Setup Test

enable_testing()
add_subdirectory(test)