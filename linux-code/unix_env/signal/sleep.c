#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


static jmp_buf env;

static void sig_alm(int signo)
{
    longjmp(env, 1);
}

static void sig_int(int signo)
{
    int i, j;
    volatile int k;

    printf("\n sig_int start\n");
    for (i = 0; i < 1000000000; i++)
    {
        for (j = 0; j < 1000000; j++)
        {
            k += j;
        }
    }

    printf("sig_int finished\n");
}

static unsigned int sleep2(unsigned int nseconds)
{
    signal(SIGALRM, sig_alm);

    if (setjmp(env) == 0)
    {
        alarm(nseconds);
        pause();
    }

    return alarm(0);
}


int main(int argc, char *argv[])
{
    unsigned int unum;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        fprintf(stderr, "line = %d failure\n", __LINE__);
        return EXIT_FAILURE;
    }

    unum = sleep2(2);
    printf("sleep2 returned: %u\n", unum);

    return EXIT_SUCCESS;
}
