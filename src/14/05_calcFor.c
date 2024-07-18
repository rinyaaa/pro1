#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, sum = 0;

    printf("n? ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("1から%dまでの和は %d\n", n, sum);

    return 0;
}