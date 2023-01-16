cmake_minimum_required(VERSION 3.20)
project(ProjectShapes VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(lib/googletest)
add_subdirectory(projects/shapes)

# set(PROJECT_SOURCE_DIR test_app/src)

#set(PROJECT_SOURCES
#    ${PROJECT_SOURCE_DIR}/main.cpp
#)

# Import Library
#set(BUILD_STATIC_LIBS ON BOOL) # Build as Static
#add_subdirectory(shapes)

#add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
#target_link_libraries(${PROJECT_NAME} PRIVATE shapes)