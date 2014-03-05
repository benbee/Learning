#include <stdio.h>

#define  MAXCOUNT 4

int main(int argc, char *argv[])
{
    int ch;
    int count;
    count = 0;

    while ((ch = getchar()) != EOF) {
	if (ch == '\t') {
	    printf("  \\t%4d", ch);
	} else if (ch == '\n') {
	    printf("  \\n%5d", ch);
	} else {
	    printf("%3c%4d", ch, ch);
	}
	count++;
	if (count == MAXCOUNT) {
	    printf("\n");
	    count = 0;
	}
    }
    
    return 0;
}
