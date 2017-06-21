#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int fds[2] = {0};
    pid_t pid;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out filename\n");
        return EXIT_FAILURE;
    }

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
            close(fds[0]);
        }

        execl("/bin/more", "/bin/more", (char *)0);

        perror("execl failure");
        close(fds[0]);
        return EXIT_FAILURE;
    }
    else
    {
        char buffer[BUFSIZ] = "";
        FILE *fp = NULL;

        close(fds[0]);

        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            perror("fopen failure: ");
            return EXIT_FAILURE;
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            write(fds[1], buffer, strlen(buffer));
        }

        fclose(fp);

        waitpid(pid, NULL, 0);
    }

    return EXIT_SUCCESS;
}
