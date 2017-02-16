#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


#define readable_lock(fd, whence, start, len)       \
    (test_lock((fd), F_RDLCK, (whence), (start), (len)))

#define writeable_lock(fd, whence, start, len)      \
    (test_lock((fd), F_WRLOCK, (whence), (start), (len)))


static int test_lock(int fd, int type, int whence, int start, int len)
{
    struct flock flock;

    flock.l_type = type;
    flock.l_whence = whence;
    flock.l_start = start;
    flock.l_len = len;

    fcntl(fd, F_GETLK, &flock);

    if (flock.l_type == F_UNLCK)
    {
        return 0;
    }

    return flock.l_pid;
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
