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

Rectangle* createRectangle(Point* p, int width, int height) {
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    rectangle -> p = p;
    rectangle -> width = width;
    rectangle -> height = height;
    return rectangle;
}

void freeRectangle(Rectangle* rectangle) {
    free(rectangle);
}

void printRectangle(Rectangle* rectangle) {
    printf("Rectangle: ");
    printPoint(rectangle -> p);
    printf(" - %d, %d", rectangle -> width, rectangle -> height);
    // Initialization of the 4 points of the rectangle
    Point* corner0 = createPoint(rectangle -> p -> x, rectangle -> p -> y);
    Point* corner1 = createPoint(rectangle -> p -> x + rectangle -> width, rectangle -> p -> y);
    Point* corner2 = createPoint(rectangle -> p -> x + rectangle -> width, rectangle -> p -> y + rectangle -> height);
    Point* corner3 = createPoint(rectangle -> p -> x, rectangle -> p -> y + rectangle -> height);
    // Initialization of the 4 lines of the rectangle
    Line* line0 = createLine(corner0, corner1);
    Line* line1 = createLine(corner1, corner2);
    Line* line2 = createLine(corner2, corner3);
    Line* line3 = createLine(corner3, corner0);
    // Trace the 4 lines of the rectangle
    traceLine(line0);
    traceLine(line1);
    traceLine(line2);
    traceLine(line3);
    // Free the 4 lines of the rectangle from memory
    freeLine(line0);
    freeLine(line1);
    freeLine(line2);
    freeLine(line3);
    // Free the 4 points of the rectangle from memory
    freePoint(corner0);
    freePoint(corner1);
    freePoint(corner2);
    freePoint(corner3);
}
