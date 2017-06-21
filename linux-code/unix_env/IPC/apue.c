#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>

#define MAXLINE             (1024)
#define DEF_PAGER           "/bin/more"


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

        if ((pager = getenv("PAGER")) == NULL)
        {
            pager = DEF_PAGER;
        }
        if ((argv0 = strchr(pager, '/')) != NULL)
        {
            argv0++;
        }
        else
        {
            argv0 = pager;
        }
        printf("pager: %s, argv0: %s\n", pager, argv0);

        execl(pager, argv0, (char *)0);
    }
    else
    {
        close(fd[0]);

        while (fgets(line, MAXLINE, fp) != NULL)
        {
            n = strlen(line);
            if (write(fd[1], line, n) != n)
            {
                perror("write failure: ");
                return EXIT_FAILURE;
            }
        }

        fclose(fp);
        if (waitpid(pid, NULL, 0) < 0)
        {
            perror("waitpid failure: ");
            return EXIT_FAILURE;
        }
        exit(0);
    }

    return EXIT_FAILURE;
}
