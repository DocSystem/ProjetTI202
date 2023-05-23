//
// Created by antoine7805 on 15/03/2023.
//

#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#if __linux__ || __APPLE__

#include <sys/ioctl.h>
#include <stdlib.h>

#elif _WIN32

#include <windows.h>

#else

#error "OS not supported"

#endif

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

char* selectedText(char* text) {
    char* selected = malloc(sizeof(char) * (strlen(text) + 10));
    sprintf(selected, "\033[7m%s\033[0m", text);
    return selected;
}

#if __linux__ || __APPLE__
win_size getWindowSize() {
    win_size size;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    size.width = w.ws_col;
    size.height = w.ws_row;
    return size;
}
#elif _WIN32
win_size getWindowSize() {
    win_size size;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    size.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return size;
}
#else
win_size getWindowSize() {
    win_size size;
    size.width = 0;
    size.height = 0;
    return size;
}
#endif

void showWindowBox() {
    win_size size = getWindowSize();
    clearScreen();
    for (int i = 1; i <= size.width; i++) {
        printAtCoos(i, 1, "-");
    }
    for (int i = 1; i <= size.height - 3; i++) {
        printAtCoos(1, i + 1, "|");
        printAtCoos(size.width, i + 1, "|");
    }
    for (int i = 1; i <= size.width; i++) {
        printAtCoos(i, size.height - 1, "-");
    }
    printAtCoos(1, size.height, ">>> ");
}

void printHelp() {
    // HEEEEEEEEEEEEEEEEELP ME
    win_size size = getWindowSize();
    printAtCoos(0, 0, "");
    for (int i = 0; i < size.width / 2 - 11; i++) {
        printf("=");
    }
    printf(" Liste des commandes ");
    for (int i = 0; i < size.width / 2 - 11; i++) {
        printf("=");
    }
    printf("\nCommandes de base :\n");
    printf("\thelp : Affiche la liste des commandes\n");
    printf("\texit : Quitte le programme\n");
    printf("\tclear : Efface l'écran\n");
    printf("\tplot : Affiche l'image\n");
    printf("Formes :\n");
    printf("\tpoint <y> <y> : Ajoute un point\n");
    printf("\tline <x1> <y1> <x2> <y2> : Ajoute une ligne\n");
    printf("\tcircle <x> <y> <radius> : Ajoute un cercle\n");
    printf("\tsquare <x> <y> <size> : Ajoute un carré\n");
    printf("\trectangle <x> <y> <width> <height> : Ajoute un rectangle\n");
    printf("\tpolygon <x1> <y1> <x2> <y2> ... <xn> <yn> : Ajoute un polygone\n");
    printf("Calques :\n");
    printf("\tlist layer : Liste les calques\n");
    printf("\tnew layer <name> : Ajoute un calque de nom <name>\n");
    printf("\tlayer <id> : Sélectionne le calque <id>\n");
    printf("\tdelete layer <id> : Supprime le calque <id>\n");
    printf("\tset layer visible <id> : Rend le calque <id> visible\n");
    printf("\tset layer hide <id> : Rend le calque <id> invisible\n");
}

char* waitForCommand() {
    char* command = malloc(sizeof(char) * 100);
    printAtCoos(1, getWindowSize().height, ">>> ");
    fgets(command, 100, stdin);
    return command;
}

int parseInt(char* str) {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

Command parseCommand(char* cmd) {
    Command command;
    command.command = malloc(sizeof(char) * 100);
    command.args = malloc(sizeof(char*));
    int arg_count = 0;
    int cmd_length = 0;
    while (cmd[cmd_length] != ' ' && cmd[cmd_length] != '\0' && cmd[cmd_length] != '\n') {
        command.command[cmd_length] = cmd[cmd_length];
        cmd_length++;
    }
    command.command[cmd_length] = '\0';
    if (cmd[cmd_length] == '\0' || cmd[cmd_length] == '\n') {
        command.arg_count = 0;
        return command;
    }
    for (int i = 0; i < strlen(cmd); i++) {
        if (cmd[i] == ' ') {
            arg_count++;
        }
    }
    command.arg_count = arg_count;
    for (int i = 0; i < arg_count; i++) {
        char* arg = malloc(sizeof(char) * 100);
        int space_count = 0;
        int arg_length = 0;
        for (int j = 0; j < strlen(cmd); j++) {
            if (cmd[j] == ' ' || cmd[j] == '\n') {
                space_count++;
            }
            if (space_count == i + 1 && cmd[j] != ' ') {
                arg[arg_length] = cmd[j];
                arg_length++;
            }
        }
        arg[arg_length] = '\0';
        command.args[i] = arg;
    }
    return command;
}

void showPopup(char* message) {
    win_size size = getWindowSize();
    int width = strlen(message) + 9;
    int height = 4;
    int x = (size.width - width) / 2;
    int y = (size.height - height) / 2;
    for (int i = 0; i <= width; i++) {
        printAtCoos(x + i, y, "-");
        printAtCoos(x + i, y + height, "-");
    }
    for (int i = 1; i < height; i++) {
        printAtCoos(x, y + i, "|");
        printAtCoos(x + width, y + i, "|");
    }
    printAtCoos((int)(size.width / 2) - (int)(strlen(message) / 2), y + 2, message);
}
