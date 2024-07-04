#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a;
    int b;

    printf("a b? ");
    scanf("%d %d", &a, &b);

    printf("大きい方の値は ");
    if(a > b) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }

    return 0;
}