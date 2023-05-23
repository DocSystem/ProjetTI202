cmake_minimum_required(VERSION 3.24)
project(ProjetTI202 C)

set(CMAKE_C_STANDARD 23)

include_directories(.)

add_executable(ScribbleVibes
        algorithm.c
        algorithm.h
        area.c
        area.h
        double_chained_list.c
        double_chained_list.h
        geometry.c
        geometry.h
        id.c
        id.h
        layer.c
        layer.h
        main.c
        utils.c
        utils.h)
