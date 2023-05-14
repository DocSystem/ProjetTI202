//
// Created by Valentin on 14/05/2023.
//

#include <string.h>
#include <stdio.h>
#include "layer.h"
#include "id.h"


Layer* create_layer(char* name) {
    Layer* layer = malloc(sizeof(Layer));
    layer->id = get_next_layer_id();
    strcpy(layer->name, name);
    layer->visible = VISIBLE;
    layer->shapes = lst_create_list();
    layer->shapes = NULL;
    return layer;
}

void delete_layer(Layer* layer) {
    lst_delete_list(layer->shapes);
    free(layer);
}

List* create_layer_list() {
    List* lst = lst_create_list();
    return lst;
}

void delete_layer_list(List* layer_list) {
    lst_delete_list(layer_list);
}

void add_layer_to_list(List* layer_list, Layer* layer) {
    lst_insert_tail(layer_list, lst_create_node(layer));
}

void remove_layer_from_list(List* layer_list, Layer* layer) {
    lnode* node = layer_list->head;
    while (node != NULL && ((Layer*) node->data)->id != layer) {
        node = node->next;
    } if (node != NULL) {
        lst_delete_node(layer_list, node);
    }
}

void set_layer_visible(Layer* layer) {
    layer->visible = VISIBLE;
}

void set_layer_invisible(Layer* layer) {
    layer->visible = INVISIBLE;
}

void add_shape_to_layer(Layer* layer, Shape* shape) {
    lst_insert_tail(layer->shapes, lst_create_node(shape));
}

void remove_shape_to_layer(Layer* layer, Shape* shape) {
    lnode* node = layer->shapes->head;
    while (node != NULL && ((Shape*) node->data)->id != shape) {
        node = node->next;
    } if (node != NULL) {
        lst_delete_node(layer->shapes, node);
    }
}

Layer* access_layer_by_id(List* layer_list, unsigned int id_layer) {
    lnode* node = get_first_node(layer_list);
    while (node != NULL) {
        Layer* layer = node->data;
        if (layer->id == id_layer) {
            return layer;
        }
        node = node->next;
    }
    return NULL;
}

void print_layer(Layer* layer) {
    printf("Layer %d: %s\t", layer->id, layer->name);
    printf("Visible: %d", layer->visible);
    printf("\n");
}