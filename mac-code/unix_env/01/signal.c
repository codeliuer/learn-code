#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


#define forever_true()          for(;;)


static jmp_buf jmpbuf;


static void func(int signo)
{
    printf("%d\n", signo);

    siglongjmp(jmpbuf, 1);
}


int
main(int argc, char* argv[])
{
    int savesigs = 1;

    signal(SIGSEGV, func);
    signal(SIGINT, func);

    if (sigsetjmp(jmpbuf, savesigs) == 0)
    {
        forever_true();
    }

    return EXIT_SUCCESS;
}
