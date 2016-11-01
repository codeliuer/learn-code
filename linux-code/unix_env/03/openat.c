#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


#define STATEMENT           "test is or not success\n"


int
main(int argc, char* argv[])
{
    int dir_fd = 0;
    int log_fd = 0;

    errno = 0;
    dir_fd = open("test", O_RDONLY);
    if (dir_fd < 0)
    {
        fprintf(stderr, "open ../02 failure, errno = %d\n", errno);
        return EXIT_FAILURE;
    }

    log_fd = openat(AT_FDCWD, "log.txt", O_CREAT|O_TRUNC|O_RDWR, 0666);
    if (log_fd < 0)
    {
        fprintf(stderr, "at ../02 dir open log.txt failure\n");
        close(dir_fd);
        return EXIT_FAILURE;
    }

    write(log_fd, STATEMENT, strlen(STATEMENT));

    printf("AT_FDCWD = %d\n", AT_FDCWD);

    close(log_fd);
    close(dir_fd);

//    printf("O_EXEC = %d\n", O_EXEC);

    return EXIT_SUCCESS;
}
