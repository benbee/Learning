#include <stdio.h>

void larger_of(double * x, double * y);
double max(double x, double y);

int main(int argc, char *argv[])
{
    double x, y;

    printf("Please enter two numbers:\n");
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    larger_of(&x, &y);
    printf("After larger_of, x = %.2lf, y = %.2lf\n", x, y);
    
    return 0;
}

double max(double x, double y)
{
    double max;

    max = x > y ? x : y;
    return max;
}

void larger_of(double * x, double * y)
{
    double larger = max(*x, *y);
    *x = larger;
    *y = larger;
}
