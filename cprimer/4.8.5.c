/* need to covert int to string */

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int main(int argc, char *argv[])
{
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];

    printf("Please enter your first name and lastname(like \"John  Brown\"):\n");
    scanf("%s %s", first_name, last_name);
    //printf("%*s %*s\n", strlen(first_name), first_name, strlen(last_name), last_name);
    printf("%*d %*d\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));
    
    return 0;
}
