//
// Created by antoine7805 on 15/03/2023.
//

#include <stdio.h>
#include <time.h>
#include "utils.h"

void sleep(int seconds) {
    clock_t end;
    end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) {}
}

void clearScreen() {
    printf("\033[2J");
    printf("\033[0;0H");
}

void printAtCoos(int x, int y, char *str) {
    printf("\033[%d;%dH%s", y, x, str);
}

win_size getWindowSize() {
    win_size size;
    size.width = 80;
    size.height = 24;
    return size;
}

void showWindowBox() {
    win_size size = getWindowSize();
    for (int i = 0; i < size.width; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < size.height - 2; i++) {
        printf("|");
        for (int j = 0; j < size.width - 2; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    for (int i = 0; i < size.width; i++) {
        printf("-");
    }
    printf("\n");
}
