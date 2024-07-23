#include <stdio.h>

void devB(int a, int b, int c) {
    if(a || (b && c)) {
        printf("GO\n");
    } else if(!b && c) {
        printf("GO\n");
    } else {
        printf("NO\n");
    }
}

int main(int argc, const char *argv[]) {

    for(int i = 0; i < 8; i++) {
        devB(i / 4 % 2, i / 2 % 2, i % 2);
    }

    return 0;
} 