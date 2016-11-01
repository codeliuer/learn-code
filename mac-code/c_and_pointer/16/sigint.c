#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


#define forever_true()          for(;;)

static void
intfunc(int signo)
{
    raise(SIGINT);
    raise(SIGINT);

    printf("deal with\n");
}

int
main(int argc, char* argv[])
{
    signal(SIGINT, intfunc);

    forever_true();

    return EXIT_SUCCESS;
}
