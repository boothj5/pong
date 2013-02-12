#include <unistd.h>
#include <ncurses.h>

#include "game.h"

#define BALL 'O'
#define LEFT 'A'
#define RIGHT 'B'

#define SLEEP_MS 20

void game_loop(void)
{
    int rows, cols;
    int ball_col = 0;
    char ball_dir = RIGHT;

    getmaxyx(stdscr, rows, cols);
    mvwprintw(stdscr, 2, 3, "Rows: %d, Cols:%d", rows, cols);

    int ball_row = rows/2;

    mvaddch(ball_row, ball_col, BALL);

    while(1) {
        if (ball_dir == RIGHT) {
            ball_col++;
        } else {
            ball_col--;
        }
        clear();
        mvaddch(ball_row, ball_col, BALL);
        if (ball_col == cols-1) {
            ball_dir = LEFT;
        } else if (ball_col == 0) {
            ball_dir = RIGHT;
        }

        refresh();
            
        usleep(SLEEP_MS * 1000);
    }

    getch();
}

