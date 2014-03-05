/* just a simple chmoe */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int mode;					/* mod */
	int mode_u;					/* user mode */
	int mode_g;					/* group */
	int mode_o;					/* other */
	char *path;

	if (argc < 3) {
		printf("%s <mode num> <target file>\n", argv[0]);
		exit(0);
	}

	/* get command line para */
	mode = atoi(argv[1]);
	if (mode > 777 || mode < 0) {
		printf("mode num error!\n");
		exit(0);
	}

	mode_u = mode / 100;
	/* mode_g = (mode - (mode_u * 100)) / 10; */
	/* mode_o = mode - (mode_u * 100) - (mode_g*10); */

	mode_g = mode / 10 % 10;
	mode_o = mode % 10;
	mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;
	path = argv[2];
	/* mode_t */

	if (chmod(path, mode) == -1) {
		perror("chmod error\n");
		exit(1);
	}
	
    return 0;
}
