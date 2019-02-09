cmake_minimum_required(VERSION 3.10.2)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# The version number.
set (${ProjectId}_VERSION_MAJOR 1)
set (${ProjectId}_VERSION_MINOR 1)

# should we use the correct of incorrect implementation
option(USE_PRINCIPLE "Use SOLID Principle shown in the example" ON)

# configure a header file to pass some of the CMake settings
# to the source code
set (PROJECT_SOURCE_INC_DIR "${PROJECT_SOURCE_DIR}/include")
set (PROJECT_BINARY_INC_DIR "${PROJECT_BINARY_DIR}/include")
configure_file (
  "${PROJECT_SOURCE_INC_DIR}/Config.h.in"
  "${PROJECT_BINARY_INC_DIR}/Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_INC_DIR}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 17)



file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

add_executable(${ProjectId} ${project_sources} ${project_headers})
