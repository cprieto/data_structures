cmake_minimum_required(VERSION 3.28)
project(data_structures)

set(CMAKE_CXX_STANDARD 17)

# Require for tests
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.6.0
)
FetchContent_MakeAvailable(Catch2)


add_subdirectory(dictionaries)

add_library(data_structures OBJECT)
add_subdirectory(trees)

## tests
add_executable(all_tests all_tests.cpp
        trees/btree_tests.cpp)
target_link_libraries(all_tests PRIVATE Catch2::Catch2WithMain data_structures)
