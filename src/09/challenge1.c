#include <ctype.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    char ch;
    int isMinus;
    int answer;
    int inputNumber;

    answer = 0;
    isMinus = 0;

    printf("equation? ");
    while((ch = getchar()) != '\n') {

        switch(ch) {
        case '+':
            isMinus = 0;
            break;
        case '-':
            isMinus = 1;
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            inputNumber = ch - '0';
            if(isMinus == 1) {
                answer = answer - inputNumber;
            } else {
                answer = answer + inputNumber;
            }
            break;

        case '=':
            printf("answer: %d\n", answer);
            return 0;
        }
    }
}