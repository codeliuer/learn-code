#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    char buffer[BUFSIZ] = "";

    write(STDOUT_FILENO, "12345\n", 6);

    return EXIT_SUCCESS;
}
