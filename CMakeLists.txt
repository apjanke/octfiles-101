cmake_minimum_required(VERSION 3.13)
project(octfiles_101)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(/usr/local/include/octave-4.4.1)

add_executable(octfiles_101
        scratch/s01_01_call_error.cc
        scratch/s01_02_call_error.cc
        src/ex01_hello_world.cc
        src/ex02_scalar_numerics.cc
        src/ex03_inputs_and_error_checking.cc)
