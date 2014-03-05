#include <stdio.h>
#include <string.h>
#define MAX 10

int main(int argc, char *argv[])
{
    char name[MAX];

    printf("Enter your name please:\n");
    scanf("%s", name);
    printf("\"%-*s\"\n", strlen(name)+3, name);
    return 0;
}
