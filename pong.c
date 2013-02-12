#include <ncurses.h>

#include "game.h"

int main(void)
{
    initscr();
    curs_set(0);

    game_loop();

    endwin();
    return 0;
}

