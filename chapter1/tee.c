#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

int
main(int argc, char *args[argc])
{
    FILE    *fh;
    ssize_t n;
    char    buf[BUFF_SIZE];
    char    error = 0;

    if (argc != 2) {
        sprintf(&error, "Usage: %s [filename]", args[0]);
        goto end;
    }

    fh = fopen(args[1], "w");
    if (!fh) {
        sprintf(&error, "Unable to open %s for writing", args[1]);
        goto end;
    }

    while ((n = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            sprintf(&error, "Write error");
            goto end;
        }

        if (write(fileno(fh), buf, n) != n) {
            sprintf(&error, "Write error");
            goto end;
        }
    }

    if (n < 0) {
        sprintf(&error, "Read error");
    }

end:
    if (fh) {
        fclose(fh);
    }

    if (error != 0) {
        fprintf(stderr, "%s\n", &error);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
