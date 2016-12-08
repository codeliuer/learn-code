#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


#define sleep           self_sleep


typedef void (*func_t)(int);

static func_t func = NULL;


static void do_sleep(int siggno)
{
    signal(SIGALRM, func);
    raise(SIGALRM);
}

static unsigned int self_sleep(unsigned int nseconds)
{
    unsigned int reset = 0;
    func = signal(SIGALRM, do_sleep);

    reset = alarm(nseconds);
    pause();

    if (reset > nseconds)
    {
        reset -= nseconds;
    }
    else
    {
        reset = 0;
    }

    return alarm(reset);
}


static void do_func(int signo)
{
    printf("catch signo = %d\n", signo);
}


int main(int argc, char *argv[])
{
    printf("self pid = %d\n", getpid());

    signal(SIGALRM, do_func);

    alarm(4);
    printf("remain nseconds = %d\n", sleep(3));

    return EXIT_SUCCESS;
}
