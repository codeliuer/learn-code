#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>


extern int errno;

int main(int argc, char *argv[])
{
    int fd = 0;
    int fifofd = 0;
    DIR *dir = NULL;

    errno = 0;

    dir = opendir("/home/parallels");
    if (dir == NULL)
    {
        perror("opendir failure");
//        fprintf(stderr, "opendir failure\n");
        return EXIT_FAILURE;
    }

    fd = dirfd(dir);
    if (fd < 0 )
    {
        perror("dirfd failure");
//        fprintf(stderr, "dirfd failure\n");
        return EXIT_FAILURE;
    }

    fifofd = mkfifoat(fd, "./learn-code", 0644);
    if (fifofd < 0)
    {
        fprintf(stderr, "mkfifofd failure\n");
        return EXIT_FAILURE;
    }

    printf("fifofd = %d\n", fifofd);

    return EXIT_SUCCESS;
}
