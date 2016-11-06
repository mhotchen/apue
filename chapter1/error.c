#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *args[argc])
{
    int errors[] = {
        EPERM,  ENOENT,  ESRCH,   EINTR,  EIO,    ENXIO,
        E2BIG,  ENOEXEC, EBADF,   ECHILD, EAGAIN, ENOMEM,
        EACCES, EFAULT,  ENOTBLK, EBUSY,  EEXIST, EXDEV,
        ENODEV, ENOTDIR, EISDIR,  EINVAL, ENFILE, EMFILE,
        ENOTTY, ETXTBSY, EFBIG,   ENOSPC, ESPIPE, EROFS,
        EMLINK, EPIPE,   EDOM,    ERANGE,
    };

    int errorsSize = sizeof(errors) / sizeof(errors[0]);
    for (int i = 0; i < errorsSize; ++i) {
        errno = errors[i];
        perror("Error");
    }

    exit(EXIT_FAILURE);
}
