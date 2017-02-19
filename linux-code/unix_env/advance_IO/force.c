#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>


#define FORCE_FILE      "stderr.out"


int main(int argc, char *argv[])
{
    int fd = open(FORCE_FILE, O_RDWR);

    if (fd < 0)
    {
        fprintf(stderr, "open file failure\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
