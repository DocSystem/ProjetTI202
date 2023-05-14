//
// Created by Valentin on 20/04/2023.
//

#include "id.h"

unsigned int get_next_id() {
    static unsigned int id = 0;
    return id++;
}

unsigned int get_next_layer_id() {
    static unsigned int id = 0;
    return id++;
}
