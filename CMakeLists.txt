cmake_minimum_required(VERSION 3.13)
project(octfiles_101)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(/usr/local/include/octave-4.4.1)

add_executable(octfiles_101
        src/ex01_hello_world.cc
        )
