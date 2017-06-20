#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int n = 0;
    int fd[2];
    pid_t pid;
    char *pager, *argv0;
    char line[MAXLINE];
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out filename\n");
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("fopen failrue: ");
        return EXIT_FAILURE;
    }
    if (pipe(fd) < 0)
    {
        perror("pipe failure: ");
        return EXIT_FAILURE;
    }

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        close(fd[1]);
        if (fd[0] != STDIN_FILENO)
        {
            if (dup2(fd[0], STDIN_FILENO) < 0)
            {
                perror("dup2 failure: ");
                return EXIT_FAILURE;
            }
            close(fd[0]);
        }
    }
    else
    {
    }

    return EXIT_FAILURE;
}
