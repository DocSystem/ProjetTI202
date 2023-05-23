// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Ce fichier contient les fonctions utilitaires : affichage, commandes, etc.
#ifndef PROJETTI202_UTILS_H
#define PROJETTI202_UTILS_H

void clearScreen();

typedef struct{
    int width;
    int height;
} win_size;

void printAtCoos(int x, int y, char *str);
win_size getWindowSize();

void printHelp();

typedef struct {
    char* command;
    char** args;
    int arg_count;
} Command;

char* waitForCommand();
Command parseCommand(char* cmd);

int parseInt(char* str);

#endif //PROJETTI202_UTILS_H
