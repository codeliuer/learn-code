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

static int set_fl(int fd, int flag)
{
    int fl;

    fl = fcntl();
}

int main(int argc, char *argv[])
{
    int ntowrites, nwrites;
    char buffer[BUFFER_SIZE] = "";

    ntowrite = read(STDIN_FILENO, buffer, sizeof(buffer));
    fprintf(stderr, "read %d bytes\n", ntowrites);

    set_fl(STDOUT_FILENO, O_NONBLOCK);


    return EXIT_SUCCESS;
}
