# Initial cmakeLists referenced from https://github.com/Polytonic/Glitter project
cmake_minimum_required(VERSION 3.0)
project(Opengl-Demos)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(dependencies/glfw)

add_subdirectory(dependencies/glbinding)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++14 -g")

include_directories(dependencies/glfw/include
    dependencies/glm/
    dependencies/glbinding/source/glbinding/include)

file(GLOB
    PROJECT_HEADERS
    src/*.hpp)
file(GLOB
    PROJECT_SOURCES
    src/*.cpp)
file(GLOB
    PROJECT_SHADERS
    src/shaders/*.comp
    src/shaders/*.frag
    src/shaders/*.geom
    src/shaders/*.vert)
file(GLOB
    PROJECT_CONFIGS
    CMakeLists.txt
    Readme.md
    .gitattributes
    .gitignore
    .gitmodules)

source_group("Headers"
    FILES
    ${PROJECT_HEADERS})
source_group("Shaders"
    FILES
    ${PROJECT_SHADERS})
source_group("Sources"
    FILES
    ${PROJECT_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
    -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    ${PROJECT_SHADERS}
    ${PROJECT_CONFIGS})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} glbinding ${GLBINDING_LIBRARIES} ${OPENGL_LIBRARIES})
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

