/* This program get a float number and print out in xe+a */
#include <stdio.h>

int main(int argc, char *argv[])
{
    float x;
    printf("Please enter a float number: \n");
    scanf("%f", &x);
    printf("The input is %f or %e.\n", x, x);
    return 0;
}
