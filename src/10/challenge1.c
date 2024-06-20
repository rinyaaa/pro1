#include <stdio.h>

int main(int argc, const char *argv[]) {
    int primeNumbers[100] = {0};
    int index = 0;

    for(int i = 2; i <= 100; i++) {
        int isPrime = 1;

        for(int j = 2; j <= i / 2; j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime == 1) {
            index++;
            primeNumbers[index] = i;
            printf("%d, ", primeNumbers[index]);
        }
    }

    return 0;
}
