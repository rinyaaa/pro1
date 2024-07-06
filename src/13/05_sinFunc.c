#include <math.h>
#include <stdio.h>

double deg2Rad(double theta) {
    double rad = theta / 180.0 * M_PI;
    return rad;
}

int main(int argc, const char *argv[]) {
    double theta;
    double rad;

    printf("input: ");
    scanf("%lf", &theta);

    rad = deg2Rad(theta);

    printf("sin(%f) = %f\n", theta, sin(rad));

    return 0;
}