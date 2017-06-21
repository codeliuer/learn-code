#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
    }
    else
    {
    }

    return EXIT_SUCCESS;
}
