#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    char buffer[BUFSIZ] = "";

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid > 0)
    {
        while (1);
        return EXIT_FAILURE;
    }

    while (read(STDIN_FILENO, buffer, sizeof(buffer)) > 0)
    {
        printf("%d: ", pid);
        write(STDOUT_FILENO, buffer, strlen(buffer));
        memset(buffer, 0, sizeof(buffer));
    }

    return EXIT_SUCCESS;
}
