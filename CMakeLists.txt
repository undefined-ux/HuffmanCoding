cmake_minimum_required(VERSION 3.30)
project(FProject C)

set(CMAKE_C_STANDARD 11)

add_library(huffman
        huffman.h
        Process/encoder.c
        Process/encoder.h
        Process/input.c
        Process/input.h
        Process/output.c
        Process/output.h
        Process/types.h)

add_executable(FProject
        main.c
)

target_link_libraries(FProject huffman)
