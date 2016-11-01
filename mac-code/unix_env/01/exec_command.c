#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define NUL             '\0'


int
main(int argc, char* argv[])
{
    pid_t pid = 0;
    int status = 0;
    char buffer[BUFSIZ] = "";

    printf("%% ");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (buffer[strlen(buffer)-1] == '\n')
        {
            buffer[strlen(buffer)-1] = NUL;
        }

        if ((pid = fork()) < 0)
        {
            fprintf(stderr, "getpid failure\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            execlp(buffer, buffer, (char *)0);
            fprintf(stderr, "exec failure\n");
            exit(EXIT_FAILURE);
        }

        if (waitpid(pid, &status, 0) < 0)
        {
            fprintf(stderr, "failure\n");
            return EXIT_FAILURE;
        }
        printf("%% ");
    }

    return EXIT_SUCCESS;
}
