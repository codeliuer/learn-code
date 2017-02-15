#include <stdio.h>
#include <stdlib.h>

#include "./sync/process_sync_api.h"


int main(int argc, char *argv[])
{
    pid_t pid;

    TELL_WAIT();
    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        WAIT_PARENT();
        printf("child process pid = %d\n", getpid());
        TELL_PARENT(getppid());
    }
    else
    {
        TELL_CHILD(pid);
        WAIT_CHILD();
        printf("parent process pid = %d\n", getpid());
    }

    return EXIT_SUCCESS;
}
