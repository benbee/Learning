#include <stdio.h>

#define LINE_LENGTH 8

int main(int argc, char *argv[])
{
    char ch;
    int count;

    count = 0;

    while ((ch = getchar()) != '#') {
	printf("%5d", ch);
	count++;
	if (count == 8){
	    printf("\n");
	    count = 0;
	}
    }
    printf("\n");
    return 0;
}










