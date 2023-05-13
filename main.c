#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "geometry.h"
#include "utils.h"
#include "chained_list.h"
#include "gui.h"
#include "area.h"

int main() {

    Maillon** lShapes = malloc(sizeof(Maillon*));
    *lShapes = NULL;
    Area** lAreas = malloc(sizeof(Area*));
    *lAreas = NULL;

    int choice = 0;
    while (choice != -99) {
        choice = ActionChoice(lShapes, lAreas);
    }
    return 0;
}
