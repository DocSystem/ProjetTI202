// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Programme principal : contient la boucle principale et les fonctions associées aux commandes

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geometry.h"
#include "utils.h"
#include "area.h"
#include "layer.h"

void execCmd(int* error, Area* area, int* MODE, int* SUBMODE) {
    // Ask user for command, parse it and execute it
    char* cmd = waitForCommand(); // <command> <arg1> <arg2> ...
    Command command = parseCommand(cmd);
    *error = 0;
    if (strcmp(command.command, "clear") == 0) {
        // clear
        *MODE = -1;
        clearScreen();
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
    else if (strcmp(command.command, "circle") == 0) {
        // circle <x> <y> <radius>
        if (command.arg_count != 3) {
            *error = 1;
            return;
        }
        int x = parseInt(command.args[0]);
        int y = parseInt(command.args[1]);
        int radius = parseInt(command.args[2]);

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
        Point** points = malloc(sizeof(Point*) * command.arg_count / 2);
        for (int i = 0; i < command.arg_count / 2; i++) {
            points[i] = createPoint(x[i], y[i]);
        }
        Shape* p = createPolygonShape(points, command.arg_count / 2);
        // add polygon to area
        add_shape_to_area(area, p);
    }
    else if (strcmp(command.command, "plot") == 0) {
        // plot
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
        else if (strcmp(command.args[0], "layers") == 0) {
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
            lnode* n1 = area->list_layers->head;
            while (n1 != NULL) {
                Layer* l = (Layer*) n1->data;
                lnode* n2 = l->shapes->head;
                while (n2 != NULL) {
                    Shape* s = (Shape*) n2->data;
                    if (s->id == parseInt(command.args[1])) {
                        lst_delete_node(l->shapes, n2);
                        return;
                    }
                    n2 = n2->next;
                }
                n1 = n1->next;
            }
            *error = 1;
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
        // erase
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
        // help
        *MODE = 2;
    }
    else {
        *error = 1;
    }
}

int main() {
    int emojiSupported = 1;
    #if WIN32
    // Allow emojis on Windows
    system("chcp 65001 > nul");
    if (getenv("WT_SESSION") == NULL) {
        emojiSupported = 0;
    }
    #endif

    int MODE = 0;
    int SUBMODE = 0;

    win_size size = getWindowSize();

    Area* drawingArea = create_area(size.width, size.height - 1);
    clear_area(drawingArea);

    int error = 0;

    clearScreen();
    while (1) {
        size = getWindowSize();
        if (size.width != drawingArea->width || size.height != drawingArea->height) {
            // window size changed
            drawingArea->width = size.width;
            drawingArea->height = size.height - 1;

        }
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
                    printAtCoos(0, 0, "Shapes:\n");
                    printf("ID\tLayer\tShape\n");
                    lnode* n1 = drawingArea->list_layers->head;
                    while (n1 != NULL) {
                        Layer* l = (Layer*) n1->data;
                        lnode* n2 = l->shapes->head;
                        while (n2 != NULL) {
                            Shape* s = (Shape*) n2->data;
                            printf("%d\t%s\t", s->id, l->name);
                            printShape(s);
                            n2 = n2->next;
                        }
                        n1 = n1->next;
                    }
                }
                else if (SUBMODE == 2) {
                    // show list layer
                    printAtCoos(0, 0, "Layers:\n");
                    printf("ID\tName\tVisible\tSelected\n");
                    int i = 1;
                    lnode* n = drawingArea->list_layers->head;
                    while (n != NULL) {
                        Layer* l = (Layer*) n->data;
                        char* name = l->name;
                        int id = l->id;
                        if (emojiSupported) {
                            char *visible = l->visible ? "❌" : "✅";
                            char *selected = drawingArea->id_layer == l->id ? "✅" : "❌";
                            printf("%d\t%s\t%s\t%s\n", id, name, visible, selected);
                        }
                        else {
                            char *visible = l->visible ? "Non" : "Oui";
                            char *selected = drawingArea->id_layer == l->id ? "Oui" : "Non";
                            printf("%d\t%s\t%s\t%s\n", id, name, visible, selected);
                        }
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
            if (emojiSupported) {
                printAtCoos(size.width - 1, size.height, "❌");
            }
            else {
                printAtCoos(size.width - 1, size.height, "X");
            }
        }
        execCmd(&error, drawingArea, &MODE, &SUBMODE);
    }

    return 0;
}
