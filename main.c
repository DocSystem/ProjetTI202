#include <stdio.h>

#include "menu.h"
#include "geometry.h"
#include "utils.h"
#include "chained_list.h"

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

    int choice = -100;
    while (choice != -99) {
        choice = ActionChoice(&ShapeList);
    }

    return 0;
}
