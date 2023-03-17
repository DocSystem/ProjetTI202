#include <stdio.h>
#include "utils.h"
#include "geometry.h"

void showMenu(int menuId) {
    if (menuId == 0) {
        // Main menu
        // clearScreen();

    }
}

int main() {
    showWindowBox();
    Point* p = createPoint(10, 2);
    Point* p2 = createPoint(20, 3);
    Line* l = createLine(p, p2);
    printLine(l);
    freeLine(l);
    // clearScreen();
    // sleep(5);
    return 0;
}
