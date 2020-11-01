cmake_minimum_required(VERSION 2.6)
project(sinet C CXX)

set(CXX_FLAGS
    -g
    -Wall
    -Wextra
    -Werror
    -std=c++11
)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  list(APPEND CXX_FLAGS "-Wno-null-dereference")
  list(APPEND CXX_FLAGS "-Wno-sign-conversion")
  list(APPEND CXX_FLAGS "-Wno-unused-local-typedef")
  list(APPEND CXX_FLAGS "-Wthread-safety")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(sinet)

# uncomment when test
add_executable(sinet_test test/test.cpp)
target_link_libraries(sinet_test sinet)
