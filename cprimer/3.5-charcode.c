/* charcode.c -- print the value of a char */
#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;
    printf("Please enter a character.\n");
    scanf("%c", &ch);
    printf("The code fo %c is %d.\n", ch, ch);
    return 0;
}
