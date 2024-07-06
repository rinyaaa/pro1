#include <stdio.h>

#define NUM 10

int main(int argc, const char *argv[]) {
    int sum = 0;

    for(int i = 1; i <= NUM; i++) {
        sum = sum + i;
    }

    printf("総和 = %d\n", sum);

    return 0;
}