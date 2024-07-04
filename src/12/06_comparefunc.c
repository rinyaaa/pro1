#include <stdio.h>

int maxOf(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main(int argc, char const *argv[]) {
    int a;
    int b;

    printf("a b? ");
    scanf("%d %d", &a, &b);

    int max = maxOf(a, b);

    printf("大きい方の値は %d\n", max);

    return 0;
}