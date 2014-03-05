#include <stdio.h>
#include <float.h>

int main(int argc, char *argv[])
{
    double d31 = 1.0/3.0;
    float f31 = 1.0/3.0;

    printf("%.4f %.12f %.16f\n", f31, f31, f31);
    printf("%.4f %.12f %.16f\n", d31, d31, d31);
    printf("FLT_DIG:%f\nDBL_DIG:%f\n", FLT_MAX, DBL_MAX);
    return 0;
}


















