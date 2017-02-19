#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>


#define FORCE_FILE      "stderr.out"


int main(int argc, char *argv[])
{
    int fd = 0;
    struct flock flock;
    
    fd = open(FORCE_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open file failure\n");
        return EXIT_FAILURE;
    }

    flock.l_type = F_WRLCK;
    flock.l_whence = SEEK_SET;
    flock.l_start = 0;
    flock.l_len = 0;

    fcntl(fd, F_SETLK, &flock);

    while (1);

    return EXIT_SUCCESS;
}
