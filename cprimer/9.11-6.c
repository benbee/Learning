#include <stdio.h>

int ch_position(char ch);

int main(int argc, char *argv[])
{
    char ch;

    printf("Please enter something to analysis:\n");
    while((ch = getchar()) != EOF) {
	//printf("%d %d\n", 'A', 'z');
	if (ch >= 'A' && ch <= 'z') {
	    printf("The position of %c is %d\n", ch, ch_position(ch));
	}
    }
    
    return 0;
}

int ch_position(char ch)
{
    if (ch >= 'a' && ch <= 'z')
	return ch - 'a' + 1;
    else if (ch >= 'A' && ch <= 'Z')
	return ch - 'A' + 1;
    else
	return -1;
}
