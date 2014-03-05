#include <stdio.h>

int main(int argc, char *argv[])
{
    float float_num;

    printf("Please enter a float number:\n");
    scanf("%f", &float_num);

    printf("The number is %+.1f or %.3E\n", float_num, float_num);
    return 0;
}
