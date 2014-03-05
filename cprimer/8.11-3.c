#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;
    int upper_count, lower_count;
    upper_count = lower_count = 0;

    while ((ch = getchar()) != EOF) {
	if (ch >= 'a' && ch <= 'z')
	    lower_count++;
	if (ch >= 'A' && ch <= 'Z')
	    upper_count++;
    }

    printf("\n");
    printf("Total up case: %d\n", upper_count);
    printf("Total low case: %d\n", lower_count);
    
    return 0;
}
