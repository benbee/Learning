#include <stdio.h>

void Temperatures(double farh);

int main(int argc, char *argv[])
{
    double fahr;
    int status;
    printf("Enter a temperature in fahr: \n");
    status = scanf("%lf", &fahr);
    while (status == 1) {
	Temperatures(fahr);
	status = scanf("%lf", &fahr);
    }
    
    return 0;
}

void Temperatures(double fahr)
{
    
    double cels;
    double kelvin;
    cels = (fahr - 32.0) / 1.8;
    kelvin = cels + 273.16;
    printf("%4.2f farh are %4.2fC, or %4.2fK.\n", fahr, cels, kelvin);
}
















