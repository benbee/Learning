#include <stdio.h>
#define FALSE 0
#define TRUE 1

main()
{
    int c;
    int last_is_space = FALSE;
    while ((c = getchar()) != EOF) {
        if ((last_is_space) && (c == ' ')) {
	    continue;
	}
        else if ((last_is_space != TRUE) && (c == ' ')) {
	    last_is_space = TRUE;
	    putchar(c);
	} else {
            putchar(c);
        }
    }
}
