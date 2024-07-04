#include <stdio.h>

int main(int argc, const char *argv[]) {

    char inputText[21] = {'\0'};
    int isPalindrome = 1;
    int length = 0;

    printf("input(20文字以下): ");
    scanf("%s", inputText);

    for(int i = 0; i < 21; i++) {
        if(inputText[i] == '\0') {
            length = i;
            break;
        }
    }

    for(int i = 0; i < length / 2; i++) {
        if(inputText[i] != inputText[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome) {
        printf("回文OK\n");
    } else {
        printf("回文NG\n");
    }

    return 0;
}
