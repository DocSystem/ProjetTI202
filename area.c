//
// Created by Valentin on 14/04/2023.
//

#include <stdlib.h>
#include <stdio.h>

#include "geometry.h"
#include "area.h"
#include "double_chained_list.h"
#include "layer.h"

Area* create_area(unsigned int width, unsigned int height) {
    Area* area = malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = malloc(sizeof(BOOL*) * width);
    for (int i = 0; i < width; ++i) {
        area->mat[i] = malloc(sizeof(BOOL) * height);
    }
    area->list_layers = create_layer_list();
    Layer* new_layer = create_layer("default");
    lst_insert_head(area->list_layers, lst_create_node(new_layer));
    area->id_layer = 0;
    return area;
}



void add_shape_to_area(Area* area, Shape* shape) {
    Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
    if (current_layer == NULL) {
        printf("Error: Layer not found");
        return;
    }
    add_shape_to_layer(current_layer, shape);
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
    Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);

    lst_delete_list(current_layer->shapes);
    current_layer->shapes = NULL;
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
    List* pixels = lst_create_list();
    lnode* node = get_first_node(area->list_layers);
    Layer* layer = node->data;
    while (layer != NULL) {
        if (layer->visible == VISIBLE) {
            lnode *node_shape = get_first_node(layer->shapes);
            Shape *shape = node_shape->data;
            while (shape != NULL) {
                drawShape(shape, pixels);
                node_shape = get_next_node(node_shape);
                shape = node_shape->data;
            }
            node = get_next_node(node);
            layer = node->data;
        }
    }
    lnode* node_pixel = get_first_node(pixels);
    Pixel* pixel = node_pixel->data;
    while (pixel != NULL) {
        area->mat[pixel->x][pixel->y] = 1;
        node_pixel = get_next_node(node_pixel);
        pixel = node_pixel->data;
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