//
// Created by antoine7805 on 15/03/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include "utils.h"
#include "algorithm.h"


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
    return line;
}

void freeLine(Line* line){
    free(line);
}

void printLine(Line* line) {
    printf("Line: ");
    printPoint(line -> p1);
    printf(" - ");
    printPoint(line -> p2);
    traceLine(line);
}

Circle* createCircle(Point* center, int radius) {
    Circle* circle = malloc(sizeof(Circle));
    circle -> center = center;
    circle -> radius = radius;
    return circle;
}

void freeCircle(Circle* circle) {
    free(circle);
}

void printCircle(Circle* circle) {
    printf("Circle: ");
    printPoint(circle -> center);
    printf(" - %d", circle -> radius);
    traceCircle(circle);
}
