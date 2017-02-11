#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    struct sigaction sig;

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

    sig.sa_handler = SIG_IGN;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;

    sigaction(SIGHUP, &sig, NULL);

    return EXIT_SUCCESS;
}
