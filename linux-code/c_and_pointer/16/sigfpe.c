#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


static void
fpefunc(int signo)
{
    printf("signo = %d\n", signo);
}


int
main(int argc, char* argv[])
{
    int v = 0;
    signal(SIGFPE, fpefunc);

    v = 4/0;
    printf("v = %d\n", v);

    return EXIT_SUCCESS;
}
