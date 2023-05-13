//
// Created by Valentin on 14/04/2023.
//

#include <stdlib.h>
#include <stdio.h>

#include "geometry.h"
#include "area.h"
#include "chained_list.h"

Area* create_area(unsigned int width, unsigned int height) {
    Area* area = malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = malloc(sizeof(BOOL*) * width);
    for (int i = 0; i < width; ++i) {
        area->mat[i] = malloc(sizeof(BOOL) * height);
    }
    area->nb_shape = 0;
    area->shapes = malloc(sizeof(Maillon*));
    return area;
}

void add_shape_to_area(Area* area, Shape* shape) {
    if (area->shapes == NULL) {
        area->shapes = createMaillon(shape);
    } else {
        addMaillon(area->shapes, shape);
    }
    area->nb_shape++;
}

void clear_area(Area* area) {
    // Reset la matrice avec des 0
    for (int i = 0; i < area->width; ++i) {
        for (int j = 0; j < area->height; ++j) {
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area) {
    // Reset la matrice avec des 0
     clear_area(area);
    // Reset le tableau des formes
    freeList(area->shapes);
    area->nb_shape = 0;
    area->shapes = malloc(sizeof(Maillon*));
}

void delete_area(Area* area) {
    erase_area(area);
    for (int i = 0; i < area->width; ++i) {
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);

}

void draw_area(Area* area) {
    Pixel** pixels = malloc(sizeof(Pixel*));
    int nb_pixels = 0;
    for (int i = 0; i < area->nb_shape; i++) {
        Shape* shape = getMaillonByIndex(area->shapes, i)->shape;
        drawShape(shape, pixels, &nb_pixels);
    }
    for (int i = 0; i < nb_pixels; ++i) {
        Pixel* pixel = pixels[i];
        area->mat[pixel->x][pixel->y] = 1;
    }
}


void print_area(Area* area) {
    for (int i = 0; i < area->width; i++) {
        for (int j = 0; j < area->height; j++) {
            if (area->mat[i][j] == 0) {
                printf(" ");
                continue;
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}