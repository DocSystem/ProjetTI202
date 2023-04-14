//
// Created by Antoine Souben-Fink on 14/04/2023.
//

#if __linux__ || __APPLE__

#include <curses.h>
#include "keyboard.h"

int waitForKey() {
    int ch;

    /* Curses Initialisations */
    initscr();                  /* curses initialization */
    keypad(stdscr, TRUE);       /* enable KEY_UP/KEY_DOWN/KEY_RIGHT/KEY_LEFT */
    noecho();                   /* prevent displaying if other keys */

    while ((ch = getch()) != KEY_ENTER) {
        if (ch == KEY_UP) {
            return 1;
        } else if (ch == KEY_DOWN) {
            return 2;
        } else if (ch == KEY_LEFT) {
            return 3;
        } else if (ch == KEY_RIGHT) {
            return 4;
        }
    }

    return 0;
}

#elif _WIN32

#include <conio.h>
#include "keyboard.h"

int waitForKey() {
    int ch;

    while ((ch = getch()) != 13) {
        if (ch == 72) {
            return 1;
        } else if (ch == 80) {
            return 2;
        } else if (ch == 75) {
            return 3;
        } else if (ch == 77) {
            return 4;
        }
    }

    return 0;
}

#endif