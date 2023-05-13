cmake_minimum_required(VERSION 3.24)
project(ProjetTI202 C)

set(CMAKE_C_STANDARD 23)

if(APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcurses -lncurses")
endif(APPLE)

if(UNIX AND NOT APPLE)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lcurses -ltinfo")
endif(UNIX AND NOT APPLE)

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
        utils.h
        keyboard.c
        keyboard.h
        id.c
        id.h gui.c gui.h area.c area.h)

if(UNIX AND NOT APPLE)
    target_link_libraries(ProjetTI202 ${CURSES_LIBRARIES})
endif(UNIX AND NOT APPLE)
