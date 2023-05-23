//
// Created by Valentin on 14/05/2023.
//

#include <string.h>
#include <stdio.h>
#include "layer.h"
#include "id.h"
#include "utils.h"


Layer* create_layer(char* name) {
    /* Création d'un nouveau calque */
    Layer* layer = malloc(sizeof(Layer));
    layer->id = get_next_layer_id();
    strcpy(layer->name, name);
    layer->visible = VISIBLE;
    layer->shapes = lst_create_list();
    return layer;
}

void delete_layer(Layer* layer) {
    /* Suppression d'un calque */
    lst_delete_list(layer->shapes);
    free(layer);
}

List* create_layer_list() {
    /* Création d'une nouvelle liste de calques */
    List* lst = lst_create_list();
    return lst;
}

void delete_layer_list(List* layer_list) {
    /* Suppression d'une liste de calques */
    lst_delete_list(layer_list);
}

void add_layer_to_list(List* layer_list, Layer* layer) {
    /* Ajout d'un calque à une liste de calques */
    lst_insert_tail(layer_list, lst_create_node(layer));
}

void remove_layer_from_list(List* layer_list, Layer* layer) {
    /* Suppression d'un calque d'une liste de calques */
    lnode* node = layer_list->head;
    while (node != NULL)  {
        if (((Layer*) node->data)->id != layer->id) {
            node = node->next;
        }
        else {
            break;
        }
    } if (node != NULL) {
        lst_delete_node(layer_list, node);
    }
}

void set_layer_visible(Layer* layer) {
    /* Rendre un calque visible */
    layer->visible = VISIBLE;
}

void set_layer_invisible(Layer* layer) {
    /* Rendre un calque invisible */
    layer->visible = INVISIBLE;
}

void add_shape_to_layer(Layer* layer, Shape* shape) {
    /* Ajouter une forme à un calque */
    lst_insert_tail(layer->shapes, lst_create_node(shape));
}

void remove_shape_from_layer(Layer* layer, Shape* shape) {
    /* Supprimer une forme d'un calque */
    lnode* node = layer->shapes->head;
    while (node != NULL) {
        if (((Layer*) get_data(node))->id != shape->id) {
            node = node->next;
        }
        else {
            break;
        }
    } if (node != NULL) {
        lst_delete_node(layer->shapes, node);
    }
}

Layer* access_layer_by_id(List* layer_list, unsigned int id_layer) {
    /* Accéder à un calque par son id */
    lnode* node = get_first_node(layer_list);
    while (node != NULL) {
        Layer* layer = get_data(node);
        if (layer == NULL) {
            return NULL;
        }
        if (layer->id == id_layer) {
            return layer;
        }
        node = node->next;
    }
    return NULL;
}

void print_layer(Layer* layer) {
    /* Afficher un calque */
    printf("Layer %d: %s\t", layer->id, layer->name);
    printf("Visible: %s", layer->visible?"Non":"Oui");
    printf("\n");
}