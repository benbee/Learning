#include <stdio.h>

void chline(char ch, int x, int y);

int main(int argc, char *argv[])
{
    char ch;
    int i, j;
    
    printf("Which character do you want to print out?\n");
    scanf("%c", &ch);
    printf("Where do you want to start and stop?\n");
    scanf("%d %d", &i, &j);
    chline(ch, i, j);
    
    return 0;
}

void chline(char ch, int i, int j)
{
    int n;
    
    for (n = 0; n < i; n++) {
	printf("%c", ' ');
    }
    for (n = i; n <=j; n++) {
	printf("%c", ch);
    }
    printf("\n");
}
