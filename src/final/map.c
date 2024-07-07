#include <stdio.h>

enum { map_height = 30, map_width = 40 };

typedef enum { map_floor, map_wall, map_start, map_goal } MazeCell;

int main() {
    printf("Map height: %d\n", map_height);
    printf("Map width: %d\n", map_width);
    return 0;
}