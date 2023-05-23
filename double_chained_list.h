// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Ce fichier contient les fonctions de gestion d'une liste doublement chaînée

#ifndef PROJETTI202_DOUBLE_CHAINED_LIST_H
#define PROJETTI202_DOUBLE_CHAINED_LIST_H

#include <stdlib.h>

typedef struct lnode_ {
    void *data;
    struct lnode_ *prev;
    struct lnode_ *next;
} lnode;

typedef struct list_ {
    lnode *head;
    lnode *tail;
} List;


lnode* lst_create_node(void *data);
List* lst_create_list();
void lst_delete_list(List *list);
void lst_insert_head(List *list, lnode* pnew);
void lst_insert_tail(List *list, lnode* pnew);
void lst_insert_after(List *list, lnode *pnew, lnode *ptr);
void lst_delete_head(List *list);
void lst_delete_tail(List *list);
void lst_delete_node(List *list, lnode *ptr);
lnode* get_first_node(List *list);
lnode* get_last_node(List *list);
lnode* get_next_node(lnode *node);
void* get_previous_elem(List *list);

lnode* get_node_by_index(List *list, int index);

void* get_data(lnode* node);

#endif //PROJETTI202_DOUBLE_CHAINED_LIST_H
