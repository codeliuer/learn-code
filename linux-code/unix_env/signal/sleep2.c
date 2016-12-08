#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


static jmp_buf jmp = {0};

static void do_int(int signo)
{
    int i = 0;
    int j = 9;
    volatile unsigned long long int k = 0;

    printf("\nsig_int starting\n");
    for (i = 0; i < 10000000; i++)
    {
        for (j = 0; j < 1000000000; j++)
        {
            k += j;
        }
    }
    printf("sig_int finished\n");
}

static void do_alrm(int signo)
{
    longjmp(jmp, 1);
}

int main(int argc, char *argv[])
{
    unsigned int remain = 0;

    signal(SIGALRM, do_alrm);
    signal(SIGINT, do_int);

    if (setjmp(jmp) == 0)
    {
        alarm(5);
        pause();
    }
    remain = alarm(0);
    
    printf("sleep returned: %u\n", remain);

    return EXIT_SUCCESS;
}
