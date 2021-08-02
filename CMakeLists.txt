cmake_minimum_required(VERSION 3.17)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long
        srcs/main.c
        headers/main.h)