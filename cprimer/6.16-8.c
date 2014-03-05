#include <stdio.h>

float cal_float(float a, float b);

int main(int argc, char *argv[])
{
    float a, b;

    printf("Enter two float(like\"2.6 56.7\"):\n");
    while (scanf("%f %f", &a, &b) == 2) {
	printf("%f\n", cal_float(a, b));
    }

    
    return 0;
}

float cal_float(float a, float b)
{
    return (a-b)/(a*b);
}
