#include <stdio.h>
#include <string.h>

char * duplicate(char *str);
int read_line(char *str, int n);

int main(int argc, char *argv[])
{
    char test_str[255];
	char *p;
	
	printf("Enter something: ");
	read_line(test_str, 255);
	/* scanf("%s", test_str); */

	p = duplicate(test_str);

	printf("You entered: \"%s\"\n", p);
	
    return 0;
}

char *duplicate(char *str)
{
	char *p;

	p = (char *)malloc(sizeof(str));

	strcpy(p, str);

	return p;
}

int read_line(char *str, int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
