//
// Created by antoine7805 on 15/03/2023.
//

#include "algorithm.h"


void trace_line(Line* line){
    // Déclaration des variables
    int dx, dy;
    int x1, y1;
    int x2, y2;

    // Affectation des variables à partir de la structure line
    x1 = line -> p1 -> x;
    x2 = line -> p2 -> x;
    y1 = line -> p1 -> y;
    y2 = line -> p2 -> y;

    // Calcul de dx et dy
    dx = x2 - x1;
    dy = y2 - y1;

    if (dx != 0) {
        if (dx > 0) {
            if (dy != 0) {
                if (dy > 0) {

                }
            }
        }
    }
}