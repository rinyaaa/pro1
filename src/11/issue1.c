
#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[]) {

    char inputText[21] = {'\0'};
    int isPalindrome = 1;

    printf("input(20文字以下): ");
    scanf("%s", inputText);

    int length = strlen(inputText);
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
