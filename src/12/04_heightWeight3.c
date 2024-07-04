#include <stdio.h>

int main(int argc, char const *argv[]) {
    int human[3][2] = {};

    for(int i = 0; i < 3; i++) {
        printf("%d人目の身長と体重? ", i + 1);
        for(int j = 0; j < 2; j++) {
            scanf("%d", &human[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0) {
                printf("%d人目の身長と体重は ", i + 1);
            }
            printf("%d ", human[i][j]);
        }
        printf("\n");
    }

    return 0;
}