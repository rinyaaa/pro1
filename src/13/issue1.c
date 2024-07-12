#include <math.h>
#include <stdio.h>

double calcArea(double r) { return M_PI * pow(r, 2); }

double calcCircumference(double r) { return 2 * M_PI * r; }

int main(int argc, const char *argv[]) {

    double r;

    printf("input r: ");
    scansf("%lf", &r);

    printf("%f ", calcArea(r));

    printf("%f\n", calcCircumference(r));
    return 0;
}