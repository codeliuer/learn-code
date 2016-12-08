#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


extern int errno;

void pr_mask(const char *str)
{
    sigset_t sigset = {0};
    int errno_save = errno;

    if (sigprocmask(0, NULL, &sigset) < 0)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("%s", str);
        if (sigismember(&sigset, SIGINT))
        {
            printf("SIGINT");
        }
        if (sigismember(&sigset, SIGQUIT))
        {
            printf("SIGQUIT");
        }
        if (sigismember(&sigset, SIGUSR1))
        {
            printf("SIGUSR1");
        }
        if (sigismember(&sigset, SIGALRM))
        {
            printf("SIGALRM");
        }
    }

    printf("\n");
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
