// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Ce fichier contient les fonctions permettant de gérer les identifiants des formes et des calques

#include "id.h"

unsigned int get_next_id() {
    /* Renvoie un id unique à chaque appel */
    static unsigned int id = 0; // static permet de conserver la valeur de id entre chaque appel
    return id++; // id++ renvoie id puis incrémente id
}

unsigned int get_next_layer_id() {
    /* Renvoie un id unique à chaque appel */
    static unsigned int id = 0; // static permet de conserver la valeur de id entre chaque appel
    return id++; // id++ renvoie id puis incrémente id
}
