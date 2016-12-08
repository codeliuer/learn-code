#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
    printf("catch signo = %d\n", signo);
}


int main(int argc, char *argv[])
{
    printf("self pid = %d\n", getpid());

    signal(SIGALRM, do_func);

    printf("remain nseconds = %d\n", sleep(10));

    return EXIT_SUCCESS;
}
