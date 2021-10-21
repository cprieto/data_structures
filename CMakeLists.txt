cmake_minimum_required(VERSION 3.20)
project(data_structures)

# With LLVM this is required for Catch2!
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(Catch2 REQUIRED)

list(APPEND SOURCE
        src/stuff.c)

add_library(ds OBJECT ${SOURCE})
set_property(TARGET ds PROPERTY C_STANDARD 11)

list(APPEND TESTS
        src/test_main.cpp
        src/stuff_test.cpp)

add_executable(tests ${TESTS})

target_link_libraries(tests PRIVATE ds Catch2::Catch2)
