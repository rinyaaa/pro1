#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int selected;
    double x;

    printf("x? ");
    scanf("%lf", &x);

    printf("--- menu ---\n");

    printf("1:絶対値, 2:二乗, 3: 三乗\n");
    printf("menu no? ");
    scanf("%d", &selected);

    switch(selected) {
    case 1:
        printf("|%lf| = %lf", x, fabs(x));
        break;

    case 2:
        printf("%lf ^ 2 = %lf", x, pow(x, 2));
        break;
    case 3:
        printf("%lf ^ 3 = %lf", x, pow(x, 3));
        break;
    }
    return 0;
}