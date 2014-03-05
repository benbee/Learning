#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;
    int count;

    ch = getchar();
    count = 1;

    while ((ch = getchar()) != EOF){
	count++;
    }

    printf("%d\n", count);
    
    return 0;
}
