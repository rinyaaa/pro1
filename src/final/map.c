#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { map_height = 31, map_width = 41 }; // mapの範囲指定

typedef enum { map_floor, map_wall, map_start, map_goal } MazeCell;

MazeCell map[map_height][map_width];

void initialize_map() {
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            map[y][x] = map_wall;
        }
    }
}

void print_map() {
    for(int y = 0; y < map_height; y++) {
        for(int x = 0; x < map_width; x++) {
            switch(map[y][x]) {
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

void generate_map(int x, int y) {
    const int dirs[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    int order[4] = {0, 1, 2, 3};
    map[y][x] = map_floor;

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
           map[ny][nx] == map_wall) {
            map[ny - dy / 2][nx - dx / 2] = map_floor;
            map[ny][nx] = map_floor;
            generate_map(nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_map();
    generate_map(1, 1); // スタート地点を(1,1)に設定
    map[1][1] = map_start;
    map[map_height - 2][map_width - 2] = map_goal;
    print_map();
    return 0;
}