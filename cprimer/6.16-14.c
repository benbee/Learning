#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 255

int main(int argc, char *argv[])
{
    int i;
    char ch[MAX_LENGTH];

    printf("Enter some thing please:\n");
    gets(ch);

    for (i = strlen(ch); i >= 0; i--) {
	printf("%c", ch[i]);
    }

    printf("\n");
    
    return 0;
}
