#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    char buffer[BUFSIZ] = "";

    while (1){
    read(STDIN_FILENO, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, strlen(buffer));
    }

    return EXIT_SUCCESS;
}
