#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j;

    for (i = 0; i < 4; ++i) {
	for (j = 0; j < 8; ++j) {
	    printf("$");
	}
	printf("\n");
    }
    return 0;
}
