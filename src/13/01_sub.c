#include <stdio.h>

int subOf(int a, int b) { return a - b; }
int main(int argc, char const *argv[]) {
    int a = 5;
    int b = 10;
    int result;

    result = subOf(a, b);

    printf("%d - %d = %d\n", a, b, result);

    return 0;
}