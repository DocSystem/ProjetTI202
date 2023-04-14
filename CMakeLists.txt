cmake_minimum_required(VERSION 3.25)
project(ProjetTI202 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcurses -ocurses-test")

include_directories(.)

add_executable(ProjetTI202
        algorithm.c
        algorithm.h
        chained_list.c
        chained_list.h
        geometry.c
        geometry.h
        main.c
        menu.c
        menu.h
        utils.c
        utils.h keyboard.c keyboard.h)
