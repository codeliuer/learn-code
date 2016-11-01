#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
    int n = 0;
    char buffer[BUFSIZ] = "";

    while ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    {
        write(STDOUT_FILENO, buffer, n);
    }

    return EXIT_SUCCESS;
}
