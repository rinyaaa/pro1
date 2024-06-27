#include <stdio.h>

int main(int argc, const char *argv[]) {
    char array[] = "abcde";

    printf("一文字ずつ印字: ");
    for(int i = 0; i < 5; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
    return 0;
}
