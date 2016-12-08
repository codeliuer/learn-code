#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
    printf("catch signal number = %d\n", signo);
}


int main(int argc, char *argv[])
{
    signal(SIGALRM, do_func);

    alarm(0);

    sleep(3);

    return EXIT_SUCCESS;
}
