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

Polygon* createPolygon(Point** points);
void freePolygon(Polygon* polygon);
void printPolygon(Polygon* polygon);

typedef enum {
    POINT,
    LINE,
    CIRCLE,
    RECTANGLE,
    SQUARE,
    POLYGON
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
Shape* createPolygonShape(Point** points);
void freeShape(Shape* shape);
void printShape(Shape* shape);


#endif //PROJETTI202_GEOMETRY_H
