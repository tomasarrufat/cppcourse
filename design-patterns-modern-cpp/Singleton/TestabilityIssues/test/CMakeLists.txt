add_executable(
    unit_tests
    singletonTest.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    ${ProjectId}lib
    )

add_test(
  NAME
    unit
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND
    ${CMAKE_INSTALL_BINDIR}/unit_tests
  )