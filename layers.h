//
// Created by Valentin on 17/03/2023.
//

#ifndef PROJETTI202_LAYERS_H
#define PROJETTI202_LAYERS_H

#include "geometry.h"

typedef struct { // Un calque est un ensemble de formes géométriques, chacune stockée dans une liste
    Point* points;
    int nbPoints;
    Line* lines;
    int nbLines;
    Circle* circles;
    int nbCircles;
    Rectangle* rectangles;
    int nbRectangles;
    Square* squares;
    int nbSquares;
    Polygon* polygons;
    int nbPolygons;
} Layer;

#endif //PROJETTI202_LAYERS_H
