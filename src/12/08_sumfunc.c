#include <stdio.h>

int sumOf(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int n;

    printf("n? ");
    scanf("%d", &n);

    int sum = sumOf(n);

    printf("1から%dまでの和は %d\n", n, sum);

    return 0;
}