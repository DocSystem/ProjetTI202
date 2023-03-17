//
// Created by antoine7805 on 15/03/2023.
//

#include "algorithm.h"
#include "utils.h"
#include "geometry.h"


void traceLine(Line* line){
    /* Cet algorithme est inspiré de celui présenté dans le cours de TI202
     * Il vient de cette page : "https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham"
     * Il a été adapté pour fonctionner avec les coordonnées de la structure Line
     * et pour fonctionner avec la fonction printAtCoos() de utils.c
     */
    // Déclaration des variables
    int dx, dy;
    int x1, y1;
    int x2, y2;

    // Affectation des variables à partir de la structure line
    x1 = line -> p1 -> x;
    x2 = line -> p2 -> x;
    y1 = line -> p1 -> y;
    y2 = line -> p2 -> y;

    // Calcul de dx et dy
    dx = x2 - x1;
    dy = y2 - y1;

    if (dx != 0) {
        if (dx > 0) {
            if (dy != 0) {
                if (dy > 0) {
                    // Vecteur oblique dans le 1er cadran
                    if (dx >= dy) {
                        // Vecteur diagonale ou oblique proche de l'horizontale, dans le 1er octant
                        int e;
                        e = dx; // e est positif
                        dx = e * 2;
                        dy = dy * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e - dy;
                            if (e < 0) {
                                y1++; // Déplacement diagonal
                                e = e + dx;
                            }
                            x1++; // Déplacement horizontal
                        } while (x1 != x2);

                    } else {
                        // Vecteur oblique proche de la verticale, dans le 2nd octant
                        int e;
                        e = dy; // e est positif
                        dy = e * 2;
                        dx = dx * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e - dx;
                            if (e < 0) {
                                x1++; // Déplacement diagonal
                                e = e + dy;
                            }
                            y1++; // Déplacement vertical
                        } while (y1 != y2);
                    }

                } else {
                    // Vecteur oblique dans le 4ème cadran
                    if (dx >= -dy) {
                        // Vecteur diagonale ou oblique proche de l'horizontale, dans le 8ème octant
                        int e;
                        e = dx; // e est positif
                        dx = e * 2;
                        dy = dy * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e + dy;
                            if (e < 0) {
                                y1--;
                                e = e + dx;
                            }
                            x1++;
                        } while (x1 != x2);

                    } else {
                        // Vecteur oblique proche de la verticale, dans le 7ème octant
                        int e;
                        e = dy; // e est négatif
                        dy = e * 2;
                        dx = dx * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e + dx;
                            if (e > 0) {
                                x1++;
                                e = e + dy;
                            }
                            y1--;
                        } while (y1 != y2);
                    }
                }
            } else {
                // Vecteur horizontal vers la droite
                do {
                    printAtCoos(x1, y1, "-");
                    x1++;
                } while (x1 != x2);
            }
        } else {
            // dx < 0
            dy = y1 - y2;
            if (dy != 0) {
                if (dy > 0) {
                    // Vecteur oblique dans le 2nd cadran
                    if (-dx >= dy) {
                        // Vecteur diagonale ou oblique proche de l'horizontale, dans le 4ème octant
                        int e;
                        e = dx; // e est négatif
                        dx = e * 2;
                        dy = dy * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e + dy;
                            if (e >= 0) {
                                y1++; // Déplacement diagonal
                                e = e + dx;
                            }
                            x1--; // Déplacement horizontal
                        } while (x1 != x2);

                    } else {
                        // Vecteur oblique proche de la verticale, dans le 3ème octant
                        int e;
                        e = dy; // e est positif
                        dy = e * 2;
                        dx = dx * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e + dx;
                            if (e <= 0) {
                                x1--;
                                e = e + dy;
                            }
                            y1++;
                        } while (y1 != y2);
                    }

                } else {
                    // Vecteur oblique dans le 3ème cadran
                    if (dx <= dy) {
                        // Vecteur diagonale ou oblique proche de l'horizontale, dans le 5ème octant
                        int e;
                        e = dx; // e est négatif
                        dx = e * 2;
                        dy = dy * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e - dy;
                            if (e >= 0) {
                                y1--; // Déplacement diagonal
                                e = e + dx;
                            }
                            x1--; // Déplacement horizontal
                        } while (x1 != x2);

                    } else {
                        // Vecteur oblique proche de la verticale, dans le 6ème octant
                        int e;
                        e = dy; // e est négatif
                        dy = e * 2;
                        dx = dx * 2;
                        do {
                            printAtCoos(x1, y1, "-");
                            e = e - dx;
                            if (e >= 0) {
                                x1--;
                                e = e + dy; // Déplacement diagonal
                            }
                            y1--;
                        } while (y1 != y2);
                    }
                }
            } else {
                // dy = 0 et dx < 0
                // Vecteur horizontal vers la gauche
                do {
                    printAtCoos(x1, y1, "-");
                    x1--;
                } while (x1 != x2);
            }
        }
    } else {
        // dx = 0
        dy = y2 - y1;
        if (dy != 0) {
            if (dy > 0) {
                // Vecteur vertical croissant
                do {
                    printAtCoos(x1, y1, "-");
                    y1++;
                } while (y1 != y2);
            } else {
                // Vecteur vertical décroissant
                do {
                    printAtCoos(x1, y1, "-");
                    y1--;
                } while (y1 != y2);
            }
        }
    }
    // Le pixel final (x2, y2) n'est pas tracé
}

void traceCircle(Circle* circle) {
    /* Cet algorithme est inspiré de celui présenté dans le cours de TI202
     * Il vient de cette page : "https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_cercle_d%27Andres"
     * Il a été adapté pour fonctionner avec les coordonnées de la structure Circle
     * et pour fonctionner avec la fonction printAtCoos() de utils.c
     */
    int x_center = circle -> center -> x;
    int y_center = circle -> center -> y;
    int r = circle -> radius;
    int x, y, d;
    x = 0;
    y = r;
    d = r - 1;
    while(y >= x) {

        // Tracé d'un pixel par octants
        printAtCoos(x_center + x, y_center + y, "-");
        printAtCoos(x_center + y, y_center + x, "-");
        printAtCoos(x_center - x, y_center + y, "-");
        printAtCoos(x_center - y, y_center + x, "-");
        printAtCoos(x_center + x, y_center - y, "-");
        printAtCoos(x_center + y, y_center - x, "-");
        printAtCoos(x_center - x, y_center - y, "-");
        printAtCoos(x_center - y, y_center - x, "-");

        if (d >= 2 * x) {
            d -= 2 * x++ - 1;
        } else if (d < 2 * (r - y)) {
            d += 2 * y-- - 1;
        } else {
            d += (y-- - x-- - 1);
        }
    }
}
