cmake_minimum_required(VERSION 3.20)
project(algo)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(Catch2 REQUIRED)

list(APPEND SOURCES
        src/stuff.c)

# This line is required for the compiler
# if not, it won't link the C files
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE CXX)

add_library(algo OBJECT ${SOURCES})

list(APPEND TESTS
        src/test_main.cpp
        src/stuff_test.cpp)

add_executable(tests ${TESTS})

target_link_libraries(tests PRIVATE algo Catch2::Catch2)
