/* 4.2-praise1.c -- use deferent kinds of strings */
#include <stdio.h>

#define PRAISE "What a super marvelous name!"

int main(int argc, char *argv[])
{
    char name[40];

    printf("What\'s your name?\n");
    scanf("%s", name);
    //gets("%s", name);        // use gets instead
    printf("Hello, %s. %s\n", name, PRAISE);
    return 0;
}
