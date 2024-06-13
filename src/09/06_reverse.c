#include <stdio.h>

int main(int argc, const char *argv[]) {
    int input[5] = {0};
    int i;

    for(i = 0; i < 5; i++) {
        printf("input[%d]? ", i);
        scanf("%d", &input[i]);
    }
    printf("---reverse---\n");
    for(i = 4; 0 <= i; i--) {
        printf("input[%d]: %d\n", i, input[i]);
    }
    return 0;
}