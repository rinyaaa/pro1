#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

typedef struct {
    int x, y;
} Point;

void initialize_snake(Point snake[], int length, int max_x, int max_y) {
    for(int i = 0; i < length; i++) {
        snake[i].x = max_x / 2 - i;
        snake[i].y = max_y / 2;
    }
}

void move_snake(Point snake[], int length, int direction) {
    for(int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    switch(direction) {
    case KEY_UP:
        snake[0].y--;
        break;
    case KEY_DOWN:
        snake[0].y++;
        break;
    case KEY_LEFT:
        snake[0].x--;
        break;
    case KEY_RIGHT:
        snake[0].x++;
        break;
    }
}

int check_collision(Point snake[], int length, int max_x, int max_y) {
    if(snake[0].x < 0 || snake[0].x >= max_x || snake[0].y < 0 ||
       snake[0].y >= max_y) {
        return 1;
    }
    for(int i = 1; i < length; i++) {
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return 1;
        }
    }
    return 0;
}

void draw_snake(Point snake[], int length) {
    for(int i = 0; i < length; i++) {
        mvprintw(snake[i].y, snake[i].x, "O");
    }
}

int main() {
    Point snake[100];
    int length = 5;
    int ch;
    int max_x, max_y;
    int direction = KEY_RIGHT;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    timeout(0);
    getmaxyx(stdscr, max_y, max_x);

    initialize_snake(snake, length, max_x, max_y);

    while(1) {
        clear();

        ch = getch();
        if(ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT ||
           ch == KEY_RIGHT) {
            direction = ch;
        }

        move_snake(snake, length, direction);
        draw_snake(snake, length);

        refresh();
        usleep(DELAY);

        if(check_collision(snake, length, max_x, max_y)) {
            break;
        }
    }

    endwin();
    printf("Game Over\n");
    return 0;
}
