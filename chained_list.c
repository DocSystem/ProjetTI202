//
// Created by Valentin on 28/03/2023.
//

#include "chained_list.h"
#include <stdio.h>
#include <stdlib.h>

#include "geometry.h"

Maillon* createMaillon(Shape* shape) {
    Maillon* maillon = malloc(sizeof(Maillon));
    maillon->shape = shape;
    maillon->next = NULL;
    return maillon;
}

void freeMaillon(Maillon* maillon) {
    free(maillon);
}

void printMaillon(Maillon* maillon) {
    printf("Maillon : ");
    printShape(maillon->shape);
}

Maillon* addMaillon(Maillon* head, Shape* shape) {
    if (head == NULL) {
        return createMaillon(shape);
    }
    head->next = addMaillon(head->next, shape);
    return head;
}

void freeList(Maillon* head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    freeMaillon(head);
}

void printList(Maillon* head) {
    if (head == NULL) {
        return;
    }
    printMaillon(head);
    printList(head->next);
}

Maillon* removeMaillonById(Maillon* head, int id) {
    if (head == NULL) {
        return NULL;
    }
    if (head->shape->id == id) {
        Maillon* next = head->next;
        freeMaillon(head);
        return next;
    }
    head->next = removeMaillonById(head->next, id);
    return head;
}

Maillon* removeMaillonByIndex(Maillon* head, int index) {
    if (head == NULL) {
        return NULL;
    }
    if (index == 0) {
        Maillon* next = head->next;
        freeMaillon(head);
        return next;
    }
    head->next = removeMaillonByIndex(head->next, index - 1);
    return head;
}

Maillon* getMaillonByIndex(Maillon* head, int index) {
    if (head == NULL) {
        return NULL;
    }
    if (index == 0) {
        return head;
    }
    return getMaillonByIndex(head->next, index - 1);
}

Maillon* getMaillonById(Maillon* head, int id) {
    if (head == NULL) {
        return NULL;
    }
    if (head->shape->id == id) {
        return head;
    }
    return getMaillonById(head->next, id);
}

int getMaillonIndexById(Maillon* head, int id) {
    if (head == NULL) {
        return -1;
    }
    if (head->shape->id == id) {
        return 0;
    }
    int index = getMaillonIndexById(head->next, id);
    if (index == -1) {
        return -1;
    }
    return 1 + index;
}

int getMaillonCount(Maillon* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + getMaillonCount(head->next);
}

Maillon* insertMaillon(Maillon* head, Shape* shape, int index) {
    if (head == NULL) {
        return NULL;
    }
    if (index == 0) {
        Maillon* newMaillon = createMaillon(shape);
        newMaillon->next = head;
        return newMaillon;
    }
    head->next = insertMaillon(head->next, shape, index - 1);
    return head;
}

int length(Maillon* head) {
    return getMaillonCount(head);
}
