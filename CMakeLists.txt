cmake_minimum_required(VERSION 3.16)

project(TuringSurakarta)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(INSTALL_DIR ${CMAKE_SOURCE_DIR}/surakarta_ta)

set(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra")
set(ENV "TEST" CACHE STRING "DEV or TEST, for students, please use TEST")

add_subdirectory(src)

