#include <stdio.h>

#define MAX 20

int main(int argc, char *argv[])
{
    char first_name[MAX];
    char last_name[MAX];

    printf("Enter your first name please:\n");
    scanf("%s", first_name);
    printf("Enter your last name please:\n");
    scanf("%s", last_name);

    printf("%s, %s\n", first_name, last_name);
    return 0;
}
