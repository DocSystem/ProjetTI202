//
// Created by antoine7805 on 15/03/2023.
//

#include <stdio.h>
#include <time.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/ioctl.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#else
#error "OS not supported"
#endif
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

#if defined(__unix__) || defined(__APPLE__)
win_size getWindowSize() {
    win_size size;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    size.width = w.ws_col;
    size.height = w.ws_row;
    return size;
}
#elif defined(_WIN32) || defined(WIN32)
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

int main() {
    win_size size = getWindowSize();
    printf("Width: %d\nHeight: %d\n", size.width, size.height);
    return 0;
}
