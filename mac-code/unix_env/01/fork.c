#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int
main(int argc, char* argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "failure\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        fprintf(stderr, "child pid = %d\n", getpid());
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(stderr, "father\n");
    }

    return EXIT_SUCCESS;
}
