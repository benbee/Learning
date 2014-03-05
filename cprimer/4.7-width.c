/* width.c -- character-width */
#include <stdio.h>

#define PAGES 931

int main(int argc, char *argv[])
{
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);
    return 0;
}
