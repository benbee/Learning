/* print out 100 in dec, octal, hex */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
    return 0;
}
