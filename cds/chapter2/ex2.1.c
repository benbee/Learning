// Program to fiand MAXimum of 3 values
#include <stdio.h>

int FindMax(int a, int b, int c);

int main(int argc, char *argv[])
{
    int a, b, c;
	int max;

	printf("enter values of a, b, c\n");
	scanf("%d%d%d", &a, &b, &c);

	max = FindMax(a, b, c);

	printf("\nMax Value of %d, %d, %d is %d\n", a, b, c, max);
	
    return 0;
}

int FindMax(int a, int b, int c)
{
	int max;
	max = a;

	if (max < b)
		max = b;
	if (max < c)
		max = c;

	return max;
}
