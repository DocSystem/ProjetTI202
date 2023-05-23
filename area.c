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
    /* Fonction qui crée une zone de dessin de taille width * height
     * en utilisant la structure Area
     * et qui renvoie un pointeur vers cette zone
     */
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
    /* Fonction qui ajoute une forme à la zone de dessin
     * en utilisant la structure Area
     */
    Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
    if (current_layer == NULL) {
        printf("Error: Layer not found");
        return;
    }
    add_shape_to_layer(current_layer, shape);
}

void clear_area(Area* area) {
    /* Fonction qui efface la zone de dessin
     * de la structure Area
     */
    // Reset la matrice avec des 0
    for (int i = 0; i < area->width; ++i) {
        for (int j = 0; j < area->height; ++j) {
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area) {
    /* Fonction qui supprime les formes
     * du calque actif de la zone de dessin
     * de la structure Area
     */
    // Reset la matrice avec des 0
     clear_area(area);
    // Reset le tableau des formes
    Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);

    lst_delete_list(current_layer->shapes);
    current_layer->shapes = NULL;
}

void delete_area(Area* area) {
    /* Fonction qui supprime la zone de dessin
     * de la structure Area
     */
    erase_area(area);
    for (int i = 0; i < area->width; ++i) {
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);

}

void draw_area(Area* area) {
    /* Fonction qui dessine la zone de dessin
     * de la structure Area
     */
    clear_area(area);
    List* pixels = lst_create_list();
    lnode* node = get_first_node(area->list_layers);
    Layer* layer = get_data(node);
    while (layer != NULL) {
        if (layer->visible == VISIBLE) {
            lnode *node_shape = get_first_node(layer->shapes);
            Shape *shape = get_data(node_shape);
            while (shape != NULL) {
                drawShape(shape, pixels);
                node_shape = get_next_node(node_shape);
                shape = get_data(node_shape);
            }
            node = get_next_node(node);
            layer = get_data(node);
        }
    }
    lnode* node_pixel = get_first_node(pixels);
    Pixel* pixel = get_data(node_pixel);
    int x, y;
    while (pixel != NULL) {
        x = pixel->x;
        y = pixel->y;
        (area->mat)[x][y] = 1;
        printf("x: %d, y: %d\n", x, y);
        node_pixel = get_next_node(node_pixel);
        pixel = get_data(node_pixel);
    }
}


void print_area(Area* area) {
    /* Fonction qui affiche la zone de dessin
     * de la structure Area
     */
    for (int i = 0; i < area->width; i++) {
        for (int j = 0; j < area->height; j++) {
            if (area->mat[i][j] == 1) {
                printf("X ");
                continue;
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}