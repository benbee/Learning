#include <stdio.h>
#include <unistd.h>

#define opps(m, x) { perror(m); exit(x); }

int main(int argc, char *argv[])
{
    int pid, todc[2], fromdc[2];

    /* make tow pipes */

    if (pipe(todc) == -1 || pipe(fromdc) == -1)
        opps("pipe failed", 1);

    /* get a process for user interface */

    if ((pid = fork()) == -1)
        opps("Cannot fork", 2);
    if (pid == 0)               /* child dc */
        be_dc(todc, fromdc);
    else{
        be_bc(todc, fromdc);
        wait(NULL);
    }

    return 0;
}


int be_dc(int in[2], int out[2])
/* set up stdin and stdout, then execl dc */
{
    /* setup stdin from pipein */
    if (dup2(in[0], 0) == -1) { /* copy read end to 0 */
        opps("dc: cannot redirect stdin", 3);
    }

    close(in[0]);               /* moved to fd0 */
    close(in[1]);               /* won't write here */

    /* set up stdout to pipeout */
    if (dup2(out[1], 1) == -1) {
        opps("dc: cannot readirect stdout", 4);
    }

    close(out[1]);              /* moved to fd1 */
    close(out[0]);              /* won't read from here */

    /* now execl dc with the - option */
    execlp("dc", "dc", "-", NULL);
    opps("Cannot run dc", 5);
}

int be_bc(int todc[2], int fromdc[2])
/*
  read from stdin and covert into to RPN, send down pipe
  then read from other pipe and print to user
  uses fdopen() to convert a file descriptor to a stream
 */
{
    int num1, num2;
    char operations[BUFSIZ], message[BUFSIZ];
    FILE *fpout, *fpin;
    int fatal();
    /* setup */
    close(todc[0]);             /* won't read from pipe to dc */
    close(fromdc[1]);           /* won't write to pipe from dc */

    fpout = fdopen(todc[1], "w"); /* convert file dp to streams */
    fpin = fdopen(fromdc[0], "r");

    if (fpout == NULL || fpin == NULL) {
        fatal("Error convering pipes to streams");
    }

    while(printf("tinybc: "), fgets(message, BUFSIZ, stdin)
          != NULL) {
        /* parse input */
        if (sscanf(message, "%d%[-+*/%^]%d", &num1, operations, &num2)
            != 3) {
            printf("syntax error\n");
            continue;
        }

        /* make_cal(message); */

        /* printf("\n"); */
        /* printf("message: %s", message); */
        /* printf("\n"); */

        if (fprintf(fpout, "%d\n %d\n %c\np\n", num1, num2, *operations) == EOF) {
            fatal("Error writing");
        }
        //fprintf(fpout, "%s", message);

        fflush(fpout);
        if (fgets(message, BUFSIZ, fpin) == NULL) {
            break;
        }

        printf("%d %c %d = %s", num1, *operations, num2, message);

    }
    fclose(fpout);
    fclose(fpin);
}

int make_cal(char *message)
{
    int syntax_check = 0;
    char line[BUFSIZ];
    int i = 0, ch;
    while((ch = getchar()) != '\n') {
        line[i] = ch;
        i++;
    }
    line[i] = '\0';

    for (i = 0; line[i] != '\0'; i++) {
        message[i] = line[i];
    }

}

int fatal(char *mess)
{
    fprintf(stderr, "Error: %s", mess);
    exit(1);
}
