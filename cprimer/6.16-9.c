#include <stdio.h>

int square_sum(int a, int b);

int main(int argc, char *argv[])
{
    int upper, lower;

    printf("Enter lower and upper integer limites: ");
    scanf("%d %d", &lower, &upper);
    while(upper > lower) {
	printf("The sums of the squares from %d to %d is %d\n", lower, upper,square_sum(lower, upper));
	scanf("%d %d", &lower, &upper);
    }

    printf("Done!\n");
    
    return 0;
}

int square_sum(int a, int b)
{
    int result = 0;
    
    for(a; a <= b; a++) {
	result += a*a;
    }

    return result;
}
