#include <stdio.h>

int main(int argc, const char *argv[]) {
    char inputText[6] = {'\0'};

    printf("input: ");
    scanf("%s", inputText);

    for(int i = 4; i >= 0; i--) {
        printf("%c", inputText[i]);
    }

    printf("\n");
    return 0;
}