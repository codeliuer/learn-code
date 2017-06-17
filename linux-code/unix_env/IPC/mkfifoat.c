#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    int fifofd = 0;
    DIR *dir = NULL;

    dir = opendir("/Users/weiliu/");
    if (dir == NULL)
    {
        fprintf(stderr, "opendir failure\n");
        return EXIT_FAILURE;
    }

    fd = dirfd(dir);
    if (fd < 0 )
    {
        fprintf(stderr, "dirfd failure\n");
        return EXIT_FAILURE;
    }

    fifofd = mkfifoat(fd, "./learn-code", "w");
    if (fifofd < 0)
    {
        fprintf(stderr, "mkfifofd failure\n");
        return EXIT_FAILURE;
    }

    printf("fifofd = %d\n", fifoat);

    return EXIT_SUCCESS;
}
