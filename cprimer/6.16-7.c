#include <stdio.h>

int main(int argc, char *argv[])
{
    float a, b;

    printf("Enter two floats please(like\"2 6\"):\n");
    while (scanf("%f %f", &a, &b) == 2) {
	printf("%f\n", (a-b)/(a*b));
    }
    
    return 0;
}
