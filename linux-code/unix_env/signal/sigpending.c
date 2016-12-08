#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


static void do_quit(int signo)
{
    printf("catch signal signo = %d\n", signo);

    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
    {
        printf("signal register failure\n");
        return;
    }
}


static void test_sigpending(void)
{
    sigset_t oset = {0};
    sigset_t nset = {0};
    sigset_t set = {0};

    signal(SIGQUIT, do_quit);
    signal(SIGINT, do_quit);

    sigemptyset(&nset);
    sigaddset(&nset, SIGQUIT);
    if (sigprocmask(SIG_SETMASK, &nset, &oset) < 0)
    {
        perror("sigprocmask :");
        return;
    }

    printf("sleep 5\n");
    sleep(5);

    sigpending(&set);
    if (sigismember(&nset, SIGQUIT))
    {
        printf("sigquit is pending\n");
    }
    if (sigismember(&nset, SIGINT))
    {
        printf("sigquit is pending\n");
    }
    printf("sigint is not pending\n");

    if (sigprocmask(SIG_SETMASK, &oset, &nset) < 0)
    {
        printf("restore failure\n");
        return;
    }

    sleep(5);

    return;
}


int main(int argc, char *argv[])
{
    test_sigpending();

    return EXIT_SUCCESS;
}
