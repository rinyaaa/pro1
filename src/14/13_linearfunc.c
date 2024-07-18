#include <stdio.h>

int f(int x) {
    return 2 * x + 1;
}

int main(int argc, const char *argv[]) {
    for(int x = 0; x <= 4; x++) {
        printf("f(%d)=%d\n", x, f(x));
    }
    return 0;
}