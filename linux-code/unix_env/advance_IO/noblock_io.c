/***********************************************************
 * block IO write
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define BUFFER_SIZE         (5000000)


int main(int argc, char *argv[])
{
    int ntowrites, nwrites;
    char buffer[BUFFER_SIZE] = "";

    ntowrite = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (ntowrite)


    return EXIT_SUCCESS;
}
