#include <ncurses.h>
#include <stdlib.h>

int main() {
    initscr();
    cbreak();
    noecho();
    clear();

    endwin();

    return 0;
}