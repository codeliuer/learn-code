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
    if (signal(SIGTTOU, do_func) == SIG_ERR || signal(SIGINT, do_func) == SIG_ERR)
    {
        fprintf(stderr, "signal register failure\n");
        return EXIT_SUCCESS;
    }

    sleep(5);

    printf("write terminate\n");

    return EXIT_SUCCESS;
}
