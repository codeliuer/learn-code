#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


static void sig_alrm(int signo)
{
    printf("enter success\n");
    printf("quit success\n");
}


int main(int argc, char *argv[])
{
    int n = 0;
    char buffer[BUFSIZ] = "";

    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        fprintf(stderr, "signal register failure\n");
        return EXIT_FAILURE;
    }

    alarm(10);
    if ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) < 0)
    {
        fprintf(stderr, "read failure\n");
        return EXIT_FAILURE;
    }
    alarm(0);

    write(STDOUT_FILENO, buffer, strlen(buffer));

    return EXIT_SUCCESS;
}
