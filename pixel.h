//
// Created by Valentin on 12/05/2023.
//

#include "geometry.h"

#ifndef PROJETTI202_PIXEL_H
#define PROJETTI202_PIXEL_H

typedef struct {
    int x;
    int y;
} Pixel;

Pixel* createPixel(int x, int y);
void deletePixel(Pixel* pixel);

void pixel_forme(Shape* shape, Pixel** pixel, int* nb_pixels);

#endif //PROJETTI202_PIXEL_H
