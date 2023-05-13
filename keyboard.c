//
// Created by Antoine Souben-Fink on 14/04/2023.
//

#include <stdlib.h>
#include "keyboard.h"

#if __linux__ || __APPLE__

#include <curses.h>

char* waitForKey() {
    int ch;

    /* Curses Initialisations */
    initscr();                  /* curses initialization */
    keypad(stdscr, TRUE);       /* enable KEY_UP/KEY_DOWN/KEY_RIGHT/KEY_LEFT */
    noecho();                   /* prevent displaying if other keys */

    while (1) {
        ch = getch();
        // printf("%d\r\n", ch);
        if (ch == KEY_UP) {
            return "up";
        } else if (ch == KEY_DOWN) {
            return "down";
        } else if (ch == KEY_LEFT) {
            return "left";
        } else if (ch == KEY_RIGHT) {
            return "right";
        } else if (ch >= 97 && ch <= 122) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch >= 65 && ch <= 90) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch >= 48 && ch <= 57) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch == 32) {
            return "space";
        } else if (ch == 9) {
            return "tab";
        } else if (ch == 127) {
            return "backspace";
        } else if (ch == 10) {
            return "enter";
        } else if (ch == 27) {
            return "escape";
        }
    }
    return "ERROR";
}

#elif _WIN32

#include <conio.h>

char* waitForKey() {
    int ch;

    while (1) {
        ch = getch();
        // printf("%d\r\n", ch);
        if (ch == 72) {
            return "up";
        } else if (ch == 80) {
            return "down";
        } else if (ch == 75) {
            return "left";
        } else if (ch == 77) {
            return "right";
        } else if (ch >= 97 && ch <= 122) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch >= 65 && ch <= 90) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch >= 48 && ch <= 57) {
            char* str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = '\0';
            return str;
        } else if (ch == 32) {
            return "space";
        } else if (ch == 9) {
            return "tab";
        } else if (ch == 8) {
            return "backspace";
        } else if (ch == 13) {
            return "enter";
        } else if (ch == 27) {
            return "escape";
        }
    }

    return 0;
}

#else

#error "Unsupported platform"

#endif