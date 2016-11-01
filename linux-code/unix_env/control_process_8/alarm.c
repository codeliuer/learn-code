#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void
alarm_func(int signo)
{
    printf("pid = %d\n", getpid());
    exit(EXIT_FAILURE);
}


int
main(int argc, char argv[])
{
    pid_t pid;

    if (signal(SIGALRM, alarm_func) == SIG_ERR)
    {
        fprintf(stderr, "regiter signal failure\n");
        return EXIT_FAILURE;
    }
    
    alarm(3);

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        /*
        ** The child process of unprocessed alarm is cleared
        */
        printf("child pid = %d\n", getpid());
    }
    else
    {
        printf("father pid = %d\n", getpid());
    }

    sleep(4);

    return EXIT_SUCCESS;
}
