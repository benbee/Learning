#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    unsigned long num;		/* the number to be checked */
    unsigned long div;		/* divisor possible */
    bool isPrime;		/* flag to prime */

    printf("Please enter an integer for analysis: ");
    printf("Enter q to quit.\n");
    while (scanf("%lu", &num ) == 1) {
	for (div = 2, isPrime = true; (div * div) <= num; div++) {
	    if ((num % div == 0)){
		if ((div * div) != num)
		    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
		else
		    printf("%lu is divisible by %lu.\n", num, div);
		isPrime = false; /* not a prime */
	    }
	}

	if (num == 1) {
	    isPrime = false;
	}

	if (isPrime)
	    printf("%lu is prime.\n", num);
	printf("Please enter another integer for analysis: \n");
	printf("Press q to quit.\n");
    }

    printf("BYE!\n");
    
    return 0;
}
