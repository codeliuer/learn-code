#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_SUCCESS;    
    }
    else if (pid != 0)
    {
        exit(EXIT_SUCCESS);
    }

    setsid();

    

    return EXIT_SUCCESS;
}
