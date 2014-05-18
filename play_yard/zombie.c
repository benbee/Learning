#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("error occurred\n");
    } else if (pid == 0) {      /* child exit */
        exit(0);
    } else {
        sleep(30);              /* sleep 30sec */
        wait(NULL);             /* collection zombie process */
    }
}
