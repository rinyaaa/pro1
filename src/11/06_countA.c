#include <stdio.h>

int main(int argc, const char *argv[]) {
    char inputText[21] = {'\0'};
    int count = 0;

    printf("input(20文字以下): ");
    scanf("%s", inputText);

    for(int i = 0; inputText[i] != '\0'; i++)
        if('a' == inputText[i])
            count++;

    printf("aの数: %d\n", count);
    return 0;
}