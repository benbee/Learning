#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    char ch;

    printf("Please enter something for analysis:\n");
    while ((ch = getchar()) != '#') {
	if (ch == '!') {
	    printf("!!");
	    count++;
	} else
	    printf("%c", ch);
    }

    printf("There are total %d \"!\".\n", count);
    
    return 0;
}
