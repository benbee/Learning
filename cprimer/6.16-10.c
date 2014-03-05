#include <stdio.h>

#define ARR_LEN 8

int main(int argc, char *argv[])
{
    int num[ARR_LEN];
    int i;
    
    printf("Enter %d numbers: ", ARR_LEN);
    for (i = 0; i < ARR_LEN; ++i) {
	scanf("%d", &num[i]);
    }

    for (i = ARR_LEN - 1; i >= 0; --i) {
	printf("%3d", num[i]);
    }
    printf("\n");
    return 0;
}
