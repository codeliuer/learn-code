#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


static void do_func(int signo)
{
    printf("catch signal number = %d\n", signo);
}

int main(int argc, char *argv[])
{
    sigset_t oset, nset;
    sigset_t set;

    if (signal(SIGINT, do_func) == SIG_ERR)
    {
        fprintf(stderr, "signal register failure\n");
        return EXIT_FAILURE;
    }

    sigemptyset(&nset);
    sigaddset(&nset, SIGINT);
    sigaddset(&nset, SIGQUIT);
    if (sigprocmask(SIG_SETMASK, &nset, &oset) < 0)
    {
        fprintf(stderr, "sigprocmask failure\n");
        return EXIT_FAILURE;
    }

    raise(SIGINT);

    printf("block over\n");

    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    sigsuspend(&set);

    sleep(1);
    printf("sleep 1 over\n");
    raise(SIGINT);
    printf("sleep 2 over\n");
    sleep(2);

    return EXIT_SUCCESS;
}
