#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int fd = 0;

    printf("%d\n", PIPE_BUF);

    fd = open("test.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    printf("fd = %d\n", fd);

    return EXIT_SUCCESS;
}
