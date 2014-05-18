#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void opps(char *s1, char *s2);

int main(int argc, char *argv[])
{
    int fd;

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Cannot open ", argv[1]);
    }

    if (close(fd) == -1) {
        opps("Error closing files", "");
    }
    
    return 0;
}


void opps(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s", s1);
    perror(s2);
    exit(1);
}
