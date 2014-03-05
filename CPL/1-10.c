#include <stdio.h>
#define FALSE 0
#define TRUE 1

main()
{
    int c;

    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    printf("\\t");
	} else if (c == '\b') {
	    printf("\\b");
	} else if (c == '\\') {
	    printf("\\\\");
	} else {
	    putchar(c);
	}
    }
}
