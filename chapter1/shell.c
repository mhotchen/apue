#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define BUFF_SIZE 4096

bool
prompt(char buf[BUFF_SIZE])
{
    printf("> ");
    return fgets(buf, BUFF_SIZE, stdin) != NULL && strcmp(buf, "exit\n") != 0;
}

int
main (int argc, char *args[argc])
{
    char  buf[BUFF_SIZE];
    pid_t pid;
    int   status;

    while (prompt(buf)) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if (strcmp(buf, "\0") == 0) {
            continue;
        }

        pid = fork();
        if (pid < 0) {
            perror("Fork error");
        }

        if (pid == 0) {
            execlp(buf, buf, (char *) 0);
            fprintf(stderr, "Couldn't exec '%s'\n", buf);
            exit(EXIT_FAILURE);
        }

        pid = waitpid(pid, &status, 0);
        if (pid < 0) {
            perror("Error waiting on child process");
        }
    }

    printf("\n");
    exit(EXIT_SUCCESS);
}
