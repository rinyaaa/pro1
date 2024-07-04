#include <stdio.h>

int addOf(int a, int b) {
    int add = a + b;
    return add;
}

int main(int argc, char const *argv[]) {
    int a, b;

    printf("a b? ");
    scanf("%d %d", &a, &b);

    int add = addOf(a, b);

    printf("和は? %d\n", add);
    return 0;
}