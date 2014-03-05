#include <stdio.h>
#include <ctype.h>		/* support for isalpha() */

int main(int argc, char *argv[])
{
    char ch;

    while ((ch = getchar()) != '\n') {
	if (isalpha(ch)) {
	    putchar(ch + 1);
	} else {
	    putchar(ch);
	}
    }

    putchar(ch);
    
    return 0;
}
