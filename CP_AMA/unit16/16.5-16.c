#include <stdio.h>

int main(int argc, char *argv[])
{
    enum {FALSE, TRUE} b;
	int i;

	/* b = FALSE; */
	/* b = i; */
	/* b++; */
	/* b += 100; */
	/* i = b; */
	/* printf("b: %d\n", b); */
	i = 2 * b + 1;
	printf("i: %d\n", i);

    return 0;
}
