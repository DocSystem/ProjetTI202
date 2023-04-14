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
    printf("Point (%d, %d)\n", point -> x, point -> y);
}

void drawPoint(Point* point) {
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
    printf("Line (%d, %d) -> (%d, %d)\n", line -> p1 -> x, line -> p1 -> y, line -> p2 -> x, line -> p2 -> y);
}

void drawLine(Line* line) {
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
    printf("Circle (%d, %d) with radius %d\n", circle -> center -> x, circle -> center -> y, circle -> radius);
}

void drawCircle(Circle* circle) {
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
    printf("Rectangle (%d, %d) with width %d and height %d\n", rectangle -> p -> x, rectangle -> p -> y, rectangle -> width, rectangle -> height);
}

void drawRectangle(Rectangle* rectangle) {
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
    printf("Square (%d, %d) with side %d\n", square -> p -> x, square -> p -> y, square -> side);
}

void drawSquare(Square* square) {
    // A square is a special rectangle
    Rectangle* rectangle = createRectangle(square -> p, square -> side, square -> side);
    printRectangle(rectangle);
}

Polygon* createPolygon(Point** points, int nbPoints) {
    Polygon* polygon = malloc(sizeof(Polygon));
    polygon -> points = points;
    polygon -> nbPoints = nbPoints;
    return polygon;
}

void freePolygon(Polygon* polygon) {
    free(polygon);
}

void printPolygon(Polygon* polygon) {
    printf("Polygon with %d points\n", polygon -> nbPoints);
    for (int i = 0; i < polygon -> nbPoints; i++) {
        printPoint(polygon -> points[i]);
    }
}

void drawPolygon(Polygon* polygon) {
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

Shape* createEmptyShape(ShapeType type) {
    Shape* shape = malloc(sizeof(Shape));
    // Valeur par défault
    shape -> ptrShape = NULL;
    shape -> id = -1; // Il manque encore la fonction GetNextId()
    // Type de la forme qui sera stockée
    shape -> type = type;
    return shape;
}

Shape* createPointShape(int x, int y) {
    Shape* shape = createEmptyShape(POINT);
    Point* point = createPoint(x, y);
    shape -> ptrShape = (Point*) point;
    return shape;
}

Shape* createLineShape(Point* p1, Point* p2) {
    Shape* shape = createEmptyShape(LINE);
    Line* line = createLine(p1, p2);
    shape -> ptrShape = line;
    return shape;
}

Shape* createCircleShape(Point* center, int radius) {
    Shape* shape = createEmptyShape(CIRCLE);
    Circle* circle = createCircle(center, radius);
    shape -> ptrShape = circle;
    return shape;
}

Shape* createRectangleShape(Point* p, int width, int height) {
    Shape* shape = createEmptyShape(RECTANGLE);
    Rectangle* rectangle = createRectangle(p, width, height);
    shape -> ptrShape = rectangle;
    return shape;
}

Shape* createSquareShape(Point* p, int side) {
    Shape* shape = createEmptyShape(SQUARE);
    Square* square = createSquare(p, side);
    shape -> ptrShape = square;
    return shape;
}

Shape* createPolygonShape(Point** points) {
    Shape* shape = createEmptyShape(POLYGON);
    Polygon* polygon = createPolygon(points, sizeof(points) / sizeof(points[0]));
    shape -> ptrShape = polygon;
    return shape;
}

void freeShape(Shape* shape) {
    switch (shape -> type) {
        case POINT:
            freePoint(shape -> ptrShape);
            break;
        case LINE:
            freeLine(shape -> ptrShape);
            break;
        case CIRCLE:
            freeCircle(shape -> ptrShape);
            break;
        case RECTANGLE:
            freeRectangle(shape -> ptrShape);
            break;
        case SQUARE:
            freeSquare(shape -> ptrShape);
            break;
        case POLYGON:
            freePolygon(shape -> ptrShape);
            break;
    }
    free(shape);
}

void printShape(Shape* shape) {
    switch (shape -> type) {
        case POINT:
            printPoint(shape -> ptrShape);
            break;
        case LINE:
            printLine(shape -> ptrShape);
            break;
        case CIRCLE:
            printCircle(shape -> ptrShape);
            break;
        case RECTANGLE:
            printRectangle(shape -> ptrShape);
            break;
        case SQUARE:
            printSquare(shape -> ptrShape);
            break;
        case POLYGON:
            printPolygon(shape -> ptrShape);
            break;
    }
}

void drawShape(Shape* shape) {
    switch (shape -> type) {
        case POINT:
            drawPoint(shape -> ptrShape);
            break;
        case LINE:
            drawLine(shape -> ptrShape);
            break;
        case CIRCLE:
            drawCircle(shape -> ptrShape);
            break;
        case RECTANGLE:
            drawRectangle(shape -> ptrShape);
            break;
        case SQUARE:
            drawSquare(shape -> ptrShape);
            break;
        case POLYGON:
            drawPolygon(shape -> ptrShape);
            break;
    }
}
