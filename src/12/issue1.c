#include <stdio.h>

int factOf(int n) {
    int fact = 1;
    for(int i = n; i >= 1; i--) {
        fact = i * fact;
    }
    return fact;
}

int main(int argc, char const *argv[]) {
    int n;

    printf("n? ");
    scanf("%d", &n);

    int fact = factOf(n);

    printf("%dの階乗は %d\n", n, fact);

    return 0;
}