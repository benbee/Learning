#include <stdio.h>

int main(int argc, char *argv[])
{
    int num, end;

    printf("Please enter a number:\n");
    scanf("%d", &num);
    end = num + 10;

    while (num <= end) {
	printf("%4d", num);
	++num;
    }
    printf("\n");
    
    return 0;
}
