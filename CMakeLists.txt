cmake_minimum_required(VERSION 3.8)
project(library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-parentheses -pedantic")

add_subdirectory(library)
add_subdirectory(utility)
