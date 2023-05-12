#include <stdio.h>

#include "menu.h"
#include "geometry.h"
#include "utils.h"
#include "chained_list.h"
#include "area.h"

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

    Maillon* ShapeList = NULL;

    while (1) {
        Area* a = create_area(10, 10);
        add_shape_to_area(a, createPointShape(1, 1));
        delete_area(a);
    }

    int choice = -100;
    while (choice != -99) {
        choice = ActionChoice(&ShapeList);
    }

    return 0;
}
