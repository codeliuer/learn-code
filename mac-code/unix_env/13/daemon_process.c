#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    struct sigaction sig;
    struct rlimit lim;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;    
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

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "the second fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid != 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    chdir("/");

    /* close all file descriptor */
    getrlimit(&rlimit);

    return EXIT_SUCCESS;
}
