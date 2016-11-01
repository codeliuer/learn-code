#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>


static void
pr_exit(int status)
{
    if (WIFEXITED(status))
    {
        printf("child process exit status = %d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status) ? " (core file generated) " : "");
#else
                "");
#endif //WCOREDUMP
    }
    else if (WIFSTOPPED(status))
    {
        printf("child ");
    }
}


int
main(int argc, char* argv[])
{
    pid_t pid = 0;
    int status = 0;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        exit(7);
    }

    if (wait(&status) != pid)
    {
        fprintf(stderr, "wait error\n");
        return EXIT_FAILURE;
    }
    pr_exit(status);

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        abort();
    }

    if (wait(&status) != pid)
    {
        fprintf(stderr, "wait error\n");
        return EXIT_FAILURE;
    }
    pr_exit(status);

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        status /= 0;
    }

    if (wait(&status) != pid)
    {
        fprintf(stderr, "wait error\n");
        return EXIT_FAILURE;
    }
    pr_exit(status);

    return EXIT_SUCCESS;
}
