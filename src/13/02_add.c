#include <stdio.h>

void addOf(int a, int b) { printf("%d + %d = %d\n", a, b, a + b); }
int main(int argc, char const *argv[]) {
    int a = 5;
    int b = 10;
    int result = 0;

    addOf(a, b);

    return 0;
}