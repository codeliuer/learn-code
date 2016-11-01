#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>


static jmp_buf restart;


static void sigfunc(int signo)
{
    printf("error\n");
    longjmp(restart, 1);
}


int
main(int argc, char* argv[])
{
    int* ptr = NULL;

    signal(SIGSEGV, sigfunc);

    if (setjmp(restart) == 0)
    {
        *ptr = 3;
        return EXIT_SUCCESS;
    }


    printf("catch signal\n");

    return EXIT_SUCCESS;
}
