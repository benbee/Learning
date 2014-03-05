#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j;

    for (i = 0; i < 26; ++i) {
	for (j =  26-i-1; j > 0 ; j--) {
	    printf(" ");
	}
	for (j = 0; j <= i; j++) {
	    printf("%c", j + 'A');
	}
	for (j = i-1; j >= 0; j--) {
	    printf("%c", j + 'A');
	}

	printf("\n");
    }
    
    return 0;
}
