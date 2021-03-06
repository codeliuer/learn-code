/***********************************************************
 * block IO write
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define BUFFER_SIZE         (5000000)

static int set_fl(int fd, int flag)
{
    int fl;

    fl = fcntl(fd, F_GETFL, 0);

    return (fcntl(fd, F_SETFL, fl|flag));
}

static int clr_fl(int fd, int flag)
{
    int fl;

    fl = fcntl(fd, F_GETFL, 0);

    return (fcntl(fd, F_SETFL, fl & ~flag));
}

int main(int argc, char *argv[])
{
    char *ptr = NULL;
    int ntowrites, nwrites;
    char buffer[BUFFER_SIZE] = "";

    ntowrites = read(STDIN_FILENO, buffer, sizeof(buffer));
    fprintf(stderr, "read %d bytes\n", ntowrites);

    set_fl(STDOUT_FILENO, O_NONBLOCK);

    ptr = buffer;

    while (ntowrites > 0)
    {
        errno = 0;
        nwrites = write(STDOUT_FILENO, ptr, ntowrites);
        fprintf(stderr, "nwrites = %d, errno = %d\n", nwrites, errno);

        if (nwrites > 0)
        {
            ptr += nwrites;
            ntowrites -= nwrites;
        }
    }

    clr_fl(STDOUT_FILENO, O_NONBLOCK);

    return EXIT_SUCCESS;
}
