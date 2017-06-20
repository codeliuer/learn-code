#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    int fds[2] = {0};
    pid_t pid;

    if (pipe(fds) < 0)
    {
        perror("pipe failure: ");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
