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
    printAtCoos(point -> x, point -> y, "X");
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

Square* createSquare(Point* p, int side) {
    Square* square = malloc(sizeof(Square));
    square -> p = p;
    square -> side = side;
    return square;
}

void freeSquare(Square* square) {
    free(square);
}

void printSquare(Square* square) {
    // A square is a special rectangle
    Rectangle* rectangle = createRectangle(square -> p, square -> side, square -> side);
    printRectangle(rectangle);
}

Polygon* createPolygon(Point** points) {
    Polygon* polygon = malloc(sizeof(Polygon));
    polygon -> points = points;
    return polygon;
}

void freePolygon(Polygon* polygon) {
    free(polygon);
}

void printPolygon(Polygon* polygon) {
    int i;
    // Initialization of the lines of the polygon
    Line* line;
    // Trace the lines of the polygon
    for (i = 0; i < sizeof(polygon -> points) / sizeof(polygon -> points[0]) - 1; i++) {
        line = createLine(polygon -> points[i], polygon -> points[i + 1]);
        traceLine(line);
        freeLine(line);
    }
    // Trace the last line of the polygon
    line = createLine(polygon -> points[i], polygon -> points[0]);
    traceLine(line);
    freeLine(line);
}
