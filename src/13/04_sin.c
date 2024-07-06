#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    double theta;
    double rad;

    printf("input: ");
    scanf("%lf", &theta);

    rad = theta / 180.0 * M_PI;

    printf("sin(%f) = %f\n", theta, sin(rad));

    return 0;
}