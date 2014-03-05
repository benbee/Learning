#include <stdio.h>

#define array_length 8

int power(int a, int b);

int main(int argc, char *argv[])
{
    int i;
    int num[array_length];
    
    for (i = 0; i < array_length; ++i) {
	num[i] = power(2, i);
    }

    i = 0;
    do
    {
	printf("%6d", num[i]);
	i++;
    } while (i < array_length);
    printf("\n");
    return 0;
}

int power(int a, int b)
{
    int result;
    for (b, result = 1; b > 0; b--) {
	result = result * a;
    }

    return result;
}
