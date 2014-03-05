#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

int main(int argc, char *argv[])
{
    int i;
    char words[MAX_LENGTH];

    printf("Enter something please: \n");
    scanf("%s", words);

    for (i = strlen(words); i >= 0; i--) {
	printf("%c", words[i]);
    }
    
    return 0;
}
