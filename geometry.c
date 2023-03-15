//
// Created by antoine7805 on 15/03/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"


Point* createPoint(int x, int y) {
    Point* point = malloc(sizeof(Point));
    point -> x = x;
    point -> y = y;
    return point;
}

void freePoint(Point* point) {
    free(point);
}

void printPoint(Point* point) {
    printf("%d, %d", point -> x, point -> y);
}

Line* createLine(Point* p1, Point* p2) {
    Line* line = malloc(sizeof(Line));
    line -> p1 = p1;
    line -> p2 = p2;
}

void freeLine(line* line){
    free(line);
}

