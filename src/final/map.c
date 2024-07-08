#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { map_height = 31, map_width = 41 }; // mapの範囲指定

typedef enum { map_floor, map_wall, map_start, map_goal } MazeCell;

MazeCell maze[map_height][map_width];

void initialize_maze() {
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            maze[y][x] = map_wall;
        }
    }
}

void print_maze() {
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            switch(maze[y][x]) {
            case map_floor:
                printf("  ");
                break;
            case map_wall:
                printf("##");
                break;
            case map_start:
                printf("1 ");
                break;
            case map_goal:
                printf("G ");
                break;
            }
        }
        printf("\n");
    }
}

void generate_maze(int x, int y) {
    const int dirs[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};
    maze[y][x] = map_floor;

    // Fisher-Yatesアルゴリズムで方向をランダムにシャッフル
    for(int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    for(int i = 0; i < 4; i++) {
        int dx = dirs[order[i]][0];
        int dy = dirs[order[i]][1];
        int nx = x + dx;
        int ny = y + dy;
        if(nx >= 0 && nx < map_width && ny >= 0 && ny < map_height &&
           maze[ny][nx] == map_wall) {
            maze[ny - dy / 2][nx - dx / 2] = map_floor;
            maze[ny][nx] = map_floor;
            generate_maze(nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_maze();
    generate_maze(1, 1); // スタート地点を(1,1)に設定
    maze[1][1] = map_start;
    maze[map_height - 2][map_width - 2] = map_goal;
    print_maze();
    return 0;
}