#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

#include <unistd.h>


#define HUGE_N                  (100000000)


static int global = 0;
extern int errno;


static void child_func(int signo)
{
    pid_t pid;
//    int status = 0;

    pid = wait(NULL);
    printf("pid = %d\n", pid);
    global = 1;
}


int main(int argc, char* argv[])
{
    int i = 0;
    int status = 0;
    pid_t pid = 0;

    if (signal(SIGCHLD, child_func) < 0)
    {
        fprintf(stderr, "regiter signal failure\n");
        return EXIT_FAILURE;
    }

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        printf("child pid = %d\n", getpid());
        sleep(1);
        exit(EXIT_SUCCESS);
    }
    else
    {
    }

    for (i = 0; i < HUGE_N; i++)
    {
        printf("%d\n", i);
        if (global == 1)
        {
            printf("%d\n", ++i);
            break;
        }
    }

    sleep(3);

    printf("print infomation\n");

    return EXIT_SUCCESS;
}
