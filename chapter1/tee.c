#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int main(int argc, char *args[argc])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", args[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fh = fopen(args[1], "w");
    if (!fh) {
        fprintf(stderr, "Unable to open %s for writing\n", args[1]);
        exit(EXIT_FAILURE);
    }

    int  n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            fprintf(stderr, "Write error\n");
            exit(EXIT_FAILURE);
        }

        if (write(fileno(fh), buf, n) != n) {
            fprintf(stderr, "Write error\n");
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}
