cmake_minimum_required (VERSION 3.7)

add_executable(helloworld helloworld.cpp)
add_executable(arrays arrays.cpp)


set (HEADER_FILES
  container.h
)

set (SOURCE_FILES
  container.cpp
)

add_executable(container ${HEADER_FILES} ${SOURCE_FILES})
