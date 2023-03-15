//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_UTILS_H
#define PROJETTI202_UTILS_H

void sleep(int seconds);
void clearScreen();

typedef struct {
    int width;
    int height;
} win_size;

void print_at_coos(int x, int y, char *str);
win_size getWindowSize();
void showWindowBox();

#endif //PROJETTI202_UTILS_H
