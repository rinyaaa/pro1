#include <stdio.h>

int main(int argc, const char *argv[]) {
    char c;

    printf("文字を入力してください: ");
    c = getchar();

    switch(c) {
    case 'L':
        printf("Left\n");
        break;
    case 'R':
        printf("Right\n");
        break;
    default:
        printf("nop\n");
        break;
    }

    return 0;
}