//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_GEOMETRY_H
#define PROJETTI202_GEOMETRY_H


#include "double_chained_list.h"

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
        Point* p1;
        Point* p2;
} Line;

typedef struct {
        Point* center;
        int radius;
} Circle;

typedef struct {
    Point* p;
    int width;
    int height;
} Rectangle;

typedef struct {
    Point* p;
    int side;
} Square;

typedef struct {
    int nbPoints;
    Point** points;
} Polygon;

typedef struct {
    Point* p1;
    Point* p2;
    Point* p3;
    Point* p4;
} Curve;

Point* createPoint(int x, int y);
void freePoint(Point* point);
void printPoint(Point* point);


Line* createLine(Point* p1, Point* p2);
void freeLine(Line* line);
void printLine(Line* line);


Circle* createCircle(Point* center, int radius);
void freeCircle(Circle* circle);
void printCircle(Circle* circle);

Rectangle* createRectangle(Point* p, int width, int height);
void freeRectangle(Rectangle* rectangle);
void printRectangle(Rectangle* rectangle);

Square* createSquare(Point* p, int side);
void freeSquare(Square* square);
void printSquare(Square* square);

Polygon* createPolygon(Point** points, int nbPoints);
void freePolygon(Polygon* polygon);
void printPolygon(Polygon* polygon);

Curve* createCurve(Point* p1, Point* p2, Point* p3, Point* p4);
void freeCurve(Curve* curve);
void printCurve(Curve* curve);

typedef enum {
    POINT,
    LINE,
    CIRCLE,
    RECTANGLE,
    SQUARE,
    POLYGON,
    CURVE
} ShapeType;

typedef struct {
    ShapeType type;
    int id;
    void* ptrShape;
} Shape;

Shape* createEmptyShape(ShapeType type);
Shape* createPointShape(int x, int y);
Shape* createLineShape(Point* p1, Point* p2);
Shape* createCircleShape(Point* center, int radius);
Shape* createRectangleShape(Point* p, int width, int height);
Shape* createSquareShape(Point* p, int side);
Shape* createPolygonShape(Point** points, int nbPoints);
Shape* createCurveShape(Point* p1, Point* p2, Point* p3, Point* p4);
void freeShape(Shape* shape);
void printShape(Shape* shape);


typedef struct pixel_{
    int x;
    int y;
} Pixel;

void addPixel(List* lPixels, Pixel* pixel);

Pixel* createPixel(int x, int y);
void deletePixel(Pixel* pixel);

void drawPoint(Point* point, List* pixels);
void drawLine(Line* line, List* pixels);
void drawCircle(Circle* circle, List* pixels);
void drawRectangle(Rectangle* rectangle, List* pixels);
void drawSquare(Square* square, List* pixels);
void drawPolygon(Polygon* polygon, List* pixels);


void drawShape(Shape* shape, List* pixels;

#endif //PROJETTI202_GEOMETRY_H
