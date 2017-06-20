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
    }
    else
    {
        char buffer[BUFSIZ] = "";

        close(fds[0]);
        while (read(STDIN_FILENO, buffer, sizeof(buffer)) > 0)
        {
            write(fds[1], buffer, );
        }
    }

    return EXIT_SUCCESS;
}
