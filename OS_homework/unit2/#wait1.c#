#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pc, pr;				/* process child, process parents pid */
	pc = fork();

	if (pc < 0) {
		printf("error ocurred!\n");
	} else if (pc == 0) {
		printf("This is child process with pid of %d\n");
		sleep(10);
	} else {
		pr = wait(NULL);
		printf("I catched a child process with pid of %d\n");
	}
	
    return 0;
}
