#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


static sigjmp_buf jmpbuf;
static volatile sig_atomic_t atomic;

static void do_func(int signo)
{
    if (atomic == 0)
    {
        return;
    }

    printf("catch signal signo = %d\n", signo);

    siglongjmp(jmpbuf, 1);
}

int main(int argc, char *argv[])
{
    if (signal(SIGINT, do_func) == SIG_ERR)
    {
        fprintf(stderr, "SIGINT register failure\n");
        return EXIT_FAILURE;
    }

//    atomic = 1;
//    sleep(10);
    if (sigsetjmp(jmpbuf, 1))
    {
        printf("ready to quit\n");

        exit(EXIT_SUCCESS);
    }
    atomic = 1;

    for (;;)
    {
        pause();
    }

    return EXIT_SUCCESS;
}
