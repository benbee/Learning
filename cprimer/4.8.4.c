#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[20];
    int  height_in_cm;

    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Enter your height (in cms):\n");
    scanf("%d", &height_in_cm);

    printf("%s, you are %.2f meters tall\n", name, height_in_cm / 100.0);
    return 0;
}
