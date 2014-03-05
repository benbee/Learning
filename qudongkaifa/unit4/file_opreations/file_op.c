#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LENGTH 100

int main(int argc, char *argv[])
{
    int fd, len;
	char str[LENGTH];

	fd = open("hello.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR); /* create and open file */
	if (fd) {
		write(fd, "Hello, World!", strlen("Hello, World!")); /* write string */
		close(fd);
	}

	fd = open("hello.txt", O_RDWR);
	len = read(fd, str, LENGTH); /* read file content */
	printf("%s\n", str);
	close(fd);
	
    return 0;
}


















