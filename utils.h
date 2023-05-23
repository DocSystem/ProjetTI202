//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_UTILS_H
#define PROJETTI202_UTILS_H

void sleep(int seconds);
void clearScreen();
char* selectedText(char* text);

typedef struct{
    int width;
    int height;
} win_size;

void printAtCoos(int x, int y, char *str);
win_size getWindowSize();
void showWindowBox();

typedef struct {
    char* command;
    char** args;
    int arg_count;
} Command;

char* waitForCommand();
Command parseCommand(char* cmd);

int parseInt(char* str);

void showPopup(char* message);

#endif //PROJETTI202_UTILS_H
