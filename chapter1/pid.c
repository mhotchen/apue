#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *args[argc])
{
    printf("PID: %ld\n", (long) getpid());
    exit(EXIT_SUCCESS);
}
