//
// Created by Valentin on 28/03/2023.
//

#ifndef PROJETTI202_CHAINED_LIST_H
#define PROJETTI202_CHAINED_LIST_H

#include "geometry.h"
#include "area.h"



struct Maillon {
    Shape* shape;
    struct Maillon* next;
};

typedef struct Maillon Maillon;

Maillon* createMaillon(Shape* shape);
void freeMaillon(Maillon* maillon);
void printMaillon(Maillon* maillon);

Maillon* addMaillon(Maillon* head, Shape* shape);
void freeList(Maillon* head);
void printList(Maillon* head);
Maillon* removeMaillonById(Maillon* head, int id);
Maillon* removeMaillonByIndex(Maillon* head, int index);
Maillon* getMaillonByIndex(Maillon* head, int index);
Maillon* getMaillonById(Maillon* head, int id);
int getMaillonIndexById(Maillon* head, int id);
int getMaillonCount(Maillon* head);
Maillon* insertMaillon(Maillon* head, Shape* shape, int index);
int length(Maillon* head);

#endif //PROJETTI202_CHAINED_LIST_H
