#include <stdio.h>


int main(int argc, char *argv[])
{
    int x = 100;

    while (x++ < 103)
	printf("%4d\n", x);
    printf("%4d\n", x);
    return 0;
}
