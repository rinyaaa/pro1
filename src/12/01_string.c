#include <stdio.h>

int main(int argc, char const *argv[]) {
    char array[11] = {'\0'};

    printf("入力(10文字以内): ");
    scanf("%s", array);

    printf("%s\n", array);
    return 0;
}
