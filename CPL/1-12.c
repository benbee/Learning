#include <stdio.h>
/*
 * print one word a line
 */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t'){
	    printf("\n");
	}
	else if (state == OUT) {
	    putchar(c);
	}
    }
}
