/* convert days to weeks and days */
#include <stdio.h>

const D_PER_W = 7;

int main(int argc, char *argv[])
{
    int days;

    printf("Enter days:\n");
    scanf("%d", &days);
    while (days > 0){
	printf("%d days are %d weeks, %d days.\n", days, days/D_PER_W, days%D_PER_W);
	scanf("%d", &days);
    }
    return 0;
}
