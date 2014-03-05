#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));
    static int number;
	number = rand() % 100;
	number = 50;

	printf("Number to be gussed: %d", number);
	int guess, count;
	count = 8;

	printf("Enter a number(1-100): ");
	scanf("%d", &guess);
	
	while (number != guess) {
		count--;
		if (count < 0) {
			printf("Too many times, it's over\n");
			exit(1);
		}

		if (guess < number) {
			printf("Too small\n");
			printf("sorry, wrong number, try again: ");
			scanf("%d", &guess);
		} else if (guess > number) {
			printf("Too big\n");
			printf("sorry, wrong number, try again: ");
			scanf("%d", &guess);
		} else {
			break;
		}
	}
	printf("You win the game\n");
	
    return 0;
}
