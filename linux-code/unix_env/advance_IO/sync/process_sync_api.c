#include <stdio.h>
#include <signal.h>

#include "process_sync_api.h"


#define UNDEL(x)        ((void)(x))

#ifdef DEBUG
# define enter_log()     printf("Enter function %s\n", __func__)
# define quit_log()      printf("Quit function %s\n", __func__)
#else
# define enter_log()    
# define quit_log()
#endif //DEBUG


static volatile sig_atomic_t atomic = 0;

static sigset_t oset;
static sigset_t zeroset;


static void do_usr(int signo)
{
    UNDEL(signo);

    printf("getpid = %d\n", getpid());
    atomic = 1;
}

void TELL_WAIT(void)
{
    sigset_t nset;

    if (signal(SIGUSR1, do_usr) == SIG_ERR)
    {
        fprintf(stderr, "signal failure\n");
        return;
    }

    enter_log();

    sigemptyset(&nset);
    sigemptyset(&zeroset);
    sigaddset(&nset, SIGUSR1);

    if (sigprocmask(SIG_BLOCK, &nset, &oset) < 0)
    {
        fprintf(stderr, "sigprocmask failure\n");
        return;
    }

    quit_log();
}


void TELL_CHILD(pid_t pid)
{
    enter_log();
    kill(pid, SIGUSR1);
    quit_log();
}

void WAIT_CHILD(void)
{
    enter_log();
    while (atomic == 0)
    {
        sigsuspend(&zeroset);
    }
    atomic = 0;

    if (sigprocmask(SIG_SETMASK, &oset, NULL) < 0)
    {
        fprintf(stderr, "sigprocmask failure\n");
        return;
    }
    quit_log();
}


void TELL_PARENT(pid_t pid)
{
    enter_log();
    kill(pid, SIGUSR1);
    quit_log();
}

void WAIT_PARENT(void)
{
    enter_log();
    WAIT_CHILD();
    quit_log();
}
