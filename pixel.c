//
// Created by Valentin on 12/05/2023.
//

#include <stdlib.h>
#include "pixel.h"
#include "geometry.h"

Pixel* createPixel(int x, int y) {
    Pixel* pixel = malloc(sizeof(Pixel));
    pixel->x = x;
    pixel->y = y;
    return pixel;
}

void deletePixel(Pixel* pixel) {
    free(pixel);
}

