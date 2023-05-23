#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "geometry.h"
#include "utils.h"
#include "chained_list.h"
#include "area.h"

void execCmd(int* error, Area* area) {
    // split cmd into two variables
    // first variable is the command
    // second variable is an array of arguments
    char* cmd = waitForCommand(); // <command> <arg1> <arg2> ...
    Command command = parseCommand(cmd);
    *error = 0;
    if (strcmp(command.command, "clear") == 0) {
        // clear
    }
    else if (strcmp(command.command, "exit") == 0) {
        // exit
        exit(0);
    }
    else if (strcmp(command.command, "point") == 0) {
        // point <x> <y>
        if (command.arg_count != 2) {
            *error = 1;
            return;
        }
        int x = parseInt(command.args[0]);
        int y = parseInt(command.args[1]);
        Shape* p = createPointShape(x, y);
        // add point to area
        add_shape_to_area(area, p);
    }
    else if (strcmp(command.command, "line") == 0) {
        // line <x1> <y1> <x2> <y2>
        if (command.arg_count != 4) {
            *error = 1;
            return;
        }
        int x1 = parseInt(command.args[0]);
        int y1 = parseInt(command.args[1]);
        int x2 = parseInt(command.args[2]);
        int y2 = parseInt(command.args[3]);
        Point* p1 = createPoint(x1, y1);
        Point* p2 = createPoint(x2, y2);
        Shape* l = createLineShape(p1, p2);
        // add line to area
        add_shape_to_area(area, l);
    }
    else {
        *error = 1;
    }
}

int main() {
    /*showWindowBox();
    Point* p = createPoint(10, 2);
    Point* p2 = createPoint(20, 3);
    Line* l = createLine(p, p2);
    printLine(l);
    freeLine(l);
    // clearScreen();
    // sleep(5);
    scanf("%s");
    */
    //showWindowBox();

    Area* drawingArea = create_area(100, 100);
    clear_area(drawingArea);

    int error = 0;

    clearScreen();
    while (1) {
        win_size size = getWindowSize();
        showWindowBox();
        // render shapes
        draw_area(drawingArea);
        if (error == 1) {
            printAtCoos(size.width - 1, size.height, "❌");
        }
        execCmd(&error, drawingArea);
    }

    return 0;
}
