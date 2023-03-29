//
// Created by Valentin on 28/03/2023.
//

#include <stdio.h>
#include "menu.h"
#include "geometry.h"


void ActionChoice() {
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
        case 'A':
            printf("Vous avez choisi d'ajouter une forme \n");
            ShapeChoice();
        case 'B':
            printf("Vous avez choisi d'afficher la liste des formes \n");
            break;
        case 'C':
            printf("Vous avez choisi de supprimer une forme \n");
            break;
        case 'D':
            printf("Vous avez choisi de tracer le dessin \n");
            break;
        case 'E':
            printf("Vous avez choisi d'afficher l'aide \n");
            break;
        case 'F':
            printf("Vous avez choisi de quitter \n");
            break;
        default:
            printf("Vous n'avez pas choisi une action valide \n");
            break;

    }
}

void ShapeChoice() {
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
            createPointShape(x, y);
            printf("Le point a été créé avec les coordonnées (%d, %d) \n", x, y);

        }
        case 2:
            printf("Vous avez choisi de créer une ligne \n");
            break;
        case 3:
            printf("Vous avez choisi de créer un cercle \n");
            break;
        case 4:
            printf("Vous avez choisi de créer un rectangle \n");
            break;
        case 5:
            printf("Vous avez choisi de créer un carré \n");
            break;
        case 6:
            printf("Vous avez choisi de créer un polygone \n");
            break;
        case 7:
            printf("Vous avez choisi de revenir au menu précédent \n");
            break;
        default:
            printf("Vous n'avez pas choisi une forme valide \n");
            break;
    }
}
