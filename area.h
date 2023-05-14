//
// Created by Valentin on 14/05/2023.
//

#ifndef PROJETTI202_AREA_H
#define PROJETTI202_AREA_H

#include "geometry.h"
#include "double_chained_list.h"

#define BOOL int

typedef struct {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    List* list_layers; // Tableau des couches;
    unsigned id_layer; // Id de la couche courante
} Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

#endif //PROJETTI202_AREA_H

