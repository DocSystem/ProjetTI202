#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "geometry.h"
#include "utils.h"
#include "gui.h"
#include "area.h"

int main() {

    Area* drawingArea = create_area(10, 10);

    int choice = 0;
    while (choice != -99) {
        choice = ActionChoice(drawingArea);
    }
    return 0;
}
