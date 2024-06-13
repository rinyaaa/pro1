#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;

    printf("n? ");
    scanf("%d", &n);

    switch(n) {
    case 1:
        printf("AAA");
        break;
    case 2:
        printf("BBB");
        break;
    case 3:
        printf("Defaultです.");
        break;
    }

    return 0;
}