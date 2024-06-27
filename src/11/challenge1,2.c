#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[]) {
    char paragraph[] =
        "we hold these truths to be self-evident, that all men are created "
        "equal, that they are endowed by their creator with certain "
        "unalienable "
        "rights, that among these are life, liberty and the pursuit of "
        "happiness.";
    char searchTerm[13] = {'\0'};
    int index = -1;

    printf("searchTerm: ");
    scanf("%s", searchTerm);

    char *ptr = strstr(paragraph, searchTerm);

    if(ptr != NULL) {
        index = ptr - paragraph;
    }

    printf("indexOf: %d\n", index);

    return 0;
}