/* translate a ascii value to a char */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    printf("Please enter a ASCII value: \n");
    scanf("%d", &c);
    printf("The value you enter is char: %c.\n", c);
    return 0;
}
