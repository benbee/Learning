#include <stdio.h>

int main(int argc, char *argv[])
{
    int ten = 10;
    int two = 2;
    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing it wrong: \n");
    printf("%d minus %d is %d\n", ten);
    return 0;
}
