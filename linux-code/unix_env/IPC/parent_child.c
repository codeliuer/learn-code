#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) < 0)
    {
        perror("pipe failure: ");
        return EXIT_FAILURE;
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        char buf[PIPE_BUF] = "";

        close(fd[1]);
        if (read(fd[0], buf, sizeof(buf)) < 0)
        {
            perror("read failure: ");
            return EXIT_FAILURE;
        }

        printf("%s", buf);
    }
    else
    {
        close(fd[0]);
        if (write(fd[1], "Hello World!", 12) != 12)
        {
            perror("write failure: ");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
