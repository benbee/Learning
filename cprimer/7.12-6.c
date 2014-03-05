#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    char ch, prev;

    printf("Please enter something for analysis: \n");
    while ((ch = getchar()) != '#') {
	if (ch == 'i' && prev == 'e') {
	    count++;
	    prev = ch;
	} else
	    prev = ch;
    }

    printf("Reveived %d \'ei\'.\n", count);
    
    return 0;
}
