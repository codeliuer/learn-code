#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "failure\n");

        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        execl("/bin/ls", "ls", "-l", (char *)0);

        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
