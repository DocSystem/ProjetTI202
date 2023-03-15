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
    Point* p = createPoint(100, 200);
    Point* p2 = createPoint(200, 300);
    Line* l = createLine(p, p2);
    printLine(l);
    freeLine(l);
    // clearScreen();
    // sleep(5);
    return 0;
}
