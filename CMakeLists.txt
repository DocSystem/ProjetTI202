cmake_minimum_required(VERSION 3.24)
project(ProjetTI202 C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetTI202 main.c utils.c utils.h geometry.c geometry.h algorithm.c algorithm.h)
