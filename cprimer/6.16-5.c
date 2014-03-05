#include <stdio.h>

int main(int argc, char *argv[])
{
    int upper, lower;
    int i;
    printf("Please enter the start and end point of power and cube table(like \"2 6\"): \n");
    scanf("%d %d", &lower, &upper);

    printf("%5s %5s %5s\n", "n", "power", "cube");
    for (i = lower; i <= upper; ++i) {
	printf("%5d %5d %5d\n", i, i*i, i*i*i);
    }
    
    return 0;
}
