#include <stdio.h>

int bigger_than_guess_number(int guess);

int main(int argc, char *argv[])
{
    int guess;
    int max_guess;
    int min_guess;
    char ch;

    max_guess = 100;
    min_guess = 0;
    guess = 50;
    printf("Hi there,");
    printf("please think a number(1-100) to let me guess:\n");
    printf("Is it %d ?(enter 'y' or 'n')\n", guess);
    while ((ch = getchar()) != 'y') {
	if (ch != 'n')
	    continue;    
	if (bigger_than_guess_number(guess)) {
	    max_guess = guess;
	    guess = (min_guess + max_guess) / 2;	    
	} else {
	    min_guess = guess;
	    guess = (min_guess + max_guess) / 2;
	}
	
	printf("Ennnnn, is it %d ('y' or 'n')?\n", guess);
}
    printf("HAHA! I gues the right number!\n");
    printf("I love this game!\n");
    
    return 0;
}

int bigger_than_guess_number(int guess)
{
    char ch;
    
    printf("Oh, no!\n");
    printf("%d is bigger or smaller?(enter 'b' or 's')\n", guess);
    while ((ch = getchar()) != EOF) {
	switch(ch)
	{
	    case 'b':
	    case 'B':
		return 1;
	    case 's':
	    case 'S':
		return 0;
	    case '\n':
		break;
	    default:
		printf("Please enter the right option('b' or 's').\n");
		while (getchar() != '\n')
		    continue;
	}
    }
}
