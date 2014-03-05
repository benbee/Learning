#include <stdio.h>

#define WARP_LENGTH 10

char line[WARP_LENGTH];

void print_line();

int main(int argc, char *argv[])
{
    int i, c, last_space;
    int n = 0;
    
    int s[WARP_LENGTH];

    while ((c = getchar()) != EOF) {
	s[n] = c;
	if (s[n] == ' ') {
	    last_space = n;
	}

	if (n = WARP_LENGTH - 1) {
	    for (i = 0; i < last_space; ++i) {
		printf("%c", s[i]);
	    }

	    if (last_space != WARP_LENGTH) {
		printf("\n");
		n = 0;

		for (i = last_space + 1; i < WARP_LENGTH - 1; ++i) {
		    s[n] = s[i];
		    n++;
		}
	    }
	} else {
	    n++;
	}

    }
    return 0;
}
