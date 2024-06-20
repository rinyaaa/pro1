#include <stdio.h>

int main(int argc, const char *argv[]) {
    int evenNumbers[5] = {0};
    int sum = 0;
    int gu = 2;

    for(int i = 0; i < 5; i++) {
        evenNumbers[i] = gu;
        gu = gu + 2;

        sum = sum + evenNumbers[i];
    }
    printf("%d\n", sum);
}