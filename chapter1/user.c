#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char *args[argc])
{
    printf("uid = '%d', gid = '%d'\n", getuid(), getgid());

    printf("groups:");

    __gid_t groups[16] = {0};
    int count = getgroups(16, groups);

    for (int i = 0; i < count; ++i) {
        printf(" '%d'", groups[i]);
    }

    printf("\n");

    exit(EXIT_SUCCESS);
}
