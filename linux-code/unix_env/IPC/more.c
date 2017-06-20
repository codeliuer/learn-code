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

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        close(fds[0]), close(fds[1]);
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        close(fds[1]);
        if (fds[0] != STDIN_FILENO)
        {
            if (dup2(fds[0], STDIN_FILENO) < 0)
            {
                perror("dup2 failure: ");
                close(fds[0]);
                return EXIT_FAILURE;
            }
        }

        execl("");
    }
    else
    {
        ssize_t len = 0;
        char buffer[BUFSIZ] = "";

        close(fds[0]);
        while ((len = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
        {
            if (write(fds[1], buffer, len) != len)
            {
                perror("write failure: ");
                close(fds[1]);
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
