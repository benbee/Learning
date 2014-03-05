#include <stdio.h>

void butler(void);

int main(int argc, char *argv[])
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");
    return 0;
}

void butler(void)
{
    printf("You rang. sir?\n");
}
