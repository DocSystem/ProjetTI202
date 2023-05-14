//
// Created by Valentin on 14/05/2023.
//

#ifndef PROJETTI202_LAYER_H
#define PROJETTI202_LAYER_H

#include "double_chained_list.h"
#include "geometry.h"


#define VISIBLE 0
#define INVISIBLE 1

typedef struct {
    unsigned int id;
    char name[255];
    unsigned int visible;
    List* shapes;
} Layer;

Layer* create_layer(char* name);
void delete_layer(Layer* layer);
List* create_layer_list();
void delete_layer_list(List* layer_list);
void add_layer_to_list(List* layer_list, Layer* layer);
void remove_layer_from_list(List* layer_list, Layer* layer);
void set_layer_visible(Layer* layer);
void set_layer_invisible(Layer* layer);
void add_shape_to_layer(Layer* layer, Shape* shape);
void remove_shape_to_layer(Layer* layer, Shape* shape);

#endif //PROJETTI202_LAYER_H

//TODO Sublayers
