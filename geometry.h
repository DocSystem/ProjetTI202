//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_GEOMETRY_H
#define PROJETTI202_GEOMETRY_H



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
    Point** points;
} Polygon;

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



#endif //PROJETTI202_GEOMETRY_H
