#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%x %X %#X\n", 31, 31, 31);
    printf("***%d**% d**% d**\n", 42, 42, -42);
    printf("***%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
    return 0;
}
