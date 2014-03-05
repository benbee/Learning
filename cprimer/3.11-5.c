/* compute your age to seconds */
#include <stdio.h>

#define YEAR_TO_SECONDS  3.156e7

int main(int argc, char *argv[])
{
    int age;
    printf("Please enter your age: \n");
    scanf("%d", &age);
    printf("You lived %e seconds at least!\n", age * YEAR_TO_SECONDS);
    return 0;
}
