#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/wait.h>


#define forever_true()      for(;;)


static void
func(int signo)
{
    printf("signo = %d\n", signo);
    exit(EXIT_SUCCESS);
}


int
main(int argc, char *argv[])
{
    int status = 0;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        signal(SIGINT, func);

        forever_true()
        {
            sleep(2);
            printf("child pid = %d\n", getpid());
        }
    }
    else
    {
        while (kill(pid, 0) != 0);
        sleep(1);
        kill(pid, SIGINT);
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("exit status = %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("exit signaled =  %d\n", WTERMSIG(status));
        }
        else if (WIFSTOPPED(status))
        {
            printf("stop signal = %d\n", WSTOPSIG(status));
        }
        else if (WIFCONTINUED(status))
        {
            printf("continued = %s\n", "continued");
        }
    }

    return EXIT_SUCCESS;
}
