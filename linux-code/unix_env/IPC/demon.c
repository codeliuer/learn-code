#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        printf("child process pid = %d\n", getpid());

        while (1);
    }
    else
    {
        printf("parent process pid = %d\n", getpid());

        while (1);
    }

    return EXIT_SUCCESS;
}
