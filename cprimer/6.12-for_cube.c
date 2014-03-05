/* printout cube table */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    printf("n\tpower\tcube\n");

    for (n = 1; n < 10; ++n) {
	printf("%d\t%d\t%d\n", n, n*n, n*n*n);
    }
    return 0;
}
