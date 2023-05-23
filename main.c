#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geometry.h"
#include "utils.h"
#include "area.h"
#include "layer.h"

void execCmd(int* error, Area* area, int* MODE, int* SUBMODE) {
    // split cmd into two variables
    // first variable is the command
    // second variable is an array of arguments
    char* cmd = waitForCommand(); // <command> <arg1> <arg2> ...
    Command command = parseCommand(cmd);
    *error = 0;
    if (strcmp(command.command, "clear") == 0) {
        *MODE = -1;
        clearScreen();
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
        if (x1 < 0 || x1 >= area->width - 1 || x2 < 0 || x2 >= area->width - 1 || y1 < 0 || y1 >= area->height - 2 || y2 < 0 || y2 >= area->height - 2) {
            *error = 1;
            return;
        }
        Point* p1 = createPoint(x1, y1);
        Point* p2 = createPoint(x2, y2);
        Shape* l = createLineShape(p1, p2);
        // add line to area
        add_shape_to_area(area, l);
    }
    else if (strcmp(command.command, "circle") == 0) {
        // circle <x> <y> <radius>
        if (command.arg_count != 3) {
            *error = 1;
            return;
        }
        int x = parseInt(command.args[0]);
        int y = parseInt(command.args[1]);
        int radius = parseInt(command.args[2]);
        if (x < 0 || x >= area->width - 1 || y < 0 || y >= area->height - 2) {
            *error = 1;
            return;
        }
        Point* p = createPoint(x, y);
        Shape* c = createCircleShape(p, radius);
        // add circle to area
        add_shape_to_area(area, c);
    }
    else if (strcmp(command.command, "square") == 0) {
        // square <x> <y> <length>
        if (command.arg_count != 3) {
            *error = 1;
            return;
        }
        int x = parseInt(command.args[0]);
        int y = parseInt(command.args[1]);
        int length = parseInt(command.args[2]);
        if (x < 0 || x >= area->width - 1 || y < 0 || y >= area->height - 2) {
            *error = 1;
            return;
        }
        Point* p = createPoint(x, y);
        Shape* s = createSquareShape(p, length);
        // add square to area
        add_shape_to_area(area, s);
    }
    else if (strcmp(command.command, "rectangle") == 0) {
        // rectangle <x> <y> <width> <height>
        if (command.arg_count != 4) {
            *error = 1;
            return;
        }
        int x = parseInt(command.args[0]);
        int y = parseInt(command.args[1]);
        int width = parseInt(command.args[2]);
        int height = parseInt(command.args[3]);
        if (x < 0 || x >= area->width - 1 || y < 0 || y >= area->height - 2) {
            *error = 1;
            return;
        }
        Point* p = createPoint(x, y);
        Shape* r = createRectangleShape(p, width, height);
        // add rectangle to area
        add_shape_to_area(area, r);
    }
    else if (strcmp(command.command, "polygon") == 0) {
        // polygon <x1> <y1> <x2> <y2> ... <xn> <yn>
        if (command.arg_count < 6 || command.arg_count % 2 != 0) {
            *error = 1;
            return;
        }
        int* x = malloc(sizeof(int) * command.arg_count / 2);
        int* y = malloc(sizeof(int) * command.arg_count / 2);
        for (int i = 0; i < command.arg_count; i++) {
            if (i % 2 == 0) {
                x[i / 2] = parseInt(command.args[i]);
            }
            else {
                y[i / 2] = parseInt(command.args[i]);
            }
        }
        for (int i = 0; i < command.arg_count / 2; i++) {
            if (x[i] < 0 || x[i] >= area->width - 1 || y[i] < 0 || y[i] >= area->height - 2) {
                *error = 1;
                return;
            }
        }
        Point** points = malloc(sizeof(Point*) * command.arg_count / 2);
        for (int i = 0; i < command.arg_count / 2; i++) {
            points[i] = createPoint(x[i], y[i]);
        }
        Shape* p = createPolygonShape(points, command.arg_count / 2);
        // add polygon to area
        add_shape_to_area(area, p);
    }
    else if (strcmp(command.command, "plot") == 0) {
        *MODE = 0;
    }
    else if (strcmp(command.command, "list") == 0) {
        // list <shapes|layer>
        if (command.arg_count != 1) {
            *error = 1;
            return;
        }
        if (strcmp(command.args[0], "shapes") == 0) {
            *MODE = 1;
            *SUBMODE = 1;
        }
        else if (strcmp(command.args[0], "layer") == 0) {
            *MODE = 1;
            *SUBMODE = 2;
        }
        else {
            *error = 1;
        }
    }
    else if (strcmp(command.command, "delete") == 0) {
        // delete <shape|layer> <id>
        if (command.arg_count != 2) {
            *error = 1;
            return;
        }
        if (strcmp(command.args[0], "shape") == 0) {
            // delete shape <id>
        }
        else if (strcmp(command.args[0], "layer") == 0) {
            // delete layer <id>
            Layer* l = access_layer_by_id(area->list_layers, parseInt(command.args[1]));
            remove_layer_from_list(area->list_layers, l);
            delete_layer(l);
        }
        else {
            *error = 1;
        }
    }
    else if (strcmp(command.command, "erase") == 0) {
        erase_area(area);
    }
    else if (strcmp(command.command, "new") == 0) {
        // new layer <name>
        if (command.arg_count != 2) {
            *error = 1;
            return;
        }
        if (strcmp(command.args[0], "layer") == 0) {
            // new layer <name>
            Layer* l = create_layer(command.args[1]);
            add_layer_to_list(area->list_layers, l);
            area->id_layer = l->id;
        }
        else {
            *error = 1;
        }
    }
    else if (strcmp(command.command, "layer") == 0) {
        // layer <id>
        if (command.arg_count != 1) {
            *error = 1;
            return;
        }
        int id = parseInt(command.args[0]);
        if (id < 0) {
            *error = 1;
            return;
        }
        Layer* l = access_layer_by_id(area->list_layers, id);
        if (l == NULL) {
            *error = 1;
            return;
        }
        // set current layer
        area->id_layer = id;
    }
    else if (strcmp(command.command, "set") == 0) {
        // set layer <visible|hide> <id>
        if (command.arg_count != 3) {
            *error = 1;
            return;
        }
        if (strcmp(command.args[0], "layer") == 0) {
            // set layer <visible|hide> <id>
            int id = parseInt(command.args[2]);
            if (id < 0) {
                *error = 1;
                return;
            }
            Layer* l = access_layer_by_id(area->list_layers, id);
            if (l == NULL) {
                *error = 1;
                return;
            }
            if (strcmp(command.args[1], "show") == 0) {
                set_layer_visible(l);
            }
            else if (strcmp(command.args[1], "hide") == 0) {
                set_layer_invisible(l);
            }
            else {
                *error = 1;
                return;
            }
        }
        else {
            *error = 1;
            return;
        }
    }
    else if (strcmp(command.command, "help") == 0) {
        *MODE = 2;
    }
    else {
        *error = 1;
    }
}

