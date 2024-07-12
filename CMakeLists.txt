cmake_minimum_required(VERSION 3.10)
project(numa VERSION 0.0.0 LANGUAGES C)

set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(numa STATIC src/numa.c)

target_include_directories(numa PUBLIC include)
