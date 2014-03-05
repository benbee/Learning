#include <stdio.h>

void chprint(char ch, int count, int lines);

int main(int argc, char *argv[])
{
    chprint('*', 5, 5);
    
    return 0;
}

void chprint(char ch, int count, int lines)
{
    int i, j;
    for (i = 0; i < lines; ++i) {
	for (j = 0; j < count; ++j) {
	    printf("%c", ch);
	}
	printf("\n");
    }
}
