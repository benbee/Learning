#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void do_something(long t)
{
	int i = 0;
	for (i = i; i < t; i++) {
		for (i = 0; i < t; i++) {
			for (i = 0; i < t; i++) {
			}
		}
	}
}

int main(int argc, char *argv[])
{
    pid_t pid;

	/* only one process */
	printf("PID before fork(): %d\n", getpid());
	pid = fork();

	/* now two processes */
	pid_t npid = getpid();
	if (pid < 0) {
		perror("fork error\n");
	} else if (pid == 0) {		/* pid == 0 means child process */
		while (1) {
			printf("I am child process, PID is %d\n", npid);
			do_something(100000000);
		}
	} else if(pid >= 0) {		/* pid > 0 means farcher */
		while (1) {
		    printf("I am father process, PID is %d\n", npid);
            do_something(100000000);
		}
	}

    return 0;
}
