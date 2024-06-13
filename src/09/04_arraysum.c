#include <stdio.h>

int main(int argc, const char *argv[]) {
    int numbers[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int sum;

    sum = 0;

    for(int n = 0; n < 10; n++) {
        sum = sum + numbers[n];
    }
    printf("合計 = %d", sum);

    return 0;
}