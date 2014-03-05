#include <stdio.h>

void one_two(void);
void two(void);

int main(int argc, char *argv[])
{
    printf("starting now:\n");
    one_two();
    two();
    printf("three\n");
    printf("done!\n");
    return 0;
}

void one_two(void)
{
    printf("one\n");
}

void two(void)
{
    printf("two\n");
}
