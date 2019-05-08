CMAKE_MINIMUM_REQUIRED(VERSION 3.0 )
PROJECT(LearnOpenGLTutorial)

set (CMAKE_CXX_STANDARD 14)

# Build GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
ADD_SUBDIRECTORY (libs/glfw)

#include directories glad
INCLUDE_DIRECTORIES (
    libs/glfw/include
    libs/glad/include
    include)

#Source Files and Headers
SET ( SRC_FILES "src/hello_window.cpp"
                "src/callbacks.cpp"
                "libs/glad/src/glad.c"
                "src/hello_triangle.cpp" )
SET ( HEADER_FILES "libs/glad/include/glad/glad.h"
                "include/LearnOpenGL/hello_window.h" 
                "include/LearnOpenGL/hello_triangle.h"
                "include/LearnOpenGL/callbacks.h" )

#build library
ADD_LIBRARY (${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES (${PROJECT_NAME} glfw)

ADD_EXECUTABLE ( main "src/main.cpp" )
TARGET_LINK_LIBRARIES (main ${PROJECT_NAME})