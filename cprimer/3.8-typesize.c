/* print out the size of each type*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Type int has a sieze of %u bytes.\n", sizeof(int));
    printf("Type char has a size of %u bytes.\n", sizeof(char));
    printf("Type long has a size of %u bytes.\n", sizeof(long));
    printf("Type float has a size of %u bytes.\n", sizeof(float));
    printf("Type double has a size of %u bytes.\n", sizeof(double));
    return 0;
}
