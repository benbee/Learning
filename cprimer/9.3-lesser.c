/* lesser.c -- find the smaller integer */
#include <stdio.h>
int imin(int, int);

int main(int argc, char *argv[])
{
    int evil1, evil2;

    printf("Enter a pair of integers (q to quit):\n");
    while (scanf("%d %d", &evil1, &evil2) == 2) {
	printf("The lesser of %d and %d ia %d.\n", evil1, evil2, imin(evil1, evil2));
	printf("Enter a pair of integers (q to quit):\n");
    }
    printf("Bye!\n");
    
    return 0;
}

int imin(int n, int m)
/* return the lesser number */
{
    /* if(n >= m) */
    /* 	return m; */
    /* else */
    /* 	return n; */
    return (n < m) ? n : m;
}

