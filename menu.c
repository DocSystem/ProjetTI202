//
// Created by Valentin on 28/03/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "geometry.h"
#include "double_chained_list.h"
#include "layer.h"
#include "utils.h"


int ActionChoice(Area* area) {
    clearScreen();
    printf("\n");
    printf("Menu principal : \n");
    printf("Veuillez choisir une action : \n");
    printf("A- Ajouter une forme \n");
    printf("a- Ajouter un calque \n");
    printf("B- Afficher la liste des formes \n");
    printf("b- Afficher la liste des calques \n");
    printf("C- Supprimer une forme \n");
    printf("c- Supprimer un calque \n");
    printf("D- Tracer le dessin \n");
    printf("d- Changer de calque \n");
    printf("E- Afficher la calque actif \n");
    printf("e- Cacher le calque actif \n");

    printf("F- Aide \n");
    printf("G- Quitter \n");
    char choice;
    scanf(" %c", &choice);
    clearScreen();A
    switch (choice) {
        case 'A': {

            printf("Vous avez choisi d'ajouter une forme \n");
            Shape *shape = ShapeChoice();
            add_shape_to_area(area, shape);
            return 1;
        }
        case 'a' :{
            printf("Vous avez choisi d'ajouter un calque \n");
            printf("Veuillez entrer le nom du calque : \n");
            char name[20];
            scanf(" %s", name);
            Layer* layer = create_layer(name);
            add_layer_to_list(area->list_layers, layer);
            area->id_layer = ((Layer*) get_last_node(area->list_layers))->id;
            return -1;
        }
        case 'B': {
            printf("Vous avez choisi d'afficher la liste des formes \n");
            Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
            lnode *node = get_first_node(current_layer->shapes);
            while (node != NULL) {
                Shape* shape = (Shape*) node->data;
                printShape(shape);
                node = get_next_node(node);
            }
            return 2;
        }
        case 'b' :{
            printf("Vous avez choisi d'afficher la liste des calques \n");
            lnode* node = get_first_node(area->list_layers);
            while (node != NULL) {
                Layer* layer = (Layer*) node->data;
                print_layer(layer);
                node = get_next_node(node);
            }
            return 1;
        }
        case 'C': {
            printf("Vous avez choisi de supprimer une forme \n");
            Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
            // Affichage des formes du calque actif
            printf("Formes du calque actif : \n");
            lnode* node = get_first_node(current_layer->shapes);
            while (node != NULL) {
                Shape* shape = (Shape*) node->data;
                printShape(shape);
                node = get_next_node(node);
            }
            printf("Veuillez entrer l'id de la forme à supprimer : \n");
            int id;
            scanf(" %d", &id);
            lnode* node_shape = get_first_node(current_layer->shapes);
            while (node_shape != NULL) {
                Shape* shape = (Shape*) node_shape->data;
                if (shape->id == id) {
                    lst_delete_node(current_layer->shapes, node_shape);
                    return 2;
                }
                node_shape = get_next_node(node_shape);
            }
            printf("La forme n'a pas été trouvée \n");
            return 29;
        }
        case 'c':
        {
            printf("Vous avez choisi de supprimer un calque \n");
            printf("Veuillez entrer l'id du calque à supprimer : \n");
            int id;
            scanf(" %d", &id);
            Layer* layer = access_layer_by_id(area->list_layers, id);
            if (layer != NULL) {
                remove_layer_from_list(area->list_layers, layer);
                return -2;
            }
            printf("Le calque n'a pas été trouvé \n");
            return -29;
        }
        case 'D': {
            printf("Vous avez choisi de tracer le dessin \n");
            draw_area(area);
            print_area(area);
            return 3;
        }
        case 'd': {
            printf("Vous avez choisi de changer de calque \n");
            printf("Veuillez entrer l'id du calque : \n");
            int id;
            scanf(" %d", &id);
            Layer* layer = access_layer_by_id(area->list_layers, id);
            if (layer != NULL) {
                area->id_layer = id;
                return -3;
            }
            printf("Le calque n'a pas été trouvé \n");
            return -39;
        }
        case 'E': {
            printf("Vous avez choisi d'afficher le calque actif \n");
            Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
            set_layer_visible(current_layer);

            return 4;
        }
        case 'e': {
            printf("Vous avez choisi de cacher le calque actif \n");
            Layer* current_layer = access_layer_by_id(area->list_layers, area->id_layer);
            set_layer_invisible(current_layer);
            return -4;
        }
        case 'F': {
            printf("Vous avez choisi d'afficher l'aide \n");
            return 5;
        }
        case 'G': {
            printf("Vous avez choisi de quitter \n");
            return -99;
        }
        default: {
            printf("Vous n'avez pas choisi une action valide \n");
            return -98;
        }

    }
}

Shape* ShapeChoice() {
    clearScreen();
    printf("Veuillez choisir une forme : \n");
    printf("1- Point \n");
    printf("2- Ligne \n");
    printf("3- Cercle \n");
    printf("4- Rectangle \n");
    printf("5- Carre \n");
    printf("6- Polygone \n");
    printf("7- Courbe \n");
    printf("8- Revenir au menu précédent \n");
    int choice;
    scanf(" %d", &choice);
    clearScreen();
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

        case 7: {
            printf("Vous avez choisi de créer une courbe de Bézier \n");
            printf("Veuillez entrer les coordonnées du point de départ : \n");
            int x1, y1;
            printf("x : ");
            scanf("%d", &x1);
            printf("y : ");
            scanf("%d", &y1);
            Point* p1 = createPoint(x1, y1);
            printf("Veuillez entrer les coordonnées du point d'arrivée : \n");
            int x2, y2;
            printf("x : ");
            scanf("%d", &x2);
            printf("y : ");
            scanf("%d", &y2);
            Point* p2 = createPoint(x2, y2);
            printf("Veuillez entrer les coordonnées du premier point de contrôle : \n");
            int x3, y3;
            printf("x : ");
            scanf("%d", &x3);
            printf("y : ");
            scanf("%d", &y3);
            Point* p3 = createPoint(x3, y3);
            printf("Veuillez entrer les coordonnées du second point de contrôle : \n");
            int x4, y4;
            printf("x : ");
            scanf("%d", &x4);
            printf("y : ");
            scanf("%d", &y4);
            Point* p4 = createPoint(x4, y4);
            Shape* bezier = createCurveShape(p1, p2, p3, p4);
            return bezier;
        }


        case 8 : {
            printf("Vous avez choisi de revenir au menu précédent \n");
            return NULL;
        }

        default: {
            printf("Vous n'avez pas choisi une forme valide \n");
            return ShapeChoice();
        }
    }
}
