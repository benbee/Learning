/* bad para suitation */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int f = 4;
    int g = 5;
    float h = 5.0f;

    printf("%d\n", f, g);
    printf("%d %d\n", f);
    printf("%d %f\n", h, g);
    return 0;
}
