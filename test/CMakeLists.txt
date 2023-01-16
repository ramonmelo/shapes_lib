# Ignore in case of shared libs
if (NOT BUILD_STATIC_LIBS)
    return()
endif()

# Define Test Project

set(BINARY ${PROJECT_NAME}_test)

## Define Source Code files

set(TEST_SOURCE_DIR src)

set(TEST_SOURCES
    ${TEST_SOURCE_DIR}/main.cpp
    ${TEST_SOURCE_DIR}/PointTest.cpp
)

# Define Test Runner

add_executable(${BINARY} ${TEST_SOURCES})

add_test(
    NAME ${BINARY} 
    COMMAND ${BINARY}
)

# Link Test Framework
target_link_libraries(${BINARY} PUBLIC gtest)

# Link Lib to test
target_link_libraries(${BINARY} PUBLIC ${PROJECT_NAME})