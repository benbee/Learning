#include <stdio.h>

double xiezhi(double x, double y);

int main(int argc, char *argv[])
{
    double x, y;
    
    printf("Enter two numbers:\n");
    scanf("%lf %lf", &x, &y);
    printf("%.2lf he %.2lf de xie zhi shi: %.2lf\n", x, y, xiezhi(x, y));
    
    return 0;
}

double xiezhi(double x, double y)
{
    return 1/(((1/x) + (1/y))/2);
}
