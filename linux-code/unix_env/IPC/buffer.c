#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    char buffer[BUFSIZ] = "";

//    setvbuf(stdin, buffer, _IOFBF, BUFSIZ);
//    setvbuf(stdout, buffer, _IONBF, BUFSIZ);

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        execl("./a.out", "a.out", (char *)0);
    }
    else
    {
    }

    return EXIT_SUCCESS;
}
