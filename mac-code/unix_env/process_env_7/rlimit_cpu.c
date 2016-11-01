/*
** SIGXCPU
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#include <sys/resource.h>


#define S_TO_NS                     (1000000000L)


#define forever_true()              for(;;)


extern int errno;


static void
cpu_catch(int signo)
{
    printf("signo = %d\n", signo);
    exit(EXIT_FAILURE);
}


static void
time_monitor(int n)
{
    int nseconds = 0;
    struct timespec tms;
    struct timespec newtms;
    long int timediff = 0;

    clock_gettime(CLOCK_MONOTONIC, &tms);
    forever_true()
    {
        clock_gettime(CLOCK_MONOTONIC, &newtms);
        timediff = newtms.tv_sec - tms.tv_sec;
        if ((timediff >= 2) || (newtms.tv_nsec+timediff*S_TO_NS-tms.tv_nsec) >= S_TO_NS)
        {
            memcpy(&tms, &newtms, sizeof(newtms));
            printf("nseconds = %d\n", ++nseconds);
            if (nseconds == n)
            {
                break;
            }
        }
    }
}


static void
cpu_exec(void)
{
    struct rlimit rlim;

    errno = 0;
    if (getrlimit(RLIMIT_CPU, &rlim) < 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }

    rlim.rlim_cur = 10;
    if (setrlimit(RLIMIT_CPU, &rlim) < 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }

    time_monitor(100);
}


int
main(int argc, char *argv[])
{
    signal(SIGXCPU, cpu_catch);

    cpu_exec();

    forever_true();

    return EXIT_SUCCESS;
}
