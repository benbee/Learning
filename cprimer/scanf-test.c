#include <stdio.h>

int main(int argc, char *argv[])
{
    int a;
    char s[50];
    printf("Please enter your code & name: ");
    scanf("%d, %s", &a, s);

    printf("Welcome %d member %s\n", a, s);
    return 0;
}
