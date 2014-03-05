#include <stdio.h>

#define LENGTH 100

int main(int argc, char *argv[])
{
    FILE *fd;
	char str[LENGTH];

	fd = fopen("hello.txt", "w+"); /* create and open file */
	if (fd) {
		fputs("Hello, World!", fd); /* write string to file */
		fclose(fd);
	}

	fd = fopen("hello.txt", "r");
	fgets(str, LENGTH, fd);		/* read file content */
	printf("%s\n", str);
	fclose(fd);
	
    return 0;
}
