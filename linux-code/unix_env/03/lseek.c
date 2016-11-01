#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>


static void
test_fileno(int fd)
{
    errno = 0;
    if (lseek(fd, 0, SEEK_CUR) == -1)
    {
        perror(strerror(errno));
        printf("errno = %d\n", errno);
    }
    else
    {
        printf("seek OK\n");
    }
}


int
main(int argc, char* argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        fprintf(stderr, "failure\n");
        return EXIT_FAILURE;
    }

    test_fileno(fd);
    test_fileno(STDIN_FILENO);

    int fd1 = open("log", O_RDWR);
    test_fileno(fd1);

    return EXIT_SUCCESS;
}
