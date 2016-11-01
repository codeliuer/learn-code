#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int
main(int argc,char* argv[])
{
    int status = 0;
    pid_t pid = 0;

    fork();

    while ((pid = waitpid(-1, &status, 0)) < 0)
    {
    }
    printf("pid = %d\n", pid);

    return EXIT_SUCCESS;
}