int main() {
    #if WIN32
    // Allow emojis on Windows
    system("chcp 65001");
    #endif
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

    int MODE = 0;
    int SUBMODE = 0;

    win_size size = getWindowSize();

    Area* drawingArea = create_area(size.width, size.height - 1);
    clear_area(drawingArea);

    int error = 0;

    clearScreen();
    while (1) {
        // showWindowBox();
        // render shapes
        clearScreen();
        switch (MODE) {
            case 0:
                // show plot (default / command `plot`)
                draw_area(drawingArea);
                print_area(drawingArea);
                break;

            case 1:
                // show list
                if (SUBMODE == 1) {
                    // show list shapes

                }
                else if (SUBMODE == 2) {
                    // show list layer
                    printAtCoos(0, 0, "Layers:\n");
                    printf("ID\tName\tVisible\tSelected\n");
                    int i = 1;
                    lnode* n = drawingArea->list_layers->head;
                    while (n != NULL) {
                        Layer* l = (Layer*) n->data;
                        char* visible = l->visible ? "❌" : "✅";
                        char* selected = drawingArea->id_layer == l->id ? "✅" : "❌";
                        char* name = l->name;
                        int id = l->id;
                        printf("%d\t%s\t%s\t%s\n", id, name, visible, selected);
                        n = n->next;
                    }
                }
                else {
                    MODE = 0;
                }
                break;

            case 2:
                // show help (command `help`)
                printHelp();
                break;

            case -1:
                // show nothing (screen cleared)
                break;

            default:
                MODE = 0;
                break;
        }
        if (error == 1) {
            printAtCoos(size.width - 1, size.height, "❌");
        }
        execCmd(&error, drawingArea, &MODE, &SUBMODE);
    }

    return 0;
}
