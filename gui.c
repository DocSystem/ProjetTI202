//
// Created by Antoine Souben-Fink on 12/05/2023.
//

#include <stdio.h>
#include "gui.h"
#include "geometry.h"
#include "keyboard.h"
#include "utils.h"

void runEditor() {
    char* k = waitForKey();
    printf("%s\n", k);
}
