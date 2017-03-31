#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_SUCCESS;
    }
    else if (pid == 0)
    {
        sleep(10);
    }

    sleep(10)
;
    return EXIT_SUCCESS;
}
