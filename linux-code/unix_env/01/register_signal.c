#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define NUL             '\0'



static void 
sig_int(int signo)
{
    printf("interrupt\n");
}


#define print(x)            printf(#x " = %d\n", x)

int
main(int argc, char* argv[])
{
    pid_t pid;
    int status = 0;
    char buffer[BUFSIZ] = "";

    signal(SIGINT, sig_int);

    printf("WNOHANG = %d\n", WNOHANG);
    print(WUNTRACED);
    print(WCONTINUED);
    printf("%% ");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (buffer[strlen(buffer)-1] == '\n')
        {
            buffer[strlen(buffer)-1] = NUL;
        }

        if ((pid = fork()) < 0)
        {
            fprintf(stderr, "fork failure\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            execlp(buffer, buffer, (char *)0);
            fprintf(stderr, "exec command %s failure\n", buffer);
            exit(127);
        }

        if (waitpid(-1, &status, 0) < 0)
        {
            fprintf(stderr, "wait process %d failure\n", pid);
            return EXIT_FAILURE;
        }
        printf("%% ");
    }

    return EXIT_SUCCESS;
}
