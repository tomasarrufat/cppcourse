set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

################################
# GTest
################################
#ADD_SUBDIRECTORY (googletest)
#enable_testing()
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)


find_package(Boost 1.65.1)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR}/src)
  add_executable(${ProjectId} ${project_sources} ${project_headers})
  add_library(${ProjectId}lib ${project_sources} ${project_headers})
  target_link_libraries(${ProjectId} PUBLIC ${Boost_LIBRARIES})
  #add_test(NAME SingletonTotalPopulationTest COMMAND example)
endif()

enable_testing()
add_subdirectory(test)

file(COPY data/countries DESTINATION ${CMAKE_BINARY_DIR})

