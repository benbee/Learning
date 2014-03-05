/* make swap by use pointer */
#include <stdio.h>

void interchange(int *, int *);

int main(int argc, char *argv[])
{
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d\n", x, y);
    interchange(&x, &y);	/* pass the address to the function */
    printf("Now x = %d adn y = %d\n",x, y);
    
    return 0;
}

void interchange(int * u, int * v)
{
    int temp;
    temp = *v;
    *v = *u;
    *u = temp;
}
