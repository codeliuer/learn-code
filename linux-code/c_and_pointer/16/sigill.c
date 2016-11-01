#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>



static void
sigfunc(int signo)
{
    printf("signo = %d\n", signo);
//    exit(EXIT_FAILURE);
}

int
main(int argc, char* argv[])
{
    void (*ptr)(void);

    signal(SIGILL, sigfunc);
    signal(SIGSEGV, sigfunc);

    (*ptr)();

    return EXIT_SUCCESS;
}
