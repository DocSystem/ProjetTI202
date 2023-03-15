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
    printf("Hello, World!\n");
    printPoint(p);
    freePoint(p);
    // clearScreen();
    // sleep(5);
    return 0;
}
