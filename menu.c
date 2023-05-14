//
// Created by Valentin on 28/03/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "geometry.h"
#include "chained_list.h"


int ActionChoice(Area* area) {

    Maillon **head = &(area->shapes);

    printf("Veuillez choisir une action : \n");
    printf("A- Ajouter une forme \n");
    printf("B- Afficher la liste des formes \n");
    printf("C- Supprimer une forme \n");
    printf("D- Tracer le dessin \n");
    printf("E- Aide \n");
    printf("F- Quitter \n");
    char choice;
    scanf(" %c", &choice);
    switch (choice) {
        case 'A': {

            printf("Vous avez choisi d'ajouter une forme \n");
            Shape *shape = ShapeChoice();
            *head = addMaillon(*head, shape);
            return 0;
        }
        case 'a' :{
            return 0;
        }
        case 'B': {
            printf("Vous avez choisi d'afficher la liste des formes \n");
            printList(*head);
            return 1;
        }
        case 'C': {
            printf("Vous avez choisi de supprimer une forme \n");
            printList(*head);
            printf("Veuillez entrer l'id de la forme à supprimer : \n");
            int id;
            scanf(" %d", &id);
            *head = removeMaillonById(*head, id);

            return 2;
        }
        case 'D': {
            printf("Vous avez choisi de tracer le dessin \n");
            return 3;
        }
        case 'E': {
            printf("Vous avez choisi d'afficher l'aide \n");
            return 4;
        }
        case 'F': {
            printf("Vous avez choisi de quitter \n");
            return -99;
        }
        default: {
            printf("Vous n'avez pas choisi une action valide \n");
            return -1;
        }

    }
}

Shape* ShapeChoice() {
    printf("Veuillez choisir une forme : \n");
    printf("1- Point \n");
    printf("2- Ligne \n");
    printf("3- Cercle \n");
    printf("4- Rectangle \n");
    printf("5- Carre \n");
    printf("6- Polygone \n");
    printf("7- Revenir au menu précédent \n");
    int choice;
    scanf(" %d", &choice);
    switch (choice) {
        case 1: {
            printf("Vous avez choisi de créer un point \n");
            int x, y;
            printf("Veuillez entrer les coordonnées du point : \n");
            printf("x : ");
            scanf(" %d", &x);
            printf("y : ");
            scanf(" %d", &y);
            Shape* point = createPointShape(x, y);
            printf("Le point a été créé avec les coordonnées (%d, %d) \n", x, y);
            return point;
        }

        case 2: {
            printf("Vous avez choisi de créer une ligne \n");
            printf("Veuillez entrer les coordonnées du point de départ : \n");
            int x1, y1;
            printf("x : ");
            scanf(" %d", &x1);
            printf("y : ");
            scanf(" %d", &y1);
            printf("Veuillez entrer les coordonnées du point d'arrivée : \n");
            int x2, y2;
            printf("x : ");
            scanf(" %d", &x2);
            printf("y : ");
            scanf(" %d", &y2);
            Shape* line = createLineShape(createPoint(x1, y1), createPoint(x2, y2));
            printf("La ligne a été créée avec les coordonnées (%d, %d) et (%d, %d) \n", x1, y1, x2, y2);
            return line;
        }

        case 3: {
            printf("Vous avez choisi de créer un cercle \n");
            printf("Veuillez entrer les coordonnées du centre du cercle : \n");
            int x, y;
            printf("x : ");
            scanf(" %d", &x);
            printf("y : ");
            scanf(" %d", &y);
            printf("Veuillez entrer le rayon du cercle : \n");
            int r;
            printf("r : ");
            scanf(" %d", &r);
            Shape* circle = createCircleShape(createPoint(x, y), r);
            printf("Le cercle a été créé avec les coordonnées (%d, %d) et un rayon de %d \n", x, y, r);
            return circle;
        }
        case 4: {
            printf("Vous avez choisi de créer un rectangle \n");
            printf("Veuillez entrer les coordonnées du coint supérieur gauche : \n");
            int x1, y1;
            printf("x : ");
            scanf(" %d", &x1);
            printf("y : ");
            scanf(" %d", &y1);
            printf("Veuillez entrer la largeur (horizontale) du rectangle : \n");
            int w;
            printf("w : ");
            scanf(" %d", &w);
            printf("Veuillez entrer la hauteur (verticale) du rectangle : \n");
            int h;
            printf("h : ");
            scanf(" %d", &h);
            Shape* rectangle = createRectangleShape(createPoint(x1, y1), w, h);
            return rectangle;
        }
        case 5: {
            printf("Vous avez choisi de créer un carré \n");
            printf("Veuillez entrer les coordonnées du coint supérieur gauche : \n");
            int x1, y1;
            printf("x : ");
            scanf(" %d", &x1);
            printf("y : ");
            scanf(" %d", &y1);
            printf("Veuillez entrer la longueur d'un côté : \n");
            int w;
            printf("w : ");
            scanf(" %d", &w);
            Shape* square = createSquareShape(createPoint(x1, y1), w);
            return square;
        }

        case 6: {
            printf("Vous avez choisi de créer un polygone \n");
            int nbPoints;
            printf("Veuillez entrer le nombre de points du polygone : \n");
            scanf(" %d", &nbPoints);
            Point **points = malloc(sizeof(Point) * nbPoints);
            for (int i = 0; i < nbPoints; i++) {
                printf("Veuillez entrer les coordonnées du point %d : \n", i + 1);
                int x, y;
                printf("x : ");
                scanf(" %d", &x);
                printf("y : ");
                scanf(" %d", &y);
                points[i] = createPoint(x, y);
            }
            Shape *polygon = createPolygonShape(points, nbPoints);
            return polygon;
        }
        case 7:
            printf("Vous avez choisi de revenir au menu précédent \n");
            return NULL;

        default: {
            printf("Vous n'avez pas choisi une forme valide \n");
            return ShapeChoice();
        }
    }
}
